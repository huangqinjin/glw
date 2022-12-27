//
// Copyright (c) 2022-2023 Huang Qinjin (huangqinjin@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GLW_GL_H
#define GLW_GL_H

#if defined(__gl_h_) || defined(__GL_H__)
#error gl.h included before.
#endif

#include <stddef.h>
#include <stdint.h>

#define __gl_h_
#define __GL_H__

typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef signed char GLbyte;
typedef short GLshort;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned long GLulong;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
typedef char GLchar;
typedef int64_t GLint64;
typedef uint64_t GLuint64;

// https://www.khronos.org/opengl/wiki/History_of_OpenGL
// Modified version of glew.h

#ifndef GLW_API
#define GLW_API
#endif

#define GL_SINCE(...)
#define GL_DEPRECATED(...)

#if defined(_WIN32)
#define GLW_GLCALL __stdcall
#else
#define GLW_GLCALL
#endif

#ifndef GLF
#define GLF(R, f, ...) extern GLW_API R (GLW_GLCALL *f)(__VA_ARGS__)
#endif

typedef void(GLW_GLCALL* GLfunc)(void);
extern GLW_API GLfunc (*glGetProcAddress)(const char* name);

/* ----------------------------- GL_VERSION_1_0 ---------------------------- */

#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1

#define GL_ZERO 0
#define GL_FALSE 0
#define GL_LOGIC_OP 0x0BF1
#define GL_NONE 0
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_NO_ERROR 0
#define GL_POINTS 0x0000
#define GL_CURRENT_BIT 0x00000001
#define GL_TRUE 1
#define GL_ONE 1
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_POINT_BIT 0x00000002
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_LINE_STRIP 0x0003
#define GL_LINE_BIT 0x00000004
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON 0x0009
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_LIGHTING_BIT 0x00000040
#define GL_FOG_BIT 0x00000080
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_ACCUM 0x0100
#define GL_LOAD 0x0101
#define GL_RETURN 0x0102
#define GL_MULT 0x0103
#define GL_ADD 0x0104
#define GL_NEVER 0x0200
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_OUT_OF_MEMORY 0x0505
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_EXP 0x0800
#define GL_VIEWPORT_BIT 0x00000800
#define GL_EXP2 0x0801
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_COEFF 0x0A00
#define GL_ORDER 0x0A01
#define GL_DOMAIN 0x0A02
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_POINT_SMOOTH 0x0B10
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LIST_MODE 0x0B30
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_LIST_BASE 0x0B32
#define GL_LIST_INDEX 0x0B33
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_EDGE_FLAG 0x0B43
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_LIGHTING 0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_SHADE_MODEL 0x0B54
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL 0x0B57
#define GL_FOG 0x0B60
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_MATRIX_MODE 0x0BA0
#define GL_NORMALIZE 0x0BA1
#define GL_VIEWPORT 0x0BA2
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_AUX_BUFFERS 0x0C00
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_INDEX_MODE 0x0C30
#define GL_RGBA_MODE 0x0C31
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_RENDER_MODE 0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_FOG_HINT 0x0C54
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_INDEX_BITS 0x0D51
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_AUTO_NORMAL 0x0D80
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TRANSFORM_BIT 0x00001000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_BORDER 0x1005
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_DOUBLE 0x140A
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_EMISSION 0x1600
#define GL_SHININESS 0x1601
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_COLOR_INDEXES 0x1603
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_COLOR_INDEX 0x1900
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_BITMAP 0x1A00
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_RENDER 0x1C00
#define GL_FEEDBACK 0x1C01
#define GL_SELECT 0x1C02
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_S 0x2000
#define GL_ENABLE_BIT 0x00002000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_EYE_LINEAR 0x2400
#define GL_OBJECT_LINEAR 0x2401
#define GL_SPHERE_MAP 0x2402
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_OBJECT_PLANE 0x2501
#define GL_EYE_PLANE 0x2502
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_CLAMP 0x2900
#define GL_REPEAT 0x2901
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_R3_G3_B2 0x2A10
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
#define GL_C3F_V3F 0x2A24
#define GL_N3F_V3F 0x2A25
#define GL_C4F_N3F_V3F 0x2A26
#define GL_T2F_V3F 0x2A27
#define GL_T4F_V4F 0x2A28
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_LIGHT0 0x4000
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
#define GL_HINT_BIT 0x00008000
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_EVAL_BIT 0x00010000
#define GL_LIST_BIT 0x00020000
#define GL_TEXTURE_BIT 0x00040000
#define GL_SCISSOR_BIT 0x00080000
#define GL_ALL_ATTRIB_BITS 0x000fffff
#define GL_CLIENT_ALL_ATTRIB_BITS 0xffffffff

GL_SINCE(1, 0)
GLF(void, glAccum, GLenum op, GLfloat value);

GL_SINCE(1, 0)
GLF(void, glAlphaFunc, GLenum func, GLclampf ref);

GL_SINCE(1, 0)
GLF(void, glBegin, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glBitmap, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);

GL_SINCE(1, 0)
GLF(void, glBlendFunc, GLenum sfactor, GLenum dfactor);

GL_SINCE(1, 0)
GLF(void, glCallList, GLuint list);

GL_SINCE(1, 0)
GLF(void, glCallLists, GLsizei n, GLenum type, const void *lists);

GL_SINCE(1, 0)
GLF(void, glClear, GLbitfield mask);

