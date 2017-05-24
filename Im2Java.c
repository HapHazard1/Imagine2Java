#include <windows.h>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include "imdefs.h"
#include "txdefs.h"
#include "d:\devtools\jdks\jdk1.6_32bit\include\jni.h"
#include "Im2Java.h"

#ifdef	__cplusplus
extern "C" {
#endif

static JNIEnv *env = NULL;
static JavaVM *jvm;
static jclass mycls;
static int loaded = 0;

LONG	(*pInit)();      // passed to Imagine by InquireTexture
void	(*pCleanup)();   // passed to Imagine by InquireTexture

char	szName[18] = "Imagine to Java";  // passed to Imagine by InquireTexture

BYTE	ubParamFlags[16] = {  // passed to Imagine by InquireTexture
	TXTF_SCL,
	TXTF_SCL,
	TXTF_SCL,
	0,0,0,0,
	TXTF_RED,	// TXTF_RED, etc., are ignored now.

	TXTF_GRN,
	TXTF_BLU,
	TXTF_RED,
	TXTF_GRN,
	TXTF_BLU,
	TXTF_RED,
	TXTF_GRN,
	TXTF_BLU
};

float fParams[16] = {  // passed to Imagine by InquireTexture
	1.0,  2.0,  3.0,  4.0,
	5.0,  6.0,  7.0,  8.0,
	9.0,  10.0, 11.0, 12.0,
	13.0, 14.0, 15.0, 16.0
};

TFORM	tfAxes = {  // passed to Imagine by InquireTexture
	0.0, 0.0, 0.0,

	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,

	32.0, 32.0, 32.0
};

typedef /*_JNI_IMPORT_OR_EXPORT_*/ jint (JNICALL *JNI_CreateJavaVM_func)(JavaVM **pvm, void **penv, void *args);

JNI_CreateJavaVM_func JNI_CreateJavaVM_ptr;

// load the JVM via call to LoadLibrary instead of the JNI CreateJavaVM method (it's flaky)
JNIEnv* create_vm(JavaVM ** jvm) {
  JNIEnv *env;
  JavaVMInitArgs vm_args;
  JavaVMOption options[3];
  HANDLE jvm_dll;
  int ret;
  DWORD dw;
  char mybuf[1024];

  // The path to the classes used by the texture needs to be, relative to the location
  //  of the imagine.exe binary, textures\Im2Java
  options[0].optionString = "-Djava.class.path=.\\textures\\Im2Java";
  options[1].optionString = "-Xms512m";
  options[2].optionString = "-Xmx640m";
  vm_args.version = JNI_VERSION_1_6; //JDK version. This indicates version 1.6
  vm_args.nOptions = 3;
  vm_args.options = &options;
  vm_args.ignoreUnrecognized = 0;

  jvm_dll = LoadLibrary("jvm.dll");
  dw = GetLastError();

  if (jvm_dll == NULL) {
    // display the error we got trying to call LoadLibrary
    sprintf(&mybuf[0],"Loding jvm.dll failed with error num:%i",dw);
    MessageBox(NULL,mybuf,"Error",MB_OK);
    return NULL;
  }

  JNI_CreateJavaVM_ptr = (JNI_CreateJavaVM_func)GetProcAddress(jvm_dll, "JNI_CreateJavaVM");
  dw = GetLastError();

  if (JNI_CreateJavaVM_ptr == NULL) {
    sprintf(&mybuf[0],"Unable to find CreateJavaVM  method in jvm.dll. Error num:%i",dw);
    MessageBox(NULL,mybuf,"Error",MB_OK);
    return NULL;
  }

  ret = JNI_CreateJavaVM_ptr(jvm, (void**)&env, &vm_args);
  if (ret < 0) {
    sprintf(&mybuf[0],"Call to CreateJavaVM failed with error num:%i",ret);
    MessageBox(NULL,mybuf,"got here",MB_OK);
    return NULL;
  }
  return env;
}

// main work method for the DLL as far as Imagine is concerned
void Work(float *params, PATCH *patch, VECTOR *vector, TFORM *axes) {
  
  // declare Java variables...
  jclass tmpcls;
  static jfieldID myfid[89];
  static jmethodID mymid;
  jint   myint;
  jsize buflen;
  jsize nVMs;
	int x,y;


  if (mycls == NULL) {
    // this check allows us to know whether we need worry about getting the VM.
    buflen = 2;
    myint = JNI_GetCreatedJavaVMs(&jvm,buflen,&nVMs);

    if (nVMs == 0) {
      // nVMs is either 1 or 0. If we don't have one we need to create one.
      env = create_vm(&jvm);
    } else {
      myint = (*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_6);
      if (myint == JNI_EDETACHED) {
        myint = (*jvm)->AttachCurrentThread(jvm, (void **)&env, NULL);
        if (myint != 0) {
          MessageBox(NULL,"GetEnv: not attached - failed","Error",MB_OK);
          return;
        }
      } else if (myint == JNI_EVERSION) {
        MessageBox(NULL,"GetEnv: bad java version","Error",MB_OK);
        return;
      } else if (myint == JNI_OK) {
      }
    }

    // we've got the VM so now create the class
    tmpcls = (*env)->FindClass(env, "ImJavaWork");
    if (tmpcls == 0) {
      MessageBox(NULL,"Could not find ImJavaWork class","Error",MB_OK);
      return;
    } else {
      mycls = (*env)->NewGlobalRef(env, tmpcls);
    }
    // and the method in the class
    mymid = (*env)->GetStaticMethodID(env,mycls,"callWork","()I");
    if (mymid == 0) {
      // error finding method
      MessageBox(NULL,"Could not find callWork method in class","Error",MB_OK);
      return;
    }
    // and the attributes in the class
    for (x=0; x<89; x++) {
      myfid[x] = (*env)->GetStaticFieldID(env,mycls,finfo[x].fn,finfo[x].sig);
    }
  }

  // set fields in ImJavaWork to values from *param, etc.
	x = 0;
	// position vector
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_pos.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_pos.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_pos.Z);
	x++;

   // normal vector
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_nor.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_nor.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_nor.Z);
	x++;

   // color
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_col.r);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_col.g);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_col.b);
	x++;
	
	// reflect
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_ref.r);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_ref.g);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_ref.b);
	x++;
	
	// transparency
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_tra.r);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_tra.g);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_tra.b);
	x++;
	
	// specularity
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_spc.r);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_spc.g);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_spc.b);
	x++;

   // shape flags
	(*env)->SetStaticIntField(env,mycls,myfid[x],patch->ptc_shp);
	x++;
	
	// shadow flags
	(*env)->SetStaticIntField(env,mycls,myfid[x],patch->ptc_shd);
	x++;
	
	// 1st barycentric
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_c1);
	x++;
	
	// 2nd barycentric
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_c2);
	x++;
	
	// ray info
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_rayptr->m_base.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_rayptr->m_base.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_rayptr->m_base.Z);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_rayptr->m_unit.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_rayptr->m_unit.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_rayptr->m_unit.Z);
	x++;
	
	// ray distance
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_raydst);
	x++;
	
	// fog length
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_foglen);
	x++;
	
	// shininess
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_shiny);
	x++;
	
	// hardness
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_hard);
	x++;
	
	// index of refraction
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_index);
	x++;
	
	// brightness
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_bright);
	x++;
	
	// texture data area
	for (y=0; y<16; y++) {
   	(*env)->SetStaticByteField(env,mycls,myfid[x],(byte)patch->ptc_txdata[y]);
	   x++;
	}
	
	// roughness
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_rough);
	x++;
	
	// ambient light
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_brlite.r);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_brlite.g);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],patch->ptc_brlite.b);
	x++;
	
	// user parameters
	for (y=0; y<16; y++) {
   	(*env)->SetStaticFloatField(env,mycls,myfid[x],params[y]);
	   x++;
	}
	
	// position
	(*env)->SetStaticFloatField(env,mycls,myfid[x],vector->X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],vector->Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],vector->Z);
	x++;
	
	// transform position
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->r.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->r.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->r.Z);
	x++;

   // transform X direction unit vector
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->a.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->a.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->a.Z);
	x++;

   // transform Y direction unit vector
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->b.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->b.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->b.Z);
	x++;

   // transform Z direction unit vector
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->c.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->c.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->c.Z);
	x++;

   // transform axis lengths vector
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->s.X);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->s.Y);
	x++;
	(*env)->SetStaticFloatField(env,mycls,myfid[x],axes->s.Z);

	// call Java method
	x = (*env)->CallStaticIntMethod(env,mycls,mymid);
	if (x == 0) {
	   // error on method envoke
	   MessageBox(NULL,"Error on method invoke","Error",MB_OK);
	}

	// get the done flag value from the class. This allows more detailed
	// error handling to be possible from the java class to the dll.
	x = (*env)->GetStaticIntField(env,mycls,myfid[88]);
	if (x == 0) {
	   // error in java
	   MessageBox(NULL,"Error in Java code","Error",MB_OK);
	   return;
	}
	
	// set values in *patch to values from fields in ImJavaWork
	x=3;
	// normal
	patch->ptc_nor.X = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_nor.Y = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_nor.Z = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;

   // color
	patch->ptc_col.r = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_col.g = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_col.b = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// reflect
	patch->ptc_ref.r = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_ref.g = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_ref.b = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// transparency
	patch->ptc_tra.r = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_tra.g = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_tra.b = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// specularity
	patch->ptc_spc.r = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_spc.g = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_spc.b = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x = 29;
	
	// fog length
	patch->ptc_foglen = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// shininess
	patch->ptc_shiny = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// hardness
	patch->ptc_hard = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// index of refraction
	patch->ptc_index = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// brightness
	patch->ptc_bright = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;

	// texture data area
	for (y=0; y<16; y++) {
      patch->ptc_txdata[y] = (*env)->GetStaticByteField(env,mycls,myfid[x]);
	   x++;
	}

	// roughness
	patch->ptc_rough = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	
	// ambient light
	patch->ptc_brlite.r = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_brlite.g = (*env)->GetStaticFloatField(env,mycls,myfid[x]);
	x++;
	patch->ptc_brlite.b = (*env)->GetStaticFloatField(env,mycls,myfid[x]);

}

void Cleanup() {
  // this should probably have VM clean up in it.
  return;
}
#ifdef	__cplusplus
};
#endif
