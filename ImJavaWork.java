/*
  This is the "bootstrap" class which is loaded by Imagine.  It defines the variables
  which are used to pass hit point information between Imagine and the java classes
  during rendering.  The static variables and the callWork() method signature must
  remain unchanged.
*/

public class ImJavaWork {
   
   static float ptc_pos_x;   // Location of hitpoint.  X, Y, and Z
   static float ptc_pos_y;   // components in world coords.  These
   static float ptc_pos_z;   // values are read only.
   
   static float ptc_nor_x;   // Vector normal to surface at hitpoint.  X,
   static float ptc_nor_y;   // Y, and Z components.  Range 0.0 to 1.0
   static float ptc_nor_z;   // SquareRoot(X*X + Y*Y + Z*Z) must equal 1.0
   
   static float ptc_col_r;   // These are the color attributes at the
   static float ptc_col_g;   // hit-point.  They are Red, Green, and Blue
   static float ptc_col_b;   // components.  Range between 0.0 and 1.0
   
   static float ptc_ref_r;   // These are the reflect attributes at the
   static float ptc_ref_g;   // hit-point.  They are Red, Green, and Blue
   static float ptc_ref_b;   // components.  Range between 0.0 and 1.0
   
   static float ptc_tra_r;   // These are the filter (transparency) attributes
   static float ptc_tra_g;   // at the hit-point.  They are Red, Green, and Blue
   static float ptc_tra_b;   // components.  Range between 0.0 and 1.0
   
   static float ptc_spc_r;   // These are the specular attributes at the
   static float ptc_spc_g;   // hit-point.  They are Red, Green, and Blue
   static float ptc_spc_b;   // components.  Range between 0.0 and 1.0
   
   static int   ptc_shp;     // Used for backward compatibility.  Do not
   static int   ptc_shd;     // use.  Readonly
   static float ptc_c1;      //      :
   static float ptc_c2;      // Backward compatibility.  Readonly
   
   static float ptc_rayptr_base_x;   // Base point location for ray that hit object
   static float ptc_rayptr_base_y;   // at the hitpoint.  X, Y, and Z components
   static float ptc_rayptr_base_z;   // for the location in world coords.  Readonly
   static float ptc_rayptr_unit_x;   // Unit direction vector for base point to 
   static float ptc_rayptr_unit_y;   // hitpoint for ray.  X, Y, and Z coords in
   static float ptc_rayptr_unit_z;   // normalized form.  Readonly
   
   static float ptc_raydst;  // Distance ray traveled from base to hitpoint. Readonly
   
   static float ptc_foglen;      // Foglength greater or equal to 0.0
   static float ptc_shiny;       // Shininess between 0.0 and 1.0
   static float ptc_hard;        // Specular hardness between 0 and 255
   static float ptc_index;       // Index of refraction greater or equal to 1.0
   static float ptc_bright;      // Brightness between 0.0 and 1.0
   static byte  ptc_txdata_0;    // Texture data area.  Useful for passing data
   static byte  ptc_txdata_1;    // between multiple textures applied to the
   static byte  ptc_txdata_2;    // same object.  May not be supported in future
   static byte  ptc_txdata_3;    // versions of Imagine.
   static byte  ptc_txdata_4;    //    :
   static byte  ptc_txdata_5;    //    :
   static byte  ptc_txdata_6;    //    :
   static byte  ptc_txdata_7;    //    :
   static byte  ptc_txdata_8;    //    :
   static byte  ptc_txdata_9;    //    :
   static byte  ptc_txdata_10;   //    :
   static byte  ptc_txdata_11;   //    :
   static byte  ptc_txdata_12;   //    :
   static byte  ptc_txdata_13;   //    :
   static byte  ptc_txdata_14;   //    :
   static byte  ptc_txdata_15;   // Texture data area
   static float ptc_rough;       // Roughness between 0.0 and 1.0
   
   static float ptc_brlite_r;    // Ambient light values.  Red, Green,
   static float ptc_brlite_g;    // and Blue components.  Range between
   static float ptc_brlite_b;    // 0.0 and 1.0
   
   static float params_0;        // Parameter 1 set in texture properties dialog.
   static float params_1;        // Parameter 2 set in texture properties dialog.
   static float params_2;        // Parameter 3 set in texture properties dialog.
   static float params_3;        // Parameter 4 set in texture properties dialog.
   static float params_4;        // Parameter 5 set in texture properties dialog.
   static float params_5;        // Parameter 6 set in texture properties dialog.
   static float params_6;        // Parameter 7 set in texture properties dialog.
   static float params_7;        // Parameter 8 set in texture properties dialog.
   static float params_8;        // Parameter 9 set in texture properties dialog.
   static float params_9;        // Parameter 10 set in texture properties dialog.
   static float params_10;       // Parameter 11 set in texture properties dialog.
   static float params_11;       // Parameter 12 set in texture properties dialog.
   static float params_12;       // Parameter 13 set in texture properties dialog.
   static float params_13;       // Parameter 14 set in texture properties dialog.
   static float params_14;       // Parameter 15 set in texture properties dialog.
   static float params_15;       // Parameter 16 set in texture properties dialog.
   
   static float posn_x;          // Hitpoint position measured relative to texture
   static float posn_y;          // axis.  X, Y, and Z components.
   static float posn_z;          // Readonly
   
   static float tform_r_x;       // Texture axis location information.  All readonly
   static float tform_r_y;       // Location, in world coords., of the axis.  X, Y,
   static float tform_r_z;       // and Z components.
   static float tform_a_x;       // Direction vector for the X axis of texture.  
   static float tform_a_y;       // X, Y, and Z
   static float tform_a_z;       // components.  Also readonly
   static float tform_b_x;       // Direction vector for the Y axis of texture.
   static float tform_b_y;       // X, Y, and Z
   static float tform_b_z;       // components.  Also readonly
   static float tform_c_x;       // Direction vector for the Y axis of texture.
   static float tform_c_y;       // X, Y, and Z
   static float tform_c_z;       // components.  Also readonly
   static float tform_s_x;       // Length of X axis.  Readonly
   static float tform_s_y;       // Length of Y axis.  Readonly
   static float tform_s_z;       // Length of Z axis.  Readonly
   
   static int   done;            // Status flag for Java, must be set to 1 for success

   static ImWork myWork;
   
   public static int callWork() {

      if (myWork == null) {
        myWork = new ImWork();
      }
      
      done = 0;
      
      myWork.doWork();
      
      return done;
   }
}
   