GL_SINCE(1, 0)
GLF(void, glClearAccum, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

GL_SINCE(1, 0)
GLF(void, glClearColor, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);

GL_SINCE(1, 0)
GLF(void, glClearDepth, GLclampd depth);

GL_SINCE(1, 0)
GLF(void, glClearIndex, GLfloat c);

GL_SINCE(1, 0)
GLF(void, glClearStencil, GLint s);

GL_SINCE(1, 0)
GLF(void, glClipPlane, GLenum plane, const GLdouble *equation);

GL_SINCE(1, 0)
GLF(void, glColor3b, GLbyte red, GLbyte green, GLbyte blue);

GL_SINCE(1, 0)
GLF(void, glColor3bv, const GLbyte *v);

GL_SINCE(1, 0)
GLF(void, glColor3d, GLdouble red, GLdouble green, GLdouble blue);

GL_SINCE(1, 0)
GLF(void, glColor3dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glColor3f, GLfloat red, GLfloat green, GLfloat blue);

GL_SINCE(1, 0)
GLF(void, glColor3fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glColor3i, GLint red, GLint green, GLint blue);

GL_SINCE(1, 0)
GLF(void, glColor3iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glColor3s, GLshort red, GLshort green, GLshort blue);

GL_SINCE(1, 0)
GLF(void, glColor3sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glColor3ub, GLubyte red, GLubyte green, GLubyte blue);

GL_SINCE(1, 0)
GLF(void, glColor3ubv, const GLubyte *v);

GL_SINCE(1, 0)
GLF(void, glColor3ui, GLuint red, GLuint green, GLuint blue);

GL_SINCE(1, 0)
GLF(void, glColor3uiv, const GLuint *v);

GL_SINCE(1, 0)
GLF(void, glColor3us, GLushort red, GLushort green, GLushort blue);

GL_SINCE(1, 0)
GLF(void, glColor3usv, const GLushort *v);

GL_SINCE(1, 0)
GLF(void, glColor4b, GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);

GL_SINCE(1, 0)
GLF(void, glColor4bv, const GLbyte *v);

GL_SINCE(1, 0)
GLF(void, glColor4d, GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);

GL_SINCE(1, 0)
GLF(void, glColor4dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glColor4f, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

GL_SINCE(1, 0)
GLF(void, glColor4fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glColor4i, GLint red, GLint green, GLint blue, GLint alpha);

GL_SINCE(1, 0)
GLF(void, glColor4iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glColor4s, GLshort red, GLshort green, GLshort blue, GLshort alpha);

GL_SINCE(1, 0)
GLF(void, glColor4sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glColor4ub, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);

GL_SINCE(1, 0)
GLF(void, glColor4ubv, const GLubyte *v);

GL_SINCE(1, 0)
GLF(void, glColor4ui, GLuint red, GLuint green, GLuint blue, GLuint alpha);

GL_SINCE(1, 0)
GLF(void, glColor4uiv, const GLuint *v);

GL_SINCE(1, 0)
GLF(void, glColor4us, GLushort red, GLushort green, GLushort blue, GLushort alpha);

GL_SINCE(1, 0)
GLF(void, glColor4usv, const GLushort *v);

GL_SINCE(1, 0)
GLF(void, glColorMask, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);

GL_SINCE(1, 0)
GLF(void, glColorMaterial, GLenum face, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glColorPointer, GLint size, GLenum type, GLsizei stride, const void *pointer);

GL_SINCE(1, 0)
GLF(void, glCopyPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);

GL_SINCE(1, 0)
GLF(void, glCullFace, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glDeleteLists, GLuint list, GLsizei range);

GL_SINCE(1, 0)
GLF(void, glDepthFunc, GLenum func);

GL_SINCE(1, 0)
GLF(void, glDepthMask, GLboolean flag);

GL_SINCE(1, 0)
GLF(void, glDepthRange, GLclampd zNear, GLclampd zFar);

GL_SINCE(1, 0)
GLF(void, glDisable, GLenum cap);

GL_SINCE(1, 0)
GLF(void, glDrawBuffer, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glDrawPixels, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);

GL_SINCE(1, 0)
GLF(void, glEdgeFlag, GLboolean flag);

GL_SINCE(1, 0)
GLF(void, glEdgeFlagv, const GLboolean *flag);

GL_SINCE(1, 0)
GLF(void, glEnable, GLenum cap);

GL_SINCE(1, 0)
GLF(void, glEnd, void);

GL_SINCE(1, 0)
GLF(void, glEndList, void);

GL_SINCE(1, 0)
GLF(void, glEvalCoord1d, GLdouble u);

GL_SINCE(1, 0)
GLF(void, glEvalCoord1dv, const GLdouble *u);

GL_SINCE(1, 0)
GLF(void, glEvalCoord1f, GLfloat u);

GL_SINCE(1, 0)
GLF(void, glEvalCoord1fv, const GLfloat *u);

GL_SINCE(1, 0)
GLF(void, glEvalCoord2d, GLdouble u, GLdouble v);

GL_SINCE(1, 0)
GLF(void, glEvalCoord2dv, const GLdouble *u);

GL_SINCE(1, 0)
GLF(void, glEvalCoord2f, GLfloat u, GLfloat v);

GL_SINCE(1, 0)
GLF(void, glEvalCoord2fv, const GLfloat *u);

GL_SINCE(1, 0)
GLF(void, glEvalMesh1, GLenum mode, GLint i1, GLint i2);

GL_SINCE(1, 0)
GLF(void, glEvalMesh2, GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);

GL_SINCE(1, 0)
GLF(void, glEvalPoint1, GLint i);

GL_SINCE(1, 0)
GLF(void, glEvalPoint2, GLint i, GLint j);

GL_SINCE(1, 0)
GLF(void, glFeedbackBuffer, GLsizei size, GLenum type, GLfloat *buffer);

GL_SINCE(1, 0)
GLF(void, glFinish, void);

GL_SINCE(1, 0)
GLF(void, glFlush, void);

GL_SINCE(1, 0)
GLF(void, glFogf, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glFogfv, GLenum pname, const GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glFogi, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glFogiv, GLenum pname, const GLint *params);

GL_SINCE(1, 0)
GLF(void, glFrontFace, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glFrustum, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);

GL_SINCE(1, 0)
GLF(GLuint, glGenLists, GLsizei range);

GL_SINCE(1, 0)
GLF(void, glGetBooleanv, GLenum pname, GLboolean *params);

GL_SINCE(1, 0)
GLF(void, glGetClipPlane, GLenum plane, GLdouble *equation);

GL_SINCE(1, 0)
GLF(void, glGetDoublev, GLenum pname, GLdouble *params);

GL_SINCE(1, 0)
GLF(GLenum, glGetError, void);

GL_SINCE(1, 0)
GLF(void, glGetFloatv, GLenum pname, GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glGetIntegerv, GLenum pname, GLint *params);

GL_SINCE(1, 0)
GLF(void, glGetLightfv, GLenum light, GLenum pname, GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glGetLightiv, GLenum light, GLenum pname, GLint *params);

GL_SINCE(1, 0)
GLF(void, glGetMapdv, GLenum target, GLenum query, GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glGetMapfv, GLenum target, GLenum query, GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glGetMapiv, GLenum target, GLenum query, GLint *v);

GL_SINCE(1, 0)
GLF(void, glGetMaterialfv, GLenum face, GLenum pname, GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glGetMaterialiv, GLenum face, GLenum pname, GLint *params);

GL_SINCE(1, 0)
GLF(void, glGetPixelMapfv, GLenum map, GLfloat *values);

GL_SINCE(1, 0)
GLF(void, glGetPixelMapuiv, GLenum map, GLuint *values);

GL_SINCE(1, 0)
GLF(void, glGetPixelMapusv, GLenum map, GLushort *values);

GL_SINCE(1, 0)
GLF(void, glGetPolygonStipple, GLubyte *mask);

GL_SINCE(1, 0)
GLF(const GLubyte *, glGetString, GLenum name);

GL_SINCE(1, 0)
GLF(void, glGetTexEnvfv, GLenum target, GLenum pname, GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glGetTexEnviv, GLenum target, GLenum pname, GLint *params);

GL_SINCE(1, 0)
GLF(void, glGetTexGendv, GLenum coord, GLenum pname, GLdouble *params);

GL_SINCE(1, 0)
GLF(void, glGetTexGenfv, GLenum coord, GLenum pname, GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glGetTexGeniv, GLenum coord, GLenum pname, GLint *params);

GL_SINCE(1, 0)
GLF(void, glGetTexImage, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);

GL_SINCE(1, 0)
GLF(void, glGetTexLevelParameterfv, GLenum target, GLint level, GLenum pname, GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glGetTexLevelParameteriv, GLenum target, GLint level, GLenum pname, GLint *params);

GL_SINCE(1, 0)
GLF(void, glGetTexParameterfv, GLenum target, GLenum pname, GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glGetTexParameteriv, GLenum target, GLenum pname, GLint *params);

GL_SINCE(1, 0)
GLF(void, glHint, GLenum target, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glIndexMask, GLuint mask);

GL_SINCE(1, 0)
GLF(void, glIndexd, GLdouble c);

GL_SINCE(1, 0)
GLF(void, glIndexdv, const GLdouble *c);

GL_SINCE(1, 0)
GLF(void, glIndexf, GLfloat c);

GL_SINCE(1, 0)
GLF(void, glIndexfv, const GLfloat *c);

GL_SINCE(1, 0)
GLF(void, glIndexi, GLint c);

GL_SINCE(1, 0)
GLF(void, glIndexiv, const GLint *c);

GL_SINCE(1, 0)
GLF(void, glIndexs, GLshort c);

GL_SINCE(1, 0)
GLF(void, glIndexsv, const GLshort *c);

GL_SINCE(1, 0)
GLF(void, glIndexub, GLubyte c);

GL_SINCE(1, 0)
GLF(void, glIndexubv, const GLubyte *c);

GL_SINCE(1, 0)
GLF(void, glInitNames, void);

GL_SINCE(1, 0)
GLF(GLboolean, glIsEnabled, GLenum cap);

GL_SINCE(1, 0)
GLF(GLboolean, glIsList, GLuint list);

GL_SINCE(1, 0)
GLF(void, glLightModelf, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glLightModelfv, GLenum pname, const GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glLightModeli, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glLightModeliv, GLenum pname, const GLint *params);

GL_SINCE(1, 0)
GLF(void, glLightf, GLenum light, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glLightfv, GLenum light, GLenum pname, const GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glLighti, GLenum light, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glLightiv, GLenum light, GLenum pname, const GLint *params);

GL_SINCE(1, 0)
GLF(void, glLineStipple, GLint factor, GLushort pattern);

GL_SINCE(1, 0)
GLF(void, glLineWidth, GLfloat width);

GL_SINCE(1, 0)
GLF(void, glListBase, GLuint base);

GL_SINCE(1, 0)
GLF(void, glLoadIdentity, void);

GL_SINCE(1, 0)
GLF(void, glLoadMatrixd, const GLdouble *m);

GL_SINCE(1, 0)
GLF(void, glLoadMatrixf, const GLfloat *m);

GL_SINCE(1, 0)
GLF(void, glLoadName, GLuint name);

GL_SINCE(1, 0)
GLF(void, glLogicOp, GLenum opcode);

GL_SINCE(1, 0)
GLF(void, glMap1d, GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);

GL_SINCE(1, 0)
GLF(void, glMap1f, GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);

GL_SINCE(1, 0)
GLF(void, glMap2d, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);

GL_SINCE(1, 0)
GLF(void, glMap2f, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);

GL_SINCE(1, 0)
GLF(void, glMapGrid1d, GLint un, GLdouble u1, GLdouble u2);

GL_SINCE(1, 0)
GLF(void, glMapGrid1f, GLint un, GLfloat u1, GLfloat u2);

GL_SINCE(1, 0)
GLF(void, glMapGrid2d, GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);

GL_SINCE(1, 0)
GLF(void, glMapGrid2f, GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);

GL_SINCE(1, 0)
GLF(void, glMaterialf, GLenum face, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glMaterialfv, GLenum face, GLenum pname, const GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glMateriali, GLenum face, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glMaterialiv, GLenum face, GLenum pname, const GLint *params);

GL_SINCE(1, 0)
GLF(void, glMatrixMode, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glMultMatrixd, const GLdouble *m);

GL_SINCE(1, 0)
GLF(void, glMultMatrixf, const GLfloat *m);

GL_SINCE(1, 0)
GLF(void, glNewList, GLuint list, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glNormal3b, GLbyte nx, GLbyte ny, GLbyte nz);

GL_SINCE(1, 0)
GLF(void, glNormal3bv, const GLbyte *v);

GL_SINCE(1, 0)
GLF(void, glNormal3d, GLdouble nx, GLdouble ny, GLdouble nz);

GL_SINCE(1, 0)
GLF(void, glNormal3dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glNormal3f, GLfloat nx, GLfloat ny, GLfloat nz);

GL_SINCE(1, 0)
GLF(void, glNormal3fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glNormal3i, GLint nx, GLint ny, GLint nz);

GL_SINCE(1, 0)
GLF(void, glNormal3iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glNormal3s, GLshort nx, GLshort ny, GLshort nz);

GL_SINCE(1, 0)
GLF(void, glNormal3sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glOrtho, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);

GL_SINCE(1, 0)
GLF(void, glPassThrough, GLfloat token);

GL_SINCE(1, 0)
GLF(void, glPixelMapfv, GLenum map, GLsizei mapsize, const GLfloat *values);

GL_SINCE(1, 0)
GLF(void, glPixelMapuiv, GLenum map, GLsizei mapsize, const GLuint *values);

GL_SINCE(1, 0)
GLF(void, glPixelMapusv, GLenum map, GLsizei mapsize, const GLushort *values);

GL_SINCE(1, 0)
GLF(void, glPixelStoref, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glPixelStorei, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glPixelTransferf, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glPixelTransferi, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glPixelZoom, GLfloat xfactor, GLfloat yfactor);

GL_SINCE(1, 0)
GLF(void, glPointSize, GLfloat size);

GL_SINCE(1, 0)
GLF(void, glPolygonMode, GLenum face, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glPolygonStipple, const GLubyte *mask);

GL_SINCE(1, 0)
GLF(void, glPopAttrib, void);

GL_SINCE(1, 0)
GLF(void, glPopMatrix, void);

GL_SINCE(1, 0)
GLF(void, glPopName, void);

GL_SINCE(1, 0)
GLF(void, glPushAttrib, GLbitfield mask);

GL_SINCE(1, 0)
GLF(void, glPushMatrix, void);

GL_SINCE(1, 0)
GLF(void, glPushName, GLuint name);

GL_SINCE(1, 0)
GLF(void, glRasterPos2d, GLdouble x, GLdouble y);

GL_SINCE(1, 0)
GLF(void, glRasterPos2dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos2f, GLfloat x, GLfloat y);

GL_SINCE(1, 0)
GLF(void, glRasterPos2fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos2i, GLint x, GLint y);

GL_SINCE(1, 0)
GLF(void, glRasterPos2iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos2s, GLshort x, GLshort y);

GL_SINCE(1, 0)
GLF(void, glRasterPos2sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos3d, GLdouble x, GLdouble y, GLdouble z);

GL_SINCE(1, 0)
GLF(void, glRasterPos3dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos3f, GLfloat x, GLfloat y, GLfloat z);

GL_SINCE(1, 0)
GLF(void, glRasterPos3fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos3i, GLint x, GLint y, GLint z);

GL_SINCE(1, 0)
GLF(void, glRasterPos3iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos3s, GLshort x, GLshort y, GLshort z);

GL_SINCE(1, 0)
GLF(void, glRasterPos3sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos4d, GLdouble x, GLdouble y, GLdouble z, GLdouble w);

GL_SINCE(1, 0)
GLF(void, glRasterPos4dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos4f, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

GL_SINCE(1, 0)
GLF(void, glRasterPos4fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos4i, GLint x, GLint y, GLint z, GLint w);

GL_SINCE(1, 0)
GLF(void, glRasterPos4iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glRasterPos4s, GLshort x, GLshort y, GLshort z, GLshort w);

GL_SINCE(1, 0)
GLF(void, glRasterPos4sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glReadBuffer, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glReadPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);

GL_SINCE(1, 0)
GLF(void, glRectd, GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);

GL_SINCE(1, 0)
GLF(void, glRectdv, const GLdouble *v1, const GLdouble *v2);

GL_SINCE(1, 0)
GLF(void, glRectf, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);

GL_SINCE(1, 0)
GLF(void, glRectfv, const GLfloat *v1, const GLfloat *v2);

GL_SINCE(1, 0)
GLF(void, glRecti, GLint x1, GLint y1, GLint x2, GLint y2);

GL_SINCE(1, 0)
GLF(void, glRectiv, const GLint *v1, const GLint *v2);

GL_SINCE(1, 0)
GLF(void, glRects, GLshort x1, GLshort y1, GLshort x2, GLshort y2);

GL_SINCE(1, 0)
GLF(void, glRectsv, const GLshort *v1, const GLshort *v2);

GL_SINCE(1, 0)
GLF(GLint, glRenderMode, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glRotated, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);

GL_SINCE(1, 0)
GLF(void, glRotatef, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);

GL_SINCE(1, 0)
GLF(void, glScaled, GLdouble x, GLdouble y, GLdouble z);

GL_SINCE(1, 0)
GLF(void, glScalef, GLfloat x, GLfloat y, GLfloat z);

GL_SINCE(1, 0)
GLF(void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height);

GL_SINCE(1, 0)
GLF(void, glSelectBuffer, GLsizei size, GLuint *buffer);

GL_SINCE(1, 0)
GLF(void, glShadeModel, GLenum mode);

GL_SINCE(1, 0)
GLF(void, glStencilFunc, GLenum func, GLint ref, GLuint mask);

GL_SINCE(1, 0)
GLF(void, glStencilMask, GLuint mask);

GL_SINCE(1, 0)
GLF(void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass);

GL_SINCE(1, 0)
GLF(void, glTexCoord1d, GLdouble s);

GL_SINCE(1, 0)
GLF(void, glTexCoord1dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord1f, GLfloat s);

GL_SINCE(1, 0)
GLF(void, glTexCoord1fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord1i, GLint s);

GL_SINCE(1, 0)
GLF(void, glTexCoord1iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord1s, GLshort s);

GL_SINCE(1, 0)
GLF(void, glTexCoord1sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord2d, GLdouble s, GLdouble t);

GL_SINCE(1, 0)
GLF(void, glTexCoord2dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord2f, GLfloat s, GLfloat t);

GL_SINCE(1, 0)
GLF(void, glTexCoord2fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord2i, GLint s, GLint t);

GL_SINCE(1, 0)
GLF(void, glTexCoord2iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord2s, GLshort s, GLshort t);

GL_SINCE(1, 0)
GLF(void, glTexCoord2sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord3d, GLdouble s, GLdouble t, GLdouble r);

GL_SINCE(1, 0)
GLF(void, glTexCoord3dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord3f, GLfloat s, GLfloat t, GLfloat r);

GL_SINCE(1, 0)
GLF(void, glTexCoord3fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord3i, GLint s, GLint t, GLint r);

GL_SINCE(1, 0)
GLF(void, glTexCoord3iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord3s, GLshort s, GLshort t, GLshort r);

GL_SINCE(1, 0)
GLF(void, glTexCoord3sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord4d, GLdouble s, GLdouble t, GLdouble r, GLdouble q);

GL_SINCE(1, 0)
GLF(void, glTexCoord4dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord4f, GLfloat s, GLfloat t, GLfloat r, GLfloat q);

GL_SINCE(1, 0)
GLF(void, glTexCoord4fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord4i, GLint s, GLint t, GLint r, GLint q);

GL_SINCE(1, 0)
GLF(void, glTexCoord4iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glTexCoord4s, GLshort s, GLshort t, GLshort r, GLshort q);

GL_SINCE(1, 0)
GLF(void, glTexCoord4sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glTexEnvf, GLenum target, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glTexEnvfv, GLenum target, GLenum pname, const GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glTexEnvi, GLenum target, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glTexEnviv, GLenum target, GLenum pname, const GLint *params);

GL_SINCE(1, 0)
GLF(void, glTexGend, GLenum coord, GLenum pname, GLdouble param);

GL_SINCE(1, 0)
GLF(void, glTexGendv, GLenum coord, GLenum pname, const GLdouble *params);

GL_SINCE(1, 0)
GLF(void, glTexGenf, GLenum coord, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glTexGenfv, GLenum coord, GLenum pname, const GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glTexGeni, GLenum coord, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glTexGeniv, GLenum coord, GLenum pname, const GLint *params);

GL_SINCE(1, 0)
GLF(void, glTexImage1D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);

GL_SINCE(1, 0)
GLF(void, glTexImage2D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);

GL_SINCE(1, 0)
GLF(void, glTexParameterf, GLenum target, GLenum pname, GLfloat param);

GL_SINCE(1, 0)
GLF(void, glTexParameterfv, GLenum target, GLenum pname, const GLfloat *params);

GL_SINCE(1, 0)
GLF(void, glTexParameteri, GLenum target, GLenum pname, GLint param);

GL_SINCE(1, 0)
GLF(void, glTexParameteriv, GLenum target, GLenum pname, const GLint *params);

GL_SINCE(1, 0)
GLF(void, glTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);

GL_SINCE(1, 0)
GLF(void, glTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);

GL_SINCE(1, 0)
GLF(void, glTranslated, GLdouble x, GLdouble y, GLdouble z);

GL_SINCE(1, 0)
GLF(void, glTranslatef, GLfloat x, GLfloat y, GLfloat z);

GL_SINCE(1, 0)
GLF(void, glVertex2d, GLdouble x, GLdouble y);

GL_SINCE(1, 0)
GLF(void, glVertex2dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glVertex2f, GLfloat x, GLfloat y);

GL_SINCE(1, 0)
GLF(void, glVertex2fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glVertex2i, GLint x, GLint y);

GL_SINCE(1, 0)
GLF(void, glVertex2iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glVertex2s, GLshort x, GLshort y);

GL_SINCE(1, 0)
GLF(void, glVertex2sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glVertex3d, GLdouble x, GLdouble y, GLdouble z);

GL_SINCE(1, 0)
GLF(void, glVertex3dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glVertex3f, GLfloat x, GLfloat y, GLfloat z);

GL_SINCE(1, 0)
GLF(void, glVertex3fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glVertex3i, GLint x, GLint y, GLint z);

GL_SINCE(1, 0)
GLF(void, glVertex3iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glVertex3s, GLshort x, GLshort y, GLshort z);

GL_SINCE(1, 0)
GLF(void, glVertex3sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glVertex4d, GLdouble x, GLdouble y, GLdouble z, GLdouble w);

GL_SINCE(1, 0)
GLF(void, glVertex4dv, const GLdouble *v);

GL_SINCE(1, 0)
GLF(void, glVertex4f, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

GL_SINCE(1, 0)
GLF(void, glVertex4fv, const GLfloat *v);

GL_SINCE(1, 0)
GLF(void, glVertex4i, GLint x, GLint y, GLint z, GLint w);

GL_SINCE(1, 0)
GLF(void, glVertex4iv, const GLint *v);

GL_SINCE(1, 0)
GLF(void, glVertex4s, GLshort x, GLshort y, GLshort z, GLshort w);

GL_SINCE(1, 0)
GLF(void, glVertex4sv, const GLshort *v);

GL_SINCE(1, 0)
GLF(void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height);

#endif /* GL_VERSION_1_0 */


/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1

GL_SINCE(1, 1)
GLF(GLboolean, glAreTexturesResident, GLsizei n, const GLuint *textures, GLboolean *residences);

GL_SINCE(1, 1)
GLF(void, glArrayElement, GLint i);

GL_SINCE(1, 1)
GLF(void, glBindTexture, GLenum target, GLuint texture);

GL_SINCE(1, 1)
GLF(void, glCopyTexImage1D, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);

GL_SINCE(1, 1)
GLF(void, glCopyTexImage2D, GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);

GL_SINCE(1, 1)
GLF(void, glCopyTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);

GL_SINCE(1, 1)
GLF(void, glCopyTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);

GL_SINCE(1, 1)
GLF(void, glDeleteTextures, GLsizei n, const GLuint *textures);

GL_SINCE(1, 1)
GLF(void, glDisableClientState, GLenum array);

GL_SINCE(1, 1)
GLF(void, glDrawArrays, GLenum mode, GLint first, GLsizei count);

GL_SINCE(1, 1)
GLF(void, glDrawElements, GLenum mode, GLsizei count, GLenum type, const void *indices);

GL_SINCE(1, 1)
GLF(void, glEdgeFlagPointer, GLsizei stride, const void *pointer);

GL_SINCE(1, 1)
GLF(void, glEnableClientState, GLenum array);

GL_SINCE(1, 1)
GLF(void, glGenTextures, GLsizei n, GLuint *textures);

GL_SINCE(1, 1)
GLF(void, glGetPointerv, GLenum pname, void* *params);

GL_SINCE(1, 1)
GLF(void, glIndexPointer, GLenum type, GLsizei stride, const void *pointer);

GL_SINCE(1, 1)
GLF(void, glInterleavedArrays, GLenum format, GLsizei stride, const void *pointer);

GL_SINCE(1, 1)
GLF(GLboolean, glIsTexture, GLuint texture);

GL_SINCE(1, 1)
GLF(void, glNormalPointer, GLenum type, GLsizei stride, const void *pointer);

GL_SINCE(1, 1)
GLF(void, glPolygonOffset, GLfloat factor, GLfloat units);

GL_SINCE(1, 1)
GLF(void, glPopClientAttrib, void);

GL_SINCE(1, 1)
GLF(void, glPrioritizeTextures, GLsizei n, const GLuint *textures, const GLclampf *priorities);

GL_SINCE(1, 1)
GLF(void, glPushClientAttrib, GLbitfield mask);

GL_SINCE(1, 1)
GLF(void, glTexCoordPointer, GLint size, GLenum type, GLsizei stride, const void *pointer);

GL_SINCE(1, 1)
GLF(void, glVertexPointer, GLint size, GLenum type, GLsizei stride, const void *pointer);

#endif /* GL_VERSION_1_1 */


/* ----------------------------- GL_VERSION_1_2 ---------------------------- */

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1

#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_RESCALE_NORMAL 0x803A
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E

GL_SINCE(1, 2)
GLF(void, glCopyTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

GL_SINCE(1, 2)
GLF(void, glDrawRangeElements, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);

GL_SINCE(1, 2)
GLF(void, glTexImage3D, GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);

GL_SINCE(1, 2)
GLF(void, glTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);

#endif /* GL_VERSION_1_2 */


/* ----------------------------- GL_VERSION_1_3 ---------------------------- */

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1

#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_SUBTRACT 0x84E7
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
#define GL_MULTISAMPLE_BIT 0x20000000

GL_SINCE(1, 3)
GLF(void, glActiveTexture, GLenum texture);

GL_SINCE(1, 3)
GLF(void, glClientActiveTexture, GLenum texture);

GL_SINCE(1, 3)
GLF(void, glCompressedTexImage1D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);

GL_SINCE(1, 3)
GLF(void, glCompressedTexImage2D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);

GL_SINCE(1, 3)
GLF(void, glCompressedTexImage3D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);

GL_SINCE(1, 3)
GLF(void, glCompressedTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);

GL_SINCE(1, 3)
GLF(void, glCompressedTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);

GL_SINCE(1, 3)
GLF(void, glCompressedTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);

GL_SINCE(1, 3)
GLF(void, glGetCompressedTexImage, GLenum target, GLint lod, void *img);

GL_SINCE(1, 3)
GLF(void, glLoadTransposeMatrixd, const GLdouble m[16]);

GL_SINCE(1, 3)
GLF(void, glLoadTransposeMatrixf, const GLfloat m[16]);

GL_SINCE(1, 3)
GLF(void, glMultTransposeMatrixd, const GLdouble m[16]);

GL_SINCE(1, 3)
GLF(void, glMultTransposeMatrixf, const GLfloat m[16]);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1d,  GLenum target, GLdouble s);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1dv, GLenum target, const GLdouble *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1f,  GLenum target, GLfloat s);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1fv, GLenum target, const GLfloat *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1i,  GLenum target, GLint s);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1iv, GLenum target, const GLint *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1s,  GLenum target, GLshort s);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord1sv, GLenum target, const GLshort *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2d,  GLenum target, GLdouble s, GLdouble t);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2dv, GLenum target, const GLdouble *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2f,  GLenum target, GLfloat s, GLfloat t);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2fv, GLenum target, const GLfloat *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2i,  GLenum target, GLint s, GLint t);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2iv, GLenum target, const GLint *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2s,  GLenum target, GLshort s, GLshort t);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord2sv, GLenum target, const GLshort *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3d,  GLenum target, GLdouble s, GLdouble t, GLdouble r);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3dv, GLenum target, const GLdouble *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3f,  GLenum target, GLfloat s, GLfloat t, GLfloat r);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3fv, GLenum target, const GLfloat *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3i,  GLenum target, GLint s, GLint t, GLint r);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3iv, GLenum target, const GLint *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3s,  GLenum target, GLshort s, GLshort t, GLshort r);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord3sv, GLenum target, const GLshort *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4d,  GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4dv, GLenum target, const GLdouble *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4f,  GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4fv, GLenum target, const GLfloat *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4i,  GLenum target, GLint s, GLint t, GLint r, GLint q);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4iv, GLenum target, const GLint *v);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4s,  GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);

