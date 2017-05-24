/*
   ImWork.java  : This is an example customizable class for imagine textures.
   The ImJavaWork class is currently coded to expect this ImWork class to exist
   and for the class to contain a method named doWork().  If you want to use
   different classes and methods then matching changes must be made in the
   ImJavaWork class.  Alternatively this class can be modified to call whatever
   other methods in other classes need to be called.
*/

/* The following items are available for read or read/write.
   Each is an attribute of the ImJavaWork class and therefore
   is referenced by prepending ImJavaWork.  They are included
   in this comment for easy reference.

   float ptc_pos_x;   Location of hitpoint.  X, Y, and Z
   float ptc_pos_y;   components in world coords.  These
   float ptc_pos_z;   values are read only.
   
   float ptc_nor_x;   Vector normal to surface at hitpoint.  X,
   float ptc_nor_y;   Y, and Z components.  Range 0.0 to 1.0
   float ptc_nor_z;   SquareRoot(X*X + Y*Y + Z*Z) must equal 1.0
   
   float ptc_col_r;   These are the color attributes at the
   float ptc_col_g;   hit-point.  They are Red, Green, and Blue
   float ptc_col_b;   components.  Range between 0.0 and 1.0
   
   float ptc_ref_r;   These are the reflect attributes at the
   float ptc_ref_g;   hit-point.  They are Red, Green, and Blue
   float ptc_ref_b;   components.  Range between 0.0 and 1.0
   
   float ptc_tra_r;   These are the filter attributes at the
   float ptc_tra_g;   hit-point.  They are Red, Green, and Blue
   float ptc_tra_b;   components.  Range between 0.0 and 1.0
   
   float ptc_spc_r;   These are the specular attributes at the
   float ptc_spc_g;   hit-point.  They are Red, Green, and Blue
   float ptc_spc_b;   components.  Range between 0.0 and 1.0
   
   int   ptc_shp;     Used for backward compatibility.  Do not
   int   ptc_shd;     use.  Readonly
   float ptc_c1;           :
   float ptc_c2;      Backward compatibility.  Readonly
   
   float ptc_rayptr_base_x;   Base point location for ray that hit object
   float ptc_rayptr_base_y;   at the hitpoint.  X, Y, and Z components
   float ptc_rayptr_base_z;   for the location in world coords.  Readonly
   float ptc_rayptr_unit_x;   Unit direction vector for base point to 
   float ptc_rayptr_unit_y;   hitpoint for ray.  X, Y, and Z coords in
   float ptc_rayptr_unit_z;   normalized form.  Readonly
   
   float ptc_raydst;          Distance ray traveled from base to hitpoint.
                              Readonly
   
   float ptc_foglen;       Foglength greater or equal to 0.0
   float ptc_shiny;        Shininess between 0.0 and 1.0
   float ptc_hard;         Specular hardness between 0 and 255
   float ptc_index;        Index of refraction greater or equal to 1.0
   float ptc_bright;       Brightness between 0.0 and 1.0
   byte  ptc_txdata_0;     Texture data area.  Useful for passing data
   byte  ptc_txdata_1;     between multiple textures applied to the
   byte  ptc_txdata_2;     same object.  May not be supported in future
   byte  ptc_txdata_3;     versions of Imagine.
   byte  ptc_txdata_4;        :
   byte  ptc_txdata_5;        :
   byte  ptc_txdata_6;        :
   byte  ptc_txdata_7;        :
   byte  ptc_txdata_8;        :
   byte  ptc_txdata_9;        :
   byte  ptc_txdata_10;       :
   byte  ptc_txdata_11;       :
   byte  ptc_txdata_12;       :
   byte  ptc_txdata_13;       :
   byte  ptc_txdata_14;       :
   byte  ptc_txdata_15;    Texture data area
   float ptc_rough;        Roughness between 0.0 and 1.0
   
   float ptc_brlite_r;     Ambient light values.  Red, Green,
   float ptc_brlite_g;     and Blue components.  Range between
   float ptc_brlite_b;     0.0 and 1.0
   
   float params_0;         Parameter 1 set in texture properties dialog.
   float params_1;         Parameter 2 set in texture properties dialog.
   float params_2;         Parameter 3 set in texture properties dialog.
   float params_3;         Parameter 4 set in texture properties dialog.
   float params_4;         Parameter 5 set in texture properties dialog.
   float params_5;         Parameter 6 set in texture properties dialog.
   float params_6;         Parameter 7 set in texture properties dialog.
   float params_7;         Parameter 8 set in texture properties dialog.
   float params_8;         Parameter 9 set in texture properties dialog.
   float params_9;         Parameter 10 set in texture properties dialog.
   float params_10;        Parameter 11 set in texture properties dialog.
   float params_11;        Parameter 12 set in texture properties dialog.
   float params_12;        Parameter 13 set in texture properties dialog.
   float params_13;        Parameter 14 set in texture properties dialog.
   float params_14;        Parameter 15 set in texture properties dialog.
   float params_15;        Parameter 16 set in texture properties dialog.
   
   float posn_x;           Hitpoint position measured relative to texture
   float posn_y;           axis.  X, Y, and Z components.
   float posn_z;           Readonly
   
   float tform_r_x;        Texture axis location information.  All readonly
   float tform_r_y;        Location, in world coords., of the axis.  X, Y,
   float tform_r_z;        and Z components.
   float tform_a_x;        Direction vector for the X axis of texture.  
   float tform_a_y;        X, Y, and Z
   float tform_a_z;        components.  Also readonly
   float tform_b_x;        Direction vector for the Y axis of texture.
   float tform_b_y;        X, Y, and Z
   float tform_b_z;        components.  Also readonly
   float tform_c_x;        Direction vector for the Y axis of texture.
   float tform_c_y;        X, Y, and Z
   float tform_c_z;        components.  Also readonly
   float tform_s_x;        Length of X axis.  Readonly
   float tform_s_y;        Length of Y axis.  Readonly
   float tform_s_z;        Length of Z axis.  Readonly
   
   int   done;             Status flag for Java, must be set to 1 for success
*/

