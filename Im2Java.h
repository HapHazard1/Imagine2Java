// include file for Im2Java.c

struct fieldinfo {
   char fn[20]; // Field name
   char sig[2]; // Field signature
};

struct fieldinfo finfo[89] = {"ptc_pos_x","F",        // 0
                              "ptc_pos_y","F",        // 1
                              "ptc_pos_z","F",        // 2
                              "ptc_nor_x","F",        // 3
                              "ptc_nor_y","F",        // 4
                              "ptc_nor_z","F",        // 5
                              "ptc_col_r","F",        // 6
                              "ptc_col_g","F",        // 7
                              "ptc_col_b","F",        // 8
                              "ptc_ref_r","F",        // 9
                              "ptc_ref_g","F",        // 10
                              "ptc_ref_b","F",        // 11
                              "ptc_tra_r","F",        // 12
                              "ptc_tra_g","F",        // 13
                              "ptc_tra_b","F",        // 14
                              "ptc_spc_r","F",        // 15
                              "ptc_spc_g","F",        // 16
                              "ptc_spc_b","F",        // 17
                              "ptc_shp","I",          // 18
                              "ptc_shd","I",          // 19
                              "ptc_c1","F",           // 20
                              "ptc_c2","F",           // 21
                              "ptc_rayptr_base_x","F",// 22
                              "ptc_rayptr_base_y","F",// 23
                              "ptc_rayptr_base_z","F",// 24
                              "ptc_rayptr_unit_x","F",// 25
                              "ptc_rayptr_unit_y","F",// 26
                              "ptc_rayptr_unit_z","F",// 27
                              "ptc_raydst","F",       // 28
                              "ptc_foglen","F",       // 29
                              "ptc_shiny","F",        // 30
                              "ptc_hard","F",         // 31
                              "ptc_index","F",        // 32
                              "ptc_bright","F",       // 33
                              "ptc_txdata_0","B",     // 34
                              "ptc_txdata_1","B",     // 35
                              "ptc_txdata_2","B",     // 36
                              "ptc_txdata_3","B",     // 37
                              "ptc_txdata_4","B",     // 38
                              "ptc_txdata_5","B",     // 39
                              "ptc_txdata_6","B",     // 40
                              "ptc_txdata_7","B",     // 41
                              "ptc_txdata_8","B",     // 42
                              "ptc_txdata_9","B",     // 43
                              "ptc_txdata_10","B",    // 44
                              "ptc_txdata_11","B",    // 45
                              "ptc_txdata_12","B",    // 46
                              "ptc_txdata_13","B",    // 47
                              "ptc_txdata_14","B",    // 48
                              "ptc_txdata_15","B",    // 49
                              "ptc_rough","F",        // 50
                              "ptc_brlite_r","F",     // 51
                              "ptc_brlite_g","F",     // 52
                              "ptc_brlite_b","F",     // 53
                              "params_0","F",         // 54
                              "params_1","F",         // 55
                              "params_2","F",         // 56
                              "params_3","F",         // 57
                              "params_4","F",         // 58
                              "params_5","F",         // 59
                              "params_6","F",         // 60
                              "params_7","F",         // 61
                              "params_8","F",         // 62
                              "params_9","F",         // 63
                              "params_10","F",        // 64
                              "params_11","F",        // 65
                              "params_12","F",        // 66
                              "params_13","F",        // 67
                              "params_14","F",        // 68
                              "params_15","F",        // 69
                              "posn_x","F",           // 70
                              "posn_y","F",           // 71
                              "posn_z","F",           // 72
                              "tform_r_x","F",        // 73
                              "tform_r_y","F",        // 74
                              "tform_r_z","F",        // 75
                              "tform_a_x","F",        // 76
                              "tform_a_y","F",        // 77
                              "tform_a_z","F",        // 78
                              "tform_b_x","F",        // 79
                              "tform_b_y","F",        // 80
                              "tform_b_z","F",        // 81
                              "tform_c_x","F",        // 82
                              "tform_c_y","F",        // 83
                              "tform_c_z","F",        // 84
                              "tform_s_x","F",        // 85
                              "tform_s_y","F",        // 86
                              "tform_s_z","F",        // 87
                              "done","I"};            // 88
                              
                              
   