GL_SINCE(1, 3)
GLF(void, glMultiTexCoord4sv, GLenum target, const GLshort *v);

GL_SINCE(1, 3)
GLF(void, glSampleCoverage, GLclampf value, GLboolean invert);

#endif /* GL_VERSION_1_3 */


/* ----------------------------- GL_VERSION_1_4 ---------------------------- */

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1

#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_BLEND_COLOR 0x8005
#define GL_FUNC_ADD 0x8006
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_BLEND_EQUATION 0x8009
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_COMPARE_R_TO_TEXTURE 0x884E

GL_SINCE(1, 4)
GLF(void, glBlendColor, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);

GL_SINCE(1, 4)
GLF(void, glBlendEquation, GLenum mode);

GL_SINCE(1, 4)
GLF(void, glBlendFuncSeparate, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);

GL_SINCE(1, 4)
GLF(void, glFogCoordPointer, GLenum type, GLsizei stride, const void *pointer);

GL_SINCE(1, 4)
GLF(void, glFogCoordd, GLdouble coord);

GL_SINCE(1, 4)
GLF(void, glFogCoorddv, const GLdouble *coord);

GL_SINCE(1, 4)
GLF(void, glFogCoordf, GLfloat coord);

GL_SINCE(1, 4)
GLF(void, glFogCoordfv, const GLfloat *coord);