public class ImWork {

   public ImWork() {
   }
   
   // This method is required
   public void doWork() {
      
      // This example uses the first user parameter (params_0)
      // to determine what the texture does.  This is useful if
      // you need to use the Java texture with several different
      // objects and each object needs a different behavior from
      // the Java texture.  
      
      if (ImJavaWork.params_0 < 1.0) {
         // If param_0 < 1.0 then the color values at the hitpoint
         // are derived from the values of the direction normal to
         // the surface at the hitpoint.
         
         ImJavaWork.ptc_col_r = ImJavaWork.ptc_nor_x;
         ImJavaWork.ptc_col_g = ImJavaWork.ptc_nor_y;
         ImJavaWork.ptc_col_b = ImJavaWork.ptc_nor_z;
         
      } else if (ImJavaWork.params_0 < 2.0) {
         // If param_0 < 2.0 then the transparency values at the
         // hitpoint are derived from the values of the direction
         // normal to the surface at the hitpoint.
         
         ImJavaWork.ptc_tra_r = ImJavaWork.ptc_nor_x;
         ImJavaWork.ptc_tra_g = ImJavaWork.ptc_nor_y;
         ImJavaWork.ptc_tra_b = ImJavaWork.ptc_nor_z;
      } else if (ImJavaWork.params_0 < 3.0) {
         // If param_0 < 3.0 then the specularity values at the hitpoint
         // are derived from the values of the direction normal to
         // the surface at the hitpoint.
         
         ImJavaWork.ptc_spc_r = ImJavaWork.ptc_nor_x;
         ImJavaWork.ptc_spc_g = ImJavaWork.ptc_nor_y;
         ImJavaWork.ptc_spc_b = ImJavaWork.ptc_nor_z;
      } else {
         // If param_0 > 3.0 then the reflectivity values at the hitpoint
         // are derived from the values of the direction normal to
         // the surface at the hitpoint.
         
         ImJavaWork.ptc_ref_r = ImJavaWork.ptc_nor_x;
         ImJavaWork.ptc_ref_g = ImJavaWork.ptc_nor_y;
         ImJavaWork.ptc_ref_b = ImJavaWork.ptc_nor_z;
      }
      
      ImJavaWork.done = 1; // always set done = 1 when the work is done.
      return;
   }
}