GL_SINCE(1, 4)
GLF(void, glMultiDrawArrays, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);

GL_SINCE(1, 4)
GLF(void, glMultiDrawElements, GLenum mode, const GLsizei *count, GLenum type, const void *const* indices, GLsizei drawcount);

GL_SINCE(1, 4)
GLF(void, glPointParameterf, GLenum pname, GLfloat param);

GL_SINCE(1, 4)
GLF(void, glPointParameterfv, GLenum pname, const GLfloat *params);

GL_SINCE(1, 4)
GLF(void, glPointParameteri, GLenum pname, GLint param);

GL_SINCE(1, 4)
GLF(void, glPointParameteriv, GLenum pname, const GLint *params);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3b, GLbyte red, GLbyte green, GLbyte blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3bv,const GLbyte *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3d, GLdouble red, GLdouble green, GLdouble blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3dv, const GLdouble *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3f, GLfloat red, GLfloat green, GLfloat blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3fv, const GLfloat *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3i, GLint red, GLint green, GLint blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3iv, const GLint *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3s, GLshort red, GLshort green, GLshort blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3sv, const GLshort *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3ub, GLubyte red, GLubyte green, GLubyte blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3ubv, const GLubyte *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3ui, GLuint red, GLuint green, GLuint blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3uiv, const GLuint *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3us, GLushort red, GLushort green, GLushort blue);

GL_SINCE(1, 4)
GLF(void, glSecondaryColor3usv, const GLushort *v);

GL_SINCE(1, 4)
GLF(void, glSecondaryColorPointer, GLint size, GLenum type, GLsizei stride, const void *pointer);

GL_SINCE(1, 4)
GLF(void, glWindowPos2d, GLdouble x, GLdouble y);

GL_SINCE(1, 4)
GLF(void, glWindowPos2dv, const GLdouble *p);

GL_SINCE(1, 4)
GLF(void, glWindowPos2f, GLfloat x, GLfloat y);

GL_SINCE(1, 4)
GLF(void, glWindowPos2fv, const GLfloat *p);

GL_SINCE(1, 4)
GLF(void, glWindowPos2i, GLint x, GLint y);

GL_SINCE(1, 4)
GLF(void, glWindowPos2iv, const GLint *p);

GL_SINCE(1, 4)
GLF(void, glWindowPos2s, GLshort x, GLshort y);

GL_SINCE(1, 4)
GLF(void, glWindowPos2sv, const GLshort *p);

GL_SINCE(1, 4)
GLF(void, glWindowPos3d, GLdouble x, GLdouble y, GLdouble z);

GL_SINCE(1, 4)
GLF(void, glWindowPos3dv, const GLdouble *p);

GL_SINCE(1, 4)
GLF(void, glWindowPos3f, GLfloat x, GLfloat y, GLfloat z);

GL_SINCE(1, 4)
GLF(void, glWindowPos3fv, const GLfloat *p);

GL_SINCE(1, 4)
GLF(void, glWindowPos3i, GLint x, GLint y, GLint z);

GL_SINCE(1, 4)
GLF(void, glWindowPos3iv, const GLint *p);

GL_SINCE(1, 4)
GLF(void, glWindowPos3s, GLshort x, GLshort y, GLshort z);

GL_SINCE(1, 4)
GLF(void, glWindowPos3sv, const GLshort *p);

#endif /* GL_VERSION_1_4 */


/* ----------------------------- GL_VERSION_1_5 ---------------------------- */

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1

#define GL_CURRENT_FOG_COORD GL_CURRENT_FOG_COORDINATE
#define GL_FOG_COORD GL_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY GL_FOG_COORDINATE_ARRAY
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define GL_FOG_COORD_ARRAY_POINTER GL_FOG_COORDINATE_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY_STRIDE GL_FOG_COORDINATE_ARRAY_STRIDE
#define GL_FOG_COORD_ARRAY_TYPE GL_FOG_COORDINATE_ARRAY_TYPE
#define GL_FOG_COORD_SRC GL_FOG_COORDINATE_SOURCE
#define GL_SRC0_ALPHA GL_SOURCE0_ALPHA
#define GL_SRC0_RGB GL_SOURCE0_RGB
#define GL_SRC1_ALPHA GL_SOURCE1_ALPHA
#define GL_SRC1_RGB GL_SOURCE1_RGB
#define GL_SRC2_ALPHA GL_SOURCE2_ALPHA
#define GL_SRC2_RGB GL_SOURCE2_RGB
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914

typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;

GL_SINCE(1, 5)
GLF(void, glBeginQuery, GLenum target, GLuint id);

GL_SINCE(1, 5)
GLF(void, glBindBuffer, GLenum target, GLuint buffer);

GL_SINCE(1, 5)
GLF(void, glBufferData, GLenum target, GLsizeiptr size, const void* data, GLenum usage);

GL_SINCE(1, 5)
GLF(void, glBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, const void* data);

GL_SINCE(1, 5)
GLF(void, glDeleteBuffers, GLsizei n, const GLuint* buffers);

GL_SINCE(1, 5)
GLF(void, glDeleteQueries, GLsizei n, const GLuint* ids);

GL_SINCE(1, 5)
GLF(void, glEndQuery, GLenum target);

GL_SINCE(1, 5)
GLF(void, glGenBuffers, GLsizei n, GLuint* buffers);

GL_SINCE(1, 5)
GLF(void, glGenQueries, GLsizei n, GLuint* ids);

GL_SINCE(1, 5)
GLF(void, glGetBufferParameteriv, GLenum target, GLenum pname, GLint* params);

GL_SINCE(1, 5)
GLF(void, glGetBufferPointerv,  GLenum target, GLenum pname, void** params);

GL_SINCE(1, 5)
GLF(void, glGetBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, void* data);

GL_SINCE(1, 5)
GLF(void, glGetQueryObjectiv, GLuint id, GLenum pname, GLint* params);

GL_SINCE(1, 5)
GLF(void, glGetQueryObjectuiv, GLuint id, GLenum pname, GLuint* params);

GL_SINCE(1, 5)
GLF(void, glGetQueryiv, GLenum target, GLenum pname, GLint* params);

GL_SINCE(1, 5)
GLF(GLboolean, glIsBuffer, GLuint buffer);

GL_SINCE(1, 5)
GLF(GLboolean, glIsQuery, GLuint id);

GL_SINCE(1, 5)
GLF(void*, glMapBuffer, GLenum target, GLenum access);

GL_SINCE(1, 5)
GLF(GLboolean, glUnmapBuffer, GLenum target);

#endif /* GL_VERSION_1_5 */


/* ----------------------------- GL_VERSION_2_0 ---------------------------- */

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1

#define GL_BLEND_EQUATION_RGB GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5

GL_SINCE(2, 0)
GLF(void, glAttachShader, GLuint program, GLuint shader);

GL_SINCE(2, 0)
GLF(void, glBindAttribLocation, GLuint program, GLuint index, const GLchar* name);

GL_SINCE(2, 0)
GLF(void, glBlendEquationSeparate, GLenum modeRGB, GLenum modeAlpha);

GL_SINCE(2, 0)
GLF(void, glCompileShader, GLuint shader);

GL_SINCE(2, 0)
GLF(GLuint, glCreateProgram, void);

GL_SINCE(2, 0)
GLF(GLuint, glCreateShader,  GLenum type);

GL_SINCE(2, 0)
GLF(void, glDeleteProgram, GLuint program);

GL_SINCE(2, 0)
GLF(void, glDeleteShader, GLuint shader);

GL_SINCE(2, 0)
GLF(void, glDetachShader, GLuint program, GLuint shader);

GL_SINCE(2, 0)
GLF(void, glDisableVertexAttribArray, GLuint index);

GL_SINCE(2, 0)
GLF(void, glDrawBuffers, GLsizei n, const GLenum* bufs);

GL_SINCE(2, 0)
GLF(void, glEnableVertexAttribArray, GLuint index);

GL_SINCE(2, 0)
GLF(void, glGetActiveAttrib, GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name);

GL_SINCE(2, 0)
GLF(void, glGetActiveUniform, GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name);

GL_SINCE(2, 0)
GLF(void, glGetAttachedShaders, GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);

GL_SINCE(2, 0)
GLF(GLint, glGetAttribLocation, GLuint program, const GLchar* name);

GL_SINCE(2, 0)
GLF(void, glGetProgramInfoLog, GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

GL_SINCE(2, 0)
GLF(void, glGetProgramiv, GLuint program, GLenum pname, GLint* param);

GL_SINCE(2, 0)
GLF(void, glGetShaderInfoLog, GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

GL_SINCE(2, 0)
GLF(void, glGetShaderSource, GLuint obj, GLsizei maxLength, GLsizei* length, GLchar* source);

GL_SINCE(2, 0)
GLF(void, glGetShaderiv, GLuint shader, GLenum pname, GLint* param);

GL_SINCE(2, 0)
GLF(GLint, glGetUniformLocation, GLuint program, const GLchar* name);

GL_SINCE(2, 0)
GLF(void, glGetUniformfv, GLuint program, GLint location, GLfloat* params);

GL_SINCE(2, 0)
GLF(void, glGetUniformiv, GLuint program, GLint location, GLint* params);

GL_SINCE(2, 0)
GLF(void, glGetVertexAttribPointerv, GLuint index, GLenum pname, void** pointer);

GL_SINCE(2, 0)
GLF(void, glGetVertexAttribdv, GLuint index, GLenum pname, GLdouble* params);

GL_SINCE(2, 0)
GLF(void, glGetVertexAttribfv, GLuint index, GLenum pname, GLfloat* params);

GL_SINCE(2, 0)
GLF(void, glGetVertexAttribiv, GLuint index, GLenum pname, GLint* params);

GL_SINCE(2, 0)
GLF(GLboolean, glIsProgram, GLuint program);

GL_SINCE(2, 0)
GLF(GLboolean, glIsShader, GLuint shader);

GL_SINCE(2, 0)
GLF(void, glLinkProgram, GLuint program);

GL_SINCE(2, 0)
GLF(void, glShaderSource, GLuint shader, GLsizei count, const GLchar *const* string, const GLint* length);

GL_SINCE(2, 0)
GLF(void, glStencilFuncSeparate, GLenum face, GLenum func, GLint ref, GLuint mask);

GL_SINCE(2, 0)
GLF(void, glStencilMaskSeparate, GLenum face, GLuint mask);

GL_SINCE(2, 0)
GLF(void, glStencilOpSeparate, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);

GL_SINCE(2, 0)
GLF(void, glUniform1f, GLint location, GLfloat v0);

GL_SINCE(2, 0)
GLF(void, glUniform1fv, GLint location, GLsizei count, const GLfloat* value);

GL_SINCE(2, 0)
GLF(void, glUniform1i, GLint location, GLint v0);

GL_SINCE(2, 0)
GLF(void, glUniform1iv, GLint location, GLsizei count, const GLint* value);

GL_SINCE(2, 0)
GLF(void, glUniform2f, GLint location, GLfloat v0, GLfloat v1);

GL_SINCE(2, 0)
GLF(void, glUniform2fv, GLint location, GLsizei count, const GLfloat* value);

GL_SINCE(2, 0)
GLF(void, glUniform2i, GLint location, GLint v0, GLint v1);

GL_SINCE(2, 0)
GLF(void, glUniform2iv, GLint location, GLsizei count, const GLint* value);

GL_SINCE(2, 0)
GLF(void, glUniform3f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);

GL_SINCE(2, 0)
GLF(void, glUniform3fv, GLint location, GLsizei count, const GLfloat* value);

GL_SINCE(2, 0)
GLF(void, glUniform3i, GLint location, GLint v0, GLint v1, GLint v2);

GL_SINCE(2, 0)
GLF(void, glUniform3iv, GLint location, GLsizei count, const GLint* value);

GL_SINCE(2, 0)
GLF(void, glUniform4f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);

GL_SINCE(2, 0)
GLF(void, glUniform4fv, GLint location, GLsizei count, const GLfloat* value);

GL_SINCE(2, 0)
GLF(void, glUniform4i, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);

GL_SINCE(2, 0)
GLF(void, glUniform4iv, GLint location, GLsizei count, const GLint* value);

GL_SINCE(2, 0)
GLF(void, glUniformMatrix2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

GL_SINCE(2, 0)
GLF(void, glUniformMatrix3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

GL_SINCE(2, 0)
GLF(void, glUniformMatrix4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

GL_SINCE(2, 0)
GLF(void, glUseProgram, GLuint program);

GL_SINCE(2, 0)
GLF(void, glValidateProgram, GLuint program);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib1d, GLuint index, GLdouble x);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib1dv, GLuint index, const GLdouble* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib1f, GLuint index, GLfloat x);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib1fv, GLuint index, const GLfloat* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib1s, GLuint index, GLshort x);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib1sv, GLuint index, const GLshort* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib2d, GLuint index, GLdouble x, GLdouble y);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib2dv, GLuint index, const GLdouble* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib2f, GLuint index, GLfloat x, GLfloat y);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib2fv, GLuint index, const GLfloat* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib2s, GLuint index, GLshort x, GLshort y);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib2sv, GLuint index, const GLshort* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib3d, GLuint index, GLdouble x, GLdouble y, GLdouble z);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib3dv, GLuint index, const GLdouble* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib3f, GLuint index, GLfloat x, GLfloat y, GLfloat z);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib3fv, GLuint index, const GLfloat* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib3s, GLuint index, GLshort x, GLshort y, GLshort z);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib3sv, GLuint index, const GLshort* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4Nbv, GLuint index, const GLbyte* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4Niv, GLuint index, const GLint* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4Nsv, GLuint index, const GLshort* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4Nub, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4Nubv, GLuint index, const GLubyte* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4Nuiv, GLuint index, const GLuint* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4Nusv, GLuint index, const GLushort* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4bv, GLuint index, const GLbyte* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4d, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4dv, GLuint index, const GLdouble* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4f, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4fv, GLuint index, const GLfloat* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4iv, GLuint index, const GLint* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4s, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4sv, GLuint index, const GLshort* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4ubv, GLuint index, const GLubyte* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4uiv, GLuint index, const GLuint* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttrib4usv, GLuint index, const GLushort* v);

GL_SINCE(2, 0)
GLF(void, glVertexAttribPointer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);

#endif /* GL_VERSION_2_0 */


/* ----------------------------- GL_VERSION_2_1 ---------------------------- */

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1

#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B

GL_SINCE(2, 1)
GLF(void, glUniformMatrix2x3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

GL_SINCE(2, 1)
GLF(void, glUniformMatrix2x4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

GL_SINCE(2, 1)
GLF(void, glUniformMatrix3x2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

GL_SINCE(2, 1)
GLF(void, glUniformMatrix3x4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

GL_SINCE(2, 1)
GLF(void, glUniformMatrix4x2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

GL_SINCE(2, 1)
GLF(void, glUniformMatrix4x3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

#endif /* GL_VERSION_2_1 */


/* ----------------------------- GL_VERSION_3_0 ---------------------------- */

#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1

#define GL_CLIP_DISTANCE0 GL_CLIP_PLANE0
#define GL_CLIP_DISTANCE1 GL_CLIP_PLANE1
#define GL_CLIP_DISTANCE2 GL_CLIP_PLANE2
#define GL_CLIP_DISTANCE3 GL_CLIP_PLANE3
#define GL_CLIP_DISTANCE4 GL_CLIP_PLANE4
#define GL_CLIP_DISTANCE5 GL_CLIP_PLANE5
#define GL_COMPARE_REF_TO_TEXTURE GL_COMPARE_R_TO_TEXTURE_ARB
#define GL_MAX_CLIP_DISTANCES GL_MAX_CLIP_PLANES
#define GL_MAX_VARYING_COMPONENTS GL_MAX_VARYING_FLOATS
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_INDEX 0x8222
#define GL_DEPTH_BUFFER 0x8223
#define GL_STENCIL_BUFFER 0x8224
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_VERTEX_ARRAY_BINDING 0x85B5
#define GL_RGBA32F 0x8814
#define GL_RGB32F 0x8815
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_SRGB 0x8C40
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57
#define GL_RGBA32UI 0x8D70
#define GL_RGB32UI 0x8D71
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGB32I 0x8D83
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_ALPHA_INTEGER 0x8D97
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16

GL_SINCE(3, 0)
GLF(void, glBeginConditionalRender, GLuint id, GLenum mode);

GL_SINCE(3, 0)
GLF(void, glBeginTransformFeedback, GLenum primitiveMode);

GL_SINCE(3, 0)
GLF(void, glBindFragDataLocation, GLuint program, GLuint colorNumber, const GLchar* name);

GL_SINCE(3, 0)
GLF(void, glBindFramebuffer, GLenum target, GLuint framebuffer);

GL_SINCE(3, 0)
GLF(void, glBindRenderbuffer, GLenum target, GLuint renderbuffer);

GL_SINCE(3, 0)
GLF(void, glBindVertexArray, GLuint array);

GL_SINCE(3, 0)
GLF(void, glBlitFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

GL_SINCE(3, 0)
GLF(GLenum, glCheckFramebufferStatus, GLenum target);

GL_SINCE(3, 0)
GLF(void, glClampColor, GLenum target, GLenum clamp);

GL_SINCE(3, 0)
GLF(void, glClearBufferfi, GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil);

GL_SINCE(3, 0)
GLF(void, glClearBufferfv, GLenum buffer, GLint drawBuffer, const GLfloat* value);

GL_SINCE(3, 0)
GLF(void, glClearBufferiv, GLenum buffer, GLint drawBuffer, const GLint* value);

GL_SINCE(3, 0)
GLF(void, glClearBufferuiv, GLenum buffer, GLint drawBuffer, const GLuint* value);

GL_SINCE(3, 0)
GLF(void, glColorMaski, GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);

GL_SINCE(3, 0)
GLF(void, glDeleteFramebuffers, GLsizei n, const GLuint* framebuffers);

GL_SINCE(3, 0)
GLF(void, glDeleteRenderbuffers, GLsizei n, const GLuint* renderbuffers);

GL_SINCE(3, 0)
GLF(void, glDeleteVertexArrays, GLsizei n, const GLuint* arrays);

GL_SINCE(3, 0)
GLF(void, glDisablei, GLenum cap, GLuint index);

GL_SINCE(3, 0)
GLF(void, glEnablei, GLenum cap, GLuint index);

GL_SINCE(3, 0)
GLF(void, glEndConditionalRender, void);

GL_SINCE(3, 0)
GLF(void, glEndTransformFeedback, void);

GL_SINCE(3, 0)
GLF(void, glFramebufferRenderbuffer, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);

GL_SINCE(3, 0)
GLF(void, glFramebufferTexture1D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);

GL_SINCE(3, 0)
GLF(void, glFramebufferTexture2D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);

GL_SINCE(3, 0)
GLF(void, glFramebufferTexture3D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer);

GL_SINCE(3, 0)
GLF(void, glFramebufferTextureLayer, GLenum target,GLenum attachment, GLuint texture,GLint level,GLint layer);

GL_SINCE(3, 0)
GLF(void, glGenerateMipmap, GLenum target);

GL_SINCE(3, 0)
GLF(void, glGenFramebuffers, GLsizei n, GLuint* framebuffers);

GL_SINCE(3, 0)
GLF(void, glGenRenderbuffers, GLsizei n, GLuint* renderbuffers);

GL_SINCE(3, 0)
GLF(void, glGenVertexArrays, GLsizei n, GLuint* arrays);

GL_SINCE(3, 0)
GLF(void, glGetBooleani_v, GLenum pname, GLuint index, GLboolean* data);

GL_SINCE(3, 0)
GLF(GLint, glGetFragDataLocation, GLuint program, const GLchar* name);

GL_SINCE(3, 0)
GLF(void, glGetFramebufferAttachmentParameteriv, GLenum target, GLenum attachment, GLenum pname, GLint* params);

GL_SINCE(3, 0)
GLF(void, glGetRenderbufferParameteriv, GLenum target, GLenum pname, GLint* params);

GL_SINCE(3, 0)
GLF(const GLubyte*, glGetStringi, GLenum name, GLuint index);

GL_SINCE(3, 0)
GLF(void, glGetTexParameterIiv, GLenum target, GLenum pname, GLint* params);

GL_SINCE(3, 0)
GLF(void, glGetTexParameterIuiv, GLenum target, GLenum pname, GLuint* params);

GL_SINCE(3, 0)
GLF(void, glGetTransformFeedbackVarying, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);

GL_SINCE(3, 0)
GLF(void, glGetUniformuiv, GLuint program, GLint location, GLuint* params);

GL_SINCE(3, 0)
GLF(void, glGetVertexAttribIiv, GLuint index, GLenum pname, GLint* params);

GL_SINCE(3, 0)
GLF(void, glGetVertexAttribIuiv, GLuint index, GLenum pname, GLuint* params);

GL_SINCE(3, 0)
GLF(GLboolean, glIsEnabledi, GLenum cap, GLuint index);

GL_SINCE(3, 0)
GLF(GLboolean, glIsFramebuffer, GLuint framebuffer);

GL_SINCE(3, 0)
GLF(GLboolean, glIsRenderbuffer, GLuint renderbuffer);

GL_SINCE(3, 0)
GLF(GLboolean, glIsVertexArray, GLuint array);

GL_SINCE(3, 0)
GLF(void, glRenderbufferStorage, GLenum target, GLenum internalformat, GLsizei width, GLsizei height);

GL_SINCE(3, 0)
GLF(void, glRenderbufferStorageMultisample, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);

GL_SINCE(3, 0)
GLF(void, glTexParameterIiv, GLenum target, GLenum pname, const GLint* params);

GL_SINCE(3, 0)
GLF(void, glTexParameterIuiv, GLenum target, GLenum pname, const GLuint* params);

GL_SINCE(3, 0)
GLF(void, glTransformFeedbackVaryings, GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);

GL_SINCE(3, 0)
GLF(void, glUniform1ui, GLint location, GLuint v0);

GL_SINCE(3, 0)
GLF(void, glUniform1uiv, GLint location, GLsizei count, const GLuint* value);

GL_SINCE(3, 0)
GLF(void, glUniform2ui, GLint location, GLuint v0, GLuint v1);

GL_SINCE(3, 0)
GLF(void, glUniform2uiv, GLint location, GLsizei count, const GLuint* value);

GL_SINCE(3, 0)
GLF(void, glUniform3ui, GLint location, GLuint v0, GLuint v1, GLuint v2);

GL_SINCE(3, 0)
GLF(void, glUniform3uiv, GLint location, GLsizei count, const GLuint* value);

GL_SINCE(3, 0)
GLF(void, glUniform4ui, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);

GL_SINCE(3, 0)
GLF(void, glUniform4uiv, GLint location, GLsizei count, const GLuint* value);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI1i, GLuint index, GLint v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI1iv, GLuint index, const GLint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI1ui, GLuint index, GLuint v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI1uiv, GLuint index, const GLuint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI2i, GLuint index, GLint v0, GLint v1);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI2iv, GLuint index, const GLint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI2ui, GLuint index, GLuint v0, GLuint v1);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI2uiv, GLuint index, const GLuint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI3i, GLuint index, GLint v0, GLint v1, GLint v2);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI3iv, GLuint index, const GLint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI3ui, GLuint index, GLuint v0, GLuint v1, GLuint v2);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI3uiv, GLuint index, const GLuint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4bv, GLuint index, const GLbyte* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4i, GLuint index, GLint v0, GLint v1, GLint v2, GLint v3);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4iv, GLuint index, const GLint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4sv, GLuint index, const GLshort* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4ubv, GLuint index, const GLubyte* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4ui, GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4uiv, GLuint index, const GLuint* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribI4usv, GLuint index, const GLushort* v0);

GL_SINCE(3, 0)
GLF(void, glVertexAttribIPointer, GLuint index, GLint size, GLenum type, GLsizei stride, const void*pointer);

#endif /* GL_VERSION_3_0 */


/* ----------------------------- GL_VERSION_3_1 ---------------------------- */

#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1

#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT 0x8C2E
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_RED_SNORM 0x8F90
#define GL_RG_SNORM 0x8F91
#define GL_RGB_SNORM 0x8F92
#define GL_RGBA_SNORM 0x8F93
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121

GL_SINCE(3, 1)
GLF(void, glDrawArraysInstanced, GLenum mode, GLint first, GLsizei count, GLsizei primcount);

GL_SINCE(3, 1)
GLF(void, glDrawElementsInstanced, GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);

GL_SINCE(3, 1)
GLF(void, glPrimitiveRestartIndex, GLuint buffer);

GL_SINCE(3, 1)
GLF(void, glTexBuffer, GLenum target, GLenum internalFormat, GLuint buffer);

#endif /* GL_VERSION_3_1 */


/* ----------------------------- GL_VERSION_3_2 ---------------------------- */

#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1

#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_CONTEXT_PROFILE_MASK 0x9126

GL_SINCE(3, 2)
GLF(void, glDrawElementsBaseVertex, GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);

GL_SINCE(3, 2)
GLF(void, glDrawElementsInstancedBaseVertex, GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);

GL_SINCE(3, 2)
GLF(void, glDrawRangeElementsBaseVertex, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);

GL_SINCE(3, 2)
GLF(void, glFramebufferTexture, GLenum target, GLenum attachment, GLuint texture, GLint level);

GL_SINCE(3, 2)
GLF(void, glGetBufferParameteri64v, GLenum target, GLenum value, GLint64 * data);

GL_SINCE(3, 2)
GLF(void, glGetInteger64i_v, GLenum pname, GLuint index, GLint64 * data);

GL_SINCE(3, 2)
GLF(void, glMultiDrawElementsBaseVertex, GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);

#endif /* GL_VERSION_3_2 */


/* ----------------------------- GL_VERSION_3_3 ---------------------------- */

#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_SAMPLER_BINDING 0x8919
#define GL_RGB10_A2UI 0x906F

GL_SINCE(3, 3)
GLF(void, glBindSampler, GLuint unit, GLuint sampler);

GL_SINCE(3, 3)
GLF(void, glDeleteSamplers, GLsizei count, const GLuint* samplers);

GL_SINCE(3, 3)
GLF(void, glGenSamplers, GLsizei count, GLuint* samplers);

GL_SINCE(3, 3)
GLF(void, glGetSamplerParameterIiv, GLuint sampler, GLenum pname, GLint* params);

GL_SINCE(3, 3)
GLF(void, glGetSamplerParameterIuiv, GLuint sampler, GLenum pname, GLuint* params);

GL_SINCE(3, 3)
GLF(void, glGetSamplerParameterfv, GLuint sampler, GLenum pname, GLfloat* params);

GL_SINCE(3, 3)
GLF(void, glGetSamplerParameteriv, GLuint sampler, GLenum pname, GLint* params);

GL_SINCE(3, 3)
GLF(GLboolean, glIsSampler, GLuint sampler);

GL_SINCE(3, 3)
GLF(void, glSamplerParameterIiv, GLuint sampler, GLenum pname, const GLint* params);

GL_SINCE(3, 3)
GLF(void, glSamplerParameterIuiv, GLuint sampler, GLenum pname, const GLuint* params);

GL_SINCE(3, 3)
GLF(void, glSamplerParameterf, GLuint sampler, GLenum pname, GLfloat param);

GL_SINCE(3, 3)
GLF(void, glSamplerParameterfv, GLuint sampler, GLenum pname, const GLfloat* params);

GL_SINCE(3, 3)
GLF(void, glSamplerParameteri, GLuint sampler, GLenum pname, GLint param);

GL_SINCE(3, 3)
GLF(void, glSamplerParameteriv, GLuint sampler, GLenum pname, const GLint* params);

GL_SINCE(3, 3)
GLF(void, glVertexAttribDivisor, GLuint index, GLuint divisor);

#endif /* GL_VERSION_3_3 */


/* ----------------------------- GL_VERSION_4_0 ---------------------------- */

#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1

#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS 0x8F9F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

GL_SINCE(4, 0)
GLF(void, glBlendEquationSeparatei, GLuint buf, GLenum modeRGB, GLenum modeAlpha);

GL_SINCE(4, 0)
GLF(void, glBlendEquationi, GLuint buf, GLenum mode);

GL_SINCE(4, 0)
GLF(void, glBlendFuncSeparatei, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

GL_SINCE(4, 0)
GLF(void, glBlendFunci, GLuint buf, GLenum src, GLenum dst);

GL_SINCE(4, 0)
GLF(void, glMinSampleShading, GLclampf value);

#endif /* GL_VERSION_4_0 */


/* ----------------------------- GL_VERSION_4_1 ---------------------------- */

#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1

#endif /* GL_VERSION_4_1 */


/* ----------------------------- GL_VERSION_4_2 ---------------------------- */

#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1

#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37

#endif /* GL_VERSION_4_2 */


/* ----------------------------- GL_VERSION_4_3 ---------------------------- */

#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1

#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E

#endif /* GL_VERSION_4_3 */


/* ----------------------------- GL_VERSION_4_4 ---------------------------- */

#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1

#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
#define GL_TEXTURE_BUFFER_BINDING 0x8C2A

#endif /* GL_VERSION_4_4 */


/* ----------------------------- GL_VERSION_4_5 ---------------------------- */

#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1

#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004


GL_SINCE(4, 5)
GLF(GLenum, glGetGraphicsResetStatus, void);

GL_SINCE(4, 5)
GLF(void, glGetnCompressedTexImage, GLenum target, GLint lod, GLsizei bufSize, GLvoid *pixels);

GL_SINCE(4, 5)
GLF(void, glGetnTexImage, GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *pixels);

GL_SINCE(4, 5)
GLF(void, glGetnUniformdv, GLuint program, GLint location, GLsizei bufSize, GLdouble *params);

#endif /* GL_VERSION_4_5 */

/* ----------------------------- GL_VERSION_4_6 ---------------------------- */

#ifndef GL_VERSION_4_6
#define GL_VERSION_4_6 1

#define GL_CONTEXT_FLAG_NO_ERROR_BIT 0x00000008
#define GL_PARAMETER_BUFFER 0x80EE
#define GL_PARAMETER_BUFFER_BINDING 0x80EF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED
#define GL_VERTICES_SUBMITTED 0x82EE
#define GL_PRIMITIVES_SUBMITTED 0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS 0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES 0x82F7
#define GL_TEXTURE_MAX_ANISOTROPY 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY 0x84FF
#define GL_POLYGON_OFFSET_CLAMP 0x8E1B
#define GL_SHADER_BINARY_FORMAT_SPIR_V 0x9551
#define GL_SPIR_V_BINARY 0x9552
#define GL_SPIR_V_EXTENSIONS 0x9553
#define GL_NUM_SPIR_V_EXTENSIONS 0x9554

GL_SINCE(4, 6)
GLF(void, glMultiDrawArraysIndirectCount, GLenum mode, const GLvoid *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);

GL_SINCE(4, 6)
GLF(void, glMultiDrawElementsIndirectCount, GLenum mode, GLenum type, const GLvoid *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);

GL_SINCE(4, 6)
GLF(void, glSpecializeShader, GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);

#endif /* GL_VERSION_4_6 */


#undef GLF

#endif
