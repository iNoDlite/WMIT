/***************************************************************************
*	Notice: This file has been slightly modified from the original.
*
* GLee.h 
* GLee (OpenGL Easy Extension library)        
* Version : 5.4
*
* Copyright (c)2009  Ben Woodhouse  All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are 
* met:
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer as
* the first lines of this file unmodified.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY BEN WOODHOUSE ``AS IS'' AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL BEN WOODHOUSE BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

* Web: http://elf-stone.com/glee.php
*
***************************************************************************/

#ifndef __glee_h_
#define __glee_h_

#ifdef __gl_h_
	#error gl.h included before glee.h
#endif

#ifdef __glext_h_
	#error glext.h included before glee.h
#endif

#ifdef __wglext_h_
	#error wglext.h included before glee.h
#endif

#ifdef __glxext_h_
	#error glxext.h included before glee.h
#endif

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#include <GL/gl.h>
#elif defined(__APPLE__) || defined(__APPLE_CC__)
    #define GL_GLEXT_LEGACY
	#include <OpenGL/gl.h>
#else // GLX
	#define __glext_h_  /* prevent glext.h from being included  */
	#define __glxext_h_ /* prevent glxext.h from being included */
	#define GLX_GLXEXT_PROTOTYPES
    #define __gl_glext_h_
    #define __glx_glxext_h_
	#include <GL/gl.h>
	#include <GL/glx.h>

// Clean up some of Xlib's pollution to be Qt friendly
	#ifdef Bool
	# undef Bool
	#endif
	#ifdef Status
	# undef Status
	#endif
	#ifdef True
	# undef True
	#endif
	#ifdef False
	# undef False
	#endif
	#ifdef QueuedAlready
	# undef QueuedAlready
	#endif
	#ifdef QueuedAfterReading
	# undef QueuedAfterReading
	#endif
	#ifdef QueuedAfterFlush
	# undef QueuedAfterFlush
	#endif
	#ifdef None
	# undef None
	#endif
	#ifdef KeyPress
	# undef KeyPress
	#endif
	#ifdef KeyRelease
	# undef KeyRelease
	#endif
	#ifdef FocusIn
	# undef FocusIn
	#endif
	#ifdef FocusOut
	# undef FocusOut
	#endif
	#ifdef FontChange
	# undef FontChange
	#endif
	#ifdef Unsorted
	# undef Unsorted
	#endif
	#ifdef CursorShape
	# undef CursorShape
	#endif
#endif

#ifndef APIENTRY
	#define APIENTRY
#endif

#ifndef APIENTRYP
	#define APIENTRYP APIENTRY *
#endif

#define GLEE_EXTERN extern

#ifdef __cplusplus
	extern "C" {		/* begin C linkage */
#endif

#define GLEE_LINK_FAIL 0
#define GLEE_LINK_PARTIAL 1
#define GLEE_LINK_COMPLETE 2

/* Extension querying variables */

GLEE_EXTERN GLboolean _GLEE_VERSION_1_2;
GLEE_EXTERN GLboolean _GLEE_ARB_imaging;
GLEE_EXTERN GLboolean _GLEE_VERSION_1_3;
GLEE_EXTERN GLboolean _GLEE_VERSION_1_4;
GLEE_EXTERN GLboolean _GLEE_VERSION_1_5;
GLEE_EXTERN GLboolean _GLEE_VERSION_2_0;
GLEE_EXTERN GLboolean _GLEE_VERSION_2_1;
GLEE_EXTERN GLboolean _GLEE_VERSION_3_0;
GLEE_EXTERN GLboolean _GLEE_ARB_multitexture;
GLEE_EXTERN GLboolean _GLEE_ARB_transpose_matrix;
GLEE_EXTERN GLboolean _GLEE_ARB_multisample;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_add;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_cube_map;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_compression;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_border_clamp;
GLEE_EXTERN GLboolean _GLEE_ARB_point_parameters;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_blend;
GLEE_EXTERN GLboolean _GLEE_ARB_matrix_palette;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_combine;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_crossbar;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_dot3;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_mirrored_repeat;
GLEE_EXTERN GLboolean _GLEE_ARB_depth_texture;
GLEE_EXTERN GLboolean _GLEE_ARB_shadow;
GLEE_EXTERN GLboolean _GLEE_ARB_shadow_ambient;
GLEE_EXTERN GLboolean _GLEE_ARB_window_pos;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_program;
GLEE_EXTERN GLboolean _GLEE_ARB_fragment_program;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_buffer_object;
GLEE_EXTERN GLboolean _GLEE_ARB_occlusion_query;
GLEE_EXTERN GLboolean _GLEE_ARB_shader_objects;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_shader;
GLEE_EXTERN GLboolean _GLEE_ARB_fragment_shader;
GLEE_EXTERN GLboolean _GLEE_ARB_shading_language_100;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_non_power_of_two;
GLEE_EXTERN GLboolean _GLEE_ARB_point_sprite;
GLEE_EXTERN GLboolean _GLEE_ARB_fragment_program_shadow;
GLEE_EXTERN GLboolean _GLEE_ARB_draw_buffers;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_rectangle;
GLEE_EXTERN GLboolean _GLEE_ARB_color_buffer_float;
GLEE_EXTERN GLboolean _GLEE_ARB_half_float_pixel;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_float;
GLEE_EXTERN GLboolean _GLEE_ARB_pixel_buffer_object;
GLEE_EXTERN GLboolean _GLEE_ARB_depth_buffer_float;
GLEE_EXTERN GLboolean _GLEE_ARB_draw_instanced;
GLEE_EXTERN GLboolean _GLEE_ARB_framebuffer_object;
GLEE_EXTERN GLboolean _GLEE_ARB_framebuffer_sRGB;
GLEE_EXTERN GLboolean _GLEE_ARB_geometry_shader4;
GLEE_EXTERN GLboolean _GLEE_ARB_half_float_vertex;
GLEE_EXTERN GLboolean _GLEE_ARB_instanced_arrays;
GLEE_EXTERN GLboolean _GLEE_ARB_map_buffer_range;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_buffer_object;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_compression_rgtc;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_rg;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_array_object;
GLEE_EXTERN GLboolean _GLEE_EXT_abgr;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_color;
GLEE_EXTERN GLboolean _GLEE_EXT_polygon_offset;
GLEE_EXTERN GLboolean _GLEE_EXT_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_texture3D;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_filter4;
GLEE_EXTERN GLboolean _GLEE_EXT_subtexture;
GLEE_EXTERN GLboolean _GLEE_EXT_copy_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_histogram;
GLEE_EXTERN GLboolean _GLEE_EXT_convolution;
GLEE_EXTERN GLboolean _GLEE_SGI_color_matrix;
GLEE_EXTERN GLboolean _GLEE_SGI_color_table;
GLEE_EXTERN GLboolean _GLEE_SGIS_pixel_texture;
GLEE_EXTERN GLboolean _GLEE_SGIX_pixel_texture;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture4D;
GLEE_EXTERN GLboolean _GLEE_SGI_texture_color_table;
GLEE_EXTERN GLboolean _GLEE_EXT_cmyka;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_object;
GLEE_EXTERN GLboolean _GLEE_SGIS_detail_texture;
GLEE_EXTERN GLboolean _GLEE_SGIS_sharpen_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_packed_pixels;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_lod;
GLEE_EXTERN GLboolean _GLEE_SGIS_multisample;
GLEE_EXTERN GLboolean _GLEE_EXT_rescale_normal;
GLEE_EXTERN GLboolean _GLEE_EXT_vertex_array;
GLEE_EXTERN GLboolean _GLEE_EXT_misc_attribute;
GLEE_EXTERN GLboolean _GLEE_SGIS_generate_mipmap;
GLEE_EXTERN GLboolean _GLEE_SGIX_clipmap;
GLEE_EXTERN GLboolean _GLEE_SGIX_shadow;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_edge_clamp;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_border_clamp;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_minmax;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_subtract;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_logic_op;
GLEE_EXTERN GLboolean _GLEE_SGIX_interlace;
GLEE_EXTERN GLboolean _GLEE_SGIX_pixel_tiles;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_select;
GLEE_EXTERN GLboolean _GLEE_SGIX_sprite;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_multi_buffer;
GLEE_EXTERN GLboolean _GLEE_EXT_point_parameters;
GLEE_EXTERN GLboolean _GLEE_SGIS_point_parameters;
GLEE_EXTERN GLboolean _GLEE_SGIX_instruments;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_scale_bias;
GLEE_EXTERN GLboolean _GLEE_SGIX_framezoom;
GLEE_EXTERN GLboolean _GLEE_SGIX_tag_sample_buffer;
GLEE_EXTERN GLboolean _GLEE_FfdMaskSGIX;
GLEE_EXTERN GLboolean _GLEE_SGIX_polynomial_ffd;
GLEE_EXTERN GLboolean _GLEE_SGIX_reference_plane;
GLEE_EXTERN GLboolean _GLEE_SGIX_flush_raster;
GLEE_EXTERN GLboolean _GLEE_SGIX_depth_texture;
GLEE_EXTERN GLboolean _GLEE_SGIS_fog_function;
GLEE_EXTERN GLboolean _GLEE_SGIX_fog_offset;
GLEE_EXTERN GLboolean _GLEE_HP_image_transform;
GLEE_EXTERN GLboolean _GLEE_HP_convolution_border_modes;
GLEE_EXTERN GLboolean _GLEE_INGR_palette_buffer;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_add_env;
GLEE_EXTERN GLboolean _GLEE_EXT_color_subtable;
GLEE_EXTERN GLboolean _GLEE_PGI_vertex_hints;
GLEE_EXTERN GLboolean _GLEE_PGI_misc_hints;
GLEE_EXTERN GLboolean _GLEE_EXT_paletted_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_clip_volume_hint;
GLEE_EXTERN GLboolean _GLEE_SGIX_list_priority;
GLEE_EXTERN GLboolean _GLEE_SGIX_ir_instrument1;
GLEE_EXTERN GLboolean _GLEE_SGIX_calligraphic_fragment;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_lod_bias;
GLEE_EXTERN GLboolean _GLEE_SGIX_shadow_ambient;
GLEE_EXTERN GLboolean _GLEE_EXT_index_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_index_material;
GLEE_EXTERN GLboolean _GLEE_EXT_index_func;
GLEE_EXTERN GLboolean _GLEE_EXT_index_array_formats;
GLEE_EXTERN GLboolean _GLEE_EXT_compiled_vertex_array;
GLEE_EXTERN GLboolean _GLEE_EXT_cull_vertex;
GLEE_EXTERN GLboolean _GLEE_SGIX_ycrcb;
GLEE_EXTERN GLboolean _GLEE_SGIX_fragment_lighting;
GLEE_EXTERN GLboolean _GLEE_IBM_rasterpos_clip;
GLEE_EXTERN GLboolean _GLEE_HP_texture_lighting;
GLEE_EXTERN GLboolean _GLEE_EXT_draw_range_elements;
GLEE_EXTERN GLboolean _GLEE_WIN_phong_shading;
GLEE_EXTERN GLboolean _GLEE_WIN_specular_fog;
GLEE_EXTERN GLboolean _GLEE_EXT_light_texture;
GLEE_EXTERN GLboolean _GLEE_SGIX_blend_alpha_minmax;
GLEE_EXTERN GLboolean _GLEE_SGIX_impact_pixel_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_bgra;
GLEE_EXTERN GLboolean _GLEE_SGIX_async;
GLEE_EXTERN GLboolean _GLEE_SGIX_async_pixel;
GLEE_EXTERN GLboolean _GLEE_SGIX_async_histogram;
GLEE_EXTERN GLboolean _GLEE_INTEL_texture_scissor;
GLEE_EXTERN GLboolean _GLEE_INTEL_parallel_arrays;
GLEE_EXTERN GLboolean _GLEE_HP_occlusion_test;
GLEE_EXTERN GLboolean _GLEE_EXT_pixel_transform;
GLEE_EXTERN GLboolean _GLEE_EXT_pixel_transform_color_table;
GLEE_EXTERN GLboolean _GLEE_EXT_shared_texture_palette;
GLEE_EXTERN GLboolean _GLEE_EXT_separate_specular_color;
GLEE_EXTERN GLboolean _GLEE_EXT_secondary_color;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_perturb_normal;
GLEE_EXTERN GLboolean _GLEE_EXT_multi_draw_arrays;
GLEE_EXTERN GLboolean _GLEE_EXT_fog_coord;
GLEE_EXTERN GLboolean _GLEE_REND_screen_coordinates;
GLEE_EXTERN GLboolean _GLEE_EXT_coordinate_frame;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env_combine;
GLEE_EXTERN GLboolean _GLEE_APPLE_specular_vector;
GLEE_EXTERN GLboolean _GLEE_APPLE_transform_hint;
GLEE_EXTERN GLboolean _GLEE_SGIX_fog_scale;
GLEE_EXTERN GLboolean _GLEE_SUNX_constant_data;
GLEE_EXTERN GLboolean _GLEE_SUN_global_alpha;
GLEE_EXTERN GLboolean _GLEE_SUN_triangle_list;
GLEE_EXTERN GLboolean _GLEE_SUN_vertex;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_func_separate;
GLEE_EXTERN GLboolean _GLEE_INGR_color_clamp;
GLEE_EXTERN GLboolean _GLEE_INGR_interlace_read;
GLEE_EXTERN GLboolean _GLEE_EXT_stencil_wrap;
GLEE_EXTERN GLboolean _GLEE_EXT_422_pixels;
GLEE_EXTERN GLboolean _GLEE_NV_texgen_reflection;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_cube_map;
GLEE_EXTERN GLboolean _GLEE_SUN_convolution_border_modes;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env_add;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_lod_bias;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_filter_anisotropic;
GLEE_EXTERN GLboolean _GLEE_EXT_vertex_weighting;
GLEE_EXTERN GLboolean _GLEE_NV_light_max_exponent;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_array_range;
GLEE_EXTERN GLboolean _GLEE_NV_register_combiners;
GLEE_EXTERN GLboolean _GLEE_NV_fog_distance;
GLEE_EXTERN GLboolean _GLEE_NV_texgen_emboss;
GLEE_EXTERN GLboolean _GLEE_NV_blend_square;
GLEE_EXTERN GLboolean _GLEE_NV_texture_env_combine4;
GLEE_EXTERN GLboolean _GLEE_MESA_resize_buffers;
GLEE_EXTERN GLboolean _GLEE_MESA_window_pos;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_s3tc;
GLEE_EXTERN GLboolean _GLEE_IBM_cull_vertex;
GLEE_EXTERN GLboolean _GLEE_IBM_multimode_draw_arrays;
GLEE_EXTERN GLboolean _GLEE_IBM_vertex_array_lists;
GLEE_EXTERN GLboolean _GLEE_SGIX_subsample;
GLEE_EXTERN GLboolean _GLEE_SGIX_ycrcb_subsample;
GLEE_EXTERN GLboolean _GLEE_SGIX_ycrcba;
GLEE_EXTERN GLboolean _GLEE_SGI_depth_pass_instrument;
GLEE_EXTERN GLboolean _GLEE_3DFX_texture_compression_FXT1;
GLEE_EXTERN GLboolean _GLEE_3DFX_multisample;
GLEE_EXTERN GLboolean _GLEE_3DFX_tbuffer;
GLEE_EXTERN GLboolean _GLEE_EXT_multisample;
GLEE_EXTERN GLboolean _GLEE_SGIX_vertex_preclip;
GLEE_EXTERN GLboolean _GLEE_SGIX_convolution_accuracy;
GLEE_EXTERN GLboolean _GLEE_SGIX_resample;
GLEE_EXTERN GLboolean _GLEE_SGIS_point_line_texgen;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_color_mask;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env_dot3;
GLEE_EXTERN GLboolean _GLEE_ATI_texture_mirror_once;
GLEE_EXTERN GLboolean _GLEE_NV_fence;
GLEE_EXTERN GLboolean _GLEE_IBM_texture_mirrored_repeat;
GLEE_EXTERN GLboolean _GLEE_NV_evaluators;
GLEE_EXTERN GLboolean _GLEE_NV_packed_depth_stencil;
GLEE_EXTERN GLboolean _GLEE_NV_register_combiners2;
GLEE_EXTERN GLboolean _GLEE_NV_texture_compression_vtc;
GLEE_EXTERN GLboolean _GLEE_NV_texture_rectangle;
GLEE_EXTERN GLboolean _GLEE_NV_texture_shader;
GLEE_EXTERN GLboolean _GLEE_NV_texture_shader2;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_array_range2;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_coordinate_clamp;
GLEE_EXTERN GLboolean _GLEE_SGIX_scalebias_hint;
GLEE_EXTERN GLboolean _GLEE_OML_interlace;
GLEE_EXTERN GLboolean _GLEE_OML_subsample;
GLEE_EXTERN GLboolean _GLEE_OML_resample;
GLEE_EXTERN GLboolean _GLEE_NV_copy_depth_to_color;
GLEE_EXTERN GLboolean _GLEE_ATI_envmap_bumpmap;
GLEE_EXTERN GLboolean _GLEE_ATI_fragment_shader;
GLEE_EXTERN GLboolean _GLEE_ATI_pn_triangles;
GLEE_EXTERN GLboolean _GLEE_ATI_vertex_array_object;
GLEE_EXTERN GLboolean _GLEE_EXT_vertex_shader;
GLEE_EXTERN GLboolean _GLEE_ATI_vertex_streams;
GLEE_EXTERN GLboolean _GLEE_ATI_element_array;
GLEE_EXTERN GLboolean _GLEE_SUN_mesh_array;
GLEE_EXTERN GLboolean _GLEE_SUN_slice_accum;
GLEE_EXTERN GLboolean _GLEE_NV_multisample_filter_hint;
GLEE_EXTERN GLboolean _GLEE_NV_depth_clamp;
GLEE_EXTERN GLboolean _GLEE_NV_occlusion_query;
GLEE_EXTERN GLboolean _GLEE_NV_point_sprite;
GLEE_EXTERN GLboolean _GLEE_NV_texture_shader3;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program1_1;
GLEE_EXTERN GLboolean _GLEE_EXT_shadow_funcs;
GLEE_EXTERN GLboolean _GLEE_EXT_stencil_two_side;
GLEE_EXTERN GLboolean _GLEE_ATI_text_fragment_shader;
GLEE_EXTERN GLboolean _GLEE_APPLE_client_storage;
GLEE_EXTERN GLboolean _GLEE_APPLE_element_array;
GLEE_EXTERN GLboolean _GLEE_APPLE_fence;
GLEE_EXTERN GLboolean _GLEE_APPLE_vertex_array_object;
GLEE_EXTERN GLboolean _GLEE_APPLE_vertex_array_range;
GLEE_EXTERN GLboolean _GLEE_APPLE_ycbcr_422;
GLEE_EXTERN GLboolean _GLEE_S3_s3tc;
GLEE_EXTERN GLboolean _GLEE_ATI_draw_buffers;
GLEE_EXTERN GLboolean _GLEE_ATI_pixel_format_float;
GLEE_EXTERN GLboolean _GLEE_ATI_texture_env_combine3;
GLEE_EXTERN GLboolean _GLEE_ATI_texture_float;
GLEE_EXTERN GLboolean _GLEE_NV_float_buffer;
GLEE_EXTERN GLboolean _GLEE_NV_fragment_program;
GLEE_EXTERN GLboolean _GLEE_NV_half_float;
GLEE_EXTERN GLboolean _GLEE_NV_pixel_data_range;
GLEE_EXTERN GLboolean _GLEE_NV_primitive_restart;
GLEE_EXTERN GLboolean _GLEE_NV_texture_expand_normal;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program2;
GLEE_EXTERN GLboolean _GLEE_ATI_map_object_buffer;
GLEE_EXTERN GLboolean _GLEE_ATI_separate_stencil;
GLEE_EXTERN GLboolean _GLEE_ATI_vertex_attrib_array_object;
GLEE_EXTERN GLboolean _GLEE_OES_read_format;
GLEE_EXTERN GLboolean _GLEE_EXT_depth_bounds_test;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_mirror_clamp;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_equation_separate;
GLEE_EXTERN GLboolean _GLEE_MESA_pack_invert;
GLEE_EXTERN GLboolean _GLEE_MESA_ycbcr_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_pixel_buffer_object;
GLEE_EXTERN GLboolean _GLEE_NV_fragment_program_option;
GLEE_EXTERN GLboolean _GLEE_NV_fragment_program2;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program2_option;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program3;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_object;
GLEE_EXTERN GLboolean _GLEE_GREMEDY_string_marker;
GLEE_EXTERN GLboolean _GLEE_EXT_packed_depth_stencil;
GLEE_EXTERN GLboolean _GLEE_EXT_stencil_clear_tag;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_sRGB;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_blit;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_multisample;
GLEE_EXTERN GLboolean _GLEE_MESAX_texture_stack;
GLEE_EXTERN GLboolean _GLEE_EXT_timer_query;
GLEE_EXTERN GLboolean _GLEE_EXT_gpu_program_parameters;
GLEE_EXTERN GLboolean _GLEE_APPLE_flush_buffer_range;
GLEE_EXTERN GLboolean _GLEE_EXT_gpu_shader4;
GLEE_EXTERN GLboolean _GLEE_EXT_draw_instanced;
GLEE_EXTERN GLboolean _GLEE_EXT_packed_float;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_array;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_buffer_object;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_latc;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_rgtc;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_shared_exponent;
GLEE_EXTERN GLboolean _GLEE_NV_depth_buffer_float;
GLEE_EXTERN GLboolean _GLEE_NV_framebuffer_multisample_coverage;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_sRGB;
GLEE_EXTERN GLboolean _GLEE_NV_geometry_shader4;
GLEE_EXTERN GLboolean _GLEE_NV_parameter_buffer_object;
GLEE_EXTERN GLboolean _GLEE_EXT_draw_buffers2;
GLEE_EXTERN GLboolean _GLEE_NV_transform_feedback;
GLEE_EXTERN GLboolean _GLEE_EXT_bindable_uniform;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_integer;
GLEE_EXTERN GLboolean _GLEE_GREMEDY_frame_terminator;
GLEE_EXTERN GLboolean _GLEE_NV_conditional_render;
GLEE_EXTERN GLboolean _GLEE_NV_present_video;
GLEE_EXTERN GLboolean _GLEE_EXT_transform_feedback;
GLEE_EXTERN GLboolean _GLEE_EXT_direct_state_access;
GLEE_EXTERN GLboolean _GLEE_EXT_vertex_array_bgra;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_swizzle;
GLEE_EXTERN GLboolean _GLEE_NV_explicit_multisample;
GLEE_EXTERN GLboolean _GLEE_NV_transform_feedback2;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_select;
GLEE_EXTERN GLboolean _GLEE_INGR_blend_func_separate;
GLEE_EXTERN GLboolean _GLEE_SGIX_depth_pass_instrument;
GLEE_EXTERN GLboolean _GLEE_SGIX_igloo_interface;
GLEE_EXTERN GLboolean _GLEE_EXT_fragment_lighting;
GLEE_EXTERN GLboolean _GLEE_EXT_geometry_shader4;
GLEE_EXTERN GLboolean _GLEE_EXT_scene_marker;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_dxt1;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env;
GLEE_EXTERN GLboolean _GLEE_IBM_static_data;
GLEE_EXTERN GLboolean _GLEE_NV_gpu_program4;
GLEE_EXTERN GLboolean _GLEE_OES_byte_coordinates;
GLEE_EXTERN GLboolean _GLEE_OES_compressed_paletted_texture;
GLEE_EXTERN GLboolean _GLEE_OES_single_precision;
GLEE_EXTERN GLboolean _GLEE_SGIX_pixel_texture_bits;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_range;

/* Aliases for extension querying variables */

#define GLEE_VERSION_1_2     GLeeEnabled(&_GLEE_VERSION_1_2)
#define GLEE_ARB_imaging     GLeeEnabled(&_GLEE_ARB_imaging)
#define GLEE_VERSION_1_3     GLeeEnabled(&_GLEE_VERSION_1_3)
#define GLEE_VERSION_1_4     GLeeEnabled(&_GLEE_VERSION_1_4)
#define GLEE_VERSION_1_5     GLeeEnabled(&_GLEE_VERSION_1_5)
#define GLEE_VERSION_2_0     GLeeEnabled(&_GLEE_VERSION_2_0)
#define GLEE_VERSION_2_1     GLeeEnabled(&_GLEE_VERSION_2_1)
#define GLEE_VERSION_3_0     GLeeEnabled(&_GLEE_VERSION_3_0)
#define GLEE_ARB_multitexture     GLeeEnabled(&_GLEE_ARB_multitexture)
#define GLEE_ARB_transpose_matrix     GLeeEnabled(&_GLEE_ARB_transpose_matrix)
#define GLEE_ARB_multisample     GLeeEnabled(&_GLEE_ARB_multisample)
#define GLEE_ARB_texture_env_add     GLeeEnabled(&_GLEE_ARB_texture_env_add)
#define GLEE_ARB_texture_cube_map     GLeeEnabled(&_GLEE_ARB_texture_cube_map)
#define GLEE_ARB_texture_compression     GLeeEnabled(&_GLEE_ARB_texture_compression)
#define GLEE_ARB_texture_border_clamp     GLeeEnabled(&_GLEE_ARB_texture_border_clamp)
#define GLEE_ARB_point_parameters     GLeeEnabled(&_GLEE_ARB_point_parameters)
#define GLEE_ARB_vertex_blend     GLeeEnabled(&_GLEE_ARB_vertex_blend)
#define GLEE_ARB_matrix_palette     GLeeEnabled(&_GLEE_ARB_matrix_palette)
#define GLEE_ARB_texture_env_combine     GLeeEnabled(&_GLEE_ARB_texture_env_combine)
#define GLEE_ARB_texture_env_crossbar     GLeeEnabled(&_GLEE_ARB_texture_env_crossbar)
#define GLEE_ARB_texture_env_dot3     GLeeEnabled(&_GLEE_ARB_texture_env_dot3)
#define GLEE_ARB_texture_mirrored_repeat     GLeeEnabled(&_GLEE_ARB_texture_mirrored_repeat)
#define GLEE_ARB_depth_texture     GLeeEnabled(&_GLEE_ARB_depth_texture)
#define GLEE_ARB_shadow     GLeeEnabled(&_GLEE_ARB_shadow)
#define GLEE_ARB_shadow_ambient     GLeeEnabled(&_GLEE_ARB_shadow_ambient)
#define GLEE_ARB_window_pos     GLeeEnabled(&_GLEE_ARB_window_pos)
#define GLEE_ARB_vertex_program     GLeeEnabled(&_GLEE_ARB_vertex_program)
#define GLEE_ARB_fragment_program     GLeeEnabled(&_GLEE_ARB_fragment_program)
#define GLEE_ARB_vertex_buffer_object     GLeeEnabled(&_GLEE_ARB_vertex_buffer_object)
#define GLEE_ARB_occlusion_query     GLeeEnabled(&_GLEE_ARB_occlusion_query)
#define GLEE_ARB_shader_objects     GLeeEnabled(&_GLEE_ARB_shader_objects)
#define GLEE_ARB_vertex_shader     GLeeEnabled(&_GLEE_ARB_vertex_shader)
#define GLEE_ARB_fragment_shader     GLeeEnabled(&_GLEE_ARB_fragment_shader)
#define GLEE_ARB_shading_language_100     GLeeEnabled(&_GLEE_ARB_shading_language_100)
#define GLEE_ARB_texture_non_power_of_two     GLeeEnabled(&_GLEE_ARB_texture_non_power_of_two)
#define GLEE_ARB_point_sprite     GLeeEnabled(&_GLEE_ARB_point_sprite)
#define GLEE_ARB_fragment_program_shadow     GLeeEnabled(&_GLEE_ARB_fragment_program_shadow)
#define GLEE_ARB_draw_buffers     GLeeEnabled(&_GLEE_ARB_draw_buffers)
#define GLEE_ARB_texture_rectangle     GLeeEnabled(&_GLEE_ARB_texture_rectangle)
#define GLEE_ARB_color_buffer_float     GLeeEnabled(&_GLEE_ARB_color_buffer_float)
#define GLEE_ARB_half_float_pixel     GLeeEnabled(&_GLEE_ARB_half_float_pixel)
#define GLEE_ARB_texture_float     GLeeEnabled(&_GLEE_ARB_texture_float)
#define GLEE_ARB_pixel_buffer_object     GLeeEnabled(&_GLEE_ARB_pixel_buffer_object)
#define GLEE_ARB_depth_buffer_float     GLeeEnabled(&_GLEE_ARB_depth_buffer_float)
#define GLEE_ARB_draw_instanced     GLeeEnabled(&_GLEE_ARB_draw_instanced)
#define GLEE_ARB_framebuffer_object     GLeeEnabled(&_GLEE_ARB_framebuffer_object)
#define GLEE_ARB_framebuffer_sRGB     GLeeEnabled(&_GLEE_ARB_framebuffer_sRGB)
#define GLEE_ARB_geometry_shader4     GLeeEnabled(&_GLEE_ARB_geometry_shader4)
#define GLEE_ARB_half_float_vertex     GLeeEnabled(&_GLEE_ARB_half_float_vertex)
#define GLEE_ARB_instanced_arrays     GLeeEnabled(&_GLEE_ARB_instanced_arrays)
#define GLEE_ARB_map_buffer_range     GLeeEnabled(&_GLEE_ARB_map_buffer_range)
#define GLEE_ARB_texture_buffer_object     GLeeEnabled(&_GLEE_ARB_texture_buffer_object)
#define GLEE_ARB_texture_compression_rgtc     GLeeEnabled(&_GLEE_ARB_texture_compression_rgtc)
#define GLEE_ARB_texture_rg     GLeeEnabled(&_GLEE_ARB_texture_rg)
#define GLEE_ARB_vertex_array_object     GLeeEnabled(&_GLEE_ARB_vertex_array_object)
#define GLEE_EXT_abgr     GLeeEnabled(&_GLEE_EXT_abgr)
#define GLEE_EXT_blend_color     GLeeEnabled(&_GLEE_EXT_blend_color)
#define GLEE_EXT_polygon_offset     GLeeEnabled(&_GLEE_EXT_polygon_offset)
#define GLEE_EXT_texture     GLeeEnabled(&_GLEE_EXT_texture)
#define GLEE_EXT_texture3D     GLeeEnabled(&_GLEE_EXT_texture3D)
#define GLEE_SGIS_texture_filter4     GLeeEnabled(&_GLEE_SGIS_texture_filter4)
#define GLEE_EXT_subtexture     GLeeEnabled(&_GLEE_EXT_subtexture)
#define GLEE_EXT_copy_texture     GLeeEnabled(&_GLEE_EXT_copy_texture)
#define GLEE_EXT_histogram     GLeeEnabled(&_GLEE_EXT_histogram)
#define GLEE_EXT_convolution     GLeeEnabled(&_GLEE_EXT_convolution)
#define GLEE_SGI_color_matrix     GLeeEnabled(&_GLEE_SGI_color_matrix)
#define GLEE_SGI_color_table     GLeeEnabled(&_GLEE_SGI_color_table)
#define GLEE_SGIS_pixel_texture     GLeeEnabled(&_GLEE_SGIS_pixel_texture)
#define GLEE_SGIX_pixel_texture     GLeeEnabled(&_GLEE_SGIX_pixel_texture)
#define GLEE_SGIS_texture4D     GLeeEnabled(&_GLEE_SGIS_texture4D)
#define GLEE_SGI_texture_color_table     GLeeEnabled(&_GLEE_SGI_texture_color_table)
#define GLEE_EXT_cmyka     GLeeEnabled(&_GLEE_EXT_cmyka)
#define GLEE_EXT_texture_object     GLeeEnabled(&_GLEE_EXT_texture_object)
#define GLEE_SGIS_detail_texture     GLeeEnabled(&_GLEE_SGIS_detail_texture)
#define GLEE_SGIS_sharpen_texture     GLeeEnabled(&_GLEE_SGIS_sharpen_texture)
#define GLEE_EXT_packed_pixels     GLeeEnabled(&_GLEE_EXT_packed_pixels)
#define GLEE_SGIS_texture_lod     GLeeEnabled(&_GLEE_SGIS_texture_lod)
#define GLEE_SGIS_multisample     GLeeEnabled(&_GLEE_SGIS_multisample)
#define GLEE_EXT_rescale_normal     GLeeEnabled(&_GLEE_EXT_rescale_normal)
#define GLEE_EXT_vertex_array     GLeeEnabled(&_GLEE_EXT_vertex_array)
#define GLEE_EXT_misc_attribute     GLeeEnabled(&_GLEE_EXT_misc_attribute)
#define GLEE_SGIS_generate_mipmap     GLeeEnabled(&_GLEE_SGIS_generate_mipmap)
#define GLEE_SGIX_clipmap     GLeeEnabled(&_GLEE_SGIX_clipmap)
#define GLEE_SGIX_shadow     GLeeEnabled(&_GLEE_SGIX_shadow)
#define GLEE_SGIS_texture_edge_clamp     GLeeEnabled(&_GLEE_SGIS_texture_edge_clamp)
#define GLEE_SGIS_texture_border_clamp     GLeeEnabled(&_GLEE_SGIS_texture_border_clamp)
#define GLEE_EXT_blend_minmax     GLeeEnabled(&_GLEE_EXT_blend_minmax)
#define GLEE_EXT_blend_subtract     GLeeEnabled(&_GLEE_EXT_blend_subtract)
#define GLEE_EXT_blend_logic_op     GLeeEnabled(&_GLEE_EXT_blend_logic_op)
#define GLEE_SGIX_interlace     GLeeEnabled(&_GLEE_SGIX_interlace)
#define GLEE_SGIX_pixel_tiles     GLeeEnabled(&_GLEE_SGIX_pixel_tiles)
#define GLEE_SGIS_texture_select     GLeeEnabled(&_GLEE_SGIS_texture_select)
#define GLEE_SGIX_sprite     GLeeEnabled(&_GLEE_SGIX_sprite)
#define GLEE_SGIX_texture_multi_buffer     GLeeEnabled(&_GLEE_SGIX_texture_multi_buffer)
#define GLEE_EXT_point_parameters     GLeeEnabled(&_GLEE_EXT_point_parameters)
#define GLEE_SGIS_point_parameters     GLeeEnabled(&_GLEE_SGIS_point_parameters)
#define GLEE_SGIX_instruments     GLeeEnabled(&_GLEE_SGIX_instruments)
#define GLEE_SGIX_texture_scale_bias     GLeeEnabled(&_GLEE_SGIX_texture_scale_bias)
#define GLEE_SGIX_framezoom     GLeeEnabled(&_GLEE_SGIX_framezoom)
#define GLEE_SGIX_tag_sample_buffer     GLeeEnabled(&_GLEE_SGIX_tag_sample_buffer)
#define GLEE_FfdMaskSGIX     GLeeEnabled(&_GLEE_FfdMaskSGIX)
#define GLEE_SGIX_polynomial_ffd     GLeeEnabled(&_GLEE_SGIX_polynomial_ffd)
#define GLEE_SGIX_reference_plane     GLeeEnabled(&_GLEE_SGIX_reference_plane)
#define GLEE_SGIX_flush_raster     GLeeEnabled(&_GLEE_SGIX_flush_raster)
#define GLEE_SGIX_depth_texture     GLeeEnabled(&_GLEE_SGIX_depth_texture)
#define GLEE_SGIS_fog_function     GLeeEnabled(&_GLEE_SGIS_fog_function)
#define GLEE_SGIX_fog_offset     GLeeEnabled(&_GLEE_SGIX_fog_offset)
#define GLEE_HP_image_transform     GLeeEnabled(&_GLEE_HP_image_transform)
#define GLEE_HP_convolution_border_modes     GLeeEnabled(&_GLEE_HP_convolution_border_modes)
#define GLEE_INGR_palette_buffer     GLeeEnabled(&_GLEE_INGR_palette_buffer)
#define GLEE_SGIX_texture_add_env     GLeeEnabled(&_GLEE_SGIX_texture_add_env)
#define GLEE_EXT_color_subtable     GLeeEnabled(&_GLEE_EXT_color_subtable)
#define GLEE_PGI_vertex_hints     GLeeEnabled(&_GLEE_PGI_vertex_hints)
#define GLEE_PGI_misc_hints     GLeeEnabled(&_GLEE_PGI_misc_hints)
#define GLEE_EXT_paletted_texture     GLeeEnabled(&_GLEE_EXT_paletted_texture)
#define GLEE_EXT_clip_volume_hint     GLeeEnabled(&_GLEE_EXT_clip_volume_hint)
#define GLEE_SGIX_list_priority     GLeeEnabled(&_GLEE_SGIX_list_priority)
#define GLEE_SGIX_ir_instrument1     GLeeEnabled(&_GLEE_SGIX_ir_instrument1)
#define GLEE_SGIX_calligraphic_fragment     GLeeEnabled(&_GLEE_SGIX_calligraphic_fragment)
#define GLEE_SGIX_texture_lod_bias     GLeeEnabled(&_GLEE_SGIX_texture_lod_bias)
#define GLEE_SGIX_shadow_ambient     GLeeEnabled(&_GLEE_SGIX_shadow_ambient)
#define GLEE_EXT_index_texture     GLeeEnabled(&_GLEE_EXT_index_texture)
#define GLEE_EXT_index_material     GLeeEnabled(&_GLEE_EXT_index_material)
#define GLEE_EXT_index_func     GLeeEnabled(&_GLEE_EXT_index_func)
#define GLEE_EXT_index_array_formats     GLeeEnabled(&_GLEE_EXT_index_array_formats)
#define GLEE_EXT_compiled_vertex_array     GLeeEnabled(&_GLEE_EXT_compiled_vertex_array)
#define GLEE_EXT_cull_vertex     GLeeEnabled(&_GLEE_EXT_cull_vertex)
#define GLEE_SGIX_ycrcb     GLeeEnabled(&_GLEE_SGIX_ycrcb)
#define GLEE_SGIX_fragment_lighting     GLeeEnabled(&_GLEE_SGIX_fragment_lighting)
#define GLEE_IBM_rasterpos_clip     GLeeEnabled(&_GLEE_IBM_rasterpos_clip)
#define GLEE_HP_texture_lighting     GLeeEnabled(&_GLEE_HP_texture_lighting)
#define GLEE_EXT_draw_range_elements     GLeeEnabled(&_GLEE_EXT_draw_range_elements)
#define GLEE_WIN_phong_shading     GLeeEnabled(&_GLEE_WIN_phong_shading)
#define GLEE_WIN_specular_fog     GLeeEnabled(&_GLEE_WIN_specular_fog)
#define GLEE_EXT_light_texture     GLeeEnabled(&_GLEE_EXT_light_texture)
#define GLEE_SGIX_blend_alpha_minmax     GLeeEnabled(&_GLEE_SGIX_blend_alpha_minmax)
#define GLEE_SGIX_impact_pixel_texture     GLeeEnabled(&_GLEE_SGIX_impact_pixel_texture)
#define GLEE_EXT_bgra     GLeeEnabled(&_GLEE_EXT_bgra)
#define GLEE_SGIX_async     GLeeEnabled(&_GLEE_SGIX_async)
#define GLEE_SGIX_async_pixel     GLeeEnabled(&_GLEE_SGIX_async_pixel)
#define GLEE_SGIX_async_histogram     GLeeEnabled(&_GLEE_SGIX_async_histogram)
#define GLEE_INTEL_texture_scissor     GLeeEnabled(&_GLEE_INTEL_texture_scissor)
#define GLEE_INTEL_parallel_arrays     GLeeEnabled(&_GLEE_INTEL_parallel_arrays)
#define GLEE_HP_occlusion_test     GLeeEnabled(&_GLEE_HP_occlusion_test)
#define GLEE_EXT_pixel_transform     GLeeEnabled(&_GLEE_EXT_pixel_transform)
#define GLEE_EXT_pixel_transform_color_table     GLeeEnabled(&_GLEE_EXT_pixel_transform_color_table)
#define GLEE_EXT_shared_texture_palette     GLeeEnabled(&_GLEE_EXT_shared_texture_palette)
#define GLEE_EXT_separate_specular_color     GLeeEnabled(&_GLEE_EXT_separate_specular_color)
#define GLEE_EXT_secondary_color     GLeeEnabled(&_GLEE_EXT_secondary_color)
#define GLEE_EXT_texture_perturb_normal     GLeeEnabled(&_GLEE_EXT_texture_perturb_normal)
#define GLEE_EXT_multi_draw_arrays     GLeeEnabled(&_GLEE_EXT_multi_draw_arrays)
#define GLEE_EXT_fog_coord     GLeeEnabled(&_GLEE_EXT_fog_coord)
#define GLEE_REND_screen_coordinates     GLeeEnabled(&_GLEE_REND_screen_coordinates)
#define GLEE_EXT_coordinate_frame     GLeeEnabled(&_GLEE_EXT_coordinate_frame)
#define GLEE_EXT_texture_env_combine     GLeeEnabled(&_GLEE_EXT_texture_env_combine)
#define GLEE_APPLE_specular_vector     GLeeEnabled(&_GLEE_APPLE_specular_vector)
#define GLEE_APPLE_transform_hint     GLeeEnabled(&_GLEE_APPLE_transform_hint)
#define GLEE_SGIX_fog_scale     GLeeEnabled(&_GLEE_SGIX_fog_scale)
#define GLEE_SUNX_constant_data     GLeeEnabled(&_GLEE_SUNX_constant_data)
#define GLEE_SUN_global_alpha     GLeeEnabled(&_GLEE_SUN_global_alpha)
#define GLEE_SUN_triangle_list     GLeeEnabled(&_GLEE_SUN_triangle_list)
#define GLEE_SUN_vertex     GLeeEnabled(&_GLEE_SUN_vertex)
#define GLEE_EXT_blend_func_separate     GLeeEnabled(&_GLEE_EXT_blend_func_separate)
#define GLEE_INGR_color_clamp     GLeeEnabled(&_GLEE_INGR_color_clamp)
#define GLEE_INGR_interlace_read     GLeeEnabled(&_GLEE_INGR_interlace_read)
#define GLEE_EXT_stencil_wrap     GLeeEnabled(&_GLEE_EXT_stencil_wrap)
#define GLEE_EXT_422_pixels     GLeeEnabled(&_GLEE_EXT_422_pixels)
#define GLEE_NV_texgen_reflection     GLeeEnabled(&_GLEE_NV_texgen_reflection)
#define GLEE_EXT_texture_cube_map     GLeeEnabled(&_GLEE_EXT_texture_cube_map)
#define GLEE_SUN_convolution_border_modes     GLeeEnabled(&_GLEE_SUN_convolution_border_modes)
#define GLEE_EXT_texture_env_add     GLeeEnabled(&_GLEE_EXT_texture_env_add)
#define GLEE_EXT_texture_lod_bias     GLeeEnabled(&_GLEE_EXT_texture_lod_bias)
#define GLEE_EXT_texture_filter_anisotropic     GLeeEnabled(&_GLEE_EXT_texture_filter_anisotropic)
#define GLEE_EXT_vertex_weighting     GLeeEnabled(&_GLEE_EXT_vertex_weighting)
#define GLEE_NV_light_max_exponent     GLeeEnabled(&_GLEE_NV_light_max_exponent)
#define GLEE_NV_vertex_array_range     GLeeEnabled(&_GLEE_NV_vertex_array_range)
#define GLEE_NV_register_combiners     GLeeEnabled(&_GLEE_NV_register_combiners)
#define GLEE_NV_fog_distance     GLeeEnabled(&_GLEE_NV_fog_distance)
#define GLEE_NV_texgen_emboss     GLeeEnabled(&_GLEE_NV_texgen_emboss)
#define GLEE_NV_blend_square     GLeeEnabled(&_GLEE_NV_blend_square)
#define GLEE_NV_texture_env_combine4     GLeeEnabled(&_GLEE_NV_texture_env_combine4)
#define GLEE_MESA_resize_buffers     GLeeEnabled(&_GLEE_MESA_resize_buffers)
#define GLEE_MESA_window_pos     GLeeEnabled(&_GLEE_MESA_window_pos)
#define GLEE_EXT_texture_compression_s3tc     GLeeEnabled(&_GLEE_EXT_texture_compression_s3tc)
#define GLEE_IBM_cull_vertex     GLeeEnabled(&_GLEE_IBM_cull_vertex)
#define GLEE_IBM_multimode_draw_arrays     GLeeEnabled(&_GLEE_IBM_multimode_draw_arrays)
#define GLEE_IBM_vertex_array_lists     GLeeEnabled(&_GLEE_IBM_vertex_array_lists)
#define GLEE_SGIX_subsample     GLeeEnabled(&_GLEE_SGIX_subsample)
#define GLEE_SGIX_ycrcb_subsample     GLeeEnabled(&_GLEE_SGIX_ycrcb_subsample)
#define GLEE_SGIX_ycrcba     GLeeEnabled(&_GLEE_SGIX_ycrcba)
#define GLEE_SGI_depth_pass_instrument     GLeeEnabled(&_GLEE_SGI_depth_pass_instrument)
#define GLEE_3DFX_texture_compression_FXT1     GLeeEnabled(&_GLEE_3DFX_texture_compression_FXT1)
#define GLEE_3DFX_multisample     GLeeEnabled(&_GLEE_3DFX_multisample)
#define GLEE_3DFX_tbuffer     GLeeEnabled(&_GLEE_3DFX_tbuffer)
#define GLEE_EXT_multisample     GLeeEnabled(&_GLEE_EXT_multisample)
#define GLEE_SGIX_vertex_preclip     GLeeEnabled(&_GLEE_SGIX_vertex_preclip)
#define GLEE_SGIX_convolution_accuracy     GLeeEnabled(&_GLEE_SGIX_convolution_accuracy)
#define GLEE_SGIX_resample     GLeeEnabled(&_GLEE_SGIX_resample)
#define GLEE_SGIS_point_line_texgen     GLeeEnabled(&_GLEE_SGIS_point_line_texgen)
#define GLEE_SGIS_texture_color_mask     GLeeEnabled(&_GLEE_SGIS_texture_color_mask)
#define GLEE_EXT_texture_env_dot3     GLeeEnabled(&_GLEE_EXT_texture_env_dot3)
#define GLEE_ATI_texture_mirror_once     GLeeEnabled(&_GLEE_ATI_texture_mirror_once)
#define GLEE_NV_fence     GLeeEnabled(&_GLEE_NV_fence)
#define GLEE_IBM_texture_mirrored_repeat     GLeeEnabled(&_GLEE_IBM_texture_mirrored_repeat)
#define GLEE_NV_evaluators     GLeeEnabled(&_GLEE_NV_evaluators)
#define GLEE_NV_packed_depth_stencil     GLeeEnabled(&_GLEE_NV_packed_depth_stencil)
#define GLEE_NV_register_combiners2     GLeeEnabled(&_GLEE_NV_register_combiners2)
#define GLEE_NV_texture_compression_vtc     GLeeEnabled(&_GLEE_NV_texture_compression_vtc)
#define GLEE_NV_texture_rectangle     GLeeEnabled(&_GLEE_NV_texture_rectangle)
#define GLEE_NV_texture_shader     GLeeEnabled(&_GLEE_NV_texture_shader)
#define GLEE_NV_texture_shader2     GLeeEnabled(&_GLEE_NV_texture_shader2)
#define GLEE_NV_vertex_array_range2     GLeeEnabled(&_GLEE_NV_vertex_array_range2)
#define GLEE_NV_vertex_program     GLeeEnabled(&_GLEE_NV_vertex_program)
#define GLEE_SGIX_texture_coordinate_clamp     GLeeEnabled(&_GLEE_SGIX_texture_coordinate_clamp)
#define GLEE_SGIX_scalebias_hint     GLeeEnabled(&_GLEE_SGIX_scalebias_hint)
#define GLEE_OML_interlace     GLeeEnabled(&_GLEE_OML_interlace)
#define GLEE_OML_subsample     GLeeEnabled(&_GLEE_OML_subsample)
#define GLEE_OML_resample     GLeeEnabled(&_GLEE_OML_resample)
#define GLEE_NV_copy_depth_to_color     GLeeEnabled(&_GLEE_NV_copy_depth_to_color)
#define GLEE_ATI_envmap_bumpmap     GLeeEnabled(&_GLEE_ATI_envmap_bumpmap)
#define GLEE_ATI_fragment_shader     GLeeEnabled(&_GLEE_ATI_fragment_shader)
#define GLEE_ATI_pn_triangles     GLeeEnabled(&_GLEE_ATI_pn_triangles)
#define GLEE_ATI_vertex_array_object     GLeeEnabled(&_GLEE_ATI_vertex_array_object)
#define GLEE_EXT_vertex_shader     GLeeEnabled(&_GLEE_EXT_vertex_shader)
#define GLEE_ATI_vertex_streams     GLeeEnabled(&_GLEE_ATI_vertex_streams)
#define GLEE_ATI_element_array     GLeeEnabled(&_GLEE_ATI_element_array)
#define GLEE_SUN_mesh_array     GLeeEnabled(&_GLEE_SUN_mesh_array)
#define GLEE_SUN_slice_accum     GLeeEnabled(&_GLEE_SUN_slice_accum)
#define GLEE_NV_multisample_filter_hint     GLeeEnabled(&_GLEE_NV_multisample_filter_hint)
#define GLEE_NV_depth_clamp     GLeeEnabled(&_GLEE_NV_depth_clamp)
#define GLEE_NV_occlusion_query     GLeeEnabled(&_GLEE_NV_occlusion_query)
#define GLEE_NV_point_sprite     GLeeEnabled(&_GLEE_NV_point_sprite)
#define GLEE_NV_texture_shader3     GLeeEnabled(&_GLEE_NV_texture_shader3)
#define GLEE_NV_vertex_program1_1     GLeeEnabled(&_GLEE_NV_vertex_program1_1)
#define GLEE_EXT_shadow_funcs     GLeeEnabled(&_GLEE_EXT_shadow_funcs)
#define GLEE_EXT_stencil_two_side     GLeeEnabled(&_GLEE_EXT_stencil_two_side)
#define GLEE_ATI_text_fragment_shader     GLeeEnabled(&_GLEE_ATI_text_fragment_shader)
#define GLEE_APPLE_client_storage     GLeeEnabled(&_GLEE_APPLE_client_storage)
#define GLEE_APPLE_element_array     GLeeEnabled(&_GLEE_APPLE_element_array)
#define GLEE_APPLE_fence     GLeeEnabled(&_GLEE_APPLE_fence)
#define GLEE_APPLE_vertex_array_object     GLeeEnabled(&_GLEE_APPLE_vertex_array_object)
#define GLEE_APPLE_vertex_array_range     GLeeEnabled(&_GLEE_APPLE_vertex_array_range)
#define GLEE_APPLE_ycbcr_422     GLeeEnabled(&_GLEE_APPLE_ycbcr_422)
#define GLEE_S3_s3tc     GLeeEnabled(&_GLEE_S3_s3tc)
#define GLEE_ATI_draw_buffers     GLeeEnabled(&_GLEE_ATI_draw_buffers)
#define GLEE_ATI_pixel_format_float     GLeeEnabled(&_GLEE_ATI_pixel_format_float)
#define GLEE_ATI_texture_env_combine3     GLeeEnabled(&_GLEE_ATI_texture_env_combine3)
#define GLEE_ATI_texture_float     GLeeEnabled(&_GLEE_ATI_texture_float)
#define GLEE_NV_float_buffer     GLeeEnabled(&_GLEE_NV_float_buffer)
#define GLEE_NV_fragment_program     GLeeEnabled(&_GLEE_NV_fragment_program)
#define GLEE_NV_half_float     GLeeEnabled(&_GLEE_NV_half_float)
#define GLEE_NV_pixel_data_range     GLeeEnabled(&_GLEE_NV_pixel_data_range)
#define GLEE_NV_primitive_restart     GLeeEnabled(&_GLEE_NV_primitive_restart)
#define GLEE_NV_texture_expand_normal     GLeeEnabled(&_GLEE_NV_texture_expand_normal)
#define GLEE_NV_vertex_program2     GLeeEnabled(&_GLEE_NV_vertex_program2)
#define GLEE_ATI_map_object_buffer     GLeeEnabled(&_GLEE_ATI_map_object_buffer)
#define GLEE_ATI_separate_stencil     GLeeEnabled(&_GLEE_ATI_separate_stencil)
#define GLEE_ATI_vertex_attrib_array_object     GLeeEnabled(&_GLEE_ATI_vertex_attrib_array_object)
#define GLEE_OES_read_format     GLeeEnabled(&_GLEE_OES_read_format)
#define GLEE_EXT_depth_bounds_test     GLeeEnabled(&_GLEE_EXT_depth_bounds_test)
#define GLEE_EXT_texture_mirror_clamp     GLeeEnabled(&_GLEE_EXT_texture_mirror_clamp)
#define GLEE_EXT_blend_equation_separate     GLeeEnabled(&_GLEE_EXT_blend_equation_separate)
#define GLEE_MESA_pack_invert     GLeeEnabled(&_GLEE_MESA_pack_invert)
#define GLEE_MESA_ycbcr_texture     GLeeEnabled(&_GLEE_MESA_ycbcr_texture)
#define GLEE_EXT_pixel_buffer_object     GLeeEnabled(&_GLEE_EXT_pixel_buffer_object)
#define GLEE_NV_fragment_program_option     GLeeEnabled(&_GLEE_NV_fragment_program_option)
#define GLEE_NV_fragment_program2     GLeeEnabled(&_GLEE_NV_fragment_program2)
#define GLEE_NV_vertex_program2_option     GLeeEnabled(&_GLEE_NV_vertex_program2_option)
#define GLEE_NV_vertex_program3     GLeeEnabled(&_GLEE_NV_vertex_program3)
#define GLEE_EXT_framebuffer_object     GLeeEnabled(&_GLEE_EXT_framebuffer_object)
#define GLEE_GREMEDY_string_marker     GLeeEnabled(&_GLEE_GREMEDY_string_marker)
#define GLEE_EXT_packed_depth_stencil     GLeeEnabled(&_GLEE_EXT_packed_depth_stencil)
#define GLEE_EXT_stencil_clear_tag     GLeeEnabled(&_GLEE_EXT_stencil_clear_tag)
#define GLEE_EXT_texture_sRGB     GLeeEnabled(&_GLEE_EXT_texture_sRGB)
#define GLEE_EXT_framebuffer_blit     GLeeEnabled(&_GLEE_EXT_framebuffer_blit)
#define GLEE_EXT_framebuffer_multisample     GLeeEnabled(&_GLEE_EXT_framebuffer_multisample)
#define GLEE_MESAX_texture_stack     GLeeEnabled(&_GLEE_MESAX_texture_stack)
#define GLEE_EXT_timer_query     GLeeEnabled(&_GLEE_EXT_timer_query)
#define GLEE_EXT_gpu_program_parameters     GLeeEnabled(&_GLEE_EXT_gpu_program_parameters)
#define GLEE_APPLE_flush_buffer_range     GLeeEnabled(&_GLEE_APPLE_flush_buffer_range)
#define GLEE_EXT_gpu_shader4     GLeeEnabled(&_GLEE_EXT_gpu_shader4)
#define GLEE_EXT_draw_instanced     GLeeEnabled(&_GLEE_EXT_draw_instanced)
#define GLEE_EXT_packed_float     GLeeEnabled(&_GLEE_EXT_packed_float)
#define GLEE_EXT_texture_array     GLeeEnabled(&_GLEE_EXT_texture_array)
#define GLEE_EXT_texture_buffer_object     GLeeEnabled(&_GLEE_EXT_texture_buffer_object)
#define GLEE_EXT_texture_compression_latc     GLeeEnabled(&_GLEE_EXT_texture_compression_latc)
#define GLEE_EXT_texture_compression_rgtc     GLeeEnabled(&_GLEE_EXT_texture_compression_rgtc)
#define GLEE_EXT_texture_shared_exponent     GLeeEnabled(&_GLEE_EXT_texture_shared_exponent)
#define GLEE_NV_depth_buffer_float     GLeeEnabled(&_GLEE_NV_depth_buffer_float)
#define GLEE_NV_framebuffer_multisample_coverage     GLeeEnabled(&_GLEE_NV_framebuffer_multisample_coverage)
#define GLEE_EXT_framebuffer_sRGB     GLeeEnabled(&_GLEE_EXT_framebuffer_sRGB)
#define GLEE_NV_geometry_shader4     GLeeEnabled(&_GLEE_NV_geometry_shader4)
#define GLEE_NV_parameter_buffer_object     GLeeEnabled(&_GLEE_NV_parameter_buffer_object)
#define GLEE_EXT_draw_buffers2     GLeeEnabled(&_GLEE_EXT_draw_buffers2)
#define GLEE_NV_transform_feedback     GLeeEnabled(&_GLEE_NV_transform_feedback)
#define GLEE_EXT_bindable_uniform     GLeeEnabled(&_GLEE_EXT_bindable_uniform)
#define GLEE_EXT_texture_integer     GLeeEnabled(&_GLEE_EXT_texture_integer)
#define GLEE_GREMEDY_frame_terminator     GLeeEnabled(&_GLEE_GREMEDY_frame_terminator)
#define GLEE_NV_conditional_render     GLeeEnabled(&_GLEE_NV_conditional_render)
#define GLEE_NV_present_video     GLeeEnabled(&_GLEE_NV_present_video)
#define GLEE_EXT_transform_feedback     GLeeEnabled(&_GLEE_EXT_transform_feedback)
#define GLEE_EXT_direct_state_access     GLeeEnabled(&_GLEE_EXT_direct_state_access)
#define GLEE_EXT_vertex_array_bgra     GLeeEnabled(&_GLEE_EXT_vertex_array_bgra)
#define GLEE_EXT_texture_swizzle     GLeeEnabled(&_GLEE_EXT_texture_swizzle)
#define GLEE_NV_explicit_multisample     GLeeEnabled(&_GLEE_NV_explicit_multisample)
#define GLEE_NV_transform_feedback2     GLeeEnabled(&_GLEE_NV_transform_feedback2)
#define GLEE_SGIX_texture_select     GLeeEnabled(&_GLEE_SGIX_texture_select)
#define GLEE_INGR_blend_func_separate     GLeeEnabled(&_GLEE_INGR_blend_func_separate)
#define GLEE_SGIX_depth_pass_instrument     GLeeEnabled(&_GLEE_SGIX_depth_pass_instrument)
#define GLEE_SGIX_igloo_interface     GLeeEnabled(&_GLEE_SGIX_igloo_interface)
#define GLEE_EXT_fragment_lighting     GLeeEnabled(&_GLEE_EXT_fragment_lighting)
#define GLEE_EXT_geometry_shader4     GLeeEnabled(&_GLEE_EXT_geometry_shader4)
#define GLEE_EXT_scene_marker     GLeeEnabled(&_GLEE_EXT_scene_marker)
#define GLEE_EXT_texture_compression_dxt1     GLeeEnabled(&_GLEE_EXT_texture_compression_dxt1)
#define GLEE_EXT_texture_env     GLeeEnabled(&_GLEE_EXT_texture_env)
#define GLEE_IBM_static_data     GLeeEnabled(&_GLEE_IBM_static_data)
#define GLEE_NV_gpu_program4     GLeeEnabled(&_GLEE_NV_gpu_program4)
#define GLEE_OES_byte_coordinates     GLeeEnabled(&_GLEE_OES_byte_coordinates)
#define GLEE_OES_compressed_paletted_texture     GLeeEnabled(&_GLEE_OES_compressed_paletted_texture)
#define GLEE_OES_single_precision     GLeeEnabled(&_GLEE_OES_single_precision)
#define GLEE_SGIX_pixel_texture_bits     GLeeEnabled(&_GLEE_SGIX_pixel_texture_bits)
#define GLEE_SGIX_texture_range     GLeeEnabled(&_GLEE_SGIX_texture_range)


/*****************************************************************
 * Additional types needed for extensions
 *****************************************************************/

/* Used for GLSL shader text */
#ifndef GL_VERSION_2_0
	typedef char GLchar;
#endif

#include <stddef.h>

#ifndef GL_VERSION_1_5
	typedef ptrdiff_t GLintptr;
	typedef ptrdiff_t GLsizeiptr;
#endif

#ifndef GL_NV_half_float
	typedef unsigned short GLhalfNV;
#endif

#ifndef GL_ARB_vertex_buffer_object
	typedef ptrdiff_t GLintptrARB;
	typedef ptrdiff_t GLsizeiptrARB;
#endif

#ifndef GL_ARB_shader_objects
	typedef int GLhandleARB;
	typedef char GLcharARB;
#endif

#ifndef GL_EXT_timer_query
	typedef signed long long GLint64EXT;
	typedef unsigned long long GLuint64EXT;
#endif

/* Platform-specific */

#ifdef WIN32

	/* WGL */

	#ifndef WGL_ARB_pbuffer
		DECLARE_HANDLE(HPBUFFERARB);
	#endif

	#ifndef WGL_EXT_pbuffer
		DECLARE_HANDLE(HPBUFFEREXT);
	#endif

	#ifndef WGL_NV_video_output
		DECLARE_HANDLE(HPVIDEODEV);
	#endif

	#ifndef WGL_NV_present_video
		DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
	#endif

	#ifndef WGL_NV_gpu_affinity
		DECLARE_HANDLE(HPGPUNV);
		DECLARE_HANDLE(HGPUNV);

		typedef struct _GPU_DEVICE {
			DWORD  cb;
			CHAR   DeviceName[32];
			CHAR   DeviceString[128];
			DWORD  Flags;
			RECT   rcVirtualScreen;
		} GPU_DEVICE, *PGPU_DEVICE;
	#endif

#elif defined(__APPLE__) || defined(__APPLE_CC__)

	/* Mac OS X */

#else

	/* GLX */

	typedef void (*__GLXextFuncPtr)(void);

	#ifndef GLX_ARB_get_proc_address
	#define GLX_ARB_get_proc_address 1
		extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
		extern void ( * glXGetProcAddressARB (const GLubyte *procName))(void);
		typedef __GLXextFuncPtr ( * PFNGLXGETPROCADDRESSARBPROC) (const GLubyte *procName);
	#endif

	#ifndef GLX_SGIX_fbconfig
		typedef XID GLXFBConfigIDSGIX;
		typedef struct __GLXFBConfigRec *GLXFBConfigSGIX;
	#endif

	#ifndef GLX_SGIX_pbuffer
	typedef XID GLXPbufferSGIX;
	typedef struct {
		int type;
		unsigned long serial;
		int send_event;
		Display *display;
		GLXDrawable drawable;
		int event_type;
		int draw_type;
		unsigned int mask;
		int x, y;
		int width, height;
		int count;
	} GLXBufferClobberEventSGIX;
	#endif

	#ifndef GLX_SGIX_hyperpipe
		#define _GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX 80
		typedef struct
		{
			char  pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int  networkId;
		} GLXHyperpipeNetworkSGIX;

		typedef struct
		{
			char pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int channel;
			unsigned int participationType;
			int timeSlice;
		} GLXHyperpipeConfigSGIX;

		typedef struct
		{
			char pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int srcXOrigin;
			int srcYOrigin;
			int srcWidth;
			int srcHeight;
			int destXOrigin;
			int destYOrigin;
			int destWidth;
			int destHeight;
		} GLXPipeRect;

		typedef struct
		{
			char pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int XOrigin;
			int YOrigin;
			int maxHeight;
			int maxWidth;
		} GLXPipeRectLimits;
	#endif

	#ifndef GLX_NV_video_output
	typedef unsigned int GLXVideoDeviceNV;
	#endif // GLX_NV_video_output

#endif /* end platform specific */



/* GL_VERSION_1_2 */

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define __GLEE_GL_VERSION_1_2 1
/* Constants */
#define GL_UNSIGNED_BYTE_3_3_2                             0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4                          0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1                          0x8034
#define GL_UNSIGNED_INT_8_8_8_8                            0x8035
#define GL_UNSIGNED_INT_10_10_10_2                         0x8036
#define GL_RESCALE_NORMAL                                  0x803A
#define GL_TEXTURE_BINDING_3D                              0x806A
#define GL_PACK_SKIP_IMAGES                                0x806B
#define GL_PACK_IMAGE_HEIGHT                               0x806C
#define GL_UNPACK_SKIP_IMAGES                              0x806D
#define GL_UNPACK_IMAGE_HEIGHT                             0x806E
#define GL_TEXTURE_3D                                      0x806F
#define GL_PROXY_TEXTURE_3D                                0x8070
#define GL_TEXTURE_DEPTH                                   0x8071
#define GL_TEXTURE_WRAP_R                                  0x8072
#define GL_MAX_3D_TEXTURE_SIZE                             0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV                         0x8362
#define GL_UNSIGNED_SHORT_5_6_5                            0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV                        0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV                      0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV                      0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV                        0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV                     0x8368
#define GL_BGR                                             0x80E0
#define GL_BGRA                                            0x80E1
#define GL_MAX_ELEMENTS_VERTICES                           0x80E8
#define GL_MAX_ELEMENTS_INDICES                            0x80E9
#define GL_CLAMP_TO_EDGE                                   0x812F
#define GL_TEXTURE_MIN_LOD                                 0x813A
#define GL_TEXTURE_MAX_LOD                                 0x813B
#define GL_TEXTURE_BASE_LEVEL                              0x813C
#define GL_TEXTURE_MAX_LEVEL                               0x813D
#define GL_LIGHT_MODEL_COLOR_CONTROL                       0x81F8
#define GL_SINGLE_COLOR                                    0x81F9
#define GL_SEPARATE_SPECULAR_COLOR                         0x81FA
#define GL_SMOOTH_POINT_SIZE_RANGE                         0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY                   0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE                         0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY                   0x0B23
#define GL_ALIASED_POINT_SIZE_RANGE                        0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE                        0x846E
#ifndef GLEE_H_DEFINED_glBlendColor
#define GLEE_H_DEFINED_glBlendColor
  typedef void (APIENTRYP GLEEPFNGLBLENDCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
  GLEE_EXTERN GLEEPFNGLBLENDCOLORPROC GLeeFuncPtr_glBlendColor;
  #define glBlendColor GLeeFuncPtr_glBlendColor
#endif
#ifndef GLEE_H_DEFINED_glBlendEquation
#define GLEE_H_DEFINED_glBlendEquation
  typedef void (APIENTRYP GLEEPFNGLBLENDEQUATIONPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLBLENDEQUATIONPROC GLeeFuncPtr_glBlendEquation;
  #define glBlendEquation GLeeFuncPtr_glBlendEquation
#endif
#ifndef GLEE_H_DEFINED_glDrawRangeElements
#define GLEE_H_DEFINED_glDrawRangeElements
  typedef void (APIENTRYP GLEEPFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
  GLEE_EXTERN GLEEPFNGLDRAWRANGEELEMENTSPROC GLeeFuncPtr_glDrawRangeElements;
  #define glDrawRangeElements GLeeFuncPtr_glDrawRangeElements
#endif
#ifndef GLEE_H_DEFINED_glColorTable
#define GLEE_H_DEFINED_glColorTable
  typedef void (APIENTRYP GLEEPFNGLCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
  GLEE_EXTERN GLEEPFNGLCOLORTABLEPROC GLeeFuncPtr_glColorTable;
  #define glColorTable GLeeFuncPtr_glColorTable
#endif
#ifndef GLEE_H_DEFINED_glColorTableParameterfv
#define GLEE_H_DEFINED_glColorTableParameterfv
  typedef void (APIENTRYP GLEEPFNGLCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLCOLORTABLEPARAMETERFVPROC GLeeFuncPtr_glColorTableParameterfv;
  #define glColorTableParameterfv GLeeFuncPtr_glColorTableParameterfv
#endif
#ifndef GLEE_H_DEFINED_glColorTableParameteriv
#define GLEE_H_DEFINED_glColorTableParameteriv
  typedef void (APIENTRYP GLEEPFNGLCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLCOLORTABLEPARAMETERIVPROC GLeeFuncPtr_glColorTableParameteriv;
  #define glColorTableParameteriv GLeeFuncPtr_glColorTableParameteriv
#endif
#ifndef GLEE_H_DEFINED_glCopyColorTable
#define GLEE_H_DEFINED_glCopyColorTable
  typedef void (APIENTRYP GLEEPFNGLCOPYCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYCOLORTABLEPROC GLeeFuncPtr_glCopyColorTable;
  #define glCopyColorTable GLeeFuncPtr_glCopyColorTable
#endif
#ifndef GLEE_H_DEFINED_glGetColorTable
#define GLEE_H_DEFINED_glGetColorTable
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEPROC) (GLenum target, GLenum format, GLenum type, GLvoid * table);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEPROC GLeeFuncPtr_glGetColorTable;
  #define glGetColorTable GLeeFuncPtr_glGetColorTable
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableParameterfv
#define GLEE_H_DEFINED_glGetColorTableParameterfv
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEPARAMETERFVPROC GLeeFuncPtr_glGetColorTableParameterfv;
  #define glGetColorTableParameterfv GLeeFuncPtr_glGetColorTableParameterfv
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableParameteriv
#define GLEE_H_DEFINED_glGetColorTableParameteriv
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEPARAMETERIVPROC GLeeFuncPtr_glGetColorTableParameteriv;
  #define glGetColorTableParameteriv GLeeFuncPtr_glGetColorTableParameteriv
#endif
#ifndef GLEE_H_DEFINED_glColorSubTable
#define GLEE_H_DEFINED_glColorSubTable
  typedef void (APIENTRYP GLEEPFNGLCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOLORSUBTABLEPROC GLeeFuncPtr_glColorSubTable;
  #define glColorSubTable GLeeFuncPtr_glColorSubTable
#endif
#ifndef GLEE_H_DEFINED_glCopyColorSubTable
#define GLEE_H_DEFINED_glCopyColorSubTable
  typedef void (APIENTRYP GLEEPFNGLCOPYCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYCOLORSUBTABLEPROC GLeeFuncPtr_glCopyColorSubTable;
  #define glCopyColorSubTable GLeeFuncPtr_glCopyColorSubTable
#endif
#ifndef GLEE_H_DEFINED_glConvolutionFilter1D
#define GLEE_H_DEFINED_glConvolutionFilter1D
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONFILTER1DPROC GLeeFuncPtr_glConvolutionFilter1D;
  #define glConvolutionFilter1D GLeeFuncPtr_glConvolutionFilter1D
#endif
#ifndef GLEE_H_DEFINED_glConvolutionFilter2D
#define GLEE_H_DEFINED_glConvolutionFilter2D
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONFILTER2DPROC GLeeFuncPtr_glConvolutionFilter2D;
  #define glConvolutionFilter2D GLeeFuncPtr_glConvolutionFilter2D
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameterf
#define GLEE_H_DEFINED_glConvolutionParameterf
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERFPROC GLeeFuncPtr_glConvolutionParameterf;
  #define glConvolutionParameterf GLeeFuncPtr_glConvolutionParameterf
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameterfv
#define GLEE_H_DEFINED_glConvolutionParameterfv
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERFVPROC GLeeFuncPtr_glConvolutionParameterfv;
  #define glConvolutionParameterfv GLeeFuncPtr_glConvolutionParameterfv
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameteri
#define GLEE_H_DEFINED_glConvolutionParameteri
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERIPROC) (GLenum target, GLenum pname, GLint params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERIPROC GLeeFuncPtr_glConvolutionParameteri;
  #define glConvolutionParameteri GLeeFuncPtr_glConvolutionParameteri
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameteriv
#define GLEE_H_DEFINED_glConvolutionParameteriv
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERIVPROC GLeeFuncPtr_glConvolutionParameteriv;
  #define glConvolutionParameteriv GLeeFuncPtr_glConvolutionParameteriv
#endif
#ifndef GLEE_H_DEFINED_glCopyConvolutionFilter1D
#define GLEE_H_DEFINED_glCopyConvolutionFilter1D
  typedef void (APIENTRYP GLEEPFNGLCOPYCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYCONVOLUTIONFILTER1DPROC GLeeFuncPtr_glCopyConvolutionFilter1D;
  #define glCopyConvolutionFilter1D GLeeFuncPtr_glCopyConvolutionFilter1D
#endif
#ifndef GLEE_H_DEFINED_glCopyConvolutionFilter2D
#define GLEE_H_DEFINED_glCopyConvolutionFilter2D
  typedef void (APIENTRYP GLEEPFNGLCOPYCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYCONVOLUTIONFILTER2DPROC GLeeFuncPtr_glCopyConvolutionFilter2D;
  #define glCopyConvolutionFilter2D GLeeFuncPtr_glCopyConvolutionFilter2D
#endif
#ifndef GLEE_H_DEFINED_glGetConvolutionFilter
#define GLEE_H_DEFINED_glGetConvolutionFilter
  typedef void (APIENTRYP GLEEPFNGLGETCONVOLUTIONFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid * image);
  GLEE_EXTERN GLEEPFNGLGETCONVOLUTIONFILTERPROC GLeeFuncPtr_glGetConvolutionFilter;
  #define glGetConvolutionFilter GLeeFuncPtr_glGetConvolutionFilter
#endif
#ifndef GLEE_H_DEFINED_glGetConvolutionParameterfv
#define GLEE_H_DEFINED_glGetConvolutionParameterfv
  typedef void (APIENTRYP GLEEPFNGLGETCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCONVOLUTIONPARAMETERFVPROC GLeeFuncPtr_glGetConvolutionParameterfv;
  #define glGetConvolutionParameterfv GLeeFuncPtr_glGetConvolutionParameterfv
#endif
#ifndef GLEE_H_DEFINED_glGetConvolutionParameteriv
#define GLEE_H_DEFINED_glGetConvolutionParameteriv
  typedef void (APIENTRYP GLEEPFNGLGETCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETCONVOLUTIONPARAMETERIVPROC GLeeFuncPtr_glGetConvolutionParameteriv;
  #define glGetConvolutionParameteriv GLeeFuncPtr_glGetConvolutionParameteriv
#endif
#ifndef GLEE_H_DEFINED_glGetSeparableFilter
#define GLEE_H_DEFINED_glGetSeparableFilter
  typedef void (APIENTRYP GLEEPFNGLGETSEPARABLEFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span);
  GLEE_EXTERN GLEEPFNGLGETSEPARABLEFILTERPROC GLeeFuncPtr_glGetSeparableFilter;
  #define glGetSeparableFilter GLeeFuncPtr_glGetSeparableFilter
#endif
#ifndef GLEE_H_DEFINED_glSeparableFilter2D
#define GLEE_H_DEFINED_glSeparableFilter2D
  typedef void (APIENTRYP GLEEPFNGLSEPARABLEFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column);
  GLEE_EXTERN GLEEPFNGLSEPARABLEFILTER2DPROC GLeeFuncPtr_glSeparableFilter2D;
  #define glSeparableFilter2D GLeeFuncPtr_glSeparableFilter2D
#endif
#ifndef GLEE_H_DEFINED_glGetHistogram
#define GLEE_H_DEFINED_glGetHistogram
  typedef void (APIENTRYP GLEEPFNGLGETHISTOGRAMPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
  GLEE_EXTERN GLEEPFNGLGETHISTOGRAMPROC GLeeFuncPtr_glGetHistogram;
  #define glGetHistogram GLeeFuncPtr_glGetHistogram
#endif
#ifndef GLEE_H_DEFINED_glGetHistogramParameterfv
#define GLEE_H_DEFINED_glGetHistogramParameterfv
  typedef void (APIENTRYP GLEEPFNGLGETHISTOGRAMPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETHISTOGRAMPARAMETERFVPROC GLeeFuncPtr_glGetHistogramParameterfv;
  #define glGetHistogramParameterfv GLeeFuncPtr_glGetHistogramParameterfv
#endif
#ifndef GLEE_H_DEFINED_glGetHistogramParameteriv
#define GLEE_H_DEFINED_glGetHistogramParameteriv
  typedef void (APIENTRYP GLEEPFNGLGETHISTOGRAMPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETHISTOGRAMPARAMETERIVPROC GLeeFuncPtr_glGetHistogramParameteriv;
  #define glGetHistogramParameteriv GLeeFuncPtr_glGetHistogramParameteriv
#endif
#ifndef GLEE_H_DEFINED_glGetMinmax
#define GLEE_H_DEFINED_glGetMinmax
  typedef void (APIENTRYP GLEEPFNGLGETMINMAXPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
  GLEE_EXTERN GLEEPFNGLGETMINMAXPROC GLeeFuncPtr_glGetMinmax;
  #define glGetMinmax GLeeFuncPtr_glGetMinmax
#endif
#ifndef GLEE_H_DEFINED_glGetMinmaxParameterfv
#define GLEE_H_DEFINED_glGetMinmaxParameterfv
  typedef void (APIENTRYP GLEEPFNGLGETMINMAXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMINMAXPARAMETERFVPROC GLeeFuncPtr_glGetMinmaxParameterfv;
  #define glGetMinmaxParameterfv GLeeFuncPtr_glGetMinmaxParameterfv
#endif
#ifndef GLEE_H_DEFINED_glGetMinmaxParameteriv
#define GLEE_H_DEFINED_glGetMinmaxParameteriv
  typedef void (APIENTRYP GLEEPFNGLGETMINMAXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMINMAXPARAMETERIVPROC GLeeFuncPtr_glGetMinmaxParameteriv;
  #define glGetMinmaxParameteriv GLeeFuncPtr_glGetMinmaxParameteriv
#endif
#ifndef GLEE_H_DEFINED_glHistogram
#define GLEE_H_DEFINED_glHistogram
  typedef void (APIENTRYP GLEEPFNGLHISTOGRAMPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
  GLEE_EXTERN GLEEPFNGLHISTOGRAMPROC GLeeFuncPtr_glHistogram;
  #define glHistogram GLeeFuncPtr_glHistogram
#endif
#ifndef GLEE_H_DEFINED_glMinmax
#define GLEE_H_DEFINED_glMinmax
  typedef void (APIENTRYP GLEEPFNGLMINMAXPROC) (GLenum target, GLenum internalformat, GLboolean sink);
  GLEE_EXTERN GLEEPFNGLMINMAXPROC GLeeFuncPtr_glMinmax;
  #define glMinmax GLeeFuncPtr_glMinmax
#endif
#ifndef GLEE_H_DEFINED_glResetHistogram
#define GLEE_H_DEFINED_glResetHistogram
  typedef void (APIENTRYP GLEEPFNGLRESETHISTOGRAMPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLRESETHISTOGRAMPROC GLeeFuncPtr_glResetHistogram;
  #define glResetHistogram GLeeFuncPtr_glResetHistogram
#endif
#ifndef GLEE_H_DEFINED_glResetMinmax
#define GLEE_H_DEFINED_glResetMinmax
  typedef void (APIENTRYP GLEEPFNGLRESETMINMAXPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLRESETMINMAXPROC GLeeFuncPtr_glResetMinmax;
  #define glResetMinmax GLeeFuncPtr_glResetMinmax
#endif
#ifndef GLEE_H_DEFINED_glTexImage3D
#define GLEE_H_DEFINED_glTexImage3D
  typedef void (APIENTRYP GLEEPFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXIMAGE3DPROC GLeeFuncPtr_glTexImage3D;
  #define glTexImage3D GLeeFuncPtr_glTexImage3D
#endif
#ifndef GLEE_H_DEFINED_glTexSubImage3D
#define GLEE_H_DEFINED_glTexSubImage3D
  typedef void (APIENTRYP GLEEPFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXSUBIMAGE3DPROC GLeeFuncPtr_glTexSubImage3D;
  #define glTexSubImage3D GLeeFuncPtr_glTexSubImage3D
#endif
#ifndef GLEE_H_DEFINED_glCopyTexSubImage3D
#define GLEE_H_DEFINED_glCopyTexSubImage3D
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYTEXSUBIMAGE3DPROC GLeeFuncPtr_glCopyTexSubImage3D;
  #define glCopyTexSubImage3D GLeeFuncPtr_glCopyTexSubImage3D
#endif
#endif

/* GL_ARB_imaging */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#define __GLEE_GL_ARB_imaging 1
/* Constants */
#define GL_CONSTANT_COLOR                                  0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR                        0x8002
#define GL_CONSTANT_ALPHA                                  0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA                        0x8004
#define GL_BLEND_COLOR                                     0x8005
#define GL_FUNC_ADD                                        0x8006
#define GL_MIN                                             0x8007
#define GL_MAX                                             0x8008
#define GL_BLEND_EQUATION                                  0x8009
#define GL_FUNC_SUBTRACT                                   0x800A
#define GL_FUNC_REVERSE_SUBTRACT                           0x800B
#define GL_CONVOLUTION_1D                                  0x8010
#define GL_CONVOLUTION_2D                                  0x8011
#define GL_SEPARABLE_2D                                    0x8012
#define GL_CONVOLUTION_BORDER_MODE                         0x8013
#define GL_CONVOLUTION_FILTER_SCALE                        0x8014
#define GL_CONVOLUTION_FILTER_BIAS                         0x8015
#define GL_REDUCE                                          0x8016
#define GL_CONVOLUTION_FORMAT                              0x8017
#define GL_CONVOLUTION_WIDTH                               0x8018
#define GL_CONVOLUTION_HEIGHT                              0x8019
#define GL_MAX_CONVOLUTION_WIDTH                           0x801A
#define GL_MAX_CONVOLUTION_HEIGHT                          0x801B
#define GL_POST_CONVOLUTION_RED_SCALE                      0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE                    0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE                     0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE                    0x801F
#define GL_POST_CONVOLUTION_RED_BIAS                       0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS                     0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS                      0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS                     0x8023
#define GL_HISTOGRAM                                       0x8024
#define GL_PROXY_HISTOGRAM                                 0x8025
#define GL_HISTOGRAM_WIDTH                                 0x8026
#define GL_HISTOGRAM_FORMAT                                0x8027
#define GL_HISTOGRAM_RED_SIZE                              0x8028
#define GL_HISTOGRAM_GREEN_SIZE                            0x8029
#define GL_HISTOGRAM_BLUE_SIZE                             0x802A
#define GL_HISTOGRAM_ALPHA_SIZE                            0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE                        0x802C
#define GL_HISTOGRAM_SINK                                  0x802D
#define GL_MINMAX                                          0x802E
#define GL_MINMAX_FORMAT                                   0x802F
#define GL_MINMAX_SINK                                     0x8030
#define GL_TABLE_TOO_LARGE                                 0x8031
#define GL_COLOR_MATRIX                                    0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH                        0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH                    0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE                     0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE                   0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE                    0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE                   0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS                      0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS                    0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS                     0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS                    0x80BB
#define GL_COLOR_TABLE                                     0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE                    0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE                   0x80D2
#define GL_PROXY_COLOR_TABLE                               0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE              0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE             0x80D5
#define GL_COLOR_TABLE_SCALE                               0x80D6
#define GL_COLOR_TABLE_BIAS                                0x80D7
#define GL_COLOR_TABLE_FORMAT                              0x80D8
#define GL_COLOR_TABLE_WIDTH                               0x80D9
#define GL_COLOR_TABLE_RED_SIZE                            0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE                          0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE                           0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE                          0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE                      0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE                      0x80DF
#define GL_CONSTANT_BORDER                                 0x8151
#define GL_REPLICATE_BORDER                                0x8153
#define GL_CONVOLUTION_BORDER_COLOR                        0x8154
#endif

/* GL_VERSION_1_3 */

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define __GLEE_GL_VERSION_1_3 1
/* Constants */
#define GL_TEXTURE0                                        0x84C0
#define GL_TEXTURE1                                        0x84C1
#define GL_TEXTURE2                                        0x84C2
#define GL_TEXTURE3                                        0x84C3
#define GL_TEXTURE4                                        0x84C4
#define GL_TEXTURE5                                        0x84C5
#define GL_TEXTURE6                                        0x84C6
#define GL_TEXTURE7                                        0x84C7
#define GL_TEXTURE8                                        0x84C8
#define GL_TEXTURE9                                        0x84C9
#define GL_TEXTURE10                                       0x84CA
#define GL_TEXTURE11                                       0x84CB
#define GL_TEXTURE12                                       0x84CC
#define GL_TEXTURE13                                       0x84CD
#define GL_TEXTURE14                                       0x84CE
#define GL_TEXTURE15                                       0x84CF
#define GL_TEXTURE16                                       0x84D0
#define GL_TEXTURE17                                       0x84D1
#define GL_TEXTURE18                                       0x84D2
#define GL_TEXTURE19                                       0x84D3
#define GL_TEXTURE20                                       0x84D4
#define GL_TEXTURE21                                       0x84D5
#define GL_TEXTURE22                                       0x84D6
#define GL_TEXTURE23                                       0x84D7
#define GL_TEXTURE24                                       0x84D8
#define GL_TEXTURE25                                       0x84D9
#define GL_TEXTURE26                                       0x84DA
#define GL_TEXTURE27                                       0x84DB
#define GL_TEXTURE28                                       0x84DC
#define GL_TEXTURE29                                       0x84DD
#define GL_TEXTURE30                                       0x84DE
#define GL_TEXTURE31                                       0x84DF
#define GL_ACTIVE_TEXTURE                                  0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE                           0x84E1
#define GL_MAX_TEXTURE_UNITS                               0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX                      0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX                     0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX                        0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX                          0x84E6
#define GL_MULTISAMPLE                                     0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE                        0x809E
#define GL_SAMPLE_ALPHA_TO_ONE                             0x809F
#define GL_SAMPLE_COVERAGE                                 0x80A0
#define GL_SAMPLE_BUFFERS                                  0x80A8
#define GL_SAMPLES                                         0x80A9
#define GL_SAMPLE_COVERAGE_VALUE                           0x80AA
#define GL_SAMPLE_COVERAGE_INVERT                          0x80AB
#define GL_MULTISAMPLE_BIT                                 0x20000000
#define GL_NORMAL_MAP                                      0x8511
#define GL_REFLECTION_MAP                                  0x8512
#define GL_TEXTURE_CUBE_MAP                                0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP                        0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X                     0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X                     0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y                     0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                     0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z                     0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                     0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP                          0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE                       0x851C
#define GL_COMPRESSED_ALPHA                                0x84E9
#define GL_COMPRESSED_LUMINANCE                            0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA                      0x84EB
#define GL_COMPRESSED_INTENSITY                            0x84EC
#define GL_COMPRESSED_RGB                                  0x84ED
#define GL_COMPRESSED_RGBA                                 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT                        0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE                   0x86A0
#define GL_TEXTURE_COMPRESSED                              0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS                  0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS                      0x86A3
#define GL_CLAMP_TO_BORDER                                 0x812D
#define GL_COMBINE                                         0x8570
#define GL_COMBINE_RGB                                     0x8571
#define GL_COMBINE_ALPHA                                   0x8572
#define GL_SOURCE0_RGB                                     0x8580
#define GL_SOURCE1_RGB                                     0x8581
#define GL_SOURCE2_RGB                                     0x8582
#define GL_SOURCE0_ALPHA                                   0x8588
#define GL_SOURCE1_ALPHA                                   0x8589
#define GL_SOURCE2_ALPHA                                   0x858A
#define GL_OPERAND0_RGB                                    0x8590
#define GL_OPERAND1_RGB                                    0x8591
#define GL_OPERAND2_RGB                                    0x8592
#define GL_OPERAND0_ALPHA                                  0x8598
#define GL_OPERAND1_ALPHA                                  0x8599
#define GL_OPERAND2_ALPHA                                  0x859A
#define GL_RGB_SCALE                                       0x8573
#define GL_ADD_SIGNED                                      0x8574
#define GL_INTERPOLATE                                     0x8575
#define GL_SUBTRACT                                        0x84E7
#define GL_CONSTANT                                        0x8576
#define GL_PRIMARY_COLOR                                   0x8577
#define GL_PREVIOUS                                        0x8578
#define GL_DOT3_RGB                                        0x86AE
#define GL_DOT3_RGBA                                       0x86AF
#ifndef GLEE_H_DEFINED_glActiveTexture
#define GLEE_H_DEFINED_glActiveTexture
  typedef void (APIENTRYP GLEEPFNGLACTIVETEXTUREPROC) (GLenum texture);
  GLEE_EXTERN GLEEPFNGLACTIVETEXTUREPROC GLeeFuncPtr_glActiveTexture;
  #define glActiveTexture GLeeFuncPtr_glActiveTexture
#endif
#ifndef GLEE_H_DEFINED_glClientActiveTexture
#define GLEE_H_DEFINED_glClientActiveTexture
  typedef void (APIENTRYP GLEEPFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);
  GLEE_EXTERN GLEEPFNGLCLIENTACTIVETEXTUREPROC GLeeFuncPtr_glClientActiveTexture;
  #define glClientActiveTexture GLeeFuncPtr_glClientActiveTexture
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1d
#define GLEE_H_DEFINED_glMultiTexCoord1d
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1DPROC) (GLenum target, GLdouble s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1DPROC GLeeFuncPtr_glMultiTexCoord1d;
  #define glMultiTexCoord1d GLeeFuncPtr_glMultiTexCoord1d
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1dv
#define GLEE_H_DEFINED_glMultiTexCoord1dv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1DVPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1DVPROC GLeeFuncPtr_glMultiTexCoord1dv;
  #define glMultiTexCoord1dv GLeeFuncPtr_glMultiTexCoord1dv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1f
#define GLEE_H_DEFINED_glMultiTexCoord1f
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1FPROC) (GLenum target, GLfloat s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1FPROC GLeeFuncPtr_glMultiTexCoord1f;
  #define glMultiTexCoord1f GLeeFuncPtr_glMultiTexCoord1f
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1fv
#define GLEE_H_DEFINED_glMultiTexCoord1fv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1FVPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1FVPROC GLeeFuncPtr_glMultiTexCoord1fv;
  #define glMultiTexCoord1fv GLeeFuncPtr_glMultiTexCoord1fv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1i
#define GLEE_H_DEFINED_glMultiTexCoord1i
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1IPROC) (GLenum target, GLint s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1IPROC GLeeFuncPtr_glMultiTexCoord1i;
  #define glMultiTexCoord1i GLeeFuncPtr_glMultiTexCoord1i
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1iv
#define GLEE_H_DEFINED_glMultiTexCoord1iv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1IVPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1IVPROC GLeeFuncPtr_glMultiTexCoord1iv;
  #define glMultiTexCoord1iv GLeeFuncPtr_glMultiTexCoord1iv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1s
#define GLEE_H_DEFINED_glMultiTexCoord1s
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1SPROC) (GLenum target, GLshort s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1SPROC GLeeFuncPtr_glMultiTexCoord1s;
  #define glMultiTexCoord1s GLeeFuncPtr_glMultiTexCoord1s
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1sv
#define GLEE_H_DEFINED_glMultiTexCoord1sv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1SVPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1SVPROC GLeeFuncPtr_glMultiTexCoord1sv;
  #define glMultiTexCoord1sv GLeeFuncPtr_glMultiTexCoord1sv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2d
#define GLEE_H_DEFINED_glMultiTexCoord2d
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2DPROC) (GLenum target, GLdouble s, GLdouble t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2DPROC GLeeFuncPtr_glMultiTexCoord2d;
  #define glMultiTexCoord2d GLeeFuncPtr_glMultiTexCoord2d
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2dv
#define GLEE_H_DEFINED_glMultiTexCoord2dv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2DVPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2DVPROC GLeeFuncPtr_glMultiTexCoord2dv;
  #define glMultiTexCoord2dv GLeeFuncPtr_glMultiTexCoord2dv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2f
#define GLEE_H_DEFINED_glMultiTexCoord2f
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2FPROC) (GLenum target, GLfloat s, GLfloat t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2FPROC GLeeFuncPtr_glMultiTexCoord2f;
  #define glMultiTexCoord2f GLeeFuncPtr_glMultiTexCoord2f
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2fv
#define GLEE_H_DEFINED_glMultiTexCoord2fv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2FVPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2FVPROC GLeeFuncPtr_glMultiTexCoord2fv;
  #define glMultiTexCoord2fv GLeeFuncPtr_glMultiTexCoord2fv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2i
#define GLEE_H_DEFINED_glMultiTexCoord2i
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2IPROC) (GLenum target, GLint s, GLint t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2IPROC GLeeFuncPtr_glMultiTexCoord2i;
  #define glMultiTexCoord2i GLeeFuncPtr_glMultiTexCoord2i
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2iv
#define GLEE_H_DEFINED_glMultiTexCoord2iv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2IVPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2IVPROC GLeeFuncPtr_glMultiTexCoord2iv;
  #define glMultiTexCoord2iv GLeeFuncPtr_glMultiTexCoord2iv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2s
#define GLEE_H_DEFINED_glMultiTexCoord2s
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2SPROC) (GLenum target, GLshort s, GLshort t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2SPROC GLeeFuncPtr_glMultiTexCoord2s;
  #define glMultiTexCoord2s GLeeFuncPtr_glMultiTexCoord2s
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2sv
#define GLEE_H_DEFINED_glMultiTexCoord2sv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2SVPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2SVPROC GLeeFuncPtr_glMultiTexCoord2sv;
  #define glMultiTexCoord2sv GLeeFuncPtr_glMultiTexCoord2sv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3d
#define GLEE_H_DEFINED_glMultiTexCoord3d
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3DPROC GLeeFuncPtr_glMultiTexCoord3d;
  #define glMultiTexCoord3d GLeeFuncPtr_glMultiTexCoord3d
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3dv
#define GLEE_H_DEFINED_glMultiTexCoord3dv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3DVPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3DVPROC GLeeFuncPtr_glMultiTexCoord3dv;
  #define glMultiTexCoord3dv GLeeFuncPtr_glMultiTexCoord3dv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3f
#define GLEE_H_DEFINED_glMultiTexCoord3f
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3FPROC GLeeFuncPtr_glMultiTexCoord3f;
  #define glMultiTexCoord3f GLeeFuncPtr_glMultiTexCoord3f
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3fv
#define GLEE_H_DEFINED_glMultiTexCoord3fv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3FVPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3FVPROC GLeeFuncPtr_glMultiTexCoord3fv;
  #define glMultiTexCoord3fv GLeeFuncPtr_glMultiTexCoord3fv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3i
#define GLEE_H_DEFINED_glMultiTexCoord3i
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3IPROC) (GLenum target, GLint s, GLint t, GLint r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3IPROC GLeeFuncPtr_glMultiTexCoord3i;
  #define glMultiTexCoord3i GLeeFuncPtr_glMultiTexCoord3i
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3iv
#define GLEE_H_DEFINED_glMultiTexCoord3iv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3IVPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3IVPROC GLeeFuncPtr_glMultiTexCoord3iv;
  #define glMultiTexCoord3iv GLeeFuncPtr_glMultiTexCoord3iv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3s
#define GLEE_H_DEFINED_glMultiTexCoord3s
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3SPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3SPROC GLeeFuncPtr_glMultiTexCoord3s;
  #define glMultiTexCoord3s GLeeFuncPtr_glMultiTexCoord3s
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3sv
#define GLEE_H_DEFINED_glMultiTexCoord3sv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3SVPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3SVPROC GLeeFuncPtr_glMultiTexCoord3sv;
  #define glMultiTexCoord3sv GLeeFuncPtr_glMultiTexCoord3sv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4d
#define GLEE_H_DEFINED_glMultiTexCoord4d
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4DPROC GLeeFuncPtr_glMultiTexCoord4d;
  #define glMultiTexCoord4d GLeeFuncPtr_glMultiTexCoord4d
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4dv
#define GLEE_H_DEFINED_glMultiTexCoord4dv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4DVPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4DVPROC GLeeFuncPtr_glMultiTexCoord4dv;
  #define glMultiTexCoord4dv GLeeFuncPtr_glMultiTexCoord4dv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4f
#define GLEE_H_DEFINED_glMultiTexCoord4f
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4FPROC GLeeFuncPtr_glMultiTexCoord4f;
  #define glMultiTexCoord4f GLeeFuncPtr_glMultiTexCoord4f
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4fv
#define GLEE_H_DEFINED_glMultiTexCoord4fv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4FVPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4FVPROC GLeeFuncPtr_glMultiTexCoord4fv;
  #define glMultiTexCoord4fv GLeeFuncPtr_glMultiTexCoord4fv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4i
#define GLEE_H_DEFINED_glMultiTexCoord4i
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4IPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4IPROC GLeeFuncPtr_glMultiTexCoord4i;
  #define glMultiTexCoord4i GLeeFuncPtr_glMultiTexCoord4i
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4iv
#define GLEE_H_DEFINED_glMultiTexCoord4iv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4IVPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4IVPROC GLeeFuncPtr_glMultiTexCoord4iv;
  #define glMultiTexCoord4iv GLeeFuncPtr_glMultiTexCoord4iv
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4s
#define GLEE_H_DEFINED_glMultiTexCoord4s
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4SPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4SPROC GLeeFuncPtr_glMultiTexCoord4s;
  #define glMultiTexCoord4s GLeeFuncPtr_glMultiTexCoord4s
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4sv
#define GLEE_H_DEFINED_glMultiTexCoord4sv
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4SVPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4SVPROC GLeeFuncPtr_glMultiTexCoord4sv;
  #define glMultiTexCoord4sv GLeeFuncPtr_glMultiTexCoord4sv
#endif
#ifndef GLEE_H_DEFINED_glLoadTransposeMatrixf
#define GLEE_H_DEFINED_glLoadTransposeMatrixf
  typedef void (APIENTRYP GLEEPFNGLLOADTRANSPOSEMATRIXFPROC) (const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLLOADTRANSPOSEMATRIXFPROC GLeeFuncPtr_glLoadTransposeMatrixf;
  #define glLoadTransposeMatrixf GLeeFuncPtr_glLoadTransposeMatrixf
#endif
#ifndef GLEE_H_DEFINED_glLoadTransposeMatrixd
#define GLEE_H_DEFINED_glLoadTransposeMatrixd
  typedef void (APIENTRYP GLEEPFNGLLOADTRANSPOSEMATRIXDPROC) (const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLLOADTRANSPOSEMATRIXDPROC GLeeFuncPtr_glLoadTransposeMatrixd;
  #define glLoadTransposeMatrixd GLeeFuncPtr_glLoadTransposeMatrixd
#endif
#ifndef GLEE_H_DEFINED_glMultTransposeMatrixf
#define GLEE_H_DEFINED_glMultTransposeMatrixf
  typedef void (APIENTRYP GLEEPFNGLMULTTRANSPOSEMATRIXFPROC) (const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLMULTTRANSPOSEMATRIXFPROC GLeeFuncPtr_glMultTransposeMatrixf;
  #define glMultTransposeMatrixf GLeeFuncPtr_glMultTransposeMatrixf
#endif
#ifndef GLEE_H_DEFINED_glMultTransposeMatrixd
#define GLEE_H_DEFINED_glMultTransposeMatrixd
  typedef void (APIENTRYP GLEEPFNGLMULTTRANSPOSEMATRIXDPROC) (const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLMULTTRANSPOSEMATRIXDPROC GLeeFuncPtr_glMultTransposeMatrixd;
  #define glMultTransposeMatrixd GLeeFuncPtr_glMultTransposeMatrixd
#endif
#ifndef GLEE_H_DEFINED_glSampleCoverage
#define GLEE_H_DEFINED_glSampleCoverage
  typedef void (APIENTRYP GLEEPFNGLSAMPLECOVERAGEPROC) (GLclampf value, GLboolean invert);
  GLEE_EXTERN GLEEPFNGLSAMPLECOVERAGEPROC GLeeFuncPtr_glSampleCoverage;
  #define glSampleCoverage GLeeFuncPtr_glSampleCoverage
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexImage3D
#define GLEE_H_DEFINED_glCompressedTexImage3D
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXIMAGE3DPROC GLeeFuncPtr_glCompressedTexImage3D;
  #define glCompressedTexImage3D GLeeFuncPtr_glCompressedTexImage3D
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexImage2D
#define GLEE_H_DEFINED_glCompressedTexImage2D
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXIMAGE2DPROC GLeeFuncPtr_glCompressedTexImage2D;
  #define glCompressedTexImage2D GLeeFuncPtr_glCompressedTexImage2D
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexImage1D
#define GLEE_H_DEFINED_glCompressedTexImage1D
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXIMAGE1DPROC GLeeFuncPtr_glCompressedTexImage1D;
  #define glCompressedTexImage1D GLeeFuncPtr_glCompressedTexImage1D
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexSubImage3D
#define GLEE_H_DEFINED_glCompressedTexSubImage3D
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXSUBIMAGE3DPROC GLeeFuncPtr_glCompressedTexSubImage3D;
  #define glCompressedTexSubImage3D GLeeFuncPtr_glCompressedTexSubImage3D
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexSubImage2D
#define GLEE_H_DEFINED_glCompressedTexSubImage2D
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXSUBIMAGE2DPROC GLeeFuncPtr_glCompressedTexSubImage2D;
  #define glCompressedTexSubImage2D GLeeFuncPtr_glCompressedTexSubImage2D
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexSubImage1D
#define GLEE_H_DEFINED_glCompressedTexSubImage1D
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXSUBIMAGE1DPROC GLeeFuncPtr_glCompressedTexSubImage1D;
  #define glCompressedTexSubImage1D GLeeFuncPtr_glCompressedTexSubImage1D
#endif
#ifndef GLEE_H_DEFINED_glGetCompressedTexImage
#define GLEE_H_DEFINED_glGetCompressedTexImage
  typedef void (APIENTRYP GLEEPFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, GLvoid * img);
  GLEE_EXTERN GLEEPFNGLGETCOMPRESSEDTEXIMAGEPROC GLeeFuncPtr_glGetCompressedTexImage;
  #define glGetCompressedTexImage GLeeFuncPtr_glGetCompressedTexImage
#endif
#endif

/* GL_VERSION_1_4 */

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define __GLEE_GL_VERSION_1_4 1
/* Constants */
#define GL_BLEND_DST_RGB                                   0x80C8
#define GL_BLEND_SRC_RGB                                   0x80C9
#define GL_BLEND_DST_ALPHA                                 0x80CA
#define GL_BLEND_SRC_ALPHA                                 0x80CB
#define GL_POINT_SIZE_MIN                                  0x8126
#define GL_POINT_SIZE_MAX                                  0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE                       0x8128
#define GL_POINT_DISTANCE_ATTENUATION                      0x8129
#define GL_GENERATE_MIPMAP                                 0x8191
#define GL_GENERATE_MIPMAP_HINT                            0x8192
#define GL_DEPTH_COMPONENT16                               0x81A5
#define GL_DEPTH_COMPONENT24                               0x81A6
#define GL_DEPTH_COMPONENT32                               0x81A7
#define GL_MIRRORED_REPEAT                                 0x8370
#define GL_FOG_COORDINATE_SOURCE                           0x8450
#define GL_FOG_COORDINATE                                  0x8451
#define GL_FRAGMENT_DEPTH                                  0x8452
#define GL_CURRENT_FOG_COORDINATE                          0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE                       0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE                     0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER                    0x8456
#define GL_FOG_COORDINATE_ARRAY                            0x8457
#define GL_COLOR_SUM                                       0x8458
#define GL_CURRENT_SECONDARY_COLOR                         0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE                      0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE                      0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE                    0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER                   0x845D
#define GL_SECONDARY_COLOR_ARRAY                           0x845E
#define GL_MAX_TEXTURE_LOD_BIAS                            0x84FD
#define GL_TEXTURE_FILTER_CONTROL                          0x8500
#define GL_TEXTURE_LOD_BIAS                                0x8501
#define GL_INCR_WRAP                                       0x8507
#define GL_DECR_WRAP                                       0x8508
#define GL_TEXTURE_DEPTH_SIZE                              0x884A
#define GL_DEPTH_TEXTURE_MODE                              0x884B
#define GL_TEXTURE_COMPARE_MODE                            0x884C
#define GL_TEXTURE_COMPARE_FUNC                            0x884D
#define GL_COMPARE_R_TO_TEXTURE                            0x884E
#ifndef GLEE_H_DEFINED_glBlendFuncSeparate
#define GLEE_H_DEFINED_glBlendFuncSeparate
  typedef void (APIENTRYP GLEEPFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
  GLEE_EXTERN GLEEPFNGLBLENDFUNCSEPARATEPROC GLeeFuncPtr_glBlendFuncSeparate;
  #define glBlendFuncSeparate GLeeFuncPtr_glBlendFuncSeparate
#endif
#ifndef GLEE_H_DEFINED_glFogCoordf
#define GLEE_H_DEFINED_glFogCoordf
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDFPROC) (GLfloat coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDFPROC GLeeFuncPtr_glFogCoordf;
  #define glFogCoordf GLeeFuncPtr_glFogCoordf
#endif
#ifndef GLEE_H_DEFINED_glFogCoordfv
#define GLEE_H_DEFINED_glFogCoordfv
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDFVPROC) (const GLfloat * coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDFVPROC GLeeFuncPtr_glFogCoordfv;
  #define glFogCoordfv GLeeFuncPtr_glFogCoordfv
#endif
#ifndef GLEE_H_DEFINED_glFogCoordd
#define GLEE_H_DEFINED_glFogCoordd
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDDPROC) (GLdouble coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDDPROC GLeeFuncPtr_glFogCoordd;
  #define glFogCoordd GLeeFuncPtr_glFogCoordd
#endif
#ifndef GLEE_H_DEFINED_glFogCoorddv
#define GLEE_H_DEFINED_glFogCoorddv
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDDVPROC) (const GLdouble * coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDDVPROC GLeeFuncPtr_glFogCoorddv;
  #define glFogCoorddv GLeeFuncPtr_glFogCoorddv
#endif
#ifndef GLEE_H_DEFINED_glFogCoordPointer
#define GLEE_H_DEFINED_glFogCoordPointer
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDPOINTERPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLFOGCOORDPOINTERPROC GLeeFuncPtr_glFogCoordPointer;
  #define glFogCoordPointer GLeeFuncPtr_glFogCoordPointer
#endif
#ifndef GLEE_H_DEFINED_glMultiDrawArrays
#define GLEE_H_DEFINED_glMultiDrawArrays
  typedef void (APIENTRYP GLEEPFNGLMULTIDRAWARRAYSPROC) (GLenum mode, GLint * first, GLsizei * count, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLMULTIDRAWARRAYSPROC GLeeFuncPtr_glMultiDrawArrays;
  #define glMultiDrawArrays GLeeFuncPtr_glMultiDrawArrays
#endif
#ifndef GLEE_H_DEFINED_glMultiDrawElements
#define GLEE_H_DEFINED_glMultiDrawElements
  typedef void (APIENTRYP GLEEPFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei * count, GLenum type, const GLvoid* * indices, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLMULTIDRAWELEMENTSPROC GLeeFuncPtr_glMultiDrawElements;
  #define glMultiDrawElements GLeeFuncPtr_glMultiDrawElements
#endif
#ifndef GLEE_H_DEFINED_glPointParameterf
#define GLEE_H_DEFINED_glPointParameterf
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFPROC GLeeFuncPtr_glPointParameterf;
  #define glPointParameterf GLeeFuncPtr_glPointParameterf
#endif
#ifndef GLEE_H_DEFINED_glPointParameterfv
#define GLEE_H_DEFINED_glPointParameterfv
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFVPROC GLeeFuncPtr_glPointParameterfv;
  #define glPointParameterfv GLeeFuncPtr_glPointParameterfv
#endif
#ifndef GLEE_H_DEFINED_glPointParameteri
#define GLEE_H_DEFINED_glPointParameteri
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERIPROC GLeeFuncPtr_glPointParameteri;
  #define glPointParameteri GLeeFuncPtr_glPointParameteri
#endif
#ifndef GLEE_H_DEFINED_glPointParameteriv
#define GLEE_H_DEFINED_glPointParameteriv
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERIVPROC GLeeFuncPtr_glPointParameteriv;
  #define glPointParameteriv GLeeFuncPtr_glPointParameteriv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3b
#define GLEE_H_DEFINED_glSecondaryColor3b
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3BPROC GLeeFuncPtr_glSecondaryColor3b;
  #define glSecondaryColor3b GLeeFuncPtr_glSecondaryColor3b
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3bv
#define GLEE_H_DEFINED_glSecondaryColor3bv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3BVPROC) (const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3BVPROC GLeeFuncPtr_glSecondaryColor3bv;
  #define glSecondaryColor3bv GLeeFuncPtr_glSecondaryColor3bv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3d
#define GLEE_H_DEFINED_glSecondaryColor3d
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3DPROC GLeeFuncPtr_glSecondaryColor3d;
  #define glSecondaryColor3d GLeeFuncPtr_glSecondaryColor3d
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3dv
#define GLEE_H_DEFINED_glSecondaryColor3dv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3DVPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3DVPROC GLeeFuncPtr_glSecondaryColor3dv;
  #define glSecondaryColor3dv GLeeFuncPtr_glSecondaryColor3dv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3f
#define GLEE_H_DEFINED_glSecondaryColor3f
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3FPROC GLeeFuncPtr_glSecondaryColor3f;
  #define glSecondaryColor3f GLeeFuncPtr_glSecondaryColor3f
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3fv
#define GLEE_H_DEFINED_glSecondaryColor3fv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3FVPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3FVPROC GLeeFuncPtr_glSecondaryColor3fv;
  #define glSecondaryColor3fv GLeeFuncPtr_glSecondaryColor3fv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3i
#define GLEE_H_DEFINED_glSecondaryColor3i
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3IPROC) (GLint red, GLint green, GLint blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3IPROC GLeeFuncPtr_glSecondaryColor3i;
  #define glSecondaryColor3i GLeeFuncPtr_glSecondaryColor3i
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3iv
#define GLEE_H_DEFINED_glSecondaryColor3iv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3IVPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3IVPROC GLeeFuncPtr_glSecondaryColor3iv;
  #define glSecondaryColor3iv GLeeFuncPtr_glSecondaryColor3iv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3s
#define GLEE_H_DEFINED_glSecondaryColor3s
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3SPROC GLeeFuncPtr_glSecondaryColor3s;
  #define glSecondaryColor3s GLeeFuncPtr_glSecondaryColor3s
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3sv
#define GLEE_H_DEFINED_glSecondaryColor3sv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3SVPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3SVPROC GLeeFuncPtr_glSecondaryColor3sv;
  #define glSecondaryColor3sv GLeeFuncPtr_glSecondaryColor3sv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3ub
#define GLEE_H_DEFINED_glSecondaryColor3ub
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UBPROC GLeeFuncPtr_glSecondaryColor3ub;
  #define glSecondaryColor3ub GLeeFuncPtr_glSecondaryColor3ub
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3ubv
#define GLEE_H_DEFINED_glSecondaryColor3ubv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UBVPROC) (const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UBVPROC GLeeFuncPtr_glSecondaryColor3ubv;
  #define glSecondaryColor3ubv GLeeFuncPtr_glSecondaryColor3ubv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3ui
#define GLEE_H_DEFINED_glSecondaryColor3ui
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UIPROC GLeeFuncPtr_glSecondaryColor3ui;
  #define glSecondaryColor3ui GLeeFuncPtr_glSecondaryColor3ui
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3uiv
#define GLEE_H_DEFINED_glSecondaryColor3uiv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UIVPROC) (const GLuint * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UIVPROC GLeeFuncPtr_glSecondaryColor3uiv;
  #define glSecondaryColor3uiv GLeeFuncPtr_glSecondaryColor3uiv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3us
#define GLEE_H_DEFINED_glSecondaryColor3us
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3USPROC GLeeFuncPtr_glSecondaryColor3us;
  #define glSecondaryColor3us GLeeFuncPtr_glSecondaryColor3us
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3usv
#define GLEE_H_DEFINED_glSecondaryColor3usv
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3USVPROC) (const GLushort * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3USVPROC GLeeFuncPtr_glSecondaryColor3usv;
  #define glSecondaryColor3usv GLeeFuncPtr_glSecondaryColor3usv
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColorPointer
#define GLEE_H_DEFINED_glSecondaryColorPointer
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLORPOINTERPROC GLeeFuncPtr_glSecondaryColorPointer;
  #define glSecondaryColorPointer GLeeFuncPtr_glSecondaryColorPointer
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2d
#define GLEE_H_DEFINED_glWindowPos2d
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2DPROC) (GLdouble x, GLdouble y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2DPROC GLeeFuncPtr_glWindowPos2d;
  #define glWindowPos2d GLeeFuncPtr_glWindowPos2d
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2dv
#define GLEE_H_DEFINED_glWindowPos2dv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2DVPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2DVPROC GLeeFuncPtr_glWindowPos2dv;
  #define glWindowPos2dv GLeeFuncPtr_glWindowPos2dv
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2f
#define GLEE_H_DEFINED_glWindowPos2f
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2FPROC) (GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2FPROC GLeeFuncPtr_glWindowPos2f;
  #define glWindowPos2f GLeeFuncPtr_glWindowPos2f
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2fv
#define GLEE_H_DEFINED_glWindowPos2fv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2FVPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2FVPROC GLeeFuncPtr_glWindowPos2fv;
  #define glWindowPos2fv GLeeFuncPtr_glWindowPos2fv
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2i
#define GLEE_H_DEFINED_glWindowPos2i
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2IPROC) (GLint x, GLint y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2IPROC GLeeFuncPtr_glWindowPos2i;
  #define glWindowPos2i GLeeFuncPtr_glWindowPos2i
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2iv
#define GLEE_H_DEFINED_glWindowPos2iv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2IVPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2IVPROC GLeeFuncPtr_glWindowPos2iv;
  #define glWindowPos2iv GLeeFuncPtr_glWindowPos2iv
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2s
#define GLEE_H_DEFINED_glWindowPos2s
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2SPROC) (GLshort x, GLshort y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2SPROC GLeeFuncPtr_glWindowPos2s;
  #define glWindowPos2s GLeeFuncPtr_glWindowPos2s
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2sv
#define GLEE_H_DEFINED_glWindowPos2sv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2SVPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2SVPROC GLeeFuncPtr_glWindowPos2sv;
  #define glWindowPos2sv GLeeFuncPtr_glWindowPos2sv
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3d
#define GLEE_H_DEFINED_glWindowPos3d
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3DPROC GLeeFuncPtr_glWindowPos3d;
  #define glWindowPos3d GLeeFuncPtr_glWindowPos3d
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3dv
#define GLEE_H_DEFINED_glWindowPos3dv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3DVPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3DVPROC GLeeFuncPtr_glWindowPos3dv;
  #define glWindowPos3dv GLeeFuncPtr_glWindowPos3dv
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3f
#define GLEE_H_DEFINED_glWindowPos3f
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3FPROC GLeeFuncPtr_glWindowPos3f;
  #define glWindowPos3f GLeeFuncPtr_glWindowPos3f
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3fv
#define GLEE_H_DEFINED_glWindowPos3fv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3FVPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3FVPROC GLeeFuncPtr_glWindowPos3fv;
  #define glWindowPos3fv GLeeFuncPtr_glWindowPos3fv
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3i
#define GLEE_H_DEFINED_glWindowPos3i
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3IPROC) (GLint x, GLint y, GLint z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3IPROC GLeeFuncPtr_glWindowPos3i;
  #define glWindowPos3i GLeeFuncPtr_glWindowPos3i
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3iv
#define GLEE_H_DEFINED_glWindowPos3iv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3IVPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3IVPROC GLeeFuncPtr_glWindowPos3iv;
  #define glWindowPos3iv GLeeFuncPtr_glWindowPos3iv
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3s
#define GLEE_H_DEFINED_glWindowPos3s
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3SPROC) (GLshort x, GLshort y, GLshort z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3SPROC GLeeFuncPtr_glWindowPos3s;
  #define glWindowPos3s GLeeFuncPtr_glWindowPos3s
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3sv
#define GLEE_H_DEFINED_glWindowPos3sv
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3SVPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3SVPROC GLeeFuncPtr_glWindowPos3sv;
  #define glWindowPos3sv GLeeFuncPtr_glWindowPos3sv
#endif
#endif

/* GL_VERSION_1_5 */

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
#define __GLEE_GL_VERSION_1_5 1
/* Constants */
#define GL_BUFFER_SIZE                                     0x8764
#define GL_BUFFER_USAGE                                    0x8765
#define GL_QUERY_COUNTER_BITS                              0x8864
#define GL_CURRENT_QUERY                                   0x8865
#define GL_QUERY_RESULT                                    0x8866
#define GL_QUERY_RESULT_AVAILABLE                          0x8867
#define GL_ARRAY_BUFFER                                    0x8892
#define GL_ELEMENT_ARRAY_BUFFER                            0x8893
#define GL_ARRAY_BUFFER_BINDING                            0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING                    0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING                     0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING                     0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING                      0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING                      0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING              0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING                  0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING            0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING             0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING                     0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING              0x889F
#define GL_READ_ONLY                                       0x88B8
#define GL_WRITE_ONLY                                      0x88B9
#define GL_READ_WRITE                                      0x88BA
#define GL_BUFFER_ACCESS                                   0x88BB
#define GL_BUFFER_MAPPED                                   0x88BC
#define GL_BUFFER_MAP_POINTER                              0x88BD
#define GL_STREAM_DRAW                                     0x88E0
#define GL_STREAM_READ                                     0x88E1
#define GL_STREAM_COPY                                     0x88E2
#define GL_STATIC_DRAW                                     0x88E4
#define GL_STATIC_READ                                     0x88E5
#define GL_STATIC_COPY                                     0x88E6
#define GL_DYNAMIC_DRAW                                    0x88E8
#define GL_DYNAMIC_READ                                    0x88E9
#define GL_DYNAMIC_COPY                                    0x88EA
#define GL_SAMPLES_PASSED                                  0x8914
#define GL_FOG_COORD_SRC                                   GL_FOG_COORDINATE_SOURCE
#define GL_FOG_COORD                                       GL_FOG_COORDINATE
#define GL_CURRENT_FOG_COORD                               GL_CURRENT_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY_TYPE                            GL_FOG_COORDINATE_ARRAY_TYPE
#define GL_FOG_COORD_ARRAY_STRIDE                          GL_FOG_COORDINATE_ARRAY_STRIDE
#define GL_FOG_COORD_ARRAY_POINTER                         GL_FOG_COORDINATE_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY                                 GL_FOG_COORDINATE_ARRAY
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING                  GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define GL_SRC0_RGB                                        GL_SOURCE0_RGB
#define GL_SRC1_RGB                                        GL_SOURCE1_RGB
#define GL_SRC2_RGB                                        GL_SOURCE2_RGB
#define GL_SRC0_ALPHA                                      GL_SOURCE0_ALPHA
#define GL_SRC1_ALPHA                                      GL_SOURCE1_ALPHA
#define GL_SRC2_ALPHA                                      GL_SOURCE2_ALPHA
#ifndef GLEE_H_DEFINED_glGenQueries
#define GLEE_H_DEFINED_glGenQueries
  typedef void (APIENTRYP GLEEPFNGLGENQUERIESPROC) (GLsizei n, GLuint * ids);
  GLEE_EXTERN GLEEPFNGLGENQUERIESPROC GLeeFuncPtr_glGenQueries;
  #define glGenQueries GLeeFuncPtr_glGenQueries
#endif
#ifndef GLEE_H_DEFINED_glDeleteQueries
#define GLEE_H_DEFINED_glDeleteQueries
  typedef void (APIENTRYP GLEEPFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint * ids);
  GLEE_EXTERN GLEEPFNGLDELETEQUERIESPROC GLeeFuncPtr_glDeleteQueries;
  #define glDeleteQueries GLeeFuncPtr_glDeleteQueries
#endif
#ifndef GLEE_H_DEFINED_glIsQuery
#define GLEE_H_DEFINED_glIsQuery
  typedef GLboolean (APIENTRYP GLEEPFNGLISQUERYPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLISQUERYPROC GLeeFuncPtr_glIsQuery;
  #define glIsQuery GLeeFuncPtr_glIsQuery
#endif
#ifndef GLEE_H_DEFINED_glBeginQuery
#define GLEE_H_DEFINED_glBeginQuery
  typedef void (APIENTRYP GLEEPFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
  GLEE_EXTERN GLEEPFNGLBEGINQUERYPROC GLeeFuncPtr_glBeginQuery;
  #define glBeginQuery GLeeFuncPtr_glBeginQuery
#endif
#ifndef GLEE_H_DEFINED_glEndQuery
#define GLEE_H_DEFINED_glEndQuery
  typedef void (APIENTRYP GLEEPFNGLENDQUERYPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLENDQUERYPROC GLeeFuncPtr_glEndQuery;
  #define glEndQuery GLeeFuncPtr_glEndQuery
#endif
#ifndef GLEE_H_DEFINED_glGetQueryiv
#define GLEE_H_DEFINED_glGetQueryiv
  typedef void (APIENTRYP GLEEPFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYIVPROC GLeeFuncPtr_glGetQueryiv;
  #define glGetQueryiv GLeeFuncPtr_glGetQueryiv
#endif
#ifndef GLEE_H_DEFINED_glGetQueryObjectiv
#define GLEE_H_DEFINED_glGetQueryObjectiv
  typedef void (APIENTRYP GLEEPFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYOBJECTIVPROC GLeeFuncPtr_glGetQueryObjectiv;
  #define glGetQueryObjectiv GLeeFuncPtr_glGetQueryObjectiv
#endif
#ifndef GLEE_H_DEFINED_glGetQueryObjectuiv
#define GLEE_H_DEFINED_glGetQueryObjectuiv
  typedef void (APIENTRYP GLEEPFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYOBJECTUIVPROC GLeeFuncPtr_glGetQueryObjectuiv;
  #define glGetQueryObjectuiv GLeeFuncPtr_glGetQueryObjectuiv
#endif
#ifndef GLEE_H_DEFINED_glBindBuffer
#define GLEE_H_DEFINED_glBindBuffer
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERPROC GLeeFuncPtr_glBindBuffer;
  #define glBindBuffer GLeeFuncPtr_glBindBuffer
#endif
#ifndef GLEE_H_DEFINED_glDeleteBuffers
#define GLEE_H_DEFINED_glDeleteBuffers
  typedef void (APIENTRYP GLEEPFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint * buffers);
  GLEE_EXTERN GLEEPFNGLDELETEBUFFERSPROC GLeeFuncPtr_glDeleteBuffers;
  #define glDeleteBuffers GLeeFuncPtr_glDeleteBuffers
#endif
#ifndef GLEE_H_DEFINED_glGenBuffers
#define GLEE_H_DEFINED_glGenBuffers
  typedef void (APIENTRYP GLEEPFNGLGENBUFFERSPROC) (GLsizei n, GLuint * buffers);
  GLEE_EXTERN GLEEPFNGLGENBUFFERSPROC GLeeFuncPtr_glGenBuffers;
  #define glGenBuffers GLeeFuncPtr_glGenBuffers
#endif
#ifndef GLEE_H_DEFINED_glIsBuffer
#define GLEE_H_DEFINED_glIsBuffer
  typedef GLboolean (APIENTRYP GLEEPFNGLISBUFFERPROC) (GLuint buffer);
  GLEE_EXTERN GLEEPFNGLISBUFFERPROC GLeeFuncPtr_glIsBuffer;
  #define glIsBuffer GLeeFuncPtr_glIsBuffer
#endif
#ifndef GLEE_H_DEFINED_glBufferData
#define GLEE_H_DEFINED_glBufferData
  typedef void (APIENTRYP GLEEPFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
  GLEE_EXTERN GLEEPFNGLBUFFERDATAPROC GLeeFuncPtr_glBufferData;
  #define glBufferData GLeeFuncPtr_glBufferData
#endif
#ifndef GLEE_H_DEFINED_glBufferSubData
#define GLEE_H_DEFINED_glBufferSubData
  typedef void (APIENTRYP GLEEPFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLBUFFERSUBDATAPROC GLeeFuncPtr_glBufferSubData;
  #define glBufferSubData GLeeFuncPtr_glBufferSubData
#endif
#ifndef GLEE_H_DEFINED_glGetBufferSubData
#define GLEE_H_DEFINED_glGetBufferSubData
  typedef void (APIENTRYP GLEEPFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
  GLEE_EXTERN GLEEPFNGLGETBUFFERSUBDATAPROC GLeeFuncPtr_glGetBufferSubData;
  #define glGetBufferSubData GLeeFuncPtr_glGetBufferSubData
#endif
#ifndef GLEE_H_DEFINED_glMapBuffer
#define GLEE_H_DEFINED_glMapBuffer
  typedef GLvoid* (APIENTRYP GLEEPFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
  GLEE_EXTERN GLEEPFNGLMAPBUFFERPROC GLeeFuncPtr_glMapBuffer;
  #define glMapBuffer GLeeFuncPtr_glMapBuffer
#endif
#ifndef GLEE_H_DEFINED_glUnmapBuffer
#define GLEE_H_DEFINED_glUnmapBuffer
  typedef GLboolean (APIENTRYP GLEEPFNGLUNMAPBUFFERPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLUNMAPBUFFERPROC GLeeFuncPtr_glUnmapBuffer;
  #define glUnmapBuffer GLeeFuncPtr_glUnmapBuffer
#endif
#ifndef GLEE_H_DEFINED_glGetBufferParameteriv
#define GLEE_H_DEFINED_glGetBufferParameteriv
  typedef void (APIENTRYP GLEEPFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETBUFFERPARAMETERIVPROC GLeeFuncPtr_glGetBufferParameteriv;
  #define glGetBufferParameteriv GLeeFuncPtr_glGetBufferParameteriv
#endif
#ifndef GLEE_H_DEFINED_glGetBufferPointerv
#define GLEE_H_DEFINED_glGetBufferPointerv
  typedef void (APIENTRYP GLEEPFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, GLvoid* * params);
  GLEE_EXTERN GLEEPFNGLGETBUFFERPOINTERVPROC GLeeFuncPtr_glGetBufferPointerv;
  #define glGetBufferPointerv GLeeFuncPtr_glGetBufferPointerv
#endif
#endif

/* GL_VERSION_2_0 */

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
#define __GLEE_GL_VERSION_2_0 1
/* Constants */
#define GL_BLEND_EQUATION_RGB                              GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED                     0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE                        0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE                      0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE                        0x8625
#define GL_CURRENT_VERTEX_ATTRIB                           0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE                       0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE                         0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER                     0x8645
#define GL_STENCIL_BACK_FUNC                               0x8800
#define GL_STENCIL_BACK_FAIL                               0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL                    0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS                    0x8803
#define GL_MAX_DRAW_BUFFERS                                0x8824
#define GL_DRAW_BUFFER0                                    0x8825
#define GL_DRAW_BUFFER1                                    0x8826
#define GL_DRAW_BUFFER2                                    0x8827
#define GL_DRAW_BUFFER3                                    0x8828
#define GL_DRAW_BUFFER4                                    0x8829
#define GL_DRAW_BUFFER5                                    0x882A
#define GL_DRAW_BUFFER6                                    0x882B
#define GL_DRAW_BUFFER7                                    0x882C
#define GL_DRAW_BUFFER8                                    0x882D
#define GL_DRAW_BUFFER9                                    0x882E
#define GL_DRAW_BUFFER10                                   0x882F
#define GL_DRAW_BUFFER11                                   0x8830
#define GL_DRAW_BUFFER12                                   0x8831
#define GL_DRAW_BUFFER13                                   0x8832
#define GL_DRAW_BUFFER14                                   0x8833
#define GL_DRAW_BUFFER15                                   0x8834
#define GL_BLEND_EQUATION_ALPHA                            0x883D
#define GL_POINT_SPRITE                                    0x8861
#define GL_COORD_REPLACE                                   0x8862
#define GL_MAX_VERTEX_ATTRIBS                              0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                  0x886A
#define GL_MAX_TEXTURE_COORDS                              0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS                         0x8872
#define GL_FRAGMENT_SHADER                                 0x8B30
#define GL_VERTEX_SHADER                                   0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS                 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS                   0x8B4A
#define GL_MAX_VARYING_FLOATS                              0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                  0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS                0x8B4D
#define GL_SHADER_TYPE                                     0x8B4F
#define GL_FLOAT_VEC2                                      0x8B50
#define GL_FLOAT_VEC3                                      0x8B51
#define GL_FLOAT_VEC4                                      0x8B52
#define GL_INT_VEC2                                        0x8B53
#define GL_INT_VEC3                                        0x8B54
#define GL_INT_VEC4                                        0x8B55
#define GL_BOOL                                            0x8B56
#define GL_BOOL_VEC2                                       0x8B57
#define GL_BOOL_VEC3                                       0x8B58
#define GL_BOOL_VEC4                                       0x8B59
#define GL_FLOAT_MAT2                                      0x8B5A
#define GL_FLOAT_MAT3                                      0x8B5B
#define GL_FLOAT_MAT4                                      0x8B5C
#define GL_SAMPLER_1D                                      0x8B5D
#define GL_SAMPLER_2D                                      0x8B5E
#define GL_SAMPLER_3D                                      0x8B5F
#define GL_SAMPLER_CUBE                                    0x8B60
#define GL_SAMPLER_1D_SHADOW                               0x8B61
#define GL_SAMPLER_2D_SHADOW                               0x8B62
#define GL_DELETE_STATUS                                   0x8B80
#define GL_COMPILE_STATUS                                  0x8B81
#define GL_LINK_STATUS                                     0x8B82
#define GL_VALIDATE_STATUS                                 0x8B83
#define GL_INFO_LOG_LENGTH                                 0x8B84
#define GL_ATTACHED_SHADERS                                0x8B85
#define GL_ACTIVE_UNIFORMS                                 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH                       0x8B87
#define GL_SHADER_SOURCE_LENGTH                            0x8B88
#define GL_ACTIVE_ATTRIBUTES                               0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                     0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT                 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION                        0x8B8C
#define GL_CURRENT_PROGRAM                                 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN                       0x8CA0
#define GL_LOWER_LEFT                                      0x8CA1
#define GL_UPPER_LEFT                                      0x8CA2
#define GL_STENCIL_BACK_REF                                0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK                         0x8CA4
#define GL_STENCIL_BACK_WRITEMASK                          0x8CA5
#ifndef GLEE_H_DEFINED_glBlendEquationSeparate
#define GLEE_H_DEFINED_glBlendEquationSeparate
  typedef void (APIENTRYP GLEEPFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
  GLEE_EXTERN GLEEPFNGLBLENDEQUATIONSEPARATEPROC GLeeFuncPtr_glBlendEquationSeparate;
  #define glBlendEquationSeparate GLeeFuncPtr_glBlendEquationSeparate
#endif
#ifndef GLEE_H_DEFINED_glDrawBuffers
#define GLEE_H_DEFINED_glDrawBuffers
  typedef void (APIENTRYP GLEEPFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum * bufs);
  GLEE_EXTERN GLEEPFNGLDRAWBUFFERSPROC GLeeFuncPtr_glDrawBuffers;
  #define glDrawBuffers GLeeFuncPtr_glDrawBuffers
#endif
#ifndef GLEE_H_DEFINED_glStencilOpSeparate
#define GLEE_H_DEFINED_glStencilOpSeparate
  typedef void (APIENTRYP GLEEPFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
  GLEE_EXTERN GLEEPFNGLSTENCILOPSEPARATEPROC GLeeFuncPtr_glStencilOpSeparate;
  #define glStencilOpSeparate GLeeFuncPtr_glStencilOpSeparate
#endif
#ifndef GLEE_H_DEFINED_glStencilFuncSeparate
#define GLEE_H_DEFINED_glStencilFuncSeparate
  typedef void (APIENTRYP GLEEPFNGLSTENCILFUNCSEPARATEPROC) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
  GLEE_EXTERN GLEEPFNGLSTENCILFUNCSEPARATEPROC GLeeFuncPtr_glStencilFuncSeparate;
  #define glStencilFuncSeparate GLeeFuncPtr_glStencilFuncSeparate
#endif
#ifndef GLEE_H_DEFINED_glStencilMaskSeparate
#define GLEE_H_DEFINED_glStencilMaskSeparate
  typedef void (APIENTRYP GLEEPFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
  GLEE_EXTERN GLEEPFNGLSTENCILMASKSEPARATEPROC GLeeFuncPtr_glStencilMaskSeparate;
  #define glStencilMaskSeparate GLeeFuncPtr_glStencilMaskSeparate
#endif
#ifndef GLEE_H_DEFINED_glAttachShader
#define GLEE_H_DEFINED_glAttachShader
  typedef void (APIENTRYP GLEEPFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
  GLEE_EXTERN GLEEPFNGLATTACHSHADERPROC GLeeFuncPtr_glAttachShader;
  #define glAttachShader GLeeFuncPtr_glAttachShader
#endif
#ifndef GLEE_H_DEFINED_glBindAttribLocation
#define GLEE_H_DEFINED_glBindAttribLocation
  typedef void (APIENTRYP GLEEPFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLBINDATTRIBLOCATIONPROC GLeeFuncPtr_glBindAttribLocation;
  #define glBindAttribLocation GLeeFuncPtr_glBindAttribLocation
#endif
#ifndef GLEE_H_DEFINED_glCompileShader
#define GLEE_H_DEFINED_glCompileShader
  typedef void (APIENTRYP GLEEPFNGLCOMPILESHADERPROC) (GLuint shader);
  GLEE_EXTERN GLEEPFNGLCOMPILESHADERPROC GLeeFuncPtr_glCompileShader;
  #define glCompileShader GLeeFuncPtr_glCompileShader
#endif
#ifndef GLEE_H_DEFINED_glCreateProgram
#define GLEE_H_DEFINED_glCreateProgram
  typedef GLuint (APIENTRYP GLEEPFNGLCREATEPROGRAMPROC) ();
  GLEE_EXTERN GLEEPFNGLCREATEPROGRAMPROC GLeeFuncPtr_glCreateProgram;
  #define glCreateProgram GLeeFuncPtr_glCreateProgram
#endif
#ifndef GLEE_H_DEFINED_glCreateShader
#define GLEE_H_DEFINED_glCreateShader
  typedef GLuint (APIENTRYP GLEEPFNGLCREATESHADERPROC) (GLenum type);
  GLEE_EXTERN GLEEPFNGLCREATESHADERPROC GLeeFuncPtr_glCreateShader;
  #define glCreateShader GLeeFuncPtr_glCreateShader
#endif
#ifndef GLEE_H_DEFINED_glDeleteProgram
#define GLEE_H_DEFINED_glDeleteProgram
  typedef void (APIENTRYP GLEEPFNGLDELETEPROGRAMPROC) (GLuint program);
  GLEE_EXTERN GLEEPFNGLDELETEPROGRAMPROC GLeeFuncPtr_glDeleteProgram;
  #define glDeleteProgram GLeeFuncPtr_glDeleteProgram
#endif
#ifndef GLEE_H_DEFINED_glDeleteShader
#define GLEE_H_DEFINED_glDeleteShader
  typedef void (APIENTRYP GLEEPFNGLDELETESHADERPROC) (GLuint shader);
  GLEE_EXTERN GLEEPFNGLDELETESHADERPROC GLeeFuncPtr_glDeleteShader;
  #define glDeleteShader GLeeFuncPtr_glDeleteShader
#endif
#ifndef GLEE_H_DEFINED_glDetachShader
#define GLEE_H_DEFINED_glDetachShader
  typedef void (APIENTRYP GLEEPFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
  GLEE_EXTERN GLEEPFNGLDETACHSHADERPROC GLeeFuncPtr_glDetachShader;
  #define glDetachShader GLeeFuncPtr_glDetachShader
#endif
#ifndef GLEE_H_DEFINED_glDisableVertexAttribArray
#define GLEE_H_DEFINED_glDisableVertexAttribArray
  typedef void (APIENTRYP GLEEPFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
  GLEE_EXTERN GLEEPFNGLDISABLEVERTEXATTRIBARRAYPROC GLeeFuncPtr_glDisableVertexAttribArray;
  #define glDisableVertexAttribArray GLeeFuncPtr_glDisableVertexAttribArray
#endif
#ifndef GLEE_H_DEFINED_glEnableVertexAttribArray
#define GLEE_H_DEFINED_glEnableVertexAttribArray
  typedef void (APIENTRYP GLEEPFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
  GLEE_EXTERN GLEEPFNGLENABLEVERTEXATTRIBARRAYPROC GLeeFuncPtr_glEnableVertexAttribArray;
  #define glEnableVertexAttribArray GLeeFuncPtr_glEnableVertexAttribArray
#endif
#ifndef GLEE_H_DEFINED_glGetActiveAttrib
#define GLEE_H_DEFINED_glGetActiveAttrib
  typedef void (APIENTRYP GLEEPFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETACTIVEATTRIBPROC GLeeFuncPtr_glGetActiveAttrib;
  #define glGetActiveAttrib GLeeFuncPtr_glGetActiveAttrib
#endif
#ifndef GLEE_H_DEFINED_glGetActiveUniform
#define GLEE_H_DEFINED_glGetActiveUniform
  typedef void (APIENTRYP GLEEPFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETACTIVEUNIFORMPROC GLeeFuncPtr_glGetActiveUniform;
  #define glGetActiveUniform GLeeFuncPtr_glGetActiveUniform
#endif
#ifndef GLEE_H_DEFINED_glGetAttachedShaders
#define GLEE_H_DEFINED_glGetAttachedShaders
  typedef void (APIENTRYP GLEEPFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj);
  GLEE_EXTERN GLEEPFNGLGETATTACHEDSHADERSPROC GLeeFuncPtr_glGetAttachedShaders;
  #define glGetAttachedShaders GLeeFuncPtr_glGetAttachedShaders
#endif
#ifndef GLEE_H_DEFINED_glGetAttribLocation
#define GLEE_H_DEFINED_glGetAttribLocation
  typedef GLint (APIENTRYP GLEEPFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETATTRIBLOCATIONPROC GLeeFuncPtr_glGetAttribLocation;
  #define glGetAttribLocation GLeeFuncPtr_glGetAttribLocation
#endif
#ifndef GLEE_H_DEFINED_glGetProgramiv
#define GLEE_H_DEFINED_glGetProgramiv
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMIVPROC GLeeFuncPtr_glGetProgramiv;
  #define glGetProgramiv GLeeFuncPtr_glGetProgramiv
#endif
#ifndef GLEE_H_DEFINED_glGetProgramInfoLog
#define GLEE_H_DEFINED_glGetProgramInfoLog
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMINFOLOGPROC GLeeFuncPtr_glGetProgramInfoLog;
  #define glGetProgramInfoLog GLeeFuncPtr_glGetProgramInfoLog
#endif
#ifndef GLEE_H_DEFINED_glGetShaderiv
#define GLEE_H_DEFINED_glGetShaderiv
  typedef void (APIENTRYP GLEEPFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETSHADERIVPROC GLeeFuncPtr_glGetShaderiv;
  #define glGetShaderiv GLeeFuncPtr_glGetShaderiv
#endif
#ifndef GLEE_H_DEFINED_glGetShaderInfoLog
#define GLEE_H_DEFINED_glGetShaderInfoLog
  typedef void (APIENTRYP GLEEPFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
  GLEE_EXTERN GLEEPFNGLGETSHADERINFOLOGPROC GLeeFuncPtr_glGetShaderInfoLog;
  #define glGetShaderInfoLog GLeeFuncPtr_glGetShaderInfoLog
#endif
#ifndef GLEE_H_DEFINED_glGetShaderSource
#define GLEE_H_DEFINED_glGetShaderSource
  typedef void (APIENTRYP GLEEPFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
  GLEE_EXTERN GLEEPFNGLGETSHADERSOURCEPROC GLeeFuncPtr_glGetShaderSource;
  #define glGetShaderSource GLeeFuncPtr_glGetShaderSource
#endif
#ifndef GLEE_H_DEFINED_glGetUniformLocation
#define GLEE_H_DEFINED_glGetUniformLocation
  typedef GLint (APIENTRYP GLEEPFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMLOCATIONPROC GLeeFuncPtr_glGetUniformLocation;
  #define glGetUniformLocation GLeeFuncPtr_glGetUniformLocation
#endif
#ifndef GLEE_H_DEFINED_glGetUniformfv
#define GLEE_H_DEFINED_glGetUniformfv
  typedef void (APIENTRYP GLEEPFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMFVPROC GLeeFuncPtr_glGetUniformfv;
  #define glGetUniformfv GLeeFuncPtr_glGetUniformfv
#endif
#ifndef GLEE_H_DEFINED_glGetUniformiv
#define GLEE_H_DEFINED_glGetUniformiv
  typedef void (APIENTRYP GLEEPFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMIVPROC GLeeFuncPtr_glGetUniformiv;
  #define glGetUniformiv GLeeFuncPtr_glGetUniformiv
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribdv
#define GLEE_H_DEFINED_glGetVertexAttribdv
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBDVPROC GLeeFuncPtr_glGetVertexAttribdv;
  #define glGetVertexAttribdv GLeeFuncPtr_glGetVertexAttribdv
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribfv
#define GLEE_H_DEFINED_glGetVertexAttribfv
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBFVPROC GLeeFuncPtr_glGetVertexAttribfv;
  #define glGetVertexAttribfv GLeeFuncPtr_glGetVertexAttribfv
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribiv
#define GLEE_H_DEFINED_glGetVertexAttribiv
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBIVPROC GLeeFuncPtr_glGetVertexAttribiv;
  #define glGetVertexAttribiv GLeeFuncPtr_glGetVertexAttribiv
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribPointerv
#define GLEE_H_DEFINED_glGetVertexAttribPointerv
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBPOINTERVPROC GLeeFuncPtr_glGetVertexAttribPointerv;
  #define glGetVertexAttribPointerv GLeeFuncPtr_glGetVertexAttribPointerv
#endif
#ifndef GLEE_H_DEFINED_glIsProgram
#define GLEE_H_DEFINED_glIsProgram
  typedef GLboolean (APIENTRYP GLEEPFNGLISPROGRAMPROC) (GLuint program);
  GLEE_EXTERN GLEEPFNGLISPROGRAMPROC GLeeFuncPtr_glIsProgram;
  #define glIsProgram GLeeFuncPtr_glIsProgram
#endif
#ifndef GLEE_H_DEFINED_glIsShader
#define GLEE_H_DEFINED_glIsShader
  typedef GLboolean (APIENTRYP GLEEPFNGLISSHADERPROC) (GLuint shader);
  GLEE_EXTERN GLEEPFNGLISSHADERPROC GLeeFuncPtr_glIsShader;
  #define glIsShader GLeeFuncPtr_glIsShader
#endif
#ifndef GLEE_H_DEFINED_glLinkProgram
#define GLEE_H_DEFINED_glLinkProgram
  typedef void (APIENTRYP GLEEPFNGLLINKPROGRAMPROC) (GLuint program);
  GLEE_EXTERN GLEEPFNGLLINKPROGRAMPROC GLeeFuncPtr_glLinkProgram;
  #define glLinkProgram GLeeFuncPtr_glLinkProgram
#endif
#ifndef GLEE_H_DEFINED_glShaderSource
#define GLEE_H_DEFINED_glShaderSource
  typedef void (APIENTRYP GLEEPFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar* * string, const GLint * length);
  GLEE_EXTERN GLEEPFNGLSHADERSOURCEPROC GLeeFuncPtr_glShaderSource;
  #define glShaderSource GLeeFuncPtr_glShaderSource
#endif
#ifndef GLEE_H_DEFINED_glUseProgram
#define GLEE_H_DEFINED_glUseProgram
  typedef void (APIENTRYP GLEEPFNGLUSEPROGRAMPROC) (GLuint program);
  GLEE_EXTERN GLEEPFNGLUSEPROGRAMPROC GLeeFuncPtr_glUseProgram;
  #define glUseProgram GLeeFuncPtr_glUseProgram
#endif
#ifndef GLEE_H_DEFINED_glUniform1f
#define GLEE_H_DEFINED_glUniform1f
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
  GLEE_EXTERN GLEEPFNGLUNIFORM1FPROC GLeeFuncPtr_glUniform1f;
  #define glUniform1f GLeeFuncPtr_glUniform1f
#endif
#ifndef GLEE_H_DEFINED_glUniform2f
#define GLEE_H_DEFINED_glUniform2f
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
  GLEE_EXTERN GLEEPFNGLUNIFORM2FPROC GLeeFuncPtr_glUniform2f;
  #define glUniform2f GLeeFuncPtr_glUniform2f
#endif
#ifndef GLEE_H_DEFINED_glUniform3f
#define GLEE_H_DEFINED_glUniform3f
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
  GLEE_EXTERN GLEEPFNGLUNIFORM3FPROC GLeeFuncPtr_glUniform3f;
  #define glUniform3f GLeeFuncPtr_glUniform3f
#endif
#ifndef GLEE_H_DEFINED_glUniform4f
#define GLEE_H_DEFINED_glUniform4f
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
  GLEE_EXTERN GLEEPFNGLUNIFORM4FPROC GLeeFuncPtr_glUniform4f;
  #define glUniform4f GLeeFuncPtr_glUniform4f
#endif
#ifndef GLEE_H_DEFINED_glUniform1i
#define GLEE_H_DEFINED_glUniform1i
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1IPROC) (GLint location, GLint v0);
  GLEE_EXTERN GLEEPFNGLUNIFORM1IPROC GLeeFuncPtr_glUniform1i;
  #define glUniform1i GLeeFuncPtr_glUniform1i
#endif
#ifndef GLEE_H_DEFINED_glUniform2i
#define GLEE_H_DEFINED_glUniform2i
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
  GLEE_EXTERN GLEEPFNGLUNIFORM2IPROC GLeeFuncPtr_glUniform2i;
  #define glUniform2i GLeeFuncPtr_glUniform2i
#endif
#ifndef GLEE_H_DEFINED_glUniform3i
#define GLEE_H_DEFINED_glUniform3i
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
  GLEE_EXTERN GLEEPFNGLUNIFORM3IPROC GLeeFuncPtr_glUniform3i;
  #define glUniform3i GLeeFuncPtr_glUniform3i
#endif
#ifndef GLEE_H_DEFINED_glUniform4i
#define GLEE_H_DEFINED_glUniform4i
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
  GLEE_EXTERN GLEEPFNGLUNIFORM4IPROC GLeeFuncPtr_glUniform4i;
  #define glUniform4i GLeeFuncPtr_glUniform4i
#endif
#ifndef GLEE_H_DEFINED_glUniform1fv
#define GLEE_H_DEFINED_glUniform1fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM1FVPROC GLeeFuncPtr_glUniform1fv;
  #define glUniform1fv GLeeFuncPtr_glUniform1fv
#endif
#ifndef GLEE_H_DEFINED_glUniform2fv
#define GLEE_H_DEFINED_glUniform2fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM2FVPROC GLeeFuncPtr_glUniform2fv;
  #define glUniform2fv GLeeFuncPtr_glUniform2fv
#endif
#ifndef GLEE_H_DEFINED_glUniform3fv
#define GLEE_H_DEFINED_glUniform3fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM3FVPROC GLeeFuncPtr_glUniform3fv;
  #define glUniform3fv GLeeFuncPtr_glUniform3fv
#endif
#ifndef GLEE_H_DEFINED_glUniform4fv
#define GLEE_H_DEFINED_glUniform4fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM4FVPROC GLeeFuncPtr_glUniform4fv;
  #define glUniform4fv GLeeFuncPtr_glUniform4fv
#endif
#ifndef GLEE_H_DEFINED_glUniform1iv
#define GLEE_H_DEFINED_glUniform1iv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM1IVPROC GLeeFuncPtr_glUniform1iv;
  #define glUniform1iv GLeeFuncPtr_glUniform1iv
#endif
#ifndef GLEE_H_DEFINED_glUniform2iv
#define GLEE_H_DEFINED_glUniform2iv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM2IVPROC GLeeFuncPtr_glUniform2iv;
  #define glUniform2iv GLeeFuncPtr_glUniform2iv
#endif
#ifndef GLEE_H_DEFINED_glUniform3iv
#define GLEE_H_DEFINED_glUniform3iv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM3IVPROC GLeeFuncPtr_glUniform3iv;
  #define glUniform3iv GLeeFuncPtr_glUniform3iv
#endif
#ifndef GLEE_H_DEFINED_glUniform4iv
#define GLEE_H_DEFINED_glUniform4iv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM4IVPROC GLeeFuncPtr_glUniform4iv;
  #define glUniform4iv GLeeFuncPtr_glUniform4iv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix2fv
#define GLEE_H_DEFINED_glUniformMatrix2fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX2FVPROC GLeeFuncPtr_glUniformMatrix2fv;
  #define glUniformMatrix2fv GLeeFuncPtr_glUniformMatrix2fv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix3fv
#define GLEE_H_DEFINED_glUniformMatrix3fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX3FVPROC GLeeFuncPtr_glUniformMatrix3fv;
  #define glUniformMatrix3fv GLeeFuncPtr_glUniformMatrix3fv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix4fv
#define GLEE_H_DEFINED_glUniformMatrix4fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX4FVPROC GLeeFuncPtr_glUniformMatrix4fv;
  #define glUniformMatrix4fv GLeeFuncPtr_glUniformMatrix4fv
#endif
#ifndef GLEE_H_DEFINED_glValidateProgram
#define GLEE_H_DEFINED_glValidateProgram
  typedef void (APIENTRYP GLEEPFNGLVALIDATEPROGRAMPROC) (GLuint program);
  GLEE_EXTERN GLEEPFNGLVALIDATEPROGRAMPROC GLeeFuncPtr_glValidateProgram;
  #define glValidateProgram GLeeFuncPtr_glValidateProgram
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1d
#define GLEE_H_DEFINED_glVertexAttrib1d
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1DPROC GLeeFuncPtr_glVertexAttrib1d;
  #define glVertexAttrib1d GLeeFuncPtr_glVertexAttrib1d
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1dv
#define GLEE_H_DEFINED_glVertexAttrib1dv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1DVPROC GLeeFuncPtr_glVertexAttrib1dv;
  #define glVertexAttrib1dv GLeeFuncPtr_glVertexAttrib1dv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1f
#define GLEE_H_DEFINED_glVertexAttrib1f
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1FPROC GLeeFuncPtr_glVertexAttrib1f;
  #define glVertexAttrib1f GLeeFuncPtr_glVertexAttrib1f
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1fv
#define GLEE_H_DEFINED_glVertexAttrib1fv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1FVPROC GLeeFuncPtr_glVertexAttrib1fv;
  #define glVertexAttrib1fv GLeeFuncPtr_glVertexAttrib1fv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1s
#define GLEE_H_DEFINED_glVertexAttrib1s
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1SPROC GLeeFuncPtr_glVertexAttrib1s;
  #define glVertexAttrib1s GLeeFuncPtr_glVertexAttrib1s
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1sv
#define GLEE_H_DEFINED_glVertexAttrib1sv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1SVPROC GLeeFuncPtr_glVertexAttrib1sv;
  #define glVertexAttrib1sv GLeeFuncPtr_glVertexAttrib1sv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2d
#define GLEE_H_DEFINED_glVertexAttrib2d
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2DPROC GLeeFuncPtr_glVertexAttrib2d;
  #define glVertexAttrib2d GLeeFuncPtr_glVertexAttrib2d
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2dv
#define GLEE_H_DEFINED_glVertexAttrib2dv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2DVPROC GLeeFuncPtr_glVertexAttrib2dv;
  #define glVertexAttrib2dv GLeeFuncPtr_glVertexAttrib2dv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2f
#define GLEE_H_DEFINED_glVertexAttrib2f
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2FPROC GLeeFuncPtr_glVertexAttrib2f;
  #define glVertexAttrib2f GLeeFuncPtr_glVertexAttrib2f
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2fv
#define GLEE_H_DEFINED_glVertexAttrib2fv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2FVPROC GLeeFuncPtr_glVertexAttrib2fv;
  #define glVertexAttrib2fv GLeeFuncPtr_glVertexAttrib2fv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2s
#define GLEE_H_DEFINED_glVertexAttrib2s
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2SPROC GLeeFuncPtr_glVertexAttrib2s;
  #define glVertexAttrib2s GLeeFuncPtr_glVertexAttrib2s
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2sv
#define GLEE_H_DEFINED_glVertexAttrib2sv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2SVPROC GLeeFuncPtr_glVertexAttrib2sv;
  #define glVertexAttrib2sv GLeeFuncPtr_glVertexAttrib2sv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3d
#define GLEE_H_DEFINED_glVertexAttrib3d
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3DPROC GLeeFuncPtr_glVertexAttrib3d;
  #define glVertexAttrib3d GLeeFuncPtr_glVertexAttrib3d
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3dv
#define GLEE_H_DEFINED_glVertexAttrib3dv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3DVPROC GLeeFuncPtr_glVertexAttrib3dv;
  #define glVertexAttrib3dv GLeeFuncPtr_glVertexAttrib3dv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3f
#define GLEE_H_DEFINED_glVertexAttrib3f
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3FPROC GLeeFuncPtr_glVertexAttrib3f;
  #define glVertexAttrib3f GLeeFuncPtr_glVertexAttrib3f
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3fv
#define GLEE_H_DEFINED_glVertexAttrib3fv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3FVPROC GLeeFuncPtr_glVertexAttrib3fv;
  #define glVertexAttrib3fv GLeeFuncPtr_glVertexAttrib3fv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3s
#define GLEE_H_DEFINED_glVertexAttrib3s
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3SPROC GLeeFuncPtr_glVertexAttrib3s;
  #define glVertexAttrib3s GLeeFuncPtr_glVertexAttrib3s
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3sv
#define GLEE_H_DEFINED_glVertexAttrib3sv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3SVPROC GLeeFuncPtr_glVertexAttrib3sv;
  #define glVertexAttrib3sv GLeeFuncPtr_glVertexAttrib3sv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4Nbv
#define GLEE_H_DEFINED_glVertexAttrib4Nbv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NBVPROC GLeeFuncPtr_glVertexAttrib4Nbv;
  #define glVertexAttrib4Nbv GLeeFuncPtr_glVertexAttrib4Nbv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4Niv
#define GLEE_H_DEFINED_glVertexAttrib4Niv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NIVPROC GLeeFuncPtr_glVertexAttrib4Niv;
  #define glVertexAttrib4Niv GLeeFuncPtr_glVertexAttrib4Niv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4Nsv
#define GLEE_H_DEFINED_glVertexAttrib4Nsv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NSVPROC GLeeFuncPtr_glVertexAttrib4Nsv;
  #define glVertexAttrib4Nsv GLeeFuncPtr_glVertexAttrib4Nsv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4Nub
#define GLEE_H_DEFINED_glVertexAttrib4Nub
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUBPROC GLeeFuncPtr_glVertexAttrib4Nub;
  #define glVertexAttrib4Nub GLeeFuncPtr_glVertexAttrib4Nub
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4Nubv
#define GLEE_H_DEFINED_glVertexAttrib4Nubv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUBVPROC GLeeFuncPtr_glVertexAttrib4Nubv;
  #define glVertexAttrib4Nubv GLeeFuncPtr_glVertexAttrib4Nubv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4Nuiv
#define GLEE_H_DEFINED_glVertexAttrib4Nuiv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUIVPROC GLeeFuncPtr_glVertexAttrib4Nuiv;
  #define glVertexAttrib4Nuiv GLeeFuncPtr_glVertexAttrib4Nuiv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4Nusv
#define GLEE_H_DEFINED_glVertexAttrib4Nusv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUSVPROC GLeeFuncPtr_glVertexAttrib4Nusv;
  #define glVertexAttrib4Nusv GLeeFuncPtr_glVertexAttrib4Nusv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4bv
#define GLEE_H_DEFINED_glVertexAttrib4bv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4BVPROC GLeeFuncPtr_glVertexAttrib4bv;
  #define glVertexAttrib4bv GLeeFuncPtr_glVertexAttrib4bv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4d
#define GLEE_H_DEFINED_glVertexAttrib4d
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4DPROC GLeeFuncPtr_glVertexAttrib4d;
  #define glVertexAttrib4d GLeeFuncPtr_glVertexAttrib4d
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4dv
#define GLEE_H_DEFINED_glVertexAttrib4dv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4DVPROC GLeeFuncPtr_glVertexAttrib4dv;
  #define glVertexAttrib4dv GLeeFuncPtr_glVertexAttrib4dv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4f
#define GLEE_H_DEFINED_glVertexAttrib4f
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4FPROC GLeeFuncPtr_glVertexAttrib4f;
  #define glVertexAttrib4f GLeeFuncPtr_glVertexAttrib4f
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4fv
#define GLEE_H_DEFINED_glVertexAttrib4fv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4FVPROC GLeeFuncPtr_glVertexAttrib4fv;
  #define glVertexAttrib4fv GLeeFuncPtr_glVertexAttrib4fv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4iv
#define GLEE_H_DEFINED_glVertexAttrib4iv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4IVPROC GLeeFuncPtr_glVertexAttrib4iv;
  #define glVertexAttrib4iv GLeeFuncPtr_glVertexAttrib4iv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4s
#define GLEE_H_DEFINED_glVertexAttrib4s
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4SPROC GLeeFuncPtr_glVertexAttrib4s;
  #define glVertexAttrib4s GLeeFuncPtr_glVertexAttrib4s
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4sv
#define GLEE_H_DEFINED_glVertexAttrib4sv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4SVPROC GLeeFuncPtr_glVertexAttrib4sv;
  #define glVertexAttrib4sv GLeeFuncPtr_glVertexAttrib4sv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4ubv
#define GLEE_H_DEFINED_glVertexAttrib4ubv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4UBVPROC GLeeFuncPtr_glVertexAttrib4ubv;
  #define glVertexAttrib4ubv GLeeFuncPtr_glVertexAttrib4ubv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4uiv
#define GLEE_H_DEFINED_glVertexAttrib4uiv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4UIVPROC GLeeFuncPtr_glVertexAttrib4uiv;
  #define glVertexAttrib4uiv GLeeFuncPtr_glVertexAttrib4uiv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4usv
#define GLEE_H_DEFINED_glVertexAttrib4usv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4USVPROC GLeeFuncPtr_glVertexAttrib4usv;
  #define glVertexAttrib4usv GLeeFuncPtr_glVertexAttrib4usv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribPointer
#define GLEE_H_DEFINED_glVertexAttribPointer
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBPOINTERPROC GLeeFuncPtr_glVertexAttribPointer;
  #define glVertexAttribPointer GLeeFuncPtr_glVertexAttribPointer
#endif
#endif

/* GL_VERSION_2_1 */

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define __GLEE_GL_VERSION_2_1 1
/* Constants */
#define GL_CURRENT_RASTER_SECONDARY_COLOR                  0x845F
#define GL_PIXEL_PACK_BUFFER                               0x88EB
#define GL_PIXEL_UNPACK_BUFFER                             0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING                       0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING                     0x88EF
#define GL_FLOAT_MAT2x3                                    0x8B65
#define GL_FLOAT_MAT2x4                                    0x8B66
#define GL_FLOAT_MAT3x2                                    0x8B67
#define GL_FLOAT_MAT3x4                                    0x8B68
#define GL_FLOAT_MAT4x2                                    0x8B69
#define GL_FLOAT_MAT4x3                                    0x8B6A
#define GL_SRGB                                            0x8C40
#define GL_SRGB8                                           0x8C41
#define GL_SRGB_ALPHA                                      0x8C42
#define GL_SRGB8_ALPHA8                                    0x8C43
#define GL_SLUMINANCE_ALPHA                                0x8C44
#define GL_SLUMINANCE8_ALPHA8                              0x8C45
#define GL_SLUMINANCE                                      0x8C46
#define GL_SLUMINANCE8                                     0x8C47
#define GL_COMPRESSED_SRGB                                 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA                           0x8C49
#define GL_COMPRESSED_SLUMINANCE                           0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA                     0x8C4B
#ifndef GLEE_H_DEFINED_glUniformMatrix2x3fv
#define GLEE_H_DEFINED_glUniformMatrix2x3fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX2X3FVPROC GLeeFuncPtr_glUniformMatrix2x3fv;
  #define glUniformMatrix2x3fv GLeeFuncPtr_glUniformMatrix2x3fv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix3x2fv
#define GLEE_H_DEFINED_glUniformMatrix3x2fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX3X2FVPROC GLeeFuncPtr_glUniformMatrix3x2fv;
  #define glUniformMatrix3x2fv GLeeFuncPtr_glUniformMatrix3x2fv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix2x4fv
#define GLEE_H_DEFINED_glUniformMatrix2x4fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX2X4FVPROC GLeeFuncPtr_glUniformMatrix2x4fv;
  #define glUniformMatrix2x4fv GLeeFuncPtr_glUniformMatrix2x4fv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix4x2fv
#define GLEE_H_DEFINED_glUniformMatrix4x2fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX4X2FVPROC GLeeFuncPtr_glUniformMatrix4x2fv;
  #define glUniformMatrix4x2fv GLeeFuncPtr_glUniformMatrix4x2fv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix3x4fv
#define GLEE_H_DEFINED_glUniformMatrix3x4fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX3X4FVPROC GLeeFuncPtr_glUniformMatrix3x4fv;
  #define glUniformMatrix3x4fv GLeeFuncPtr_glUniformMatrix3x4fv
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix4x3fv
#define GLEE_H_DEFINED_glUniformMatrix4x3fv
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX4X3FVPROC GLeeFuncPtr_glUniformMatrix4x3fv;
  #define glUniformMatrix4x3fv GLeeFuncPtr_glUniformMatrix4x3fv
#endif
#endif

/* GL_VERSION_3_0 */

#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
#define __GLEE_GL_VERSION_3_0 1
/* Constants */
#define GL_COMPARE_REF_TO_TEXTURE                          GL_COMPARE_R_TO_TEXTURE_ARB
#define GL_CLIP_DISTANCE0                                  GL_CLIP_PLANE0
#define GL_CLIP_DISTANCE1                                  GL_CLIP_PLANE1
#define GL_CLIP_DISTANCE2                                  GL_CLIP_PLANE2
#define GL_CLIP_DISTANCE3                                  GL_CLIP_PLANE3
#define GL_CLIP_DISTANCE4                                  GL_CLIP_PLANE4
#define GL_CLIP_DISTANCE5                                  GL_CLIP_PLANE5
#define GL_MAX_CLIP_DISTANCES                              GL_MAX_CLIP_PLANES
#define GL_MAJOR_VERSION                                   0x821B
#define GL_MINOR_VERSION                                   0x821C
#define GL_NUM_EXTENSIONS                                  0x821D
#define GL_CONTEXT_FLAGS                                   0x821E
#define GL_DEPTH_BUFFER                                    0x8223
#define GL_STENCIL_BUFFER                                  0x8224
#define GL_COMPRESSED_RED                                  0x8225
#define GL_COMPRESSED_RG                                   0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT             0x0001
#define GL_RGBA32F                                         0x8814
#define GL_RGB32F                                          0x8815
#define GL_RGBA16F                                         0x881A
#define GL_RGB16F                                          0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER                     0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS                        0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET                        0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET                        0x8905
#define GL_CLAMP_VERTEX_COLOR                              0x891A
#define GL_CLAMP_FRAGMENT_COLOR                            0x891B
#define GL_CLAMP_READ_COLOR                                0x891C
#define GL_FIXED_ONLY                                      0x891D
#define GL_MAX_VARYING_COMPONENTS                          GL_MAX_VARYING_FLOATS
#define GL_TEXTURE_RED_TYPE                                0x8C10
#define GL_TEXTURE_GREEN_TYPE                              0x8C11
#define GL_TEXTURE_BLUE_TYPE                               0x8C12
#define GL_TEXTURE_ALPHA_TYPE                              0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE                          0x8C14
#define GL_TEXTURE_INTENSITY_TYPE                          0x8C15
#define GL_TEXTURE_DEPTH_TYPE                              0x8C16
#define GL_UNSIGNED_NORMALIZED                             0x8C17
#define GL_TEXTURE_1D_ARRAY                                0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY                          0x8C19
#define GL_TEXTURE_2D_ARRAY                                0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY                          0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY                        0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY                        0x8C1D
#define GL_R11F_G11F_B10F                                  0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV                    0x8C3B
#define GL_RGB9_E5                                         0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV                        0x8C3E
#define GL_TEXTURE_SHARED_SIZE                             0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH           0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE                  0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS      0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS                     0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START                 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                  0x8C85
#define GL_PRIMITIVES_GENERATED                            0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN           0x8C88
#define GL_RASTERIZER_DISCARD                              0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS   0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS         0x8C8B
#define GL_INTERLEAVED_ATTRIBS                             0x8C8C
#define GL_SEPARATE_ATTRIBS                                0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER                       0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING               0x8C8F
#define GL_RGBA32UI                                        0x8D70
#define GL_RGB32UI                                         0x8D71
#define GL_RGBA16UI                                        0x8D76
#define GL_RGB16UI                                         0x8D77
#define GL_RGBA8UI                                         0x8D7C
#define GL_RGB8UI                                          0x8D7D
#define GL_RGBA32I                                         0x8D82
#define GL_RGB32I                                          0x8D83
#define GL_RGBA16I                                         0x8D88
#define GL_RGB16I                                          0x8D89
#define GL_RGBA8I                                          0x8D8E
#define GL_RGB8I                                           0x8D8F
#define GL_RED_INTEGER                                     0x8D94
#define GL_GREEN_INTEGER                                   0x8D95
#define GL_BLUE_INTEGER                                    0x8D96
#define GL_ALPHA_INTEGER                                   0x8D97
#define GL_RGB_INTEGER                                     0x8D98
#define GL_RGBA_INTEGER                                    0x8D99
#define GL_BGR_INTEGER                                     0x8D9A
#define GL_BGRA_INTEGER                                    0x8D9B
#define GL_SAMPLER_1D_ARRAY                                0x8DC0
#define GL_SAMPLER_2D_ARRAY                                0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW                         0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW                         0x8DC4
#define GL_SAMPLER_CUBE_SHADOW                             0x8DC5
#define GL_UNSIGNED_INT_VEC2                               0x8DC6
#define GL_UNSIGNED_INT_VEC3                               0x8DC7
#define GL_UNSIGNED_INT_VEC4                               0x8DC8
#define GL_INT_SAMPLER_1D                                  0x8DC9
#define GL_INT_SAMPLER_2D                                  0x8DCA
#define GL_INT_SAMPLER_3D                                  0x8DCB
#define GL_INT_SAMPLER_CUBE                                0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY                            0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY                            0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D                         0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D                         0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D                         0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE                       0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY                   0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                   0x8DD7
#define GL_QUERY_WAIT                                      0x8E13
#define GL_QUERY_NO_WAIT                                   0x8E14
#define GL_QUERY_BY_REGION_WAIT                            0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT                         0x8E16
#ifndef GLEE_H_DEFINED_glColorMaski
#define GLEE_H_DEFINED_glColorMaski
  typedef void (APIENTRYP GLEEPFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
  GLEE_EXTERN GLEEPFNGLCOLORMASKIPROC GLeeFuncPtr_glColorMaski;
  #define glColorMaski GLeeFuncPtr_glColorMaski
#endif
#ifndef GLEE_H_DEFINED_glGetBooleani_v
#define GLEE_H_DEFINED_glGetBooleani_v
  typedef void (APIENTRYP GLEEPFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean * data);
  GLEE_EXTERN GLEEPFNGLGETBOOLEANI_VPROC GLeeFuncPtr_glGetBooleani_v;
  #define glGetBooleani_v GLeeFuncPtr_glGetBooleani_v
#endif
#ifndef GLEE_H_DEFINED_glGetIntegeri_v
#define GLEE_H_DEFINED_glGetIntegeri_v
  typedef void (APIENTRYP GLEEPFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint * data);
  GLEE_EXTERN GLEEPFNGLGETINTEGERI_VPROC GLeeFuncPtr_glGetIntegeri_v;
  #define glGetIntegeri_v GLeeFuncPtr_glGetIntegeri_v
#endif
#ifndef GLEE_H_DEFINED_glEnablei
#define GLEE_H_DEFINED_glEnablei
  typedef void (APIENTRYP GLEEPFNGLENABLEIPROC) (GLenum target, GLuint index);
  GLEE_EXTERN GLEEPFNGLENABLEIPROC GLeeFuncPtr_glEnablei;
  #define glEnablei GLeeFuncPtr_glEnablei
#endif
#ifndef GLEE_H_DEFINED_glDisablei
#define GLEE_H_DEFINED_glDisablei
  typedef void (APIENTRYP GLEEPFNGLDISABLEIPROC) (GLenum target, GLuint index);
  GLEE_EXTERN GLEEPFNGLDISABLEIPROC GLeeFuncPtr_glDisablei;
  #define glDisablei GLeeFuncPtr_glDisablei
#endif
#ifndef GLEE_H_DEFINED_glIsEnabledi
#define GLEE_H_DEFINED_glIsEnabledi
  typedef GLboolean (APIENTRYP GLEEPFNGLISENABLEDIPROC) (GLenum target, GLuint index);
  GLEE_EXTERN GLEEPFNGLISENABLEDIPROC GLeeFuncPtr_glIsEnabledi;
  #define glIsEnabledi GLeeFuncPtr_glIsEnabledi
#endif
#ifndef GLEE_H_DEFINED_glBeginTransformFeedback
#define GLEE_H_DEFINED_glBeginTransformFeedback
  typedef void (APIENTRYP GLEEPFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
  GLEE_EXTERN GLEEPFNGLBEGINTRANSFORMFEEDBACKPROC GLeeFuncPtr_glBeginTransformFeedback;
  #define glBeginTransformFeedback GLeeFuncPtr_glBeginTransformFeedback
#endif
#ifndef GLEE_H_DEFINED_glEndTransformFeedback
#define GLEE_H_DEFINED_glEndTransformFeedback
  typedef void (APIENTRYP GLEEPFNGLENDTRANSFORMFEEDBACKPROC) ();
  GLEE_EXTERN GLEEPFNGLENDTRANSFORMFEEDBACKPROC GLeeFuncPtr_glEndTransformFeedback;
  #define glEndTransformFeedback GLeeFuncPtr_glEndTransformFeedback
#endif
#ifndef GLEE_H_DEFINED_glBindBufferRange
#define GLEE_H_DEFINED_glBindBufferRange
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERRANGEPROC GLeeFuncPtr_glBindBufferRange;
  #define glBindBufferRange GLeeFuncPtr_glBindBufferRange
#endif
#ifndef GLEE_H_DEFINED_glBindBufferBase
#define GLEE_H_DEFINED_glBindBufferBase
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERBASEPROC GLeeFuncPtr_glBindBufferBase;
  #define glBindBufferBase GLeeFuncPtr_glBindBufferBase
#endif
#ifndef GLEE_H_DEFINED_glTransformFeedbackVaryings
#define GLEE_H_DEFINED_glTransformFeedbackVaryings
  typedef void (APIENTRYP GLEEPFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode);
  GLEE_EXTERN GLEEPFNGLTRANSFORMFEEDBACKVARYINGSPROC GLeeFuncPtr_glTransformFeedbackVaryings;
  #define glTransformFeedbackVaryings GLeeFuncPtr_glTransformFeedbackVaryings
#endif
#ifndef GLEE_H_DEFINED_glGetTransformFeedbackVarying
#define GLEE_H_DEFINED_glGetTransformFeedbackVarying
  typedef void (APIENTRYP GLEEPFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLint * location);
  GLEE_EXTERN GLEEPFNGLGETTRANSFORMFEEDBACKVARYINGPROC GLeeFuncPtr_glGetTransformFeedbackVarying;
  #define glGetTransformFeedbackVarying GLeeFuncPtr_glGetTransformFeedbackVarying
#endif
#ifndef GLEE_H_DEFINED_glClampColor
#define GLEE_H_DEFINED_glClampColor
  typedef void (APIENTRYP GLEEPFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
  GLEE_EXTERN GLEEPFNGLCLAMPCOLORPROC GLeeFuncPtr_glClampColor;
  #define glClampColor GLeeFuncPtr_glClampColor
#endif
#ifndef GLEE_H_DEFINED_glBeginConditionalRender
#define GLEE_H_DEFINED_glBeginConditionalRender
  typedef void (APIENTRYP GLEEPFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
  GLEE_EXTERN GLEEPFNGLBEGINCONDITIONALRENDERPROC GLeeFuncPtr_glBeginConditionalRender;
  #define glBeginConditionalRender GLeeFuncPtr_glBeginConditionalRender
#endif
#ifndef GLEE_H_DEFINED_glEndConditionalRender
#define GLEE_H_DEFINED_glEndConditionalRender
  typedef void (APIENTRYP GLEEPFNGLENDCONDITIONALRENDERPROC) ();
  GLEE_EXTERN GLEEPFNGLENDCONDITIONALRENDERPROC GLeeFuncPtr_glEndConditionalRender;
  #define glEndConditionalRender GLeeFuncPtr_glEndConditionalRender
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI1i
#define GLEE_H_DEFINED_glVertexAttribI1i
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI1IPROC GLeeFuncPtr_glVertexAttribI1i;
  #define glVertexAttribI1i GLeeFuncPtr_glVertexAttribI1i
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2i
#define GLEE_H_DEFINED_glVertexAttribI2i
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2IPROC GLeeFuncPtr_glVertexAttribI2i;
  #define glVertexAttribI2i GLeeFuncPtr_glVertexAttribI2i
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3i
#define GLEE_H_DEFINED_glVertexAttribI3i
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3IPROC GLeeFuncPtr_glVertexAttribI3i;
  #define glVertexAttribI3i GLeeFuncPtr_glVertexAttribI3i
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4i
#define GLEE_H_DEFINED_glVertexAttribI4i
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4IPROC GLeeFuncPtr_glVertexAttribI4i;
  #define glVertexAttribI4i GLeeFuncPtr_glVertexAttribI4i
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI1ui
#define GLEE_H_DEFINED_glVertexAttribI1ui
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI1UIPROC GLeeFuncPtr_glVertexAttribI1ui;
  #define glVertexAttribI1ui GLeeFuncPtr_glVertexAttribI1ui
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2ui
#define GLEE_H_DEFINED_glVertexAttribI2ui
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2UIPROC GLeeFuncPtr_glVertexAttribI2ui;
  #define glVertexAttribI2ui GLeeFuncPtr_glVertexAttribI2ui
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3ui
#define GLEE_H_DEFINED_glVertexAttribI3ui
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3UIPROC GLeeFuncPtr_glVertexAttribI3ui;
  #define glVertexAttribI3ui GLeeFuncPtr_glVertexAttribI3ui
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4ui
#define GLEE_H_DEFINED_glVertexAttribI4ui
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4UIPROC GLeeFuncPtr_glVertexAttribI4ui;
  #define glVertexAttribI4ui GLeeFuncPtr_glVertexAttribI4ui
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI1iv
#define GLEE_H_DEFINED_glVertexAttribI1iv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI1IVPROC GLeeFuncPtr_glVertexAttribI1iv;
  #define glVertexAttribI1iv GLeeFuncPtr_glVertexAttribI1iv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2iv
#define GLEE_H_DEFINED_glVertexAttribI2iv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2IVPROC GLeeFuncPtr_glVertexAttribI2iv;
  #define glVertexAttribI2iv GLeeFuncPtr_glVertexAttribI2iv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3iv
#define GLEE_H_DEFINED_glVertexAttribI3iv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3IVPROC GLeeFuncPtr_glVertexAttribI3iv;
  #define glVertexAttribI3iv GLeeFuncPtr_glVertexAttribI3iv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4iv
#define GLEE_H_DEFINED_glVertexAttribI4iv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4IVPROC GLeeFuncPtr_glVertexAttribI4iv;
  #define glVertexAttribI4iv GLeeFuncPtr_glVertexAttribI4iv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI1uiv
#define GLEE_H_DEFINED_glVertexAttribI1uiv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI1UIVPROC GLeeFuncPtr_glVertexAttribI1uiv;
  #define glVertexAttribI1uiv GLeeFuncPtr_glVertexAttribI1uiv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2uiv
#define GLEE_H_DEFINED_glVertexAttribI2uiv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2UIVPROC GLeeFuncPtr_glVertexAttribI2uiv;
  #define glVertexAttribI2uiv GLeeFuncPtr_glVertexAttribI2uiv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3uiv
#define GLEE_H_DEFINED_glVertexAttribI3uiv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3UIVPROC GLeeFuncPtr_glVertexAttribI3uiv;
  #define glVertexAttribI3uiv GLeeFuncPtr_glVertexAttribI3uiv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4uiv
#define GLEE_H_DEFINED_glVertexAttribI4uiv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4UIVPROC GLeeFuncPtr_glVertexAttribI4uiv;
  #define glVertexAttribI4uiv GLeeFuncPtr_glVertexAttribI4uiv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4bv
#define GLEE_H_DEFINED_glVertexAttribI4bv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4BVPROC GLeeFuncPtr_glVertexAttribI4bv;
  #define glVertexAttribI4bv GLeeFuncPtr_glVertexAttribI4bv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4sv
#define GLEE_H_DEFINED_glVertexAttribI4sv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4SVPROC GLeeFuncPtr_glVertexAttribI4sv;
  #define glVertexAttribI4sv GLeeFuncPtr_glVertexAttribI4sv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4ubv
#define GLEE_H_DEFINED_glVertexAttribI4ubv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4UBVPROC GLeeFuncPtr_glVertexAttribI4ubv;
  #define glVertexAttribI4ubv GLeeFuncPtr_glVertexAttribI4ubv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4usv
#define GLEE_H_DEFINED_glVertexAttribI4usv
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4USVPROC GLeeFuncPtr_glVertexAttribI4usv;
  #define glVertexAttribI4usv GLeeFuncPtr_glVertexAttribI4usv
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribIPointer
#define GLEE_H_DEFINED_glVertexAttribIPointer
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBIPOINTERPROC GLeeFuncPtr_glVertexAttribIPointer;
  #define glVertexAttribIPointer GLeeFuncPtr_glVertexAttribIPointer
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribIiv
#define GLEE_H_DEFINED_glGetVertexAttribIiv
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBIIVPROC GLeeFuncPtr_glGetVertexAttribIiv;
  #define glGetVertexAttribIiv GLeeFuncPtr_glGetVertexAttribIiv
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribIuiv
#define GLEE_H_DEFINED_glGetVertexAttribIuiv
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBIUIVPROC GLeeFuncPtr_glGetVertexAttribIuiv;
  #define glGetVertexAttribIuiv GLeeFuncPtr_glGetVertexAttribIuiv
#endif
#ifndef GLEE_H_DEFINED_glGetUniformuiv
#define GLEE_H_DEFINED_glGetUniformuiv
  typedef void (APIENTRYP GLEEPFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMUIVPROC GLeeFuncPtr_glGetUniformuiv;
  #define glGetUniformuiv GLeeFuncPtr_glGetUniformuiv
#endif
#ifndef GLEE_H_DEFINED_glBindFragDataLocation
#define GLEE_H_DEFINED_glBindFragDataLocation
  typedef void (APIENTRYP GLEEPFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLBINDFRAGDATALOCATIONPROC GLeeFuncPtr_glBindFragDataLocation;
  #define glBindFragDataLocation GLeeFuncPtr_glBindFragDataLocation
#endif
#ifndef GLEE_H_DEFINED_glGetFragDataLocation
#define GLEE_H_DEFINED_glGetFragDataLocation
  typedef GLint (APIENTRYP GLEEPFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETFRAGDATALOCATIONPROC GLeeFuncPtr_glGetFragDataLocation;
  #define glGetFragDataLocation GLeeFuncPtr_glGetFragDataLocation
#endif
#ifndef GLEE_H_DEFINED_glUniform1ui
#define GLEE_H_DEFINED_glUniform1ui
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
  GLEE_EXTERN GLEEPFNGLUNIFORM1UIPROC GLeeFuncPtr_glUniform1ui;
  #define glUniform1ui GLeeFuncPtr_glUniform1ui
#endif
#ifndef GLEE_H_DEFINED_glUniform2ui
#define GLEE_H_DEFINED_glUniform2ui
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
  GLEE_EXTERN GLEEPFNGLUNIFORM2UIPROC GLeeFuncPtr_glUniform2ui;
  #define glUniform2ui GLeeFuncPtr_glUniform2ui
#endif
#ifndef GLEE_H_DEFINED_glUniform3ui
#define GLEE_H_DEFINED_glUniform3ui
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
  GLEE_EXTERN GLEEPFNGLUNIFORM3UIPROC GLeeFuncPtr_glUniform3ui;
  #define glUniform3ui GLeeFuncPtr_glUniform3ui
#endif
#ifndef GLEE_H_DEFINED_glUniform4ui
#define GLEE_H_DEFINED_glUniform4ui
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
  GLEE_EXTERN GLEEPFNGLUNIFORM4UIPROC GLeeFuncPtr_glUniform4ui;
  #define glUniform4ui GLeeFuncPtr_glUniform4ui
#endif
#ifndef GLEE_H_DEFINED_glUniform1uiv
#define GLEE_H_DEFINED_glUniform1uiv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM1UIVPROC GLeeFuncPtr_glUniform1uiv;
  #define glUniform1uiv GLeeFuncPtr_glUniform1uiv
#endif
#ifndef GLEE_H_DEFINED_glUniform2uiv
#define GLEE_H_DEFINED_glUniform2uiv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM2UIVPROC GLeeFuncPtr_glUniform2uiv;
  #define glUniform2uiv GLeeFuncPtr_glUniform2uiv
#endif
#ifndef GLEE_H_DEFINED_glUniform3uiv
#define GLEE_H_DEFINED_glUniform3uiv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM3UIVPROC GLeeFuncPtr_glUniform3uiv;
  #define glUniform3uiv GLeeFuncPtr_glUniform3uiv
#endif
#ifndef GLEE_H_DEFINED_glUniform4uiv
#define GLEE_H_DEFINED_glUniform4uiv
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM4UIVPROC GLeeFuncPtr_glUniform4uiv;
  #define glUniform4uiv GLeeFuncPtr_glUniform4uiv
#endif
#ifndef GLEE_H_DEFINED_glTexParameterIiv
#define GLEE_H_DEFINED_glTexParameterIiv
  typedef void (APIENTRYP GLEEPFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLTEXPARAMETERIIVPROC GLeeFuncPtr_glTexParameterIiv;
  #define glTexParameterIiv GLeeFuncPtr_glTexParameterIiv
#endif
#ifndef GLEE_H_DEFINED_glTexParameterIuiv
#define GLEE_H_DEFINED_glTexParameterIuiv
  typedef void (APIENTRYP GLEEPFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLTEXPARAMETERIUIVPROC GLeeFuncPtr_glTexParameterIuiv;
  #define glTexParameterIuiv GLeeFuncPtr_glTexParameterIuiv
#endif
#ifndef GLEE_H_DEFINED_glGetTexParameterIiv
#define GLEE_H_DEFINED_glGetTexParameterIiv
  typedef void (APIENTRYP GLEEPFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXPARAMETERIIVPROC GLeeFuncPtr_glGetTexParameterIiv;
  #define glGetTexParameterIiv GLeeFuncPtr_glGetTexParameterIiv
#endif
#ifndef GLEE_H_DEFINED_glGetTexParameterIuiv
#define GLEE_H_DEFINED_glGetTexParameterIuiv
  typedef void (APIENTRYP GLEEPFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXPARAMETERIUIVPROC GLeeFuncPtr_glGetTexParameterIuiv;
  #define glGetTexParameterIuiv GLeeFuncPtr_glGetTexParameterIuiv
#endif
#ifndef GLEE_H_DEFINED_glClearBufferiv
#define GLEE_H_DEFINED_glClearBufferiv
  typedef void (APIENTRYP GLEEPFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint * value);
  GLEE_EXTERN GLEEPFNGLCLEARBUFFERIVPROC GLeeFuncPtr_glClearBufferiv;
  #define glClearBufferiv GLeeFuncPtr_glClearBufferiv
#endif
#ifndef GLEE_H_DEFINED_glClearBufferuiv
#define GLEE_H_DEFINED_glClearBufferuiv
  typedef void (APIENTRYP GLEEPFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLCLEARBUFFERUIVPROC GLeeFuncPtr_glClearBufferuiv;
  #define glClearBufferuiv GLeeFuncPtr_glClearBufferuiv
#endif
#ifndef GLEE_H_DEFINED_glClearBufferfv
#define GLEE_H_DEFINED_glClearBufferfv
  typedef void (APIENTRYP GLEEPFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLCLEARBUFFERFVPROC GLeeFuncPtr_glClearBufferfv;
  #define glClearBufferfv GLeeFuncPtr_glClearBufferfv
#endif
#ifndef GLEE_H_DEFINED_glClearBufferfi
#define GLEE_H_DEFINED_glClearBufferfi
  typedef void (APIENTRYP GLEEPFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
  GLEE_EXTERN GLEEPFNGLCLEARBUFFERFIPROC GLeeFuncPtr_glClearBufferfi;
  #define glClearBufferfi GLeeFuncPtr_glClearBufferfi
#endif
#ifndef GLEE_H_DEFINED_glGetStringi
#define GLEE_H_DEFINED_glGetStringi
  typedef const GLubyte * (APIENTRYP GLEEPFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
  GLEE_EXTERN GLEEPFNGLGETSTRINGIPROC GLeeFuncPtr_glGetStringi;
  #define glGetStringi GLeeFuncPtr_glGetStringi
#endif
#endif

/* GL_ARB_multitexture */

#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
#define __GLEE_GL_ARB_multitexture 1
/* Constants */
#define GL_TEXTURE0_ARB                                    0x84C0
#define GL_TEXTURE1_ARB                                    0x84C1
#define GL_TEXTURE2_ARB                                    0x84C2
#define GL_TEXTURE3_ARB                                    0x84C3
#define GL_TEXTURE4_ARB                                    0x84C4
#define GL_TEXTURE5_ARB                                    0x84C5
#define GL_TEXTURE6_ARB                                    0x84C6
#define GL_TEXTURE7_ARB                                    0x84C7
#define GL_TEXTURE8_ARB                                    0x84C8
#define GL_TEXTURE9_ARB                                    0x84C9
#define GL_TEXTURE10_ARB                                   0x84CA
#define GL_TEXTURE11_ARB                                   0x84CB
#define GL_TEXTURE12_ARB                                   0x84CC
#define GL_TEXTURE13_ARB                                   0x84CD
#define GL_TEXTURE14_ARB                                   0x84CE
#define GL_TEXTURE15_ARB                                   0x84CF
#define GL_TEXTURE16_ARB                                   0x84D0
#define GL_TEXTURE17_ARB                                   0x84D1
#define GL_TEXTURE18_ARB                                   0x84D2
#define GL_TEXTURE19_ARB                                   0x84D3
#define GL_TEXTURE20_ARB                                   0x84D4
#define GL_TEXTURE21_ARB                                   0x84D5
#define GL_TEXTURE22_ARB                                   0x84D6
#define GL_TEXTURE23_ARB                                   0x84D7
#define GL_TEXTURE24_ARB                                   0x84D8
#define GL_TEXTURE25_ARB                                   0x84D9
#define GL_TEXTURE26_ARB                                   0x84DA
#define GL_TEXTURE27_ARB                                   0x84DB
#define GL_TEXTURE28_ARB                                   0x84DC
#define GL_TEXTURE29_ARB                                   0x84DD
#define GL_TEXTURE30_ARB                                   0x84DE
#define GL_TEXTURE31_ARB                                   0x84DF
#define GL_ACTIVE_TEXTURE_ARB                              0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB                       0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB                           0x84E2
#ifndef GLEE_H_DEFINED_glActiveTextureARB
#define GLEE_H_DEFINED_glActiveTextureARB
  typedef void (APIENTRYP GLEEPFNGLACTIVETEXTUREARBPROC) (GLenum texture);
  GLEE_EXTERN GLEEPFNGLACTIVETEXTUREARBPROC GLeeFuncPtr_glActiveTextureARB;
  #define glActiveTextureARB GLeeFuncPtr_glActiveTextureARB
#endif
#ifndef GLEE_H_DEFINED_glClientActiveTextureARB
#define GLEE_H_DEFINED_glClientActiveTextureARB
  typedef void (APIENTRYP GLEEPFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum texture);
  GLEE_EXTERN GLEEPFNGLCLIENTACTIVETEXTUREARBPROC GLeeFuncPtr_glClientActiveTextureARB;
  #define glClientActiveTextureARB GLeeFuncPtr_glClientActiveTextureARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1dARB
#define GLEE_H_DEFINED_glMultiTexCoord1dARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1DARBPROC) (GLenum target, GLdouble s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1DARBPROC GLeeFuncPtr_glMultiTexCoord1dARB;
  #define glMultiTexCoord1dARB GLeeFuncPtr_glMultiTexCoord1dARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1dvARB
#define GLEE_H_DEFINED_glMultiTexCoord1dvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1DVARBPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1DVARBPROC GLeeFuncPtr_glMultiTexCoord1dvARB;
  #define glMultiTexCoord1dvARB GLeeFuncPtr_glMultiTexCoord1dvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1fARB
#define GLEE_H_DEFINED_glMultiTexCoord1fARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1FARBPROC) (GLenum target, GLfloat s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1FARBPROC GLeeFuncPtr_glMultiTexCoord1fARB;
  #define glMultiTexCoord1fARB GLeeFuncPtr_glMultiTexCoord1fARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1fvARB
#define GLEE_H_DEFINED_glMultiTexCoord1fvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1FVARBPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1FVARBPROC GLeeFuncPtr_glMultiTexCoord1fvARB;
  #define glMultiTexCoord1fvARB GLeeFuncPtr_glMultiTexCoord1fvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1iARB
#define GLEE_H_DEFINED_glMultiTexCoord1iARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1IARBPROC) (GLenum target, GLint s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1IARBPROC GLeeFuncPtr_glMultiTexCoord1iARB;
  #define glMultiTexCoord1iARB GLeeFuncPtr_glMultiTexCoord1iARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1ivARB
#define GLEE_H_DEFINED_glMultiTexCoord1ivARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1IVARBPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1IVARBPROC GLeeFuncPtr_glMultiTexCoord1ivARB;
  #define glMultiTexCoord1ivARB GLeeFuncPtr_glMultiTexCoord1ivARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1sARB
#define GLEE_H_DEFINED_glMultiTexCoord1sARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1SARBPROC) (GLenum target, GLshort s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1SARBPROC GLeeFuncPtr_glMultiTexCoord1sARB;
  #define glMultiTexCoord1sARB GLeeFuncPtr_glMultiTexCoord1sARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1svARB
#define GLEE_H_DEFINED_glMultiTexCoord1svARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1SVARBPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1SVARBPROC GLeeFuncPtr_glMultiTexCoord1svARB;
  #define glMultiTexCoord1svARB GLeeFuncPtr_glMultiTexCoord1svARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2dARB
#define GLEE_H_DEFINED_glMultiTexCoord2dARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2DARBPROC) (GLenum target, GLdouble s, GLdouble t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2DARBPROC GLeeFuncPtr_glMultiTexCoord2dARB;
  #define glMultiTexCoord2dARB GLeeFuncPtr_glMultiTexCoord2dARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2dvARB
#define GLEE_H_DEFINED_glMultiTexCoord2dvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2DVARBPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2DVARBPROC GLeeFuncPtr_glMultiTexCoord2dvARB;
  #define glMultiTexCoord2dvARB GLeeFuncPtr_glMultiTexCoord2dvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2fARB
#define GLEE_H_DEFINED_glMultiTexCoord2fARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2FARBPROC) (GLenum target, GLfloat s, GLfloat t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2FARBPROC GLeeFuncPtr_glMultiTexCoord2fARB;
  #define glMultiTexCoord2fARB GLeeFuncPtr_glMultiTexCoord2fARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2fvARB
#define GLEE_H_DEFINED_glMultiTexCoord2fvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2FVARBPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2FVARBPROC GLeeFuncPtr_glMultiTexCoord2fvARB;
  #define glMultiTexCoord2fvARB GLeeFuncPtr_glMultiTexCoord2fvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2iARB
#define GLEE_H_DEFINED_glMultiTexCoord2iARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2IARBPROC) (GLenum target, GLint s, GLint t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2IARBPROC GLeeFuncPtr_glMultiTexCoord2iARB;
  #define glMultiTexCoord2iARB GLeeFuncPtr_glMultiTexCoord2iARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2ivARB
#define GLEE_H_DEFINED_glMultiTexCoord2ivARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2IVARBPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2IVARBPROC GLeeFuncPtr_glMultiTexCoord2ivARB;
  #define glMultiTexCoord2ivARB GLeeFuncPtr_glMultiTexCoord2ivARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2sARB
#define GLEE_H_DEFINED_glMultiTexCoord2sARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2SARBPROC) (GLenum target, GLshort s, GLshort t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2SARBPROC GLeeFuncPtr_glMultiTexCoord2sARB;
  #define glMultiTexCoord2sARB GLeeFuncPtr_glMultiTexCoord2sARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2svARB
#define GLEE_H_DEFINED_glMultiTexCoord2svARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2SVARBPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2SVARBPROC GLeeFuncPtr_glMultiTexCoord2svARB;
  #define glMultiTexCoord2svARB GLeeFuncPtr_glMultiTexCoord2svARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3dARB
#define GLEE_H_DEFINED_glMultiTexCoord3dARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3DARBPROC GLeeFuncPtr_glMultiTexCoord3dARB;
  #define glMultiTexCoord3dARB GLeeFuncPtr_glMultiTexCoord3dARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3dvARB
#define GLEE_H_DEFINED_glMultiTexCoord3dvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3DVARBPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3DVARBPROC GLeeFuncPtr_glMultiTexCoord3dvARB;
  #define glMultiTexCoord3dvARB GLeeFuncPtr_glMultiTexCoord3dvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3fARB
#define GLEE_H_DEFINED_glMultiTexCoord3fARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3FARBPROC GLeeFuncPtr_glMultiTexCoord3fARB;
  #define glMultiTexCoord3fARB GLeeFuncPtr_glMultiTexCoord3fARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3fvARB
#define GLEE_H_DEFINED_glMultiTexCoord3fvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3FVARBPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3FVARBPROC GLeeFuncPtr_glMultiTexCoord3fvARB;
  #define glMultiTexCoord3fvARB GLeeFuncPtr_glMultiTexCoord3fvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3iARB
#define GLEE_H_DEFINED_glMultiTexCoord3iARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3IARBPROC) (GLenum target, GLint s, GLint t, GLint r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3IARBPROC GLeeFuncPtr_glMultiTexCoord3iARB;
  #define glMultiTexCoord3iARB GLeeFuncPtr_glMultiTexCoord3iARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3ivARB
#define GLEE_H_DEFINED_glMultiTexCoord3ivARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3IVARBPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3IVARBPROC GLeeFuncPtr_glMultiTexCoord3ivARB;
  #define glMultiTexCoord3ivARB GLeeFuncPtr_glMultiTexCoord3ivARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3sARB
#define GLEE_H_DEFINED_glMultiTexCoord3sARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3SARBPROC GLeeFuncPtr_glMultiTexCoord3sARB;
  #define glMultiTexCoord3sARB GLeeFuncPtr_glMultiTexCoord3sARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3svARB
#define GLEE_H_DEFINED_glMultiTexCoord3svARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3SVARBPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3SVARBPROC GLeeFuncPtr_glMultiTexCoord3svARB;
  #define glMultiTexCoord3svARB GLeeFuncPtr_glMultiTexCoord3svARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4dARB
#define GLEE_H_DEFINED_glMultiTexCoord4dARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4DARBPROC GLeeFuncPtr_glMultiTexCoord4dARB;
  #define glMultiTexCoord4dARB GLeeFuncPtr_glMultiTexCoord4dARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4dvARB
#define GLEE_H_DEFINED_glMultiTexCoord4dvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4DVARBPROC) (GLenum target, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4DVARBPROC GLeeFuncPtr_glMultiTexCoord4dvARB;
  #define glMultiTexCoord4dvARB GLeeFuncPtr_glMultiTexCoord4dvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4fARB
#define GLEE_H_DEFINED_glMultiTexCoord4fARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4FARBPROC GLeeFuncPtr_glMultiTexCoord4fARB;
  #define glMultiTexCoord4fARB GLeeFuncPtr_glMultiTexCoord4fARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4fvARB
#define GLEE_H_DEFINED_glMultiTexCoord4fvARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4FVARBPROC) (GLenum target, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4FVARBPROC GLeeFuncPtr_glMultiTexCoord4fvARB;
  #define glMultiTexCoord4fvARB GLeeFuncPtr_glMultiTexCoord4fvARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4iARB
#define GLEE_H_DEFINED_glMultiTexCoord4iARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4IARBPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4IARBPROC GLeeFuncPtr_glMultiTexCoord4iARB;
  #define glMultiTexCoord4iARB GLeeFuncPtr_glMultiTexCoord4iARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4ivARB
#define GLEE_H_DEFINED_glMultiTexCoord4ivARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4IVARBPROC) (GLenum target, const GLint * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4IVARBPROC GLeeFuncPtr_glMultiTexCoord4ivARB;
  #define glMultiTexCoord4ivARB GLeeFuncPtr_glMultiTexCoord4ivARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4sARB
#define GLEE_H_DEFINED_glMultiTexCoord4sARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4SARBPROC GLeeFuncPtr_glMultiTexCoord4sARB;
  #define glMultiTexCoord4sARB GLeeFuncPtr_glMultiTexCoord4sARB
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4svARB
#define GLEE_H_DEFINED_glMultiTexCoord4svARB
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4SVARBPROC) (GLenum target, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4SVARBPROC GLeeFuncPtr_glMultiTexCoord4svARB;
  #define glMultiTexCoord4svARB GLeeFuncPtr_glMultiTexCoord4svARB
#endif
#endif

/* GL_ARB_transpose_matrix */

#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
#define __GLEE_GL_ARB_transpose_matrix 1
/* Constants */
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB                  0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB                 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB                    0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB                      0x84E6
#ifndef GLEE_H_DEFINED_glLoadTransposeMatrixfARB
#define GLEE_H_DEFINED_glLoadTransposeMatrixfARB
  typedef void (APIENTRYP GLEEPFNGLLOADTRANSPOSEMATRIXFARBPROC) (const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLLOADTRANSPOSEMATRIXFARBPROC GLeeFuncPtr_glLoadTransposeMatrixfARB;
  #define glLoadTransposeMatrixfARB GLeeFuncPtr_glLoadTransposeMatrixfARB
#endif
#ifndef GLEE_H_DEFINED_glLoadTransposeMatrixdARB
#define GLEE_H_DEFINED_glLoadTransposeMatrixdARB
  typedef void (APIENTRYP GLEEPFNGLLOADTRANSPOSEMATRIXDARBPROC) (const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLLOADTRANSPOSEMATRIXDARBPROC GLeeFuncPtr_glLoadTransposeMatrixdARB;
  #define glLoadTransposeMatrixdARB GLeeFuncPtr_glLoadTransposeMatrixdARB
#endif
#ifndef GLEE_H_DEFINED_glMultTransposeMatrixfARB
#define GLEE_H_DEFINED_glMultTransposeMatrixfARB
  typedef void (APIENTRYP GLEEPFNGLMULTTRANSPOSEMATRIXFARBPROC) (const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLMULTTRANSPOSEMATRIXFARBPROC GLeeFuncPtr_glMultTransposeMatrixfARB;
  #define glMultTransposeMatrixfARB GLeeFuncPtr_glMultTransposeMatrixfARB
#endif
#ifndef GLEE_H_DEFINED_glMultTransposeMatrixdARB
#define GLEE_H_DEFINED_glMultTransposeMatrixdARB
  typedef void (APIENTRYP GLEEPFNGLMULTTRANSPOSEMATRIXDARBPROC) (const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLMULTTRANSPOSEMATRIXDARBPROC GLeeFuncPtr_glMultTransposeMatrixdARB;
  #define glMultTransposeMatrixdARB GLeeFuncPtr_glMultTransposeMatrixdARB
#endif
#endif

/* GL_ARB_multisample */

#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
#define __GLEE_GL_ARB_multisample 1
/* Constants */
#define GL_MULTISAMPLE_ARB                                 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB                    0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB                         0x809F
#define GL_SAMPLE_COVERAGE_ARB                             0x80A0
#define GL_SAMPLE_BUFFERS_ARB                              0x80A8
#define GL_SAMPLES_ARB                                     0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB                       0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB                      0x80AB
#define GL_MULTISAMPLE_BIT_ARB                             0x20000000
#ifndef GLEE_H_DEFINED_glSampleCoverageARB
#define GLEE_H_DEFINED_glSampleCoverageARB
  typedef void (APIENTRYP GLEEPFNGLSAMPLECOVERAGEARBPROC) (GLclampf value, GLboolean invert);
  GLEE_EXTERN GLEEPFNGLSAMPLECOVERAGEARBPROC GLeeFuncPtr_glSampleCoverageARB;
  #define glSampleCoverageARB GLeeFuncPtr_glSampleCoverageARB
#endif
#endif

/* GL_ARB_texture_env_add */

#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add 1
#define __GLEE_GL_ARB_texture_env_add 1
/* Constants */
#endif

/* GL_ARB_texture_cube_map */

#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map 1
#define __GLEE_GL_ARB_texture_cube_map 1
/* Constants */
#define GL_NORMAL_MAP_ARB                                  0x8511
#define GL_REFLECTION_MAP_ARB                              0x8512
#define GL_TEXTURE_CUBE_MAP_ARB                            0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB                    0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB                      0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB                   0x851C
#endif

/* GL_ARB_texture_compression */

#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
#define __GLEE_GL_ARB_texture_compression 1
/* Constants */
#define GL_COMPRESSED_ALPHA_ARB                            0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB                        0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB                  0x84EB
#define GL_COMPRESSED_INTENSITY_ARB                        0x84EC
#define GL_COMPRESSED_RGB_ARB                              0x84ED
#define GL_COMPRESSED_RGBA_ARB                             0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB                    0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB               0x86A0
#define GL_TEXTURE_COMPRESSED_ARB                          0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB              0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB                  0x86A3
#ifndef GLEE_H_DEFINED_glCompressedTexImage3DARB
#define GLEE_H_DEFINED_glCompressedTexImage3DARB
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXIMAGE3DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXIMAGE3DARBPROC GLeeFuncPtr_glCompressedTexImage3DARB;
  #define glCompressedTexImage3DARB GLeeFuncPtr_glCompressedTexImage3DARB
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexImage2DARB
#define GLEE_H_DEFINED_glCompressedTexImage2DARB
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXIMAGE2DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXIMAGE2DARBPROC GLeeFuncPtr_glCompressedTexImage2DARB;
  #define glCompressedTexImage2DARB GLeeFuncPtr_glCompressedTexImage2DARB
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexImage1DARB
#define GLEE_H_DEFINED_glCompressedTexImage1DARB
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXIMAGE1DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXIMAGE1DARBPROC GLeeFuncPtr_glCompressedTexImage1DARB;
  #define glCompressedTexImage1DARB GLeeFuncPtr_glCompressedTexImage1DARB
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexSubImage3DARB
#define GLEE_H_DEFINED_glCompressedTexSubImage3DARB
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC GLeeFuncPtr_glCompressedTexSubImage3DARB;
  #define glCompressedTexSubImage3DARB GLeeFuncPtr_glCompressedTexSubImage3DARB
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexSubImage2DARB
#define GLEE_H_DEFINED_glCompressedTexSubImage2DARB
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC GLeeFuncPtr_glCompressedTexSubImage2DARB;
  #define glCompressedTexSubImage2DARB GLeeFuncPtr_glCompressedTexSubImage2DARB
#endif
#ifndef GLEE_H_DEFINED_glCompressedTexSubImage1DARB
#define GLEE_H_DEFINED_glCompressedTexSubImage1DARB
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC GLeeFuncPtr_glCompressedTexSubImage1DARB;
  #define glCompressedTexSubImage1DARB GLeeFuncPtr_glCompressedTexSubImage1DARB
#endif
#ifndef GLEE_H_DEFINED_glGetCompressedTexImageARB
#define GLEE_H_DEFINED_glGetCompressedTexImageARB
  typedef void (APIENTRYP GLEEPFNGLGETCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint level, GLvoid * img);
  GLEE_EXTERN GLEEPFNGLGETCOMPRESSEDTEXIMAGEARBPROC GLeeFuncPtr_glGetCompressedTexImageARB;
  #define glGetCompressedTexImageARB GLeeFuncPtr_glGetCompressedTexImageARB
#endif
#endif

/* GL_ARB_texture_border_clamp */

#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1
#define __GLEE_GL_ARB_texture_border_clamp 1
/* Constants */
#define GL_CLAMP_TO_BORDER_ARB                             0x812D
#endif

/* GL_ARB_point_parameters */

#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
#define __GLEE_GL_ARB_point_parameters 1
/* Constants */
#define GL_POINT_SIZE_MIN_ARB                              0x8126
#define GL_POINT_SIZE_MAX_ARB                              0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB                   0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB                  0x8129
#ifndef GLEE_H_DEFINED_glPointParameterfARB
#define GLEE_H_DEFINED_glPointParameterfARB
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFARBPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFARBPROC GLeeFuncPtr_glPointParameterfARB;
  #define glPointParameterfARB GLeeFuncPtr_glPointParameterfARB
#endif
#ifndef GLEE_H_DEFINED_glPointParameterfvARB
#define GLEE_H_DEFINED_glPointParameterfvARB
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFVARBPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFVARBPROC GLeeFuncPtr_glPointParameterfvARB;
  #define glPointParameterfvARB GLeeFuncPtr_glPointParameterfvARB
#endif
#endif

/* GL_ARB_vertex_blend */

#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend 1
#define __GLEE_GL_ARB_vertex_blend 1
/* Constants */
#define GL_MAX_VERTEX_UNITS_ARB                            0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB                         0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB                            0x86A6
#define GL_VERTEX_BLEND_ARB                                0x86A7
#define GL_CURRENT_WEIGHT_ARB                              0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB                           0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB                         0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB                           0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB                        0x86AC
#define GL_WEIGHT_ARRAY_ARB                                0x86AD
#define GL_MODELVIEW0_ARB                                  0x1700
#define GL_MODELVIEW1_ARB                                  0x850A
#define GL_MODELVIEW2_ARB                                  0x8722
#define GL_MODELVIEW3_ARB                                  0x8723
#define GL_MODELVIEW4_ARB                                  0x8724
#define GL_MODELVIEW5_ARB                                  0x8725
#define GL_MODELVIEW6_ARB                                  0x8726
#define GL_MODELVIEW7_ARB                                  0x8727
#define GL_MODELVIEW8_ARB                                  0x8728
#define GL_MODELVIEW9_ARB                                  0x8729
#define GL_MODELVIEW10_ARB                                 0x872A
#define GL_MODELVIEW11_ARB                                 0x872B
#define GL_MODELVIEW12_ARB                                 0x872C
#define GL_MODELVIEW13_ARB                                 0x872D
#define GL_MODELVIEW14_ARB                                 0x872E
#define GL_MODELVIEW15_ARB                                 0x872F
#define GL_MODELVIEW16_ARB                                 0x8730
#define GL_MODELVIEW17_ARB                                 0x8731
#define GL_MODELVIEW18_ARB                                 0x8732
#define GL_MODELVIEW19_ARB                                 0x8733
#define GL_MODELVIEW20_ARB                                 0x8734
#define GL_MODELVIEW21_ARB                                 0x8735
#define GL_MODELVIEW22_ARB                                 0x8736
#define GL_MODELVIEW23_ARB                                 0x8737
#define GL_MODELVIEW24_ARB                                 0x8738
#define GL_MODELVIEW25_ARB                                 0x8739
#define GL_MODELVIEW26_ARB                                 0x873A
#define GL_MODELVIEW27_ARB                                 0x873B
#define GL_MODELVIEW28_ARB                                 0x873C
#define GL_MODELVIEW29_ARB                                 0x873D
#define GL_MODELVIEW30_ARB                                 0x873E
#define GL_MODELVIEW31_ARB                                 0x873F
#ifndef GLEE_H_DEFINED_glWeightbvARB
#define GLEE_H_DEFINED_glWeightbvARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTBVARBPROC) (GLint size, const GLbyte * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTBVARBPROC GLeeFuncPtr_glWeightbvARB;
  #define glWeightbvARB GLeeFuncPtr_glWeightbvARB
#endif
#ifndef GLEE_H_DEFINED_glWeightsvARB
#define GLEE_H_DEFINED_glWeightsvARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTSVARBPROC) (GLint size, const GLshort * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTSVARBPROC GLeeFuncPtr_glWeightsvARB;
  #define glWeightsvARB GLeeFuncPtr_glWeightsvARB
#endif
#ifndef GLEE_H_DEFINED_glWeightivARB
#define GLEE_H_DEFINED_glWeightivARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTIVARBPROC) (GLint size, const GLint * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTIVARBPROC GLeeFuncPtr_glWeightivARB;
  #define glWeightivARB GLeeFuncPtr_glWeightivARB
#endif
#ifndef GLEE_H_DEFINED_glWeightfvARB
#define GLEE_H_DEFINED_glWeightfvARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTFVARBPROC) (GLint size, const GLfloat * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTFVARBPROC GLeeFuncPtr_glWeightfvARB;
  #define glWeightfvARB GLeeFuncPtr_glWeightfvARB
#endif
#ifndef GLEE_H_DEFINED_glWeightdvARB
#define GLEE_H_DEFINED_glWeightdvARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTDVARBPROC) (GLint size, const GLdouble * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTDVARBPROC GLeeFuncPtr_glWeightdvARB;
  #define glWeightdvARB GLeeFuncPtr_glWeightdvARB
#endif
#ifndef GLEE_H_DEFINED_glWeightubvARB
#define GLEE_H_DEFINED_glWeightubvARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTUBVARBPROC) (GLint size, const GLubyte * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTUBVARBPROC GLeeFuncPtr_glWeightubvARB;
  #define glWeightubvARB GLeeFuncPtr_glWeightubvARB
#endif
#ifndef GLEE_H_DEFINED_glWeightusvARB
#define GLEE_H_DEFINED_glWeightusvARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTUSVARBPROC) (GLint size, const GLushort * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTUSVARBPROC GLeeFuncPtr_glWeightusvARB;
  #define glWeightusvARB GLeeFuncPtr_glWeightusvARB
#endif
#ifndef GLEE_H_DEFINED_glWeightuivARB
#define GLEE_H_DEFINED_glWeightuivARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTUIVARBPROC) (GLint size, const GLuint * weights);
  GLEE_EXTERN GLEEPFNGLWEIGHTUIVARBPROC GLeeFuncPtr_glWeightuivARB;
  #define glWeightuivARB GLeeFuncPtr_glWeightuivARB
#endif
#ifndef GLEE_H_DEFINED_glWeightPointerARB
#define GLEE_H_DEFINED_glWeightPointerARB
  typedef void (APIENTRYP GLEEPFNGLWEIGHTPOINTERARBPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLWEIGHTPOINTERARBPROC GLeeFuncPtr_glWeightPointerARB;
  #define glWeightPointerARB GLeeFuncPtr_glWeightPointerARB
#endif
#ifndef GLEE_H_DEFINED_glVertexBlendARB
#define GLEE_H_DEFINED_glVertexBlendARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXBLENDARBPROC) (GLint count);
  GLEE_EXTERN GLEEPFNGLVERTEXBLENDARBPROC GLeeFuncPtr_glVertexBlendARB;
  #define glVertexBlendARB GLeeFuncPtr_glVertexBlendARB
#endif
#endif

/* GL_ARB_matrix_palette */

#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette 1
#define __GLEE_GL_ARB_matrix_palette 1
/* Constants */
#define GL_MATRIX_PALETTE_ARB                              0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB              0x8841
#define GL_MAX_PALETTE_MATRICES_ARB                        0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB                      0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB                          0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB                        0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB                     0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB                     0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB                   0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB                  0x8849
#ifndef GLEE_H_DEFINED_glCurrentPaletteMatrixARB
#define GLEE_H_DEFINED_glCurrentPaletteMatrixARB
  typedef void (APIENTRYP GLEEPFNGLCURRENTPALETTEMATRIXARBPROC) (GLint index);
  GLEE_EXTERN GLEEPFNGLCURRENTPALETTEMATRIXARBPROC GLeeFuncPtr_glCurrentPaletteMatrixARB;
  #define glCurrentPaletteMatrixARB GLeeFuncPtr_glCurrentPaletteMatrixARB
#endif
#ifndef GLEE_H_DEFINED_glMatrixIndexubvARB
#define GLEE_H_DEFINED_glMatrixIndexubvARB
  typedef void (APIENTRYP GLEEPFNGLMATRIXINDEXUBVARBPROC) (GLint size, const GLubyte * indices);
  GLEE_EXTERN GLEEPFNGLMATRIXINDEXUBVARBPROC GLeeFuncPtr_glMatrixIndexubvARB;
  #define glMatrixIndexubvARB GLeeFuncPtr_glMatrixIndexubvARB
#endif
#ifndef GLEE_H_DEFINED_glMatrixIndexusvARB
#define GLEE_H_DEFINED_glMatrixIndexusvARB
  typedef void (APIENTRYP GLEEPFNGLMATRIXINDEXUSVARBPROC) (GLint size, const GLushort * indices);
  GLEE_EXTERN GLEEPFNGLMATRIXINDEXUSVARBPROC GLeeFuncPtr_glMatrixIndexusvARB;
  #define glMatrixIndexusvARB GLeeFuncPtr_glMatrixIndexusvARB
#endif
#ifndef GLEE_H_DEFINED_glMatrixIndexuivARB
#define GLEE_H_DEFINED_glMatrixIndexuivARB
  typedef void (APIENTRYP GLEEPFNGLMATRIXINDEXUIVARBPROC) (GLint size, const GLuint * indices);
  GLEE_EXTERN GLEEPFNGLMATRIXINDEXUIVARBPROC GLeeFuncPtr_glMatrixIndexuivARB;
  #define glMatrixIndexuivARB GLeeFuncPtr_glMatrixIndexuivARB
#endif
#ifndef GLEE_H_DEFINED_glMatrixIndexPointerARB
#define GLEE_H_DEFINED_glMatrixIndexPointerARB
  typedef void (APIENTRYP GLEEPFNGLMATRIXINDEXPOINTERARBPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLMATRIXINDEXPOINTERARBPROC GLeeFuncPtr_glMatrixIndexPointerARB;
  #define glMatrixIndexPointerARB GLeeFuncPtr_glMatrixIndexPointerARB
#endif
#endif

/* GL_ARB_texture_env_combine */

#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine 1
#define __GLEE_GL_ARB_texture_env_combine 1
/* Constants */
#define GL_COMBINE_ARB                                     0x8570
#define GL_COMBINE_RGB_ARB                                 0x8571
#define GL_COMBINE_ALPHA_ARB                               0x8572
#define GL_SOURCE0_RGB_ARB                                 0x8580
#define GL_SOURCE1_RGB_ARB                                 0x8581
#define GL_SOURCE2_RGB_ARB                                 0x8582
#define GL_SOURCE0_ALPHA_ARB                               0x8588
#define GL_SOURCE1_ALPHA_ARB                               0x8589
#define GL_SOURCE2_ALPHA_ARB                               0x858A
#define GL_OPERAND0_RGB_ARB                                0x8590
#define GL_OPERAND1_RGB_ARB                                0x8591
#define GL_OPERAND2_RGB_ARB                                0x8592
#define GL_OPERAND0_ALPHA_ARB                              0x8598
#define GL_OPERAND1_ALPHA_ARB                              0x8599
#define GL_OPERAND2_ALPHA_ARB                              0x859A
#define GL_RGB_SCALE_ARB                                   0x8573
#define GL_ADD_SIGNED_ARB                                  0x8574
#define GL_INTERPOLATE_ARB                                 0x8575
#define GL_SUBTRACT_ARB                                    0x84E7
#define GL_CONSTANT_ARB                                    0x8576
#define GL_PRIMARY_COLOR_ARB                               0x8577
#define GL_PREVIOUS_ARB                                    0x8578
#endif

/* GL_ARB_texture_env_crossbar */

#ifndef GL_ARB_texture_env_crossbar
#define GL_ARB_texture_env_crossbar 1
#define __GLEE_GL_ARB_texture_env_crossbar 1
/* Constants */
#endif

/* GL_ARB_texture_env_dot3 */

#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3 1
#define __GLEE_GL_ARB_texture_env_dot3 1
/* Constants */
#define GL_DOT3_RGB_ARB                                    0x86AE
#define GL_DOT3_RGBA_ARB                                   0x86AF
#endif

/* GL_ARB_texture_mirrored_repeat */

#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1
#define __GLEE_GL_ARB_texture_mirrored_repeat 1
/* Constants */
#define GL_MIRRORED_REPEAT_ARB                             0x8370
#endif

/* GL_ARB_depth_texture */

#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture 1
#define __GLEE_GL_ARB_depth_texture 1
/* Constants */
#define GL_DEPTH_COMPONENT16_ARB                           0x81A5
#define GL_DEPTH_COMPONENT24_ARB                           0x81A6
#define GL_DEPTH_COMPONENT32_ARB                           0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB                          0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB                          0x884B
#endif

/* GL_ARB_shadow */

#ifndef GL_ARB_shadow
#define GL_ARB_shadow 1
#define __GLEE_GL_ARB_shadow 1
/* Constants */
#define GL_TEXTURE_COMPARE_MODE_ARB                        0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB                        0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB                        0x884E
#endif

/* GL_ARB_shadow_ambient */

#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient 1
#define __GLEE_GL_ARB_shadow_ambient 1
/* Constants */
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB                  0x80BF
#endif

/* GL_ARB_window_pos */

#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
#define __GLEE_GL_ARB_window_pos 1
/* Constants */
#ifndef GLEE_H_DEFINED_glWindowPos2dARB
#define GLEE_H_DEFINED_glWindowPos2dARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2DARBPROC) (GLdouble x, GLdouble y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2DARBPROC GLeeFuncPtr_glWindowPos2dARB;
  #define glWindowPos2dARB GLeeFuncPtr_glWindowPos2dARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2dvARB
#define GLEE_H_DEFINED_glWindowPos2dvARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2DVARBPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2DVARBPROC GLeeFuncPtr_glWindowPos2dvARB;
  #define glWindowPos2dvARB GLeeFuncPtr_glWindowPos2dvARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2fARB
#define GLEE_H_DEFINED_glWindowPos2fARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2FARBPROC) (GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2FARBPROC GLeeFuncPtr_glWindowPos2fARB;
  #define glWindowPos2fARB GLeeFuncPtr_glWindowPos2fARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2fvARB
#define GLEE_H_DEFINED_glWindowPos2fvARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2FVARBPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2FVARBPROC GLeeFuncPtr_glWindowPos2fvARB;
  #define glWindowPos2fvARB GLeeFuncPtr_glWindowPos2fvARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2iARB
#define GLEE_H_DEFINED_glWindowPos2iARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2IARBPROC) (GLint x, GLint y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2IARBPROC GLeeFuncPtr_glWindowPos2iARB;
  #define glWindowPos2iARB GLeeFuncPtr_glWindowPos2iARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2ivARB
#define GLEE_H_DEFINED_glWindowPos2ivARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2IVARBPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2IVARBPROC GLeeFuncPtr_glWindowPos2ivARB;
  #define glWindowPos2ivARB GLeeFuncPtr_glWindowPos2ivARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2sARB
#define GLEE_H_DEFINED_glWindowPos2sARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2SARBPROC) (GLshort x, GLshort y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2SARBPROC GLeeFuncPtr_glWindowPos2sARB;
  #define glWindowPos2sARB GLeeFuncPtr_glWindowPos2sARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2svARB
#define GLEE_H_DEFINED_glWindowPos2svARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2SVARBPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2SVARBPROC GLeeFuncPtr_glWindowPos2svARB;
  #define glWindowPos2svARB GLeeFuncPtr_glWindowPos2svARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3dARB
#define GLEE_H_DEFINED_glWindowPos3dARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3DARBPROC) (GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3DARBPROC GLeeFuncPtr_glWindowPos3dARB;
  #define glWindowPos3dARB GLeeFuncPtr_glWindowPos3dARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3dvARB
#define GLEE_H_DEFINED_glWindowPos3dvARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3DVARBPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3DVARBPROC GLeeFuncPtr_glWindowPos3dvARB;
  #define glWindowPos3dvARB GLeeFuncPtr_glWindowPos3dvARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3fARB
#define GLEE_H_DEFINED_glWindowPos3fARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3FARBPROC) (GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3FARBPROC GLeeFuncPtr_glWindowPos3fARB;
  #define glWindowPos3fARB GLeeFuncPtr_glWindowPos3fARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3fvARB
#define GLEE_H_DEFINED_glWindowPos3fvARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3FVARBPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3FVARBPROC GLeeFuncPtr_glWindowPos3fvARB;
  #define glWindowPos3fvARB GLeeFuncPtr_glWindowPos3fvARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3iARB
#define GLEE_H_DEFINED_glWindowPos3iARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3IARBPROC) (GLint x, GLint y, GLint z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3IARBPROC GLeeFuncPtr_glWindowPos3iARB;
  #define glWindowPos3iARB GLeeFuncPtr_glWindowPos3iARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3ivARB
#define GLEE_H_DEFINED_glWindowPos3ivARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3IVARBPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3IVARBPROC GLeeFuncPtr_glWindowPos3ivARB;
  #define glWindowPos3ivARB GLeeFuncPtr_glWindowPos3ivARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3sARB
#define GLEE_H_DEFINED_glWindowPos3sARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3SARBPROC) (GLshort x, GLshort y, GLshort z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3SARBPROC GLeeFuncPtr_glWindowPos3sARB;
  #define glWindowPos3sARB GLeeFuncPtr_glWindowPos3sARB
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3svARB
#define GLEE_H_DEFINED_glWindowPos3svARB
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3SVARBPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3SVARBPROC GLeeFuncPtr_glWindowPos3svARB;
  #define glWindowPos3svARB GLeeFuncPtr_glWindowPos3svARB
#endif
#endif

/* GL_ARB_vertex_program */

#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
#define __GLEE_GL_ARB_vertex_program 1
/* Constants */
#define GL_COLOR_SUM_ARB                                   0x8458
#define GL_VERTEX_PROGRAM_ARB                              0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB                 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                    0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB                  0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                    0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB                       0x8626
#define GL_PROGRAM_LENGTH_ARB                              0x8627
#define GL_PROGRAM_STRING_ARB                              0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB              0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB                        0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB                  0x8640
#define GL_CURRENT_MATRIX_ARB                              0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB                   0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB                     0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB                 0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB                      0x864B
#define GL_PROGRAM_BINDING_ARB                             0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB                          0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB              0x886A
#define GL_PROGRAM_ERROR_STRING_ARB                        0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB                        0x8875
#define GL_PROGRAM_FORMAT_ARB                              0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB                        0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB                    0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB                 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB             0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB                         0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB                     0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB                  0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB              0x88A7
#define GL_PROGRAM_PARAMETERS_ARB                          0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB                      0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB                   0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB               0x88AB
#define GL_PROGRAM_ATTRIBS_ARB                             0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB                         0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB                      0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB                  0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB                   0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB               0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB            0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB        0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB                0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB                  0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB                 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB                    0x88B7
#define GL_MATRIX0_ARB                                     0x88C0
#define GL_MATRIX1_ARB                                     0x88C1
#define GL_MATRIX2_ARB                                     0x88C2
#define GL_MATRIX3_ARB                                     0x88C3
#define GL_MATRIX4_ARB                                     0x88C4
#define GL_MATRIX5_ARB                                     0x88C5
#define GL_MATRIX6_ARB                                     0x88C6
#define GL_MATRIX7_ARB                                     0x88C7
#define GL_MATRIX8_ARB                                     0x88C8
#define GL_MATRIX9_ARB                                     0x88C9
#define GL_MATRIX10_ARB                                    0x88CA
#define GL_MATRIX11_ARB                                    0x88CB
#define GL_MATRIX12_ARB                                    0x88CC
#define GL_MATRIX13_ARB                                    0x88CD
#define GL_MATRIX14_ARB                                    0x88CE
#define GL_MATRIX15_ARB                                    0x88CF
#define GL_MATRIX16_ARB                                    0x88D0
#define GL_MATRIX17_ARB                                    0x88D1
#define GL_MATRIX18_ARB                                    0x88D2
#define GL_MATRIX19_ARB                                    0x88D3
#define GL_MATRIX20_ARB                                    0x88D4
#define GL_MATRIX21_ARB                                    0x88D5
#define GL_MATRIX22_ARB                                    0x88D6
#define GL_MATRIX23_ARB                                    0x88D7
#define GL_MATRIX24_ARB                                    0x88D8
#define GL_MATRIX25_ARB                                    0x88D9
#define GL_MATRIX26_ARB                                    0x88DA
#define GL_MATRIX27_ARB                                    0x88DB
#define GL_MATRIX28_ARB                                    0x88DC
#define GL_MATRIX29_ARB                                    0x88DD
#define GL_MATRIX30_ARB                                    0x88DE
#define GL_MATRIX31_ARB                                    0x88DF
#ifndef GLEE_H_DEFINED_glVertexAttrib1dARB
#define GLEE_H_DEFINED_glVertexAttrib1dARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1DARBPROC) (GLuint index, GLdouble x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1DARBPROC GLeeFuncPtr_glVertexAttrib1dARB;
  #define glVertexAttrib1dARB GLeeFuncPtr_glVertexAttrib1dARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1dvARB
#define GLEE_H_DEFINED_glVertexAttrib1dvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1DVARBPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1DVARBPROC GLeeFuncPtr_glVertexAttrib1dvARB;
  #define glVertexAttrib1dvARB GLeeFuncPtr_glVertexAttrib1dvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1fARB
#define GLEE_H_DEFINED_glVertexAttrib1fARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1FARBPROC) (GLuint index, GLfloat x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1FARBPROC GLeeFuncPtr_glVertexAttrib1fARB;
  #define glVertexAttrib1fARB GLeeFuncPtr_glVertexAttrib1fARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1fvARB
#define GLEE_H_DEFINED_glVertexAttrib1fvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1FVARBPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1FVARBPROC GLeeFuncPtr_glVertexAttrib1fvARB;
  #define glVertexAttrib1fvARB GLeeFuncPtr_glVertexAttrib1fvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1sARB
#define GLEE_H_DEFINED_glVertexAttrib1sARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1SARBPROC) (GLuint index, GLshort x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1SARBPROC GLeeFuncPtr_glVertexAttrib1sARB;
  #define glVertexAttrib1sARB GLeeFuncPtr_glVertexAttrib1sARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1svARB
#define GLEE_H_DEFINED_glVertexAttrib1svARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1SVARBPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1SVARBPROC GLeeFuncPtr_glVertexAttrib1svARB;
  #define glVertexAttrib1svARB GLeeFuncPtr_glVertexAttrib1svARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2dARB
#define GLEE_H_DEFINED_glVertexAttrib2dARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2DARBPROC) (GLuint index, GLdouble x, GLdouble y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2DARBPROC GLeeFuncPtr_glVertexAttrib2dARB;
  #define glVertexAttrib2dARB GLeeFuncPtr_glVertexAttrib2dARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2dvARB
#define GLEE_H_DEFINED_glVertexAttrib2dvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2DVARBPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2DVARBPROC GLeeFuncPtr_glVertexAttrib2dvARB;
  #define glVertexAttrib2dvARB GLeeFuncPtr_glVertexAttrib2dvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2fARB
#define GLEE_H_DEFINED_glVertexAttrib2fARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2FARBPROC) (GLuint index, GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2FARBPROC GLeeFuncPtr_glVertexAttrib2fARB;
  #define glVertexAttrib2fARB GLeeFuncPtr_glVertexAttrib2fARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2fvARB
#define GLEE_H_DEFINED_glVertexAttrib2fvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2FVARBPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2FVARBPROC GLeeFuncPtr_glVertexAttrib2fvARB;
  #define glVertexAttrib2fvARB GLeeFuncPtr_glVertexAttrib2fvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2sARB
#define GLEE_H_DEFINED_glVertexAttrib2sARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2SARBPROC) (GLuint index, GLshort x, GLshort y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2SARBPROC GLeeFuncPtr_glVertexAttrib2sARB;
  #define glVertexAttrib2sARB GLeeFuncPtr_glVertexAttrib2sARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2svARB
#define GLEE_H_DEFINED_glVertexAttrib2svARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2SVARBPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2SVARBPROC GLeeFuncPtr_glVertexAttrib2svARB;
  #define glVertexAttrib2svARB GLeeFuncPtr_glVertexAttrib2svARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3dARB
#define GLEE_H_DEFINED_glVertexAttrib3dARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3DARBPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3DARBPROC GLeeFuncPtr_glVertexAttrib3dARB;
  #define glVertexAttrib3dARB GLeeFuncPtr_glVertexAttrib3dARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3dvARB
#define GLEE_H_DEFINED_glVertexAttrib3dvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3DVARBPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3DVARBPROC GLeeFuncPtr_glVertexAttrib3dvARB;
  #define glVertexAttrib3dvARB GLeeFuncPtr_glVertexAttrib3dvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3fARB
#define GLEE_H_DEFINED_glVertexAttrib3fARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3FARBPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3FARBPROC GLeeFuncPtr_glVertexAttrib3fARB;
  #define glVertexAttrib3fARB GLeeFuncPtr_glVertexAttrib3fARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3fvARB
#define GLEE_H_DEFINED_glVertexAttrib3fvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3FVARBPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3FVARBPROC GLeeFuncPtr_glVertexAttrib3fvARB;
  #define glVertexAttrib3fvARB GLeeFuncPtr_glVertexAttrib3fvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3sARB
#define GLEE_H_DEFINED_glVertexAttrib3sARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3SARBPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3SARBPROC GLeeFuncPtr_glVertexAttrib3sARB;
  #define glVertexAttrib3sARB GLeeFuncPtr_glVertexAttrib3sARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3svARB
#define GLEE_H_DEFINED_glVertexAttrib3svARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3SVARBPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3SVARBPROC GLeeFuncPtr_glVertexAttrib3svARB;
  #define glVertexAttrib3svARB GLeeFuncPtr_glVertexAttrib3svARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4NbvARB
#define GLEE_H_DEFINED_glVertexAttrib4NbvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NBVARBPROC) (GLuint index, const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NBVARBPROC GLeeFuncPtr_glVertexAttrib4NbvARB;
  #define glVertexAttrib4NbvARB GLeeFuncPtr_glVertexAttrib4NbvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4NivARB
#define GLEE_H_DEFINED_glVertexAttrib4NivARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NIVARBPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NIVARBPROC GLeeFuncPtr_glVertexAttrib4NivARB;
  #define glVertexAttrib4NivARB GLeeFuncPtr_glVertexAttrib4NivARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4NsvARB
#define GLEE_H_DEFINED_glVertexAttrib4NsvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NSVARBPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NSVARBPROC GLeeFuncPtr_glVertexAttrib4NsvARB;
  #define glVertexAttrib4NsvARB GLeeFuncPtr_glVertexAttrib4NsvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4NubARB
#define GLEE_H_DEFINED_glVertexAttrib4NubARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUBARBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUBARBPROC GLeeFuncPtr_glVertexAttrib4NubARB;
  #define glVertexAttrib4NubARB GLeeFuncPtr_glVertexAttrib4NubARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4NubvARB
#define GLEE_H_DEFINED_glVertexAttrib4NubvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUBVARBPROC) (GLuint index, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUBVARBPROC GLeeFuncPtr_glVertexAttrib4NubvARB;
  #define glVertexAttrib4NubvARB GLeeFuncPtr_glVertexAttrib4NubvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4NuivARB
#define GLEE_H_DEFINED_glVertexAttrib4NuivARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUIVARBPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUIVARBPROC GLeeFuncPtr_glVertexAttrib4NuivARB;
  #define glVertexAttrib4NuivARB GLeeFuncPtr_glVertexAttrib4NuivARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4NusvARB
#define GLEE_H_DEFINED_glVertexAttrib4NusvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4NUSVARBPROC) (GLuint index, const GLushort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4NUSVARBPROC GLeeFuncPtr_glVertexAttrib4NusvARB;
  #define glVertexAttrib4NusvARB GLeeFuncPtr_glVertexAttrib4NusvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4bvARB
#define GLEE_H_DEFINED_glVertexAttrib4bvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4BVARBPROC) (GLuint index, const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4BVARBPROC GLeeFuncPtr_glVertexAttrib4bvARB;
  #define glVertexAttrib4bvARB GLeeFuncPtr_glVertexAttrib4bvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4dARB
#define GLEE_H_DEFINED_glVertexAttrib4dARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4DARBPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4DARBPROC GLeeFuncPtr_glVertexAttrib4dARB;
  #define glVertexAttrib4dARB GLeeFuncPtr_glVertexAttrib4dARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4dvARB
#define GLEE_H_DEFINED_glVertexAttrib4dvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4DVARBPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4DVARBPROC GLeeFuncPtr_glVertexAttrib4dvARB;
  #define glVertexAttrib4dvARB GLeeFuncPtr_glVertexAttrib4dvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4fARB
#define GLEE_H_DEFINED_glVertexAttrib4fARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4FARBPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4FARBPROC GLeeFuncPtr_glVertexAttrib4fARB;
  #define glVertexAttrib4fARB GLeeFuncPtr_glVertexAttrib4fARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4fvARB
#define GLEE_H_DEFINED_glVertexAttrib4fvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4FVARBPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4FVARBPROC GLeeFuncPtr_glVertexAttrib4fvARB;
  #define glVertexAttrib4fvARB GLeeFuncPtr_glVertexAttrib4fvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4ivARB
#define GLEE_H_DEFINED_glVertexAttrib4ivARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4IVARBPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4IVARBPROC GLeeFuncPtr_glVertexAttrib4ivARB;
  #define glVertexAttrib4ivARB GLeeFuncPtr_glVertexAttrib4ivARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4sARB
#define GLEE_H_DEFINED_glVertexAttrib4sARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4SARBPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4SARBPROC GLeeFuncPtr_glVertexAttrib4sARB;
  #define glVertexAttrib4sARB GLeeFuncPtr_glVertexAttrib4sARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4svARB
#define GLEE_H_DEFINED_glVertexAttrib4svARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4SVARBPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4SVARBPROC GLeeFuncPtr_glVertexAttrib4svARB;
  #define glVertexAttrib4svARB GLeeFuncPtr_glVertexAttrib4svARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4ubvARB
#define GLEE_H_DEFINED_glVertexAttrib4ubvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4UBVARBPROC) (GLuint index, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4UBVARBPROC GLeeFuncPtr_glVertexAttrib4ubvARB;
  #define glVertexAttrib4ubvARB GLeeFuncPtr_glVertexAttrib4ubvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4uivARB
#define GLEE_H_DEFINED_glVertexAttrib4uivARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4UIVARBPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4UIVARBPROC GLeeFuncPtr_glVertexAttrib4uivARB;
  #define glVertexAttrib4uivARB GLeeFuncPtr_glVertexAttrib4uivARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4usvARB
#define GLEE_H_DEFINED_glVertexAttrib4usvARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4USVARBPROC) (GLuint index, const GLushort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4USVARBPROC GLeeFuncPtr_glVertexAttrib4usvARB;
  #define glVertexAttrib4usvARB GLeeFuncPtr_glVertexAttrib4usvARB
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribPointerARB
#define GLEE_H_DEFINED_glVertexAttribPointerARB
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBPOINTERARBPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBPOINTERARBPROC GLeeFuncPtr_glVertexAttribPointerARB;
  #define glVertexAttribPointerARB GLeeFuncPtr_glVertexAttribPointerARB
#endif
#ifndef GLEE_H_DEFINED_glEnableVertexAttribArrayARB
#define GLEE_H_DEFINED_glEnableVertexAttribArrayARB
  typedef void (APIENTRYP GLEEPFNGLENABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);
  GLEE_EXTERN GLEEPFNGLENABLEVERTEXATTRIBARRAYARBPROC GLeeFuncPtr_glEnableVertexAttribArrayARB;
  #define glEnableVertexAttribArrayARB GLeeFuncPtr_glEnableVertexAttribArrayARB
#endif
#ifndef GLEE_H_DEFINED_glDisableVertexAttribArrayARB
#define GLEE_H_DEFINED_glDisableVertexAttribArrayARB
  typedef void (APIENTRYP GLEEPFNGLDISABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);
  GLEE_EXTERN GLEEPFNGLDISABLEVERTEXATTRIBARRAYARBPROC GLeeFuncPtr_glDisableVertexAttribArrayARB;
  #define glDisableVertexAttribArrayARB GLeeFuncPtr_glDisableVertexAttribArrayARB
#endif
#ifndef GLEE_H_DEFINED_glProgramStringARB
#define GLEE_H_DEFINED_glProgramStringARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMSTRINGARBPROC) (GLenum target, GLenum format, GLsizei len, const GLvoid * string);
  GLEE_EXTERN GLEEPFNGLPROGRAMSTRINGARBPROC GLeeFuncPtr_glProgramStringARB;
  #define glProgramStringARB GLeeFuncPtr_glProgramStringARB
#endif
#ifndef GLEE_H_DEFINED_glBindProgramARB
#define GLEE_H_DEFINED_glBindProgramARB
  typedef void (APIENTRYP GLEEPFNGLBINDPROGRAMARBPROC) (GLenum target, GLuint program);
  GLEE_EXTERN GLEEPFNGLBINDPROGRAMARBPROC GLeeFuncPtr_glBindProgramARB;
  #define glBindProgramARB GLeeFuncPtr_glBindProgramARB
#endif
#ifndef GLEE_H_DEFINED_glDeleteProgramsARB
#define GLEE_H_DEFINED_glDeleteProgramsARB
  typedef void (APIENTRYP GLEEPFNGLDELETEPROGRAMSARBPROC) (GLsizei n, const GLuint * programs);
  GLEE_EXTERN GLEEPFNGLDELETEPROGRAMSARBPROC GLeeFuncPtr_glDeleteProgramsARB;
  #define glDeleteProgramsARB GLeeFuncPtr_glDeleteProgramsARB
#endif
#ifndef GLEE_H_DEFINED_glGenProgramsARB
#define GLEE_H_DEFINED_glGenProgramsARB
  typedef void (APIENTRYP GLEEPFNGLGENPROGRAMSARBPROC) (GLsizei n, GLuint * programs);
  GLEE_EXTERN GLEEPFNGLGENPROGRAMSARBPROC GLeeFuncPtr_glGenProgramsARB;
  #define glGenProgramsARB GLeeFuncPtr_glGenProgramsARB
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameter4dARB
#define GLEE_H_DEFINED_glProgramEnvParameter4dARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETER4DARBPROC GLeeFuncPtr_glProgramEnvParameter4dARB;
  #define glProgramEnvParameter4dARB GLeeFuncPtr_glProgramEnvParameter4dARB
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameter4dvARB
#define GLEE_H_DEFINED_glProgramEnvParameter4dvARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETER4DVARBPROC GLeeFuncPtr_glProgramEnvParameter4dvARB;
  #define glProgramEnvParameter4dvARB GLeeFuncPtr_glProgramEnvParameter4dvARB
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameter4fARB
#define GLEE_H_DEFINED_glProgramEnvParameter4fARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETER4FARBPROC GLeeFuncPtr_glProgramEnvParameter4fARB;
  #define glProgramEnvParameter4fARB GLeeFuncPtr_glProgramEnvParameter4fARB
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameter4fvARB
#define GLEE_H_DEFINED_glProgramEnvParameter4fvARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETER4FVARBPROC GLeeFuncPtr_glProgramEnvParameter4fvARB;
  #define glProgramEnvParameter4fvARB GLeeFuncPtr_glProgramEnvParameter4fvARB
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameter4dARB
#define GLEE_H_DEFINED_glProgramLocalParameter4dARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETER4DARBPROC GLeeFuncPtr_glProgramLocalParameter4dARB;
  #define glProgramLocalParameter4dARB GLeeFuncPtr_glProgramLocalParameter4dARB
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameter4dvARB
#define GLEE_H_DEFINED_glProgramLocalParameter4dvARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETER4DVARBPROC GLeeFuncPtr_glProgramLocalParameter4dvARB;
  #define glProgramLocalParameter4dvARB GLeeFuncPtr_glProgramLocalParameter4dvARB
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameter4fARB
#define GLEE_H_DEFINED_glProgramLocalParameter4fARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETER4FARBPROC GLeeFuncPtr_glProgramLocalParameter4fARB;
  #define glProgramLocalParameter4fARB GLeeFuncPtr_glProgramLocalParameter4fARB
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameter4fvARB
#define GLEE_H_DEFINED_glProgramLocalParameter4fvARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETER4FVARBPROC GLeeFuncPtr_glProgramLocalParameter4fvARB;
  #define glProgramLocalParameter4fvARB GLeeFuncPtr_glProgramLocalParameter4fvARB
#endif
#ifndef GLEE_H_DEFINED_glGetProgramEnvParameterdvARB
#define GLEE_H_DEFINED_glGetProgramEnvParameterdvARB
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMENVPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMENVPARAMETERDVARBPROC GLeeFuncPtr_glGetProgramEnvParameterdvARB;
  #define glGetProgramEnvParameterdvARB GLeeFuncPtr_glGetProgramEnvParameterdvARB
#endif
#ifndef GLEE_H_DEFINED_glGetProgramEnvParameterfvARB
#define GLEE_H_DEFINED_glGetProgramEnvParameterfvARB
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMENVPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMENVPARAMETERFVARBPROC GLeeFuncPtr_glGetProgramEnvParameterfvARB;
  #define glGetProgramEnvParameterfvARB GLeeFuncPtr_glGetProgramEnvParameterfvARB
#endif
#ifndef GLEE_H_DEFINED_glGetProgramLocalParameterdvARB
#define GLEE_H_DEFINED_glGetProgramLocalParameterdvARB
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMLOCALPARAMETERDVARBPROC GLeeFuncPtr_glGetProgramLocalParameterdvARB;
  #define glGetProgramLocalParameterdvARB GLeeFuncPtr_glGetProgramLocalParameterdvARB
#endif
#ifndef GLEE_H_DEFINED_glGetProgramLocalParameterfvARB
#define GLEE_H_DEFINED_glGetProgramLocalParameterfvARB
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMLOCALPARAMETERFVARBPROC GLeeFuncPtr_glGetProgramLocalParameterfvARB;
  #define glGetProgramLocalParameterfvARB GLeeFuncPtr_glGetProgramLocalParameterfvARB
#endif
#ifndef GLEE_H_DEFINED_glGetProgramivARB
#define GLEE_H_DEFINED_glGetProgramivARB
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMIVARBPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMIVARBPROC GLeeFuncPtr_glGetProgramivARB;
  #define glGetProgramivARB GLeeFuncPtr_glGetProgramivARB
#endif
#ifndef GLEE_H_DEFINED_glGetProgramStringARB
#define GLEE_H_DEFINED_glGetProgramStringARB
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMSTRINGARBPROC) (GLenum target, GLenum pname, GLvoid * string);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMSTRINGARBPROC GLeeFuncPtr_glGetProgramStringARB;
  #define glGetProgramStringARB GLeeFuncPtr_glGetProgramStringARB
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribdvARB
#define GLEE_H_DEFINED_glGetVertexAttribdvARB
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBDVARBPROC) (GLuint index, GLenum pname, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBDVARBPROC GLeeFuncPtr_glGetVertexAttribdvARB;
  #define glGetVertexAttribdvARB GLeeFuncPtr_glGetVertexAttribdvARB
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribfvARB
#define GLEE_H_DEFINED_glGetVertexAttribfvARB
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBFVARBPROC) (GLuint index, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBFVARBPROC GLeeFuncPtr_glGetVertexAttribfvARB;
  #define glGetVertexAttribfvARB GLeeFuncPtr_glGetVertexAttribfvARB
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribivARB
#define GLEE_H_DEFINED_glGetVertexAttribivARB
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBIVARBPROC) (GLuint index, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBIVARBPROC GLeeFuncPtr_glGetVertexAttribivARB;
  #define glGetVertexAttribivARB GLeeFuncPtr_glGetVertexAttribivARB
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribPointervARB
#define GLEE_H_DEFINED_glGetVertexAttribPointervARB
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBPOINTERVARBPROC) (GLuint index, GLenum pname, GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBPOINTERVARBPROC GLeeFuncPtr_glGetVertexAttribPointervARB;
  #define glGetVertexAttribPointervARB GLeeFuncPtr_glGetVertexAttribPointervARB
#endif
#ifndef GLEE_H_DEFINED_glIsProgramARB
#define GLEE_H_DEFINED_glIsProgramARB
  typedef GLboolean (APIENTRYP GLEEPFNGLISPROGRAMARBPROC) (GLuint program);
  GLEE_EXTERN GLEEPFNGLISPROGRAMARBPROC GLeeFuncPtr_glIsProgramARB;
  #define glIsProgramARB GLeeFuncPtr_glIsProgramARB
#endif
#endif

/* GL_ARB_fragment_program */

#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1
#define __GLEE_GL_ARB_fragment_program 1
/* Constants */
#define GL_FRAGMENT_PROGRAM_ARB                            0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB                    0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB                    0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB                    0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB             0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB             0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB             0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB                0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB                0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB                0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB         0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB         0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB         0x8810
#define GL_MAX_TEXTURE_COORDS_ARB                          0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB                     0x8872
#endif

/* GL_ARB_vertex_buffer_object */

#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
#define __GLEE_GL_ARB_vertex_buffer_object 1
/* Constants */
#define GL_BUFFER_SIZE_ARB                                 0x8764
#define GL_BUFFER_USAGE_ARB                                0x8765
#define GL_ARRAY_BUFFER_ARB                                0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB                        0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB                        0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB                0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB                 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB                 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB                  0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB                  0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB          0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB              0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB        0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB         0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB                 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB          0x889F
#define GL_READ_ONLY_ARB                                   0x88B8
#define GL_WRITE_ONLY_ARB                                  0x88B9
#define GL_READ_WRITE_ARB                                  0x88BA
#define GL_BUFFER_ACCESS_ARB                               0x88BB
#define GL_BUFFER_MAPPED_ARB                               0x88BC
#define GL_BUFFER_MAP_POINTER_ARB                          0x88BD
#define GL_STREAM_DRAW_ARB                                 0x88E0
#define GL_STREAM_READ_ARB                                 0x88E1
#define GL_STREAM_COPY_ARB                                 0x88E2
#define GL_STATIC_DRAW_ARB                                 0x88E4
#define GL_STATIC_READ_ARB                                 0x88E5
#define GL_STATIC_COPY_ARB                                 0x88E6
#define GL_DYNAMIC_DRAW_ARB                                0x88E8
#define GL_DYNAMIC_READ_ARB                                0x88E9
#define GL_DYNAMIC_COPY_ARB                                0x88EA
#ifndef GLEE_H_DEFINED_glBindBufferARB
#define GLEE_H_DEFINED_glBindBufferARB
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERARBPROC) (GLenum target, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERARBPROC GLeeFuncPtr_glBindBufferARB;
  #define glBindBufferARB GLeeFuncPtr_glBindBufferARB
#endif
#ifndef GLEE_H_DEFINED_glDeleteBuffersARB
#define GLEE_H_DEFINED_glDeleteBuffersARB
  typedef void (APIENTRYP GLEEPFNGLDELETEBUFFERSARBPROC) (GLsizei n, const GLuint * buffers);
  GLEE_EXTERN GLEEPFNGLDELETEBUFFERSARBPROC GLeeFuncPtr_glDeleteBuffersARB;
  #define glDeleteBuffersARB GLeeFuncPtr_glDeleteBuffersARB
#endif
#ifndef GLEE_H_DEFINED_glGenBuffersARB
#define GLEE_H_DEFINED_glGenBuffersARB
  typedef void (APIENTRYP GLEEPFNGLGENBUFFERSARBPROC) (GLsizei n, GLuint * buffers);
  GLEE_EXTERN GLEEPFNGLGENBUFFERSARBPROC GLeeFuncPtr_glGenBuffersARB;
  #define glGenBuffersARB GLeeFuncPtr_glGenBuffersARB
#endif
#ifndef GLEE_H_DEFINED_glIsBufferARB
#define GLEE_H_DEFINED_glIsBufferARB
  typedef GLboolean (APIENTRYP GLEEPFNGLISBUFFERARBPROC) (GLuint buffer);
  GLEE_EXTERN GLEEPFNGLISBUFFERARBPROC GLeeFuncPtr_glIsBufferARB;
  #define glIsBufferARB GLeeFuncPtr_glIsBufferARB
#endif
#ifndef GLEE_H_DEFINED_glBufferDataARB
#define GLEE_H_DEFINED_glBufferDataARB
  typedef void (APIENTRYP GLEEPFNGLBUFFERDATAARBPROC) (GLenum target, GLsizeiptrARB size, const GLvoid * data, GLenum usage);
  GLEE_EXTERN GLEEPFNGLBUFFERDATAARBPROC GLeeFuncPtr_glBufferDataARB;
  #define glBufferDataARB GLeeFuncPtr_glBufferDataARB
#endif
#ifndef GLEE_H_DEFINED_glBufferSubDataARB
#define GLEE_H_DEFINED_glBufferSubDataARB
  typedef void (APIENTRYP GLEEPFNGLBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLBUFFERSUBDATAARBPROC GLeeFuncPtr_glBufferSubDataARB;
  #define glBufferSubDataARB GLeeFuncPtr_glBufferSubDataARB
#endif
#ifndef GLEE_H_DEFINED_glGetBufferSubDataARB
#define GLEE_H_DEFINED_glGetBufferSubDataARB
  typedef void (APIENTRYP GLEEPFNGLGETBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid * data);
  GLEE_EXTERN GLEEPFNGLGETBUFFERSUBDATAARBPROC GLeeFuncPtr_glGetBufferSubDataARB;
  #define glGetBufferSubDataARB GLeeFuncPtr_glGetBufferSubDataARB
#endif
#ifndef GLEE_H_DEFINED_glMapBufferARB
#define GLEE_H_DEFINED_glMapBufferARB
  typedef GLvoid* (APIENTRYP GLEEPFNGLMAPBUFFERARBPROC) (GLenum target, GLenum access);
  GLEE_EXTERN GLEEPFNGLMAPBUFFERARBPROC GLeeFuncPtr_glMapBufferARB;
  #define glMapBufferARB GLeeFuncPtr_glMapBufferARB
#endif
#ifndef GLEE_H_DEFINED_glUnmapBufferARB
#define GLEE_H_DEFINED_glUnmapBufferARB
  typedef GLboolean (APIENTRYP GLEEPFNGLUNMAPBUFFERARBPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLUNMAPBUFFERARBPROC GLeeFuncPtr_glUnmapBufferARB;
  #define glUnmapBufferARB GLeeFuncPtr_glUnmapBufferARB
#endif
#ifndef GLEE_H_DEFINED_glGetBufferParameterivARB
#define GLEE_H_DEFINED_glGetBufferParameterivARB
  typedef void (APIENTRYP GLEEPFNGLGETBUFFERPARAMETERIVARBPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETBUFFERPARAMETERIVARBPROC GLeeFuncPtr_glGetBufferParameterivARB;
  #define glGetBufferParameterivARB GLeeFuncPtr_glGetBufferParameterivARB
#endif
#ifndef GLEE_H_DEFINED_glGetBufferPointervARB
#define GLEE_H_DEFINED_glGetBufferPointervARB
  typedef void (APIENTRYP GLEEPFNGLGETBUFFERPOINTERVARBPROC) (GLenum target, GLenum pname, GLvoid* * params);
  GLEE_EXTERN GLEEPFNGLGETBUFFERPOINTERVARBPROC GLeeFuncPtr_glGetBufferPointervARB;
  #define glGetBufferPointervARB GLeeFuncPtr_glGetBufferPointervARB
#endif
#endif

/* GL_ARB_occlusion_query */

#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
#define __GLEE_GL_ARB_occlusion_query 1
/* Constants */
#define GL_QUERY_COUNTER_BITS_ARB                          0x8864
#define GL_CURRENT_QUERY_ARB                               0x8865
#define GL_QUERY_RESULT_ARB                                0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB                      0x8867
#define GL_SAMPLES_PASSED_ARB                              0x8914
#ifndef GLEE_H_DEFINED_glGenQueriesARB
#define GLEE_H_DEFINED_glGenQueriesARB
  typedef void (APIENTRYP GLEEPFNGLGENQUERIESARBPROC) (GLsizei n, GLuint * ids);
  GLEE_EXTERN GLEEPFNGLGENQUERIESARBPROC GLeeFuncPtr_glGenQueriesARB;
  #define glGenQueriesARB GLeeFuncPtr_glGenQueriesARB
#endif
#ifndef GLEE_H_DEFINED_glDeleteQueriesARB
#define GLEE_H_DEFINED_glDeleteQueriesARB
  typedef void (APIENTRYP GLEEPFNGLDELETEQUERIESARBPROC) (GLsizei n, const GLuint * ids);
  GLEE_EXTERN GLEEPFNGLDELETEQUERIESARBPROC GLeeFuncPtr_glDeleteQueriesARB;
  #define glDeleteQueriesARB GLeeFuncPtr_glDeleteQueriesARB
#endif
#ifndef GLEE_H_DEFINED_glIsQueryARB
#define GLEE_H_DEFINED_glIsQueryARB
  typedef GLboolean (APIENTRYP GLEEPFNGLISQUERYARBPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLISQUERYARBPROC GLeeFuncPtr_glIsQueryARB;
  #define glIsQueryARB GLeeFuncPtr_glIsQueryARB
#endif
#ifndef GLEE_H_DEFINED_glBeginQueryARB
#define GLEE_H_DEFINED_glBeginQueryARB
  typedef void (APIENTRYP GLEEPFNGLBEGINQUERYARBPROC) (GLenum target, GLuint id);
  GLEE_EXTERN GLEEPFNGLBEGINQUERYARBPROC GLeeFuncPtr_glBeginQueryARB;
  #define glBeginQueryARB GLeeFuncPtr_glBeginQueryARB
#endif
#ifndef GLEE_H_DEFINED_glEndQueryARB
#define GLEE_H_DEFINED_glEndQueryARB
  typedef void (APIENTRYP GLEEPFNGLENDQUERYARBPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLENDQUERYARBPROC GLeeFuncPtr_glEndQueryARB;
  #define glEndQueryARB GLeeFuncPtr_glEndQueryARB
#endif
#ifndef GLEE_H_DEFINED_glGetQueryivARB
#define GLEE_H_DEFINED_glGetQueryivARB
  typedef void (APIENTRYP GLEEPFNGLGETQUERYIVARBPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYIVARBPROC GLeeFuncPtr_glGetQueryivARB;
  #define glGetQueryivARB GLeeFuncPtr_glGetQueryivARB
#endif
#ifndef GLEE_H_DEFINED_glGetQueryObjectivARB
#define GLEE_H_DEFINED_glGetQueryObjectivARB
  typedef void (APIENTRYP GLEEPFNGLGETQUERYOBJECTIVARBPROC) (GLuint id, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYOBJECTIVARBPROC GLeeFuncPtr_glGetQueryObjectivARB;
  #define glGetQueryObjectivARB GLeeFuncPtr_glGetQueryObjectivARB
#endif
#ifndef GLEE_H_DEFINED_glGetQueryObjectuivARB
#define GLEE_H_DEFINED_glGetQueryObjectuivARB
  typedef void (APIENTRYP GLEEPFNGLGETQUERYOBJECTUIVARBPROC) (GLuint id, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYOBJECTUIVARBPROC GLeeFuncPtr_glGetQueryObjectuivARB;
  #define glGetQueryObjectuivARB GLeeFuncPtr_glGetQueryObjectuivARB
#endif
#endif

/* GL_ARB_shader_objects */

#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
#define __GLEE_GL_ARB_shader_objects 1
/* Constants */
#define GL_PROGRAM_OBJECT_ARB                              0x8B40
#define GL_SHADER_OBJECT_ARB                               0x8B48
#define GL_OBJECT_TYPE_ARB                                 0x8B4E
#define GL_OBJECT_SUBTYPE_ARB                              0x8B4F
#define GL_FLOAT_VEC2_ARB                                  0x8B50
#define GL_FLOAT_VEC3_ARB                                  0x8B51
#define GL_FLOAT_VEC4_ARB                                  0x8B52
#define GL_INT_VEC2_ARB                                    0x8B53
#define GL_INT_VEC3_ARB                                    0x8B54
#define GL_INT_VEC4_ARB                                    0x8B55
#define GL_BOOL_ARB                                        0x8B56
#define GL_BOOL_VEC2_ARB                                   0x8B57
#define GL_BOOL_VEC3_ARB                                   0x8B58
#define GL_BOOL_VEC4_ARB                                   0x8B59
#define GL_FLOAT_MAT2_ARB                                  0x8B5A
#define GL_FLOAT_MAT3_ARB                                  0x8B5B
#define GL_FLOAT_MAT4_ARB                                  0x8B5C
#define GL_SAMPLER_1D_ARB                                  0x8B5D
#define GL_SAMPLER_2D_ARB                                  0x8B5E
#define GL_SAMPLER_3D_ARB                                  0x8B5F
#define GL_SAMPLER_CUBE_ARB                                0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB                           0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB                           0x8B62
#define GL_SAMPLER_2D_RECT_ARB                             0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB                      0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB                        0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB                       0x8B81
#define GL_OBJECT_LINK_STATUS_ARB                          0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB                      0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB                      0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB                     0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB                      0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB            0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB                 0x8B88
#ifndef GLEE_H_DEFINED_glDeleteObjectARB
#define GLEE_H_DEFINED_glDeleteObjectARB
  typedef void (APIENTRYP GLEEPFNGLDELETEOBJECTARBPROC) (GLhandleARB obj);
  GLEE_EXTERN GLEEPFNGLDELETEOBJECTARBPROC GLeeFuncPtr_glDeleteObjectARB;
  #define glDeleteObjectARB GLeeFuncPtr_glDeleteObjectARB
#endif
#ifndef GLEE_H_DEFINED_glGetHandleARB
#define GLEE_H_DEFINED_glGetHandleARB
  typedef GLhandleARB (APIENTRYP GLEEPFNGLGETHANDLEARBPROC) (GLenum pname);
  GLEE_EXTERN GLEEPFNGLGETHANDLEARBPROC GLeeFuncPtr_glGetHandleARB;
  #define glGetHandleARB GLeeFuncPtr_glGetHandleARB
#endif
#ifndef GLEE_H_DEFINED_glDetachObjectARB
#define GLEE_H_DEFINED_glDetachObjectARB
  typedef void (APIENTRYP GLEEPFNGLDETACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB attachedObj);
  GLEE_EXTERN GLEEPFNGLDETACHOBJECTARBPROC GLeeFuncPtr_glDetachObjectARB;
  #define glDetachObjectARB GLeeFuncPtr_glDetachObjectARB
#endif
#ifndef GLEE_H_DEFINED_glCreateShaderObjectARB
#define GLEE_H_DEFINED_glCreateShaderObjectARB
  typedef GLhandleARB (APIENTRYP GLEEPFNGLCREATESHADEROBJECTARBPROC) (GLenum shaderType);
  GLEE_EXTERN GLEEPFNGLCREATESHADEROBJECTARBPROC GLeeFuncPtr_glCreateShaderObjectARB;
  #define glCreateShaderObjectARB GLeeFuncPtr_glCreateShaderObjectARB
#endif
#ifndef GLEE_H_DEFINED_glShaderSourceARB
#define GLEE_H_DEFINED_glShaderSourceARB
  typedef void (APIENTRYP GLEEPFNGLSHADERSOURCEARBPROC) (GLhandleARB shaderObj, GLsizei count, const GLcharARB* * string, const GLint * length);
  GLEE_EXTERN GLEEPFNGLSHADERSOURCEARBPROC GLeeFuncPtr_glShaderSourceARB;
  #define glShaderSourceARB GLeeFuncPtr_glShaderSourceARB
#endif
#ifndef GLEE_H_DEFINED_glCompileShaderARB
#define GLEE_H_DEFINED_glCompileShaderARB
  typedef void (APIENTRYP GLEEPFNGLCOMPILESHADERARBPROC) (GLhandleARB shaderObj);
  GLEE_EXTERN GLEEPFNGLCOMPILESHADERARBPROC GLeeFuncPtr_glCompileShaderARB;
  #define glCompileShaderARB GLeeFuncPtr_glCompileShaderARB
#endif
#ifndef GLEE_H_DEFINED_glCreateProgramObjectARB
#define GLEE_H_DEFINED_glCreateProgramObjectARB
  typedef GLhandleARB (APIENTRYP GLEEPFNGLCREATEPROGRAMOBJECTARBPROC) ();
  GLEE_EXTERN GLEEPFNGLCREATEPROGRAMOBJECTARBPROC GLeeFuncPtr_glCreateProgramObjectARB;
  #define glCreateProgramObjectARB GLeeFuncPtr_glCreateProgramObjectARB
#endif
#ifndef GLEE_H_DEFINED_glAttachObjectARB
#define GLEE_H_DEFINED_glAttachObjectARB
  typedef void (APIENTRYP GLEEPFNGLATTACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB obj);
  GLEE_EXTERN GLEEPFNGLATTACHOBJECTARBPROC GLeeFuncPtr_glAttachObjectARB;
  #define glAttachObjectARB GLeeFuncPtr_glAttachObjectARB
#endif
#ifndef GLEE_H_DEFINED_glLinkProgramARB
#define GLEE_H_DEFINED_glLinkProgramARB
  typedef void (APIENTRYP GLEEPFNGLLINKPROGRAMARBPROC) (GLhandleARB programObj);
  GLEE_EXTERN GLEEPFNGLLINKPROGRAMARBPROC GLeeFuncPtr_glLinkProgramARB;
  #define glLinkProgramARB GLeeFuncPtr_glLinkProgramARB
#endif
#ifndef GLEE_H_DEFINED_glUseProgramObjectARB
#define GLEE_H_DEFINED_glUseProgramObjectARB
  typedef void (APIENTRYP GLEEPFNGLUSEPROGRAMOBJECTARBPROC) (GLhandleARB programObj);
  GLEE_EXTERN GLEEPFNGLUSEPROGRAMOBJECTARBPROC GLeeFuncPtr_glUseProgramObjectARB;
  #define glUseProgramObjectARB GLeeFuncPtr_glUseProgramObjectARB
#endif
#ifndef GLEE_H_DEFINED_glValidateProgramARB
#define GLEE_H_DEFINED_glValidateProgramARB
  typedef void (APIENTRYP GLEEPFNGLVALIDATEPROGRAMARBPROC) (GLhandleARB programObj);
  GLEE_EXTERN GLEEPFNGLVALIDATEPROGRAMARBPROC GLeeFuncPtr_glValidateProgramARB;
  #define glValidateProgramARB GLeeFuncPtr_glValidateProgramARB
#endif
#ifndef GLEE_H_DEFINED_glUniform1fARB
#define GLEE_H_DEFINED_glUniform1fARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1FARBPROC) (GLint location, GLfloat v0);
  GLEE_EXTERN GLEEPFNGLUNIFORM1FARBPROC GLeeFuncPtr_glUniform1fARB;
  #define glUniform1fARB GLeeFuncPtr_glUniform1fARB
#endif
#ifndef GLEE_H_DEFINED_glUniform2fARB
#define GLEE_H_DEFINED_glUniform2fARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2FARBPROC) (GLint location, GLfloat v0, GLfloat v1);
  GLEE_EXTERN GLEEPFNGLUNIFORM2FARBPROC GLeeFuncPtr_glUniform2fARB;
  #define glUniform2fARB GLeeFuncPtr_glUniform2fARB
#endif
#ifndef GLEE_H_DEFINED_glUniform3fARB
#define GLEE_H_DEFINED_glUniform3fARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
  GLEE_EXTERN GLEEPFNGLUNIFORM3FARBPROC GLeeFuncPtr_glUniform3fARB;
  #define glUniform3fARB GLeeFuncPtr_glUniform3fARB
#endif
#ifndef GLEE_H_DEFINED_glUniform4fARB
#define GLEE_H_DEFINED_glUniform4fARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
  GLEE_EXTERN GLEEPFNGLUNIFORM4FARBPROC GLeeFuncPtr_glUniform4fARB;
  #define glUniform4fARB GLeeFuncPtr_glUniform4fARB
#endif
#ifndef GLEE_H_DEFINED_glUniform1iARB
#define GLEE_H_DEFINED_glUniform1iARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1IARBPROC) (GLint location, GLint v0);
  GLEE_EXTERN GLEEPFNGLUNIFORM1IARBPROC GLeeFuncPtr_glUniform1iARB;
  #define glUniform1iARB GLeeFuncPtr_glUniform1iARB
#endif
#ifndef GLEE_H_DEFINED_glUniform2iARB
#define GLEE_H_DEFINED_glUniform2iARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2IARBPROC) (GLint location, GLint v0, GLint v1);
  GLEE_EXTERN GLEEPFNGLUNIFORM2IARBPROC GLeeFuncPtr_glUniform2iARB;
  #define glUniform2iARB GLeeFuncPtr_glUniform2iARB
#endif
#ifndef GLEE_H_DEFINED_glUniform3iARB
#define GLEE_H_DEFINED_glUniform3iARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2);
  GLEE_EXTERN GLEEPFNGLUNIFORM3IARBPROC GLeeFuncPtr_glUniform3iARB;
  #define glUniform3iARB GLeeFuncPtr_glUniform3iARB
#endif
#ifndef GLEE_H_DEFINED_glUniform4iARB
#define GLEE_H_DEFINED_glUniform4iARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
  GLEE_EXTERN GLEEPFNGLUNIFORM4IARBPROC GLeeFuncPtr_glUniform4iARB;
  #define glUniform4iARB GLeeFuncPtr_glUniform4iARB
#endif
#ifndef GLEE_H_DEFINED_glUniform1fvARB
#define GLEE_H_DEFINED_glUniform1fvARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM1FVARBPROC GLeeFuncPtr_glUniform1fvARB;
  #define glUniform1fvARB GLeeFuncPtr_glUniform1fvARB
#endif
#ifndef GLEE_H_DEFINED_glUniform2fvARB
#define GLEE_H_DEFINED_glUniform2fvARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM2FVARBPROC GLeeFuncPtr_glUniform2fvARB;
  #define glUniform2fvARB GLeeFuncPtr_glUniform2fvARB
#endif
#ifndef GLEE_H_DEFINED_glUniform3fvARB
#define GLEE_H_DEFINED_glUniform3fvARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM3FVARBPROC GLeeFuncPtr_glUniform3fvARB;
  #define glUniform3fvARB GLeeFuncPtr_glUniform3fvARB
#endif
#ifndef GLEE_H_DEFINED_glUniform4fvARB
#define GLEE_H_DEFINED_glUniform4fvARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM4FVARBPROC GLeeFuncPtr_glUniform4fvARB;
  #define glUniform4fvARB GLeeFuncPtr_glUniform4fvARB
#endif
#ifndef GLEE_H_DEFINED_glUniform1ivARB
#define GLEE_H_DEFINED_glUniform1ivARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1IVARBPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM1IVARBPROC GLeeFuncPtr_glUniform1ivARB;
  #define glUniform1ivARB GLeeFuncPtr_glUniform1ivARB
#endif
#ifndef GLEE_H_DEFINED_glUniform2ivARB
#define GLEE_H_DEFINED_glUniform2ivARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2IVARBPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM2IVARBPROC GLeeFuncPtr_glUniform2ivARB;
  #define glUniform2ivARB GLeeFuncPtr_glUniform2ivARB
#endif
#ifndef GLEE_H_DEFINED_glUniform3ivARB
#define GLEE_H_DEFINED_glUniform3ivARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3IVARBPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM3IVARBPROC GLeeFuncPtr_glUniform3ivARB;
  #define glUniform3ivARB GLeeFuncPtr_glUniform3ivARB
#endif
#ifndef GLEE_H_DEFINED_glUniform4ivARB
#define GLEE_H_DEFINED_glUniform4ivARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4IVARBPROC) (GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM4IVARBPROC GLeeFuncPtr_glUniform4ivARB;
  #define glUniform4ivARB GLeeFuncPtr_glUniform4ivARB
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix2fvARB
#define GLEE_H_DEFINED_glUniformMatrix2fvARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX2FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX2FVARBPROC GLeeFuncPtr_glUniformMatrix2fvARB;
  #define glUniformMatrix2fvARB GLeeFuncPtr_glUniformMatrix2fvARB
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix3fvARB
#define GLEE_H_DEFINED_glUniformMatrix3fvARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX3FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX3FVARBPROC GLeeFuncPtr_glUniformMatrix3fvARB;
  #define glUniformMatrix3fvARB GLeeFuncPtr_glUniformMatrix3fvARB
#endif
#ifndef GLEE_H_DEFINED_glUniformMatrix4fvARB
#define GLEE_H_DEFINED_glUniformMatrix4fvARB
  typedef void (APIENTRYP GLEEPFNGLUNIFORMMATRIX4FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLUNIFORMMATRIX4FVARBPROC GLeeFuncPtr_glUniformMatrix4fvARB;
  #define glUniformMatrix4fvARB GLeeFuncPtr_glUniformMatrix4fvARB
#endif
#ifndef GLEE_H_DEFINED_glGetObjectParameterfvARB
#define GLEE_H_DEFINED_glGetObjectParameterfvARB
  typedef void (APIENTRYP GLEEPFNGLGETOBJECTPARAMETERFVARBPROC) (GLhandleARB obj, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETOBJECTPARAMETERFVARBPROC GLeeFuncPtr_glGetObjectParameterfvARB;
  #define glGetObjectParameterfvARB GLeeFuncPtr_glGetObjectParameterfvARB
#endif
#ifndef GLEE_H_DEFINED_glGetObjectParameterivARB
#define GLEE_H_DEFINED_glGetObjectParameterivARB
  typedef void (APIENTRYP GLEEPFNGLGETOBJECTPARAMETERIVARBPROC) (GLhandleARB obj, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETOBJECTPARAMETERIVARBPROC GLeeFuncPtr_glGetObjectParameterivARB;
  #define glGetObjectParameterivARB GLeeFuncPtr_glGetObjectParameterivARB
#endif
#ifndef GLEE_H_DEFINED_glGetInfoLogARB
#define GLEE_H_DEFINED_glGetInfoLogARB
  typedef void (APIENTRYP GLEEPFNGLGETINFOLOGARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog);
  GLEE_EXTERN GLEEPFNGLGETINFOLOGARBPROC GLeeFuncPtr_glGetInfoLogARB;
  #define glGetInfoLogARB GLeeFuncPtr_glGetInfoLogARB
#endif
#ifndef GLEE_H_DEFINED_glGetAttachedObjectsARB
#define GLEE_H_DEFINED_glGetAttachedObjectsARB
  typedef void (APIENTRYP GLEEPFNGLGETATTACHEDOBJECTSARBPROC) (GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj);
  GLEE_EXTERN GLEEPFNGLGETATTACHEDOBJECTSARBPROC GLeeFuncPtr_glGetAttachedObjectsARB;
  #define glGetAttachedObjectsARB GLeeFuncPtr_glGetAttachedObjectsARB
#endif
#ifndef GLEE_H_DEFINED_glGetUniformLocationARB
#define GLEE_H_DEFINED_glGetUniformLocationARB
  typedef GLint (APIENTRYP GLEEPFNGLGETUNIFORMLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB * name);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMLOCATIONARBPROC GLeeFuncPtr_glGetUniformLocationARB;
  #define glGetUniformLocationARB GLeeFuncPtr_glGetUniformLocationARB
#endif
#ifndef GLEE_H_DEFINED_glGetActiveUniformARB
#define GLEE_H_DEFINED_glGetActiveUniformARB
  typedef void (APIENTRYP GLEEPFNGLGETACTIVEUNIFORMARBPROC) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
  GLEE_EXTERN GLEEPFNGLGETACTIVEUNIFORMARBPROC GLeeFuncPtr_glGetActiveUniformARB;
  #define glGetActiveUniformARB GLeeFuncPtr_glGetActiveUniformARB
#endif
#ifndef GLEE_H_DEFINED_glGetUniformfvARB
#define GLEE_H_DEFINED_glGetUniformfvARB
  typedef void (APIENTRYP GLEEPFNGLGETUNIFORMFVARBPROC) (GLhandleARB programObj, GLint location, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMFVARBPROC GLeeFuncPtr_glGetUniformfvARB;
  #define glGetUniformfvARB GLeeFuncPtr_glGetUniformfvARB
#endif
#ifndef GLEE_H_DEFINED_glGetUniformivARB
#define GLEE_H_DEFINED_glGetUniformivARB
  typedef void (APIENTRYP GLEEPFNGLGETUNIFORMIVARBPROC) (GLhandleARB programObj, GLint location, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMIVARBPROC GLeeFuncPtr_glGetUniformivARB;
  #define glGetUniformivARB GLeeFuncPtr_glGetUniformivARB
#endif
#ifndef GLEE_H_DEFINED_glGetShaderSourceARB
#define GLEE_H_DEFINED_glGetShaderSourceARB
  typedef void (APIENTRYP GLEEPFNGLGETSHADERSOURCEARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source);
  GLEE_EXTERN GLEEPFNGLGETSHADERSOURCEARBPROC GLeeFuncPtr_glGetShaderSourceARB;
  #define glGetShaderSourceARB GLeeFuncPtr_glGetShaderSourceARB
#endif
#endif

/* GL_ARB_vertex_shader */

#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
#define __GLEE_GL_ARB_vertex_shader 1
/* Constants */
#define GL_VERTEX_SHADER_ARB                               0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB               0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB                          0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB              0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB            0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB                    0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB          0x8B8A
#ifndef GLEE_H_DEFINED_glBindAttribLocationARB
#define GLEE_H_DEFINED_glBindAttribLocationARB
  typedef void (APIENTRYP GLEEPFNGLBINDATTRIBLOCATIONARBPROC) (GLhandleARB programObj, GLuint index, const GLcharARB * name);
  GLEE_EXTERN GLEEPFNGLBINDATTRIBLOCATIONARBPROC GLeeFuncPtr_glBindAttribLocationARB;
  #define glBindAttribLocationARB GLeeFuncPtr_glBindAttribLocationARB
#endif
#ifndef GLEE_H_DEFINED_glGetActiveAttribARB
#define GLEE_H_DEFINED_glGetActiveAttribARB
  typedef void (APIENTRYP GLEEPFNGLGETACTIVEATTRIBARBPROC) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
  GLEE_EXTERN GLEEPFNGLGETACTIVEATTRIBARBPROC GLeeFuncPtr_glGetActiveAttribARB;
  #define glGetActiveAttribARB GLeeFuncPtr_glGetActiveAttribARB
#endif
#ifndef GLEE_H_DEFINED_glGetAttribLocationARB
#define GLEE_H_DEFINED_glGetAttribLocationARB
  typedef GLint (APIENTRYP GLEEPFNGLGETATTRIBLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB * name);
  GLEE_EXTERN GLEEPFNGLGETATTRIBLOCATIONARBPROC GLeeFuncPtr_glGetAttribLocationARB;
  #define glGetAttribLocationARB GLeeFuncPtr_glGetAttribLocationARB
#endif
#endif

/* GL_ARB_fragment_shader */

#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader 1
#define __GLEE_GL_ARB_fragment_shader 1
/* Constants */
#define GL_FRAGMENT_SHADER_ARB                             0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB             0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB             0x8B8B
#endif

/* GL_ARB_shading_language_100 */

#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100 1
#define __GLEE_GL_ARB_shading_language_100 1
/* Constants */
#define GL_SHADING_LANGUAGE_VERSION_ARB                    0x8B8C
#endif

/* GL_ARB_texture_non_power_of_two */

#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1
#define __GLEE_GL_ARB_texture_non_power_of_two 1
/* Constants */
#endif

/* GL_ARB_point_sprite */

#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite 1
#define __GLEE_GL_ARB_point_sprite 1
/* Constants */
#define GL_POINT_SPRITE_ARB                                0x8861
#define GL_COORD_REPLACE_ARB                               0x8862
#endif

/* GL_ARB_fragment_program_shadow */

#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow 1
#define __GLEE_GL_ARB_fragment_program_shadow 1
/* Constants */
#endif

/* GL_ARB_draw_buffers */

#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
#define __GLEE_GL_ARB_draw_buffers 1
/* Constants */
#define GL_MAX_DRAW_BUFFERS_ARB                            0x8824
#define GL_DRAW_BUFFER0_ARB                                0x8825
#define GL_DRAW_BUFFER1_ARB                                0x8826
#define GL_DRAW_BUFFER2_ARB                                0x8827
#define GL_DRAW_BUFFER3_ARB                                0x8828
#define GL_DRAW_BUFFER4_ARB                                0x8829
#define GL_DRAW_BUFFER5_ARB                                0x882A
#define GL_DRAW_BUFFER6_ARB                                0x882B
#define GL_DRAW_BUFFER7_ARB                                0x882C
#define GL_DRAW_BUFFER8_ARB                                0x882D
#define GL_DRAW_BUFFER9_ARB                                0x882E
#define GL_DRAW_BUFFER10_ARB                               0x882F
#define GL_DRAW_BUFFER11_ARB                               0x8830
#define GL_DRAW_BUFFER12_ARB                               0x8831
#define GL_DRAW_BUFFER13_ARB                               0x8832
#define GL_DRAW_BUFFER14_ARB                               0x8833
#define GL_DRAW_BUFFER15_ARB                               0x8834
#ifndef GLEE_H_DEFINED_glDrawBuffersARB
#define GLEE_H_DEFINED_glDrawBuffersARB
  typedef void (APIENTRYP GLEEPFNGLDRAWBUFFERSARBPROC) (GLsizei n, const GLenum * bufs);
  GLEE_EXTERN GLEEPFNGLDRAWBUFFERSARBPROC GLeeFuncPtr_glDrawBuffersARB;
  #define glDrawBuffersARB GLeeFuncPtr_glDrawBuffersARB
#endif
#endif

/* GL_ARB_texture_rectangle */

#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle 1
#define __GLEE_GL_ARB_texture_rectangle 1
/* Constants */
#define GL_TEXTURE_RECTANGLE_ARB                           0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB                   0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB                     0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB                  0x84F8
#endif

/* GL_ARB_color_buffer_float */

#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
#define __GLEE_GL_ARB_color_buffer_float 1
/* Constants */
#define GL_RGBA_FLOAT_MODE_ARB                             0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB                          0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB                        0x891B
#define GL_CLAMP_READ_COLOR_ARB                            0x891C
#define GL_FIXED_ONLY_ARB                                  0x891D
#ifndef GLEE_H_DEFINED_glClampColorARB
#define GLEE_H_DEFINED_glClampColorARB
  typedef void (APIENTRYP GLEEPFNGLCLAMPCOLORARBPROC) (GLenum target, GLenum clamp);
  GLEE_EXTERN GLEEPFNGLCLAMPCOLORARBPROC GLeeFuncPtr_glClampColorARB;
  #define glClampColorARB GLeeFuncPtr_glClampColorARB
#endif
#endif

/* GL_ARB_half_float_pixel */

#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel 1
#define __GLEE_GL_ARB_half_float_pixel 1
/* Constants */
#define GL_HALF_FLOAT_ARB                                  0x140B
#endif

/* GL_ARB_texture_float */

#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float 1
#define __GLEE_GL_ARB_texture_float 1
/* Constants */
#define GL_TEXTURE_RED_TYPE_ARB                            0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB                          0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB                           0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB                          0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB                      0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB                      0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB                          0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB                         0x8C17
#define GL_RGBA32F_ARB                                     0x8814
#define GL_RGB32F_ARB                                      0x8815
#define GL_ALPHA32F_ARB                                    0x8816
#define GL_INTENSITY32F_ARB                                0x8817
#define GL_LUMINANCE32F_ARB                                0x8818
#define GL_LUMINANCE_ALPHA32F_ARB                          0x8819
#define GL_RGBA16F_ARB                                     0x881A
#define GL_RGB16F_ARB                                      0x881B
#define GL_ALPHA16F_ARB                                    0x881C
#define GL_INTENSITY16F_ARB                                0x881D
#define GL_LUMINANCE16F_ARB                                0x881E
#define GL_LUMINANCE_ALPHA16F_ARB                          0x881F
#endif

/* GL_ARB_pixel_buffer_object */

#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1
#define __GLEE_GL_ARB_pixel_buffer_object 1
/* Constants */
#define GL_PIXEL_PACK_BUFFER_ARB                           0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB                         0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB                   0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB                 0x88EF
#endif

/* GL_ARB_depth_buffer_float */

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#define __GLEE_GL_ARB_depth_buffer_float 1
/* Constants */
#define GL_DEPTH_COMPONENT32F                              0x8CAC
#define GL_DEPTH32F_STENCIL8                               0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                  0x8DAD
#endif

/* GL_ARB_draw_instanced */

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
#define __GLEE_GL_ARB_draw_instanced 1
/* Constants */
#ifndef GLEE_H_DEFINED_glDrawArraysInstancedARB
#define GLEE_H_DEFINED_glDrawArraysInstancedARB
  typedef void (APIENTRYP GLEEPFNGLDRAWARRAYSINSTANCEDARBPROC) (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLDRAWARRAYSINSTANCEDARBPROC GLeeFuncPtr_glDrawArraysInstancedARB;
  #define glDrawArraysInstancedARB GLeeFuncPtr_glDrawArraysInstancedARB
#endif
#ifndef GLEE_H_DEFINED_glDrawElementsInstancedARB
#define GLEE_H_DEFINED_glDrawElementsInstancedARB
  typedef void (APIENTRYP GLEEPFNGLDRAWELEMENTSINSTANCEDARBPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLDRAWELEMENTSINSTANCEDARBPROC GLeeFuncPtr_glDrawElementsInstancedARB;
  #define glDrawElementsInstancedARB GLeeFuncPtr_glDrawElementsInstancedARB
#endif
#endif

/* GL_ARB_framebuffer_object */

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#define __GLEE_GL_ARB_framebuffer_object 1
/* Constants */
#define GL_INVALID_FRAMEBUFFER_OPERATION                   0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING           0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE           0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE               0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE               0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE               0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE             0x8217
#define GL_FRAMEBUFFER_DEFAULT                             0x8218
#define GL_FRAMEBUFFER_UNDEFINED                           0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT                        0x821A
#define GL_INDEX                                           0x8222
#define GL_MAX_RENDERBUFFER_SIZE                           0x84E8
#define GL_DEPTH_STENCIL                                   0x84F9
#define GL_UNSIGNED_INT_24_8                               0x84FA
#define GL_DEPTH24_STENCIL8                                0x88F0
#define GL_TEXTURE_STENCIL_SIZE                            0x88F1
#define GL_FRAMEBUFFER_BINDING                             0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING                        GL_FRAMEBUFFER_BINDING
#define GL_RENDERBUFFER_BINDING                            0x8CA7
#define GL_READ_FRAMEBUFFER                                0x8CA8
#define GL_DRAW_FRAMEBUFFER                                0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING                        0x8CAA
#define GL_RENDERBUFFER_SAMPLES                            0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE              0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME              0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL            0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE    0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER            0x8CD4
#define GL_FRAMEBUFFER_COMPLETE                            0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT               0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT       0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER              0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER              0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED                         0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS                           0x8CDF
#define GL_COLOR_ATTACHMENT0                               0x8CE0
#define GL_COLOR_ATTACHMENT1                               0x8CE1
#define GL_COLOR_ATTACHMENT2                               0x8CE2
#define GL_COLOR_ATTACHMENT3                               0x8CE3
#define GL_COLOR_ATTACHMENT4                               0x8CE4
#define GL_COLOR_ATTACHMENT5                               0x8CE5
#define GL_COLOR_ATTACHMENT6                               0x8CE6
#define GL_COLOR_ATTACHMENT7                               0x8CE7
#define GL_COLOR_ATTACHMENT8                               0x8CE8
#define GL_COLOR_ATTACHMENT9                               0x8CE9
#define GL_COLOR_ATTACHMENT10                              0x8CEA
#define GL_COLOR_ATTACHMENT11                              0x8CEB
#define GL_COLOR_ATTACHMENT12                              0x8CEC
#define GL_COLOR_ATTACHMENT13                              0x8CED
#define GL_COLOR_ATTACHMENT14                              0x8CEE
#define GL_COLOR_ATTACHMENT15                              0x8CEF
#define GL_DEPTH_ATTACHMENT                                0x8D00
#define GL_STENCIL_ATTACHMENT                              0x8D20
#define GL_FRAMEBUFFER                                     0x8D40
#define GL_RENDERBUFFER                                    0x8D41
#define GL_RENDERBUFFER_WIDTH                              0x8D42
#define GL_RENDERBUFFER_HEIGHT                             0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT                    0x8D44
#define GL_STENCIL_INDEX1                                  0x8D46
#define GL_STENCIL_INDEX4                                  0x8D47
#define GL_STENCIL_INDEX8                                  0x8D48
#define GL_STENCIL_INDEX16                                 0x8D49
#define GL_RENDERBUFFER_RED_SIZE                           0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE                         0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE                          0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE                         0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE                         0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE                       0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE              0x8D56
#define GL_MAX_SAMPLES                                     0x8D57
#ifndef GLEE_H_DEFINED_glIsRenderbuffer
#define GLEE_H_DEFINED_glIsRenderbuffer
  typedef GLboolean (APIENTRYP GLEEPFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLISRENDERBUFFERPROC GLeeFuncPtr_glIsRenderbuffer;
  #define glIsRenderbuffer GLeeFuncPtr_glIsRenderbuffer
#endif
#ifndef GLEE_H_DEFINED_glBindRenderbuffer
#define GLEE_H_DEFINED_glBindRenderbuffer
  typedef void (APIENTRYP GLEEPFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLBINDRENDERBUFFERPROC GLeeFuncPtr_glBindRenderbuffer;
  #define glBindRenderbuffer GLeeFuncPtr_glBindRenderbuffer
#endif
#ifndef GLEE_H_DEFINED_glDeleteRenderbuffers
#define GLEE_H_DEFINED_glDeleteRenderbuffers
  typedef void (APIENTRYP GLEEPFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint * renderbuffers);
  GLEE_EXTERN GLEEPFNGLDELETERENDERBUFFERSPROC GLeeFuncPtr_glDeleteRenderbuffers;
  #define glDeleteRenderbuffers GLeeFuncPtr_glDeleteRenderbuffers
#endif
#ifndef GLEE_H_DEFINED_glGenRenderbuffers
#define GLEE_H_DEFINED_glGenRenderbuffers
  typedef void (APIENTRYP GLEEPFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint * renderbuffers);
  GLEE_EXTERN GLEEPFNGLGENRENDERBUFFERSPROC GLeeFuncPtr_glGenRenderbuffers;
  #define glGenRenderbuffers GLeeFuncPtr_glGenRenderbuffers
#endif
#ifndef GLEE_H_DEFINED_glRenderbufferStorage
#define GLEE_H_DEFINED_glRenderbufferStorage
  typedef void (APIENTRYP GLEEPFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLRENDERBUFFERSTORAGEPROC GLeeFuncPtr_glRenderbufferStorage;
  #define glRenderbufferStorage GLeeFuncPtr_glRenderbufferStorage
#endif
#ifndef GLEE_H_DEFINED_glGetRenderbufferParameteriv
#define GLEE_H_DEFINED_glGetRenderbufferParameteriv
  typedef void (APIENTRYP GLEEPFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETRENDERBUFFERPARAMETERIVPROC GLeeFuncPtr_glGetRenderbufferParameteriv;
  #define glGetRenderbufferParameteriv GLeeFuncPtr_glGetRenderbufferParameteriv
#endif
#ifndef GLEE_H_DEFINED_glIsFramebuffer
#define GLEE_H_DEFINED_glIsFramebuffer
  typedef GLboolean (APIENTRYP GLEEPFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
  GLEE_EXTERN GLEEPFNGLISFRAMEBUFFERPROC GLeeFuncPtr_glIsFramebuffer;
  #define glIsFramebuffer GLeeFuncPtr_glIsFramebuffer
#endif
#ifndef GLEE_H_DEFINED_glBindFramebuffer
#define GLEE_H_DEFINED_glBindFramebuffer
  typedef void (APIENTRYP GLEEPFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
  GLEE_EXTERN GLEEPFNGLBINDFRAMEBUFFERPROC GLeeFuncPtr_glBindFramebuffer;
  #define glBindFramebuffer GLeeFuncPtr_glBindFramebuffer
#endif
#ifndef GLEE_H_DEFINED_glDeleteFramebuffers
#define GLEE_H_DEFINED_glDeleteFramebuffers
  typedef void (APIENTRYP GLEEPFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint * framebuffers);
  GLEE_EXTERN GLEEPFNGLDELETEFRAMEBUFFERSPROC GLeeFuncPtr_glDeleteFramebuffers;
  #define glDeleteFramebuffers GLeeFuncPtr_glDeleteFramebuffers
#endif
#ifndef GLEE_H_DEFINED_glGenFramebuffers
#define GLEE_H_DEFINED_glGenFramebuffers
  typedef void (APIENTRYP GLEEPFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint * framebuffers);
  GLEE_EXTERN GLEEPFNGLGENFRAMEBUFFERSPROC GLeeFuncPtr_glGenFramebuffers;
  #define glGenFramebuffers GLeeFuncPtr_glGenFramebuffers
#endif
#ifndef GLEE_H_DEFINED_glCheckFramebufferStatus
#define GLEE_H_DEFINED_glCheckFramebufferStatus
  typedef GLenum (APIENTRYP GLEEPFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLCHECKFRAMEBUFFERSTATUSPROC GLeeFuncPtr_glCheckFramebufferStatus;
  #define glCheckFramebufferStatus GLeeFuncPtr_glCheckFramebufferStatus
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTexture1D
#define GLEE_H_DEFINED_glFramebufferTexture1D
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURE1DPROC GLeeFuncPtr_glFramebufferTexture1D;
  #define glFramebufferTexture1D GLeeFuncPtr_glFramebufferTexture1D
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTexture2D
#define GLEE_H_DEFINED_glFramebufferTexture2D
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURE2DPROC GLeeFuncPtr_glFramebufferTexture2D;
  #define glFramebufferTexture2D GLeeFuncPtr_glFramebufferTexture2D
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTexture3D
#define GLEE_H_DEFINED_glFramebufferTexture3D
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURE3DPROC GLeeFuncPtr_glFramebufferTexture3D;
  #define glFramebufferTexture3D GLeeFuncPtr_glFramebufferTexture3D
#endif
#ifndef GLEE_H_DEFINED_glFramebufferRenderbuffer
#define GLEE_H_DEFINED_glFramebufferRenderbuffer
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERRENDERBUFFERPROC GLeeFuncPtr_glFramebufferRenderbuffer;
  #define glFramebufferRenderbuffer GLeeFuncPtr_glFramebufferRenderbuffer
#endif
#ifndef GLEE_H_DEFINED_glGetFramebufferAttachmentParameteriv
#define GLEE_H_DEFINED_glGetFramebufferAttachmentParameteriv
  typedef void (APIENTRYP GLEEPFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC GLeeFuncPtr_glGetFramebufferAttachmentParameteriv;
  #define glGetFramebufferAttachmentParameteriv GLeeFuncPtr_glGetFramebufferAttachmentParameteriv
#endif
#ifndef GLEE_H_DEFINED_glGenerateMipmap
#define GLEE_H_DEFINED_glGenerateMipmap
  typedef void (APIENTRYP GLEEPFNGLGENERATEMIPMAPPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLGENERATEMIPMAPPROC GLeeFuncPtr_glGenerateMipmap;
  #define glGenerateMipmap GLeeFuncPtr_glGenerateMipmap
#endif
#ifndef GLEE_H_DEFINED_glBlitFramebuffer
#define GLEE_H_DEFINED_glBlitFramebuffer
  typedef void (APIENTRYP GLEEPFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
  GLEE_EXTERN GLEEPFNGLBLITFRAMEBUFFERPROC GLeeFuncPtr_glBlitFramebuffer;
  #define glBlitFramebuffer GLeeFuncPtr_glBlitFramebuffer
#endif
#ifndef GLEE_H_DEFINED_glRenderbufferStorageMultisample
#define GLEE_H_DEFINED_glRenderbufferStorageMultisample
  typedef void (APIENTRYP GLEEPFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC GLeeFuncPtr_glRenderbufferStorageMultisample;
  #define glRenderbufferStorageMultisample GLeeFuncPtr_glRenderbufferStorageMultisample
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureLayer
#define GLEE_H_DEFINED_glFramebufferTextureLayer
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURELAYERPROC GLeeFuncPtr_glFramebufferTextureLayer;
  #define glFramebufferTextureLayer GLeeFuncPtr_glFramebufferTextureLayer
#endif
#endif

/* GL_ARB_framebuffer_sRGB */

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#define __GLEE_GL_ARB_framebuffer_sRGB 1
/* Constants */
#define GL_FRAMEBUFFER_SRGB                                0x8DB9
#endif

/* GL_ARB_geometry_shader4 */

#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
#define __GLEE_GL_ARB_geometry_shader4 1
/* Constants */
#define GL_LINES_ADJACENCY_ARB                             0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB                        0x000B
#define GL_TRIANGLES_ADJACENCY_ARB                         0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB                    0x000D
#define GL_PROGRAM_POINT_SIZE_ARB                          0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB            0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB              0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB        0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB          0x8DA9
#define GL_GEOMETRY_SHADER_ARB                             0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB                       0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB                         0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB                        0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB             0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB               0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB             0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB                0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB        0x8DE1
#ifndef GLEE_H_DEFINED_glProgramParameteriARB
#define GLEE_H_DEFINED_glProgramParameteriARB
  typedef void (APIENTRYP GLEEPFNGLPROGRAMPARAMETERIARBPROC) (GLuint program, GLenum pname, GLint value);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETERIARBPROC GLeeFuncPtr_glProgramParameteriARB;
  #define glProgramParameteriARB GLeeFuncPtr_glProgramParameteriARB
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureARB
#define GLEE_H_DEFINED_glFramebufferTextureARB
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTUREARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTUREARBPROC GLeeFuncPtr_glFramebufferTextureARB;
  #define glFramebufferTextureARB GLeeFuncPtr_glFramebufferTextureARB
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureLayerARB
#define GLEE_H_DEFINED_glFramebufferTextureLayerARB
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURELAYERARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURELAYERARBPROC GLeeFuncPtr_glFramebufferTextureLayerARB;
  #define glFramebufferTextureLayerARB GLeeFuncPtr_glFramebufferTextureLayerARB
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureFaceARB
#define GLEE_H_DEFINED_glFramebufferTextureFaceARB
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTUREFACEARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTUREFACEARBPROC GLeeFuncPtr_glFramebufferTextureFaceARB;
  #define glFramebufferTextureFaceARB GLeeFuncPtr_glFramebufferTextureFaceARB
#endif
#endif

/* GL_ARB_half_float_vertex */

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#define __GLEE_GL_ARB_half_float_vertex 1
/* Constants */
#define GL_HALF_FLOAT                                      0x140B
#endif

/* GL_ARB_instanced_arrays */

#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
#define __GLEE_GL_ARB_instanced_arrays 1
/* Constants */
#ifndef GLEE_H_DEFINED_glVertexAttribDivisor
#define GLEE_H_DEFINED_glVertexAttribDivisor
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBDIVISORPROC GLeeFuncPtr_glVertexAttribDivisor;
  #define glVertexAttribDivisor GLeeFuncPtr_glVertexAttribDivisor
#endif
#endif

/* GL_ARB_map_buffer_range */

#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#define __GLEE_GL_ARB_map_buffer_range 1
/* Constants */
#define GL_MAP_READ_BIT                                    0x0001
#define GL_MAP_WRITE_BIT                                   0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT                        0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT                       0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT                          0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT                          0x0020
#ifndef GLEE_H_DEFINED_glMapBufferRange
#define GLEE_H_DEFINED_glMapBufferRange
  typedef void (APIENTRYP GLEEPFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
  GLEE_EXTERN GLEEPFNGLMAPBUFFERRANGEPROC GLeeFuncPtr_glMapBufferRange;
  #define glMapBufferRange GLeeFuncPtr_glMapBufferRange
#endif
#ifndef GLEE_H_DEFINED_glFlushMappedBufferRange
#define GLEE_H_DEFINED_glFlushMappedBufferRange
  typedef void (APIENTRYP GLEEPFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
  GLEE_EXTERN GLEEPFNGLFLUSHMAPPEDBUFFERRANGEPROC GLeeFuncPtr_glFlushMappedBufferRange;
  #define glFlushMappedBufferRange GLeeFuncPtr_glFlushMappedBufferRange
#endif
#endif

/* GL_ARB_texture_buffer_object */

#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
#define __GLEE_GL_ARB_texture_buffer_object 1
/* Constants */
#define GL_TEXTURE_BUFFER_ARB                              0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB                     0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB                      0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB           0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB                       0x8C2E
#ifndef GLEE_H_DEFINED_glTexBufferARB
#define GLEE_H_DEFINED_glTexBufferARB
  typedef void (APIENTRYP GLEEPFNGLTEXBUFFERARBPROC) (GLenum target, GLenum internalformat, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLTEXBUFFERARBPROC GLeeFuncPtr_glTexBufferARB;
  #define glTexBufferARB GLeeFuncPtr_glTexBufferARB
#endif
#endif

/* GL_ARB_texture_compression_rgtc */

#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#define __GLEE_GL_ARB_texture_compression_rgtc 1
/* Constants */
#define GL_COMPRESSED_RED_RGTC1                            0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1                     0x8DBC
#define GL_COMPRESSED_RG_RGTC2                             0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2                      0x8DBE
#endif

/* GL_ARB_texture_rg */

#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#define __GLEE_GL_ARB_texture_rg 1
/* Constants */
#define GL_RG                                              0x8227
#define GL_RG_INTEGER                                      0x8228
#define GL_R8                                              0x8229
#define GL_R16                                             0x822A
#define GL_RG8                                             0x822B
#define GL_RG16                                            0x822C
#define GL_R16F                                            0x822D
#define GL_R32F                                            0x822E
#define GL_RG16F                                           0x822F
#define GL_RG32F                                           0x8230
#define GL_R8I                                             0x8231
#define GL_R8UI                                            0x8232
#define GL_R16I                                            0x8233
#define GL_R16UI                                           0x8234
#define GL_R32I                                            0x8235
#define GL_R32UI                                           0x8236
#define GL_RG8I                                            0x8237
#define GL_RG8UI                                           0x8238
#define GL_RG16I                                           0x8239
#define GL_RG16UI                                          0x823A
#define GL_RG32I                                           0x823B
#define GL_RG32UI                                          0x823C
#endif

/* GL_ARB_vertex_array_object */

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#define __GLEE_GL_ARB_vertex_array_object 1
/* Constants */
#define GL_VERTEX_ARRAY_BINDING                            0x85B5
#ifndef GLEE_H_DEFINED_glBindVertexArray
#define GLEE_H_DEFINED_glBindVertexArray
  typedef void (APIENTRYP GLEEPFNGLBINDVERTEXARRAYPROC) (GLuint array);
  GLEE_EXTERN GLEEPFNGLBINDVERTEXARRAYPROC GLeeFuncPtr_glBindVertexArray;
  #define glBindVertexArray GLeeFuncPtr_glBindVertexArray
#endif
#ifndef GLEE_H_DEFINED_glDeleteVertexArrays
#define GLEE_H_DEFINED_glDeleteVertexArrays
  typedef void (APIENTRYP GLEEPFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint * arrays);
  GLEE_EXTERN GLEEPFNGLDELETEVERTEXARRAYSPROC GLeeFuncPtr_glDeleteVertexArrays;
  #define glDeleteVertexArrays GLeeFuncPtr_glDeleteVertexArrays
#endif
#ifndef GLEE_H_DEFINED_glGenVertexArrays
#define GLEE_H_DEFINED_glGenVertexArrays
  typedef void (APIENTRYP GLEEPFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint * arrays);
  GLEE_EXTERN GLEEPFNGLGENVERTEXARRAYSPROC GLeeFuncPtr_glGenVertexArrays;
  #define glGenVertexArrays GLeeFuncPtr_glGenVertexArrays
#endif
#ifndef GLEE_H_DEFINED_glIsVertexArray
#define GLEE_H_DEFINED_glIsVertexArray
  typedef GLboolean (APIENTRYP GLEEPFNGLISVERTEXARRAYPROC) (GLuint array);
  GLEE_EXTERN GLEEPFNGLISVERTEXARRAYPROC GLeeFuncPtr_glIsVertexArray;
  #define glIsVertexArray GLeeFuncPtr_glIsVertexArray
#endif
#endif

/* GL_EXT_abgr */

#ifndef GL_EXT_abgr
#define GL_EXT_abgr 1
#define __GLEE_GL_EXT_abgr 1
/* Constants */
#define GL_ABGR_EXT                                        0x8000
#endif

/* GL_EXT_blend_color */

#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
#define __GLEE_GL_EXT_blend_color 1
/* Constants */
#define GL_CONSTANT_COLOR_EXT                              0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT                    0x8002
#define GL_CONSTANT_ALPHA_EXT                              0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT                    0x8004
#define GL_BLEND_COLOR_EXT                                 0x8005
#ifndef GLEE_H_DEFINED_glBlendColorEXT
#define GLEE_H_DEFINED_glBlendColorEXT
  typedef void (APIENTRYP GLEEPFNGLBLENDCOLOREXTPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
  GLEE_EXTERN GLEEPFNGLBLENDCOLOREXTPROC GLeeFuncPtr_glBlendColorEXT;
  #define glBlendColorEXT GLeeFuncPtr_glBlendColorEXT
#endif
#endif

/* GL_EXT_polygon_offset */

#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset 1
#define __GLEE_GL_EXT_polygon_offset 1
/* Constants */
#define GL_POLYGON_OFFSET_EXT                              0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT                       0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT                         0x8039
#ifndef GLEE_H_DEFINED_glPolygonOffsetEXT
#define GLEE_H_DEFINED_glPolygonOffsetEXT
  typedef void (APIENTRYP GLEEPFNGLPOLYGONOFFSETEXTPROC) (GLfloat factor, GLfloat bias);
  GLEE_EXTERN GLEEPFNGLPOLYGONOFFSETEXTPROC GLeeFuncPtr_glPolygonOffsetEXT;
  #define glPolygonOffsetEXT GLeeFuncPtr_glPolygonOffsetEXT
#endif
#endif

/* GL_EXT_texture */

#ifndef GL_EXT_texture
#define GL_EXT_texture 1
#define __GLEE_GL_EXT_texture 1
/* Constants */
#define GL_ALPHA4_EXT                                      0x803B
#define GL_ALPHA8_EXT                                      0x803C
#define GL_ALPHA12_EXT                                     0x803D
#define GL_ALPHA16_EXT                                     0x803E
#define GL_LUMINANCE4_EXT                                  0x803F
#define GL_LUMINANCE8_EXT                                  0x8040
#define GL_LUMINANCE12_EXT                                 0x8041
#define GL_LUMINANCE16_EXT                                 0x8042
#define GL_LUMINANCE4_ALPHA4_EXT                           0x8043
#define GL_LUMINANCE6_ALPHA2_EXT                           0x8044
#define GL_LUMINANCE8_ALPHA8_EXT                           0x8045
#define GL_LUMINANCE12_ALPHA4_EXT                          0x8046
#define GL_LUMINANCE12_ALPHA12_EXT                         0x8047
#define GL_LUMINANCE16_ALPHA16_EXT                         0x8048
#define GL_INTENSITY_EXT                                   0x8049
#define GL_INTENSITY4_EXT                                  0x804A
#define GL_INTENSITY8_EXT                                  0x804B
#define GL_INTENSITY12_EXT                                 0x804C
#define GL_INTENSITY16_EXT                                 0x804D
#define GL_RGB2_EXT                                        0x804E
#define GL_RGB4_EXT                                        0x804F
#define GL_RGB5_EXT                                        0x8050
#define GL_RGB8_EXT                                        0x8051
#define GL_RGB10_EXT                                       0x8052
#define GL_RGB12_EXT                                       0x8053
#define GL_RGB16_EXT                                       0x8054
#define GL_RGBA2_EXT                                       0x8055
#define GL_RGBA4_EXT                                       0x8056
#define GL_RGB5_A1_EXT                                     0x8057
#define GL_RGBA8_EXT                                       0x8058
#define GL_RGB10_A2_EXT                                    0x8059
#define GL_RGBA12_EXT                                      0x805A
#define GL_RGBA16_EXT                                      0x805B
#define GL_TEXTURE_RED_SIZE_EXT                            0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT                          0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT                           0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT                          0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT                      0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT                      0x8061
#define GL_REPLACE_EXT                                     0x8062
#define GL_PROXY_TEXTURE_1D_EXT                            0x8063
#define GL_PROXY_TEXTURE_2D_EXT                            0x8064
#define GL_TEXTURE_TOO_LARGE_EXT                           0x8065
#endif

/* GL_EXT_texture3D */

#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
#define __GLEE_GL_EXT_texture3D 1
/* Constants */
#define GL_PACK_SKIP_IMAGES_EXT                            0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT                           0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT                          0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT                         0x806E
#define GL_TEXTURE_3D_EXT                                  0x806F
#define GL_PROXY_TEXTURE_3D_EXT                            0x8070
#define GL_TEXTURE_DEPTH_EXT                               0x8071
#define GL_TEXTURE_WRAP_R_EXT                              0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT                         0x8073
#ifndef GLEE_H_DEFINED_glTexImage3DEXT
#define GLEE_H_DEFINED_glTexImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXIMAGE3DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXIMAGE3DEXTPROC GLeeFuncPtr_glTexImage3DEXT;
  #define glTexImage3DEXT GLeeFuncPtr_glTexImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glTexSubImage3DEXT
#define GLEE_H_DEFINED_glTexSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXSUBIMAGE3DEXTPROC GLeeFuncPtr_glTexSubImage3DEXT;
  #define glTexSubImage3DEXT GLeeFuncPtr_glTexSubImage3DEXT
#endif
#endif

/* GL_SGIS_texture_filter4 */

#ifndef GL_SGIS_texture_filter4
#define GL_SGIS_texture_filter4 1
#define __GLEE_GL_SGIS_texture_filter4 1
/* Constants */
#define GL_FILTER4_SGIS                                    0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS                       0x8147
#ifndef GLEE_H_DEFINED_glGetTexFilterFuncSGIS
#define GLEE_H_DEFINED_glGetTexFilterFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLGETTEXFILTERFUNCSGISPROC) (GLenum target, GLenum filter, GLfloat * weights);
  GLEE_EXTERN GLEEPFNGLGETTEXFILTERFUNCSGISPROC GLeeFuncPtr_glGetTexFilterFuncSGIS;
  #define glGetTexFilterFuncSGIS GLeeFuncPtr_glGetTexFilterFuncSGIS
#endif
#ifndef GLEE_H_DEFINED_glTexFilterFuncSGIS
#define GLEE_H_DEFINED_glTexFilterFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLTEXFILTERFUNCSGISPROC) (GLenum target, GLenum filter, GLsizei n, const GLfloat * weights);
  GLEE_EXTERN GLEEPFNGLTEXFILTERFUNCSGISPROC GLeeFuncPtr_glTexFilterFuncSGIS;
  #define glTexFilterFuncSGIS GLeeFuncPtr_glTexFilterFuncSGIS
#endif
#endif

/* GL_EXT_subtexture */

#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture 1
#define __GLEE_GL_EXT_subtexture 1
/* Constants */
#ifndef GLEE_H_DEFINED_glTexSubImage1DEXT
#define GLEE_H_DEFINED_glTexSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXSUBIMAGE1DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXSUBIMAGE1DEXTPROC GLeeFuncPtr_glTexSubImage1DEXT;
  #define glTexSubImage1DEXT GLeeFuncPtr_glTexSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glTexSubImage2DEXT
#define GLEE_H_DEFINED_glTexSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXSUBIMAGE2DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXSUBIMAGE2DEXTPROC GLeeFuncPtr_glTexSubImage2DEXT;
  #define glTexSubImage2DEXT GLeeFuncPtr_glTexSubImage2DEXT
#endif
#endif

/* GL_EXT_copy_texture */

#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture 1
#define __GLEE_GL_EXT_copy_texture 1
/* Constants */
#ifndef GLEE_H_DEFINED_glCopyTexImage1DEXT
#define GLEE_H_DEFINED_glCopyTexImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXIMAGE1DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
  GLEE_EXTERN GLEEPFNGLCOPYTEXIMAGE1DEXTPROC GLeeFuncPtr_glCopyTexImage1DEXT;
  #define glCopyTexImage1DEXT GLeeFuncPtr_glCopyTexImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTexImage2DEXT
#define GLEE_H_DEFINED_glCopyTexImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXIMAGE2DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
  GLEE_EXTERN GLEEPFNGLCOPYTEXIMAGE2DEXTPROC GLeeFuncPtr_glCopyTexImage2DEXT;
  #define glCopyTexImage2DEXT GLeeFuncPtr_glCopyTexImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTexSubImage1DEXT
#define GLEE_H_DEFINED_glCopyTexSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXSUBIMAGE1DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYTEXSUBIMAGE1DEXTPROC GLeeFuncPtr_glCopyTexSubImage1DEXT;
  #define glCopyTexSubImage1DEXT GLeeFuncPtr_glCopyTexSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTexSubImage2DEXT
#define GLEE_H_DEFINED_glCopyTexSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXSUBIMAGE2DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYTEXSUBIMAGE2DEXTPROC GLeeFuncPtr_glCopyTexSubImage2DEXT;
  #define glCopyTexSubImage2DEXT GLeeFuncPtr_glCopyTexSubImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTexSubImage3DEXT
#define GLEE_H_DEFINED_glCopyTexSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYTEXSUBIMAGE3DEXTPROC GLeeFuncPtr_glCopyTexSubImage3DEXT;
  #define glCopyTexSubImage3DEXT GLeeFuncPtr_glCopyTexSubImage3DEXT
#endif
#endif

/* GL_EXT_histogram */

#ifndef GL_EXT_histogram
#define GL_EXT_histogram 1
#define __GLEE_GL_EXT_histogram 1
/* Constants */
#define GL_HISTOGRAM_EXT                                   0x8024
#define GL_PROXY_HISTOGRAM_EXT                             0x8025
#define GL_HISTOGRAM_WIDTH_EXT                             0x8026
#define GL_HISTOGRAM_FORMAT_EXT                            0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT                          0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT                        0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT                         0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT                        0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT                    0x802C
#define GL_HISTOGRAM_SINK_EXT                              0x802D
#define GL_MINMAX_EXT                                      0x802E
#define GL_MINMAX_FORMAT_EXT                               0x802F
#define GL_MINMAX_SINK_EXT                                 0x8030
#define GL_TABLE_TOO_LARGE_EXT                             0x8031
#ifndef GLEE_H_DEFINED_glGetHistogramEXT
#define GLEE_H_DEFINED_glGetHistogramEXT
  typedef void (APIENTRYP GLEEPFNGLGETHISTOGRAMEXTPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
  GLEE_EXTERN GLEEPFNGLGETHISTOGRAMEXTPROC GLeeFuncPtr_glGetHistogramEXT;
  #define glGetHistogramEXT GLeeFuncPtr_glGetHistogramEXT
#endif
#ifndef GLEE_H_DEFINED_glGetHistogramParameterfvEXT
#define GLEE_H_DEFINED_glGetHistogramParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETHISTOGRAMPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETHISTOGRAMPARAMETERFVEXTPROC GLeeFuncPtr_glGetHistogramParameterfvEXT;
  #define glGetHistogramParameterfvEXT GLeeFuncPtr_glGetHistogramParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetHistogramParameterivEXT
#define GLEE_H_DEFINED_glGetHistogramParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETHISTOGRAMPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETHISTOGRAMPARAMETERIVEXTPROC GLeeFuncPtr_glGetHistogramParameterivEXT;
  #define glGetHistogramParameterivEXT GLeeFuncPtr_glGetHistogramParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMinmaxEXT
#define GLEE_H_DEFINED_glGetMinmaxEXT
  typedef void (APIENTRYP GLEEPFNGLGETMINMAXEXTPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
  GLEE_EXTERN GLEEPFNGLGETMINMAXEXTPROC GLeeFuncPtr_glGetMinmaxEXT;
  #define glGetMinmaxEXT GLeeFuncPtr_glGetMinmaxEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMinmaxParameterfvEXT
#define GLEE_H_DEFINED_glGetMinmaxParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETMINMAXPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMINMAXPARAMETERFVEXTPROC GLeeFuncPtr_glGetMinmaxParameterfvEXT;
  #define glGetMinmaxParameterfvEXT GLeeFuncPtr_glGetMinmaxParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMinmaxParameterivEXT
#define GLEE_H_DEFINED_glGetMinmaxParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETMINMAXPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMINMAXPARAMETERIVEXTPROC GLeeFuncPtr_glGetMinmaxParameterivEXT;
  #define glGetMinmaxParameterivEXT GLeeFuncPtr_glGetMinmaxParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glHistogramEXT
#define GLEE_H_DEFINED_glHistogramEXT
  typedef void (APIENTRYP GLEEPFNGLHISTOGRAMEXTPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
  GLEE_EXTERN GLEEPFNGLHISTOGRAMEXTPROC GLeeFuncPtr_glHistogramEXT;
  #define glHistogramEXT GLeeFuncPtr_glHistogramEXT
#endif
#ifndef GLEE_H_DEFINED_glMinmaxEXT
#define GLEE_H_DEFINED_glMinmaxEXT
  typedef void (APIENTRYP GLEEPFNGLMINMAXEXTPROC) (GLenum target, GLenum internalformat, GLboolean sink);
  GLEE_EXTERN GLEEPFNGLMINMAXEXTPROC GLeeFuncPtr_glMinmaxEXT;
  #define glMinmaxEXT GLeeFuncPtr_glMinmaxEXT
#endif
#ifndef GLEE_H_DEFINED_glResetHistogramEXT
#define GLEE_H_DEFINED_glResetHistogramEXT
  typedef void (APIENTRYP GLEEPFNGLRESETHISTOGRAMEXTPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLRESETHISTOGRAMEXTPROC GLeeFuncPtr_glResetHistogramEXT;
  #define glResetHistogramEXT GLeeFuncPtr_glResetHistogramEXT
#endif
#ifndef GLEE_H_DEFINED_glResetMinmaxEXT
#define GLEE_H_DEFINED_glResetMinmaxEXT
  typedef void (APIENTRYP GLEEPFNGLRESETMINMAXEXTPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLRESETMINMAXEXTPROC GLeeFuncPtr_glResetMinmaxEXT;
  #define glResetMinmaxEXT GLeeFuncPtr_glResetMinmaxEXT
#endif
#endif

/* GL_EXT_convolution */

#ifndef GL_EXT_convolution
#define GL_EXT_convolution 1
#define __GLEE_GL_EXT_convolution 1
/* Constants */
#define GL_CONVOLUTION_1D_EXT                              0x8010
#define GL_CONVOLUTION_2D_EXT                              0x8011
#define GL_SEPARABLE_2D_EXT                                0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT                     0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT                    0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT                     0x8015
#define GL_REDUCE_EXT                                      0x8016
#define GL_CONVOLUTION_FORMAT_EXT                          0x8017
#define GL_CONVOLUTION_WIDTH_EXT                           0x8018
#define GL_CONVOLUTION_HEIGHT_EXT                          0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT                       0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT                      0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT                  0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT                0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT                 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT                0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT                   0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT                 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT                  0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT                 0x8023
#ifndef GLEE_H_DEFINED_glConvolutionFilter1DEXT
#define GLEE_H_DEFINED_glConvolutionFilter1DEXT
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONFILTER1DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONFILTER1DEXTPROC GLeeFuncPtr_glConvolutionFilter1DEXT;
  #define glConvolutionFilter1DEXT GLeeFuncPtr_glConvolutionFilter1DEXT
#endif
#ifndef GLEE_H_DEFINED_glConvolutionFilter2DEXT
#define GLEE_H_DEFINED_glConvolutionFilter2DEXT
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONFILTER2DEXTPROC GLeeFuncPtr_glConvolutionFilter2DEXT;
  #define glConvolutionFilter2DEXT GLeeFuncPtr_glConvolutionFilter2DEXT
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameterfEXT
#define GLEE_H_DEFINED_glConvolutionParameterfEXT
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERFEXTPROC) (GLenum target, GLenum pname, GLfloat params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERFEXTPROC GLeeFuncPtr_glConvolutionParameterfEXT;
  #define glConvolutionParameterfEXT GLeeFuncPtr_glConvolutionParameterfEXT
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameterfvEXT
#define GLEE_H_DEFINED_glConvolutionParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERFVEXTPROC) (GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERFVEXTPROC GLeeFuncPtr_glConvolutionParameterfvEXT;
  #define glConvolutionParameterfvEXT GLeeFuncPtr_glConvolutionParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameteriEXT
#define GLEE_H_DEFINED_glConvolutionParameteriEXT
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERIEXTPROC) (GLenum target, GLenum pname, GLint params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERIEXTPROC GLeeFuncPtr_glConvolutionParameteriEXT;
  #define glConvolutionParameteriEXT GLeeFuncPtr_glConvolutionParameteriEXT
#endif
#ifndef GLEE_H_DEFINED_glConvolutionParameterivEXT
#define GLEE_H_DEFINED_glConvolutionParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLCONVOLUTIONPARAMETERIVEXTPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLCONVOLUTIONPARAMETERIVEXTPROC GLeeFuncPtr_glConvolutionParameterivEXT;
  #define glConvolutionParameterivEXT GLeeFuncPtr_glConvolutionParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyConvolutionFilter1DEXT
#define GLEE_H_DEFINED_glCopyConvolutionFilter1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYCONVOLUTIONFILTER1DEXTPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYCONVOLUTIONFILTER1DEXTPROC GLeeFuncPtr_glCopyConvolutionFilter1DEXT;
  #define glCopyConvolutionFilter1DEXT GLeeFuncPtr_glCopyConvolutionFilter1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyConvolutionFilter2DEXT
#define GLEE_H_DEFINED_glCopyConvolutionFilter2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYCONVOLUTIONFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYCONVOLUTIONFILTER2DEXTPROC GLeeFuncPtr_glCopyConvolutionFilter2DEXT;
  #define glCopyConvolutionFilter2DEXT GLeeFuncPtr_glCopyConvolutionFilter2DEXT
#endif
#ifndef GLEE_H_DEFINED_glGetConvolutionFilterEXT
#define GLEE_H_DEFINED_glGetConvolutionFilterEXT
  typedef void (APIENTRYP GLEEPFNGLGETCONVOLUTIONFILTEREXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid * image);
  GLEE_EXTERN GLEEPFNGLGETCONVOLUTIONFILTEREXTPROC GLeeFuncPtr_glGetConvolutionFilterEXT;
  #define glGetConvolutionFilterEXT GLeeFuncPtr_glGetConvolutionFilterEXT
#endif
#ifndef GLEE_H_DEFINED_glGetConvolutionParameterfvEXT
#define GLEE_H_DEFINED_glGetConvolutionParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETCONVOLUTIONPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCONVOLUTIONPARAMETERFVEXTPROC GLeeFuncPtr_glGetConvolutionParameterfvEXT;
  #define glGetConvolutionParameterfvEXT GLeeFuncPtr_glGetConvolutionParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetConvolutionParameterivEXT
#define GLEE_H_DEFINED_glGetConvolutionParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETCONVOLUTIONPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETCONVOLUTIONPARAMETERIVEXTPROC GLeeFuncPtr_glGetConvolutionParameterivEXT;
  #define glGetConvolutionParameterivEXT GLeeFuncPtr_glGetConvolutionParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetSeparableFilterEXT
#define GLEE_H_DEFINED_glGetSeparableFilterEXT
  typedef void (APIENTRYP GLEEPFNGLGETSEPARABLEFILTEREXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span);
  GLEE_EXTERN GLEEPFNGLGETSEPARABLEFILTEREXTPROC GLeeFuncPtr_glGetSeparableFilterEXT;
  #define glGetSeparableFilterEXT GLeeFuncPtr_glGetSeparableFilterEXT
#endif
#ifndef GLEE_H_DEFINED_glSeparableFilter2DEXT
#define GLEE_H_DEFINED_glSeparableFilter2DEXT
  typedef void (APIENTRYP GLEEPFNGLSEPARABLEFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column);
  GLEE_EXTERN GLEEPFNGLSEPARABLEFILTER2DEXTPROC GLeeFuncPtr_glSeparableFilter2DEXT;
  #define glSeparableFilter2DEXT GLeeFuncPtr_glSeparableFilter2DEXT
#endif
#endif

/* GL_SGI_color_matrix */

#ifndef GL_SGI_color_matrix
#define GL_SGI_color_matrix 1
#define __GLEE_GL_SGI_color_matrix 1
/* Constants */
#define GL_COLOR_MATRIX_SGI                                0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI                    0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI                0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI                 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI               0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI                0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI               0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI                  0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI                0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI                 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI                0x80BB
#endif

/* GL_SGI_color_table */

#ifndef GL_SGI_color_table
#define GL_SGI_color_table 1
#define __GLEE_GL_SGI_color_table 1
/* Constants */
#define GL_COLOR_TABLE_SGI                                 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI                0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI               0x80D2
#define GL_PROXY_COLOR_TABLE_SGI                           0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI          0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI         0x80D5
#define GL_COLOR_TABLE_SCALE_SGI                           0x80D6
#define GL_COLOR_TABLE_BIAS_SGI                            0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI                          0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI                           0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI                        0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI                      0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI                       0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI                      0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI                  0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI                  0x80DF
#ifndef GLEE_H_DEFINED_glColorTableSGI
#define GLEE_H_DEFINED_glColorTableSGI
  typedef void (APIENTRYP GLEEPFNGLCOLORTABLESGIPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
  GLEE_EXTERN GLEEPFNGLCOLORTABLESGIPROC GLeeFuncPtr_glColorTableSGI;
  #define glColorTableSGI GLeeFuncPtr_glColorTableSGI
#endif
#ifndef GLEE_H_DEFINED_glColorTableParameterfvSGI
#define GLEE_H_DEFINED_glColorTableParameterfvSGI
  typedef void (APIENTRYP GLEEPFNGLCOLORTABLEPARAMETERFVSGIPROC) (GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLCOLORTABLEPARAMETERFVSGIPROC GLeeFuncPtr_glColorTableParameterfvSGI;
  #define glColorTableParameterfvSGI GLeeFuncPtr_glColorTableParameterfvSGI
#endif
#ifndef GLEE_H_DEFINED_glColorTableParameterivSGI
#define GLEE_H_DEFINED_glColorTableParameterivSGI
  typedef void (APIENTRYP GLEEPFNGLCOLORTABLEPARAMETERIVSGIPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLCOLORTABLEPARAMETERIVSGIPROC GLeeFuncPtr_glColorTableParameterivSGI;
  #define glColorTableParameterivSGI GLeeFuncPtr_glColorTableParameterivSGI
#endif
#ifndef GLEE_H_DEFINED_glCopyColorTableSGI
#define GLEE_H_DEFINED_glCopyColorTableSGI
  typedef void (APIENTRYP GLEEPFNGLCOPYCOLORTABLESGIPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYCOLORTABLESGIPROC GLeeFuncPtr_glCopyColorTableSGI;
  #define glCopyColorTableSGI GLeeFuncPtr_glCopyColorTableSGI
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableSGI
#define GLEE_H_DEFINED_glGetColorTableSGI
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLESGIPROC) (GLenum target, GLenum format, GLenum type, GLvoid * table);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLESGIPROC GLeeFuncPtr_glGetColorTableSGI;
  #define glGetColorTableSGI GLeeFuncPtr_glGetColorTableSGI
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableParameterfvSGI
#define GLEE_H_DEFINED_glGetColorTableParameterfvSGI
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEPARAMETERFVSGIPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEPARAMETERFVSGIPROC GLeeFuncPtr_glGetColorTableParameterfvSGI;
  #define glGetColorTableParameterfvSGI GLeeFuncPtr_glGetColorTableParameterfvSGI
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableParameterivSGI
#define GLEE_H_DEFINED_glGetColorTableParameterivSGI
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEPARAMETERIVSGIPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEPARAMETERIVSGIPROC GLeeFuncPtr_glGetColorTableParameterivSGI;
  #define glGetColorTableParameterivSGI GLeeFuncPtr_glGetColorTableParameterivSGI
#endif
#endif

/* GL_SGIS_pixel_texture */

#ifndef GL_SGIS_pixel_texture
#define GL_SGIS_pixel_texture 1
#define __GLEE_GL_SGIS_pixel_texture 1
/* Constants */
#define GL_PIXEL_TEXTURE_SGIS                              0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS                  0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS                0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS                          0x8356
#ifndef GLEE_H_DEFINED_glPixelTexGenParameteriSGIS
#define GLEE_H_DEFINED_glPixelTexGenParameteriSGIS
  typedef void (APIENTRYP GLEEPFNGLPIXELTEXGENPARAMETERISGISPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLPIXELTEXGENPARAMETERISGISPROC GLeeFuncPtr_glPixelTexGenParameteriSGIS;
  #define glPixelTexGenParameteriSGIS GLeeFuncPtr_glPixelTexGenParameteriSGIS
#endif
#ifndef GLEE_H_DEFINED_glPixelTexGenParameterivSGIS
#define GLEE_H_DEFINED_glPixelTexGenParameterivSGIS
  typedef void (APIENTRYP GLEEPFNGLPIXELTEXGENPARAMETERIVSGISPROC) (GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPIXELTEXGENPARAMETERIVSGISPROC GLeeFuncPtr_glPixelTexGenParameterivSGIS;
  #define glPixelTexGenParameterivSGIS GLeeFuncPtr_glPixelTexGenParameterivSGIS
#endif
#ifndef GLEE_H_DEFINED_glPixelTexGenParameterfSGIS
#define GLEE_H_DEFINED_glPixelTexGenParameterfSGIS
  typedef void (APIENTRYP GLEEPFNGLPIXELTEXGENPARAMETERFSGISPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLPIXELTEXGENPARAMETERFSGISPROC GLeeFuncPtr_glPixelTexGenParameterfSGIS;
  #define glPixelTexGenParameterfSGIS GLeeFuncPtr_glPixelTexGenParameterfSGIS
#endif
#ifndef GLEE_H_DEFINED_glPixelTexGenParameterfvSGIS
#define GLEE_H_DEFINED_glPixelTexGenParameterfvSGIS
  typedef void (APIENTRYP GLEEPFNGLPIXELTEXGENPARAMETERFVSGISPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPIXELTEXGENPARAMETERFVSGISPROC GLeeFuncPtr_glPixelTexGenParameterfvSGIS;
  #define glPixelTexGenParameterfvSGIS GLeeFuncPtr_glPixelTexGenParameterfvSGIS
#endif
#ifndef GLEE_H_DEFINED_glGetPixelTexGenParameterivSGIS
#define GLEE_H_DEFINED_glGetPixelTexGenParameterivSGIS
  typedef void (APIENTRYP GLEEPFNGLGETPIXELTEXGENPARAMETERIVSGISPROC) (GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETPIXELTEXGENPARAMETERIVSGISPROC GLeeFuncPtr_glGetPixelTexGenParameterivSGIS;
  #define glGetPixelTexGenParameterivSGIS GLeeFuncPtr_glGetPixelTexGenParameterivSGIS
#endif
#ifndef GLEE_H_DEFINED_glGetPixelTexGenParameterfvSGIS
#define GLEE_H_DEFINED_glGetPixelTexGenParameterfvSGIS
  typedef void (APIENTRYP GLEEPFNGLGETPIXELTEXGENPARAMETERFVSGISPROC) (GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETPIXELTEXGENPARAMETERFVSGISPROC GLeeFuncPtr_glGetPixelTexGenParameterfvSGIS;
  #define glGetPixelTexGenParameterfvSGIS GLeeFuncPtr_glGetPixelTexGenParameterfvSGIS
#endif
#endif

/* GL_SGIX_pixel_texture */

#ifndef GL_SGIX_pixel_texture
#define GL_SGIX_pixel_texture 1
#define __GLEE_GL_SGIX_pixel_texture 1
/* Constants */
#define GL_PIXEL_TEX_GEN_SGIX                              0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX                         0x832B
#ifndef GLEE_H_DEFINED_glPixelTexGenSGIX
#define GLEE_H_DEFINED_glPixelTexGenSGIX
  typedef void (APIENTRYP GLEEPFNGLPIXELTEXGENSGIXPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLPIXELTEXGENSGIXPROC GLeeFuncPtr_glPixelTexGenSGIX;
  #define glPixelTexGenSGIX GLeeFuncPtr_glPixelTexGenSGIX
#endif
#endif

/* GL_SGIS_texture4D */

#ifndef GL_SGIS_texture4D
#define GL_SGIS_texture4D 1
#define __GLEE_GL_SGIS_texture4D 1
/* Constants */
#define GL_PACK_SKIP_VOLUMES_SGIS                          0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS                           0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS                        0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS                         0x8133
#define GL_TEXTURE_4D_SGIS                                 0x8134
#define GL_PROXY_TEXTURE_4D_SGIS                           0x8135
#define GL_TEXTURE_4DSIZE_SGIS                             0x8136
#define GL_TEXTURE_WRAP_Q_SGIS                             0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS                        0x8138
#define GL_TEXTURE_4D_BINDING_SGIS                         0x814F
#ifndef GLEE_H_DEFINED_glTexImage4DSGIS
#define GLEE_H_DEFINED_glTexImage4DSGIS
  typedef void (APIENTRYP GLEEPFNGLTEXIMAGE4DSGISPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXIMAGE4DSGISPROC GLeeFuncPtr_glTexImage4DSGIS;
  #define glTexImage4DSGIS GLeeFuncPtr_glTexImage4DSGIS
#endif
#ifndef GLEE_H_DEFINED_glTexSubImage4DSGIS
#define GLEE_H_DEFINED_glTexSubImage4DSGIS
  typedef void (APIENTRYP GLEEPFNGLTEXSUBIMAGE4DSGISPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXSUBIMAGE4DSGISPROC GLeeFuncPtr_glTexSubImage4DSGIS;
  #define glTexSubImage4DSGIS GLeeFuncPtr_glTexSubImage4DSGIS
#endif
#endif

/* GL_SGI_texture_color_table */

#ifndef GL_SGI_texture_color_table
#define GL_SGI_texture_color_table 1
#define __GLEE_GL_SGI_texture_color_table 1
/* Constants */
#define GL_TEXTURE_COLOR_TABLE_SGI                         0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI                   0x80BD
#endif

/* GL_EXT_cmyka */

#ifndef GL_EXT_cmyka
#define GL_EXT_cmyka 1
#define __GLEE_GL_EXT_cmyka 1
/* Constants */
#define GL_CMYK_EXT                                        0x800C
#define GL_CMYKA_EXT                                       0x800D
#define GL_PACK_CMYK_HINT_EXT                              0x800E
#define GL_UNPACK_CMYK_HINT_EXT                            0x800F
#endif

/* GL_EXT_texture_object */

#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
#define __GLEE_GL_EXT_texture_object 1
/* Constants */
#define GL_TEXTURE_PRIORITY_EXT                            0x8066
#define GL_TEXTURE_RESIDENT_EXT                            0x8067
#define GL_TEXTURE_1D_BINDING_EXT                          0x8068
#define GL_TEXTURE_2D_BINDING_EXT                          0x8069
#define GL_TEXTURE_3D_BINDING_EXT                          0x806A
#ifndef GLEE_H_DEFINED_glAreTexturesResidentEXT
#define GLEE_H_DEFINED_glAreTexturesResidentEXT
  typedef GLboolean (APIENTRYP GLEEPFNGLARETEXTURESRESIDENTEXTPROC) (GLsizei n, const GLuint * textures, GLboolean * residences);
  GLEE_EXTERN GLEEPFNGLARETEXTURESRESIDENTEXTPROC GLeeFuncPtr_glAreTexturesResidentEXT;
  #define glAreTexturesResidentEXT GLeeFuncPtr_glAreTexturesResidentEXT
#endif
#ifndef GLEE_H_DEFINED_glBindTextureEXT
#define GLEE_H_DEFINED_glBindTextureEXT
  typedef void (APIENTRYP GLEEPFNGLBINDTEXTUREEXTPROC) (GLenum target, GLuint texture);
  GLEE_EXTERN GLEEPFNGLBINDTEXTUREEXTPROC GLeeFuncPtr_glBindTextureEXT;
  #define glBindTextureEXT GLeeFuncPtr_glBindTextureEXT
#endif
#ifndef GLEE_H_DEFINED_glDeleteTexturesEXT
#define GLEE_H_DEFINED_glDeleteTexturesEXT
  typedef void (APIENTRYP GLEEPFNGLDELETETEXTURESEXTPROC) (GLsizei n, const GLuint * textures);
  GLEE_EXTERN GLEEPFNGLDELETETEXTURESEXTPROC GLeeFuncPtr_glDeleteTexturesEXT;
  #define glDeleteTexturesEXT GLeeFuncPtr_glDeleteTexturesEXT
#endif
#ifndef GLEE_H_DEFINED_glGenTexturesEXT
#define GLEE_H_DEFINED_glGenTexturesEXT
  typedef void (APIENTRYP GLEEPFNGLGENTEXTURESEXTPROC) (GLsizei n, GLuint * textures);
  GLEE_EXTERN GLEEPFNGLGENTEXTURESEXTPROC GLeeFuncPtr_glGenTexturesEXT;
  #define glGenTexturesEXT GLeeFuncPtr_glGenTexturesEXT
#endif
#ifndef GLEE_H_DEFINED_glIsTextureEXT
#define GLEE_H_DEFINED_glIsTextureEXT
  typedef GLboolean (APIENTRYP GLEEPFNGLISTEXTUREEXTPROC) (GLuint texture);
  GLEE_EXTERN GLEEPFNGLISTEXTUREEXTPROC GLeeFuncPtr_glIsTextureEXT;
  #define glIsTextureEXT GLeeFuncPtr_glIsTextureEXT
#endif
#ifndef GLEE_H_DEFINED_glPrioritizeTexturesEXT
#define GLEE_H_DEFINED_glPrioritizeTexturesEXT
  typedef void (APIENTRYP GLEEPFNGLPRIORITIZETEXTURESEXTPROC) (GLsizei n, const GLuint * textures, const GLclampf * priorities);
  GLEE_EXTERN GLEEPFNGLPRIORITIZETEXTURESEXTPROC GLeeFuncPtr_glPrioritizeTexturesEXT;
  #define glPrioritizeTexturesEXT GLeeFuncPtr_glPrioritizeTexturesEXT
#endif
#endif

/* GL_SGIS_detail_texture */

#ifndef GL_SGIS_detail_texture
#define GL_SGIS_detail_texture 1
#define __GLEE_GL_SGIS_detail_texture 1
/* Constants */
#define GL_DETAIL_TEXTURE_2D_SGIS                          0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS                  0x8096
#define GL_LINEAR_DETAIL_SGIS                              0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS                        0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS                        0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS                       0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS                        0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS                 0x809C
#ifndef GLEE_H_DEFINED_glDetailTexFuncSGIS
#define GLEE_H_DEFINED_glDetailTexFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLDETAILTEXFUNCSGISPROC) (GLenum target, GLsizei n, const GLfloat * points);
  GLEE_EXTERN GLEEPFNGLDETAILTEXFUNCSGISPROC GLeeFuncPtr_glDetailTexFuncSGIS;
  #define glDetailTexFuncSGIS GLeeFuncPtr_glDetailTexFuncSGIS
#endif
#ifndef GLEE_H_DEFINED_glGetDetailTexFuncSGIS
#define GLEE_H_DEFINED_glGetDetailTexFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLGETDETAILTEXFUNCSGISPROC) (GLenum target, GLfloat * points);
  GLEE_EXTERN GLEEPFNGLGETDETAILTEXFUNCSGISPROC GLeeFuncPtr_glGetDetailTexFuncSGIS;
  #define glGetDetailTexFuncSGIS GLeeFuncPtr_glGetDetailTexFuncSGIS
#endif
#endif

/* GL_SGIS_sharpen_texture */

#ifndef GL_SGIS_sharpen_texture
#define GL_SGIS_sharpen_texture 1
#define __GLEE_GL_SGIS_sharpen_texture 1
/* Constants */
#define GL_LINEAR_SHARPEN_SGIS                             0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS                       0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS                       0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS                0x80B0
#ifndef GLEE_H_DEFINED_glSharpenTexFuncSGIS
#define GLEE_H_DEFINED_glSharpenTexFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLSHARPENTEXFUNCSGISPROC) (GLenum target, GLsizei n, const GLfloat * points);
  GLEE_EXTERN GLEEPFNGLSHARPENTEXFUNCSGISPROC GLeeFuncPtr_glSharpenTexFuncSGIS;
  #define glSharpenTexFuncSGIS GLeeFuncPtr_glSharpenTexFuncSGIS
#endif
#ifndef GLEE_H_DEFINED_glGetSharpenTexFuncSGIS
#define GLEE_H_DEFINED_glGetSharpenTexFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLGETSHARPENTEXFUNCSGISPROC) (GLenum target, GLfloat * points);
  GLEE_EXTERN GLEEPFNGLGETSHARPENTEXFUNCSGISPROC GLeeFuncPtr_glGetSharpenTexFuncSGIS;
  #define glGetSharpenTexFuncSGIS GLeeFuncPtr_glGetSharpenTexFuncSGIS
#endif
#endif

/* GL_EXT_packed_pixels */

#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels 1
#define __GLEE_GL_EXT_packed_pixels 1
/* Constants */
#define GL_UNSIGNED_BYTE_3_3_2_EXT                         0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT                      0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT                      0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT                        0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT                     0x8036
#endif

/* GL_SGIS_texture_lod */

#ifndef GL_SGIS_texture_lod
#define GL_SGIS_texture_lod 1
#define __GLEE_GL_SGIS_texture_lod 1
/* Constants */
#define GL_TEXTURE_MIN_LOD_SGIS                            0x813A
#define GL_TEXTURE_MAX_LOD_SGIS                            0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS                         0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS                          0x813D
#endif

/* GL_SGIS_multisample */

#ifndef GL_SGIS_multisample
#define GL_SGIS_multisample 1
#define __GLEE_GL_SGIS_multisample 1
/* Constants */
#define GL_MULTISAMPLE_SGIS                                0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS                       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS                        0x809F
#define GL_SAMPLE_MASK_SGIS                                0x80A0
#define GL_1PASS_SGIS                                      0x80A1
#define GL_2PASS_0_SGIS                                    0x80A2
#define GL_2PASS_1_SGIS                                    0x80A3
#define GL_4PASS_0_SGIS                                    0x80A4
#define GL_4PASS_1_SGIS                                    0x80A5
#define GL_4PASS_2_SGIS                                    0x80A6
#define GL_4PASS_3_SGIS                                    0x80A7
#define GL_SAMPLE_BUFFERS_SGIS                             0x80A8
#define GL_SAMPLES_SGIS                                    0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS                          0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS                         0x80AB
#define GL_SAMPLE_PATTERN_SGIS                             0x80AC
#ifndef GLEE_H_DEFINED_glSampleMaskSGIS
#define GLEE_H_DEFINED_glSampleMaskSGIS
  typedef void (APIENTRYP GLEEPFNGLSAMPLEMASKSGISPROC) (GLclampf value, GLboolean invert);
  GLEE_EXTERN GLEEPFNGLSAMPLEMASKSGISPROC GLeeFuncPtr_glSampleMaskSGIS;
  #define glSampleMaskSGIS GLeeFuncPtr_glSampleMaskSGIS
#endif
#ifndef GLEE_H_DEFINED_glSamplePatternSGIS
#define GLEE_H_DEFINED_glSamplePatternSGIS
  typedef void (APIENTRYP GLEEPFNGLSAMPLEPATTERNSGISPROC) (GLenum pattern);
  GLEE_EXTERN GLEEPFNGLSAMPLEPATTERNSGISPROC GLeeFuncPtr_glSamplePatternSGIS;
  #define glSamplePatternSGIS GLeeFuncPtr_glSamplePatternSGIS
#endif
#endif

/* GL_EXT_rescale_normal */

#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal 1
#define __GLEE_GL_EXT_rescale_normal 1
/* Constants */
#define GL_RESCALE_NORMAL_EXT                              0x803A
#endif

/* GL_EXT_vertex_array */

#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
#define __GLEE_GL_EXT_vertex_array 1
/* Constants */
#define GL_VERTEX_ARRAY_EXT                                0x8074
#define GL_NORMAL_ARRAY_EXT                                0x8075
#define GL_COLOR_ARRAY_EXT                                 0x8076
#define GL_INDEX_ARRAY_EXT                                 0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT                         0x8078
#define GL_EDGE_FLAG_ARRAY_EXT                             0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT                           0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT                           0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT                         0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT                          0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT                           0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT                         0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT                          0x8080
#define GL_COLOR_ARRAY_SIZE_EXT                            0x8081
#define GL_COLOR_ARRAY_TYPE_EXT                            0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT                          0x8083
#define GL_COLOR_ARRAY_COUNT_EXT                           0x8084
#define GL_INDEX_ARRAY_TYPE_EXT                            0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT                          0x8086
#define GL_INDEX_ARRAY_COUNT_EXT                           0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT                    0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT                    0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT                  0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT                   0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT                      0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT                       0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT                        0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT                        0x808F
#define GL_COLOR_ARRAY_POINTER_EXT                         0x8090
#define GL_INDEX_ARRAY_POINTER_EXT                         0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT                 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT                     0x8093
#ifndef GLEE_H_DEFINED_glArrayElementEXT
#define GLEE_H_DEFINED_glArrayElementEXT
  typedef void (APIENTRYP GLEEPFNGLARRAYELEMENTEXTPROC) (GLint i);
  GLEE_EXTERN GLEEPFNGLARRAYELEMENTEXTPROC GLeeFuncPtr_glArrayElementEXT;
  #define glArrayElementEXT GLeeFuncPtr_glArrayElementEXT
#endif
#ifndef GLEE_H_DEFINED_glColorPointerEXT
#define GLEE_H_DEFINED_glColorPointerEXT
  typedef void (APIENTRYP GLEEPFNGLCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLCOLORPOINTEREXTPROC GLeeFuncPtr_glColorPointerEXT;
  #define glColorPointerEXT GLeeFuncPtr_glColorPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glDrawArraysEXT
#define GLEE_H_DEFINED_glDrawArraysEXT
  typedef void (APIENTRYP GLEEPFNGLDRAWARRAYSEXTPROC) (GLenum mode, GLint first, GLsizei count);
  GLEE_EXTERN GLEEPFNGLDRAWARRAYSEXTPROC GLeeFuncPtr_glDrawArraysEXT;
  #define glDrawArraysEXT GLeeFuncPtr_glDrawArraysEXT
#endif
#ifndef GLEE_H_DEFINED_glEdgeFlagPointerEXT
#define GLEE_H_DEFINED_glEdgeFlagPointerEXT
  typedef void (APIENTRYP GLEEPFNGLEDGEFLAGPOINTEREXTPROC) (GLsizei stride, GLsizei count, const GLboolean * pointer);
  GLEE_EXTERN GLEEPFNGLEDGEFLAGPOINTEREXTPROC GLeeFuncPtr_glEdgeFlagPointerEXT;
  #define glEdgeFlagPointerEXT GLeeFuncPtr_glEdgeFlagPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glGetPointervEXT
#define GLEE_H_DEFINED_glGetPointervEXT
  typedef void (APIENTRYP GLEEPFNGLGETPOINTERVEXTPROC) (GLenum pname, GLvoid* * params);
  GLEE_EXTERN GLEEPFNGLGETPOINTERVEXTPROC GLeeFuncPtr_glGetPointervEXT;
  #define glGetPointervEXT GLeeFuncPtr_glGetPointervEXT
#endif
#ifndef GLEE_H_DEFINED_glIndexPointerEXT
#define GLEE_H_DEFINED_glIndexPointerEXT
  typedef void (APIENTRYP GLEEPFNGLINDEXPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLINDEXPOINTEREXTPROC GLeeFuncPtr_glIndexPointerEXT;
  #define glIndexPointerEXT GLeeFuncPtr_glIndexPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glNormalPointerEXT
#define GLEE_H_DEFINED_glNormalPointerEXT
  typedef void (APIENTRYP GLEEPFNGLNORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLNORMALPOINTEREXTPROC GLeeFuncPtr_glNormalPointerEXT;
  #define glNormalPointerEXT GLeeFuncPtr_glNormalPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glTexCoordPointerEXT
#define GLEE_H_DEFINED_glTexCoordPointerEXT
  typedef void (APIENTRYP GLEEPFNGLTEXCOORDPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLTEXCOORDPOINTEREXTPROC GLeeFuncPtr_glTexCoordPointerEXT;
  #define glTexCoordPointerEXT GLeeFuncPtr_glTexCoordPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexPointerEXT
#define GLEE_H_DEFINED_glVertexPointerEXT
  typedef void (APIENTRYP GLEEPFNGLVERTEXPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXPOINTEREXTPROC GLeeFuncPtr_glVertexPointerEXT;
  #define glVertexPointerEXT GLeeFuncPtr_glVertexPointerEXT
#endif
#endif

/* GL_EXT_misc_attribute */

#ifndef GL_EXT_misc_attribute
#define GL_EXT_misc_attribute 1
#define __GLEE_GL_EXT_misc_attribute 1
/* Constants */
#endif

/* GL_SGIS_generate_mipmap */

#ifndef GL_SGIS_generate_mipmap
#define GL_SGIS_generate_mipmap 1
#define __GLEE_GL_SGIS_generate_mipmap 1
/* Constants */
#define GL_GENERATE_MIPMAP_SGIS                            0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS                       0x8192
#endif

/* GL_SGIX_clipmap */

#ifndef GL_SGIX_clipmap
#define GL_SGIX_clipmap 1
#define __GLEE_GL_SGIX_clipmap 1
/* Constants */
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX                      0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX                     0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX                      0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX                     0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX              0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX                 0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX                      0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX                          0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX                  0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX                    0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX                     0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX                     0x844F
#endif

/* GL_SGIX_shadow */

#ifndef GL_SGIX_shadow
#define GL_SGIX_shadow 1
#define __GLEE_GL_SGIX_shadow 1
/* Constants */
#define GL_TEXTURE_COMPARE_SGIX                            0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX                   0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX                           0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX                           0x819D
#endif

/* GL_SGIS_texture_edge_clamp */

#ifndef GL_SGIS_texture_edge_clamp
#define GL_SGIS_texture_edge_clamp 1
#define __GLEE_GL_SGIS_texture_edge_clamp 1
/* Constants */
#define GL_CLAMP_TO_EDGE_SGIS                              0x812F
#endif

/* GL_SGIS_texture_border_clamp */

#ifndef GL_SGIS_texture_border_clamp
#define GL_SGIS_texture_border_clamp 1
#define __GLEE_GL_SGIS_texture_border_clamp 1
/* Constants */
#define GL_CLAMP_TO_BORDER_SGIS                            0x812D
#endif

/* GL_EXT_blend_minmax */

#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
#define __GLEE_GL_EXT_blend_minmax 1
/* Constants */
#define GL_FUNC_ADD_EXT                                    0x8006
#define GL_MIN_EXT                                         0x8007
#define GL_MAX_EXT                                         0x8008
#define GL_BLEND_EQUATION_EXT                              0x8009
#ifndef GLEE_H_DEFINED_glBlendEquationEXT
#define GLEE_H_DEFINED_glBlendEquationEXT
  typedef void (APIENTRYP GLEEPFNGLBLENDEQUATIONEXTPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLBLENDEQUATIONEXTPROC GLeeFuncPtr_glBlendEquationEXT;
  #define glBlendEquationEXT GLeeFuncPtr_glBlendEquationEXT
#endif
#endif

/* GL_EXT_blend_subtract */

#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract 1
#define __GLEE_GL_EXT_blend_subtract 1
/* Constants */
#define GL_FUNC_SUBTRACT_EXT                               0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT                       0x800B
#endif

/* GL_EXT_blend_logic_op */

#ifndef GL_EXT_blend_logic_op
#define GL_EXT_blend_logic_op 1
#define __GLEE_GL_EXT_blend_logic_op 1
/* Constants */
#endif

/* GL_SGIX_interlace */

#ifndef GL_SGIX_interlace
#define GL_SGIX_interlace 1
#define __GLEE_GL_SGIX_interlace 1
/* Constants */
#define GL_INTERLACE_SGIX                                  0x8094
#endif

/* GL_SGIX_pixel_tiles */

#ifndef GL_SGIX_pixel_tiles
#define GL_SGIX_pixel_tiles 1
#define __GLEE_GL_SGIX_pixel_tiles 1
/* Constants */
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX                  0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX                 0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX                           0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX                          0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX                      0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX                     0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX                      0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX                      0x8145
#endif

/* GL_SGIS_texture_select */

#ifndef GL_SGIS_texture_select
#define GL_SGIS_texture_select 1
#define __GLEE_GL_SGIS_texture_select 1
/* Constants */
#define GL_DUAL_ALPHA4_SGIS                                0x8110
#define GL_DUAL_ALPHA8_SGIS                                0x8111
#define GL_DUAL_ALPHA12_SGIS                               0x8112
#define GL_DUAL_ALPHA16_SGIS                               0x8113
#define GL_DUAL_LUMINANCE4_SGIS                            0x8114
#define GL_DUAL_LUMINANCE8_SGIS                            0x8115
#define GL_DUAL_LUMINANCE12_SGIS                           0x8116
#define GL_DUAL_LUMINANCE16_SGIS                           0x8117
#define GL_DUAL_INTENSITY4_SGIS                            0x8118
#define GL_DUAL_INTENSITY8_SGIS                            0x8119
#define GL_DUAL_INTENSITY12_SGIS                           0x811A
#define GL_DUAL_INTENSITY16_SGIS                           0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS                      0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS                      0x811D
#define GL_QUAD_ALPHA4_SGIS                                0x811E
#define GL_QUAD_ALPHA8_SGIS                                0x811F
#define GL_QUAD_LUMINANCE4_SGIS                            0x8120
#define GL_QUAD_LUMINANCE8_SGIS                            0x8121
#define GL_QUAD_INTENSITY4_SGIS                            0x8122
#define GL_QUAD_INTENSITY8_SGIS                            0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS                        0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS                        0x8125
#endif

/* GL_SGIX_sprite */

#ifndef GL_SGIX_sprite
#define GL_SGIX_sprite 1
#define __GLEE_GL_SGIX_sprite 1
/* Constants */
#define GL_SPRITE_SGIX                                     0x8148
#define GL_SPRITE_MODE_SGIX                                0x8149
#define GL_SPRITE_AXIS_SGIX                                0x814A
#define GL_SPRITE_TRANSLATION_SGIX                         0x814B
#define GL_SPRITE_AXIAL_SGIX                               0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX                      0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX                         0x814E
#ifndef GLEE_H_DEFINED_glSpriteParameterfSGIX
#define GLEE_H_DEFINED_glSpriteParameterfSGIX
  typedef void (APIENTRYP GLEEPFNGLSPRITEPARAMETERFSGIXPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLSPRITEPARAMETERFSGIXPROC GLeeFuncPtr_glSpriteParameterfSGIX;
  #define glSpriteParameterfSGIX GLeeFuncPtr_glSpriteParameterfSGIX
#endif
#ifndef GLEE_H_DEFINED_glSpriteParameterfvSGIX
#define GLEE_H_DEFINED_glSpriteParameterfvSGIX
  typedef void (APIENTRYP GLEEPFNGLSPRITEPARAMETERFVSGIXPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLSPRITEPARAMETERFVSGIXPROC GLeeFuncPtr_glSpriteParameterfvSGIX;
  #define glSpriteParameterfvSGIX GLeeFuncPtr_glSpriteParameterfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glSpriteParameteriSGIX
#define GLEE_H_DEFINED_glSpriteParameteriSGIX
  typedef void (APIENTRYP GLEEPFNGLSPRITEPARAMETERISGIXPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLSPRITEPARAMETERISGIXPROC GLeeFuncPtr_glSpriteParameteriSGIX;
  #define glSpriteParameteriSGIX GLeeFuncPtr_glSpriteParameteriSGIX
#endif
#ifndef GLEE_H_DEFINED_glSpriteParameterivSGIX
#define GLEE_H_DEFINED_glSpriteParameterivSGIX
  typedef void (APIENTRYP GLEEPFNGLSPRITEPARAMETERIVSGIXPROC) (GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLSPRITEPARAMETERIVSGIXPROC GLeeFuncPtr_glSpriteParameterivSGIX;
  #define glSpriteParameterivSGIX GLeeFuncPtr_glSpriteParameterivSGIX
#endif
#endif

/* GL_SGIX_texture_multi_buffer */

#ifndef GL_SGIX_texture_multi_buffer
#define GL_SGIX_texture_multi_buffer 1
#define __GLEE_GL_SGIX_texture_multi_buffer 1
/* Constants */
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX                  0x812E
#endif

/* GL_EXT_point_parameters */

#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
#define __GLEE_GL_EXT_point_parameters 1
/* Constants */
#define GL_POINT_SIZE_MIN_EXT                              0x8126
#define GL_POINT_SIZE_MAX_EXT                              0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT                   0x8128
#define GL_DISTANCE_ATTENUATION_EXT                        0x8129
#ifndef GLEE_H_DEFINED_glPointParameterfEXT
#define GLEE_H_DEFINED_glPointParameterfEXT
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFEXTPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFEXTPROC GLeeFuncPtr_glPointParameterfEXT;
  #define glPointParameterfEXT GLeeFuncPtr_glPointParameterfEXT
#endif
#ifndef GLEE_H_DEFINED_glPointParameterfvEXT
#define GLEE_H_DEFINED_glPointParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFVEXTPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFVEXTPROC GLeeFuncPtr_glPointParameterfvEXT;
  #define glPointParameterfvEXT GLeeFuncPtr_glPointParameterfvEXT
#endif
#endif

/* GL_SGIS_point_parameters */

#ifndef GL_SGIS_point_parameters
#define GL_SGIS_point_parameters 1
#define __GLEE_GL_SGIS_point_parameters 1
/* Constants */
#define GL_POINT_SIZE_MIN_SGIS                             0x8126
#define GL_POINT_SIZE_MAX_SGIS                             0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS                  0x8128
#define GL_DISTANCE_ATTENUATION_SGIS                       0x8129
#ifndef GLEE_H_DEFINED_glPointParameterfSGIS
#define GLEE_H_DEFINED_glPointParameterfSGIS
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFSGISPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFSGISPROC GLeeFuncPtr_glPointParameterfSGIS;
  #define glPointParameterfSGIS GLeeFuncPtr_glPointParameterfSGIS
#endif
#ifndef GLEE_H_DEFINED_glPointParameterfvSGIS
#define GLEE_H_DEFINED_glPointParameterfvSGIS
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERFVSGISPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERFVSGISPROC GLeeFuncPtr_glPointParameterfvSGIS;
  #define glPointParameterfvSGIS GLeeFuncPtr_glPointParameterfvSGIS
#endif
#endif

/* GL_SGIX_instruments */

#ifndef GL_SGIX_instruments
#define GL_SGIX_instruments 1
#define __GLEE_GL_SGIX_instruments 1
/* Constants */
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX                  0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX                    0x8181
#ifndef GLEE_H_DEFINED_glGetInstrumentsSGIX
#define GLEE_H_DEFINED_glGetInstrumentsSGIX
  typedef GLint (APIENTRYP GLEEPFNGLGETINSTRUMENTSSGIXPROC) ();
  GLEE_EXTERN GLEEPFNGLGETINSTRUMENTSSGIXPROC GLeeFuncPtr_glGetInstrumentsSGIX;
  #define glGetInstrumentsSGIX GLeeFuncPtr_glGetInstrumentsSGIX
#endif
#ifndef GLEE_H_DEFINED_glInstrumentsBufferSGIX
#define GLEE_H_DEFINED_glInstrumentsBufferSGIX
  typedef void (APIENTRYP GLEEPFNGLINSTRUMENTSBUFFERSGIXPROC) (GLsizei size, GLint * buffer);
  GLEE_EXTERN GLEEPFNGLINSTRUMENTSBUFFERSGIXPROC GLeeFuncPtr_glInstrumentsBufferSGIX;
  #define glInstrumentsBufferSGIX GLeeFuncPtr_glInstrumentsBufferSGIX
#endif
#ifndef GLEE_H_DEFINED_glPollInstrumentsSGIX
#define GLEE_H_DEFINED_glPollInstrumentsSGIX
  typedef GLint (APIENTRYP GLEEPFNGLPOLLINSTRUMENTSSGIXPROC) (GLint * marker_p);
  GLEE_EXTERN GLEEPFNGLPOLLINSTRUMENTSSGIXPROC GLeeFuncPtr_glPollInstrumentsSGIX;
  #define glPollInstrumentsSGIX GLeeFuncPtr_glPollInstrumentsSGIX
#endif
#ifndef GLEE_H_DEFINED_glReadInstrumentsSGIX
#define GLEE_H_DEFINED_glReadInstrumentsSGIX
  typedef void (APIENTRYP GLEEPFNGLREADINSTRUMENTSSGIXPROC) (GLint marker);
  GLEE_EXTERN GLEEPFNGLREADINSTRUMENTSSGIXPROC GLeeFuncPtr_glReadInstrumentsSGIX;
  #define glReadInstrumentsSGIX GLeeFuncPtr_glReadInstrumentsSGIX
#endif
#ifndef GLEE_H_DEFINED_glStartInstrumentsSGIX
#define GLEE_H_DEFINED_glStartInstrumentsSGIX
  typedef void (APIENTRYP GLEEPFNGLSTARTINSTRUMENTSSGIXPROC) ();
  GLEE_EXTERN GLEEPFNGLSTARTINSTRUMENTSSGIXPROC GLeeFuncPtr_glStartInstrumentsSGIX;
  #define glStartInstrumentsSGIX GLeeFuncPtr_glStartInstrumentsSGIX
#endif
#ifndef GLEE_H_DEFINED_glStopInstrumentsSGIX
#define GLEE_H_DEFINED_glStopInstrumentsSGIX
  typedef void (APIENTRYP GLEEPFNGLSTOPINSTRUMENTSSGIXPROC) (GLint marker);
  GLEE_EXTERN GLEEPFNGLSTOPINSTRUMENTSSGIXPROC GLeeFuncPtr_glStopInstrumentsSGIX;
  #define glStopInstrumentsSGIX GLeeFuncPtr_glStopInstrumentsSGIX
#endif
#endif

/* GL_SGIX_texture_scale_bias */

#ifndef GL_SGIX_texture_scale_bias
#define GL_SGIX_texture_scale_bias 1
#define __GLEE_GL_SGIX_texture_scale_bias 1
/* Constants */
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX                   0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX                  0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX             0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX            0x817C
#endif

/* GL_SGIX_framezoom */

#ifndef GL_SGIX_framezoom
#define GL_SGIX_framezoom 1
#define __GLEE_GL_SGIX_framezoom 1
/* Constants */
#define GL_FRAMEZOOM_SGIX                                  0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX                           0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX                       0x818D
#ifndef GLEE_H_DEFINED_glFrameZoomSGIX
#define GLEE_H_DEFINED_glFrameZoomSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAMEZOOMSGIXPROC) (GLint factor);
  GLEE_EXTERN GLEEPFNGLFRAMEZOOMSGIXPROC GLeeFuncPtr_glFrameZoomSGIX;
  #define glFrameZoomSGIX GLeeFuncPtr_glFrameZoomSGIX
#endif
#endif

/* GL_SGIX_tag_sample_buffer */

#ifndef GL_SGIX_tag_sample_buffer
#define GL_SGIX_tag_sample_buffer 1
#define __GLEE_GL_SGIX_tag_sample_buffer 1
/* Constants */
#ifndef GLEE_H_DEFINED_glTagSampleBufferSGIX
#define GLEE_H_DEFINED_glTagSampleBufferSGIX
  typedef void (APIENTRYP GLEEPFNGLTAGSAMPLEBUFFERSGIXPROC) ();
  GLEE_EXTERN GLEEPFNGLTAGSAMPLEBUFFERSGIXPROC GLeeFuncPtr_glTagSampleBufferSGIX;
  #define glTagSampleBufferSGIX GLeeFuncPtr_glTagSampleBufferSGIX
#endif
#endif

/* GL_FfdMaskSGIX */

#ifndef GL_FfdMaskSGIX
#define GL_FfdMaskSGIX 1
#define __GLEE_GL_FfdMaskSGIX 1
/* Constants */
#define GL_TEXTURE_DEFORMATION_BIT_SGIX                    0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX                   0x00000002
#endif

/* GL_SGIX_polynomial_ffd */

#ifndef GL_SGIX_polynomial_ffd
#define GL_SGIX_polynomial_ffd 1
#define __GLEE_GL_SGIX_polynomial_ffd 1
/* Constants */
#define GL_GEOMETRY_DEFORMATION_SGIX                       0x8194
#define GL_TEXTURE_DEFORMATION_SGIX                        0x8195
#define GL_DEFORMATIONS_MASK_SGIX                          0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX                      0x8197
#ifndef GLEE_H_DEFINED_glDeformationMap3dSGIX
#define GLEE_H_DEFINED_glDeformationMap3dSGIX
  typedef void (APIENTRYP GLEEPFNGLDEFORMATIONMAP3DSGIXPROC) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble * points);
  GLEE_EXTERN GLEEPFNGLDEFORMATIONMAP3DSGIXPROC GLeeFuncPtr_glDeformationMap3dSGIX;
  #define glDeformationMap3dSGIX GLeeFuncPtr_glDeformationMap3dSGIX
#endif
#ifndef GLEE_H_DEFINED_glDeformationMap3fSGIX
#define GLEE_H_DEFINED_glDeformationMap3fSGIX
  typedef void (APIENTRYP GLEEPFNGLDEFORMATIONMAP3FSGIXPROC) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat * points);
  GLEE_EXTERN GLEEPFNGLDEFORMATIONMAP3FSGIXPROC GLeeFuncPtr_glDeformationMap3fSGIX;
  #define glDeformationMap3fSGIX GLeeFuncPtr_glDeformationMap3fSGIX
#endif
#ifndef GLEE_H_DEFINED_glDeformSGIX
#define GLEE_H_DEFINED_glDeformSGIX
  typedef void (APIENTRYP GLEEPFNGLDEFORMSGIXPROC) (GLbitfield mask);
  GLEE_EXTERN GLEEPFNGLDEFORMSGIXPROC GLeeFuncPtr_glDeformSGIX;
  #define glDeformSGIX GLeeFuncPtr_glDeformSGIX
#endif
#ifndef GLEE_H_DEFINED_glLoadIdentityDeformationMapSGIX
#define GLEE_H_DEFINED_glLoadIdentityDeformationMapSGIX
  typedef void (APIENTRYP GLEEPFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC) (GLbitfield mask);
  GLEE_EXTERN GLEEPFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC GLeeFuncPtr_glLoadIdentityDeformationMapSGIX;
  #define glLoadIdentityDeformationMapSGIX GLeeFuncPtr_glLoadIdentityDeformationMapSGIX
#endif
#endif

/* GL_SGIX_reference_plane */

#ifndef GL_SGIX_reference_plane
#define GL_SGIX_reference_plane 1
#define __GLEE_GL_SGIX_reference_plane 1
/* Constants */
#define GL_REFERENCE_PLANE_SGIX                            0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX                   0x817E
#ifndef GLEE_H_DEFINED_glReferencePlaneSGIX
#define GLEE_H_DEFINED_glReferencePlaneSGIX
  typedef void (APIENTRYP GLEEPFNGLREFERENCEPLANESGIXPROC) (const GLdouble * equation);
  GLEE_EXTERN GLEEPFNGLREFERENCEPLANESGIXPROC GLeeFuncPtr_glReferencePlaneSGIX;
  #define glReferencePlaneSGIX GLeeFuncPtr_glReferencePlaneSGIX
#endif
#endif

/* GL_SGIX_flush_raster */

#ifndef GL_SGIX_flush_raster
#define GL_SGIX_flush_raster 1
#define __GLEE_GL_SGIX_flush_raster 1
/* Constants */
#ifndef GLEE_H_DEFINED_glFlushRasterSGIX
#define GLEE_H_DEFINED_glFlushRasterSGIX
  typedef void (APIENTRYP GLEEPFNGLFLUSHRASTERSGIXPROC) ();
  GLEE_EXTERN GLEEPFNGLFLUSHRASTERSGIXPROC GLeeFuncPtr_glFlushRasterSGIX;
  #define glFlushRasterSGIX GLeeFuncPtr_glFlushRasterSGIX
#endif
#endif

/* GL_SGIX_depth_texture */

#ifndef GL_SGIX_depth_texture
#define GL_SGIX_depth_texture 1
#define __GLEE_GL_SGIX_depth_texture 1
/* Constants */
#define GL_DEPTH_COMPONENT16_SGIX                          0x81A5
#define GL_DEPTH_COMPONENT24_SGIX                          0x81A6
#define GL_DEPTH_COMPONENT32_SGIX                          0x81A7
#endif

/* GL_SGIS_fog_function */

#ifndef GL_SGIS_fog_function
#define GL_SGIS_fog_function 1
#define __GLEE_GL_SGIS_fog_function 1
/* Constants */
#define GL_FOG_FUNC_SGIS                                   0x812A
#define GL_FOG_FUNC_POINTS_SGIS                            0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS                        0x812C
#ifndef GLEE_H_DEFINED_glFogFuncSGIS
#define GLEE_H_DEFINED_glFogFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLFOGFUNCSGISPROC) (GLsizei n, const GLfloat * points);
  GLEE_EXTERN GLEEPFNGLFOGFUNCSGISPROC GLeeFuncPtr_glFogFuncSGIS;
  #define glFogFuncSGIS GLeeFuncPtr_glFogFuncSGIS
#endif
#ifndef GLEE_H_DEFINED_glGetFogFuncSGIS
#define GLEE_H_DEFINED_glGetFogFuncSGIS
  typedef void (APIENTRYP GLEEPFNGLGETFOGFUNCSGISPROC) (GLfloat * points);
  GLEE_EXTERN GLEEPFNGLGETFOGFUNCSGISPROC GLeeFuncPtr_glGetFogFuncSGIS;
  #define glGetFogFuncSGIS GLeeFuncPtr_glGetFogFuncSGIS
#endif
#endif

/* GL_SGIX_fog_offset */

#ifndef GL_SGIX_fog_offset
#define GL_SGIX_fog_offset 1
#define __GLEE_GL_SGIX_fog_offset 1
/* Constants */
#define GL_FOG_OFFSET_SGIX                                 0x8198
#define GL_FOG_OFFSET_VALUE_SGIX                           0x8199
#endif

/* GL_HP_image_transform */

#ifndef GL_HP_image_transform
#define GL_HP_image_transform 1
#define __GLEE_GL_HP_image_transform 1
/* Constants */
#define GL_IMAGE_SCALE_X_HP                                0x8155
#define GL_IMAGE_SCALE_Y_HP                                0x8156
#define GL_IMAGE_TRANSLATE_X_HP                            0x8157
#define GL_IMAGE_TRANSLATE_Y_HP                            0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP                           0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP                        0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP                        0x815B
#define GL_IMAGE_MAG_FILTER_HP                             0x815C
#define GL_IMAGE_MIN_FILTER_HP                             0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP                           0x815E
#define GL_CUBIC_HP                                        0x815F
#define GL_AVERAGE_HP                                      0x8160
#define GL_IMAGE_TRANSFORM_2D_HP                           0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP             0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP       0x8163
#ifndef GLEE_H_DEFINED_glImageTransformParameteriHP
#define GLEE_H_DEFINED_glImageTransformParameteriHP
  typedef void (APIENTRYP GLEEPFNGLIMAGETRANSFORMPARAMETERIHPPROC) (GLenum target, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLIMAGETRANSFORMPARAMETERIHPPROC GLeeFuncPtr_glImageTransformParameteriHP;
  #define glImageTransformParameteriHP GLeeFuncPtr_glImageTransformParameteriHP
#endif
#ifndef GLEE_H_DEFINED_glImageTransformParameterfHP
#define GLEE_H_DEFINED_glImageTransformParameterfHP
  typedef void (APIENTRYP GLEEPFNGLIMAGETRANSFORMPARAMETERFHPPROC) (GLenum target, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLIMAGETRANSFORMPARAMETERFHPPROC GLeeFuncPtr_glImageTransformParameterfHP;
  #define glImageTransformParameterfHP GLeeFuncPtr_glImageTransformParameterfHP
#endif
#ifndef GLEE_H_DEFINED_glImageTransformParameterivHP
#define GLEE_H_DEFINED_glImageTransformParameterivHP
  typedef void (APIENTRYP GLEEPFNGLIMAGETRANSFORMPARAMETERIVHPPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLIMAGETRANSFORMPARAMETERIVHPPROC GLeeFuncPtr_glImageTransformParameterivHP;
  #define glImageTransformParameterivHP GLeeFuncPtr_glImageTransformParameterivHP
#endif
#ifndef GLEE_H_DEFINED_glImageTransformParameterfvHP
#define GLEE_H_DEFINED_glImageTransformParameterfvHP
  typedef void (APIENTRYP GLEEPFNGLIMAGETRANSFORMPARAMETERFVHPPROC) (GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLIMAGETRANSFORMPARAMETERFVHPPROC GLeeFuncPtr_glImageTransformParameterfvHP;
  #define glImageTransformParameterfvHP GLeeFuncPtr_glImageTransformParameterfvHP
#endif
#ifndef GLEE_H_DEFINED_glGetImageTransformParameterivHP
#define GLEE_H_DEFINED_glGetImageTransformParameterivHP
  typedef void (APIENTRYP GLEEPFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC GLeeFuncPtr_glGetImageTransformParameterivHP;
  #define glGetImageTransformParameterivHP GLeeFuncPtr_glGetImageTransformParameterivHP
#endif
#ifndef GLEE_H_DEFINED_glGetImageTransformParameterfvHP
#define GLEE_H_DEFINED_glGetImageTransformParameterfvHP
  typedef void (APIENTRYP GLEEPFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC GLeeFuncPtr_glGetImageTransformParameterfvHP;
  #define glGetImageTransformParameterfvHP GLeeFuncPtr_glGetImageTransformParameterfvHP
#endif
#endif

/* GL_HP_convolution_border_modes */

#ifndef GL_HP_convolution_border_modes
#define GL_HP_convolution_border_modes 1
#define __GLEE_GL_HP_convolution_border_modes 1
/* Constants */
#define GL_IGNORE_BORDER_HP                                0x8150
#define GL_CONSTANT_BORDER_HP                              0x8151
#define GL_REPLICATE_BORDER_HP                             0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP                     0x8154
#endif

/* GL_INGR_palette_buffer */

#ifndef GL_INGR_palette_buffer
#define GL_INGR_palette_buffer 1
#define __GLEE_GL_INGR_palette_buffer 1
/* Constants */
#endif

/* GL_SGIX_texture_add_env */

#ifndef GL_SGIX_texture_add_env
#define GL_SGIX_texture_add_env 1
#define __GLEE_GL_SGIX_texture_add_env 1
/* Constants */
#define GL_TEXTURE_ENV_BIAS_SGIX                           0x80BE
#endif

/* GL_EXT_color_subtable */

#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable 1
#define __GLEE_GL_EXT_color_subtable 1
/* Constants */
#ifndef GLEE_H_DEFINED_glColorSubTableEXT
#define GLEE_H_DEFINED_glColorSubTableEXT
  typedef void (APIENTRYP GLEEPFNGLCOLORSUBTABLEEXTPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLCOLORSUBTABLEEXTPROC GLeeFuncPtr_glColorSubTableEXT;
  #define glColorSubTableEXT GLeeFuncPtr_glColorSubTableEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyColorSubTableEXT
#define GLEE_H_DEFINED_glCopyColorSubTableEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYCOLORSUBTABLEEXTPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYCOLORSUBTABLEEXTPROC GLeeFuncPtr_glCopyColorSubTableEXT;
  #define glCopyColorSubTableEXT GLeeFuncPtr_glCopyColorSubTableEXT
#endif
#endif

/* GL_PGI_vertex_hints */

#ifndef GL_PGI_vertex_hints
#define GL_PGI_vertex_hints 1
#define __GLEE_GL_PGI_vertex_hints 1
/* Constants */
#define GL_VERTEX_DATA_HINT_PGI                            0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI                      0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI                          0x1A22C
#define GL_MAX_VERTEX_HINT_PGI                             0x1A22D
#define GL_COLOR3_BIT_PGI                                  0x00010000
#define GL_COLOR4_BIT_PGI                                  0x00020000
#define GL_EDGEFLAG_BIT_PGI                                0x00040000
#define GL_INDEX_BIT_PGI                                   0x00080000
#define GL_MAT_AMBIENT_BIT_PGI                             0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI                 0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI                             0x00400000
#define GL_MAT_EMISSION_BIT_PGI                            0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI                       0x01000000
#define GL_MAT_SHININESS_BIT_PGI                           0x02000000
#define GL_MAT_SPECULAR_BIT_PGI                            0x04000000
#define GL_NORMAL_BIT_PGI                                  0x08000000
#define GL_TEXCOORD1_BIT_PGI                               0x10000000
#define GL_TEXCOORD2_BIT_PGI                               0x20000000
#define GL_TEXCOORD3_BIT_PGI                               0x40000000
#define GL_TEXCOORD4_BIT_PGI                               0x80000000
#define GL_VERTEX23_BIT_PGI                                0x00000004
#define GL_VERTEX4_BIT_PGI                                 0x00000008
#endif

/* GL_PGI_misc_hints */

#ifndef GL_PGI_misc_hints
#define GL_PGI_misc_hints 1
#define __GLEE_GL_PGI_misc_hints 1
/* Constants */
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI                    0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI                        0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI                         0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI                      0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI                  0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI                    0x1A204
#define GL_ALWAYS_FAST_HINT_PGI                            0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI                            0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI                         0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI                         0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI                         0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI                         0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI                       0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI                        0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI                         0x1A218
#define GL_FULL_STIPPLE_HINT_PGI                           0x1A219
#define GL_CLIP_NEAR_HINT_PGI                              0x1A220
#define GL_CLIP_FAR_HINT_PGI                               0x1A221
#define GL_WIDE_LINE_HINT_PGI                              0x1A222
#define GL_BACK_NORMALS_HINT_PGI                           0x1A223
#ifndef GLEE_H_DEFINED_glHintPGI
#define GLEE_H_DEFINED_glHintPGI
  typedef void (APIENTRYP GLEEPFNGLHINTPGIPROC) (GLenum target, GLint mode);
  GLEE_EXTERN GLEEPFNGLHINTPGIPROC GLeeFuncPtr_glHintPGI;
  #define glHintPGI GLeeFuncPtr_glHintPGI
#endif
#endif

/* GL_EXT_paletted_texture */

#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1
#define __GLEE_GL_EXT_paletted_texture 1
/* Constants */
#define GL_COLOR_INDEX1_EXT                                0x80E2
#define GL_COLOR_INDEX2_EXT                                0x80E3
#define GL_COLOR_INDEX4_EXT                                0x80E4
#define GL_COLOR_INDEX8_EXT                                0x80E5
#define GL_COLOR_INDEX12_EXT                               0x80E6
#define GL_COLOR_INDEX16_EXT                               0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT                          0x80ED
#ifndef GLEE_H_DEFINED_glColorTableEXT
#define GLEE_H_DEFINED_glColorTableEXT
  typedef void (APIENTRYP GLEEPFNGLCOLORTABLEEXTPROC) (GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
  GLEE_EXTERN GLEEPFNGLCOLORTABLEEXTPROC GLeeFuncPtr_glColorTableEXT;
  #define glColorTableEXT GLeeFuncPtr_glColorTableEXT
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableEXT
#define GLEE_H_DEFINED_glGetColorTableEXT
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEEXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid * data);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEEXTPROC GLeeFuncPtr_glGetColorTableEXT;
  #define glGetColorTableEXT GLeeFuncPtr_glGetColorTableEXT
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableParameterivEXT
#define GLEE_H_DEFINED_glGetColorTableParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEPARAMETERIVEXTPROC GLeeFuncPtr_glGetColorTableParameterivEXT;
  #define glGetColorTableParameterivEXT GLeeFuncPtr_glGetColorTableParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetColorTableParameterfvEXT
#define GLEE_H_DEFINED_glGetColorTableParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETCOLORTABLEPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCOLORTABLEPARAMETERFVEXTPROC GLeeFuncPtr_glGetColorTableParameterfvEXT;
  #define glGetColorTableParameterfvEXT GLeeFuncPtr_glGetColorTableParameterfvEXT
#endif
#endif

/* GL_EXT_clip_volume_hint */

#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint 1
#define __GLEE_GL_EXT_clip_volume_hint 1
/* Constants */
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT                   0x80F0
#endif

/* GL_SGIX_list_priority */

#ifndef GL_SGIX_list_priority
#define GL_SGIX_list_priority 1
#define __GLEE_GL_SGIX_list_priority 1
/* Constants */
#define GL_LIST_PRIORITY_SGIX                              0x8182
#ifndef GLEE_H_DEFINED_glGetListParameterfvSGIX
#define GLEE_H_DEFINED_glGetListParameterfvSGIX
  typedef void (APIENTRYP GLEEPFNGLGETLISTPARAMETERFVSGIXPROC) (GLuint list, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETLISTPARAMETERFVSGIXPROC GLeeFuncPtr_glGetListParameterfvSGIX;
  #define glGetListParameterfvSGIX GLeeFuncPtr_glGetListParameterfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glGetListParameterivSGIX
#define GLEE_H_DEFINED_glGetListParameterivSGIX
  typedef void (APIENTRYP GLEEPFNGLGETLISTPARAMETERIVSGIXPROC) (GLuint list, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETLISTPARAMETERIVSGIXPROC GLeeFuncPtr_glGetListParameterivSGIX;
  #define glGetListParameterivSGIX GLeeFuncPtr_glGetListParameterivSGIX
#endif
#ifndef GLEE_H_DEFINED_glListParameterfSGIX
#define GLEE_H_DEFINED_glListParameterfSGIX
  typedef void (APIENTRYP GLEEPFNGLLISTPARAMETERFSGIXPROC) (GLuint list, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLLISTPARAMETERFSGIXPROC GLeeFuncPtr_glListParameterfSGIX;
  #define glListParameterfSGIX GLeeFuncPtr_glListParameterfSGIX
#endif
#ifndef GLEE_H_DEFINED_glListParameterfvSGIX
#define GLEE_H_DEFINED_glListParameterfvSGIX
  typedef void (APIENTRYP GLEEPFNGLLISTPARAMETERFVSGIXPROC) (GLuint list, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLLISTPARAMETERFVSGIXPROC GLeeFuncPtr_glListParameterfvSGIX;
  #define glListParameterfvSGIX GLeeFuncPtr_glListParameterfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glListParameteriSGIX
#define GLEE_H_DEFINED_glListParameteriSGIX
  typedef void (APIENTRYP GLEEPFNGLLISTPARAMETERISGIXPROC) (GLuint list, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLLISTPARAMETERISGIXPROC GLeeFuncPtr_glListParameteriSGIX;
  #define glListParameteriSGIX GLeeFuncPtr_glListParameteriSGIX
#endif
#ifndef GLEE_H_DEFINED_glListParameterivSGIX
#define GLEE_H_DEFINED_glListParameterivSGIX
  typedef void (APIENTRYP GLEEPFNGLLISTPARAMETERIVSGIXPROC) (GLuint list, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLLISTPARAMETERIVSGIXPROC GLeeFuncPtr_glListParameterivSGIX;
  #define glListParameterivSGIX GLeeFuncPtr_glListParameterivSGIX
#endif
#endif

/* GL_SGIX_ir_instrument1 */

#ifndef GL_SGIX_ir_instrument1
#define GL_SGIX_ir_instrument1 1
#define __GLEE_GL_SGIX_ir_instrument1 1
/* Constants */
#define GL_IR_INSTRUMENT1_SGIX                             0x817F
#endif

/* GL_SGIX_calligraphic_fragment */

#ifndef GL_SGIX_calligraphic_fragment
#define GL_SGIX_calligraphic_fragment 1
#define __GLEE_GL_SGIX_calligraphic_fragment 1
/* Constants */
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX                      0x8183
#endif

/* GL_SGIX_texture_lod_bias */

#ifndef GL_SGIX_texture_lod_bias
#define GL_SGIX_texture_lod_bias 1
#define __GLEE_GL_SGIX_texture_lod_bias 1
/* Constants */
#define GL_TEXTURE_LOD_BIAS_S_SGIX                         0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX                         0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX                         0x8190
#endif

/* GL_SGIX_shadow_ambient */

#ifndef GL_SGIX_shadow_ambient
#define GL_SGIX_shadow_ambient 1
#define __GLEE_GL_SGIX_shadow_ambient 1
/* Constants */
#define GL_SHADOW_AMBIENT_SGIX                             0x80BF
#endif

/* GL_EXT_index_texture */

#ifndef GL_EXT_index_texture
#define GL_EXT_index_texture 1
#define __GLEE_GL_EXT_index_texture 1
/* Constants */
#endif

/* GL_EXT_index_material */

#ifndef GL_EXT_index_material
#define GL_EXT_index_material 1
#define __GLEE_GL_EXT_index_material 1
/* Constants */
#define GL_INDEX_MATERIAL_EXT                              0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT                    0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT                         0x81BA
#ifndef GLEE_H_DEFINED_glIndexMaterialEXT
#define GLEE_H_DEFINED_glIndexMaterialEXT
  typedef void (APIENTRYP GLEEPFNGLINDEXMATERIALEXTPROC) (GLenum face, GLenum mode);
  GLEE_EXTERN GLEEPFNGLINDEXMATERIALEXTPROC GLeeFuncPtr_glIndexMaterialEXT;
  #define glIndexMaterialEXT GLeeFuncPtr_glIndexMaterialEXT
#endif
#endif

/* GL_EXT_index_func */

#ifndef GL_EXT_index_func
#define GL_EXT_index_func 1
#define __GLEE_GL_EXT_index_func 1
/* Constants */
#define GL_INDEX_TEST_EXT                                  0x81B5
#define GL_INDEX_TEST_FUNC_EXT                             0x81B6
#define GL_INDEX_TEST_REF_EXT                              0x81B7
#ifndef GLEE_H_DEFINED_glIndexFuncEXT
#define GLEE_H_DEFINED_glIndexFuncEXT
  typedef void (APIENTRYP GLEEPFNGLINDEXFUNCEXTPROC) (GLenum func, GLclampf ref);
  GLEE_EXTERN GLEEPFNGLINDEXFUNCEXTPROC GLeeFuncPtr_glIndexFuncEXT;
  #define glIndexFuncEXT GLeeFuncPtr_glIndexFuncEXT
#endif
#endif

/* GL_EXT_index_array_formats */

#ifndef GL_EXT_index_array_formats
#define GL_EXT_index_array_formats 1
#define __GLEE_GL_EXT_index_array_formats 1
/* Constants */
#define GL_IUI_V2F_EXT                                     0x81AD
#define GL_IUI_V3F_EXT                                     0x81AE
#define GL_IUI_N3F_V2F_EXT                                 0x81AF
#define GL_IUI_N3F_V3F_EXT                                 0x81B0
#define GL_T2F_IUI_V2F_EXT                                 0x81B1
#define GL_T2F_IUI_V3F_EXT                                 0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT                             0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT                             0x81B4
#endif

/* GL_EXT_compiled_vertex_array */

#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
#define __GLEE_GL_EXT_compiled_vertex_array 1
/* Constants */
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT                    0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT                    0x81A9
#ifndef GLEE_H_DEFINED_glLockArraysEXT
#define GLEE_H_DEFINED_glLockArraysEXT
  typedef void (APIENTRYP GLEEPFNGLLOCKARRAYSEXTPROC) (GLint first, GLsizei count);
  GLEE_EXTERN GLEEPFNGLLOCKARRAYSEXTPROC GLeeFuncPtr_glLockArraysEXT;
  #define glLockArraysEXT GLeeFuncPtr_glLockArraysEXT
#endif
#ifndef GLEE_H_DEFINED_glUnlockArraysEXT
#define GLEE_H_DEFINED_glUnlockArraysEXT
  typedef void (APIENTRYP GLEEPFNGLUNLOCKARRAYSEXTPROC) ();
  GLEE_EXTERN GLEEPFNGLUNLOCKARRAYSEXTPROC GLeeFuncPtr_glUnlockArraysEXT;
  #define glUnlockArraysEXT GLeeFuncPtr_glUnlockArraysEXT
#endif
#endif

/* GL_EXT_cull_vertex */

#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex 1
#define __GLEE_GL_EXT_cull_vertex 1
/* Constants */
#define GL_CULL_VERTEX_EXT                                 0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT                    0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT                 0x81AC
#ifndef GLEE_H_DEFINED_glCullParameterdvEXT
#define GLEE_H_DEFINED_glCullParameterdvEXT
  typedef void (APIENTRYP GLEEPFNGLCULLPARAMETERDVEXTPROC) (GLenum pname, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLCULLPARAMETERDVEXTPROC GLeeFuncPtr_glCullParameterdvEXT;
  #define glCullParameterdvEXT GLeeFuncPtr_glCullParameterdvEXT
#endif
#ifndef GLEE_H_DEFINED_glCullParameterfvEXT
#define GLEE_H_DEFINED_glCullParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLCULLPARAMETERFVEXTPROC) (GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLCULLPARAMETERFVEXTPROC GLeeFuncPtr_glCullParameterfvEXT;
  #define glCullParameterfvEXT GLeeFuncPtr_glCullParameterfvEXT
#endif
#endif

/* GL_SGIX_ycrcb */

#ifndef GL_SGIX_ycrcb
#define GL_SGIX_ycrcb 1
#define __GLEE_GL_SGIX_ycrcb 1
/* Constants */
#define GL_YCRCB_422_SGIX                                  0x81BB
#define GL_YCRCB_444_SGIX                                  0x81BC
#endif

/* GL_SGIX_fragment_lighting */

#ifndef GL_SGIX_fragment_lighting
#define GL_SGIX_fragment_lighting 1
#define __GLEE_GL_SGIX_fragment_lighting 1
/* Constants */
#define GL_FRAGMENT_LIGHTING_SGIX                          0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX                    0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX               0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX          0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX                        0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX                          0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX                      0x8406
#define GL_LIGHT_ENV_MODE_SGIX                             0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX          0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX              0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX               0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX  0x840B
#define GL_FRAGMENT_LIGHT0_SGIX                            0x840C
#define GL_FRAGMENT_LIGHT1_SGIX                            0x840D
#define GL_FRAGMENT_LIGHT2_SGIX                            0x840E
#define GL_FRAGMENT_LIGHT3_SGIX                            0x840F
#define GL_FRAGMENT_LIGHT4_SGIX                            0x8410
#define GL_FRAGMENT_LIGHT5_SGIX                            0x8411
#define GL_FRAGMENT_LIGHT6_SGIX                            0x8412
#define GL_FRAGMENT_LIGHT7_SGIX                            0x8413
#ifndef GLEE_H_DEFINED_glFragmentColorMaterialSGIX
#define GLEE_H_DEFINED_glFragmentColorMaterialSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTCOLORMATERIALSGIXPROC) (GLenum face, GLenum mode);
  GLEE_EXTERN GLEEPFNGLFRAGMENTCOLORMATERIALSGIXPROC GLeeFuncPtr_glFragmentColorMaterialSGIX;
  #define glFragmentColorMaterialSGIX GLeeFuncPtr_glFragmentColorMaterialSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightfSGIX
#define GLEE_H_DEFINED_glFragmentLightfSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTFSGIXPROC) (GLenum light, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTFSGIXPROC GLeeFuncPtr_glFragmentLightfSGIX;
  #define glFragmentLightfSGIX GLeeFuncPtr_glFragmentLightfSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightfvSGIX
#define GLEE_H_DEFINED_glFragmentLightfvSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTFVSGIXPROC) (GLenum light, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTFVSGIXPROC GLeeFuncPtr_glFragmentLightfvSGIX;
  #define glFragmentLightfvSGIX GLeeFuncPtr_glFragmentLightfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightiSGIX
#define GLEE_H_DEFINED_glFragmentLightiSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTISGIXPROC) (GLenum light, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTISGIXPROC GLeeFuncPtr_glFragmentLightiSGIX;
  #define glFragmentLightiSGIX GLeeFuncPtr_glFragmentLightiSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightivSGIX
#define GLEE_H_DEFINED_glFragmentLightivSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTIVSGIXPROC) (GLenum light, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTIVSGIXPROC GLeeFuncPtr_glFragmentLightivSGIX;
  #define glFragmentLightivSGIX GLeeFuncPtr_glFragmentLightivSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightModelfSGIX
#define GLEE_H_DEFINED_glFragmentLightModelfSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELFSGIXPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELFSGIXPROC GLeeFuncPtr_glFragmentLightModelfSGIX;
  #define glFragmentLightModelfSGIX GLeeFuncPtr_glFragmentLightModelfSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightModelfvSGIX
#define GLEE_H_DEFINED_glFragmentLightModelfvSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELFVSGIXPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELFVSGIXPROC GLeeFuncPtr_glFragmentLightModelfvSGIX;
  #define glFragmentLightModelfvSGIX GLeeFuncPtr_glFragmentLightModelfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightModeliSGIX
#define GLEE_H_DEFINED_glFragmentLightModeliSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELISGIXPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELISGIXPROC GLeeFuncPtr_glFragmentLightModeliSGIX;
  #define glFragmentLightModeliSGIX GLeeFuncPtr_glFragmentLightModeliSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightModelivSGIX
#define GLEE_H_DEFINED_glFragmentLightModelivSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELIVSGIXPROC) (GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELIVSGIXPROC GLeeFuncPtr_glFragmentLightModelivSGIX;
  #define glFragmentLightModelivSGIX GLeeFuncPtr_glFragmentLightModelivSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialfSGIX
#define GLEE_H_DEFINED_glFragmentMaterialfSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTMATERIALFSGIXPROC) (GLenum face, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALFSGIXPROC GLeeFuncPtr_glFragmentMaterialfSGIX;
  #define glFragmentMaterialfSGIX GLeeFuncPtr_glFragmentMaterialfSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialfvSGIX
#define GLEE_H_DEFINED_glFragmentMaterialfvSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTMATERIALFVSGIXPROC) (GLenum face, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALFVSGIXPROC GLeeFuncPtr_glFragmentMaterialfvSGIX;
  #define glFragmentMaterialfvSGIX GLeeFuncPtr_glFragmentMaterialfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialiSGIX
#define GLEE_H_DEFINED_glFragmentMaterialiSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTMATERIALISGIXPROC) (GLenum face, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALISGIXPROC GLeeFuncPtr_glFragmentMaterialiSGIX;
  #define glFragmentMaterialiSGIX GLeeFuncPtr_glFragmentMaterialiSGIX
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialivSGIX
#define GLEE_H_DEFINED_glFragmentMaterialivSGIX
  typedef void (APIENTRYP GLEEPFNGLFRAGMENTMATERIALIVSGIXPROC) (GLenum face, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALIVSGIXPROC GLeeFuncPtr_glFragmentMaterialivSGIX;
  #define glFragmentMaterialivSGIX GLeeFuncPtr_glFragmentMaterialivSGIX
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentLightfvSGIX
#define GLEE_H_DEFINED_glGetFragmentLightfvSGIX
  typedef void (APIENTRYP GLEEPFNGLGETFRAGMENTLIGHTFVSGIXPROC) (GLenum light, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTLIGHTFVSGIXPROC GLeeFuncPtr_glGetFragmentLightfvSGIX;
  #define glGetFragmentLightfvSGIX GLeeFuncPtr_glGetFragmentLightfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentLightivSGIX
#define GLEE_H_DEFINED_glGetFragmentLightivSGIX
  typedef void (APIENTRYP GLEEPFNGLGETFRAGMENTLIGHTIVSGIXPROC) (GLenum light, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTLIGHTIVSGIXPROC GLeeFuncPtr_glGetFragmentLightivSGIX;
  #define glGetFragmentLightivSGIX GLeeFuncPtr_glGetFragmentLightivSGIX
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentMaterialfvSGIX
#define GLEE_H_DEFINED_glGetFragmentMaterialfvSGIX
  typedef void (APIENTRYP GLEEPFNGLGETFRAGMENTMATERIALFVSGIXPROC) (GLenum face, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTMATERIALFVSGIXPROC GLeeFuncPtr_glGetFragmentMaterialfvSGIX;
  #define glGetFragmentMaterialfvSGIX GLeeFuncPtr_glGetFragmentMaterialfvSGIX
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentMaterialivSGIX
#define GLEE_H_DEFINED_glGetFragmentMaterialivSGIX
  typedef void (APIENTRYP GLEEPFNGLGETFRAGMENTMATERIALIVSGIXPROC) (GLenum face, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTMATERIALIVSGIXPROC GLeeFuncPtr_glGetFragmentMaterialivSGIX;
  #define glGetFragmentMaterialivSGIX GLeeFuncPtr_glGetFragmentMaterialivSGIX
#endif
#ifndef GLEE_H_DEFINED_glLightEnviSGIX
#define GLEE_H_DEFINED_glLightEnviSGIX
  typedef void (APIENTRYP GLEEPFNGLLIGHTENVISGIXPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLLIGHTENVISGIXPROC GLeeFuncPtr_glLightEnviSGIX;
  #define glLightEnviSGIX GLeeFuncPtr_glLightEnviSGIX
#endif
#endif

/* GL_IBM_rasterpos_clip */

#ifndef GL_IBM_rasterpos_clip
#define GL_IBM_rasterpos_clip 1
#define __GLEE_GL_IBM_rasterpos_clip 1
/* Constants */
#define GL_RASTER_POSITION_UNCLIPPED_IBM                   0x19262
#endif

/* GL_HP_texture_lighting */

#ifndef GL_HP_texture_lighting
#define GL_HP_texture_lighting 1
#define __GLEE_GL_HP_texture_lighting 1
/* Constants */
#define GL_TEXTURE_LIGHTING_MODE_HP                        0x8167
#define GL_TEXTURE_POST_SPECULAR_HP                        0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP                         0x8169
#endif

/* GL_EXT_draw_range_elements */

#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
#define __GLEE_GL_EXT_draw_range_elements 1
/* Constants */
#define GL_MAX_ELEMENTS_VERTICES_EXT                       0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT                        0x80E9
#ifndef GLEE_H_DEFINED_glDrawRangeElementsEXT
#define GLEE_H_DEFINED_glDrawRangeElementsEXT
  typedef void (APIENTRYP GLEEPFNGLDRAWRANGEELEMENTSEXTPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
  GLEE_EXTERN GLEEPFNGLDRAWRANGEELEMENTSEXTPROC GLeeFuncPtr_glDrawRangeElementsEXT;
  #define glDrawRangeElementsEXT GLeeFuncPtr_glDrawRangeElementsEXT
#endif
#endif

/* GL_WIN_phong_shading */

#ifndef GL_WIN_phong_shading
#define GL_WIN_phong_shading 1
#define __GLEE_GL_WIN_phong_shading 1
/* Constants */
#define GL_PHONG_WIN                                       0x80EA
#define GL_PHONG_HINT_WIN                                  0x80EB
#endif

/* GL_WIN_specular_fog */

#ifndef GL_WIN_specular_fog
#define GL_WIN_specular_fog 1
#define __GLEE_GL_WIN_specular_fog 1
/* Constants */
#define GL_FOG_SPECULAR_TEXTURE_WIN                        0x80EC
#endif

/* GL_EXT_light_texture */

#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture 1
#define __GLEE_GL_EXT_light_texture 1
/* Constants */
#define GL_FRAGMENT_MATERIAL_EXT                           0x8349
#define GL_FRAGMENT_NORMAL_EXT                             0x834A
#define GL_FRAGMENT_COLOR_EXT                              0x834C
#define GL_ATTENUATION_EXT                                 0x834D
#define GL_SHADOW_ATTENUATION_EXT                          0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT                    0x834F
#define GL_TEXTURE_LIGHT_EXT                               0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT                       0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT                  0x8352
#ifndef GLEE_H_DEFINED_glApplyTextureEXT
#define GLEE_H_DEFINED_glApplyTextureEXT
  typedef void (APIENTRYP GLEEPFNGLAPPLYTEXTUREEXTPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLAPPLYTEXTUREEXTPROC GLeeFuncPtr_glApplyTextureEXT;
  #define glApplyTextureEXT GLeeFuncPtr_glApplyTextureEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureLightEXT
#define GLEE_H_DEFINED_glTextureLightEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTURELIGHTEXTPROC) (GLenum pname);
  GLEE_EXTERN GLEEPFNGLTEXTURELIGHTEXTPROC GLeeFuncPtr_glTextureLightEXT;
  #define glTextureLightEXT GLeeFuncPtr_glTextureLightEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureMaterialEXT
#define GLEE_H_DEFINED_glTextureMaterialEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREMATERIALEXTPROC) (GLenum face, GLenum mode);
  GLEE_EXTERN GLEEPFNGLTEXTUREMATERIALEXTPROC GLeeFuncPtr_glTextureMaterialEXT;
  #define glTextureMaterialEXT GLeeFuncPtr_glTextureMaterialEXT
#endif
#endif

/* GL_SGIX_blend_alpha_minmax */

#ifndef GL_SGIX_blend_alpha_minmax
#define GL_SGIX_blend_alpha_minmax 1
#define __GLEE_GL_SGIX_blend_alpha_minmax 1
/* Constants */
#define GL_ALPHA_MIN_SGIX                                  0x8320
#define GL_ALPHA_MAX_SGIX                                  0x8321
#endif

/* GL_SGIX_impact_pixel_texture */

#ifndef GL_SGIX_impact_pixel_texture
#define GL_SGIX_impact_pixel_texture 1
#define __GLEE_GL_SGIX_impact_pixel_texture 1
/* Constants */
#define GL_PIXEL_TEX_GEN_Q_CEILING_SGIX                    0x8184
#define GL_PIXEL_TEX_GEN_Q_ROUND_SGIX                      0x8185
#define GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX                      0x8186
#define GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX                0x8187
#define GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX             0x8188
#define GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX                     0x8189
#define GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX                     0x818A
#endif

/* GL_EXT_bgra */

#ifndef GL_EXT_bgra
#define GL_EXT_bgra 1
#define __GLEE_GL_EXT_bgra 1
/* Constants */
#define GL_BGR_EXT                                         0x80E0
#define GL_BGRA_EXT                                        0x80E1
#endif

/* GL_SGIX_async */

#ifndef GL_SGIX_async
#define GL_SGIX_async 1
#define __GLEE_GL_SGIX_async 1
/* Constants */
#define GL_ASYNC_MARKER_SGIX                               0x8329
#ifndef GLEE_H_DEFINED_glAsyncMarkerSGIX
#define GLEE_H_DEFINED_glAsyncMarkerSGIX
  typedef void (APIENTRYP GLEEPFNGLASYNCMARKERSGIXPROC) (GLuint marker);
  GLEE_EXTERN GLEEPFNGLASYNCMARKERSGIXPROC GLeeFuncPtr_glAsyncMarkerSGIX;
  #define glAsyncMarkerSGIX GLeeFuncPtr_glAsyncMarkerSGIX
#endif
#ifndef GLEE_H_DEFINED_glFinishAsyncSGIX
#define GLEE_H_DEFINED_glFinishAsyncSGIX
  typedef GLint (APIENTRYP GLEEPFNGLFINISHASYNCSGIXPROC) (GLuint * markerp);
  GLEE_EXTERN GLEEPFNGLFINISHASYNCSGIXPROC GLeeFuncPtr_glFinishAsyncSGIX;
  #define glFinishAsyncSGIX GLeeFuncPtr_glFinishAsyncSGIX
#endif
#ifndef GLEE_H_DEFINED_glPollAsyncSGIX
#define GLEE_H_DEFINED_glPollAsyncSGIX
  typedef GLint (APIENTRYP GLEEPFNGLPOLLASYNCSGIXPROC) (GLuint * markerp);
  GLEE_EXTERN GLEEPFNGLPOLLASYNCSGIXPROC GLeeFuncPtr_glPollAsyncSGIX;
  #define glPollAsyncSGIX GLeeFuncPtr_glPollAsyncSGIX
#endif
#ifndef GLEE_H_DEFINED_glGenAsyncMarkersSGIX
#define GLEE_H_DEFINED_glGenAsyncMarkersSGIX
  typedef GLuint (APIENTRYP GLEEPFNGLGENASYNCMARKERSSGIXPROC) (GLsizei range);
  GLEE_EXTERN GLEEPFNGLGENASYNCMARKERSSGIXPROC GLeeFuncPtr_glGenAsyncMarkersSGIX;
  #define glGenAsyncMarkersSGIX GLeeFuncPtr_glGenAsyncMarkersSGIX
#endif
#ifndef GLEE_H_DEFINED_glDeleteAsyncMarkersSGIX
#define GLEE_H_DEFINED_glDeleteAsyncMarkersSGIX
  typedef void (APIENTRYP GLEEPFNGLDELETEASYNCMARKERSSGIXPROC) (GLuint marker, GLsizei range);
  GLEE_EXTERN GLEEPFNGLDELETEASYNCMARKERSSGIXPROC GLeeFuncPtr_glDeleteAsyncMarkersSGIX;
  #define glDeleteAsyncMarkersSGIX GLeeFuncPtr_glDeleteAsyncMarkersSGIX
#endif
#ifndef GLEE_H_DEFINED_glIsAsyncMarkerSGIX
#define GLEE_H_DEFINED_glIsAsyncMarkerSGIX
  typedef GLboolean (APIENTRYP GLEEPFNGLISASYNCMARKERSGIXPROC) (GLuint marker);
  GLEE_EXTERN GLEEPFNGLISASYNCMARKERSGIXPROC GLeeFuncPtr_glIsAsyncMarkerSGIX;
  #define glIsAsyncMarkerSGIX GLeeFuncPtr_glIsAsyncMarkerSGIX
#endif
#endif

/* GL_SGIX_async_pixel */

#ifndef GL_SGIX_async_pixel
#define GL_SGIX_async_pixel 1
#define __GLEE_GL_SGIX_async_pixel 1
/* Constants */
#define GL_ASYNC_TEX_IMAGE_SGIX                            0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX                          0x835D
#define GL_ASYNC_READ_PIXELS_SGIX                          0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX                        0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX                      0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX                      0x8361
#endif

/* GL_SGIX_async_histogram */

#ifndef GL_SGIX_async_histogram
#define GL_SGIX_async_histogram 1
#define __GLEE_GL_SGIX_async_histogram 1
/* Constants */
#define GL_ASYNC_HISTOGRAM_SGIX                            0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX                        0x832D
#endif

/* GL_INTEL_texture_scissor */

#ifndef GL_INTEL_texture_scissor
#define GL_INTEL_texture_scissor 1
#define __GLEE_GL_INTEL_texture_scissor 1
/* Constants */
#endif

/* GL_INTEL_parallel_arrays */

#ifndef GL_INTEL_parallel_arrays
#define GL_INTEL_parallel_arrays 1
#define __GLEE_GL_INTEL_parallel_arrays 1
/* Constants */
#define GL_PARALLEL_ARRAYS_INTEL                           0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL            0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL            0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL             0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL     0x83F8
#ifndef GLEE_H_DEFINED_glVertexPointervINTEL
#define GLEE_H_DEFINED_glVertexPointervINTEL
  typedef void (APIENTRYP GLEEPFNGLVERTEXPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXPOINTERVINTELPROC GLeeFuncPtr_glVertexPointervINTEL;
  #define glVertexPointervINTEL GLeeFuncPtr_glVertexPointervINTEL
#endif
#ifndef GLEE_H_DEFINED_glNormalPointervINTEL
#define GLEE_H_DEFINED_glNormalPointervINTEL
  typedef void (APIENTRYP GLEEPFNGLNORMALPOINTERVINTELPROC) (GLenum type, const GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLNORMALPOINTERVINTELPROC GLeeFuncPtr_glNormalPointervINTEL;
  #define glNormalPointervINTEL GLeeFuncPtr_glNormalPointervINTEL
#endif
#ifndef GLEE_H_DEFINED_glColorPointervINTEL
#define GLEE_H_DEFINED_glColorPointervINTEL
  typedef void (APIENTRYP GLEEPFNGLCOLORPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLCOLORPOINTERVINTELPROC GLeeFuncPtr_glColorPointervINTEL;
  #define glColorPointervINTEL GLeeFuncPtr_glColorPointervINTEL
#endif
#ifndef GLEE_H_DEFINED_glTexCoordPointervINTEL
#define GLEE_H_DEFINED_glTexCoordPointervINTEL
  typedef void (APIENTRYP GLEEPFNGLTEXCOORDPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLTEXCOORDPOINTERVINTELPROC GLeeFuncPtr_glTexCoordPointervINTEL;
  #define glTexCoordPointervINTEL GLeeFuncPtr_glTexCoordPointervINTEL
#endif
#endif

/* GL_HP_occlusion_test */

#ifndef GL_HP_occlusion_test
#define GL_HP_occlusion_test 1
#define __GLEE_GL_HP_occlusion_test 1
/* Constants */
#define GL_OCCLUSION_TEST_HP                               0x8165
#define GL_OCCLUSION_TEST_RESULT_HP                        0x8166
#endif

/* GL_EXT_pixel_transform */

#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform 1
#define __GLEE_GL_EXT_pixel_transform 1
/* Constants */
#define GL_PIXEL_TRANSFORM_2D_EXT                          0x8330
#define GL_PIXEL_MAG_FILTER_EXT                            0x8331
#define GL_PIXEL_MIN_FILTER_EXT                            0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT                          0x8333
#define GL_CUBIC_EXT                                       0x8334
#define GL_AVERAGE_EXT                                     0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT              0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT          0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT                   0x8338
#ifndef GLEE_H_DEFINED_glPixelTransformParameteriEXT
#define GLEE_H_DEFINED_glPixelTransformParameteriEXT
  typedef void (APIENTRYP GLEEPFNGLPIXELTRANSFORMPARAMETERIEXTPROC) (GLenum target, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLPIXELTRANSFORMPARAMETERIEXTPROC GLeeFuncPtr_glPixelTransformParameteriEXT;
  #define glPixelTransformParameteriEXT GLeeFuncPtr_glPixelTransformParameteriEXT
#endif
#ifndef GLEE_H_DEFINED_glPixelTransformParameterfEXT
#define GLEE_H_DEFINED_glPixelTransformParameterfEXT
  typedef void (APIENTRYP GLEEPFNGLPIXELTRANSFORMPARAMETERFEXTPROC) (GLenum target, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLPIXELTRANSFORMPARAMETERFEXTPROC GLeeFuncPtr_glPixelTransformParameterfEXT;
  #define glPixelTransformParameterfEXT GLeeFuncPtr_glPixelTransformParameterfEXT
#endif
#ifndef GLEE_H_DEFINED_glPixelTransformParameterivEXT
#define GLEE_H_DEFINED_glPixelTransformParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLPIXELTRANSFORMPARAMETERIVEXTPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPIXELTRANSFORMPARAMETERIVEXTPROC GLeeFuncPtr_glPixelTransformParameterivEXT;
  #define glPixelTransformParameterivEXT GLeeFuncPtr_glPixelTransformParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glPixelTransformParameterfvEXT
#define GLEE_H_DEFINED_glPixelTransformParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLPIXELTRANSFORMPARAMETERFVEXTPROC) (GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPIXELTRANSFORMPARAMETERFVEXTPROC GLeeFuncPtr_glPixelTransformParameterfvEXT;
  #define glPixelTransformParameterfvEXT GLeeFuncPtr_glPixelTransformParameterfvEXT
#endif
#endif

/* GL_EXT_pixel_transform_color_table */

#ifndef GL_EXT_pixel_transform_color_table
#define GL_EXT_pixel_transform_color_table 1
#define __GLEE_GL_EXT_pixel_transform_color_table 1
/* Constants */
#endif

/* GL_EXT_shared_texture_palette */

#ifndef GL_EXT_shared_texture_palette
#define GL_EXT_shared_texture_palette 1
#define __GLEE_GL_EXT_shared_texture_palette 1
/* Constants */
#define GL_SHARED_TEXTURE_PALETTE_EXT                      0x81FB
#endif

/* GL_EXT_separate_specular_color */

#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color 1
#define __GLEE_GL_EXT_separate_specular_color 1
/* Constants */
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT                   0x81F8
#define GL_SINGLE_COLOR_EXT                                0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT                     0x81FA
#endif

/* GL_EXT_secondary_color */

#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
#define __GLEE_GL_EXT_secondary_color 1
/* Constants */
#define GL_COLOR_SUM_EXT                                   0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT                     0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT                  0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT                  0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT                0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT               0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT                       0x845E
#ifndef GLEE_H_DEFINED_glSecondaryColor3bEXT
#define GLEE_H_DEFINED_glSecondaryColor3bEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3BEXTPROC) (GLbyte red, GLbyte green, GLbyte blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3BEXTPROC GLeeFuncPtr_glSecondaryColor3bEXT;
  #define glSecondaryColor3bEXT GLeeFuncPtr_glSecondaryColor3bEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3bvEXT
#define GLEE_H_DEFINED_glSecondaryColor3bvEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3BVEXTPROC) (const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3BVEXTPROC GLeeFuncPtr_glSecondaryColor3bvEXT;
  #define glSecondaryColor3bvEXT GLeeFuncPtr_glSecondaryColor3bvEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3dEXT
#define GLEE_H_DEFINED_glSecondaryColor3dEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3DEXTPROC) (GLdouble red, GLdouble green, GLdouble blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3DEXTPROC GLeeFuncPtr_glSecondaryColor3dEXT;
  #define glSecondaryColor3dEXT GLeeFuncPtr_glSecondaryColor3dEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3dvEXT
#define GLEE_H_DEFINED_glSecondaryColor3dvEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3DVEXTPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3DVEXTPROC GLeeFuncPtr_glSecondaryColor3dvEXT;
  #define glSecondaryColor3dvEXT GLeeFuncPtr_glSecondaryColor3dvEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3fEXT
#define GLEE_H_DEFINED_glSecondaryColor3fEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3FEXTPROC) (GLfloat red, GLfloat green, GLfloat blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3FEXTPROC GLeeFuncPtr_glSecondaryColor3fEXT;
  #define glSecondaryColor3fEXT GLeeFuncPtr_glSecondaryColor3fEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3fvEXT
#define GLEE_H_DEFINED_glSecondaryColor3fvEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3FVEXTPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3FVEXTPROC GLeeFuncPtr_glSecondaryColor3fvEXT;
  #define glSecondaryColor3fvEXT GLeeFuncPtr_glSecondaryColor3fvEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3iEXT
#define GLEE_H_DEFINED_glSecondaryColor3iEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3IEXTPROC) (GLint red, GLint green, GLint blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3IEXTPROC GLeeFuncPtr_glSecondaryColor3iEXT;
  #define glSecondaryColor3iEXT GLeeFuncPtr_glSecondaryColor3iEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3ivEXT
#define GLEE_H_DEFINED_glSecondaryColor3ivEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3IVEXTPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3IVEXTPROC GLeeFuncPtr_glSecondaryColor3ivEXT;
  #define glSecondaryColor3ivEXT GLeeFuncPtr_glSecondaryColor3ivEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3sEXT
#define GLEE_H_DEFINED_glSecondaryColor3sEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3SEXTPROC) (GLshort red, GLshort green, GLshort blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3SEXTPROC GLeeFuncPtr_glSecondaryColor3sEXT;
  #define glSecondaryColor3sEXT GLeeFuncPtr_glSecondaryColor3sEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3svEXT
#define GLEE_H_DEFINED_glSecondaryColor3svEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3SVEXTPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3SVEXTPROC GLeeFuncPtr_glSecondaryColor3svEXT;
  #define glSecondaryColor3svEXT GLeeFuncPtr_glSecondaryColor3svEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3ubEXT
#define GLEE_H_DEFINED_glSecondaryColor3ubEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UBEXTPROC) (GLubyte red, GLubyte green, GLubyte blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UBEXTPROC GLeeFuncPtr_glSecondaryColor3ubEXT;
  #define glSecondaryColor3ubEXT GLeeFuncPtr_glSecondaryColor3ubEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3ubvEXT
#define GLEE_H_DEFINED_glSecondaryColor3ubvEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UBVEXTPROC) (const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UBVEXTPROC GLeeFuncPtr_glSecondaryColor3ubvEXT;
  #define glSecondaryColor3ubvEXT GLeeFuncPtr_glSecondaryColor3ubvEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3uiEXT
#define GLEE_H_DEFINED_glSecondaryColor3uiEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UIEXTPROC) (GLuint red, GLuint green, GLuint blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UIEXTPROC GLeeFuncPtr_glSecondaryColor3uiEXT;
  #define glSecondaryColor3uiEXT GLeeFuncPtr_glSecondaryColor3uiEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3uivEXT
#define GLEE_H_DEFINED_glSecondaryColor3uivEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3UIVEXTPROC) (const GLuint * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3UIVEXTPROC GLeeFuncPtr_glSecondaryColor3uivEXT;
  #define glSecondaryColor3uivEXT GLeeFuncPtr_glSecondaryColor3uivEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3usEXT
#define GLEE_H_DEFINED_glSecondaryColor3usEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3USEXTPROC) (GLushort red, GLushort green, GLushort blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3USEXTPROC GLeeFuncPtr_glSecondaryColor3usEXT;
  #define glSecondaryColor3usEXT GLeeFuncPtr_glSecondaryColor3usEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3usvEXT
#define GLEE_H_DEFINED_glSecondaryColor3usvEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3USVEXTPROC) (const GLushort * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3USVEXTPROC GLeeFuncPtr_glSecondaryColor3usvEXT;
  #define glSecondaryColor3usvEXT GLeeFuncPtr_glSecondaryColor3usvEXT
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColorPointerEXT
#define GLEE_H_DEFINED_glSecondaryColorPointerEXT
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLORPOINTEREXTPROC GLeeFuncPtr_glSecondaryColorPointerEXT;
  #define glSecondaryColorPointerEXT GLeeFuncPtr_glSecondaryColorPointerEXT
#endif
#endif

/* GL_EXT_texture_perturb_normal */

#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal 1
#define __GLEE_GL_EXT_texture_perturb_normal 1
/* Constants */
#define GL_PERTURB_EXT                                     0x85AE
#define GL_TEXTURE_NORMAL_EXT                              0x85AF
#ifndef GLEE_H_DEFINED_glTextureNormalEXT
#define GLEE_H_DEFINED_glTextureNormalEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTURENORMALEXTPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLTEXTURENORMALEXTPROC GLeeFuncPtr_glTextureNormalEXT;
  #define glTextureNormalEXT GLeeFuncPtr_glTextureNormalEXT
#endif
#endif

/* GL_EXT_multi_draw_arrays */

#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
#define __GLEE_GL_EXT_multi_draw_arrays 1
/* Constants */
#ifndef GLEE_H_DEFINED_glMultiDrawArraysEXT
#define GLEE_H_DEFINED_glMultiDrawArraysEXT
  typedef void (APIENTRYP GLEEPFNGLMULTIDRAWARRAYSEXTPROC) (GLenum mode, GLint * first, GLsizei * count, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLMULTIDRAWARRAYSEXTPROC GLeeFuncPtr_glMultiDrawArraysEXT;
  #define glMultiDrawArraysEXT GLeeFuncPtr_glMultiDrawArraysEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiDrawElementsEXT
#define GLEE_H_DEFINED_glMultiDrawElementsEXT
  typedef void (APIENTRYP GLEEPFNGLMULTIDRAWELEMENTSEXTPROC) (GLenum mode, const GLsizei * count, GLenum type, const GLvoid* * indices, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLMULTIDRAWELEMENTSEXTPROC GLeeFuncPtr_glMultiDrawElementsEXT;
  #define glMultiDrawElementsEXT GLeeFuncPtr_glMultiDrawElementsEXT
#endif
#endif

/* GL_EXT_fog_coord */

#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
#define __GLEE_GL_EXT_fog_coord 1
/* Constants */
#define GL_FOG_COORDINATE_SOURCE_EXT                       0x8450
#define GL_FOG_COORDINATE_EXT                              0x8451
#define GL_FRAGMENT_DEPTH_EXT                              0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT                      0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT                   0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT                 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT                0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT                        0x8457
#ifndef GLEE_H_DEFINED_glFogCoordfEXT
#define GLEE_H_DEFINED_glFogCoordfEXT
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDFEXTPROC) (GLfloat coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDFEXTPROC GLeeFuncPtr_glFogCoordfEXT;
  #define glFogCoordfEXT GLeeFuncPtr_glFogCoordfEXT
#endif
#ifndef GLEE_H_DEFINED_glFogCoordfvEXT
#define GLEE_H_DEFINED_glFogCoordfvEXT
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDFVEXTPROC) (const GLfloat * coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDFVEXTPROC GLeeFuncPtr_glFogCoordfvEXT;
  #define glFogCoordfvEXT GLeeFuncPtr_glFogCoordfvEXT
#endif
#ifndef GLEE_H_DEFINED_glFogCoorddEXT
#define GLEE_H_DEFINED_glFogCoorddEXT
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDDEXTPROC) (GLdouble coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDDEXTPROC GLeeFuncPtr_glFogCoorddEXT;
  #define glFogCoorddEXT GLeeFuncPtr_glFogCoorddEXT
#endif
#ifndef GLEE_H_DEFINED_glFogCoorddvEXT
#define GLEE_H_DEFINED_glFogCoorddvEXT
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDDVEXTPROC) (const GLdouble * coord);
  GLEE_EXTERN GLEEPFNGLFOGCOORDDVEXTPROC GLeeFuncPtr_glFogCoorddvEXT;
  #define glFogCoorddvEXT GLeeFuncPtr_glFogCoorddvEXT
#endif
#ifndef GLEE_H_DEFINED_glFogCoordPointerEXT
#define GLEE_H_DEFINED_glFogCoordPointerEXT
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLFOGCOORDPOINTEREXTPROC GLeeFuncPtr_glFogCoordPointerEXT;
  #define glFogCoordPointerEXT GLeeFuncPtr_glFogCoordPointerEXT
#endif
#endif

/* GL_REND_screen_coordinates */

#ifndef GL_REND_screen_coordinates
#define GL_REND_screen_coordinates 1
#define __GLEE_GL_REND_screen_coordinates 1
/* Constants */
#define GL_SCREEN_COORDINATES_REND                         0x8490
#define GL_INVERTED_SCREEN_W_REND                          0x8491
#endif

/* GL_EXT_coordinate_frame */

#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame 1
#define __GLEE_GL_EXT_coordinate_frame 1
/* Constants */
#define GL_TANGENT_ARRAY_EXT                               0x8439
#define GL_BINORMAL_ARRAY_EXT                              0x843A
#define GL_CURRENT_TANGENT_EXT                             0x843B
#define GL_CURRENT_BINORMAL_EXT                            0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT                          0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT                        0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT                         0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT                       0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT                       0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT                      0x8443
#define GL_MAP1_TANGENT_EXT                                0x8444
#define GL_MAP2_TANGENT_EXT                                0x8445
#define GL_MAP1_BINORMAL_EXT                               0x8446
#define GL_MAP2_BINORMAL_EXT                               0x8447
#ifndef GLEE_H_DEFINED_glTangent3bEXT
#define GLEE_H_DEFINED_glTangent3bEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3BEXTPROC) (GLbyte tx, GLbyte ty, GLbyte tz);
  GLEE_EXTERN GLEEPFNGLTANGENT3BEXTPROC GLeeFuncPtr_glTangent3bEXT;
  #define glTangent3bEXT GLeeFuncPtr_glTangent3bEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3bvEXT
#define GLEE_H_DEFINED_glTangent3bvEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3BVEXTPROC) (const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLTANGENT3BVEXTPROC GLeeFuncPtr_glTangent3bvEXT;
  #define glTangent3bvEXT GLeeFuncPtr_glTangent3bvEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3dEXT
#define GLEE_H_DEFINED_glTangent3dEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3DEXTPROC) (GLdouble tx, GLdouble ty, GLdouble tz);
  GLEE_EXTERN GLEEPFNGLTANGENT3DEXTPROC GLeeFuncPtr_glTangent3dEXT;
  #define glTangent3dEXT GLeeFuncPtr_glTangent3dEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3dvEXT
#define GLEE_H_DEFINED_glTangent3dvEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3DVEXTPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLTANGENT3DVEXTPROC GLeeFuncPtr_glTangent3dvEXT;
  #define glTangent3dvEXT GLeeFuncPtr_glTangent3dvEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3fEXT
#define GLEE_H_DEFINED_glTangent3fEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3FEXTPROC) (GLfloat tx, GLfloat ty, GLfloat tz);
  GLEE_EXTERN GLEEPFNGLTANGENT3FEXTPROC GLeeFuncPtr_glTangent3fEXT;
  #define glTangent3fEXT GLeeFuncPtr_glTangent3fEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3fvEXT
#define GLEE_H_DEFINED_glTangent3fvEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3FVEXTPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTANGENT3FVEXTPROC GLeeFuncPtr_glTangent3fvEXT;
  #define glTangent3fvEXT GLeeFuncPtr_glTangent3fvEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3iEXT
#define GLEE_H_DEFINED_glTangent3iEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3IEXTPROC) (GLint tx, GLint ty, GLint tz);
  GLEE_EXTERN GLEEPFNGLTANGENT3IEXTPROC GLeeFuncPtr_glTangent3iEXT;
  #define glTangent3iEXT GLeeFuncPtr_glTangent3iEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3ivEXT
#define GLEE_H_DEFINED_glTangent3ivEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3IVEXTPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLTANGENT3IVEXTPROC GLeeFuncPtr_glTangent3ivEXT;
  #define glTangent3ivEXT GLeeFuncPtr_glTangent3ivEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3sEXT
#define GLEE_H_DEFINED_glTangent3sEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3SEXTPROC) (GLshort tx, GLshort ty, GLshort tz);
  GLEE_EXTERN GLEEPFNGLTANGENT3SEXTPROC GLeeFuncPtr_glTangent3sEXT;
  #define glTangent3sEXT GLeeFuncPtr_glTangent3sEXT
#endif
#ifndef GLEE_H_DEFINED_glTangent3svEXT
#define GLEE_H_DEFINED_glTangent3svEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENT3SVEXTPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLTANGENT3SVEXTPROC GLeeFuncPtr_glTangent3svEXT;
  #define glTangent3svEXT GLeeFuncPtr_glTangent3svEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3bEXT
#define GLEE_H_DEFINED_glBinormal3bEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3BEXTPROC) (GLbyte bx, GLbyte by, GLbyte bz);
  GLEE_EXTERN GLEEPFNGLBINORMAL3BEXTPROC GLeeFuncPtr_glBinormal3bEXT;
  #define glBinormal3bEXT GLeeFuncPtr_glBinormal3bEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3bvEXT
#define GLEE_H_DEFINED_glBinormal3bvEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3BVEXTPROC) (const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLBINORMAL3BVEXTPROC GLeeFuncPtr_glBinormal3bvEXT;
  #define glBinormal3bvEXT GLeeFuncPtr_glBinormal3bvEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3dEXT
#define GLEE_H_DEFINED_glBinormal3dEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3DEXTPROC) (GLdouble bx, GLdouble by, GLdouble bz);
  GLEE_EXTERN GLEEPFNGLBINORMAL3DEXTPROC GLeeFuncPtr_glBinormal3dEXT;
  #define glBinormal3dEXT GLeeFuncPtr_glBinormal3dEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3dvEXT
#define GLEE_H_DEFINED_glBinormal3dvEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3DVEXTPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLBINORMAL3DVEXTPROC GLeeFuncPtr_glBinormal3dvEXT;
  #define glBinormal3dvEXT GLeeFuncPtr_glBinormal3dvEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3fEXT
#define GLEE_H_DEFINED_glBinormal3fEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3FEXTPROC) (GLfloat bx, GLfloat by, GLfloat bz);
  GLEE_EXTERN GLEEPFNGLBINORMAL3FEXTPROC GLeeFuncPtr_glBinormal3fEXT;
  #define glBinormal3fEXT GLeeFuncPtr_glBinormal3fEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3fvEXT
#define GLEE_H_DEFINED_glBinormal3fvEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3FVEXTPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLBINORMAL3FVEXTPROC GLeeFuncPtr_glBinormal3fvEXT;
  #define glBinormal3fvEXT GLeeFuncPtr_glBinormal3fvEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3iEXT
#define GLEE_H_DEFINED_glBinormal3iEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3IEXTPROC) (GLint bx, GLint by, GLint bz);
  GLEE_EXTERN GLEEPFNGLBINORMAL3IEXTPROC GLeeFuncPtr_glBinormal3iEXT;
  #define glBinormal3iEXT GLeeFuncPtr_glBinormal3iEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3ivEXT
#define GLEE_H_DEFINED_glBinormal3ivEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3IVEXTPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLBINORMAL3IVEXTPROC GLeeFuncPtr_glBinormal3ivEXT;
  #define glBinormal3ivEXT GLeeFuncPtr_glBinormal3ivEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3sEXT
#define GLEE_H_DEFINED_glBinormal3sEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3SEXTPROC) (GLshort bx, GLshort by, GLshort bz);
  GLEE_EXTERN GLEEPFNGLBINORMAL3SEXTPROC GLeeFuncPtr_glBinormal3sEXT;
  #define glBinormal3sEXT GLeeFuncPtr_glBinormal3sEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormal3svEXT
#define GLEE_H_DEFINED_glBinormal3svEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMAL3SVEXTPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLBINORMAL3SVEXTPROC GLeeFuncPtr_glBinormal3svEXT;
  #define glBinormal3svEXT GLeeFuncPtr_glBinormal3svEXT
#endif
#ifndef GLEE_H_DEFINED_glTangentPointerEXT
#define GLEE_H_DEFINED_glTangentPointerEXT
  typedef void (APIENTRYP GLEEPFNGLTANGENTPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLTANGENTPOINTEREXTPROC GLeeFuncPtr_glTangentPointerEXT;
  #define glTangentPointerEXT GLeeFuncPtr_glTangentPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glBinormalPointerEXT
#define GLEE_H_DEFINED_glBinormalPointerEXT
  typedef void (APIENTRYP GLEEPFNGLBINORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLBINORMALPOINTEREXTPROC GLeeFuncPtr_glBinormalPointerEXT;
  #define glBinormalPointerEXT GLeeFuncPtr_glBinormalPointerEXT
#endif
#endif

/* GL_EXT_texture_env_combine */

#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine 1
#define __GLEE_GL_EXT_texture_env_combine 1
/* Constants */
#define GL_COMBINE_EXT                                     0x8570
#define GL_COMBINE_RGB_EXT                                 0x8571
#define GL_COMBINE_ALPHA_EXT                               0x8572
#define GL_RGB_SCALE_EXT                                   0x8573
#define GL_ADD_SIGNED_EXT                                  0x8574
#define GL_INTERPOLATE_EXT                                 0x8575
#define GL_CONSTANT_EXT                                    0x8576
#define GL_PRIMARY_COLOR_EXT                               0x8577
#define GL_PREVIOUS_EXT                                    0x8578
#define GL_SOURCE0_RGB_EXT                                 0x8580
#define GL_SOURCE1_RGB_EXT                                 0x8581
#define GL_SOURCE2_RGB_EXT                                 0x8582
#define GL_SOURCE0_ALPHA_EXT                               0x8588
#define GL_SOURCE1_ALPHA_EXT                               0x8589
#define GL_SOURCE2_ALPHA_EXT                               0x858A
#define GL_OPERAND0_RGB_EXT                                0x8590
#define GL_OPERAND1_RGB_EXT                                0x8591
#define GL_OPERAND2_RGB_EXT                                0x8592
#define GL_OPERAND0_ALPHA_EXT                              0x8598
#define GL_OPERAND1_ALPHA_EXT                              0x8599
#define GL_OPERAND2_ALPHA_EXT                              0x859A
#endif

/* GL_APPLE_specular_vector */

#ifndef GL_APPLE_specular_vector
#define GL_APPLE_specular_vector 1
#define __GLEE_GL_APPLE_specular_vector 1
/* Constants */
#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE               0x85B0
#endif

/* GL_APPLE_transform_hint */

#ifndef GL_APPLE_transform_hint
#define GL_APPLE_transform_hint 1
#define __GLEE_GL_APPLE_transform_hint 1
/* Constants */
#define GL_TRANSFORM_HINT_APPLE                            0x85B1
#endif

/* GL_SGIX_fog_scale */

#ifndef GL_SGIX_fog_scale
#define GL_SGIX_fog_scale 1
#define __GLEE_GL_SGIX_fog_scale 1
/* Constants */
#define GL_FOG_SCALE_SGIX                                  0x81FC
#define GL_FOG_SCALE_VALUE_SGIX                            0x81FD
#endif

/* GL_SUNX_constant_data */

#ifndef GL_SUNX_constant_data
#define GL_SUNX_constant_data 1
#define __GLEE_GL_SUNX_constant_data 1
/* Constants */
#define GL_UNPACK_CONSTANT_DATA_SUNX                       0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX                      0x81D6
#ifndef GLEE_H_DEFINED_glFinishTextureSUNX
#define GLEE_H_DEFINED_glFinishTextureSUNX
  typedef void (APIENTRYP GLEEPFNGLFINISHTEXTURESUNXPROC) ();
  GLEE_EXTERN GLEEPFNGLFINISHTEXTURESUNXPROC GLeeFuncPtr_glFinishTextureSUNX;
  #define glFinishTextureSUNX GLeeFuncPtr_glFinishTextureSUNX
#endif
#endif

/* GL_SUN_global_alpha */

#ifndef GL_SUN_global_alpha
#define GL_SUN_global_alpha 1
#define __GLEE_GL_SUN_global_alpha 1
/* Constants */
#define GL_GLOBAL_ALPHA_SUN                                0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN                         0x81DA
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactorbSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactorbSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORBSUNPROC) (GLbyte factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORBSUNPROC GLeeFuncPtr_glGlobalAlphaFactorbSUN;
  #define glGlobalAlphaFactorbSUN GLeeFuncPtr_glGlobalAlphaFactorbSUN
#endif
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactorsSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactorsSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORSSUNPROC) (GLshort factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORSSUNPROC GLeeFuncPtr_glGlobalAlphaFactorsSUN;
  #define glGlobalAlphaFactorsSUN GLeeFuncPtr_glGlobalAlphaFactorsSUN
#endif
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactoriSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactoriSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORISUNPROC) (GLint factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORISUNPROC GLeeFuncPtr_glGlobalAlphaFactoriSUN;
  #define glGlobalAlphaFactoriSUN GLeeFuncPtr_glGlobalAlphaFactoriSUN
#endif
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactorfSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactorfSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORFSUNPROC) (GLfloat factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORFSUNPROC GLeeFuncPtr_glGlobalAlphaFactorfSUN;
  #define glGlobalAlphaFactorfSUN GLeeFuncPtr_glGlobalAlphaFactorfSUN
#endif
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactordSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactordSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORDSUNPROC) (GLdouble factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORDSUNPROC GLeeFuncPtr_glGlobalAlphaFactordSUN;
  #define glGlobalAlphaFactordSUN GLeeFuncPtr_glGlobalAlphaFactordSUN
#endif
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactorubSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactorubSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORUBSUNPROC) (GLubyte factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORUBSUNPROC GLeeFuncPtr_glGlobalAlphaFactorubSUN;
  #define glGlobalAlphaFactorubSUN GLeeFuncPtr_glGlobalAlphaFactorubSUN
#endif
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactorusSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactorusSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORUSSUNPROC) (GLushort factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORUSSUNPROC GLeeFuncPtr_glGlobalAlphaFactorusSUN;
  #define glGlobalAlphaFactorusSUN GLeeFuncPtr_glGlobalAlphaFactorusSUN
#endif
#ifndef GLEE_H_DEFINED_glGlobalAlphaFactoruiSUN
#define GLEE_H_DEFINED_glGlobalAlphaFactoruiSUN
  typedef void (APIENTRYP GLEEPFNGLGLOBALALPHAFACTORUISUNPROC) (GLuint factor);
  GLEE_EXTERN GLEEPFNGLGLOBALALPHAFACTORUISUNPROC GLeeFuncPtr_glGlobalAlphaFactoruiSUN;
  #define glGlobalAlphaFactoruiSUN GLeeFuncPtr_glGlobalAlphaFactoruiSUN
#endif
#endif

/* GL_SUN_triangle_list */

#ifndef GL_SUN_triangle_list
#define GL_SUN_triangle_list 1
#define __GLEE_GL_SUN_triangle_list 1
/* Constants */
#define GL_RESTART_SUN                                     0x0001
#define GL_REPLACE_MIDDLE_SUN                              0x0002
#define GL_REPLACE_OLDEST_SUN                              0x0003
#define GL_TRIANGLE_LIST_SUN                               0x81D7
#define GL_REPLACEMENT_CODE_SUN                            0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN                      0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN                 0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN               0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN              0x85C3
#define GL_R1UI_V3F_SUN                                    0x85C4
#define GL_R1UI_C4UB_V3F_SUN                               0x85C5
#define GL_R1UI_C3F_V3F_SUN                                0x85C6
#define GL_R1UI_N3F_V3F_SUN                                0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN                            0x85C8
#define GL_R1UI_T2F_V3F_SUN                                0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN                            0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN                        0x85CB
#ifndef GLEE_H_DEFINED_glReplacementCodeuiSUN
#define GLEE_H_DEFINED_glReplacementCodeuiSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUISUNPROC) (GLuint code);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUISUNPROC GLeeFuncPtr_glReplacementCodeuiSUN;
  #define glReplacementCodeuiSUN GLeeFuncPtr_glReplacementCodeuiSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeusSUN
#define GLEE_H_DEFINED_glReplacementCodeusSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUSSUNPROC) (GLushort code);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUSSUNPROC GLeeFuncPtr_glReplacementCodeusSUN;
  #define glReplacementCodeusSUN GLeeFuncPtr_glReplacementCodeusSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeubSUN
#define GLEE_H_DEFINED_glReplacementCodeubSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUBSUNPROC) (GLubyte code);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUBSUNPROC GLeeFuncPtr_glReplacementCodeubSUN;
  #define glReplacementCodeubSUN GLeeFuncPtr_glReplacementCodeubSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuivSUN
#define GLEE_H_DEFINED_glReplacementCodeuivSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUIVSUNPROC) (const GLuint * code);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUIVSUNPROC GLeeFuncPtr_glReplacementCodeuivSUN;
  #define glReplacementCodeuivSUN GLeeFuncPtr_glReplacementCodeuivSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeusvSUN
#define GLEE_H_DEFINED_glReplacementCodeusvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUSVSUNPROC) (const GLushort * code);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUSVSUNPROC GLeeFuncPtr_glReplacementCodeusvSUN;
  #define glReplacementCodeusvSUN GLeeFuncPtr_glReplacementCodeusvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeubvSUN
#define GLEE_H_DEFINED_glReplacementCodeubvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUBVSUNPROC) (const GLubyte * code);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUBVSUNPROC GLeeFuncPtr_glReplacementCodeubvSUN;
  #define glReplacementCodeubvSUN GLeeFuncPtr_glReplacementCodeubvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodePointerSUN
#define GLEE_H_DEFINED_glReplacementCodePointerSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEPOINTERSUNPROC) (GLenum type, GLsizei stride, const GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEPOINTERSUNPROC GLeeFuncPtr_glReplacementCodePointerSUN;
  #define glReplacementCodePointerSUN GLeeFuncPtr_glReplacementCodePointerSUN
#endif
#endif

/* GL_SUN_vertex */

#ifndef GL_SUN_vertex
#define GL_SUN_vertex 1
#define __GLEE_GL_SUN_vertex 1
/* Constants */
#ifndef GLEE_H_DEFINED_glColor4ubVertex2fSUN
#define GLEE_H_DEFINED_glColor4ubVertex2fSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR4UBVERTEX2FSUNPROC) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLCOLOR4UBVERTEX2FSUNPROC GLeeFuncPtr_glColor4ubVertex2fSUN;
  #define glColor4ubVertex2fSUN GLeeFuncPtr_glColor4ubVertex2fSUN
#endif
#ifndef GLEE_H_DEFINED_glColor4ubVertex2fvSUN
#define GLEE_H_DEFINED_glColor4ubVertex2fvSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR4UBVERTEX2FVSUNPROC) (const GLubyte * c, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLCOLOR4UBVERTEX2FVSUNPROC GLeeFuncPtr_glColor4ubVertex2fvSUN;
  #define glColor4ubVertex2fvSUN GLeeFuncPtr_glColor4ubVertex2fvSUN
#endif
#ifndef GLEE_H_DEFINED_glColor4ubVertex3fSUN
#define GLEE_H_DEFINED_glColor4ubVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR4UBVERTEX3FSUNPROC) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLCOLOR4UBVERTEX3FSUNPROC GLeeFuncPtr_glColor4ubVertex3fSUN;
  #define glColor4ubVertex3fSUN GLeeFuncPtr_glColor4ubVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glColor4ubVertex3fvSUN
#define GLEE_H_DEFINED_glColor4ubVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR4UBVERTEX3FVSUNPROC) (const GLubyte * c, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLCOLOR4UBVERTEX3FVSUNPROC GLeeFuncPtr_glColor4ubVertex3fvSUN;
  #define glColor4ubVertex3fvSUN GLeeFuncPtr_glColor4ubVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glColor3fVertex3fSUN
#define GLEE_H_DEFINED_glColor3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR3FVERTEX3FSUNPROC) (GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLCOLOR3FVERTEX3FSUNPROC GLeeFuncPtr_glColor3fVertex3fSUN;
  #define glColor3fVertex3fSUN GLeeFuncPtr_glColor3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glColor3fVertex3fvSUN
#define GLEE_H_DEFINED_glColor3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR3FVERTEX3FVSUNPROC) (const GLfloat * c, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLCOLOR3FVERTEX3FVSUNPROC GLeeFuncPtr_glColor3fVertex3fvSUN;
  #define glColor3fVertex3fvSUN GLeeFuncPtr_glColor3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLNORMAL3FVERTEX3FSUNPROC) (GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLNORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glNormal3fVertex3fSUN;
  #define glNormal3fVertex3fSUN GLeeFuncPtr_glNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLNORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glNormal3fVertex3fvSUN;
  #define glNormal3fVertex3fvSUN GLeeFuncPtr_glNormal3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glColor4fNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glColor4fNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glColor4fNormal3fVertex3fSUN;
  #define glColor4fNormal3fVertex3fSUN GLeeFuncPtr_glColor4fNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glColor4fNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glColor4fNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * c, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glColor4fNormal3fVertex3fvSUN;
  #define glColor4fNormal3fVertex3fvSUN GLeeFuncPtr_glColor4fNormal3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fVertex3fSUN
#define GLEE_H_DEFINED_glTexCoord2fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FVERTEX3FSUNPROC GLeeFuncPtr_glTexCoord2fVertex3fSUN;
  #define glTexCoord2fVertex3fSUN GLeeFuncPtr_glTexCoord2fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fVertex3fvSUN
#define GLEE_H_DEFINED_glTexCoord2fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FVERTEX3FVSUNPROC GLeeFuncPtr_glTexCoord2fVertex3fvSUN;
  #define glTexCoord2fVertex3fvSUN GLeeFuncPtr_glTexCoord2fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord4fVertex4fSUN
#define GLEE_H_DEFINED_glTexCoord4fVertex4fSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD4FVERTEX4FSUNPROC) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLTEXCOORD4FVERTEX4FSUNPROC GLeeFuncPtr_glTexCoord4fVertex4fSUN;
  #define glTexCoord4fVertex4fSUN GLeeFuncPtr_glTexCoord4fVertex4fSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord4fVertex4fvSUN
#define GLEE_H_DEFINED_glTexCoord4fVertex4fvSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD4FVERTEX4FVSUNPROC) (const GLfloat * tc, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD4FVERTEX4FVSUNPROC GLeeFuncPtr_glTexCoord4fVertex4fvSUN;
  #define glTexCoord4fVertex4fvSUN GLeeFuncPtr_glTexCoord4fVertex4fvSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fColor4ubVertex3fSUN
#define GLEE_H_DEFINED_glTexCoord2fColor4ubVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC GLeeFuncPtr_glTexCoord2fColor4ubVertex3fSUN;
  #define glTexCoord2fColor4ubVertex3fSUN GLeeFuncPtr_glTexCoord2fColor4ubVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fColor4ubVertex3fvSUN
#define GLEE_H_DEFINED_glTexCoord2fColor4ubVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC) (const GLfloat * tc, const GLubyte * c, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC GLeeFuncPtr_glTexCoord2fColor4ubVertex3fvSUN;
  #define glTexCoord2fColor4ubVertex3fvSUN GLeeFuncPtr_glTexCoord2fColor4ubVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fColor3fVertex3fSUN
#define GLEE_H_DEFINED_glTexCoord2fColor3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC GLeeFuncPtr_glTexCoord2fColor3fVertex3fSUN;
  #define glTexCoord2fColor3fVertex3fSUN GLeeFuncPtr_glTexCoord2fColor3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fColor3fVertex3fvSUN
#define GLEE_H_DEFINED_glTexCoord2fColor3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * c, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC GLeeFuncPtr_glTexCoord2fColor3fVertex3fvSUN;
  #define glTexCoord2fColor3fVertex3fvSUN GLeeFuncPtr_glTexCoord2fColor3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glTexCoord2fNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glTexCoord2fNormal3fVertex3fSUN;
  #define glTexCoord2fNormal3fVertex3fSUN GLeeFuncPtr_glTexCoord2fNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glTexCoord2fNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glTexCoord2fNormal3fVertex3fvSUN;
  #define glTexCoord2fNormal3fVertex3fvSUN GLeeFuncPtr_glTexCoord2fNormal3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fColor4fNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glTexCoord2fColor4fNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glTexCoord2fColor4fNormal3fVertex3fSUN;
  #define glTexCoord2fColor4fNormal3fVertex3fSUN GLeeFuncPtr_glTexCoord2fColor4fNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2fColor4fNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glTexCoord2fColor4fNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glTexCoord2fColor4fNormal3fVertex3fvSUN;
  #define glTexCoord2fColor4fNormal3fVertex3fvSUN GLeeFuncPtr_glTexCoord2fColor4fNormal3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord4fColor4fNormal3fVertex4fSUN
#define GLEE_H_DEFINED_glTexCoord4fColor4fNormal3fVertex4fSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC GLeeFuncPtr_glTexCoord4fColor4fNormal3fVertex4fSUN;
  #define glTexCoord4fColor4fNormal3fVertex4fSUN GLeeFuncPtr_glTexCoord4fColor4fNormal3fVertex4fSUN
#endif
#ifndef GLEE_H_DEFINED_glTexCoord4fColor4fNormal3fVertex4fvSUN
#define GLEE_H_DEFINED_glTexCoord4fColor4fNormal3fVertex4fvSUN
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC) (const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC GLeeFuncPtr_glTexCoord4fColor4fNormal3fVertex4fvSUN;
  #define glTexCoord4fColor4fNormal3fVertex4fvSUN GLeeFuncPtr_glTexCoord4fColor4fNormal3fVertex4fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC) (GLuint rc, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiVertex3fSUN;
  #define glReplacementCodeuiVertex3fSUN GLeeFuncPtr_glReplacementCodeuiVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiVertex3fvSUN;
  #define glReplacementCodeuiVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiColor4ubVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiColor4ubVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC) (GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiColor4ubVertex3fSUN;
  #define glReplacementCodeuiColor4ubVertex3fSUN GLeeFuncPtr_glReplacementCodeuiColor4ubVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiColor4ubVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiColor4ubVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC) (const GLuint * rc, const GLubyte * c, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiColor4ubVertex3fvSUN;
  #define glReplacementCodeuiColor4ubVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiColor4ubVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiColor3fVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiColor3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiColor3fVertex3fSUN;
  #define glReplacementCodeuiColor3fVertex3fSUN GLeeFuncPtr_glReplacementCodeuiColor3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiColor3fVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiColor3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * c, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiColor3fVertex3fvSUN;
  #define glReplacementCodeuiColor3fVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiColor3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiNormal3fVertex3fSUN;
  #define glReplacementCodeuiNormal3fVertex3fSUN GLeeFuncPtr_glReplacementCodeuiNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiNormal3fVertex3fvSUN;
  #define glReplacementCodeuiNormal3fVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiNormal3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiColor4fNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiColor4fNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiColor4fNormal3fVertex3fSUN;
  #define glReplacementCodeuiColor4fNormal3fVertex3fSUN GLeeFuncPtr_glReplacementCodeuiColor4fNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiColor4fNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiColor4fNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
  #define glReplacementCodeuiColor4fNormal3fVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiColor4fNormal3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC) (GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiTexCoord2fVertex3fSUN;
  #define glReplacementCodeuiTexCoord2fVertex3fSUN GLeeFuncPtr_glReplacementCodeuiTexCoord2fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * tc, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiTexCoord2fVertex3fvSUN;
  #define glReplacementCodeuiTexCoord2fVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiTexCoord2fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
  #define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN GLeeFuncPtr_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * tc, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
  #define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
#define GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC GLeeFuncPtr_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
  #define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN GLeeFuncPtr_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
#endif
#ifndef GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
#define GLEE_H_DEFINED_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
  typedef void (APIENTRYP GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC GLeeFuncPtr_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
  #define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN GLeeFuncPtr_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
#endif
#endif

/* GL_EXT_blend_func_separate */

#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
#define __GLEE_GL_EXT_blend_func_separate 1
/* Constants */
#define GL_BLEND_DST_RGB_EXT                               0x80C8
#define GL_BLEND_SRC_RGB_EXT                               0x80C9
#define GL_BLEND_DST_ALPHA_EXT                             0x80CA
#define GL_BLEND_SRC_ALPHA_EXT                             0x80CB
#ifndef GLEE_H_DEFINED_glBlendFuncSeparateEXT
#define GLEE_H_DEFINED_glBlendFuncSeparateEXT
  typedef void (APIENTRYP GLEEPFNGLBLENDFUNCSEPARATEEXTPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
  GLEE_EXTERN GLEEPFNGLBLENDFUNCSEPARATEEXTPROC GLeeFuncPtr_glBlendFuncSeparateEXT;
  #define glBlendFuncSeparateEXT GLeeFuncPtr_glBlendFuncSeparateEXT
#endif
#endif

/* GL_INGR_color_clamp */

#ifndef GL_INGR_color_clamp
#define GL_INGR_color_clamp 1
#define __GLEE_GL_INGR_color_clamp 1
/* Constants */
#define GL_RED_MIN_CLAMP_INGR                              0x8560
#define GL_GREEN_MIN_CLAMP_INGR                            0x8561
#define GL_BLUE_MIN_CLAMP_INGR                             0x8562
#define GL_ALPHA_MIN_CLAMP_INGR                            0x8563
#define GL_RED_MAX_CLAMP_INGR                              0x8564
#define GL_GREEN_MAX_CLAMP_INGR                            0x8565
#define GL_BLUE_MAX_CLAMP_INGR                             0x8566
#define GL_ALPHA_MAX_CLAMP_INGR                            0x8567
#endif

/* GL_INGR_interlace_read */

#ifndef GL_INGR_interlace_read
#define GL_INGR_interlace_read 1
#define __GLEE_GL_INGR_interlace_read 1
/* Constants */
#define GL_INTERLACE_READ_INGR                             0x8568
#endif

/* GL_EXT_stencil_wrap */

#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap 1
#define __GLEE_GL_EXT_stencil_wrap 1
/* Constants */
#define GL_INCR_WRAP_EXT                                   0x8507
#define GL_DECR_WRAP_EXT                                   0x8508
#endif

/* GL_EXT_422_pixels */

#ifndef GL_EXT_422_pixels
#define GL_EXT_422_pixels 1
#define __GLEE_GL_EXT_422_pixels 1
/* Constants */
#define GL_422_EXT                                         0x80CC
#define GL_422_REV_EXT                                     0x80CD
#define GL_422_AVERAGE_EXT                                 0x80CE
#define GL_422_REV_AVERAGE_EXT                             0x80CF
#endif

/* GL_NV_texgen_reflection */

#ifndef GL_NV_texgen_reflection
#define GL_NV_texgen_reflection 1
#define __GLEE_GL_NV_texgen_reflection 1
/* Constants */
#define GL_NORMAL_MAP_NV                                   0x8511
#define GL_REFLECTION_MAP_NV                               0x8512
#endif

/* GL_EXT_texture_cube_map */

#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map 1
#define __GLEE_GL_EXT_texture_cube_map 1
/* Constants */
#define GL_NORMAL_MAP_EXT                                  0x8511
#define GL_REFLECTION_MAP_EXT                              0x8512
#define GL_TEXTURE_CUBE_MAP_EXT                            0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT                    0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT                 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT                 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT                 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT                 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT                 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT                 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT                      0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT                   0x851C
#endif

/* GL_SUN_convolution_border_modes */

#ifndef GL_SUN_convolution_border_modes
#define GL_SUN_convolution_border_modes 1
#define __GLEE_GL_SUN_convolution_border_modes 1
/* Constants */
#define GL_WRAP_BORDER_SUN                                 0x81D4
#endif

/* GL_EXT_texture_env_add */

#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add 1
#define __GLEE_GL_EXT_texture_env_add 1
/* Constants */
#endif

/* GL_EXT_texture_lod_bias */

#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias 1
#define __GLEE_GL_EXT_texture_lod_bias 1
/* Constants */
#define GL_MAX_TEXTURE_LOD_BIAS_EXT                        0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT                      0x8500
#define GL_TEXTURE_LOD_BIAS_EXT                            0x8501
#endif

/* GL_EXT_texture_filter_anisotropic */

#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic 1
#define __GLEE_GL_EXT_texture_filter_anisotropic 1
/* Constants */
#define GL_TEXTURE_MAX_ANISOTROPY_EXT                      0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT                  0x84FF
#endif

/* GL_EXT_vertex_weighting */

#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting 1
#define __GLEE_GL_EXT_vertex_weighting 1
/* Constants */
#define GL_MODELVIEW0_STACK_DEPTH_EXT                      GL_MODELVIEW_STACK_DEPTH
#define GL_MODELVIEW1_STACK_DEPTH_EXT                      0x8502
#define GL_MODELVIEW0_MATRIX_EXT                           GL_MODELVIEW_MATRIX
#define GL_MODELVIEW1_MATRIX_EXT                           0x8506
#define GL_VERTEX_WEIGHTING_EXT                            0x8509
#define GL_MODELVIEW0_EXT                                  GL_MODELVIEW
#define GL_MODELVIEW1_EXT                                  0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT                       0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT                         0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT                    0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT                    0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT                  0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT                 0x8510
#ifndef GLEE_H_DEFINED_glVertexWeightfEXT
#define GLEE_H_DEFINED_glVertexWeightfEXT
  typedef void (APIENTRYP GLEEPFNGLVERTEXWEIGHTFEXTPROC) (GLfloat weight);
  GLEE_EXTERN GLEEPFNGLVERTEXWEIGHTFEXTPROC GLeeFuncPtr_glVertexWeightfEXT;
  #define glVertexWeightfEXT GLeeFuncPtr_glVertexWeightfEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexWeightfvEXT
#define GLEE_H_DEFINED_glVertexWeightfvEXT
  typedef void (APIENTRYP GLEEPFNGLVERTEXWEIGHTFVEXTPROC) (const GLfloat * weight);
  GLEE_EXTERN GLEEPFNGLVERTEXWEIGHTFVEXTPROC GLeeFuncPtr_glVertexWeightfvEXT;
  #define glVertexWeightfvEXT GLeeFuncPtr_glVertexWeightfvEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexWeightPointerEXT
#define GLEE_H_DEFINED_glVertexWeightPointerEXT
  typedef void (APIENTRYP GLEEPFNGLVERTEXWEIGHTPOINTEREXTPROC) (GLsizei size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXWEIGHTPOINTEREXTPROC GLeeFuncPtr_glVertexWeightPointerEXT;
  #define glVertexWeightPointerEXT GLeeFuncPtr_glVertexWeightPointerEXT
#endif
#endif

/* GL_NV_light_max_exponent */

#ifndef GL_NV_light_max_exponent
#define GL_NV_light_max_exponent 1
#define __GLEE_GL_NV_light_max_exponent 1
/* Constants */
#define GL_MAX_SHININESS_NV                                0x8504
#define GL_MAX_SPOT_EXPONENT_NV                            0x8505
#endif

/* GL_NV_vertex_array_range */

#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1
#define __GLEE_GL_NV_vertex_array_range 1
/* Constants */
#define GL_VERTEX_ARRAY_RANGE_NV                           0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV                    0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV                     0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV               0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV                   0x8521
#ifndef GLEE_H_DEFINED_glFlushVertexArrayRangeNV
#define GLEE_H_DEFINED_glFlushVertexArrayRangeNV
  typedef void (APIENTRYP GLEEPFNGLFLUSHVERTEXARRAYRANGENVPROC) ();
  GLEE_EXTERN GLEEPFNGLFLUSHVERTEXARRAYRANGENVPROC GLeeFuncPtr_glFlushVertexArrayRangeNV;
  #define glFlushVertexArrayRangeNV GLeeFuncPtr_glFlushVertexArrayRangeNV
#endif
#ifndef GLEE_H_DEFINED_glVertexArrayRangeNV
#define GLEE_H_DEFINED_glVertexArrayRangeNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXARRAYRANGENVPROC) (GLsizei length, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXARRAYRANGENVPROC GLeeFuncPtr_glVertexArrayRangeNV;
  #define glVertexArrayRangeNV GLeeFuncPtr_glVertexArrayRangeNV
#endif
#endif

/* GL_NV_register_combiners */

#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1
#define __GLEE_GL_NV_register_combiners 1
/* Constants */
#define GL_REGISTER_COMBINERS_NV                           0x8522
#define GL_VARIABLE_A_NV                                   0x8523
#define GL_VARIABLE_B_NV                                   0x8524
#define GL_VARIABLE_C_NV                                   0x8525
#define GL_VARIABLE_D_NV                                   0x8526
#define GL_VARIABLE_E_NV                                   0x8527
#define GL_VARIABLE_F_NV                                   0x8528
#define GL_VARIABLE_G_NV                                   0x8529
#define GL_CONSTANT_COLOR0_NV                              0x852A
#define GL_CONSTANT_COLOR1_NV                              0x852B
#define GL_PRIMARY_COLOR_NV                                0x852C
#define GL_SECONDARY_COLOR_NV                              0x852D
#define GL_SPARE0_NV                                       0x852E
#define GL_SPARE1_NV                                       0x852F
#define GL_DISCARD_NV                                      0x8530
#define GL_E_TIMES_F_NV                                    0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV                  0x8532
#define GL_UNSIGNED_IDENTITY_NV                            0x8536
#define GL_UNSIGNED_INVERT_NV                              0x8537
#define GL_EXPAND_NORMAL_NV                                0x8538
#define GL_EXPAND_NEGATE_NV                                0x8539
#define GL_HALF_BIAS_NORMAL_NV                             0x853A
#define GL_HALF_BIAS_NEGATE_NV                             0x853B
#define GL_SIGNED_IDENTITY_NV                              0x853C
#define GL_SIGNED_NEGATE_NV                                0x853D
#define GL_SCALE_BY_TWO_NV                                 0x853E
#define GL_SCALE_BY_FOUR_NV                                0x853F
#define GL_SCALE_BY_ONE_HALF_NV                            0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV                    0x8541
#define GL_COMBINER_INPUT_NV                               0x8542
#define GL_COMBINER_MAPPING_NV                             0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV                     0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV                      0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV                      0x8546
#define GL_COMBINER_MUX_SUM_NV                             0x8547
#define GL_COMBINER_SCALE_NV                               0x8548
#define GL_COMBINER_BIAS_NV                                0x8549
#define GL_COMBINER_AB_OUTPUT_NV                           0x854A
#define GL_COMBINER_CD_OUTPUT_NV                           0x854B
#define GL_COMBINER_SUM_OUTPUT_NV                          0x854C
#define GL_MAX_GENERAL_COMBINERS_NV                        0x854D
#define GL_NUM_GENERAL_COMBINERS_NV                        0x854E
#define GL_COLOR_SUM_CLAMP_NV                              0x854F
#define GL_COMBINER0_NV                                    0x8550
#define GL_COMBINER1_NV                                    0x8551
#define GL_COMBINER2_NV                                    0x8552
#define GL_COMBINER3_NV                                    0x8553
#define GL_COMBINER4_NV                                    0x8554
#define GL_COMBINER5_NV                                    0x8555
#define GL_COMBINER6_NV                                    0x8556
#define GL_COMBINER7_NV                                    0x8557
#ifndef GLEE_H_DEFINED_glCombinerParameterfvNV
#define GLEE_H_DEFINED_glCombinerParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLCOMBINERPARAMETERFVNVPROC) (GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLCOMBINERPARAMETERFVNVPROC GLeeFuncPtr_glCombinerParameterfvNV;
  #define glCombinerParameterfvNV GLeeFuncPtr_glCombinerParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glCombinerParameterfNV
#define GLEE_H_DEFINED_glCombinerParameterfNV
  typedef void (APIENTRYP GLEEPFNGLCOMBINERPARAMETERFNVPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLCOMBINERPARAMETERFNVPROC GLeeFuncPtr_glCombinerParameterfNV;
  #define glCombinerParameterfNV GLeeFuncPtr_glCombinerParameterfNV
#endif
#ifndef GLEE_H_DEFINED_glCombinerParameterivNV
#define GLEE_H_DEFINED_glCombinerParameterivNV
  typedef void (APIENTRYP GLEEPFNGLCOMBINERPARAMETERIVNVPROC) (GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLCOMBINERPARAMETERIVNVPROC GLeeFuncPtr_glCombinerParameterivNV;
  #define glCombinerParameterivNV GLeeFuncPtr_glCombinerParameterivNV
#endif
#ifndef GLEE_H_DEFINED_glCombinerParameteriNV
#define GLEE_H_DEFINED_glCombinerParameteriNV
  typedef void (APIENTRYP GLEEPFNGLCOMBINERPARAMETERINVPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLCOMBINERPARAMETERINVPROC GLeeFuncPtr_glCombinerParameteriNV;
  #define glCombinerParameteriNV GLeeFuncPtr_glCombinerParameteriNV
#endif
#ifndef GLEE_H_DEFINED_glCombinerInputNV
#define GLEE_H_DEFINED_glCombinerInputNV
  typedef void (APIENTRYP GLEEPFNGLCOMBINERINPUTNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
  GLEE_EXTERN GLEEPFNGLCOMBINERINPUTNVPROC GLeeFuncPtr_glCombinerInputNV;
  #define glCombinerInputNV GLeeFuncPtr_glCombinerInputNV
#endif
#ifndef GLEE_H_DEFINED_glCombinerOutputNV
#define GLEE_H_DEFINED_glCombinerOutputNV
  typedef void (APIENTRYP GLEEPFNGLCOMBINEROUTPUTNVPROC) (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
  GLEE_EXTERN GLEEPFNGLCOMBINEROUTPUTNVPROC GLeeFuncPtr_glCombinerOutputNV;
  #define glCombinerOutputNV GLeeFuncPtr_glCombinerOutputNV
#endif
#ifndef GLEE_H_DEFINED_glFinalCombinerInputNV
#define GLEE_H_DEFINED_glFinalCombinerInputNV
  typedef void (APIENTRYP GLEEPFNGLFINALCOMBINERINPUTNVPROC) (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
  GLEE_EXTERN GLEEPFNGLFINALCOMBINERINPUTNVPROC GLeeFuncPtr_glFinalCombinerInputNV;
  #define glFinalCombinerInputNV GLeeFuncPtr_glFinalCombinerInputNV
#endif
#ifndef GLEE_H_DEFINED_glGetCombinerInputParameterfvNV
#define GLEE_H_DEFINED_glGetCombinerInputParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETCOMBINERINPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCOMBINERINPUTPARAMETERFVNVPROC GLeeFuncPtr_glGetCombinerInputParameterfvNV;
  #define glGetCombinerInputParameterfvNV GLeeFuncPtr_glGetCombinerInputParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetCombinerInputParameterivNV
#define GLEE_H_DEFINED_glGetCombinerInputParameterivNV
  typedef void (APIENTRYP GLEEPFNGLGETCOMBINERINPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETCOMBINERINPUTPARAMETERIVNVPROC GLeeFuncPtr_glGetCombinerInputParameterivNV;
  #define glGetCombinerInputParameterivNV GLeeFuncPtr_glGetCombinerInputParameterivNV
#endif
#ifndef GLEE_H_DEFINED_glGetCombinerOutputParameterfvNV
#define GLEE_H_DEFINED_glGetCombinerOutputParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC GLeeFuncPtr_glGetCombinerOutputParameterfvNV;
  #define glGetCombinerOutputParameterfvNV GLeeFuncPtr_glGetCombinerOutputParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetCombinerOutputParameterivNV
#define GLEE_H_DEFINED_glGetCombinerOutputParameterivNV
  typedef void (APIENTRYP GLEEPFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC GLeeFuncPtr_glGetCombinerOutputParameterivNV;
  #define glGetCombinerOutputParameterivNV GLeeFuncPtr_glGetCombinerOutputParameterivNV
#endif
#ifndef GLEE_H_DEFINED_glGetFinalCombinerInputParameterfvNV
#define GLEE_H_DEFINED_glGetFinalCombinerInputParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) (GLenum variable, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC GLeeFuncPtr_glGetFinalCombinerInputParameterfvNV;
  #define glGetFinalCombinerInputParameterfvNV GLeeFuncPtr_glGetFinalCombinerInputParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetFinalCombinerInputParameterivNV
#define GLEE_H_DEFINED_glGetFinalCombinerInputParameterivNV
  typedef void (APIENTRYP GLEEPFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) (GLenum variable, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC GLeeFuncPtr_glGetFinalCombinerInputParameterivNV;
  #define glGetFinalCombinerInputParameterivNV GLeeFuncPtr_glGetFinalCombinerInputParameterivNV
#endif
#endif

/* GL_NV_fog_distance */

#ifndef GL_NV_fog_distance
#define GL_NV_fog_distance 1
#define __GLEE_GL_NV_fog_distance 1
/* Constants */
#define GL_FOG_DISTANCE_MODE_NV                            0x855A
#define GL_EYE_RADIAL_NV                                   0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV                           0x855C
#endif

/* GL_NV_texgen_emboss */

#ifndef GL_NV_texgen_emboss
#define GL_NV_texgen_emboss 1
#define __GLEE_GL_NV_texgen_emboss 1
/* Constants */
#define GL_EMBOSS_LIGHT_NV                                 0x855D
#define GL_EMBOSS_CONSTANT_NV                              0x855E
#define GL_EMBOSS_MAP_NV                                   0x855F
#endif

/* GL_NV_blend_square */

#ifndef GL_NV_blend_square
#define GL_NV_blend_square 1
#define __GLEE_GL_NV_blend_square 1
/* Constants */
#endif

/* GL_NV_texture_env_combine4 */

#ifndef GL_NV_texture_env_combine4
#define GL_NV_texture_env_combine4 1
#define __GLEE_GL_NV_texture_env_combine4 1
/* Constants */
#define GL_COMBINE4_NV                                     0x8503
#define GL_SOURCE3_RGB_NV                                  0x8583
#define GL_SOURCE3_ALPHA_NV                                0x858B
#define GL_OPERAND3_RGB_NV                                 0x8593
#define GL_OPERAND3_ALPHA_NV                               0x859B
#endif

/* GL_MESA_resize_buffers */

#ifndef GL_MESA_resize_buffers
#define GL_MESA_resize_buffers 1
#define __GLEE_GL_MESA_resize_buffers 1
/* Constants */
#ifndef GLEE_H_DEFINED_glResizeBuffersMESA
#define GLEE_H_DEFINED_glResizeBuffersMESA
  typedef void (APIENTRYP GLEEPFNGLRESIZEBUFFERSMESAPROC) ();
  GLEE_EXTERN GLEEPFNGLRESIZEBUFFERSMESAPROC GLeeFuncPtr_glResizeBuffersMESA;
  #define glResizeBuffersMESA GLeeFuncPtr_glResizeBuffersMESA
#endif
#endif

/* GL_MESA_window_pos */

#ifndef GL_MESA_window_pos
#define GL_MESA_window_pos 1
#define __GLEE_GL_MESA_window_pos 1
/* Constants */
#ifndef GLEE_H_DEFINED_glWindowPos2dMESA
#define GLEE_H_DEFINED_glWindowPos2dMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2DMESAPROC) (GLdouble x, GLdouble y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2DMESAPROC GLeeFuncPtr_glWindowPos2dMESA;
  #define glWindowPos2dMESA GLeeFuncPtr_glWindowPos2dMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2dvMESA
#define GLEE_H_DEFINED_glWindowPos2dvMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2DVMESAPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2DVMESAPROC GLeeFuncPtr_glWindowPos2dvMESA;
  #define glWindowPos2dvMESA GLeeFuncPtr_glWindowPos2dvMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2fMESA
#define GLEE_H_DEFINED_glWindowPos2fMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2FMESAPROC) (GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2FMESAPROC GLeeFuncPtr_glWindowPos2fMESA;
  #define glWindowPos2fMESA GLeeFuncPtr_glWindowPos2fMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2fvMESA
#define GLEE_H_DEFINED_glWindowPos2fvMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2FVMESAPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2FVMESAPROC GLeeFuncPtr_glWindowPos2fvMESA;
  #define glWindowPos2fvMESA GLeeFuncPtr_glWindowPos2fvMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2iMESA
#define GLEE_H_DEFINED_glWindowPos2iMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2IMESAPROC) (GLint x, GLint y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2IMESAPROC GLeeFuncPtr_glWindowPos2iMESA;
  #define glWindowPos2iMESA GLeeFuncPtr_glWindowPos2iMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2ivMESA
#define GLEE_H_DEFINED_glWindowPos2ivMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2IVMESAPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2IVMESAPROC GLeeFuncPtr_glWindowPos2ivMESA;
  #define glWindowPos2ivMESA GLeeFuncPtr_glWindowPos2ivMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2sMESA
#define GLEE_H_DEFINED_glWindowPos2sMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2SMESAPROC) (GLshort x, GLshort y);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2SMESAPROC GLeeFuncPtr_glWindowPos2sMESA;
  #define glWindowPos2sMESA GLeeFuncPtr_glWindowPos2sMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos2svMESA
#define GLEE_H_DEFINED_glWindowPos2svMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS2SVMESAPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS2SVMESAPROC GLeeFuncPtr_glWindowPos2svMESA;
  #define glWindowPos2svMESA GLeeFuncPtr_glWindowPos2svMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3dMESA
#define GLEE_H_DEFINED_glWindowPos3dMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3DMESAPROC) (GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3DMESAPROC GLeeFuncPtr_glWindowPos3dMESA;
  #define glWindowPos3dMESA GLeeFuncPtr_glWindowPos3dMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3dvMESA
#define GLEE_H_DEFINED_glWindowPos3dvMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3DVMESAPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3DVMESAPROC GLeeFuncPtr_glWindowPos3dvMESA;
  #define glWindowPos3dvMESA GLeeFuncPtr_glWindowPos3dvMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3fMESA
#define GLEE_H_DEFINED_glWindowPos3fMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3FMESAPROC) (GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3FMESAPROC GLeeFuncPtr_glWindowPos3fMESA;
  #define glWindowPos3fMESA GLeeFuncPtr_glWindowPos3fMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3fvMESA
#define GLEE_H_DEFINED_glWindowPos3fvMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3FVMESAPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3FVMESAPROC GLeeFuncPtr_glWindowPos3fvMESA;
  #define glWindowPos3fvMESA GLeeFuncPtr_glWindowPos3fvMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3iMESA
#define GLEE_H_DEFINED_glWindowPos3iMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3IMESAPROC) (GLint x, GLint y, GLint z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3IMESAPROC GLeeFuncPtr_glWindowPos3iMESA;
  #define glWindowPos3iMESA GLeeFuncPtr_glWindowPos3iMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3ivMESA
#define GLEE_H_DEFINED_glWindowPos3ivMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3IVMESAPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3IVMESAPROC GLeeFuncPtr_glWindowPos3ivMESA;
  #define glWindowPos3ivMESA GLeeFuncPtr_glWindowPos3ivMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3sMESA
#define GLEE_H_DEFINED_glWindowPos3sMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3SMESAPROC) (GLshort x, GLshort y, GLshort z);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3SMESAPROC GLeeFuncPtr_glWindowPos3sMESA;
  #define glWindowPos3sMESA GLeeFuncPtr_glWindowPos3sMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos3svMESA
#define GLEE_H_DEFINED_glWindowPos3svMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS3SVMESAPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS3SVMESAPROC GLeeFuncPtr_glWindowPos3svMESA;
  #define glWindowPos3svMESA GLeeFuncPtr_glWindowPos3svMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4dMESA
#define GLEE_H_DEFINED_glWindowPos4dMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4DMESAPROC) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4DMESAPROC GLeeFuncPtr_glWindowPos4dMESA;
  #define glWindowPos4dMESA GLeeFuncPtr_glWindowPos4dMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4dvMESA
#define GLEE_H_DEFINED_glWindowPos4dvMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4DVMESAPROC) (const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4DVMESAPROC GLeeFuncPtr_glWindowPos4dvMESA;
  #define glWindowPos4dvMESA GLeeFuncPtr_glWindowPos4dvMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4fMESA
#define GLEE_H_DEFINED_glWindowPos4fMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4FMESAPROC) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4FMESAPROC GLeeFuncPtr_glWindowPos4fMESA;
  #define glWindowPos4fMESA GLeeFuncPtr_glWindowPos4fMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4fvMESA
#define GLEE_H_DEFINED_glWindowPos4fvMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4FVMESAPROC) (const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4FVMESAPROC GLeeFuncPtr_glWindowPos4fvMESA;
  #define glWindowPos4fvMESA GLeeFuncPtr_glWindowPos4fvMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4iMESA
#define GLEE_H_DEFINED_glWindowPos4iMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4IMESAPROC) (GLint x, GLint y, GLint z, GLint w);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4IMESAPROC GLeeFuncPtr_glWindowPos4iMESA;
  #define glWindowPos4iMESA GLeeFuncPtr_glWindowPos4iMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4ivMESA
#define GLEE_H_DEFINED_glWindowPos4ivMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4IVMESAPROC) (const GLint * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4IVMESAPROC GLeeFuncPtr_glWindowPos4ivMESA;
  #define glWindowPos4ivMESA GLeeFuncPtr_glWindowPos4ivMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4sMESA
#define GLEE_H_DEFINED_glWindowPos4sMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4SMESAPROC) (GLshort x, GLshort y, GLshort z, GLshort w);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4SMESAPROC GLeeFuncPtr_glWindowPos4sMESA;
  #define glWindowPos4sMESA GLeeFuncPtr_glWindowPos4sMESA
#endif
#ifndef GLEE_H_DEFINED_glWindowPos4svMESA
#define GLEE_H_DEFINED_glWindowPos4svMESA
  typedef void (APIENTRYP GLEEPFNGLWINDOWPOS4SVMESAPROC) (const GLshort * v);
  GLEE_EXTERN GLEEPFNGLWINDOWPOS4SVMESAPROC GLeeFuncPtr_glWindowPos4svMESA;
  #define glWindowPos4svMESA GLeeFuncPtr_glWindowPos4svMESA
#endif
#endif

/* GL_EXT_texture_compression_s3tc */

#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
#define __GLEE_GL_EXT_texture_compression_s3tc 1
/* Constants */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT                    0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT                   0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT                   0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT                   0x83F3
#endif

/* GL_IBM_cull_vertex */

#ifndef GL_IBM_cull_vertex
#define GL_IBM_cull_vertex 1
#define __GLEE_GL_IBM_cull_vertex 1
/* Constants */
#define GL_CULL_VERTEX_IBM                                 103050
#endif

/* GL_IBM_multimode_draw_arrays */

#ifndef GL_IBM_multimode_draw_arrays
#define GL_IBM_multimode_draw_arrays 1
#define __GLEE_GL_IBM_multimode_draw_arrays 1
/* Constants */
#ifndef GLEE_H_DEFINED_glMultiModeDrawArraysIBM
#define GLEE_H_DEFINED_glMultiModeDrawArraysIBM
  typedef void (APIENTRYP GLEEPFNGLMULTIMODEDRAWARRAYSIBMPROC) (const GLenum * mode, const GLint * first, const GLsizei * count, GLsizei primcount, GLint modestride);
  GLEE_EXTERN GLEEPFNGLMULTIMODEDRAWARRAYSIBMPROC GLeeFuncPtr_glMultiModeDrawArraysIBM;
  #define glMultiModeDrawArraysIBM GLeeFuncPtr_glMultiModeDrawArraysIBM
#endif
#ifndef GLEE_H_DEFINED_glMultiModeDrawElementsIBM
#define GLEE_H_DEFINED_glMultiModeDrawElementsIBM
  typedef void (APIENTRYP GLEEPFNGLMULTIMODEDRAWELEMENTSIBMPROC) (const GLenum * mode, const GLsizei * count, GLenum type, const GLvoid* const * indices, GLsizei primcount, GLint modestride);
  GLEE_EXTERN GLEEPFNGLMULTIMODEDRAWELEMENTSIBMPROC GLeeFuncPtr_glMultiModeDrawElementsIBM;
  #define glMultiModeDrawElementsIBM GLeeFuncPtr_glMultiModeDrawElementsIBM
#endif
#endif

/* GL_IBM_vertex_array_lists */

#ifndef GL_IBM_vertex_array_lists
#define GL_IBM_vertex_array_lists 1
#define __GLEE_GL_IBM_vertex_array_lists 1
/* Constants */
#define GL_VERTEX_ARRAY_LIST_IBM                           103070
#define GL_NORMAL_ARRAY_LIST_IBM                           103071
#define GL_COLOR_ARRAY_LIST_IBM                            103072
#define GL_INDEX_ARRAY_LIST_IBM                            103073
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM                    103074
#define GL_EDGE_FLAG_ARRAY_LIST_IBM                        103075
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM                   103076
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM                  103077
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM                    103080
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM                    103081
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM                     103082
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM                     103083
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM             103084
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM                 103085
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM            103086
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM           103087
#ifndef GLEE_H_DEFINED_glColorPointerListIBM
#define GLEE_H_DEFINED_glColorPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLCOLORPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLCOLORPOINTERLISTIBMPROC GLeeFuncPtr_glColorPointerListIBM;
  #define glColorPointerListIBM GLeeFuncPtr_glColorPointerListIBM
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColorPointerListIBM
#define GLEE_H_DEFINED_glSecondaryColorPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLORPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLORPOINTERLISTIBMPROC GLeeFuncPtr_glSecondaryColorPointerListIBM;
  #define glSecondaryColorPointerListIBM GLeeFuncPtr_glSecondaryColorPointerListIBM
#endif
#ifndef GLEE_H_DEFINED_glEdgeFlagPointerListIBM
#define GLEE_H_DEFINED_glEdgeFlagPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLEDGEFLAGPOINTERLISTIBMPROC) (GLint stride, const GLboolean* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLEDGEFLAGPOINTERLISTIBMPROC GLeeFuncPtr_glEdgeFlagPointerListIBM;
  #define glEdgeFlagPointerListIBM GLeeFuncPtr_glEdgeFlagPointerListIBM
#endif
#ifndef GLEE_H_DEFINED_glFogCoordPointerListIBM
#define GLEE_H_DEFINED_glFogCoordPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLFOGCOORDPOINTERLISTIBMPROC GLeeFuncPtr_glFogCoordPointerListIBM;
  #define glFogCoordPointerListIBM GLeeFuncPtr_glFogCoordPointerListIBM
#endif
#ifndef GLEE_H_DEFINED_glIndexPointerListIBM
#define GLEE_H_DEFINED_glIndexPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLINDEXPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLINDEXPOINTERLISTIBMPROC GLeeFuncPtr_glIndexPointerListIBM;
  #define glIndexPointerListIBM GLeeFuncPtr_glIndexPointerListIBM
#endif
#ifndef GLEE_H_DEFINED_glNormalPointerListIBM
#define GLEE_H_DEFINED_glNormalPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLNORMALPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLNORMALPOINTERLISTIBMPROC GLeeFuncPtr_glNormalPointerListIBM;
  #define glNormalPointerListIBM GLeeFuncPtr_glNormalPointerListIBM
#endif
#ifndef GLEE_H_DEFINED_glTexCoordPointerListIBM
#define GLEE_H_DEFINED_glTexCoordPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLTEXCOORDPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLTEXCOORDPOINTERLISTIBMPROC GLeeFuncPtr_glTexCoordPointerListIBM;
  #define glTexCoordPointerListIBM GLeeFuncPtr_glTexCoordPointerListIBM
#endif
#ifndef GLEE_H_DEFINED_glVertexPointerListIBM
#define GLEE_H_DEFINED_glVertexPointerListIBM
  typedef void (APIENTRYP GLEEPFNGLVERTEXPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
  GLEE_EXTERN GLEEPFNGLVERTEXPOINTERLISTIBMPROC GLeeFuncPtr_glVertexPointerListIBM;
  #define glVertexPointerListIBM GLeeFuncPtr_glVertexPointerListIBM
#endif
#endif

/* GL_SGIX_subsample */

#ifndef GL_SGIX_subsample
#define GL_SGIX_subsample 1
#define __GLEE_GL_SGIX_subsample 1
/* Constants */
#define GL_PACK_SUBSAMPLE_RATE_SGIX                        0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX                      0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX                       0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX                       0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX                       0x85A4
#endif

/* GL_SGIX_ycrcb_subsample */

#ifndef GL_SGIX_ycrcb_subsample
#define GL_SGIX_ycrcb_subsample 1
#define __GLEE_GL_SGIX_ycrcb_subsample 1
/* Constants */
#endif

/* GL_SGIX_ycrcba */

#ifndef GL_SGIX_ycrcba
#define GL_SGIX_ycrcba 1
#define __GLEE_GL_SGIX_ycrcba 1
/* Constants */
#define GL_YCRCB_SGIX                                      0x8318
#define GL_YCRCBA_SGIX                                     0x8319
#endif

/* GL_SGI_depth_pass_instrument */

#ifndef GL_SGI_depth_pass_instrument
#define GL_SGI_depth_pass_instrument 1
#define __GLEE_GL_SGI_depth_pass_instrument 1
/* Constants */
#define GL_DEPTH_PASS_INSTRUMENT_SGIX                      0x8310
#define GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX             0x8311
#define GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX                  0x8312
#endif

/* GL_3DFX_texture_compression_FXT1 */

#ifndef GL_3DFX_texture_compression_FXT1
#define GL_3DFX_texture_compression_FXT1 1
#define __GLEE_GL_3DFX_texture_compression_FXT1 1
/* Constants */
#define GL_COMPRESSED_RGB_FXT1_3DFX                        0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX                       0x86B1
#endif

/* GL_3DFX_multisample */

#ifndef GL_3DFX_multisample
#define GL_3DFX_multisample 1
#define __GLEE_GL_3DFX_multisample 1
/* Constants */
#define GL_MULTISAMPLE_3DFX                                0x86B2
#define GL_SAMPLE_BUFFERS_3DFX                             0x86B3
#define GL_SAMPLES_3DFX                                    0x86B4
#define GL_MULTISAMPLE_BIT_3DFX                            0x20000000
#endif

/* GL_3DFX_tbuffer */

#ifndef GL_3DFX_tbuffer
#define GL_3DFX_tbuffer 1
#define __GLEE_GL_3DFX_tbuffer 1
/* Constants */
#ifndef GLEE_H_DEFINED_glTbufferMask3DFX
#define GLEE_H_DEFINED_glTbufferMask3DFX
  typedef void (APIENTRYP GLEEPFNGLTBUFFERMASK3DFXPROC) (GLuint mask);
  GLEE_EXTERN GLEEPFNGLTBUFFERMASK3DFXPROC GLeeFuncPtr_glTbufferMask3DFX;
  #define glTbufferMask3DFX GLeeFuncPtr_glTbufferMask3DFX
#endif
#endif

/* GL_EXT_multisample */

#ifndef GL_EXT_multisample
#define GL_EXT_multisample 1
#define __GLEE_GL_EXT_multisample 1
/* Constants */
#define GL_MULTISAMPLE_EXT                                 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT                        0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT                         0x809F
#define GL_SAMPLE_MASK_EXT                                 0x80A0
#define GL_1PASS_EXT                                       0x80A1
#define GL_2PASS_0_EXT                                     0x80A2
#define GL_2PASS_1_EXT                                     0x80A3
#define GL_4PASS_0_EXT                                     0x80A4
#define GL_4PASS_1_EXT                                     0x80A5
#define GL_4PASS_2_EXT                                     0x80A6
#define GL_4PASS_3_EXT                                     0x80A7
#define GL_SAMPLE_BUFFERS_EXT                              0x80A8
#define GL_SAMPLES_EXT                                     0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT                           0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT                          0x80AB
#define GL_SAMPLE_PATTERN_EXT                              0x80AC
#define GL_MULTISAMPLE_BIT_EXT                             0x20000000
#ifndef GLEE_H_DEFINED_glSampleMaskEXT
#define GLEE_H_DEFINED_glSampleMaskEXT
  typedef void (APIENTRYP GLEEPFNGLSAMPLEMASKEXTPROC) (GLclampf value, GLboolean invert);
  GLEE_EXTERN GLEEPFNGLSAMPLEMASKEXTPROC GLeeFuncPtr_glSampleMaskEXT;
  #define glSampleMaskEXT GLeeFuncPtr_glSampleMaskEXT
#endif
#ifndef GLEE_H_DEFINED_glSamplePatternEXT
#define GLEE_H_DEFINED_glSamplePatternEXT
  typedef void (APIENTRYP GLEEPFNGLSAMPLEPATTERNEXTPROC) (GLenum pattern);
  GLEE_EXTERN GLEEPFNGLSAMPLEPATTERNEXTPROC GLeeFuncPtr_glSamplePatternEXT;
  #define glSamplePatternEXT GLeeFuncPtr_glSamplePatternEXT
#endif
#endif

/* GL_SGIX_vertex_preclip */

#ifndef GL_SGIX_vertex_preclip
#define GL_SGIX_vertex_preclip 1
#define __GLEE_GL_SGIX_vertex_preclip 1
/* Constants */
#define GL_VERTEX_PRECLIP_SGIX                             0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX                        0x83EF
#endif

/* GL_SGIX_convolution_accuracy */

#ifndef GL_SGIX_convolution_accuracy
#define GL_SGIX_convolution_accuracy 1
#define __GLEE_GL_SGIX_convolution_accuracy 1
/* Constants */
#define GL_CONVOLUTION_HINT_SGIX                           0x8316
#endif

/* GL_SGIX_resample */

#ifndef GL_SGIX_resample
#define GL_SGIX_resample 1
#define __GLEE_GL_SGIX_resample 1
/* Constants */
#define GL_PACK_RESAMPLE_SGIX                              0x842C
#define GL_UNPACK_RESAMPLE_SGIX                            0x842D
#define GL_RESAMPLE_REPLICATE_SGIX                         0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX                         0x842F
#define GL_RESAMPLE_DECIMATE_SGIX                          0x8430
#endif

/* GL_SGIS_point_line_texgen */

#ifndef GL_SGIS_point_line_texgen
#define GL_SGIS_point_line_texgen 1
#define __GLEE_GL_SGIS_point_line_texgen 1
/* Constants */
#define GL_EYE_DISTANCE_TO_POINT_SGIS                      0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS                   0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS                       0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS                    0x81F3
#define GL_EYE_POINT_SGIS                                  0x81F4
#define GL_OBJECT_POINT_SGIS                               0x81F5
#define GL_EYE_LINE_SGIS                                   0x81F6
#define GL_OBJECT_LINE_SGIS                                0x81F7
#endif

/* GL_SGIS_texture_color_mask */

#ifndef GL_SGIS_texture_color_mask
#define GL_SGIS_texture_color_mask 1
#define __GLEE_GL_SGIS_texture_color_mask 1
/* Constants */
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS                    0x81EF
#ifndef GLEE_H_DEFINED_glTextureColorMaskSGIS
#define GLEE_H_DEFINED_glTextureColorMaskSGIS
  typedef void (APIENTRYP GLEEPFNGLTEXTURECOLORMASKSGISPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
  GLEE_EXTERN GLEEPFNGLTEXTURECOLORMASKSGISPROC GLeeFuncPtr_glTextureColorMaskSGIS;
  #define glTextureColorMaskSGIS GLeeFuncPtr_glTextureColorMaskSGIS
#endif
#endif

/* GL_EXT_texture_env_dot3 */

#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3 1
#define __GLEE_GL_EXT_texture_env_dot3 1
/* Constants */
#define GL_DOT3_RGB_EXT                                    0x8740
#define GL_DOT3_RGBA_EXT                                   0x8741
#endif

/* GL_ATI_texture_mirror_once */

#ifndef GL_ATI_texture_mirror_once
#define GL_ATI_texture_mirror_once 1
#define __GLEE_GL_ATI_texture_mirror_once 1
/* Constants */
#define GL_MIRROR_CLAMP_ATI                                0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI                        0x8743
#endif

/* GL_NV_fence */

#ifndef GL_NV_fence
#define GL_NV_fence 1
#define __GLEE_GL_NV_fence 1
/* Constants */
#define GL_ALL_COMPLETED_NV                                0x84F2
#define GL_FENCE_STATUS_NV                                 0x84F3
#define GL_FENCE_CONDITION_NV                              0x84F4
#ifndef GLEE_H_DEFINED_glDeleteFencesNV
#define GLEE_H_DEFINED_glDeleteFencesNV
  typedef void (APIENTRYP GLEEPFNGLDELETEFENCESNVPROC) (GLsizei n, const GLuint * fences);
  GLEE_EXTERN GLEEPFNGLDELETEFENCESNVPROC GLeeFuncPtr_glDeleteFencesNV;
  #define glDeleteFencesNV GLeeFuncPtr_glDeleteFencesNV
#endif
#ifndef GLEE_H_DEFINED_glGenFencesNV
#define GLEE_H_DEFINED_glGenFencesNV
  typedef void (APIENTRYP GLEEPFNGLGENFENCESNVPROC) (GLsizei n, GLuint * fences);
  GLEE_EXTERN GLEEPFNGLGENFENCESNVPROC GLeeFuncPtr_glGenFencesNV;
  #define glGenFencesNV GLeeFuncPtr_glGenFencesNV
#endif
#ifndef GLEE_H_DEFINED_glIsFenceNV
#define GLEE_H_DEFINED_glIsFenceNV
  typedef GLboolean (APIENTRYP GLEEPFNGLISFENCENVPROC) (GLuint fence);
  GLEE_EXTERN GLEEPFNGLISFENCENVPROC GLeeFuncPtr_glIsFenceNV;
  #define glIsFenceNV GLeeFuncPtr_glIsFenceNV
#endif
#ifndef GLEE_H_DEFINED_glTestFenceNV
#define GLEE_H_DEFINED_glTestFenceNV
  typedef GLboolean (APIENTRYP GLEEPFNGLTESTFENCENVPROC) (GLuint fence);
  GLEE_EXTERN GLEEPFNGLTESTFENCENVPROC GLeeFuncPtr_glTestFenceNV;
  #define glTestFenceNV GLeeFuncPtr_glTestFenceNV
#endif
#ifndef GLEE_H_DEFINED_glGetFenceivNV
#define GLEE_H_DEFINED_glGetFenceivNV
  typedef void (APIENTRYP GLEEPFNGLGETFENCEIVNVPROC) (GLuint fence, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFENCEIVNVPROC GLeeFuncPtr_glGetFenceivNV;
  #define glGetFenceivNV GLeeFuncPtr_glGetFenceivNV
#endif
#ifndef GLEE_H_DEFINED_glFinishFenceNV
#define GLEE_H_DEFINED_glFinishFenceNV
  typedef void (APIENTRYP GLEEPFNGLFINISHFENCENVPROC) (GLuint fence);
  GLEE_EXTERN GLEEPFNGLFINISHFENCENVPROC GLeeFuncPtr_glFinishFenceNV;
  #define glFinishFenceNV GLeeFuncPtr_glFinishFenceNV
#endif
#ifndef GLEE_H_DEFINED_glSetFenceNV
#define GLEE_H_DEFINED_glSetFenceNV
  typedef void (APIENTRYP GLEEPFNGLSETFENCENVPROC) (GLuint fence, GLenum condition);
  GLEE_EXTERN GLEEPFNGLSETFENCENVPROC GLeeFuncPtr_glSetFenceNV;
  #define glSetFenceNV GLeeFuncPtr_glSetFenceNV
#endif
#endif

/* GL_IBM_texture_mirrored_repeat */

#ifndef GL_IBM_texture_mirrored_repeat
#define GL_IBM_texture_mirrored_repeat 1
#define __GLEE_GL_IBM_texture_mirrored_repeat 1
/* Constants */
#define GL_MIRRORED_REPEAT_IBM                             0x8370
#endif

/* GL_NV_evaluators */

#ifndef GL_NV_evaluators
#define GL_NV_evaluators 1
#define __GLEE_GL_NV_evaluators 1
/* Constants */
#define GL_EVAL_2D_NV                                      0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV                           0x86C1
#define GL_MAP_TESSELLATION_NV                             0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV                           0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV                           0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV                 0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV                          0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV                          0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV                          0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV                          0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV                          0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV                          0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV                          0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV                          0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV                          0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV                          0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV                         0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV                         0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV                         0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV                         0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV                         0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV                         0x86D5
#define GL_MAX_MAP_TESSELLATION_NV                         0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV                      0x86D7
#ifndef GLEE_H_DEFINED_glMapControlPointsNV
#define GLEE_H_DEFINED_glMapControlPointsNV
  typedef void (APIENTRYP GLEEPFNGLMAPCONTROLPOINTSNVPROC) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid * points);
  GLEE_EXTERN GLEEPFNGLMAPCONTROLPOINTSNVPROC GLeeFuncPtr_glMapControlPointsNV;
  #define glMapControlPointsNV GLeeFuncPtr_glMapControlPointsNV
#endif
#ifndef GLEE_H_DEFINED_glMapParameterivNV
#define GLEE_H_DEFINED_glMapParameterivNV
  typedef void (APIENTRYP GLEEPFNGLMAPPARAMETERIVNVPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLMAPPARAMETERIVNVPROC GLeeFuncPtr_glMapParameterivNV;
  #define glMapParameterivNV GLeeFuncPtr_glMapParameterivNV
#endif
#ifndef GLEE_H_DEFINED_glMapParameterfvNV
#define GLEE_H_DEFINED_glMapParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLMAPPARAMETERFVNVPROC) (GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLMAPPARAMETERFVNVPROC GLeeFuncPtr_glMapParameterfvNV;
  #define glMapParameterfvNV GLeeFuncPtr_glMapParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetMapControlPointsNV
#define GLEE_H_DEFINED_glGetMapControlPointsNV
  typedef void (APIENTRYP GLEEPFNGLGETMAPCONTROLPOINTSNVPROC) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid * points);
  GLEE_EXTERN GLEEPFNGLGETMAPCONTROLPOINTSNVPROC GLeeFuncPtr_glGetMapControlPointsNV;
  #define glGetMapControlPointsNV GLeeFuncPtr_glGetMapControlPointsNV
#endif
#ifndef GLEE_H_DEFINED_glGetMapParameterivNV
#define GLEE_H_DEFINED_glGetMapParameterivNV
  typedef void (APIENTRYP GLEEPFNGLGETMAPPARAMETERIVNVPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMAPPARAMETERIVNVPROC GLeeFuncPtr_glGetMapParameterivNV;
  #define glGetMapParameterivNV GLeeFuncPtr_glGetMapParameterivNV
#endif
#ifndef GLEE_H_DEFINED_glGetMapParameterfvNV
#define GLEE_H_DEFINED_glGetMapParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETMAPPARAMETERFVNVPROC) (GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMAPPARAMETERFVNVPROC GLeeFuncPtr_glGetMapParameterfvNV;
  #define glGetMapParameterfvNV GLeeFuncPtr_glGetMapParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetMapAttribParameterivNV
#define GLEE_H_DEFINED_glGetMapAttribParameterivNV
  typedef void (APIENTRYP GLEEPFNGLGETMAPATTRIBPARAMETERIVNVPROC) (GLenum target, GLuint index, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMAPATTRIBPARAMETERIVNVPROC GLeeFuncPtr_glGetMapAttribParameterivNV;
  #define glGetMapAttribParameterivNV GLeeFuncPtr_glGetMapAttribParameterivNV
#endif
#ifndef GLEE_H_DEFINED_glGetMapAttribParameterfvNV
#define GLEE_H_DEFINED_glGetMapAttribParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETMAPATTRIBPARAMETERFVNVPROC) (GLenum target, GLuint index, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMAPATTRIBPARAMETERFVNVPROC GLeeFuncPtr_glGetMapAttribParameterfvNV;
  #define glGetMapAttribParameterfvNV GLeeFuncPtr_glGetMapAttribParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glEvalMapsNV
#define GLEE_H_DEFINED_glEvalMapsNV
  typedef void (APIENTRYP GLEEPFNGLEVALMAPSNVPROC) (GLenum target, GLenum mode);
  GLEE_EXTERN GLEEPFNGLEVALMAPSNVPROC GLeeFuncPtr_glEvalMapsNV;
  #define glEvalMapsNV GLeeFuncPtr_glEvalMapsNV
#endif
#endif

/* GL_NV_packed_depth_stencil */

#ifndef GL_NV_packed_depth_stencil
#define GL_NV_packed_depth_stencil 1
#define __GLEE_GL_NV_packed_depth_stencil 1
/* Constants */
#define GL_DEPTH_STENCIL_NV                                0x84F9
#define GL_UNSIGNED_INT_24_8_NV                            0x84FA
#endif

/* GL_NV_register_combiners2 */

#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1
#define __GLEE_GL_NV_register_combiners2 1
/* Constants */
#define GL_PER_STAGE_CONSTANTS_NV                          0x8535
#ifndef GLEE_H_DEFINED_glCombinerStageParameterfvNV
#define GLEE_H_DEFINED_glCombinerStageParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLCOMBINERSTAGEPARAMETERFVNVPROC GLeeFuncPtr_glCombinerStageParameterfvNV;
  #define glCombinerStageParameterfvNV GLeeFuncPtr_glCombinerStageParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetCombinerStageParameterfvNV
#define GLEE_H_DEFINED_glGetCombinerStageParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC GLeeFuncPtr_glGetCombinerStageParameterfvNV;
  #define glGetCombinerStageParameterfvNV GLeeFuncPtr_glGetCombinerStageParameterfvNV
#endif
#endif

/* GL_NV_texture_compression_vtc */

#ifndef GL_NV_texture_compression_vtc
#define GL_NV_texture_compression_vtc 1
#define __GLEE_GL_NV_texture_compression_vtc 1
/* Constants */
#endif

/* GL_NV_texture_rectangle */

#ifndef GL_NV_texture_rectangle
#define GL_NV_texture_rectangle 1
#define __GLEE_GL_NV_texture_rectangle 1
/* Constants */
#define GL_TEXTURE_RECTANGLE_NV                            0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV                    0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV                      0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV                   0x84F8
#endif

/* GL_NV_texture_shader */

#ifndef GL_NV_texture_shader
#define GL_NV_texture_shader 1
#define __GLEE_GL_NV_texture_shader 1
/* Constants */
#define GL_OFFSET_TEXTURE_RECTANGLE_NV                     0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV               0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV                0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV            0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV                       0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV                   0x86DB
#define GL_DSDT_MAG_INTENSITY_NV                           0x86DC
#define GL_SHADER_CONSISTENT_NV                            0x86DD
#define GL_TEXTURE_SHADER_NV                               0x86DE
#define GL_SHADER_OPERATION_NV                             0x86DF
#define GL_CULL_MODES_NV                                   0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV                        0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV                         0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV                          0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV                     GL_OFFSET_TEXTURE_MATRIX_NV
#define GL_OFFSET_TEXTURE_2D_SCALE_NV                      GL_OFFSET_TEXTURE_SCALE_NV
#define GL_OFFSET_TEXTURE_2D_BIAS_NV                       GL_OFFSET_TEXTURE_BIAS_NV
#define GL_PREVIOUS_TEXTURE_INPUT_NV                       0x86E4
#define GL_CONST_EYE_NV                                    0x86E5
#define GL_PASS_THROUGH_NV                                 0x86E6
#define GL_CULL_FRAGMENT_NV                                0x86E7
#define GL_OFFSET_TEXTURE_2D_NV                            0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV                      0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV                      0x86EA
#define GL_DOT_PRODUCT_NV                                  0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV                    0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV                       0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV                 0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV                 0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV                 0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV       0x86F3
#define GL_HILO_NV                                         0x86F4
#define GL_DSDT_NV                                         0x86F5
#define GL_DSDT_MAG_NV                                     0x86F6
#define GL_DSDT_MAG_VIB_NV                                 0x86F7
#define GL_HILO16_NV                                       0x86F8
#define GL_SIGNED_HILO_NV                                  0x86F9
#define GL_SIGNED_HILO16_NV                                0x86FA
#define GL_SIGNED_RGBA_NV                                  0x86FB
#define GL_SIGNED_RGBA8_NV                                 0x86FC
#define GL_SIGNED_RGB_NV                                   0x86FE
#define GL_SIGNED_RGB8_NV                                  0x86FF
#define GL_SIGNED_LUMINANCE_NV                             0x8701
#define GL_SIGNED_LUMINANCE8_NV                            0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV                       0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV                     0x8704
#define GL_SIGNED_ALPHA_NV                                 0x8705
#define GL_SIGNED_ALPHA8_NV                                0x8706
#define GL_SIGNED_INTENSITY_NV                             0x8707
#define GL_SIGNED_INTENSITY8_NV                            0x8708
#define GL_DSDT8_NV                                        0x8709
#define GL_DSDT8_MAG8_NV                                   0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV                        0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV                    0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV                  0x870D
#define GL_HI_SCALE_NV                                     0x870E
#define GL_LO_SCALE_NV                                     0x870F
#define GL_DS_SCALE_NV                                     0x8710
#define GL_DT_SCALE_NV                                     0x8711
#define GL_MAGNITUDE_SCALE_NV                              0x8712
#define GL_VIBRANCE_SCALE_NV                               0x8713
#define GL_HI_BIAS_NV                                      0x8714
#define GL_LO_BIAS_NV                                      0x8715
#define GL_DS_BIAS_NV                                      0x8716
#define GL_DT_BIAS_NV                                      0x8717
#define GL_MAGNITUDE_BIAS_NV                               0x8718
#define GL_VIBRANCE_BIAS_NV                                0x8719
#define GL_TEXTURE_BORDER_VALUES_NV                        0x871A
#define GL_TEXTURE_HI_SIZE_NV                              0x871B
#define GL_TEXTURE_LO_SIZE_NV                              0x871C
#define GL_TEXTURE_DS_SIZE_NV                              0x871D
#define GL_TEXTURE_DT_SIZE_NV                              0x871E
#define GL_TEXTURE_MAG_SIZE_NV                             0x871F
#endif

/* GL_NV_texture_shader2 */

#ifndef GL_NV_texture_shader2
#define GL_NV_texture_shader2 1
#define __GLEE_GL_NV_texture_shader2 1
/* Constants */
#define GL_DOT_PRODUCT_TEXTURE_3D_NV                       0x86EF
#endif

/* GL_NV_vertex_array_range2 */

#ifndef GL_NV_vertex_array_range2
#define GL_NV_vertex_array_range2 1
#define __GLEE_GL_NV_vertex_array_range2 1
/* Constants */
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV             0x8533
#endif

/* GL_NV_vertex_program */

#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1
#define __GLEE_GL_NV_vertex_program 1
/* Constants */
#define GL_VERTEX_PROGRAM_NV                               0x8620
#define GL_VERTEX_STATE_PROGRAM_NV                         0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV                            0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV                          0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV                            0x8625
#define GL_CURRENT_ATTRIB_NV                               0x8626
#define GL_PROGRAM_LENGTH_NV                               0x8627
#define GL_PROGRAM_STRING_NV                               0x8628
#define GL_MODELVIEW_PROJECTION_NV                         0x8629
#define GL_IDENTITY_NV                                     0x862A
#define GL_INVERSE_NV                                      0x862B
#define GL_TRANSPOSE_NV                                    0x862C
#define GL_INVERSE_TRANSPOSE_NV                            0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV                 0x862E
#define GL_MAX_TRACK_MATRICES_NV                           0x862F
#define GL_MATRIX0_NV                                      0x8630
#define GL_MATRIX1_NV                                      0x8631
#define GL_MATRIX2_NV                                      0x8632
#define GL_MATRIX3_NV                                      0x8633
#define GL_MATRIX4_NV                                      0x8634
#define GL_MATRIX5_NV                                      0x8635
#define GL_MATRIX6_NV                                      0x8636
#define GL_MATRIX7_NV                                      0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV                   0x8640
#define GL_CURRENT_MATRIX_NV                               0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV                    0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV                      0x8643
#define GL_PROGRAM_PARAMETER_NV                            0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV                         0x8645
#define GL_PROGRAM_TARGET_NV                               0x8646
#define GL_PROGRAM_RESIDENT_NV                             0x8647
#define GL_TRACK_MATRIX_NV                                 0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV                       0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV                       0x864A
#define GL_PROGRAM_ERROR_POSITION_NV                       0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV                         0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV                         0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV                         0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV                         0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV                         0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV                         0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV                         0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV                         0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV                         0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV                         0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV                        0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV                        0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV                        0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV                        0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV                        0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV                        0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV                        0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV                        0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV                        0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV                        0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV                        0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV                        0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV                        0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV                        0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV                        0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV                        0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV                       0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV                       0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV                       0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV                       0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV                       0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV                       0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV                        0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV                        0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV                        0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV                        0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV                        0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV                        0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV                        0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV                        0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV                        0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV                        0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV                       0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV                       0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV                       0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV                       0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV                       0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV                       0x867F
#ifndef GLEE_H_DEFINED_glAreProgramsResidentNV
#define GLEE_H_DEFINED_glAreProgramsResidentNV
  typedef GLboolean (APIENTRYP GLEEPFNGLAREPROGRAMSRESIDENTNVPROC) (GLsizei n, const GLuint * programs, GLboolean * residences);
  GLEE_EXTERN GLEEPFNGLAREPROGRAMSRESIDENTNVPROC GLeeFuncPtr_glAreProgramsResidentNV;
  #define glAreProgramsResidentNV GLeeFuncPtr_glAreProgramsResidentNV
#endif
#ifndef GLEE_H_DEFINED_glBindProgramNV
#define GLEE_H_DEFINED_glBindProgramNV
  typedef void (APIENTRYP GLEEPFNGLBINDPROGRAMNVPROC) (GLenum target, GLuint id);
  GLEE_EXTERN GLEEPFNGLBINDPROGRAMNVPROC GLeeFuncPtr_glBindProgramNV;
  #define glBindProgramNV GLeeFuncPtr_glBindProgramNV
#endif
#ifndef GLEE_H_DEFINED_glDeleteProgramsNV
#define GLEE_H_DEFINED_glDeleteProgramsNV
  typedef void (APIENTRYP GLEEPFNGLDELETEPROGRAMSNVPROC) (GLsizei n, const GLuint * programs);
  GLEE_EXTERN GLEEPFNGLDELETEPROGRAMSNVPROC GLeeFuncPtr_glDeleteProgramsNV;
  #define glDeleteProgramsNV GLeeFuncPtr_glDeleteProgramsNV
#endif
#ifndef GLEE_H_DEFINED_glExecuteProgramNV
#define GLEE_H_DEFINED_glExecuteProgramNV
  typedef void (APIENTRYP GLEEPFNGLEXECUTEPROGRAMNVPROC) (GLenum target, GLuint id, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLEXECUTEPROGRAMNVPROC GLeeFuncPtr_glExecuteProgramNV;
  #define glExecuteProgramNV GLeeFuncPtr_glExecuteProgramNV
#endif
#ifndef GLEE_H_DEFINED_glGenProgramsNV
#define GLEE_H_DEFINED_glGenProgramsNV
  typedef void (APIENTRYP GLEEPFNGLGENPROGRAMSNVPROC) (GLsizei n, GLuint * programs);
  GLEE_EXTERN GLEEPFNGLGENPROGRAMSNVPROC GLeeFuncPtr_glGenProgramsNV;
  #define glGenProgramsNV GLeeFuncPtr_glGenProgramsNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramParameterdvNV
#define GLEE_H_DEFINED_glGetProgramParameterdvNV
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMPARAMETERDVNVPROC) (GLenum target, GLuint index, GLenum pname, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMPARAMETERDVNVPROC GLeeFuncPtr_glGetProgramParameterdvNV;
  #define glGetProgramParameterdvNV GLeeFuncPtr_glGetProgramParameterdvNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramParameterfvNV
#define GLEE_H_DEFINED_glGetProgramParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMPARAMETERFVNVPROC) (GLenum target, GLuint index, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMPARAMETERFVNVPROC GLeeFuncPtr_glGetProgramParameterfvNV;
  #define glGetProgramParameterfvNV GLeeFuncPtr_glGetProgramParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramivNV
#define GLEE_H_DEFINED_glGetProgramivNV
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMIVNVPROC) (GLuint id, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMIVNVPROC GLeeFuncPtr_glGetProgramivNV;
  #define glGetProgramivNV GLeeFuncPtr_glGetProgramivNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramStringNV
#define GLEE_H_DEFINED_glGetProgramStringNV
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMSTRINGNVPROC) (GLuint id, GLenum pname, GLubyte * program);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMSTRINGNVPROC GLeeFuncPtr_glGetProgramStringNV;
  #define glGetProgramStringNV GLeeFuncPtr_glGetProgramStringNV
#endif
#ifndef GLEE_H_DEFINED_glGetTrackMatrixivNV
#define GLEE_H_DEFINED_glGetTrackMatrixivNV
  typedef void (APIENTRYP GLEEPFNGLGETTRACKMATRIXIVNVPROC) (GLenum target, GLuint address, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETTRACKMATRIXIVNVPROC GLeeFuncPtr_glGetTrackMatrixivNV;
  #define glGetTrackMatrixivNV GLeeFuncPtr_glGetTrackMatrixivNV
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribdvNV
#define GLEE_H_DEFINED_glGetVertexAttribdvNV
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBDVNVPROC) (GLuint index, GLenum pname, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBDVNVPROC GLeeFuncPtr_glGetVertexAttribdvNV;
  #define glGetVertexAttribdvNV GLeeFuncPtr_glGetVertexAttribdvNV
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribfvNV
#define GLEE_H_DEFINED_glGetVertexAttribfvNV
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBFVNVPROC) (GLuint index, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBFVNVPROC GLeeFuncPtr_glGetVertexAttribfvNV;
  #define glGetVertexAttribfvNV GLeeFuncPtr_glGetVertexAttribfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribivNV
#define GLEE_H_DEFINED_glGetVertexAttribivNV
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBIVNVPROC) (GLuint index, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBIVNVPROC GLeeFuncPtr_glGetVertexAttribivNV;
  #define glGetVertexAttribivNV GLeeFuncPtr_glGetVertexAttribivNV
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribPointervNV
#define GLEE_H_DEFINED_glGetVertexAttribPointervNV
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBPOINTERVNVPROC) (GLuint index, GLenum pname, GLvoid* * pointer);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBPOINTERVNVPROC GLeeFuncPtr_glGetVertexAttribPointervNV;
  #define glGetVertexAttribPointervNV GLeeFuncPtr_glGetVertexAttribPointervNV
#endif
#ifndef GLEE_H_DEFINED_glIsProgramNV
#define GLEE_H_DEFINED_glIsProgramNV
  typedef GLboolean (APIENTRYP GLEEPFNGLISPROGRAMNVPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLISPROGRAMNVPROC GLeeFuncPtr_glIsProgramNV;
  #define glIsProgramNV GLeeFuncPtr_glIsProgramNV
#endif
#ifndef GLEE_H_DEFINED_glLoadProgramNV
#define GLEE_H_DEFINED_glLoadProgramNV
  typedef void (APIENTRYP GLEEPFNGLLOADPROGRAMNVPROC) (GLenum target, GLuint id, GLsizei len, const GLubyte * program);
  GLEE_EXTERN GLEEPFNGLLOADPROGRAMNVPROC GLeeFuncPtr_glLoadProgramNV;
  #define glLoadProgramNV GLeeFuncPtr_glLoadProgramNV
#endif
#ifndef GLEE_H_DEFINED_glProgramParameter4dNV
#define GLEE_H_DEFINED_glProgramParameter4dNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMPARAMETER4DNVPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETER4DNVPROC GLeeFuncPtr_glProgramParameter4dNV;
  #define glProgramParameter4dNV GLeeFuncPtr_glProgramParameter4dNV
#endif
#ifndef GLEE_H_DEFINED_glProgramParameter4dvNV
#define GLEE_H_DEFINED_glProgramParameter4dvNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMPARAMETER4DVNVPROC) (GLenum target, GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETER4DVNVPROC GLeeFuncPtr_glProgramParameter4dvNV;
  #define glProgramParameter4dvNV GLeeFuncPtr_glProgramParameter4dvNV
#endif
#ifndef GLEE_H_DEFINED_glProgramParameter4fNV
#define GLEE_H_DEFINED_glProgramParameter4fNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMPARAMETER4FNVPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETER4FNVPROC GLeeFuncPtr_glProgramParameter4fNV;
  #define glProgramParameter4fNV GLeeFuncPtr_glProgramParameter4fNV
#endif
#ifndef GLEE_H_DEFINED_glProgramParameter4fvNV
#define GLEE_H_DEFINED_glProgramParameter4fvNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMPARAMETER4FVNVPROC) (GLenum target, GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETER4FVNVPROC GLeeFuncPtr_glProgramParameter4fvNV;
  #define glProgramParameter4fvNV GLeeFuncPtr_glProgramParameter4fvNV
#endif
#ifndef GLEE_H_DEFINED_glProgramParameters4dvNV
#define GLEE_H_DEFINED_glProgramParameters4dvNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMPARAMETERS4DVNVPROC) (GLenum target, GLuint index, GLuint count, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETERS4DVNVPROC GLeeFuncPtr_glProgramParameters4dvNV;
  #define glProgramParameters4dvNV GLeeFuncPtr_glProgramParameters4dvNV
#endif
#ifndef GLEE_H_DEFINED_glProgramParameters4fvNV
#define GLEE_H_DEFINED_glProgramParameters4fvNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMPARAMETERS4FVNVPROC) (GLenum target, GLuint index, GLuint count, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETERS4FVNVPROC GLeeFuncPtr_glProgramParameters4fvNV;
  #define glProgramParameters4fvNV GLeeFuncPtr_glProgramParameters4fvNV
#endif
#ifndef GLEE_H_DEFINED_glRequestResidentProgramsNV
#define GLEE_H_DEFINED_glRequestResidentProgramsNV
  typedef void (APIENTRYP GLEEPFNGLREQUESTRESIDENTPROGRAMSNVPROC) (GLsizei n, const GLuint * programs);
  GLEE_EXTERN GLEEPFNGLREQUESTRESIDENTPROGRAMSNVPROC GLeeFuncPtr_glRequestResidentProgramsNV;
  #define glRequestResidentProgramsNV GLeeFuncPtr_glRequestResidentProgramsNV
#endif
#ifndef GLEE_H_DEFINED_glTrackMatrixNV
#define GLEE_H_DEFINED_glTrackMatrixNV
  typedef void (APIENTRYP GLEEPFNGLTRACKMATRIXNVPROC) (GLenum target, GLuint address, GLenum matrix, GLenum transform);
  GLEE_EXTERN GLEEPFNGLTRACKMATRIXNVPROC GLeeFuncPtr_glTrackMatrixNV;
  #define glTrackMatrixNV GLeeFuncPtr_glTrackMatrixNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribPointerNV
#define GLEE_H_DEFINED_glVertexAttribPointerNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBPOINTERNVPROC) (GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBPOINTERNVPROC GLeeFuncPtr_glVertexAttribPointerNV;
  #define glVertexAttribPointerNV GLeeFuncPtr_glVertexAttribPointerNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1dNV
#define GLEE_H_DEFINED_glVertexAttrib1dNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1DNVPROC) (GLuint index, GLdouble x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1DNVPROC GLeeFuncPtr_glVertexAttrib1dNV;
  #define glVertexAttrib1dNV GLeeFuncPtr_glVertexAttrib1dNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1dvNV
#define GLEE_H_DEFINED_glVertexAttrib1dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1DVNVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1DVNVPROC GLeeFuncPtr_glVertexAttrib1dvNV;
  #define glVertexAttrib1dvNV GLeeFuncPtr_glVertexAttrib1dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1fNV
#define GLEE_H_DEFINED_glVertexAttrib1fNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1FNVPROC) (GLuint index, GLfloat x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1FNVPROC GLeeFuncPtr_glVertexAttrib1fNV;
  #define glVertexAttrib1fNV GLeeFuncPtr_glVertexAttrib1fNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1fvNV
#define GLEE_H_DEFINED_glVertexAttrib1fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1FVNVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1FVNVPROC GLeeFuncPtr_glVertexAttrib1fvNV;
  #define glVertexAttrib1fvNV GLeeFuncPtr_glVertexAttrib1fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1sNV
#define GLEE_H_DEFINED_glVertexAttrib1sNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1SNVPROC) (GLuint index, GLshort x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1SNVPROC GLeeFuncPtr_glVertexAttrib1sNV;
  #define glVertexAttrib1sNV GLeeFuncPtr_glVertexAttrib1sNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1svNV
#define GLEE_H_DEFINED_glVertexAttrib1svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1SVNVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1SVNVPROC GLeeFuncPtr_glVertexAttrib1svNV;
  #define glVertexAttrib1svNV GLeeFuncPtr_glVertexAttrib1svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2dNV
#define GLEE_H_DEFINED_glVertexAttrib2dNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2DNVPROC) (GLuint index, GLdouble x, GLdouble y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2DNVPROC GLeeFuncPtr_glVertexAttrib2dNV;
  #define glVertexAttrib2dNV GLeeFuncPtr_glVertexAttrib2dNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2dvNV
#define GLEE_H_DEFINED_glVertexAttrib2dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2DVNVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2DVNVPROC GLeeFuncPtr_glVertexAttrib2dvNV;
  #define glVertexAttrib2dvNV GLeeFuncPtr_glVertexAttrib2dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2fNV
#define GLEE_H_DEFINED_glVertexAttrib2fNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2FNVPROC) (GLuint index, GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2FNVPROC GLeeFuncPtr_glVertexAttrib2fNV;
  #define glVertexAttrib2fNV GLeeFuncPtr_glVertexAttrib2fNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2fvNV
#define GLEE_H_DEFINED_glVertexAttrib2fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2FVNVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2FVNVPROC GLeeFuncPtr_glVertexAttrib2fvNV;
  #define glVertexAttrib2fvNV GLeeFuncPtr_glVertexAttrib2fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2sNV
#define GLEE_H_DEFINED_glVertexAttrib2sNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2SNVPROC) (GLuint index, GLshort x, GLshort y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2SNVPROC GLeeFuncPtr_glVertexAttrib2sNV;
  #define glVertexAttrib2sNV GLeeFuncPtr_glVertexAttrib2sNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2svNV
#define GLEE_H_DEFINED_glVertexAttrib2svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2SVNVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2SVNVPROC GLeeFuncPtr_glVertexAttrib2svNV;
  #define glVertexAttrib2svNV GLeeFuncPtr_glVertexAttrib2svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3dNV
#define GLEE_H_DEFINED_glVertexAttrib3dNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3DNVPROC GLeeFuncPtr_glVertexAttrib3dNV;
  #define glVertexAttrib3dNV GLeeFuncPtr_glVertexAttrib3dNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3dvNV
#define GLEE_H_DEFINED_glVertexAttrib3dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3DVNVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3DVNVPROC GLeeFuncPtr_glVertexAttrib3dvNV;
  #define glVertexAttrib3dvNV GLeeFuncPtr_glVertexAttrib3dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3fNV
#define GLEE_H_DEFINED_glVertexAttrib3fNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3FNVPROC GLeeFuncPtr_glVertexAttrib3fNV;
  #define glVertexAttrib3fNV GLeeFuncPtr_glVertexAttrib3fNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3fvNV
#define GLEE_H_DEFINED_glVertexAttrib3fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3FVNVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3FVNVPROC GLeeFuncPtr_glVertexAttrib3fvNV;
  #define glVertexAttrib3fvNV GLeeFuncPtr_glVertexAttrib3fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3sNV
#define GLEE_H_DEFINED_glVertexAttrib3sNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3SNVPROC GLeeFuncPtr_glVertexAttrib3sNV;
  #define glVertexAttrib3sNV GLeeFuncPtr_glVertexAttrib3sNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3svNV
#define GLEE_H_DEFINED_glVertexAttrib3svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3SVNVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3SVNVPROC GLeeFuncPtr_glVertexAttrib3svNV;
  #define glVertexAttrib3svNV GLeeFuncPtr_glVertexAttrib3svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4dNV
#define GLEE_H_DEFINED_glVertexAttrib4dNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4DNVPROC GLeeFuncPtr_glVertexAttrib4dNV;
  #define glVertexAttrib4dNV GLeeFuncPtr_glVertexAttrib4dNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4dvNV
#define GLEE_H_DEFINED_glVertexAttrib4dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4DVNVPROC) (GLuint index, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4DVNVPROC GLeeFuncPtr_glVertexAttrib4dvNV;
  #define glVertexAttrib4dvNV GLeeFuncPtr_glVertexAttrib4dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4fNV
#define GLEE_H_DEFINED_glVertexAttrib4fNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4FNVPROC GLeeFuncPtr_glVertexAttrib4fNV;
  #define glVertexAttrib4fNV GLeeFuncPtr_glVertexAttrib4fNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4fvNV
#define GLEE_H_DEFINED_glVertexAttrib4fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4FVNVPROC) (GLuint index, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4FVNVPROC GLeeFuncPtr_glVertexAttrib4fvNV;
  #define glVertexAttrib4fvNV GLeeFuncPtr_glVertexAttrib4fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4sNV
#define GLEE_H_DEFINED_glVertexAttrib4sNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4SNVPROC GLeeFuncPtr_glVertexAttrib4sNV;
  #define glVertexAttrib4sNV GLeeFuncPtr_glVertexAttrib4sNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4svNV
#define GLEE_H_DEFINED_glVertexAttrib4svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4SVNVPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4SVNVPROC GLeeFuncPtr_glVertexAttrib4svNV;
  #define glVertexAttrib4svNV GLeeFuncPtr_glVertexAttrib4svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4ubNV
#define GLEE_H_DEFINED_glVertexAttrib4ubNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4UBNVPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4UBNVPROC GLeeFuncPtr_glVertexAttrib4ubNV;
  #define glVertexAttrib4ubNV GLeeFuncPtr_glVertexAttrib4ubNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4ubvNV
#define GLEE_H_DEFINED_glVertexAttrib4ubvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4UBVNVPROC) (GLuint index, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4UBVNVPROC GLeeFuncPtr_glVertexAttrib4ubvNV;
  #define glVertexAttrib4ubvNV GLeeFuncPtr_glVertexAttrib4ubvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs1dvNV
#define GLEE_H_DEFINED_glVertexAttribs1dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS1DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS1DVNVPROC GLeeFuncPtr_glVertexAttribs1dvNV;
  #define glVertexAttribs1dvNV GLeeFuncPtr_glVertexAttribs1dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs1fvNV
#define GLEE_H_DEFINED_glVertexAttribs1fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS1FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS1FVNVPROC GLeeFuncPtr_glVertexAttribs1fvNV;
  #define glVertexAttribs1fvNV GLeeFuncPtr_glVertexAttribs1fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs1svNV
#define GLEE_H_DEFINED_glVertexAttribs1svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS1SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS1SVNVPROC GLeeFuncPtr_glVertexAttribs1svNV;
  #define glVertexAttribs1svNV GLeeFuncPtr_glVertexAttribs1svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs2dvNV
#define GLEE_H_DEFINED_glVertexAttribs2dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS2DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS2DVNVPROC GLeeFuncPtr_glVertexAttribs2dvNV;
  #define glVertexAttribs2dvNV GLeeFuncPtr_glVertexAttribs2dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs2fvNV
#define GLEE_H_DEFINED_glVertexAttribs2fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS2FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS2FVNVPROC GLeeFuncPtr_glVertexAttribs2fvNV;
  #define glVertexAttribs2fvNV GLeeFuncPtr_glVertexAttribs2fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs2svNV
#define GLEE_H_DEFINED_glVertexAttribs2svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS2SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS2SVNVPROC GLeeFuncPtr_glVertexAttribs2svNV;
  #define glVertexAttribs2svNV GLeeFuncPtr_glVertexAttribs2svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs3dvNV
#define GLEE_H_DEFINED_glVertexAttribs3dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS3DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS3DVNVPROC GLeeFuncPtr_glVertexAttribs3dvNV;
  #define glVertexAttribs3dvNV GLeeFuncPtr_glVertexAttribs3dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs3fvNV
#define GLEE_H_DEFINED_glVertexAttribs3fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS3FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS3FVNVPROC GLeeFuncPtr_glVertexAttribs3fvNV;
  #define glVertexAttribs3fvNV GLeeFuncPtr_glVertexAttribs3fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs3svNV
#define GLEE_H_DEFINED_glVertexAttribs3svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS3SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS3SVNVPROC GLeeFuncPtr_glVertexAttribs3svNV;
  #define glVertexAttribs3svNV GLeeFuncPtr_glVertexAttribs3svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs4dvNV
#define GLEE_H_DEFINED_glVertexAttribs4dvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS4DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS4DVNVPROC GLeeFuncPtr_glVertexAttribs4dvNV;
  #define glVertexAttribs4dvNV GLeeFuncPtr_glVertexAttribs4dvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs4fvNV
#define GLEE_H_DEFINED_glVertexAttribs4fvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS4FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS4FVNVPROC GLeeFuncPtr_glVertexAttribs4fvNV;
  #define glVertexAttribs4fvNV GLeeFuncPtr_glVertexAttribs4fvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs4svNV
#define GLEE_H_DEFINED_glVertexAttribs4svNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS4SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS4SVNVPROC GLeeFuncPtr_glVertexAttribs4svNV;
  #define glVertexAttribs4svNV GLeeFuncPtr_glVertexAttribs4svNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs4ubvNV
#define GLEE_H_DEFINED_glVertexAttribs4ubvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS4UBVNVPROC) (GLuint index, GLsizei count, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS4UBVNVPROC GLeeFuncPtr_glVertexAttribs4ubvNV;
  #define glVertexAttribs4ubvNV GLeeFuncPtr_glVertexAttribs4ubvNV
#endif
#endif

/* GL_SGIX_texture_coordinate_clamp */

#ifndef GL_SGIX_texture_coordinate_clamp
#define GL_SGIX_texture_coordinate_clamp 1
#define __GLEE_GL_SGIX_texture_coordinate_clamp 1
/* Constants */
#define GL_TEXTURE_MAX_CLAMP_S_SGIX                        0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX                        0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX                        0x836B
#endif

/* GL_SGIX_scalebias_hint */

#ifndef GL_SGIX_scalebias_hint
#define GL_SGIX_scalebias_hint 1
#define __GLEE_GL_SGIX_scalebias_hint 1
/* Constants */
#define GL_SCALEBIAS_HINT_SGIX                             0x8322
#endif

/* GL_OML_interlace */

#ifndef GL_OML_interlace
#define GL_OML_interlace 1
#define __GLEE_GL_OML_interlace 1
/* Constants */
#define GL_INTERLACE_OML                                   0x8980
#define GL_INTERLACE_READ_OML                              0x8981
#endif

/* GL_OML_subsample */

#ifndef GL_OML_subsample
#define GL_OML_subsample 1
#define __GLEE_GL_OML_subsample 1
/* Constants */
#define GL_FORMAT_SUBSAMPLE_24_24_OML                      0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML                    0x8983
#endif

/* GL_OML_resample */

#ifndef GL_OML_resample
#define GL_OML_resample 1
#define __GLEE_GL_OML_resample 1
/* Constants */
#define GL_PACK_RESAMPLE_OML                               0x8984
#define GL_UNPACK_RESAMPLE_OML                             0x8985
#define GL_RESAMPLE_REPLICATE_OML                          0x8986
#define GL_RESAMPLE_ZERO_FILL_OML                          0x8987
#define GL_RESAMPLE_AVERAGE_OML                            0x8988
#define GL_RESAMPLE_DECIMATE_OML                           0x8989
#endif

/* GL_NV_copy_depth_to_color */

#ifndef GL_NV_copy_depth_to_color
#define GL_NV_copy_depth_to_color 1
#define __GLEE_GL_NV_copy_depth_to_color 1
/* Constants */
#define GL_DEPTH_STENCIL_TO_RGBA_NV                        0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV                        0x886F
#endif

/* GL_ATI_envmap_bumpmap */

#ifndef GL_ATI_envmap_bumpmap
#define GL_ATI_envmap_bumpmap 1
#define __GLEE_GL_ATI_envmap_bumpmap 1
/* Constants */
#define GL_BUMP_ROT_MATRIX_ATI                             0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI                        0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI                          0x8777
#define GL_BUMP_TEX_UNITS_ATI                              0x8778
#define GL_DUDV_ATI                                        0x8779
#define GL_DU8DV8_ATI                                      0x877A
#define GL_BUMP_ENVMAP_ATI                                 0x877B
#define GL_BUMP_TARGET_ATI                                 0x877C
#ifndef GLEE_H_DEFINED_glTexBumpParameterivATI
#define GLEE_H_DEFINED_glTexBumpParameterivATI
  typedef void (APIENTRYP GLEEPFNGLTEXBUMPPARAMETERIVATIPROC) (GLenum pname, const GLint * param);
  GLEE_EXTERN GLEEPFNGLTEXBUMPPARAMETERIVATIPROC GLeeFuncPtr_glTexBumpParameterivATI;
  #define glTexBumpParameterivATI GLeeFuncPtr_glTexBumpParameterivATI
#endif
#ifndef GLEE_H_DEFINED_glTexBumpParameterfvATI
#define GLEE_H_DEFINED_glTexBumpParameterfvATI
  typedef void (APIENTRYP GLEEPFNGLTEXBUMPPARAMETERFVATIPROC) (GLenum pname, const GLfloat * param);
  GLEE_EXTERN GLEEPFNGLTEXBUMPPARAMETERFVATIPROC GLeeFuncPtr_glTexBumpParameterfvATI;
  #define glTexBumpParameterfvATI GLeeFuncPtr_glTexBumpParameterfvATI
#endif
#ifndef GLEE_H_DEFINED_glGetTexBumpParameterivATI
#define GLEE_H_DEFINED_glGetTexBumpParameterivATI
  typedef void (APIENTRYP GLEEPFNGLGETTEXBUMPPARAMETERIVATIPROC) (GLenum pname, GLint * param);
  GLEE_EXTERN GLEEPFNGLGETTEXBUMPPARAMETERIVATIPROC GLeeFuncPtr_glGetTexBumpParameterivATI;
  #define glGetTexBumpParameterivATI GLeeFuncPtr_glGetTexBumpParameterivATI
#endif
#ifndef GLEE_H_DEFINED_glGetTexBumpParameterfvATI
#define GLEE_H_DEFINED_glGetTexBumpParameterfvATI
  typedef void (APIENTRYP GLEEPFNGLGETTEXBUMPPARAMETERFVATIPROC) (GLenum pname, GLfloat * param);
  GLEE_EXTERN GLEEPFNGLGETTEXBUMPPARAMETERFVATIPROC GLeeFuncPtr_glGetTexBumpParameterfvATI;
  #define glGetTexBumpParameterfvATI GLeeFuncPtr_glGetTexBumpParameterfvATI
#endif
#endif

/* GL_ATI_fragment_shader */

#ifndef GL_ATI_fragment_shader
#define GL_ATI_fragment_shader 1
#define __GLEE_GL_ATI_fragment_shader 1
/* Constants */
#define GL_FRAGMENT_SHADER_ATI                             0x8920
#define GL_REG_0_ATI                                       0x8921
#define GL_REG_1_ATI                                       0x8922
#define GL_REG_2_ATI                                       0x8923
#define GL_REG_3_ATI                                       0x8924
#define GL_REG_4_ATI                                       0x8925
#define GL_REG_5_ATI                                       0x8926
#define GL_REG_6_ATI                                       0x8927
#define GL_REG_7_ATI                                       0x8928
#define GL_REG_8_ATI                                       0x8929
#define GL_REG_9_ATI                                       0x892A
#define GL_REG_10_ATI                                      0x892B
#define GL_REG_11_ATI                                      0x892C
#define GL_REG_12_ATI                                      0x892D
#define GL_REG_13_ATI                                      0x892E
#define GL_REG_14_ATI                                      0x892F
#define GL_REG_15_ATI                                      0x8930
#define GL_REG_16_ATI                                      0x8931
#define GL_REG_17_ATI                                      0x8932
#define GL_REG_18_ATI                                      0x8933
#define GL_REG_19_ATI                                      0x8934
#define GL_REG_20_ATI                                      0x8935
#define GL_REG_21_ATI                                      0x8936
#define GL_REG_22_ATI                                      0x8937
#define GL_REG_23_ATI                                      0x8938
#define GL_REG_24_ATI                                      0x8939
#define GL_REG_25_ATI                                      0x893A
#define GL_REG_26_ATI                                      0x893B
#define GL_REG_27_ATI                                      0x893C
#define GL_REG_28_ATI                                      0x893D
#define GL_REG_29_ATI                                      0x893E
#define GL_REG_30_ATI                                      0x893F
#define GL_REG_31_ATI                                      0x8940
#define GL_CON_0_ATI                                       0x8941
#define GL_CON_1_ATI                                       0x8942
#define GL_CON_2_ATI                                       0x8943
#define GL_CON_3_ATI                                       0x8944
#define GL_CON_4_ATI                                       0x8945
#define GL_CON_5_ATI                                       0x8946
#define GL_CON_6_ATI                                       0x8947
#define GL_CON_7_ATI                                       0x8948
#define GL_CON_8_ATI                                       0x8949
#define GL_CON_9_ATI                                       0x894A
#define GL_CON_10_ATI                                      0x894B
#define GL_CON_11_ATI                                      0x894C
#define GL_CON_12_ATI                                      0x894D
#define GL_CON_13_ATI                                      0x894E
#define GL_CON_14_ATI                                      0x894F
#define GL_CON_15_ATI                                      0x8950
#define GL_CON_16_ATI                                      0x8951
#define GL_CON_17_ATI                                      0x8952
#define GL_CON_18_ATI                                      0x8953
#define GL_CON_19_ATI                                      0x8954
#define GL_CON_20_ATI                                      0x8955
#define GL_CON_21_ATI                                      0x8956
#define GL_CON_22_ATI                                      0x8957
#define GL_CON_23_ATI                                      0x8958
#define GL_CON_24_ATI                                      0x8959
#define GL_CON_25_ATI                                      0x895A
#define GL_CON_26_ATI                                      0x895B
#define GL_CON_27_ATI                                      0x895C
#define GL_CON_28_ATI                                      0x895D
#define GL_CON_29_ATI                                      0x895E
#define GL_CON_30_ATI                                      0x895F
#define GL_CON_31_ATI                                      0x8960
#define GL_MOV_ATI                                         0x8961
#define GL_ADD_ATI                                         0x8963
#define GL_MUL_ATI                                         0x8964
#define GL_SUB_ATI                                         0x8965
#define GL_DOT3_ATI                                        0x8966
#define GL_DOT4_ATI                                        0x8967
#define GL_MAD_ATI                                         0x8968
#define GL_LERP_ATI                                        0x8969
#define GL_CND_ATI                                         0x896A
#define GL_CND0_ATI                                        0x896B
#define GL_DOT2_ADD_ATI                                    0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI                      0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI                      0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI                      0x896F
#define GL_NUM_PASSES_ATI                                  0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI                   0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI                      0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI           0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI                     0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI                         0x8975
#define GL_SWIZZLE_STR_ATI                                 0x8976
#define GL_SWIZZLE_STQ_ATI                                 0x8977
#define GL_SWIZZLE_STR_DR_ATI                              0x8978
#define GL_SWIZZLE_STQ_DQ_ATI                              0x8979
#define GL_SWIZZLE_STRQ_ATI                                0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI                             0x897B
#define GL_RED_BIT_ATI                                     0x00000001
#define GL_GREEN_BIT_ATI                                   0x00000002
#define GL_BLUE_BIT_ATI                                    0x00000004
#define GL_2X_BIT_ATI                                      0x00000001
#define GL_4X_BIT_ATI                                      0x00000002
#define GL_8X_BIT_ATI                                      0x00000004
#define GL_HALF_BIT_ATI                                    0x00000008
#define GL_QUARTER_BIT_ATI                                 0x00000010
#define GL_EIGHTH_BIT_ATI                                  0x00000020
#define GL_SATURATE_BIT_ATI                                0x00000040
#define GL_COMP_BIT_ATI                                    0x00000002
#define GL_NEGATE_BIT_ATI                                  0x00000004
#define GL_BIAS_BIT_ATI                                    0x00000008
#ifndef GLEE_H_DEFINED_glGenFragmentShadersATI
#define GLEE_H_DEFINED_glGenFragmentShadersATI
  typedef GLuint (APIENTRYP GLEEPFNGLGENFRAGMENTSHADERSATIPROC) (GLuint range);
  GLEE_EXTERN GLEEPFNGLGENFRAGMENTSHADERSATIPROC GLeeFuncPtr_glGenFragmentShadersATI;
  #define glGenFragmentShadersATI GLeeFuncPtr_glGenFragmentShadersATI
#endif
#ifndef GLEE_H_DEFINED_glBindFragmentShaderATI
#define GLEE_H_DEFINED_glBindFragmentShaderATI
  typedef void (APIENTRYP GLEEPFNGLBINDFRAGMENTSHADERATIPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLBINDFRAGMENTSHADERATIPROC GLeeFuncPtr_glBindFragmentShaderATI;
  #define glBindFragmentShaderATI GLeeFuncPtr_glBindFragmentShaderATI
#endif
#ifndef GLEE_H_DEFINED_glDeleteFragmentShaderATI
#define GLEE_H_DEFINED_glDeleteFragmentShaderATI
  typedef void (APIENTRYP GLEEPFNGLDELETEFRAGMENTSHADERATIPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLDELETEFRAGMENTSHADERATIPROC GLeeFuncPtr_glDeleteFragmentShaderATI;
  #define glDeleteFragmentShaderATI GLeeFuncPtr_glDeleteFragmentShaderATI
#endif
#ifndef GLEE_H_DEFINED_glBeginFragmentShaderATI
#define GLEE_H_DEFINED_glBeginFragmentShaderATI
  typedef void (APIENTRYP GLEEPFNGLBEGINFRAGMENTSHADERATIPROC) ();
  GLEE_EXTERN GLEEPFNGLBEGINFRAGMENTSHADERATIPROC GLeeFuncPtr_glBeginFragmentShaderATI;
  #define glBeginFragmentShaderATI GLeeFuncPtr_glBeginFragmentShaderATI
#endif
#ifndef GLEE_H_DEFINED_glEndFragmentShaderATI
#define GLEE_H_DEFINED_glEndFragmentShaderATI
  typedef void (APIENTRYP GLEEPFNGLENDFRAGMENTSHADERATIPROC) ();
  GLEE_EXTERN GLEEPFNGLENDFRAGMENTSHADERATIPROC GLeeFuncPtr_glEndFragmentShaderATI;
  #define glEndFragmentShaderATI GLeeFuncPtr_glEndFragmentShaderATI
#endif
#ifndef GLEE_H_DEFINED_glPassTexCoordATI
#define GLEE_H_DEFINED_glPassTexCoordATI
  typedef void (APIENTRYP GLEEPFNGLPASSTEXCOORDATIPROC) (GLuint dst, GLuint coord, GLenum swizzle);
  GLEE_EXTERN GLEEPFNGLPASSTEXCOORDATIPROC GLeeFuncPtr_glPassTexCoordATI;
  #define glPassTexCoordATI GLeeFuncPtr_glPassTexCoordATI
#endif
#ifndef GLEE_H_DEFINED_glSampleMapATI
#define GLEE_H_DEFINED_glSampleMapATI
  typedef void (APIENTRYP GLEEPFNGLSAMPLEMAPATIPROC) (GLuint dst, GLuint interp, GLenum swizzle);
  GLEE_EXTERN GLEEPFNGLSAMPLEMAPATIPROC GLeeFuncPtr_glSampleMapATI;
  #define glSampleMapATI GLeeFuncPtr_glSampleMapATI
#endif
#ifndef GLEE_H_DEFINED_glColorFragmentOp1ATI
#define GLEE_H_DEFINED_glColorFragmentOp1ATI
  typedef void (APIENTRYP GLEEPFNGLCOLORFRAGMENTOP1ATIPROC) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
  GLEE_EXTERN GLEEPFNGLCOLORFRAGMENTOP1ATIPROC GLeeFuncPtr_glColorFragmentOp1ATI;
  #define glColorFragmentOp1ATI GLeeFuncPtr_glColorFragmentOp1ATI
#endif
#ifndef GLEE_H_DEFINED_glColorFragmentOp2ATI
#define GLEE_H_DEFINED_glColorFragmentOp2ATI
  typedef void (APIENTRYP GLEEPFNGLCOLORFRAGMENTOP2ATIPROC) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
  GLEE_EXTERN GLEEPFNGLCOLORFRAGMENTOP2ATIPROC GLeeFuncPtr_glColorFragmentOp2ATI;
  #define glColorFragmentOp2ATI GLeeFuncPtr_glColorFragmentOp2ATI
#endif
#ifndef GLEE_H_DEFINED_glColorFragmentOp3ATI
#define GLEE_H_DEFINED_glColorFragmentOp3ATI
  typedef void (APIENTRYP GLEEPFNGLCOLORFRAGMENTOP3ATIPROC) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
  GLEE_EXTERN GLEEPFNGLCOLORFRAGMENTOP3ATIPROC GLeeFuncPtr_glColorFragmentOp3ATI;
  #define glColorFragmentOp3ATI GLeeFuncPtr_glColorFragmentOp3ATI
#endif
#ifndef GLEE_H_DEFINED_glAlphaFragmentOp1ATI
#define GLEE_H_DEFINED_glAlphaFragmentOp1ATI
  typedef void (APIENTRYP GLEEPFNGLALPHAFRAGMENTOP1ATIPROC) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
  GLEE_EXTERN GLEEPFNGLALPHAFRAGMENTOP1ATIPROC GLeeFuncPtr_glAlphaFragmentOp1ATI;
  #define glAlphaFragmentOp1ATI GLeeFuncPtr_glAlphaFragmentOp1ATI
#endif
#ifndef GLEE_H_DEFINED_glAlphaFragmentOp2ATI
#define GLEE_H_DEFINED_glAlphaFragmentOp2ATI
  typedef void (APIENTRYP GLEEPFNGLALPHAFRAGMENTOP2ATIPROC) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
  GLEE_EXTERN GLEEPFNGLALPHAFRAGMENTOP2ATIPROC GLeeFuncPtr_glAlphaFragmentOp2ATI;
  #define glAlphaFragmentOp2ATI GLeeFuncPtr_glAlphaFragmentOp2ATI
#endif
#ifndef GLEE_H_DEFINED_glAlphaFragmentOp3ATI
#define GLEE_H_DEFINED_glAlphaFragmentOp3ATI
  typedef void (APIENTRYP GLEEPFNGLALPHAFRAGMENTOP3ATIPROC) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
  GLEE_EXTERN GLEEPFNGLALPHAFRAGMENTOP3ATIPROC GLeeFuncPtr_glAlphaFragmentOp3ATI;
  #define glAlphaFragmentOp3ATI GLeeFuncPtr_glAlphaFragmentOp3ATI
#endif
#ifndef GLEE_H_DEFINED_glSetFragmentShaderConstantATI
#define GLEE_H_DEFINED_glSetFragmentShaderConstantATI
  typedef void (APIENTRYP GLEEPFNGLSETFRAGMENTSHADERCONSTANTATIPROC) (GLuint dst, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLSETFRAGMENTSHADERCONSTANTATIPROC GLeeFuncPtr_glSetFragmentShaderConstantATI;
  #define glSetFragmentShaderConstantATI GLeeFuncPtr_glSetFragmentShaderConstantATI
#endif
#endif

/* GL_ATI_pn_triangles */

#ifndef GL_ATI_pn_triangles
#define GL_ATI_pn_triangles 1
#define __GLEE_GL_ATI_pn_triangles 1
/* Constants */
#define GL_PN_TRIANGLES_ATI                                0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI          0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI                     0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI                    0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI              0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI              0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI               0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI             0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI          0x87F8
#ifndef GLEE_H_DEFINED_glPNTrianglesiATI
#define GLEE_H_DEFINED_glPNTrianglesiATI
  typedef void (APIENTRYP GLEEPFNGLPNTRIANGLESIATIPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLPNTRIANGLESIATIPROC GLeeFuncPtr_glPNTrianglesiATI;
  #define glPNTrianglesiATI GLeeFuncPtr_glPNTrianglesiATI
#endif
#ifndef GLEE_H_DEFINED_glPNTrianglesfATI
#define GLEE_H_DEFINED_glPNTrianglesfATI
  typedef void (APIENTRYP GLEEPFNGLPNTRIANGLESFATIPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLPNTRIANGLESFATIPROC GLeeFuncPtr_glPNTrianglesfATI;
  #define glPNTrianglesfATI GLeeFuncPtr_glPNTrianglesfATI
#endif
#endif

/* GL_ATI_vertex_array_object */

#ifndef GL_ATI_vertex_array_object
#define GL_ATI_vertex_array_object 1
#define __GLEE_GL_ATI_vertex_array_object 1
/* Constants */
#define GL_STATIC_ATI                                      0x8760
#define GL_DYNAMIC_ATI                                     0x8761
#define GL_PRESERVE_ATI                                    0x8762
#define GL_DISCARD_ATI                                     0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI                          0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI                         0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI                         0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI                         0x8767
#ifndef GLEE_H_DEFINED_glNewObjectBufferATI
#define GLEE_H_DEFINED_glNewObjectBufferATI
  typedef GLuint (APIENTRYP GLEEPFNGLNEWOBJECTBUFFERATIPROC) (GLsizei size, const GLvoid * pointer, GLenum usage);
  GLEE_EXTERN GLEEPFNGLNEWOBJECTBUFFERATIPROC GLeeFuncPtr_glNewObjectBufferATI;
  #define glNewObjectBufferATI GLeeFuncPtr_glNewObjectBufferATI
#endif
#ifndef GLEE_H_DEFINED_glIsObjectBufferATI
#define GLEE_H_DEFINED_glIsObjectBufferATI
  typedef GLboolean (APIENTRYP GLEEPFNGLISOBJECTBUFFERATIPROC) (GLuint buffer);
  GLEE_EXTERN GLEEPFNGLISOBJECTBUFFERATIPROC GLeeFuncPtr_glIsObjectBufferATI;
  #define glIsObjectBufferATI GLeeFuncPtr_glIsObjectBufferATI
#endif
#ifndef GLEE_H_DEFINED_glUpdateObjectBufferATI
#define GLEE_H_DEFINED_glUpdateObjectBufferATI
  typedef void (APIENTRYP GLEEPFNGLUPDATEOBJECTBUFFERATIPROC) (GLuint buffer, GLuint offset, GLsizei size, const GLvoid * pointer, GLenum preserve);
  GLEE_EXTERN GLEEPFNGLUPDATEOBJECTBUFFERATIPROC GLeeFuncPtr_glUpdateObjectBufferATI;
  #define glUpdateObjectBufferATI GLeeFuncPtr_glUpdateObjectBufferATI
#endif
#ifndef GLEE_H_DEFINED_glGetObjectBufferfvATI
#define GLEE_H_DEFINED_glGetObjectBufferfvATI
  typedef void (APIENTRYP GLEEPFNGLGETOBJECTBUFFERFVATIPROC) (GLuint buffer, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETOBJECTBUFFERFVATIPROC GLeeFuncPtr_glGetObjectBufferfvATI;
  #define glGetObjectBufferfvATI GLeeFuncPtr_glGetObjectBufferfvATI
#endif
#ifndef GLEE_H_DEFINED_glGetObjectBufferivATI
#define GLEE_H_DEFINED_glGetObjectBufferivATI
  typedef void (APIENTRYP GLEEPFNGLGETOBJECTBUFFERIVATIPROC) (GLuint buffer, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETOBJECTBUFFERIVATIPROC GLeeFuncPtr_glGetObjectBufferivATI;
  #define glGetObjectBufferivATI GLeeFuncPtr_glGetObjectBufferivATI
#endif
#ifndef GLEE_H_DEFINED_glFreeObjectBufferATI
#define GLEE_H_DEFINED_glFreeObjectBufferATI
  typedef void (APIENTRYP GLEEPFNGLFREEOBJECTBUFFERATIPROC) (GLuint buffer);
  GLEE_EXTERN GLEEPFNGLFREEOBJECTBUFFERATIPROC GLeeFuncPtr_glFreeObjectBufferATI;
  #define glFreeObjectBufferATI GLeeFuncPtr_glFreeObjectBufferATI
#endif
#ifndef GLEE_H_DEFINED_glArrayObjectATI
#define GLEE_H_DEFINED_glArrayObjectATI
  typedef void (APIENTRYP GLEEPFNGLARRAYOBJECTATIPROC) (GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
  GLEE_EXTERN GLEEPFNGLARRAYOBJECTATIPROC GLeeFuncPtr_glArrayObjectATI;
  #define glArrayObjectATI GLeeFuncPtr_glArrayObjectATI
#endif
#ifndef GLEE_H_DEFINED_glGetArrayObjectfvATI
#define GLEE_H_DEFINED_glGetArrayObjectfvATI
  typedef void (APIENTRYP GLEEPFNGLGETARRAYOBJECTFVATIPROC) (GLenum array, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETARRAYOBJECTFVATIPROC GLeeFuncPtr_glGetArrayObjectfvATI;
  #define glGetArrayObjectfvATI GLeeFuncPtr_glGetArrayObjectfvATI
#endif
#ifndef GLEE_H_DEFINED_glGetArrayObjectivATI
#define GLEE_H_DEFINED_glGetArrayObjectivATI
  typedef void (APIENTRYP GLEEPFNGLGETARRAYOBJECTIVATIPROC) (GLenum array, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETARRAYOBJECTIVATIPROC GLeeFuncPtr_glGetArrayObjectivATI;
  #define glGetArrayObjectivATI GLeeFuncPtr_glGetArrayObjectivATI
#endif
#ifndef GLEE_H_DEFINED_glVariantArrayObjectATI
#define GLEE_H_DEFINED_glVariantArrayObjectATI
  typedef void (APIENTRYP GLEEPFNGLVARIANTARRAYOBJECTATIPROC) (GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
  GLEE_EXTERN GLEEPFNGLVARIANTARRAYOBJECTATIPROC GLeeFuncPtr_glVariantArrayObjectATI;
  #define glVariantArrayObjectATI GLeeFuncPtr_glVariantArrayObjectATI
#endif
#ifndef GLEE_H_DEFINED_glGetVariantArrayObjectfvATI
#define GLEE_H_DEFINED_glGetVariantArrayObjectfvATI
  typedef void (APIENTRYP GLEEPFNGLGETVARIANTARRAYOBJECTFVATIPROC) (GLuint id, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETVARIANTARRAYOBJECTFVATIPROC GLeeFuncPtr_glGetVariantArrayObjectfvATI;
  #define glGetVariantArrayObjectfvATI GLeeFuncPtr_glGetVariantArrayObjectfvATI
#endif
#ifndef GLEE_H_DEFINED_glGetVariantArrayObjectivATI
#define GLEE_H_DEFINED_glGetVariantArrayObjectivATI
  typedef void (APIENTRYP GLEEPFNGLGETVARIANTARRAYOBJECTIVATIPROC) (GLuint id, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETVARIANTARRAYOBJECTIVATIPROC GLeeFuncPtr_glGetVariantArrayObjectivATI;
  #define glGetVariantArrayObjectivATI GLeeFuncPtr_glGetVariantArrayObjectivATI
#endif
#endif

/* GL_EXT_vertex_shader */

#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader 1
#define __GLEE_GL_EXT_vertex_shader 1
/* Constants */
#define GL_VERTEX_SHADER_EXT                               0x8780
#define GL_VERTEX_SHADER_BINDING_EXT                       0x8781
#define GL_OP_INDEX_EXT                                    0x8782
#define GL_OP_NEGATE_EXT                                   0x8783
#define GL_OP_DOT3_EXT                                     0x8784
#define GL_OP_DOT4_EXT                                     0x8785
#define GL_OP_MUL_EXT                                      0x8786
#define GL_OP_ADD_EXT                                      0x8787
#define GL_OP_MADD_EXT                                     0x8788
#define GL_OP_FRAC_EXT                                     0x8789
#define GL_OP_MAX_EXT                                      0x878A
#define GL_OP_MIN_EXT                                      0x878B
#define GL_OP_SET_GE_EXT                                   0x878C
#define GL_OP_SET_LT_EXT                                   0x878D
#define GL_OP_CLAMP_EXT                                    0x878E
#define GL_OP_FLOOR_EXT                                    0x878F
#define GL_OP_ROUND_EXT                                    0x8790
#define GL_OP_EXP_BASE_2_EXT                               0x8791
#define GL_OP_LOG_BASE_2_EXT                               0x8792
#define GL_OP_POWER_EXT                                    0x8793
#define GL_OP_RECIP_EXT                                    0x8794
#define GL_OP_RECIP_SQRT_EXT                               0x8795
#define GL_OP_SUB_EXT                                      0x8796
#define GL_OP_CROSS_PRODUCT_EXT                            0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT                          0x8798
#define GL_OP_MOV_EXT                                      0x8799
#define GL_OUTPUT_VERTEX_EXT                               0x879A
#define GL_OUTPUT_COLOR0_EXT                               0x879B
#define GL_OUTPUT_COLOR1_EXT                               0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT                       0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT                       0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT                       0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT                       0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT                       0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT                       0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT                       0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT                       0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT                       0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT                       0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT                      0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT                      0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT                      0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT                      0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT                      0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT                      0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT                      0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT                      0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT                      0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT                      0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT                      0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT                      0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT                      0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT                      0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT                      0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT                      0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT                      0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT                      0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT                      0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT                      0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT                      0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT                      0x87BC
#define GL_OUTPUT_FOG_EXT                                  0x87BD
#define GL_SCALAR_EXT                                      0x87BE
#define GL_VECTOR_EXT                                      0x87BF
#define GL_MATRIX_EXT                                      0x87C0
#define GL_VARIANT_EXT                                     0x87C1
#define GL_INVARIANT_EXT                                   0x87C2
#define GL_LOCAL_CONSTANT_EXT                              0x87C3
#define GL_LOCAL_EXT                                       0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT              0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT                  0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT                0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT           0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT                    0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT    0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT        0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT      0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT          0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT                  0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT                      0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT                    0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT               0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT                        0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT                     0x87D4
#define GL_X_EXT                                           0x87D5
#define GL_Y_EXT                                           0x87D6
#define GL_Z_EXT                                           0x87D7
#define GL_W_EXT                                           0x87D8
#define GL_NEGATIVE_X_EXT                                  0x87D9
#define GL_NEGATIVE_Y_EXT                                  0x87DA
#define GL_NEGATIVE_Z_EXT                                  0x87DB
#define GL_NEGATIVE_W_EXT                                  0x87DC
#define GL_ZERO_EXT                                        0x87DD
#define GL_ONE_EXT                                         0x87DE
#define GL_NEGATIVE_ONE_EXT                                0x87DF
#define GL_NORMALIZED_RANGE_EXT                            0x87E0
#define GL_FULL_RANGE_EXT                                  0x87E1
#define GL_CURRENT_VERTEX_EXT                              0x87E2
#define GL_MVP_MATRIX_EXT                                  0x87E3
#define GL_VARIANT_VALUE_EXT                               0x87E4
#define GL_VARIANT_DATATYPE_EXT                            0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT                        0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT                          0x87E7
#define GL_VARIANT_ARRAY_EXT                               0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT                       0x87E9
#define GL_INVARIANT_VALUE_EXT                             0x87EA
#define GL_INVARIANT_DATATYPE_EXT                          0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT                        0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT                     0x87ED
#ifndef GLEE_H_DEFINED_glBeginVertexShaderEXT
#define GLEE_H_DEFINED_glBeginVertexShaderEXT
  typedef void (APIENTRYP GLEEPFNGLBEGINVERTEXSHADEREXTPROC) ();
  GLEE_EXTERN GLEEPFNGLBEGINVERTEXSHADEREXTPROC GLeeFuncPtr_glBeginVertexShaderEXT;
  #define glBeginVertexShaderEXT GLeeFuncPtr_glBeginVertexShaderEXT
#endif
#ifndef GLEE_H_DEFINED_glEndVertexShaderEXT
#define GLEE_H_DEFINED_glEndVertexShaderEXT
  typedef void (APIENTRYP GLEEPFNGLENDVERTEXSHADEREXTPROC) ();
  GLEE_EXTERN GLEEPFNGLENDVERTEXSHADEREXTPROC GLeeFuncPtr_glEndVertexShaderEXT;
  #define glEndVertexShaderEXT GLeeFuncPtr_glEndVertexShaderEXT
#endif
#ifndef GLEE_H_DEFINED_glBindVertexShaderEXT
#define GLEE_H_DEFINED_glBindVertexShaderEXT
  typedef void (APIENTRYP GLEEPFNGLBINDVERTEXSHADEREXTPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLBINDVERTEXSHADEREXTPROC GLeeFuncPtr_glBindVertexShaderEXT;
  #define glBindVertexShaderEXT GLeeFuncPtr_glBindVertexShaderEXT
#endif
#ifndef GLEE_H_DEFINED_glGenVertexShadersEXT
#define GLEE_H_DEFINED_glGenVertexShadersEXT
  typedef GLuint (APIENTRYP GLEEPFNGLGENVERTEXSHADERSEXTPROC) (GLuint range);
  GLEE_EXTERN GLEEPFNGLGENVERTEXSHADERSEXTPROC GLeeFuncPtr_glGenVertexShadersEXT;
  #define glGenVertexShadersEXT GLeeFuncPtr_glGenVertexShadersEXT
#endif
#ifndef GLEE_H_DEFINED_glDeleteVertexShaderEXT
#define GLEE_H_DEFINED_glDeleteVertexShaderEXT
  typedef void (APIENTRYP GLEEPFNGLDELETEVERTEXSHADEREXTPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLDELETEVERTEXSHADEREXTPROC GLeeFuncPtr_glDeleteVertexShaderEXT;
  #define glDeleteVertexShaderEXT GLeeFuncPtr_glDeleteVertexShaderEXT
#endif
#ifndef GLEE_H_DEFINED_glShaderOp1EXT
#define GLEE_H_DEFINED_glShaderOp1EXT
  typedef void (APIENTRYP GLEEPFNGLSHADEROP1EXTPROC) (GLenum op, GLuint res, GLuint arg1);
  GLEE_EXTERN GLEEPFNGLSHADEROP1EXTPROC GLeeFuncPtr_glShaderOp1EXT;
  #define glShaderOp1EXT GLeeFuncPtr_glShaderOp1EXT
#endif
#ifndef GLEE_H_DEFINED_glShaderOp2EXT
#define GLEE_H_DEFINED_glShaderOp2EXT
  typedef void (APIENTRYP GLEEPFNGLSHADEROP2EXTPROC) (GLenum op, GLuint res, GLuint arg1, GLuint arg2);
  GLEE_EXTERN GLEEPFNGLSHADEROP2EXTPROC GLeeFuncPtr_glShaderOp2EXT;
  #define glShaderOp2EXT GLeeFuncPtr_glShaderOp2EXT
#endif
#ifndef GLEE_H_DEFINED_glShaderOp3EXT
#define GLEE_H_DEFINED_glShaderOp3EXT
  typedef void (APIENTRYP GLEEPFNGLSHADEROP3EXTPROC) (GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
  GLEE_EXTERN GLEEPFNGLSHADEROP3EXTPROC GLeeFuncPtr_glShaderOp3EXT;
  #define glShaderOp3EXT GLeeFuncPtr_glShaderOp3EXT
#endif
#ifndef GLEE_H_DEFINED_glSwizzleEXT
#define GLEE_H_DEFINED_glSwizzleEXT
  typedef void (APIENTRYP GLEEPFNGLSWIZZLEEXTPROC) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
  GLEE_EXTERN GLEEPFNGLSWIZZLEEXTPROC GLeeFuncPtr_glSwizzleEXT;
  #define glSwizzleEXT GLeeFuncPtr_glSwizzleEXT
#endif
#ifndef GLEE_H_DEFINED_glWriteMaskEXT
#define GLEE_H_DEFINED_glWriteMaskEXT
  typedef void (APIENTRYP GLEEPFNGLWRITEMASKEXTPROC) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
  GLEE_EXTERN GLEEPFNGLWRITEMASKEXTPROC GLeeFuncPtr_glWriteMaskEXT;
  #define glWriteMaskEXT GLeeFuncPtr_glWriteMaskEXT
#endif
#ifndef GLEE_H_DEFINED_glInsertComponentEXT
#define GLEE_H_DEFINED_glInsertComponentEXT
  typedef void (APIENTRYP GLEEPFNGLINSERTCOMPONENTEXTPROC) (GLuint res, GLuint src, GLuint num);
  GLEE_EXTERN GLEEPFNGLINSERTCOMPONENTEXTPROC GLeeFuncPtr_glInsertComponentEXT;
  #define glInsertComponentEXT GLeeFuncPtr_glInsertComponentEXT
#endif
#ifndef GLEE_H_DEFINED_glExtractComponentEXT
#define GLEE_H_DEFINED_glExtractComponentEXT
  typedef void (APIENTRYP GLEEPFNGLEXTRACTCOMPONENTEXTPROC) (GLuint res, GLuint src, GLuint num);
  GLEE_EXTERN GLEEPFNGLEXTRACTCOMPONENTEXTPROC GLeeFuncPtr_glExtractComponentEXT;
  #define glExtractComponentEXT GLeeFuncPtr_glExtractComponentEXT
#endif
#ifndef GLEE_H_DEFINED_glGenSymbolsEXT
#define GLEE_H_DEFINED_glGenSymbolsEXT
  typedef GLuint (APIENTRYP GLEEPFNGLGENSYMBOLSEXTPROC) (GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
  GLEE_EXTERN GLEEPFNGLGENSYMBOLSEXTPROC GLeeFuncPtr_glGenSymbolsEXT;
  #define glGenSymbolsEXT GLeeFuncPtr_glGenSymbolsEXT
#endif
#ifndef GLEE_H_DEFINED_glSetInvariantEXT
#define GLEE_H_DEFINED_glSetInvariantEXT
  typedef void (APIENTRYP GLEEPFNGLSETINVARIANTEXTPROC) (GLuint id, GLenum type, const GLvoid * addr);
  GLEE_EXTERN GLEEPFNGLSETINVARIANTEXTPROC GLeeFuncPtr_glSetInvariantEXT;
  #define glSetInvariantEXT GLeeFuncPtr_glSetInvariantEXT
#endif
#ifndef GLEE_H_DEFINED_glSetLocalConstantEXT
#define GLEE_H_DEFINED_glSetLocalConstantEXT
  typedef void (APIENTRYP GLEEPFNGLSETLOCALCONSTANTEXTPROC) (GLuint id, GLenum type, const GLvoid * addr);
  GLEE_EXTERN GLEEPFNGLSETLOCALCONSTANTEXTPROC GLeeFuncPtr_glSetLocalConstantEXT;
  #define glSetLocalConstantEXT GLeeFuncPtr_glSetLocalConstantEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantbvEXT
#define GLEE_H_DEFINED_glVariantbvEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTBVEXTPROC) (GLuint id, const GLbyte * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTBVEXTPROC GLeeFuncPtr_glVariantbvEXT;
  #define glVariantbvEXT GLeeFuncPtr_glVariantbvEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantsvEXT
#define GLEE_H_DEFINED_glVariantsvEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTSVEXTPROC) (GLuint id, const GLshort * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTSVEXTPROC GLeeFuncPtr_glVariantsvEXT;
  #define glVariantsvEXT GLeeFuncPtr_glVariantsvEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantivEXT
#define GLEE_H_DEFINED_glVariantivEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTIVEXTPROC) (GLuint id, const GLint * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTIVEXTPROC GLeeFuncPtr_glVariantivEXT;
  #define glVariantivEXT GLeeFuncPtr_glVariantivEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantfvEXT
#define GLEE_H_DEFINED_glVariantfvEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTFVEXTPROC) (GLuint id, const GLfloat * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTFVEXTPROC GLeeFuncPtr_glVariantfvEXT;
  #define glVariantfvEXT GLeeFuncPtr_glVariantfvEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantdvEXT
#define GLEE_H_DEFINED_glVariantdvEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTDVEXTPROC) (GLuint id, const GLdouble * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTDVEXTPROC GLeeFuncPtr_glVariantdvEXT;
  #define glVariantdvEXT GLeeFuncPtr_glVariantdvEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantubvEXT
#define GLEE_H_DEFINED_glVariantubvEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTUBVEXTPROC) (GLuint id, const GLubyte * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTUBVEXTPROC GLeeFuncPtr_glVariantubvEXT;
  #define glVariantubvEXT GLeeFuncPtr_glVariantubvEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantusvEXT
#define GLEE_H_DEFINED_glVariantusvEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTUSVEXTPROC) (GLuint id, const GLushort * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTUSVEXTPROC GLeeFuncPtr_glVariantusvEXT;
  #define glVariantusvEXT GLeeFuncPtr_glVariantusvEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantuivEXT
#define GLEE_H_DEFINED_glVariantuivEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTUIVEXTPROC) (GLuint id, const GLuint * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTUIVEXTPROC GLeeFuncPtr_glVariantuivEXT;
  #define glVariantuivEXT GLeeFuncPtr_glVariantuivEXT
#endif
#ifndef GLEE_H_DEFINED_glVariantPointerEXT
#define GLEE_H_DEFINED_glVariantPointerEXT
  typedef void (APIENTRYP GLEEPFNGLVARIANTPOINTEREXTPROC) (GLuint id, GLenum type, GLuint stride, const GLvoid * addr);
  GLEE_EXTERN GLEEPFNGLVARIANTPOINTEREXTPROC GLeeFuncPtr_glVariantPointerEXT;
  #define glVariantPointerEXT GLeeFuncPtr_glVariantPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glEnableVariantClientStateEXT
#define GLEE_H_DEFINED_glEnableVariantClientStateEXT
  typedef void (APIENTRYP GLEEPFNGLENABLEVARIANTCLIENTSTATEEXTPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLENABLEVARIANTCLIENTSTATEEXTPROC GLeeFuncPtr_glEnableVariantClientStateEXT;
  #define glEnableVariantClientStateEXT GLeeFuncPtr_glEnableVariantClientStateEXT
#endif
#ifndef GLEE_H_DEFINED_glDisableVariantClientStateEXT
#define GLEE_H_DEFINED_glDisableVariantClientStateEXT
  typedef void (APIENTRYP GLEEPFNGLDISABLEVARIANTCLIENTSTATEEXTPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLDISABLEVARIANTCLIENTSTATEEXTPROC GLeeFuncPtr_glDisableVariantClientStateEXT;
  #define glDisableVariantClientStateEXT GLeeFuncPtr_glDisableVariantClientStateEXT
#endif
#ifndef GLEE_H_DEFINED_glBindLightParameterEXT
#define GLEE_H_DEFINED_glBindLightParameterEXT
  typedef GLuint (APIENTRYP GLEEPFNGLBINDLIGHTPARAMETEREXTPROC) (GLenum light, GLenum value);
  GLEE_EXTERN GLEEPFNGLBINDLIGHTPARAMETEREXTPROC GLeeFuncPtr_glBindLightParameterEXT;
  #define glBindLightParameterEXT GLeeFuncPtr_glBindLightParameterEXT
#endif
#ifndef GLEE_H_DEFINED_glBindMaterialParameterEXT
#define GLEE_H_DEFINED_glBindMaterialParameterEXT
  typedef GLuint (APIENTRYP GLEEPFNGLBINDMATERIALPARAMETEREXTPROC) (GLenum face, GLenum value);
  GLEE_EXTERN GLEEPFNGLBINDMATERIALPARAMETEREXTPROC GLeeFuncPtr_glBindMaterialParameterEXT;
  #define glBindMaterialParameterEXT GLeeFuncPtr_glBindMaterialParameterEXT
#endif
#ifndef GLEE_H_DEFINED_glBindTexGenParameterEXT
#define GLEE_H_DEFINED_glBindTexGenParameterEXT
  typedef GLuint (APIENTRYP GLEEPFNGLBINDTEXGENPARAMETEREXTPROC) (GLenum unit, GLenum coord, GLenum value);
  GLEE_EXTERN GLEEPFNGLBINDTEXGENPARAMETEREXTPROC GLeeFuncPtr_glBindTexGenParameterEXT;
  #define glBindTexGenParameterEXT GLeeFuncPtr_glBindTexGenParameterEXT
#endif
#ifndef GLEE_H_DEFINED_glBindTextureUnitParameterEXT
#define GLEE_H_DEFINED_glBindTextureUnitParameterEXT
  typedef GLuint (APIENTRYP GLEEPFNGLBINDTEXTUREUNITPARAMETEREXTPROC) (GLenum unit, GLenum value);
  GLEE_EXTERN GLEEPFNGLBINDTEXTUREUNITPARAMETEREXTPROC GLeeFuncPtr_glBindTextureUnitParameterEXT;
  #define glBindTextureUnitParameterEXT GLeeFuncPtr_glBindTextureUnitParameterEXT
#endif
#ifndef GLEE_H_DEFINED_glBindParameterEXT
#define GLEE_H_DEFINED_glBindParameterEXT
  typedef GLuint (APIENTRYP GLEEPFNGLBINDPARAMETEREXTPROC) (GLenum value);
  GLEE_EXTERN GLEEPFNGLBINDPARAMETEREXTPROC GLeeFuncPtr_glBindParameterEXT;
  #define glBindParameterEXT GLeeFuncPtr_glBindParameterEXT
#endif
#ifndef GLEE_H_DEFINED_glIsVariantEnabledEXT
#define GLEE_H_DEFINED_glIsVariantEnabledEXT
  typedef GLboolean (APIENTRYP GLEEPFNGLISVARIANTENABLEDEXTPROC) (GLuint id, GLenum cap);
  GLEE_EXTERN GLEEPFNGLISVARIANTENABLEDEXTPROC GLeeFuncPtr_glIsVariantEnabledEXT;
  #define glIsVariantEnabledEXT GLeeFuncPtr_glIsVariantEnabledEXT
#endif
#ifndef GLEE_H_DEFINED_glGetVariantBooleanvEXT
#define GLEE_H_DEFINED_glGetVariantBooleanvEXT
  typedef void (APIENTRYP GLEEPFNGLGETVARIANTBOOLEANVEXTPROC) (GLuint id, GLenum value, GLboolean * data);
  GLEE_EXTERN GLEEPFNGLGETVARIANTBOOLEANVEXTPROC GLeeFuncPtr_glGetVariantBooleanvEXT;
  #define glGetVariantBooleanvEXT GLeeFuncPtr_glGetVariantBooleanvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetVariantIntegervEXT
#define GLEE_H_DEFINED_glGetVariantIntegervEXT
  typedef void (APIENTRYP GLEEPFNGLGETVARIANTINTEGERVEXTPROC) (GLuint id, GLenum value, GLint * data);
  GLEE_EXTERN GLEEPFNGLGETVARIANTINTEGERVEXTPROC GLeeFuncPtr_glGetVariantIntegervEXT;
  #define glGetVariantIntegervEXT GLeeFuncPtr_glGetVariantIntegervEXT
#endif
#ifndef GLEE_H_DEFINED_glGetVariantFloatvEXT
#define GLEE_H_DEFINED_glGetVariantFloatvEXT
  typedef void (APIENTRYP GLEEPFNGLGETVARIANTFLOATVEXTPROC) (GLuint id, GLenum value, GLfloat * data);
  GLEE_EXTERN GLEEPFNGLGETVARIANTFLOATVEXTPROC GLeeFuncPtr_glGetVariantFloatvEXT;
  #define glGetVariantFloatvEXT GLeeFuncPtr_glGetVariantFloatvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetVariantPointervEXT
#define GLEE_H_DEFINED_glGetVariantPointervEXT
  typedef void (APIENTRYP GLEEPFNGLGETVARIANTPOINTERVEXTPROC) (GLuint id, GLenum value, GLvoid* * data);
  GLEE_EXTERN GLEEPFNGLGETVARIANTPOINTERVEXTPROC GLeeFuncPtr_glGetVariantPointervEXT;
  #define glGetVariantPointervEXT GLeeFuncPtr_glGetVariantPointervEXT
#endif
#ifndef GLEE_H_DEFINED_glGetInvariantBooleanvEXT
#define GLEE_H_DEFINED_glGetInvariantBooleanvEXT
  typedef void (APIENTRYP GLEEPFNGLGETINVARIANTBOOLEANVEXTPROC) (GLuint id, GLenum value, GLboolean * data);
  GLEE_EXTERN GLEEPFNGLGETINVARIANTBOOLEANVEXTPROC GLeeFuncPtr_glGetInvariantBooleanvEXT;
  #define glGetInvariantBooleanvEXT GLeeFuncPtr_glGetInvariantBooleanvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetInvariantIntegervEXT
#define GLEE_H_DEFINED_glGetInvariantIntegervEXT
  typedef void (APIENTRYP GLEEPFNGLGETINVARIANTINTEGERVEXTPROC) (GLuint id, GLenum value, GLint * data);
  GLEE_EXTERN GLEEPFNGLGETINVARIANTINTEGERVEXTPROC GLeeFuncPtr_glGetInvariantIntegervEXT;
  #define glGetInvariantIntegervEXT GLeeFuncPtr_glGetInvariantIntegervEXT
#endif
#ifndef GLEE_H_DEFINED_glGetInvariantFloatvEXT
#define GLEE_H_DEFINED_glGetInvariantFloatvEXT
  typedef void (APIENTRYP GLEEPFNGLGETINVARIANTFLOATVEXTPROC) (GLuint id, GLenum value, GLfloat * data);
  GLEE_EXTERN GLEEPFNGLGETINVARIANTFLOATVEXTPROC GLeeFuncPtr_glGetInvariantFloatvEXT;
  #define glGetInvariantFloatvEXT GLeeFuncPtr_glGetInvariantFloatvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetLocalConstantBooleanvEXT
#define GLEE_H_DEFINED_glGetLocalConstantBooleanvEXT
  typedef void (APIENTRYP GLEEPFNGLGETLOCALCONSTANTBOOLEANVEXTPROC) (GLuint id, GLenum value, GLboolean * data);
  GLEE_EXTERN GLEEPFNGLGETLOCALCONSTANTBOOLEANVEXTPROC GLeeFuncPtr_glGetLocalConstantBooleanvEXT;
  #define glGetLocalConstantBooleanvEXT GLeeFuncPtr_glGetLocalConstantBooleanvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetLocalConstantIntegervEXT
#define GLEE_H_DEFINED_glGetLocalConstantIntegervEXT
  typedef void (APIENTRYP GLEEPFNGLGETLOCALCONSTANTINTEGERVEXTPROC) (GLuint id, GLenum value, GLint * data);
  GLEE_EXTERN GLEEPFNGLGETLOCALCONSTANTINTEGERVEXTPROC GLeeFuncPtr_glGetLocalConstantIntegervEXT;
  #define glGetLocalConstantIntegervEXT GLeeFuncPtr_glGetLocalConstantIntegervEXT
#endif
#ifndef GLEE_H_DEFINED_glGetLocalConstantFloatvEXT
#define GLEE_H_DEFINED_glGetLocalConstantFloatvEXT
  typedef void (APIENTRYP GLEEPFNGLGETLOCALCONSTANTFLOATVEXTPROC) (GLuint id, GLenum value, GLfloat * data);
  GLEE_EXTERN GLEEPFNGLGETLOCALCONSTANTFLOATVEXTPROC GLeeFuncPtr_glGetLocalConstantFloatvEXT;
  #define glGetLocalConstantFloatvEXT GLeeFuncPtr_glGetLocalConstantFloatvEXT
#endif
#endif

/* GL_ATI_vertex_streams */

#ifndef GL_ATI_vertex_streams
#define GL_ATI_vertex_streams 1
#define __GLEE_GL_ATI_vertex_streams 1
/* Constants */
#define GL_MAX_VERTEX_STREAMS_ATI                          0x876B
#define GL_VERTEX_STREAM0_ATI                              0x876C
#define GL_VERTEX_STREAM1_ATI                              0x876D
#define GL_VERTEX_STREAM2_ATI                              0x876E
#define GL_VERTEX_STREAM3_ATI                              0x876F
#define GL_VERTEX_STREAM4_ATI                              0x8770
#define GL_VERTEX_STREAM5_ATI                              0x8771
#define GL_VERTEX_STREAM6_ATI                              0x8772
#define GL_VERTEX_STREAM7_ATI                              0x8773
#define GL_VERTEX_SOURCE_ATI                               0x8774
#ifndef GLEE_H_DEFINED_glVertexStream1sATI
#define GLEE_H_DEFINED_glVertexStream1sATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1SATIPROC) (GLenum stream, GLshort x);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1SATIPROC GLeeFuncPtr_glVertexStream1sATI;
  #define glVertexStream1sATI GLeeFuncPtr_glVertexStream1sATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream1svATI
#define GLEE_H_DEFINED_glVertexStream1svATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1SVATIPROC) (GLenum stream, const GLshort * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1SVATIPROC GLeeFuncPtr_glVertexStream1svATI;
  #define glVertexStream1svATI GLeeFuncPtr_glVertexStream1svATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream1iATI
#define GLEE_H_DEFINED_glVertexStream1iATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1IATIPROC) (GLenum stream, GLint x);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1IATIPROC GLeeFuncPtr_glVertexStream1iATI;
  #define glVertexStream1iATI GLeeFuncPtr_glVertexStream1iATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream1ivATI
#define GLEE_H_DEFINED_glVertexStream1ivATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1IVATIPROC) (GLenum stream, const GLint * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1IVATIPROC GLeeFuncPtr_glVertexStream1ivATI;
  #define glVertexStream1ivATI GLeeFuncPtr_glVertexStream1ivATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream1fATI
#define GLEE_H_DEFINED_glVertexStream1fATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1FATIPROC) (GLenum stream, GLfloat x);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1FATIPROC GLeeFuncPtr_glVertexStream1fATI;
  #define glVertexStream1fATI GLeeFuncPtr_glVertexStream1fATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream1fvATI
#define GLEE_H_DEFINED_glVertexStream1fvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1FVATIPROC) (GLenum stream, const GLfloat * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1FVATIPROC GLeeFuncPtr_glVertexStream1fvATI;
  #define glVertexStream1fvATI GLeeFuncPtr_glVertexStream1fvATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream1dATI
#define GLEE_H_DEFINED_glVertexStream1dATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1DATIPROC) (GLenum stream, GLdouble x);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1DATIPROC GLeeFuncPtr_glVertexStream1dATI;
  #define glVertexStream1dATI GLeeFuncPtr_glVertexStream1dATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream1dvATI
#define GLEE_H_DEFINED_glVertexStream1dvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM1DVATIPROC) (GLenum stream, const GLdouble * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM1DVATIPROC GLeeFuncPtr_glVertexStream1dvATI;
  #define glVertexStream1dvATI GLeeFuncPtr_glVertexStream1dvATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2sATI
#define GLEE_H_DEFINED_glVertexStream2sATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2SATIPROC) (GLenum stream, GLshort x, GLshort y);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2SATIPROC GLeeFuncPtr_glVertexStream2sATI;
  #define glVertexStream2sATI GLeeFuncPtr_glVertexStream2sATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2svATI
#define GLEE_H_DEFINED_glVertexStream2svATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2SVATIPROC) (GLenum stream, const GLshort * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2SVATIPROC GLeeFuncPtr_glVertexStream2svATI;
  #define glVertexStream2svATI GLeeFuncPtr_glVertexStream2svATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2iATI
#define GLEE_H_DEFINED_glVertexStream2iATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2IATIPROC) (GLenum stream, GLint x, GLint y);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2IATIPROC GLeeFuncPtr_glVertexStream2iATI;
  #define glVertexStream2iATI GLeeFuncPtr_glVertexStream2iATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2ivATI
#define GLEE_H_DEFINED_glVertexStream2ivATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2IVATIPROC) (GLenum stream, const GLint * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2IVATIPROC GLeeFuncPtr_glVertexStream2ivATI;
  #define glVertexStream2ivATI GLeeFuncPtr_glVertexStream2ivATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2fATI
#define GLEE_H_DEFINED_glVertexStream2fATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2FATIPROC) (GLenum stream, GLfloat x, GLfloat y);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2FATIPROC GLeeFuncPtr_glVertexStream2fATI;
  #define glVertexStream2fATI GLeeFuncPtr_glVertexStream2fATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2fvATI
#define GLEE_H_DEFINED_glVertexStream2fvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2FVATIPROC) (GLenum stream, const GLfloat * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2FVATIPROC GLeeFuncPtr_glVertexStream2fvATI;
  #define glVertexStream2fvATI GLeeFuncPtr_glVertexStream2fvATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2dATI
#define GLEE_H_DEFINED_glVertexStream2dATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2DATIPROC) (GLenum stream, GLdouble x, GLdouble y);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2DATIPROC GLeeFuncPtr_glVertexStream2dATI;
  #define glVertexStream2dATI GLeeFuncPtr_glVertexStream2dATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream2dvATI
#define GLEE_H_DEFINED_glVertexStream2dvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM2DVATIPROC) (GLenum stream, const GLdouble * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM2DVATIPROC GLeeFuncPtr_glVertexStream2dvATI;
  #define glVertexStream2dvATI GLeeFuncPtr_glVertexStream2dvATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3sATI
#define GLEE_H_DEFINED_glVertexStream3sATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3SATIPROC) (GLenum stream, GLshort x, GLshort y, GLshort z);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3SATIPROC GLeeFuncPtr_glVertexStream3sATI;
  #define glVertexStream3sATI GLeeFuncPtr_glVertexStream3sATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3svATI
#define GLEE_H_DEFINED_glVertexStream3svATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3SVATIPROC) (GLenum stream, const GLshort * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3SVATIPROC GLeeFuncPtr_glVertexStream3svATI;
  #define glVertexStream3svATI GLeeFuncPtr_glVertexStream3svATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3iATI
#define GLEE_H_DEFINED_glVertexStream3iATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3IATIPROC) (GLenum stream, GLint x, GLint y, GLint z);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3IATIPROC GLeeFuncPtr_glVertexStream3iATI;
  #define glVertexStream3iATI GLeeFuncPtr_glVertexStream3iATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3ivATI
#define GLEE_H_DEFINED_glVertexStream3ivATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3IVATIPROC) (GLenum stream, const GLint * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3IVATIPROC GLeeFuncPtr_glVertexStream3ivATI;
  #define glVertexStream3ivATI GLeeFuncPtr_glVertexStream3ivATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3fATI
#define GLEE_H_DEFINED_glVertexStream3fATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3FATIPROC) (GLenum stream, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3FATIPROC GLeeFuncPtr_glVertexStream3fATI;
  #define glVertexStream3fATI GLeeFuncPtr_glVertexStream3fATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3fvATI
#define GLEE_H_DEFINED_glVertexStream3fvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3FVATIPROC) (GLenum stream, const GLfloat * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3FVATIPROC GLeeFuncPtr_glVertexStream3fvATI;
  #define glVertexStream3fvATI GLeeFuncPtr_glVertexStream3fvATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3dATI
#define GLEE_H_DEFINED_glVertexStream3dATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3DATIPROC) (GLenum stream, GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3DATIPROC GLeeFuncPtr_glVertexStream3dATI;
  #define glVertexStream3dATI GLeeFuncPtr_glVertexStream3dATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream3dvATI
#define GLEE_H_DEFINED_glVertexStream3dvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM3DVATIPROC) (GLenum stream, const GLdouble * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM3DVATIPROC GLeeFuncPtr_glVertexStream3dvATI;
  #define glVertexStream3dvATI GLeeFuncPtr_glVertexStream3dvATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4sATI
#define GLEE_H_DEFINED_glVertexStream4sATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4SATIPROC) (GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4SATIPROC GLeeFuncPtr_glVertexStream4sATI;
  #define glVertexStream4sATI GLeeFuncPtr_glVertexStream4sATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4svATI
#define GLEE_H_DEFINED_glVertexStream4svATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4SVATIPROC) (GLenum stream, const GLshort * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4SVATIPROC GLeeFuncPtr_glVertexStream4svATI;
  #define glVertexStream4svATI GLeeFuncPtr_glVertexStream4svATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4iATI
#define GLEE_H_DEFINED_glVertexStream4iATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4IATIPROC) (GLenum stream, GLint x, GLint y, GLint z, GLint w);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4IATIPROC GLeeFuncPtr_glVertexStream4iATI;
  #define glVertexStream4iATI GLeeFuncPtr_glVertexStream4iATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4ivATI
#define GLEE_H_DEFINED_glVertexStream4ivATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4IVATIPROC) (GLenum stream, const GLint * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4IVATIPROC GLeeFuncPtr_glVertexStream4ivATI;
  #define glVertexStream4ivATI GLeeFuncPtr_glVertexStream4ivATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4fATI
#define GLEE_H_DEFINED_glVertexStream4fATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4FATIPROC) (GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4FATIPROC GLeeFuncPtr_glVertexStream4fATI;
  #define glVertexStream4fATI GLeeFuncPtr_glVertexStream4fATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4fvATI
#define GLEE_H_DEFINED_glVertexStream4fvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4FVATIPROC) (GLenum stream, const GLfloat * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4FVATIPROC GLeeFuncPtr_glVertexStream4fvATI;
  #define glVertexStream4fvATI GLeeFuncPtr_glVertexStream4fvATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4dATI
#define GLEE_H_DEFINED_glVertexStream4dATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4DATIPROC) (GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4DATIPROC GLeeFuncPtr_glVertexStream4dATI;
  #define glVertexStream4dATI GLeeFuncPtr_glVertexStream4dATI
#endif
#ifndef GLEE_H_DEFINED_glVertexStream4dvATI
#define GLEE_H_DEFINED_glVertexStream4dvATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXSTREAM4DVATIPROC) (GLenum stream, const GLdouble * coords);
  GLEE_EXTERN GLEEPFNGLVERTEXSTREAM4DVATIPROC GLeeFuncPtr_glVertexStream4dvATI;
  #define glVertexStream4dvATI GLeeFuncPtr_glVertexStream4dvATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3bATI
#define GLEE_H_DEFINED_glNormalStream3bATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3BATIPROC) (GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3BATIPROC GLeeFuncPtr_glNormalStream3bATI;
  #define glNormalStream3bATI GLeeFuncPtr_glNormalStream3bATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3bvATI
#define GLEE_H_DEFINED_glNormalStream3bvATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3BVATIPROC) (GLenum stream, const GLbyte * coords);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3BVATIPROC GLeeFuncPtr_glNormalStream3bvATI;
  #define glNormalStream3bvATI GLeeFuncPtr_glNormalStream3bvATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3sATI
#define GLEE_H_DEFINED_glNormalStream3sATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3SATIPROC) (GLenum stream, GLshort nx, GLshort ny, GLshort nz);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3SATIPROC GLeeFuncPtr_glNormalStream3sATI;
  #define glNormalStream3sATI GLeeFuncPtr_glNormalStream3sATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3svATI
#define GLEE_H_DEFINED_glNormalStream3svATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3SVATIPROC) (GLenum stream, const GLshort * coords);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3SVATIPROC GLeeFuncPtr_glNormalStream3svATI;
  #define glNormalStream3svATI GLeeFuncPtr_glNormalStream3svATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3iATI
#define GLEE_H_DEFINED_glNormalStream3iATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3IATIPROC) (GLenum stream, GLint nx, GLint ny, GLint nz);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3IATIPROC GLeeFuncPtr_glNormalStream3iATI;
  #define glNormalStream3iATI GLeeFuncPtr_glNormalStream3iATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3ivATI
#define GLEE_H_DEFINED_glNormalStream3ivATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3IVATIPROC) (GLenum stream, const GLint * coords);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3IVATIPROC GLeeFuncPtr_glNormalStream3ivATI;
  #define glNormalStream3ivATI GLeeFuncPtr_glNormalStream3ivATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3fATI
#define GLEE_H_DEFINED_glNormalStream3fATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3FATIPROC) (GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3FATIPROC GLeeFuncPtr_glNormalStream3fATI;
  #define glNormalStream3fATI GLeeFuncPtr_glNormalStream3fATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3fvATI
#define GLEE_H_DEFINED_glNormalStream3fvATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3FVATIPROC) (GLenum stream, const GLfloat * coords);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3FVATIPROC GLeeFuncPtr_glNormalStream3fvATI;
  #define glNormalStream3fvATI GLeeFuncPtr_glNormalStream3fvATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3dATI
#define GLEE_H_DEFINED_glNormalStream3dATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3DATIPROC) (GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3DATIPROC GLeeFuncPtr_glNormalStream3dATI;
  #define glNormalStream3dATI GLeeFuncPtr_glNormalStream3dATI
#endif
#ifndef GLEE_H_DEFINED_glNormalStream3dvATI
#define GLEE_H_DEFINED_glNormalStream3dvATI
  typedef void (APIENTRYP GLEEPFNGLNORMALSTREAM3DVATIPROC) (GLenum stream, const GLdouble * coords);
  GLEE_EXTERN GLEEPFNGLNORMALSTREAM3DVATIPROC GLeeFuncPtr_glNormalStream3dvATI;
  #define glNormalStream3dvATI GLeeFuncPtr_glNormalStream3dvATI
#endif
#ifndef GLEE_H_DEFINED_glClientActiveVertexStreamATI
#define GLEE_H_DEFINED_glClientActiveVertexStreamATI
  typedef void (APIENTRYP GLEEPFNGLCLIENTACTIVEVERTEXSTREAMATIPROC) (GLenum stream);
  GLEE_EXTERN GLEEPFNGLCLIENTACTIVEVERTEXSTREAMATIPROC GLeeFuncPtr_glClientActiveVertexStreamATI;
  #define glClientActiveVertexStreamATI GLeeFuncPtr_glClientActiveVertexStreamATI
#endif
#ifndef GLEE_H_DEFINED_glVertexBlendEnviATI
#define GLEE_H_DEFINED_glVertexBlendEnviATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXBLENDENVIATIPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLVERTEXBLENDENVIATIPROC GLeeFuncPtr_glVertexBlendEnviATI;
  #define glVertexBlendEnviATI GLeeFuncPtr_glVertexBlendEnviATI
#endif
#ifndef GLEE_H_DEFINED_glVertexBlendEnvfATI
#define GLEE_H_DEFINED_glVertexBlendEnvfATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXBLENDENVFATIPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLVERTEXBLENDENVFATIPROC GLeeFuncPtr_glVertexBlendEnvfATI;
  #define glVertexBlendEnvfATI GLeeFuncPtr_glVertexBlendEnvfATI
#endif
#endif

/* GL_ATI_element_array */

#ifndef GL_ATI_element_array
#define GL_ATI_element_array 1
#define __GLEE_GL_ATI_element_array 1
/* Constants */
#define GL_ELEMENT_ARRAY_ATI                               0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI                          0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI                       0x876A
#ifndef GLEE_H_DEFINED_glElementPointerATI
#define GLEE_H_DEFINED_glElementPointerATI
  typedef void (APIENTRYP GLEEPFNGLELEMENTPOINTERATIPROC) (GLenum type, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLELEMENTPOINTERATIPROC GLeeFuncPtr_glElementPointerATI;
  #define glElementPointerATI GLeeFuncPtr_glElementPointerATI
#endif
#ifndef GLEE_H_DEFINED_glDrawElementArrayATI
#define GLEE_H_DEFINED_glDrawElementArrayATI
  typedef void (APIENTRYP GLEEPFNGLDRAWELEMENTARRAYATIPROC) (GLenum mode, GLsizei count);
  GLEE_EXTERN GLEEPFNGLDRAWELEMENTARRAYATIPROC GLeeFuncPtr_glDrawElementArrayATI;
  #define glDrawElementArrayATI GLeeFuncPtr_glDrawElementArrayATI
#endif
#ifndef GLEE_H_DEFINED_glDrawRangeElementArrayATI
#define GLEE_H_DEFINED_glDrawRangeElementArrayATI
  typedef void (APIENTRYP GLEEPFNGLDRAWRANGEELEMENTARRAYATIPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count);
  GLEE_EXTERN GLEEPFNGLDRAWRANGEELEMENTARRAYATIPROC GLeeFuncPtr_glDrawRangeElementArrayATI;
  #define glDrawRangeElementArrayATI GLeeFuncPtr_glDrawRangeElementArrayATI
#endif
#endif

/* GL_SUN_mesh_array */

#ifndef GL_SUN_mesh_array
#define GL_SUN_mesh_array 1
#define __GLEE_GL_SUN_mesh_array 1
/* Constants */
#define GL_QUAD_MESH_SUN                                   0x8614
#define GL_TRIANGLE_MESH_SUN                               0x8615
#ifndef GLEE_H_DEFINED_glDrawMeshArraysSUN
#define GLEE_H_DEFINED_glDrawMeshArraysSUN
  typedef void (APIENTRYP GLEEPFNGLDRAWMESHARRAYSSUNPROC) (GLenum mode, GLint first, GLsizei count, GLsizei width);
  GLEE_EXTERN GLEEPFNGLDRAWMESHARRAYSSUNPROC GLeeFuncPtr_glDrawMeshArraysSUN;
  #define glDrawMeshArraysSUN GLeeFuncPtr_glDrawMeshArraysSUN
#endif
#endif

/* GL_SUN_slice_accum */

#ifndef GL_SUN_slice_accum
#define GL_SUN_slice_accum 1
#define __GLEE_GL_SUN_slice_accum 1
/* Constants */
#define GL_SLICE_ACCUM_SUN                                 0x85CC
#endif

/* GL_NV_multisample_filter_hint */

#ifndef GL_NV_multisample_filter_hint
#define GL_NV_multisample_filter_hint 1
#define __GLEE_GL_NV_multisample_filter_hint 1
/* Constants */
#define GL_MULTISAMPLE_FILTER_HINT_NV                      0x8534
#endif

/* GL_NV_depth_clamp */

#ifndef GL_NV_depth_clamp
#define GL_NV_depth_clamp 1
#define __GLEE_GL_NV_depth_clamp 1
/* Constants */
#define GL_DEPTH_CLAMP_NV                                  0x864F
#endif

/* GL_NV_occlusion_query */

#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1
#define __GLEE_GL_NV_occlusion_query 1
/* Constants */
#define GL_PIXEL_COUNTER_BITS_NV                           0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV                   0x8865
#define GL_PIXEL_COUNT_NV                                  0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV                        0x8867
#ifndef GLEE_H_DEFINED_glGenOcclusionQueriesNV
#define GLEE_H_DEFINED_glGenOcclusionQueriesNV
  typedef void (APIENTRYP GLEEPFNGLGENOCCLUSIONQUERIESNVPROC) (GLsizei n, GLuint * ids);
  GLEE_EXTERN GLEEPFNGLGENOCCLUSIONQUERIESNVPROC GLeeFuncPtr_glGenOcclusionQueriesNV;
  #define glGenOcclusionQueriesNV GLeeFuncPtr_glGenOcclusionQueriesNV
#endif
#ifndef GLEE_H_DEFINED_glDeleteOcclusionQueriesNV
#define GLEE_H_DEFINED_glDeleteOcclusionQueriesNV
  typedef void (APIENTRYP GLEEPFNGLDELETEOCCLUSIONQUERIESNVPROC) (GLsizei n, const GLuint * ids);
  GLEE_EXTERN GLEEPFNGLDELETEOCCLUSIONQUERIESNVPROC GLeeFuncPtr_glDeleteOcclusionQueriesNV;
  #define glDeleteOcclusionQueriesNV GLeeFuncPtr_glDeleteOcclusionQueriesNV
#endif
#ifndef GLEE_H_DEFINED_glIsOcclusionQueryNV
#define GLEE_H_DEFINED_glIsOcclusionQueryNV
  typedef GLboolean (APIENTRYP GLEEPFNGLISOCCLUSIONQUERYNVPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLISOCCLUSIONQUERYNVPROC GLeeFuncPtr_glIsOcclusionQueryNV;
  #define glIsOcclusionQueryNV GLeeFuncPtr_glIsOcclusionQueryNV
#endif
#ifndef GLEE_H_DEFINED_glBeginOcclusionQueryNV
#define GLEE_H_DEFINED_glBeginOcclusionQueryNV
  typedef void (APIENTRYP GLEEPFNGLBEGINOCCLUSIONQUERYNVPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLBEGINOCCLUSIONQUERYNVPROC GLeeFuncPtr_glBeginOcclusionQueryNV;
  #define glBeginOcclusionQueryNV GLeeFuncPtr_glBeginOcclusionQueryNV
#endif
#ifndef GLEE_H_DEFINED_glEndOcclusionQueryNV
#define GLEE_H_DEFINED_glEndOcclusionQueryNV
  typedef void (APIENTRYP GLEEPFNGLENDOCCLUSIONQUERYNVPROC) ();
  GLEE_EXTERN GLEEPFNGLENDOCCLUSIONQUERYNVPROC GLeeFuncPtr_glEndOcclusionQueryNV;
  #define glEndOcclusionQueryNV GLeeFuncPtr_glEndOcclusionQueryNV
#endif
#ifndef GLEE_H_DEFINED_glGetOcclusionQueryivNV
#define GLEE_H_DEFINED_glGetOcclusionQueryivNV
  typedef void (APIENTRYP GLEEPFNGLGETOCCLUSIONQUERYIVNVPROC) (GLuint id, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETOCCLUSIONQUERYIVNVPROC GLeeFuncPtr_glGetOcclusionQueryivNV;
  #define glGetOcclusionQueryivNV GLeeFuncPtr_glGetOcclusionQueryivNV
#endif
#ifndef GLEE_H_DEFINED_glGetOcclusionQueryuivNV
#define GLEE_H_DEFINED_glGetOcclusionQueryuivNV
  typedef void (APIENTRYP GLEEPFNGLGETOCCLUSIONQUERYUIVNVPROC) (GLuint id, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETOCCLUSIONQUERYUIVNVPROC GLeeFuncPtr_glGetOcclusionQueryuivNV;
  #define glGetOcclusionQueryuivNV GLeeFuncPtr_glGetOcclusionQueryuivNV
#endif
#endif

/* GL_NV_point_sprite */

#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1
#define __GLEE_GL_NV_point_sprite 1
/* Constants */
#define GL_POINT_SPRITE_NV                                 0x8861
#define GL_COORD_REPLACE_NV                                0x8862
#define GL_POINT_SPRITE_R_MODE_NV                          0x8863
#ifndef GLEE_H_DEFINED_glPointParameteriNV
#define GLEE_H_DEFINED_glPointParameteriNV
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERINVPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERINVPROC GLeeFuncPtr_glPointParameteriNV;
  #define glPointParameteriNV GLeeFuncPtr_glPointParameteriNV
#endif
#ifndef GLEE_H_DEFINED_glPointParameterivNV
#define GLEE_H_DEFINED_glPointParameterivNV
  typedef void (APIENTRYP GLEEPFNGLPOINTPARAMETERIVNVPROC) (GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPOINTPARAMETERIVNVPROC GLeeFuncPtr_glPointParameterivNV;
  #define glPointParameterivNV GLeeFuncPtr_glPointParameterivNV
#endif
#endif

/* GL_NV_texture_shader3 */

#ifndef GL_NV_texture_shader3
#define GL_NV_texture_shader3 1
#define __GLEE_GL_NV_texture_shader3 1
/* Constants */
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV                 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV           0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV          0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV    0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV                       0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV                0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV            0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV     0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV                    0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV                     0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV               0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV                     0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV                       0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV             0x885D
#define GL_HILO8_NV                                        0x885E
#define GL_SIGNED_HILO8_NV                                 0x885F
#define GL_FORCE_BLUE_TO_ONE_NV                            0x8860
#endif

/* GL_NV_vertex_program1_1 */

#ifndef GL_NV_vertex_program1_1
#define GL_NV_vertex_program1_1 1
#define __GLEE_GL_NV_vertex_program1_1 1
/* Constants */
#endif

/* GL_EXT_shadow_funcs */

#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs 1
#define __GLEE_GL_EXT_shadow_funcs 1
/* Constants */
#endif

/* GL_EXT_stencil_two_side */

#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
#define __GLEE_GL_EXT_stencil_two_side 1
/* Constants */
#define GL_STENCIL_TEST_TWO_SIDE_EXT                       0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT                         0x8911
#ifndef GLEE_H_DEFINED_glActiveStencilFaceEXT
#define GLEE_H_DEFINED_glActiveStencilFaceEXT
  typedef void (APIENTRYP GLEEPFNGLACTIVESTENCILFACEEXTPROC) (GLenum face);
  GLEE_EXTERN GLEEPFNGLACTIVESTENCILFACEEXTPROC GLeeFuncPtr_glActiveStencilFaceEXT;
  #define glActiveStencilFaceEXT GLeeFuncPtr_glActiveStencilFaceEXT
#endif
#endif

/* GL_ATI_text_fragment_shader */

#ifndef GL_ATI_text_fragment_shader
#define GL_ATI_text_fragment_shader 1
#define __GLEE_GL_ATI_text_fragment_shader 1
/* Constants */
#define GL_TEXT_FRAGMENT_SHADER_ATI                        0x8200
#endif

/* GL_APPLE_client_storage */

#ifndef GL_APPLE_client_storage
#define GL_APPLE_client_storage 1
#define __GLEE_GL_APPLE_client_storage 1
/* Constants */
#define GL_UNPACK_CLIENT_STORAGE_APPLE                     0x85B2
#endif

/* GL_APPLE_element_array */

#ifndef GL_APPLE_element_array
#define GL_APPLE_element_array 1
#define __GLEE_GL_APPLE_element_array 1
/* Constants */
#define GL_ELEMENT_ARRAY_APPLE                             0x8768
#define GL_ELEMENT_ARRAY_TYPE_APPLE                        0x8769
#define GL_ELEMENT_ARRAY_POINTER_APPLE                     0x876A
#ifndef GLEE_H_DEFINED_glElementPointerAPPLE
#define GLEE_H_DEFINED_glElementPointerAPPLE
  typedef void (APIENTRYP GLEEPFNGLELEMENTPOINTERAPPLEPROC) (GLenum type, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLELEMENTPOINTERAPPLEPROC GLeeFuncPtr_glElementPointerAPPLE;
  #define glElementPointerAPPLE GLeeFuncPtr_glElementPointerAPPLE
#endif
#ifndef GLEE_H_DEFINED_glDrawElementArrayAPPLE
#define GLEE_H_DEFINED_glDrawElementArrayAPPLE
  typedef void (APIENTRYP GLEEPFNGLDRAWELEMENTARRAYAPPLEPROC) (GLenum mode, GLint first, GLsizei count);
  GLEE_EXTERN GLEEPFNGLDRAWELEMENTARRAYAPPLEPROC GLeeFuncPtr_glDrawElementArrayAPPLE;
  #define glDrawElementArrayAPPLE GLeeFuncPtr_glDrawElementArrayAPPLE
#endif
#ifndef GLEE_H_DEFINED_glDrawRangeElementArrayAPPLE
#define GLEE_H_DEFINED_glDrawRangeElementArrayAPPLE
  typedef void (APIENTRYP GLEEPFNGLDRAWRANGEELEMENTARRAYAPPLEPROC) (GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
  GLEE_EXTERN GLEEPFNGLDRAWRANGEELEMENTARRAYAPPLEPROC GLeeFuncPtr_glDrawRangeElementArrayAPPLE;
  #define glDrawRangeElementArrayAPPLE GLeeFuncPtr_glDrawRangeElementArrayAPPLE
#endif
#ifndef GLEE_H_DEFINED_glMultiDrawElementArrayAPPLE
#define GLEE_H_DEFINED_glMultiDrawElementArrayAPPLE
  typedef void (APIENTRYP GLEEPFNGLMULTIDRAWELEMENTARRAYAPPLEPROC) (GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLMULTIDRAWELEMENTARRAYAPPLEPROC GLeeFuncPtr_glMultiDrawElementArrayAPPLE;
  #define glMultiDrawElementArrayAPPLE GLeeFuncPtr_glMultiDrawElementArrayAPPLE
#endif
#ifndef GLEE_H_DEFINED_glMultiDrawRangeElementArrayAPPLE
#define GLEE_H_DEFINED_glMultiDrawRangeElementArrayAPPLE
  typedef void (APIENTRYP GLEEPFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC) (GLenum mode, GLuint start, GLuint end, const GLint * first, const GLsizei * count, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC GLeeFuncPtr_glMultiDrawRangeElementArrayAPPLE;
  #define glMultiDrawRangeElementArrayAPPLE GLeeFuncPtr_glMultiDrawRangeElementArrayAPPLE
#endif
#endif

/* GL_APPLE_fence */

#ifndef GL_APPLE_fence
#define GL_APPLE_fence 1
#define __GLEE_GL_APPLE_fence 1
/* Constants */
#define GL_DRAW_PIXELS_APPLE                               0x8A0A
#define GL_FENCE_APPLE                                     0x8A0B
#ifndef GLEE_H_DEFINED_glGenFencesAPPLE
#define GLEE_H_DEFINED_glGenFencesAPPLE
  typedef void (APIENTRYP GLEEPFNGLGENFENCESAPPLEPROC) (GLsizei n, GLuint * fences);
  GLEE_EXTERN GLEEPFNGLGENFENCESAPPLEPROC GLeeFuncPtr_glGenFencesAPPLE;
  #define glGenFencesAPPLE GLeeFuncPtr_glGenFencesAPPLE
#endif
#ifndef GLEE_H_DEFINED_glDeleteFencesAPPLE
#define GLEE_H_DEFINED_glDeleteFencesAPPLE
  typedef void (APIENTRYP GLEEPFNGLDELETEFENCESAPPLEPROC) (GLsizei n, const GLuint * fences);
  GLEE_EXTERN GLEEPFNGLDELETEFENCESAPPLEPROC GLeeFuncPtr_glDeleteFencesAPPLE;
  #define glDeleteFencesAPPLE GLeeFuncPtr_glDeleteFencesAPPLE
#endif
#ifndef GLEE_H_DEFINED_glSetFenceAPPLE
#define GLEE_H_DEFINED_glSetFenceAPPLE
  typedef void (APIENTRYP GLEEPFNGLSETFENCEAPPLEPROC) (GLuint fence);
  GLEE_EXTERN GLEEPFNGLSETFENCEAPPLEPROC GLeeFuncPtr_glSetFenceAPPLE;
  #define glSetFenceAPPLE GLeeFuncPtr_glSetFenceAPPLE
#endif
#ifndef GLEE_H_DEFINED_glIsFenceAPPLE
#define GLEE_H_DEFINED_glIsFenceAPPLE
  typedef GLboolean (APIENTRYP GLEEPFNGLISFENCEAPPLEPROC) (GLuint fence);
  GLEE_EXTERN GLEEPFNGLISFENCEAPPLEPROC GLeeFuncPtr_glIsFenceAPPLE;
  #define glIsFenceAPPLE GLeeFuncPtr_glIsFenceAPPLE
#endif
#ifndef GLEE_H_DEFINED_glTestFenceAPPLE
#define GLEE_H_DEFINED_glTestFenceAPPLE
  typedef GLboolean (APIENTRYP GLEEPFNGLTESTFENCEAPPLEPROC) (GLuint fence);
  GLEE_EXTERN GLEEPFNGLTESTFENCEAPPLEPROC GLeeFuncPtr_glTestFenceAPPLE;
  #define glTestFenceAPPLE GLeeFuncPtr_glTestFenceAPPLE
#endif
#ifndef GLEE_H_DEFINED_glFinishFenceAPPLE
#define GLEE_H_DEFINED_glFinishFenceAPPLE
  typedef void (APIENTRYP GLEEPFNGLFINISHFENCEAPPLEPROC) (GLuint fence);
  GLEE_EXTERN GLEEPFNGLFINISHFENCEAPPLEPROC GLeeFuncPtr_glFinishFenceAPPLE;
  #define glFinishFenceAPPLE GLeeFuncPtr_glFinishFenceAPPLE
#endif
#ifndef GLEE_H_DEFINED_glTestObjectAPPLE
#define GLEE_H_DEFINED_glTestObjectAPPLE
  typedef GLboolean (APIENTRYP GLEEPFNGLTESTOBJECTAPPLEPROC) (GLenum object, GLuint name);
  GLEE_EXTERN GLEEPFNGLTESTOBJECTAPPLEPROC GLeeFuncPtr_glTestObjectAPPLE;
  #define glTestObjectAPPLE GLeeFuncPtr_glTestObjectAPPLE
#endif
#ifndef GLEE_H_DEFINED_glFinishObjectAPPLE
#define GLEE_H_DEFINED_glFinishObjectAPPLE
  typedef void (APIENTRYP GLEEPFNGLFINISHOBJECTAPPLEPROC) (GLenum object, GLint name);
  GLEE_EXTERN GLEEPFNGLFINISHOBJECTAPPLEPROC GLeeFuncPtr_glFinishObjectAPPLE;
  #define glFinishObjectAPPLE GLeeFuncPtr_glFinishObjectAPPLE
#endif
#endif

/* GL_APPLE_vertex_array_object */

#ifndef GL_APPLE_vertex_array_object
#define GL_APPLE_vertex_array_object 1
#define __GLEE_GL_APPLE_vertex_array_object 1
/* Constants */
#define GL_VERTEX_ARRAY_BINDING_APPLE                      0x85B5
#ifndef GLEE_H_DEFINED_glBindVertexArrayAPPLE
#define GLEE_H_DEFINED_glBindVertexArrayAPPLE
  typedef void (APIENTRYP GLEEPFNGLBINDVERTEXARRAYAPPLEPROC) (GLuint array);
  GLEE_EXTERN GLEEPFNGLBINDVERTEXARRAYAPPLEPROC GLeeFuncPtr_glBindVertexArrayAPPLE;
  #define glBindVertexArrayAPPLE GLeeFuncPtr_glBindVertexArrayAPPLE
#endif
#ifndef GLEE_H_DEFINED_glDeleteVertexArraysAPPLE
#define GLEE_H_DEFINED_glDeleteVertexArraysAPPLE
  typedef void (APIENTRYP GLEEPFNGLDELETEVERTEXARRAYSAPPLEPROC) (GLsizei n, const GLuint * arrays);
  GLEE_EXTERN GLEEPFNGLDELETEVERTEXARRAYSAPPLEPROC GLeeFuncPtr_glDeleteVertexArraysAPPLE;
  #define glDeleteVertexArraysAPPLE GLeeFuncPtr_glDeleteVertexArraysAPPLE
#endif
#ifndef GLEE_H_DEFINED_glGenVertexArraysAPPLE
#define GLEE_H_DEFINED_glGenVertexArraysAPPLE
  typedef void (APIENTRYP GLEEPFNGLGENVERTEXARRAYSAPPLEPROC) (GLsizei n, GLuint * arrays);
  GLEE_EXTERN GLEEPFNGLGENVERTEXARRAYSAPPLEPROC GLeeFuncPtr_glGenVertexArraysAPPLE;
  #define glGenVertexArraysAPPLE GLeeFuncPtr_glGenVertexArraysAPPLE
#endif
#ifndef GLEE_H_DEFINED_glIsVertexArrayAPPLE
#define GLEE_H_DEFINED_glIsVertexArrayAPPLE
  typedef GLboolean (APIENTRYP GLEEPFNGLISVERTEXARRAYAPPLEPROC) (GLuint array);
  GLEE_EXTERN GLEEPFNGLISVERTEXARRAYAPPLEPROC GLeeFuncPtr_glIsVertexArrayAPPLE;
  #define glIsVertexArrayAPPLE GLeeFuncPtr_glIsVertexArrayAPPLE
#endif
#endif

/* GL_APPLE_vertex_array_range */

#ifndef GL_APPLE_vertex_array_range
#define GL_APPLE_vertex_array_range 1
#define __GLEE_GL_APPLE_vertex_array_range 1
/* Constants */
#define GL_VERTEX_ARRAY_RANGE_APPLE                        0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE                 0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE                 0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE                0x8521
#define GL_STORAGE_CACHED_APPLE                            0x85BE
#define GL_STORAGE_SHARED_APPLE                            0x85BF
#ifndef GLEE_H_DEFINED_glVertexArrayRangeAPPLE
#define GLEE_H_DEFINED_glVertexArrayRangeAPPLE
  typedef void (APIENTRYP GLEEPFNGLVERTEXARRAYRANGEAPPLEPROC) (GLsizei length, GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXARRAYRANGEAPPLEPROC GLeeFuncPtr_glVertexArrayRangeAPPLE;
  #define glVertexArrayRangeAPPLE GLeeFuncPtr_glVertexArrayRangeAPPLE
#endif
#ifndef GLEE_H_DEFINED_glFlushVertexArrayRangeAPPLE
#define GLEE_H_DEFINED_glFlushVertexArrayRangeAPPLE
  typedef void (APIENTRYP GLEEPFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC) (GLsizei length, GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC GLeeFuncPtr_glFlushVertexArrayRangeAPPLE;
  #define glFlushVertexArrayRangeAPPLE GLeeFuncPtr_glFlushVertexArrayRangeAPPLE
#endif
#ifndef GLEE_H_DEFINED_glVertexArrayParameteriAPPLE
#define GLEE_H_DEFINED_glVertexArrayParameteriAPPLE
  typedef void (APIENTRYP GLEEPFNGLVERTEXARRAYPARAMETERIAPPLEPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLVERTEXARRAYPARAMETERIAPPLEPROC GLeeFuncPtr_glVertexArrayParameteriAPPLE;
  #define glVertexArrayParameteriAPPLE GLeeFuncPtr_glVertexArrayParameteriAPPLE
#endif
#endif

/* GL_APPLE_ycbcr_422 */

#ifndef GL_APPLE_ycbcr_422
#define GL_APPLE_ycbcr_422 1
#define __GLEE_GL_APPLE_ycbcr_422 1
/* Constants */
#define GL_YCBCR_422_APPLE                                 0x85B9
#define GL_UNSIGNED_SHORT_8_8_APPLE                        0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE                    0x85BB
#endif

/* GL_S3_s3tc */

#ifndef GL_S3_s3tc
#define GL_S3_s3tc 1
#define __GLEE_GL_S3_s3tc 1
/* Constants */
#define GL_RGB_S3TC                                        0x83A0
#define GL_RGB4_S3TC                                       0x83A1
#define GL_RGBA_S3TC                                       0x83A2
#define GL_RGBA4_S3TC                                      0x83A3
#endif

/* GL_ATI_draw_buffers */

#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1
#define __GLEE_GL_ATI_draw_buffers 1
/* Constants */
#define GL_MAX_DRAW_BUFFERS_ATI                            0x8824
#define GL_DRAW_BUFFER0_ATI                                0x8825
#define GL_DRAW_BUFFER1_ATI                                0x8826
#define GL_DRAW_BUFFER2_ATI                                0x8827
#define GL_DRAW_BUFFER3_ATI                                0x8828
#define GL_DRAW_BUFFER4_ATI                                0x8829
#define GL_DRAW_BUFFER5_ATI                                0x882A
#define GL_DRAW_BUFFER6_ATI                                0x882B
#define GL_DRAW_BUFFER7_ATI                                0x882C
#define GL_DRAW_BUFFER8_ATI                                0x882D
#define GL_DRAW_BUFFER9_ATI                                0x882E
#define GL_DRAW_BUFFER10_ATI                               0x882F
#define GL_DRAW_BUFFER11_ATI                               0x8830
#define GL_DRAW_BUFFER12_ATI                               0x8831
#define GL_DRAW_BUFFER13_ATI                               0x8832
#define GL_DRAW_BUFFER14_ATI                               0x8833
#define GL_DRAW_BUFFER15_ATI                               0x8834
#ifndef GLEE_H_DEFINED_glDrawBuffersATI
#define GLEE_H_DEFINED_glDrawBuffersATI
  typedef void (APIENTRYP GLEEPFNGLDRAWBUFFERSATIPROC) (GLsizei n, const GLenum * bufs);
  GLEE_EXTERN GLEEPFNGLDRAWBUFFERSATIPROC GLeeFuncPtr_glDrawBuffersATI;
  #define glDrawBuffersATI GLeeFuncPtr_glDrawBuffersATI
#endif
#endif

/* GL_ATI_pixel_format_float */

#ifndef GL_ATI_pixel_format_float
#define GL_ATI_pixel_format_float 1
#define __GLEE_GL_ATI_pixel_format_float 1
/* Constants */
#define GL_TYPE_RGBA_FLOAT_ATI                             0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI                 0x8835
#endif

/* GL_ATI_texture_env_combine3 */

#ifndef GL_ATI_texture_env_combine3
#define GL_ATI_texture_env_combine3 1
#define __GLEE_GL_ATI_texture_env_combine3 1
/* Constants */
#define GL_MODULATE_ADD_ATI                                0x8744
#define GL_MODULATE_SIGNED_ADD_ATI                         0x8745
#define GL_MODULATE_SUBTRACT_ATI                           0x8746
#endif

/* GL_ATI_texture_float */

#ifndef GL_ATI_texture_float
#define GL_ATI_texture_float 1
#define __GLEE_GL_ATI_texture_float 1
/* Constants */
#define GL_RGBA_FLOAT32_ATI                                0x8814
#define GL_RGB_FLOAT32_ATI                                 0x8815
#define GL_ALPHA_FLOAT32_ATI                               0x8816
#define GL_INTENSITY_FLOAT32_ATI                           0x8817
#define GL_LUMINANCE_FLOAT32_ATI                           0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI                     0x8819
#define GL_RGBA_FLOAT16_ATI                                0x881A
#define GL_RGB_FLOAT16_ATI                                 0x881B
#define GL_ALPHA_FLOAT16_ATI                               0x881C
#define GL_INTENSITY_FLOAT16_ATI                           0x881D
#define GL_LUMINANCE_FLOAT16_ATI                           0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI                     0x881F
#endif

/* GL_NV_float_buffer */

#ifndef GL_NV_float_buffer
#define GL_NV_float_buffer 1
#define __GLEE_GL_NV_float_buffer 1
/* Constants */
#define GL_FLOAT_R_NV                                      0x8880
#define GL_FLOAT_RG_NV                                     0x8881
#define GL_FLOAT_RGB_NV                                    0x8882
#define GL_FLOAT_RGBA_NV                                   0x8883
#define GL_FLOAT_R16_NV                                    0x8884
#define GL_FLOAT_R32_NV                                    0x8885
#define GL_FLOAT_RG16_NV                                   0x8886
#define GL_FLOAT_RG32_NV                                   0x8887
#define GL_FLOAT_RGB16_NV                                  0x8888
#define GL_FLOAT_RGB32_NV                                  0x8889
#define GL_FLOAT_RGBA16_NV                                 0x888A
#define GL_FLOAT_RGBA32_NV                                 0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV                     0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV                      0x888D
#define GL_FLOAT_RGBA_MODE_NV                              0x888E
#endif

/* GL_NV_fragment_program */

#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1
#define __GLEE_GL_NV_fragment_program 1
/* Constants */
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV        0x8868
#define GL_FRAGMENT_PROGRAM_NV                             0x8870
#define GL_MAX_TEXTURE_COORDS_NV                           0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV                      0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV                     0x8873
#define GL_PROGRAM_ERROR_STRING_NV                         0x8874
#ifndef GLEE_H_DEFINED_glProgramNamedParameter4fNV
#define GLEE_H_DEFINED_glProgramNamedParameter4fNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMNAMEDPARAMETER4FNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLPROGRAMNAMEDPARAMETER4FNVPROC GLeeFuncPtr_glProgramNamedParameter4fNV;
  #define glProgramNamedParameter4fNV GLeeFuncPtr_glProgramNamedParameter4fNV
#endif
#ifndef GLEE_H_DEFINED_glProgramNamedParameter4dNV
#define GLEE_H_DEFINED_glProgramNamedParameter4dNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMNAMEDPARAMETER4DNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLPROGRAMNAMEDPARAMETER4DNVPROC GLeeFuncPtr_glProgramNamedParameter4dNV;
  #define glProgramNamedParameter4dNV GLeeFuncPtr_glProgramNamedParameter4dNV
#endif
#ifndef GLEE_H_DEFINED_glProgramNamedParameter4fvNV
#define GLEE_H_DEFINED_glProgramNamedParameter4fvNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMNAMEDPARAMETER4FVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, const GLfloat * v);
  GLEE_EXTERN GLEEPFNGLPROGRAMNAMEDPARAMETER4FVNVPROC GLeeFuncPtr_glProgramNamedParameter4fvNV;
  #define glProgramNamedParameter4fvNV GLeeFuncPtr_glProgramNamedParameter4fvNV
#endif
#ifndef GLEE_H_DEFINED_glProgramNamedParameter4dvNV
#define GLEE_H_DEFINED_glProgramNamedParameter4dvNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMNAMEDPARAMETER4DVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, const GLdouble * v);
  GLEE_EXTERN GLEEPFNGLPROGRAMNAMEDPARAMETER4DVNVPROC GLeeFuncPtr_glProgramNamedParameter4dvNV;
  #define glProgramNamedParameter4dvNV GLeeFuncPtr_glProgramNamedParameter4dvNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramNamedParameterfvNV
#define GLEE_H_DEFINED_glGetProgramNamedParameterfvNV
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC GLeeFuncPtr_glGetProgramNamedParameterfvNV;
  #define glGetProgramNamedParameterfvNV GLeeFuncPtr_glGetProgramNamedParameterfvNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramNamedParameterdvNV
#define GLEE_H_DEFINED_glGetProgramNamedParameterdvNV
  typedef void (APIENTRYP GLEEPFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC GLeeFuncPtr_glGetProgramNamedParameterdvNV;
  #define glGetProgramNamedParameterdvNV GLeeFuncPtr_glGetProgramNamedParameterdvNV
#endif
#endif

/* GL_NV_half_float */

#ifndef GL_NV_half_float
#define GL_NV_half_float 1
#define __GLEE_GL_NV_half_float 1
/* Constants */
#define GL_HALF_FLOAT_NV                                   0x140B
#ifndef GLEE_H_DEFINED_glVertex2hNV
#define GLEE_H_DEFINED_glVertex2hNV
  typedef void (APIENTRYP GLEEPFNGLVERTEX2HNVPROC) (GLhalfNV x, GLhalfNV y);
  GLEE_EXTERN GLEEPFNGLVERTEX2HNVPROC GLeeFuncPtr_glVertex2hNV;
  #define glVertex2hNV GLeeFuncPtr_glVertex2hNV
#endif
#ifndef GLEE_H_DEFINED_glVertex2hvNV
#define GLEE_H_DEFINED_glVertex2hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEX2HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEX2HVNVPROC GLeeFuncPtr_glVertex2hvNV;
  #define glVertex2hvNV GLeeFuncPtr_glVertex2hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertex3hNV
#define GLEE_H_DEFINED_glVertex3hNV
  typedef void (APIENTRYP GLEEPFNGLVERTEX3HNVPROC) (GLhalfNV x, GLhalfNV y, GLhalfNV z);
  GLEE_EXTERN GLEEPFNGLVERTEX3HNVPROC GLeeFuncPtr_glVertex3hNV;
  #define glVertex3hNV GLeeFuncPtr_glVertex3hNV
#endif
#ifndef GLEE_H_DEFINED_glVertex3hvNV
#define GLEE_H_DEFINED_glVertex3hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEX3HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEX3HVNVPROC GLeeFuncPtr_glVertex3hvNV;
  #define glVertex3hvNV GLeeFuncPtr_glVertex3hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertex4hNV
#define GLEE_H_DEFINED_glVertex4hNV
  typedef void (APIENTRYP GLEEPFNGLVERTEX4HNVPROC) (GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
  GLEE_EXTERN GLEEPFNGLVERTEX4HNVPROC GLeeFuncPtr_glVertex4hNV;
  #define glVertex4hNV GLeeFuncPtr_glVertex4hNV
#endif
#ifndef GLEE_H_DEFINED_glVertex4hvNV
#define GLEE_H_DEFINED_glVertex4hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEX4HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEX4HVNVPROC GLeeFuncPtr_glVertex4hvNV;
  #define glVertex4hvNV GLeeFuncPtr_glVertex4hvNV
#endif
#ifndef GLEE_H_DEFINED_glNormal3hNV
#define GLEE_H_DEFINED_glNormal3hNV
  typedef void (APIENTRYP GLEEPFNGLNORMAL3HNVPROC) (GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
  GLEE_EXTERN GLEEPFNGLNORMAL3HNVPROC GLeeFuncPtr_glNormal3hNV;
  #define glNormal3hNV GLeeFuncPtr_glNormal3hNV
#endif
#ifndef GLEE_H_DEFINED_glNormal3hvNV
#define GLEE_H_DEFINED_glNormal3hvNV
  typedef void (APIENTRYP GLEEPFNGLNORMAL3HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLNORMAL3HVNVPROC GLeeFuncPtr_glNormal3hvNV;
  #define glNormal3hvNV GLeeFuncPtr_glNormal3hvNV
#endif
#ifndef GLEE_H_DEFINED_glColor3hNV
#define GLEE_H_DEFINED_glColor3hNV
  typedef void (APIENTRYP GLEEPFNGLCOLOR3HNVPROC) (GLhalfNV red, GLhalfNV green, GLhalfNV blue);
  GLEE_EXTERN GLEEPFNGLCOLOR3HNVPROC GLeeFuncPtr_glColor3hNV;
  #define glColor3hNV GLeeFuncPtr_glColor3hNV
#endif
#ifndef GLEE_H_DEFINED_glColor3hvNV
#define GLEE_H_DEFINED_glColor3hvNV
  typedef void (APIENTRYP GLEEPFNGLCOLOR3HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLCOLOR3HVNVPROC GLeeFuncPtr_glColor3hvNV;
  #define glColor3hvNV GLeeFuncPtr_glColor3hvNV
#endif
#ifndef GLEE_H_DEFINED_glColor4hNV
#define GLEE_H_DEFINED_glColor4hNV
  typedef void (APIENTRYP GLEEPFNGLCOLOR4HNVPROC) (GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
  GLEE_EXTERN GLEEPFNGLCOLOR4HNVPROC GLeeFuncPtr_glColor4hNV;
  #define glColor4hNV GLeeFuncPtr_glColor4hNV
#endif
#ifndef GLEE_H_DEFINED_glColor4hvNV
#define GLEE_H_DEFINED_glColor4hvNV
  typedef void (APIENTRYP GLEEPFNGLCOLOR4HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLCOLOR4HVNVPROC GLeeFuncPtr_glColor4hvNV;
  #define glColor4hvNV GLeeFuncPtr_glColor4hvNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord1hNV
#define GLEE_H_DEFINED_glTexCoord1hNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD1HNVPROC) (GLhalfNV s);
  GLEE_EXTERN GLEEPFNGLTEXCOORD1HNVPROC GLeeFuncPtr_glTexCoord1hNV;
  #define glTexCoord1hNV GLeeFuncPtr_glTexCoord1hNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord1hvNV
#define GLEE_H_DEFINED_glTexCoord1hvNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD1HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD1HVNVPROC GLeeFuncPtr_glTexCoord1hvNV;
  #define glTexCoord1hvNV GLeeFuncPtr_glTexCoord1hvNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2hNV
#define GLEE_H_DEFINED_glTexCoord2hNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2HNVPROC) (GLhalfNV s, GLhalfNV t);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2HNVPROC GLeeFuncPtr_glTexCoord2hNV;
  #define glTexCoord2hNV GLeeFuncPtr_glTexCoord2hNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord2hvNV
#define GLEE_H_DEFINED_glTexCoord2hvNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD2HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD2HVNVPROC GLeeFuncPtr_glTexCoord2hvNV;
  #define glTexCoord2hvNV GLeeFuncPtr_glTexCoord2hvNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord3hNV
#define GLEE_H_DEFINED_glTexCoord3hNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD3HNVPROC) (GLhalfNV s, GLhalfNV t, GLhalfNV r);
  GLEE_EXTERN GLEEPFNGLTEXCOORD3HNVPROC GLeeFuncPtr_glTexCoord3hNV;
  #define glTexCoord3hNV GLeeFuncPtr_glTexCoord3hNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord3hvNV
#define GLEE_H_DEFINED_glTexCoord3hvNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD3HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD3HVNVPROC GLeeFuncPtr_glTexCoord3hvNV;
  #define glTexCoord3hvNV GLeeFuncPtr_glTexCoord3hvNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord4hNV
#define GLEE_H_DEFINED_glTexCoord4hNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD4HNVPROC) (GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
  GLEE_EXTERN GLEEPFNGLTEXCOORD4HNVPROC GLeeFuncPtr_glTexCoord4hNV;
  #define glTexCoord4hNV GLeeFuncPtr_glTexCoord4hNV
#endif
#ifndef GLEE_H_DEFINED_glTexCoord4hvNV
#define GLEE_H_DEFINED_glTexCoord4hvNV
  typedef void (APIENTRYP GLEEPFNGLTEXCOORD4HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLTEXCOORD4HVNVPROC GLeeFuncPtr_glTexCoord4hvNV;
  #define glTexCoord4hvNV GLeeFuncPtr_glTexCoord4hvNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1hNV
#define GLEE_H_DEFINED_glMultiTexCoord1hNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1HNVPROC) (GLenum target, GLhalfNV s);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1HNVPROC GLeeFuncPtr_glMultiTexCoord1hNV;
  #define glMultiTexCoord1hNV GLeeFuncPtr_glMultiTexCoord1hNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord1hvNV
#define GLEE_H_DEFINED_glMultiTexCoord1hvNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD1HVNVPROC) (GLenum target, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD1HVNVPROC GLeeFuncPtr_glMultiTexCoord1hvNV;
  #define glMultiTexCoord1hvNV GLeeFuncPtr_glMultiTexCoord1hvNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2hNV
#define GLEE_H_DEFINED_glMultiTexCoord2hNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2HNVPROC) (GLenum target, GLhalfNV s, GLhalfNV t);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2HNVPROC GLeeFuncPtr_glMultiTexCoord2hNV;
  #define glMultiTexCoord2hNV GLeeFuncPtr_glMultiTexCoord2hNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord2hvNV
#define GLEE_H_DEFINED_glMultiTexCoord2hvNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD2HVNVPROC) (GLenum target, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD2HVNVPROC GLeeFuncPtr_glMultiTexCoord2hvNV;
  #define glMultiTexCoord2hvNV GLeeFuncPtr_glMultiTexCoord2hvNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3hNV
#define GLEE_H_DEFINED_glMultiTexCoord3hNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3HNVPROC) (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3HNVPROC GLeeFuncPtr_glMultiTexCoord3hNV;
  #define glMultiTexCoord3hNV GLeeFuncPtr_glMultiTexCoord3hNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord3hvNV
#define GLEE_H_DEFINED_glMultiTexCoord3hvNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD3HVNVPROC) (GLenum target, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD3HVNVPROC GLeeFuncPtr_glMultiTexCoord3hvNV;
  #define glMultiTexCoord3hvNV GLeeFuncPtr_glMultiTexCoord3hvNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4hNV
#define GLEE_H_DEFINED_glMultiTexCoord4hNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4HNVPROC) (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4HNVPROC GLeeFuncPtr_glMultiTexCoord4hNV;
  #define glMultiTexCoord4hNV GLeeFuncPtr_glMultiTexCoord4hNV
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoord4hvNV
#define GLEE_H_DEFINED_glMultiTexCoord4hvNV
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORD4HVNVPROC) (GLenum target, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORD4HVNVPROC GLeeFuncPtr_glMultiTexCoord4hvNV;
  #define glMultiTexCoord4hvNV GLeeFuncPtr_glMultiTexCoord4hvNV
#endif
#ifndef GLEE_H_DEFINED_glFogCoordhNV
#define GLEE_H_DEFINED_glFogCoordhNV
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDHNVPROC) (GLhalfNV fog);
  GLEE_EXTERN GLEEPFNGLFOGCOORDHNVPROC GLeeFuncPtr_glFogCoordhNV;
  #define glFogCoordhNV GLeeFuncPtr_glFogCoordhNV
#endif
#ifndef GLEE_H_DEFINED_glFogCoordhvNV
#define GLEE_H_DEFINED_glFogCoordhvNV
  typedef void (APIENTRYP GLEEPFNGLFOGCOORDHVNVPROC) (const GLhalfNV * fog);
  GLEE_EXTERN GLEEPFNGLFOGCOORDHVNVPROC GLeeFuncPtr_glFogCoordhvNV;
  #define glFogCoordhvNV GLeeFuncPtr_glFogCoordhvNV
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3hNV
#define GLEE_H_DEFINED_glSecondaryColor3hNV
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3HNVPROC) (GLhalfNV red, GLhalfNV green, GLhalfNV blue);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3HNVPROC GLeeFuncPtr_glSecondaryColor3hNV;
  #define glSecondaryColor3hNV GLeeFuncPtr_glSecondaryColor3hNV
#endif
#ifndef GLEE_H_DEFINED_glSecondaryColor3hvNV
#define GLEE_H_DEFINED_glSecondaryColor3hvNV
  typedef void (APIENTRYP GLEEPFNGLSECONDARYCOLOR3HVNVPROC) (const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLSECONDARYCOLOR3HVNVPROC GLeeFuncPtr_glSecondaryColor3hvNV;
  #define glSecondaryColor3hvNV GLeeFuncPtr_glSecondaryColor3hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexWeighthNV
#define GLEE_H_DEFINED_glVertexWeighthNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXWEIGHTHNVPROC) (GLhalfNV weight);
  GLEE_EXTERN GLEEPFNGLVERTEXWEIGHTHNVPROC GLeeFuncPtr_glVertexWeighthNV;
  #define glVertexWeighthNV GLeeFuncPtr_glVertexWeighthNV
#endif
#ifndef GLEE_H_DEFINED_glVertexWeighthvNV
#define GLEE_H_DEFINED_glVertexWeighthvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXWEIGHTHVNVPROC) (const GLhalfNV * weight);
  GLEE_EXTERN GLEEPFNGLVERTEXWEIGHTHVNVPROC GLeeFuncPtr_glVertexWeighthvNV;
  #define glVertexWeighthvNV GLeeFuncPtr_glVertexWeighthvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1hNV
#define GLEE_H_DEFINED_glVertexAttrib1hNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1HNVPROC) (GLuint index, GLhalfNV x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1HNVPROC GLeeFuncPtr_glVertexAttrib1hNV;
  #define glVertexAttrib1hNV GLeeFuncPtr_glVertexAttrib1hNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib1hvNV
#define GLEE_H_DEFINED_glVertexAttrib1hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB1HVNVPROC) (GLuint index, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB1HVNVPROC GLeeFuncPtr_glVertexAttrib1hvNV;
  #define glVertexAttrib1hvNV GLeeFuncPtr_glVertexAttrib1hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2hNV
#define GLEE_H_DEFINED_glVertexAttrib2hNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2HNVPROC) (GLuint index, GLhalfNV x, GLhalfNV y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2HNVPROC GLeeFuncPtr_glVertexAttrib2hNV;
  #define glVertexAttrib2hNV GLeeFuncPtr_glVertexAttrib2hNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib2hvNV
#define GLEE_H_DEFINED_glVertexAttrib2hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB2HVNVPROC) (GLuint index, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB2HVNVPROC GLeeFuncPtr_glVertexAttrib2hvNV;
  #define glVertexAttrib2hvNV GLeeFuncPtr_glVertexAttrib2hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3hNV
#define GLEE_H_DEFINED_glVertexAttrib3hNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3HNVPROC) (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3HNVPROC GLeeFuncPtr_glVertexAttrib3hNV;
  #define glVertexAttrib3hNV GLeeFuncPtr_glVertexAttrib3hNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib3hvNV
#define GLEE_H_DEFINED_glVertexAttrib3hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB3HVNVPROC) (GLuint index, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB3HVNVPROC GLeeFuncPtr_glVertexAttrib3hvNV;
  #define glVertexAttrib3hvNV GLeeFuncPtr_glVertexAttrib3hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4hNV
#define GLEE_H_DEFINED_glVertexAttrib4hNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4HNVPROC) (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4HNVPROC GLeeFuncPtr_glVertexAttrib4hNV;
  #define glVertexAttrib4hNV GLeeFuncPtr_glVertexAttrib4hNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttrib4hvNV
#define GLEE_H_DEFINED_glVertexAttrib4hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIB4HVNVPROC) (GLuint index, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIB4HVNVPROC GLeeFuncPtr_glVertexAttrib4hvNV;
  #define glVertexAttrib4hvNV GLeeFuncPtr_glVertexAttrib4hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs1hvNV
#define GLEE_H_DEFINED_glVertexAttribs1hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS1HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS1HVNVPROC GLeeFuncPtr_glVertexAttribs1hvNV;
  #define glVertexAttribs1hvNV GLeeFuncPtr_glVertexAttribs1hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs2hvNV
#define GLEE_H_DEFINED_glVertexAttribs2hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS2HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS2HVNVPROC GLeeFuncPtr_glVertexAttribs2hvNV;
  #define glVertexAttribs2hvNV GLeeFuncPtr_glVertexAttribs2hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs3hvNV
#define GLEE_H_DEFINED_glVertexAttribs3hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS3HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS3HVNVPROC GLeeFuncPtr_glVertexAttribs3hvNV;
  #define glVertexAttribs3hvNV GLeeFuncPtr_glVertexAttribs3hvNV
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribs4hvNV
#define GLEE_H_DEFINED_glVertexAttribs4hvNV
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBS4HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBS4HVNVPROC GLeeFuncPtr_glVertexAttribs4hvNV;
  #define glVertexAttribs4hvNV GLeeFuncPtr_glVertexAttribs4hvNV
#endif
#endif

/* GL_NV_pixel_data_range */

#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1
#define __GLEE_GL_NV_pixel_data_range 1
/* Constants */
#define GL_WRITE_PIXEL_DATA_RANGE_NV                       0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV                        0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV                0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV                 0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV               0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV                0x887D
#ifndef GLEE_H_DEFINED_glPixelDataRangeNV
#define GLEE_H_DEFINED_glPixelDataRangeNV
  typedef void (APIENTRYP GLEEPFNGLPIXELDATARANGENVPROC) (GLenum target, GLsizei length, GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLPIXELDATARANGENVPROC GLeeFuncPtr_glPixelDataRangeNV;
  #define glPixelDataRangeNV GLeeFuncPtr_glPixelDataRangeNV
#endif
#ifndef GLEE_H_DEFINED_glFlushPixelDataRangeNV
#define GLEE_H_DEFINED_glFlushPixelDataRangeNV
  typedef void (APIENTRYP GLEEPFNGLFLUSHPIXELDATARANGENVPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLFLUSHPIXELDATARANGENVPROC GLeeFuncPtr_glFlushPixelDataRangeNV;
  #define glFlushPixelDataRangeNV GLeeFuncPtr_glFlushPixelDataRangeNV
#endif
#endif

/* GL_NV_primitive_restart */

#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1
#define __GLEE_GL_NV_primitive_restart 1
/* Constants */
#define GL_PRIMITIVE_RESTART_NV                            0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV                      0x8559
#ifndef GLEE_H_DEFINED_glPrimitiveRestartNV
#define GLEE_H_DEFINED_glPrimitiveRestartNV
  typedef void (APIENTRYP GLEEPFNGLPRIMITIVERESTARTNVPROC) ();
  GLEE_EXTERN GLEEPFNGLPRIMITIVERESTARTNVPROC GLeeFuncPtr_glPrimitiveRestartNV;
  #define glPrimitiveRestartNV GLeeFuncPtr_glPrimitiveRestartNV
#endif
#ifndef GLEE_H_DEFINED_glPrimitiveRestartIndexNV
#define GLEE_H_DEFINED_glPrimitiveRestartIndexNV
  typedef void (APIENTRYP GLEEPFNGLPRIMITIVERESTARTINDEXNVPROC) (GLuint index);
  GLEE_EXTERN GLEEPFNGLPRIMITIVERESTARTINDEXNVPROC GLeeFuncPtr_glPrimitiveRestartIndexNV;
  #define glPrimitiveRestartIndexNV GLeeFuncPtr_glPrimitiveRestartIndexNV
#endif
#endif

/* GL_NV_texture_expand_normal */

#ifndef GL_NV_texture_expand_normal
#define GL_NV_texture_expand_normal 1
#define __GLEE_GL_NV_texture_expand_normal 1
/* Constants */
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV                  0x888F
#endif

/* GL_NV_vertex_program2 */

#ifndef GL_NV_vertex_program2
#define GL_NV_vertex_program2 1
#define __GLEE_GL_NV_vertex_program2 1
/* Constants */
#endif

/* GL_ATI_map_object_buffer */

#ifndef GL_ATI_map_object_buffer
#define GL_ATI_map_object_buffer 1
#define __GLEE_GL_ATI_map_object_buffer 1
/* Constants */
#ifndef GLEE_H_DEFINED_glMapObjectBufferATI
#define GLEE_H_DEFINED_glMapObjectBufferATI
  typedef GLvoid* (APIENTRYP GLEEPFNGLMAPOBJECTBUFFERATIPROC) (GLuint buffer);
  GLEE_EXTERN GLEEPFNGLMAPOBJECTBUFFERATIPROC GLeeFuncPtr_glMapObjectBufferATI;
  #define glMapObjectBufferATI GLeeFuncPtr_glMapObjectBufferATI
#endif
#ifndef GLEE_H_DEFINED_glUnmapObjectBufferATI
#define GLEE_H_DEFINED_glUnmapObjectBufferATI
  typedef void (APIENTRYP GLEEPFNGLUNMAPOBJECTBUFFERATIPROC) (GLuint buffer);
  GLEE_EXTERN GLEEPFNGLUNMAPOBJECTBUFFERATIPROC GLeeFuncPtr_glUnmapObjectBufferATI;
  #define glUnmapObjectBufferATI GLeeFuncPtr_glUnmapObjectBufferATI
#endif
#endif

/* GL_ATI_separate_stencil */

#ifndef GL_ATI_separate_stencil
#define GL_ATI_separate_stencil 1
#define __GLEE_GL_ATI_separate_stencil 1
/* Constants */
#define GL_STENCIL_BACK_FUNC_ATI                           0x8800
#define GL_STENCIL_BACK_FAIL_ATI                           0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI                0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI                0x8803
#ifndef GLEE_H_DEFINED_glStencilOpSeparateATI
#define GLEE_H_DEFINED_glStencilOpSeparateATI
  typedef void (APIENTRYP GLEEPFNGLSTENCILOPSEPARATEATIPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
  GLEE_EXTERN GLEEPFNGLSTENCILOPSEPARATEATIPROC GLeeFuncPtr_glStencilOpSeparateATI;
  #define glStencilOpSeparateATI GLeeFuncPtr_glStencilOpSeparateATI
#endif
#ifndef GLEE_H_DEFINED_glStencilFuncSeparateATI
#define GLEE_H_DEFINED_glStencilFuncSeparateATI
  typedef void (APIENTRYP GLEEPFNGLSTENCILFUNCSEPARATEATIPROC) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
  GLEE_EXTERN GLEEPFNGLSTENCILFUNCSEPARATEATIPROC GLeeFuncPtr_glStencilFuncSeparateATI;
  #define glStencilFuncSeparateATI GLeeFuncPtr_glStencilFuncSeparateATI
#endif
#endif

/* GL_ATI_vertex_attrib_array_object */

#ifndef GL_ATI_vertex_attrib_array_object
#define GL_ATI_vertex_attrib_array_object 1
#define __GLEE_GL_ATI_vertex_attrib_array_object 1
/* Constants */
#ifndef GLEE_H_DEFINED_glVertexAttribArrayObjectATI
#define GLEE_H_DEFINED_glVertexAttribArrayObjectATI
  typedef void (APIENTRYP GLEEPFNGLVERTEXATTRIBARRAYOBJECTATIPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBARRAYOBJECTATIPROC GLeeFuncPtr_glVertexAttribArrayObjectATI;
  #define glVertexAttribArrayObjectATI GLeeFuncPtr_glVertexAttribArrayObjectATI
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribArrayObjectfvATI
#define GLEE_H_DEFINED_glGetVertexAttribArrayObjectfvATI
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC) (GLuint index, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC GLeeFuncPtr_glGetVertexAttribArrayObjectfvATI;
  #define glGetVertexAttribArrayObjectfvATI GLeeFuncPtr_glGetVertexAttribArrayObjectfvATI
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribArrayObjectivATI
#define GLEE_H_DEFINED_glGetVertexAttribArrayObjectivATI
  typedef void (APIENTRYP GLEEPFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC) (GLuint index, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC GLeeFuncPtr_glGetVertexAttribArrayObjectivATI;
  #define glGetVertexAttribArrayObjectivATI GLeeFuncPtr_glGetVertexAttribArrayObjectivATI
#endif
#endif

/* GL_OES_read_format */

#ifndef GL_OES_read_format
#define GL_OES_read_format 1
#define __GLEE_GL_OES_read_format 1
/* Constants */
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES              0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES            0x8B9B
#endif

/* GL_EXT_depth_bounds_test */

#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
#define __GLEE_GL_EXT_depth_bounds_test 1
/* Constants */
#define GL_DEPTH_BOUNDS_TEST_EXT                           0x8890
#define GL_DEPTH_BOUNDS_EXT                                0x8891
#ifndef GLEE_H_DEFINED_glDepthBoundsEXT
#define GLEE_H_DEFINED_glDepthBoundsEXT
  typedef void (APIENTRYP GLEEPFNGLDEPTHBOUNDSEXTPROC) (GLclampd zmin, GLclampd zmax);
  GLEE_EXTERN GLEEPFNGLDEPTHBOUNDSEXTPROC GLeeFuncPtr_glDepthBoundsEXT;
  #define glDepthBoundsEXT GLeeFuncPtr_glDepthBoundsEXT
#endif
#endif

/* GL_EXT_texture_mirror_clamp */

#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp 1
#define __GLEE_GL_EXT_texture_mirror_clamp 1
/* Constants */
#define GL_MIRROR_CLAMP_EXT                                0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT                        0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT                      0x8912
#endif

/* GL_EXT_blend_equation_separate */

#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
#define __GLEE_GL_EXT_blend_equation_separate 1
/* Constants */
#define GL_BLEND_EQUATION_RGB_EXT                          GL_BLEND_EQUATION
#define GL_BLEND_EQUATION_ALPHA_EXT                        0x883D
#ifndef GLEE_H_DEFINED_glBlendEquationSeparateEXT
#define GLEE_H_DEFINED_glBlendEquationSeparateEXT
  typedef void (APIENTRYP GLEEPFNGLBLENDEQUATIONSEPARATEEXTPROC) (GLenum modeRGB, GLenum modeAlpha);
  GLEE_EXTERN GLEEPFNGLBLENDEQUATIONSEPARATEEXTPROC GLeeFuncPtr_glBlendEquationSeparateEXT;
  #define glBlendEquationSeparateEXT GLeeFuncPtr_glBlendEquationSeparateEXT
#endif
#endif

/* GL_MESA_pack_invert */

#ifndef GL_MESA_pack_invert
#define GL_MESA_pack_invert 1
#define __GLEE_GL_MESA_pack_invert 1
/* Constants */
#define GL_PACK_INVERT_MESA                                0x8758
#endif

/* GL_MESA_ycbcr_texture */

#ifndef GL_MESA_ycbcr_texture
#define GL_MESA_ycbcr_texture 1
#define __GLEE_GL_MESA_ycbcr_texture 1
/* Constants */
#define GL_UNSIGNED_SHORT_8_8_MESA                         0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA                     0x85BB
#define GL_YCBCR_MESA                                      0x8757
#endif

/* GL_EXT_pixel_buffer_object */

#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object 1
#define __GLEE_GL_EXT_pixel_buffer_object 1
/* Constants */
#define GL_PIXEL_PACK_BUFFER_EXT                           0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT                         0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT                   0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT                 0x88EF
#endif

/* GL_NV_fragment_program_option */

#ifndef GL_NV_fragment_program_option
#define GL_NV_fragment_program_option 1
#define __GLEE_GL_NV_fragment_program_option 1
/* Constants */
#endif

/* GL_NV_fragment_program2 */

#ifndef GL_NV_fragment_program2
#define GL_NV_fragment_program2 1
#define __GLEE_GL_NV_fragment_program2 1
/* Constants */
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV                0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV                       0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV                         0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV                       0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV                       0x88F8
#endif

/* GL_NV_vertex_program2_option */

#ifndef GL_NV_vertex_program2_option
#define GL_NV_vertex_program2_option 1
#define __GLEE_GL_NV_vertex_program2_option 1
/* Constants */
#endif

/* GL_NV_vertex_program3 */

#ifndef GL_NV_vertex_program3
#define GL_NV_vertex_program3 1
#define __GLEE_GL_NV_vertex_program3 1
/* Constants */
#endif

/* GL_EXT_framebuffer_object */

#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
#define __GLEE_GL_EXT_framebuffer_object 1
/* Constants */
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT               0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT                       0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT                         0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT                        0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT          0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT          0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT        0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT   0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT                        0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT           0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT   0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT           0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT              0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT          0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT          0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                     0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT                       0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT                           0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT                           0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT                           0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT                           0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT                           0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT                           0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT                           0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT                           0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT                           0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT                           0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT                          0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT                          0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT                          0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT                          0x8CED
#define GL_COLOR_ATTACHMENT14_EXT                          0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT                          0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT                            0x8D00
#define GL_STENCIL_ATTACHMENT_EXT                          0x8D20
#define GL_FRAMEBUFFER_EXT                                 0x8D40
#define GL_RENDERBUFFER_EXT                                0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT                          0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT                         0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT                0x8D44
#define GL_STENCIL_INDEX1_EXT                              0x8D46
#define GL_STENCIL_INDEX4_EXT                              0x8D47
#define GL_STENCIL_INDEX8_EXT                              0x8D48
#define GL_STENCIL_INDEX16_EXT                             0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT                       0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT                     0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT                      0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT                     0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT                     0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT                   0x8D55
#ifndef GLEE_H_DEFINED_glIsRenderbufferEXT
#define GLEE_H_DEFINED_glIsRenderbufferEXT
  typedef GLboolean (APIENTRYP GLEEPFNGLISRENDERBUFFEREXTPROC) (GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLISRENDERBUFFEREXTPROC GLeeFuncPtr_glIsRenderbufferEXT;
  #define glIsRenderbufferEXT GLeeFuncPtr_glIsRenderbufferEXT
#endif
#ifndef GLEE_H_DEFINED_glBindRenderbufferEXT
#define GLEE_H_DEFINED_glBindRenderbufferEXT
  typedef void (APIENTRYP GLEEPFNGLBINDRENDERBUFFEREXTPROC) (GLenum target, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLBINDRENDERBUFFEREXTPROC GLeeFuncPtr_glBindRenderbufferEXT;
  #define glBindRenderbufferEXT GLeeFuncPtr_glBindRenderbufferEXT
#endif
#ifndef GLEE_H_DEFINED_glDeleteRenderbuffersEXT
#define GLEE_H_DEFINED_glDeleteRenderbuffersEXT
  typedef void (APIENTRYP GLEEPFNGLDELETERENDERBUFFERSEXTPROC) (GLsizei n, const GLuint * renderbuffers);
  GLEE_EXTERN GLEEPFNGLDELETERENDERBUFFERSEXTPROC GLeeFuncPtr_glDeleteRenderbuffersEXT;
  #define glDeleteRenderbuffersEXT GLeeFuncPtr_glDeleteRenderbuffersEXT
#endif
#ifndef GLEE_H_DEFINED_glGenRenderbuffersEXT
#define GLEE_H_DEFINED_glGenRenderbuffersEXT
  typedef void (APIENTRYP GLEEPFNGLGENRENDERBUFFERSEXTPROC) (GLsizei n, GLuint * renderbuffers);
  GLEE_EXTERN GLEEPFNGLGENRENDERBUFFERSEXTPROC GLeeFuncPtr_glGenRenderbuffersEXT;
  #define glGenRenderbuffersEXT GLeeFuncPtr_glGenRenderbuffersEXT
#endif
#ifndef GLEE_H_DEFINED_glRenderbufferStorageEXT
#define GLEE_H_DEFINED_glRenderbufferStorageEXT
  typedef void (APIENTRYP GLEEPFNGLRENDERBUFFERSTORAGEEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLRENDERBUFFERSTORAGEEXTPROC GLeeFuncPtr_glRenderbufferStorageEXT;
  #define glRenderbufferStorageEXT GLeeFuncPtr_glRenderbufferStorageEXT
#endif
#ifndef GLEE_H_DEFINED_glGetRenderbufferParameterivEXT
#define GLEE_H_DEFINED_glGetRenderbufferParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETRENDERBUFFERPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETRENDERBUFFERPARAMETERIVEXTPROC GLeeFuncPtr_glGetRenderbufferParameterivEXT;
  #define glGetRenderbufferParameterivEXT GLeeFuncPtr_glGetRenderbufferParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glIsFramebufferEXT
#define GLEE_H_DEFINED_glIsFramebufferEXT
  typedef GLboolean (APIENTRYP GLEEPFNGLISFRAMEBUFFEREXTPROC) (GLuint framebuffer);
  GLEE_EXTERN GLEEPFNGLISFRAMEBUFFEREXTPROC GLeeFuncPtr_glIsFramebufferEXT;
  #define glIsFramebufferEXT GLeeFuncPtr_glIsFramebufferEXT
#endif
#ifndef GLEE_H_DEFINED_glBindFramebufferEXT
#define GLEE_H_DEFINED_glBindFramebufferEXT
  typedef void (APIENTRYP GLEEPFNGLBINDFRAMEBUFFEREXTPROC) (GLenum target, GLuint framebuffer);
  GLEE_EXTERN GLEEPFNGLBINDFRAMEBUFFEREXTPROC GLeeFuncPtr_glBindFramebufferEXT;
  #define glBindFramebufferEXT GLeeFuncPtr_glBindFramebufferEXT
#endif
#ifndef GLEE_H_DEFINED_glDeleteFramebuffersEXT
#define GLEE_H_DEFINED_glDeleteFramebuffersEXT
  typedef void (APIENTRYP GLEEPFNGLDELETEFRAMEBUFFERSEXTPROC) (GLsizei n, const GLuint * framebuffers);
  GLEE_EXTERN GLEEPFNGLDELETEFRAMEBUFFERSEXTPROC GLeeFuncPtr_glDeleteFramebuffersEXT;
  #define glDeleteFramebuffersEXT GLeeFuncPtr_glDeleteFramebuffersEXT
#endif
#ifndef GLEE_H_DEFINED_glGenFramebuffersEXT
#define GLEE_H_DEFINED_glGenFramebuffersEXT
  typedef void (APIENTRYP GLEEPFNGLGENFRAMEBUFFERSEXTPROC) (GLsizei n, GLuint * framebuffers);
  GLEE_EXTERN GLEEPFNGLGENFRAMEBUFFERSEXTPROC GLeeFuncPtr_glGenFramebuffersEXT;
  #define glGenFramebuffersEXT GLeeFuncPtr_glGenFramebuffersEXT
#endif
#ifndef GLEE_H_DEFINED_glCheckFramebufferStatusEXT
#define GLEE_H_DEFINED_glCheckFramebufferStatusEXT
  typedef GLenum (APIENTRYP GLEEPFNGLCHECKFRAMEBUFFERSTATUSEXTPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLCHECKFRAMEBUFFERSTATUSEXTPROC GLeeFuncPtr_glCheckFramebufferStatusEXT;
  #define glCheckFramebufferStatusEXT GLeeFuncPtr_glCheckFramebufferStatusEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTexture1DEXT
#define GLEE_H_DEFINED_glFramebufferTexture1DEXT
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURE1DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURE1DEXTPROC GLeeFuncPtr_glFramebufferTexture1DEXT;
  #define glFramebufferTexture1DEXT GLeeFuncPtr_glFramebufferTexture1DEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTexture2DEXT
#define GLEE_H_DEFINED_glFramebufferTexture2DEXT
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURE2DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURE2DEXTPROC GLeeFuncPtr_glFramebufferTexture2DEXT;
  #define glFramebufferTexture2DEXT GLeeFuncPtr_glFramebufferTexture2DEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTexture3DEXT
#define GLEE_H_DEFINED_glFramebufferTexture3DEXT
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURE3DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURE3DEXTPROC GLeeFuncPtr_glFramebufferTexture3DEXT;
  #define glFramebufferTexture3DEXT GLeeFuncPtr_glFramebufferTexture3DEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferRenderbufferEXT
#define GLEE_H_DEFINED_glFramebufferRenderbufferEXT
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERRENDERBUFFEREXTPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERRENDERBUFFEREXTPROC GLeeFuncPtr_glFramebufferRenderbufferEXT;
  #define glFramebufferRenderbufferEXT GLeeFuncPtr_glFramebufferRenderbufferEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFramebufferAttachmentParameterivEXT
#define GLEE_H_DEFINED_glGetFramebufferAttachmentParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLenum target, GLenum attachment, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC GLeeFuncPtr_glGetFramebufferAttachmentParameterivEXT;
  #define glGetFramebufferAttachmentParameterivEXT GLeeFuncPtr_glGetFramebufferAttachmentParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGenerateMipmapEXT
#define GLEE_H_DEFINED_glGenerateMipmapEXT
  typedef void (APIENTRYP GLEEPFNGLGENERATEMIPMAPEXTPROC) (GLenum target);
  GLEE_EXTERN GLEEPFNGLGENERATEMIPMAPEXTPROC GLeeFuncPtr_glGenerateMipmapEXT;
  #define glGenerateMipmapEXT GLeeFuncPtr_glGenerateMipmapEXT
#endif
#endif

/* GL_GREMEDY_string_marker */

#ifndef GL_GREMEDY_string_marker
#define GL_GREMEDY_string_marker 1
#define __GLEE_GL_GREMEDY_string_marker 1
/* Constants */
#ifndef GLEE_H_DEFINED_glStringMarkerGREMEDY
#define GLEE_H_DEFINED_glStringMarkerGREMEDY
  typedef void (APIENTRYP GLEEPFNGLSTRINGMARKERGREMEDYPROC) (GLsizei len, const GLvoid * string);
  GLEE_EXTERN GLEEPFNGLSTRINGMARKERGREMEDYPROC GLeeFuncPtr_glStringMarkerGREMEDY;
  #define glStringMarkerGREMEDY GLeeFuncPtr_glStringMarkerGREMEDY
#endif
#endif

/* GL_EXT_packed_depth_stencil */

#ifndef GL_EXT_packed_depth_stencil
#define GL_EXT_packed_depth_stencil 1
#define __GLEE_GL_EXT_packed_depth_stencil 1
/* Constants */
#define GL_DEPTH_STENCIL_EXT                               0x84F9
#define GL_UNSIGNED_INT_24_8_EXT                           0x84FA
#define GL_DEPTH24_STENCIL8_EXT                            0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT                        0x88F1
#endif

/* GL_EXT_stencil_clear_tag */

#ifndef GL_EXT_stencil_clear_tag
#define GL_EXT_stencil_clear_tag 1
#define __GLEE_GL_EXT_stencil_clear_tag 1
/* Constants */
#define GL_STENCIL_TAG_BITS_EXT                            0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT                     0x88F3
#ifndef GLEE_H_DEFINED_glStencilClearTagEXT
#define GLEE_H_DEFINED_glStencilClearTagEXT
  typedef void (APIENTRYP GLEEPFNGLSTENCILCLEARTAGEXTPROC) (GLsizei stencilTagBits, GLuint stencilClearTag);
  GLEE_EXTERN GLEEPFNGLSTENCILCLEARTAGEXTPROC GLeeFuncPtr_glStencilClearTagEXT;
  #define glStencilClearTagEXT GLeeFuncPtr_glStencilClearTagEXT
#endif
#endif

/* GL_EXT_texture_sRGB */

#ifndef GL_EXT_texture_sRGB
#define GL_EXT_texture_sRGB 1
#define __GLEE_GL_EXT_texture_sRGB 1
/* Constants */
#define GL_SRGB_EXT                                        0x8C40
#define GL_SRGB8_EXT                                       0x8C41
#define GL_SRGB_ALPHA_EXT                                  0x8C42
#define GL_SRGB8_ALPHA8_EXT                                0x8C43
#define GL_SLUMINANCE_ALPHA_EXT                            0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT                          0x8C45
#define GL_SLUMINANCE_EXT                                  0x8C46
#define GL_SLUMINANCE8_EXT                                 0x8C47
#define GL_COMPRESSED_SRGB_EXT                             0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT                       0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT                       0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT                 0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT                   0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT             0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT             0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT             0x8C4F
#endif

/* GL_EXT_framebuffer_blit */

#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
#define __GLEE_GL_EXT_framebuffer_blit 1
/* Constants */
#define GL_READ_FRAMEBUFFER_EXT                            0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT                            0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT                    GL_FRAMEBUFFER_BINDING_EXT
#define GL_READ_FRAMEBUFFER_BINDING_EXT                    0x8CAA
#ifndef GLEE_H_DEFINED_glBlitFramebufferEXT
#define GLEE_H_DEFINED_glBlitFramebufferEXT
  typedef void (APIENTRYP GLEEPFNGLBLITFRAMEBUFFEREXTPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
  GLEE_EXTERN GLEEPFNGLBLITFRAMEBUFFEREXTPROC GLeeFuncPtr_glBlitFramebufferEXT;
  #define glBlitFramebufferEXT GLeeFuncPtr_glBlitFramebufferEXT
#endif
#endif

/* GL_EXT_framebuffer_multisample */

#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
#define __GLEE_GL_EXT_framebuffer_multisample 1
/* Constants */
#define GL_RENDERBUFFER_SAMPLES_EXT                        0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT          0x8D56
#define GL_MAX_SAMPLES_EXT                                 0x8D57
#ifndef GLEE_H_DEFINED_glRenderbufferStorageMultisampleEXT
#define GLEE_H_DEFINED_glRenderbufferStorageMultisampleEXT
  typedef void (APIENTRYP GLEEPFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC GLeeFuncPtr_glRenderbufferStorageMultisampleEXT;
  #define glRenderbufferStorageMultisampleEXT GLeeFuncPtr_glRenderbufferStorageMultisampleEXT
#endif
#endif

/* GL_MESAX_texture_stack */

#ifndef GL_MESAX_texture_stack
#define GL_MESAX_texture_stack 1
#define __GLEE_GL_MESAX_texture_stack 1
/* Constants */
#define GL_TEXTURE_1D_STACK_MESAX                          0x8759
#define GL_TEXTURE_2D_STACK_MESAX                          0x875A
#define GL_PROXY_TEXTURE_1D_STACK_MESAX                    0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX                    0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX                  0x875D
#define GL_TEXTURE_2D_STACK_BINDING_MESAX                  0x875E
#endif

/* GL_EXT_timer_query */

#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
#define __GLEE_GL_EXT_timer_query 1
/* Constants */
#define GL_TIME_ELAPSED_EXT                                0x88BF
#ifndef GLEE_H_DEFINED_glGetQueryObjecti64vEXT
#define GLEE_H_DEFINED_glGetQueryObjecti64vEXT
  typedef void (APIENTRYP GLEEPFNGLGETQUERYOBJECTI64VEXTPROC) (GLuint id, GLenum pname, GLint64EXT * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYOBJECTI64VEXTPROC GLeeFuncPtr_glGetQueryObjecti64vEXT;
  #define glGetQueryObjecti64vEXT GLeeFuncPtr_glGetQueryObjecti64vEXT
#endif
#ifndef GLEE_H_DEFINED_glGetQueryObjectui64vEXT
#define GLEE_H_DEFINED_glGetQueryObjectui64vEXT
  typedef void (APIENTRYP GLEEPFNGLGETQUERYOBJECTUI64VEXTPROC) (GLuint id, GLenum pname, GLuint64EXT * params);
  GLEE_EXTERN GLEEPFNGLGETQUERYOBJECTUI64VEXTPROC GLeeFuncPtr_glGetQueryObjectui64vEXT;
  #define glGetQueryObjectui64vEXT GLeeFuncPtr_glGetQueryObjectui64vEXT
#endif
#endif

/* GL_EXT_gpu_program_parameters */

#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1
#define __GLEE_GL_EXT_gpu_program_parameters 1
/* Constants */
#ifndef GLEE_H_DEFINED_glProgramEnvParameters4fvEXT
#define GLEE_H_DEFINED_glProgramEnvParameters4fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETERS4FVEXTPROC) (GLenum target, GLuint index, GLsizei count, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETERS4FVEXTPROC GLeeFuncPtr_glProgramEnvParameters4fvEXT;
  #define glProgramEnvParameters4fvEXT GLeeFuncPtr_glProgramEnvParameters4fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameters4fvEXT
#define GLEE_H_DEFINED_glProgramLocalParameters4fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC) (GLenum target, GLuint index, GLsizei count, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC GLeeFuncPtr_glProgramLocalParameters4fvEXT;
  #define glProgramLocalParameters4fvEXT GLeeFuncPtr_glProgramLocalParameters4fvEXT
#endif
#endif

/* GL_APPLE_flush_buffer_range */

#ifndef GL_APPLE_flush_buffer_range
#define GL_APPLE_flush_buffer_range 1
#define __GLEE_GL_APPLE_flush_buffer_range 1
/* Constants */
#define GL_BUFFER_SERIALIZED_MODIFY_APPLE                  0x8A12
#define GL_BUFFER_FLUSHING_UNMAP_APPLE                     0x8A13
#ifndef GLEE_H_DEFINED_glBufferParameteriAPPLE
#define GLEE_H_DEFINED_glBufferParameteriAPPLE
  typedef void (APIENTRYP GLEEPFNGLBUFFERPARAMETERIAPPLEPROC) (GLenum target, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLBUFFERPARAMETERIAPPLEPROC GLeeFuncPtr_glBufferParameteriAPPLE;
  #define glBufferParameteriAPPLE GLeeFuncPtr_glBufferParameteriAPPLE
#endif
#ifndef GLEE_H_DEFINED_glFlushMappedBufferRangeAPPLE
#define GLEE_H_DEFINED_glFlushMappedBufferRangeAPPLE
  typedef void (APIENTRYP GLEEPFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC) (GLenum target, GLintptr offset, GLsizeiptr size);
  GLEE_EXTERN GLEEPFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC GLeeFuncPtr_glFlushMappedBufferRangeAPPLE;
  #define glFlushMappedBufferRangeAPPLE GLeeFuncPtr_glFlushMappedBufferRangeAPPLE
#endif
#endif

/* GL_EXT_gpu_shader4 */

#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
#define __GLEE_GL_EXT_gpu_shader4 1
/* Constants */
#define GL_SAMPLER_1D_ARRAY_EXT                            0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT                            0x8DC1
#define GL_SAMPLER_BUFFER_EXT                              0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT                     0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT                     0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT                         0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT                           0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT                           0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT                           0x8DC8
#define GL_INT_SAMPLER_1D_EXT                              0x8DC9
#define GL_INT_SAMPLER_2D_EXT                              0x8DCA
#define GL_INT_SAMPLER_3D_EXT                              0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT                            0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT                         0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT                        0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT                        0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT                          0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT                     0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT                     0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT                     0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT                   0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT                0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT               0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT               0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT                 0x8DD8
#ifndef GLEE_H_DEFINED_glGetUniformuivEXT
#define GLEE_H_DEFINED_glGetUniformuivEXT
  typedef void (APIENTRYP GLEEPFNGLGETUNIFORMUIVEXTPROC) (GLuint program, GLint location, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMUIVEXTPROC GLeeFuncPtr_glGetUniformuivEXT;
  #define glGetUniformuivEXT GLeeFuncPtr_glGetUniformuivEXT
#endif
#ifndef GLEE_H_DEFINED_glBindFragDataLocationEXT
#define GLEE_H_DEFINED_glBindFragDataLocationEXT
  typedef void (APIENTRYP GLEEPFNGLBINDFRAGDATALOCATIONEXTPROC) (GLuint program, GLuint color, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLBINDFRAGDATALOCATIONEXTPROC GLeeFuncPtr_glBindFragDataLocationEXT;
  #define glBindFragDataLocationEXT GLeeFuncPtr_glBindFragDataLocationEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFragDataLocationEXT
#define GLEE_H_DEFINED_glGetFragDataLocationEXT
  typedef GLint (APIENTRYP GLEEPFNGLGETFRAGDATALOCATIONEXTPROC) (GLuint program, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETFRAGDATALOCATIONEXTPROC GLeeFuncPtr_glGetFragDataLocationEXT;
  #define glGetFragDataLocationEXT GLeeFuncPtr_glGetFragDataLocationEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform1uiEXT
#define GLEE_H_DEFINED_glUniform1uiEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1UIEXTPROC) (GLint location, GLuint v0);
  GLEE_EXTERN GLEEPFNGLUNIFORM1UIEXTPROC GLeeFuncPtr_glUniform1uiEXT;
  #define glUniform1uiEXT GLeeFuncPtr_glUniform1uiEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform2uiEXT
#define GLEE_H_DEFINED_glUniform2uiEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2UIEXTPROC) (GLint location, GLuint v0, GLuint v1);
  GLEE_EXTERN GLEEPFNGLUNIFORM2UIEXTPROC GLeeFuncPtr_glUniform2uiEXT;
  #define glUniform2uiEXT GLeeFuncPtr_glUniform2uiEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform3uiEXT
#define GLEE_H_DEFINED_glUniform3uiEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3UIEXTPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
  GLEE_EXTERN GLEEPFNGLUNIFORM3UIEXTPROC GLeeFuncPtr_glUniform3uiEXT;
  #define glUniform3uiEXT GLeeFuncPtr_glUniform3uiEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform4uiEXT
#define GLEE_H_DEFINED_glUniform4uiEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4UIEXTPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
  GLEE_EXTERN GLEEPFNGLUNIFORM4UIEXTPROC GLeeFuncPtr_glUniform4uiEXT;
  #define glUniform4uiEXT GLeeFuncPtr_glUniform4uiEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform1uivEXT
#define GLEE_H_DEFINED_glUniform1uivEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM1UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM1UIVEXTPROC GLeeFuncPtr_glUniform1uivEXT;
  #define glUniform1uivEXT GLeeFuncPtr_glUniform1uivEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform2uivEXT
#define GLEE_H_DEFINED_glUniform2uivEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM2UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM2UIVEXTPROC GLeeFuncPtr_glUniform2uivEXT;
  #define glUniform2uivEXT GLeeFuncPtr_glUniform2uivEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform3uivEXT
#define GLEE_H_DEFINED_glUniform3uivEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM3UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM3UIVEXTPROC GLeeFuncPtr_glUniform3uivEXT;
  #define glUniform3uivEXT GLeeFuncPtr_glUniform3uivEXT
#endif
#ifndef GLEE_H_DEFINED_glUniform4uivEXT
#define GLEE_H_DEFINED_glUniform4uivEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORM4UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLUNIFORM4UIVEXTPROC GLeeFuncPtr_glUniform4uivEXT;
  #define glUniform4uivEXT GLeeFuncPtr_glUniform4uivEXT
#endif
#endif

/* GL_EXT_draw_instanced */

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
#define __GLEE_GL_EXT_draw_instanced 1
/* Constants */
#ifndef GLEE_H_DEFINED_glDrawArraysInstancedEXT
#define GLEE_H_DEFINED_glDrawArraysInstancedEXT
  typedef void (APIENTRYP GLEEPFNGLDRAWARRAYSINSTANCEDEXTPROC) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLDRAWARRAYSINSTANCEDEXTPROC GLeeFuncPtr_glDrawArraysInstancedEXT;
  #define glDrawArraysInstancedEXT GLeeFuncPtr_glDrawArraysInstancedEXT
#endif
#ifndef GLEE_H_DEFINED_glDrawElementsInstancedEXT
#define GLEE_H_DEFINED_glDrawElementsInstancedEXT
  typedef void (APIENTRYP GLEEPFNGLDRAWELEMENTSINSTANCEDEXTPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount);
  GLEE_EXTERN GLEEPFNGLDRAWELEMENTSINSTANCEDEXTPROC GLeeFuncPtr_glDrawElementsInstancedEXT;
  #define glDrawElementsInstancedEXT GLeeFuncPtr_glDrawElementsInstancedEXT
#endif
#endif

/* GL_EXT_packed_float */

#ifndef GL_EXT_packed_float
#define GL_EXT_packed_float 1
#define __GLEE_GL_EXT_packed_float 1
/* Constants */
#define GL_R11F_G11F_B10F_EXT                              0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT                0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT                      0x8C3C
#endif

/* GL_EXT_texture_array */

#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array 1
#define __GLEE_GL_EXT_texture_array 1
/* Constants */
#define GL_TEXTURE_1D_ARRAY_EXT                            0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT                      0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT                            0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT                      0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT                    0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT                    0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT                    0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT                0x884E
#endif

/* GL_EXT_texture_buffer_object */

#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
#define __GLEE_GL_EXT_texture_buffer_object 1
/* Constants */
#define GL_TEXTURE_BUFFER_EXT                              0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT                     0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT                      0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT           0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT                       0x8C2E
#ifndef GLEE_H_DEFINED_glTexBufferEXT
#define GLEE_H_DEFINED_glTexBufferEXT
  typedef void (APIENTRYP GLEEPFNGLTEXBUFFEREXTPROC) (GLenum target, GLenum internalformat, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLTEXBUFFEREXTPROC GLeeFuncPtr_glTexBufferEXT;
  #define glTexBufferEXT GLeeFuncPtr_glTexBufferEXT
#endif
#endif

/* GL_EXT_texture_compression_latc */

#ifndef GL_EXT_texture_compression_latc
#define GL_EXT_texture_compression_latc 1
#define __GLEE_GL_EXT_texture_compression_latc 1
/* Constants */
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT                  0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT           0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT            0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT     0x8C73
#endif

/* GL_EXT_texture_compression_rgtc */

#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc 1
#define __GLEE_GL_EXT_texture_compression_rgtc 1
/* Constants */
#define GL_COMPRESSED_RED_RGTC1_EXT                        0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT                 0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT                  0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT           0x8DBE
#endif

/* GL_EXT_texture_shared_exponent */

#ifndef GL_EXT_texture_shared_exponent
#define GL_EXT_texture_shared_exponent 1
#define __GLEE_GL_EXT_texture_shared_exponent 1
/* Constants */
#define GL_RGB9_E5_EXT                                     0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT                    0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT                         0x8C3F
#endif

/* GL_NV_depth_buffer_float */

#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
#define __GLEE_GL_NV_depth_buffer_float 1
/* Constants */
#define GL_DEPTH_COMPONENT32F_NV                           0x8DAB
#define GL_DEPTH32F_STENCIL8_NV                            0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV               0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV                      0x8DAF
#ifndef GLEE_H_DEFINED_glDepthRangedNV
#define GLEE_H_DEFINED_glDepthRangedNV
  typedef void (APIENTRYP GLEEPFNGLDEPTHRANGEDNVPROC) (GLdouble zNear, GLdouble zFar);
  GLEE_EXTERN GLEEPFNGLDEPTHRANGEDNVPROC GLeeFuncPtr_glDepthRangedNV;
  #define glDepthRangedNV GLeeFuncPtr_glDepthRangedNV
#endif
#ifndef GLEE_H_DEFINED_glClearDepthdNV
#define GLEE_H_DEFINED_glClearDepthdNV
  typedef void (APIENTRYP GLEEPFNGLCLEARDEPTHDNVPROC) (GLdouble depth);
  GLEE_EXTERN GLEEPFNGLCLEARDEPTHDNVPROC GLeeFuncPtr_glClearDepthdNV;
  #define glClearDepthdNV GLeeFuncPtr_glClearDepthdNV
#endif
#ifndef GLEE_H_DEFINED_glDepthBoundsdNV
#define GLEE_H_DEFINED_glDepthBoundsdNV
  typedef void (APIENTRYP GLEEPFNGLDEPTHBOUNDSDNVPROC) (GLdouble zmin, GLdouble zmax);
  GLEE_EXTERN GLEEPFNGLDEPTHBOUNDSDNVPROC GLeeFuncPtr_glDepthBoundsdNV;
  #define glDepthBoundsdNV GLeeFuncPtr_glDepthBoundsdNV
#endif
#endif

/* GL_NV_framebuffer_multisample_coverage */

#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#define __GLEE_GL_NV_framebuffer_multisample_coverage 1
/* Constants */
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV                0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV                   0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV               0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV                   0x8E12
#ifndef GLEE_H_DEFINED_glRenderbufferStorageMultisampleCoverageNV
#define GLEE_H_DEFINED_glRenderbufferStorageMultisampleCoverageNV
  typedef void (APIENTRYP GLEEPFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC GLeeFuncPtr_glRenderbufferStorageMultisampleCoverageNV;
  #define glRenderbufferStorageMultisampleCoverageNV GLeeFuncPtr_glRenderbufferStorageMultisampleCoverageNV
#endif
#endif

/* GL_EXT_framebuffer_sRGB */

#ifndef GL_EXT_framebuffer_sRGB
#define GL_EXT_framebuffer_sRGB 1
#define __GLEE_GL_EXT_framebuffer_sRGB 1
/* Constants */
#define GL_FRAMEBUFFER_SRGB_EXT                            0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT                    0x8DBA
#endif

/* GL_NV_geometry_shader4 */

#ifndef GL_NV_geometry_shader4
#define GL_NV_geometry_shader4 1
#define __GLEE_GL_NV_geometry_shader4 1
/* Constants */
#endif

/* GL_NV_parameter_buffer_object */

#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1
#define __GLEE_GL_NV_parameter_buffer_object 1
/* Constants */
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV        0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV            0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV              0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV            0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV            0x8DA4
#ifndef GLEE_H_DEFINED_glProgramBufferParametersfvNV
#define GLEE_H_DEFINED_glProgramBufferParametersfvNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMBUFFERPARAMETERSFVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMBUFFERPARAMETERSFVNVPROC GLeeFuncPtr_glProgramBufferParametersfvNV;
  #define glProgramBufferParametersfvNV GLeeFuncPtr_glProgramBufferParametersfvNV
#endif
#ifndef GLEE_H_DEFINED_glProgramBufferParametersIivNV
#define GLEE_H_DEFINED_glProgramBufferParametersIivNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC GLeeFuncPtr_glProgramBufferParametersIivNV;
  #define glProgramBufferParametersIivNV GLeeFuncPtr_glProgramBufferParametersIivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramBufferParametersIuivNV
#define GLEE_H_DEFINED_glProgramBufferParametersIuivNV
  typedef void (APIENTRYP GLEEPFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC GLeeFuncPtr_glProgramBufferParametersIuivNV;
  #define glProgramBufferParametersIuivNV GLeeFuncPtr_glProgramBufferParametersIuivNV
#endif
#endif

/* GL_EXT_draw_buffers2 */

#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
#define __GLEE_GL_EXT_draw_buffers2 1
/* Constants */
#ifndef GLEE_H_DEFINED_glColorMaskIndexedEXT
#define GLEE_H_DEFINED_glColorMaskIndexedEXT
  typedef void (APIENTRYP GLEEPFNGLCOLORMASKINDEXEDEXTPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
  GLEE_EXTERN GLEEPFNGLCOLORMASKINDEXEDEXTPROC GLeeFuncPtr_glColorMaskIndexedEXT;
  #define glColorMaskIndexedEXT GLeeFuncPtr_glColorMaskIndexedEXT
#endif
#ifndef GLEE_H_DEFINED_glGetBooleanIndexedvEXT
#define GLEE_H_DEFINED_glGetBooleanIndexedvEXT
  typedef void (APIENTRYP GLEEPFNGLGETBOOLEANINDEXEDVEXTPROC) (GLenum target, GLuint index, GLboolean * data);
  GLEE_EXTERN GLEEPFNGLGETBOOLEANINDEXEDVEXTPROC GLeeFuncPtr_glGetBooleanIndexedvEXT;
  #define glGetBooleanIndexedvEXT GLeeFuncPtr_glGetBooleanIndexedvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetIntegerIndexedvEXT
#define GLEE_H_DEFINED_glGetIntegerIndexedvEXT
  typedef void (APIENTRYP GLEEPFNGLGETINTEGERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLint * data);
  GLEE_EXTERN GLEEPFNGLGETINTEGERINDEXEDVEXTPROC GLeeFuncPtr_glGetIntegerIndexedvEXT;
  #define glGetIntegerIndexedvEXT GLeeFuncPtr_glGetIntegerIndexedvEXT
#endif
#ifndef GLEE_H_DEFINED_glEnableIndexedEXT
#define GLEE_H_DEFINED_glEnableIndexedEXT
  typedef void (APIENTRYP GLEEPFNGLENABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
  GLEE_EXTERN GLEEPFNGLENABLEINDEXEDEXTPROC GLeeFuncPtr_glEnableIndexedEXT;
  #define glEnableIndexedEXT GLeeFuncPtr_glEnableIndexedEXT
#endif
#ifndef GLEE_H_DEFINED_glDisableIndexedEXT
#define GLEE_H_DEFINED_glDisableIndexedEXT
  typedef void (APIENTRYP GLEEPFNGLDISABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
  GLEE_EXTERN GLEEPFNGLDISABLEINDEXEDEXTPROC GLeeFuncPtr_glDisableIndexedEXT;
  #define glDisableIndexedEXT GLeeFuncPtr_glDisableIndexedEXT
#endif
#ifndef GLEE_H_DEFINED_glIsEnabledIndexedEXT
#define GLEE_H_DEFINED_glIsEnabledIndexedEXT
  typedef GLboolean (APIENTRYP GLEEPFNGLISENABLEDINDEXEDEXTPROC) (GLenum target, GLuint index);
  GLEE_EXTERN GLEEPFNGLISENABLEDINDEXEDEXTPROC GLeeFuncPtr_glIsEnabledIndexedEXT;
  #define glIsEnabledIndexedEXT GLeeFuncPtr_glIsEnabledIndexedEXT
#endif
#endif

/* GL_NV_transform_feedback */

#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1
#define __GLEE_GL_NV_transform_feedback 1
/* Constants */
#define GL_BACK_PRIMARY_COLOR_NV                           0x8C77
#define GL_BACK_SECONDARY_COLOR_NV                         0x8C78
#define GL_TEXTURE_COORD_NV                                0x8C79
#define GL_CLIP_DISTANCE_NV                                0x8C7A
#define GL_VERTEX_ID_NV                                    0x8C7B
#define GL_PRIMITIVE_ID_NV                                 0x8C7C
#define GL_GENERIC_ATTRIB_NV                               0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV                   0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV               0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV   0x8C80
#define GL_ACTIVE_VARYINGS_NV                              0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV                    0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV                  0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV              0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV               0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV                    0x8C86
#define GL_PRIMITIVES_GENERATED_NV                         0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV        0x8C88
#define GL_RASTERIZER_DISCARD_NV                           0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_ATTRIBS_NV   0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV      0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV                          0x8C8C
#define GL_SEPARATE_ATTRIBS_NV                             0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV                    0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV            0x8C8F
#ifndef GLEE_H_DEFINED_glBeginTransformFeedbackNV
#define GLEE_H_DEFINED_glBeginTransformFeedbackNV
  typedef void (APIENTRYP GLEEPFNGLBEGINTRANSFORMFEEDBACKNVPROC) (GLenum primitiveMode);
  GLEE_EXTERN GLEEPFNGLBEGINTRANSFORMFEEDBACKNVPROC GLeeFuncPtr_glBeginTransformFeedbackNV;
  #define glBeginTransformFeedbackNV GLeeFuncPtr_glBeginTransformFeedbackNV
#endif
#ifndef GLEE_H_DEFINED_glEndTransformFeedbackNV
#define GLEE_H_DEFINED_glEndTransformFeedbackNV
  typedef void (APIENTRYP GLEEPFNGLENDTRANSFORMFEEDBACKNVPROC) ();
  GLEE_EXTERN GLEEPFNGLENDTRANSFORMFEEDBACKNVPROC GLeeFuncPtr_glEndTransformFeedbackNV;
  #define glEndTransformFeedbackNV GLeeFuncPtr_glEndTransformFeedbackNV
#endif
#ifndef GLEE_H_DEFINED_glTransformFeedbackAttribsNV
#define GLEE_H_DEFINED_glTransformFeedbackAttribsNV
  typedef void (APIENTRYP GLEEPFNGLTRANSFORMFEEDBACKATTRIBSNVPROC) (GLuint count, const GLint * attribs, GLenum bufferMode);
  GLEE_EXTERN GLEEPFNGLTRANSFORMFEEDBACKATTRIBSNVPROC GLeeFuncPtr_glTransformFeedbackAttribsNV;
  #define glTransformFeedbackAttribsNV GLeeFuncPtr_glTransformFeedbackAttribsNV
#endif
#ifndef GLEE_H_DEFINED_glBindBufferRangeNV
#define GLEE_H_DEFINED_glBindBufferRangeNV
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERRANGENVPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERRANGENVPROC GLeeFuncPtr_glBindBufferRangeNV;
  #define glBindBufferRangeNV GLeeFuncPtr_glBindBufferRangeNV
#endif
#ifndef GLEE_H_DEFINED_glBindBufferOffsetNV
#define GLEE_H_DEFINED_glBindBufferOffsetNV
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFEROFFSETNVPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
  GLEE_EXTERN GLEEPFNGLBINDBUFFEROFFSETNVPROC GLeeFuncPtr_glBindBufferOffsetNV;
  #define glBindBufferOffsetNV GLeeFuncPtr_glBindBufferOffsetNV
#endif
#ifndef GLEE_H_DEFINED_glBindBufferBaseNV
#define GLEE_H_DEFINED_glBindBufferBaseNV
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERBASENVPROC) (GLenum target, GLuint index, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERBASENVPROC GLeeFuncPtr_glBindBufferBaseNV;
  #define glBindBufferBaseNV GLeeFuncPtr_glBindBufferBaseNV
#endif
#ifndef GLEE_H_DEFINED_glTransformFeedbackVaryingsNV
#define GLEE_H_DEFINED_glTransformFeedbackVaryingsNV
  typedef void (APIENTRYP GLEEPFNGLTRANSFORMFEEDBACKVARYINGSNVPROC) (GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode);
  GLEE_EXTERN GLEEPFNGLTRANSFORMFEEDBACKVARYINGSNVPROC GLeeFuncPtr_glTransformFeedbackVaryingsNV;
  #define glTransformFeedbackVaryingsNV GLeeFuncPtr_glTransformFeedbackVaryingsNV
#endif
#ifndef GLEE_H_DEFINED_glActiveVaryingNV
#define GLEE_H_DEFINED_glActiveVaryingNV
  typedef void (APIENTRYP GLEEPFNGLACTIVEVARYINGNVPROC) (GLuint program, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLACTIVEVARYINGNVPROC GLeeFuncPtr_glActiveVaryingNV;
  #define glActiveVaryingNV GLeeFuncPtr_glActiveVaryingNV
#endif
#ifndef GLEE_H_DEFINED_glGetVaryingLocationNV
#define GLEE_H_DEFINED_glGetVaryingLocationNV
  typedef GLint (APIENTRYP GLEEPFNGLGETVARYINGLOCATIONNVPROC) (GLuint program, const GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETVARYINGLOCATIONNVPROC GLeeFuncPtr_glGetVaryingLocationNV;
  #define glGetVaryingLocationNV GLeeFuncPtr_glGetVaryingLocationNV
#endif
#ifndef GLEE_H_DEFINED_glGetActiveVaryingNV
#define GLEE_H_DEFINED_glGetActiveVaryingNV
  typedef void (APIENTRYP GLEEPFNGLGETACTIVEVARYINGNVPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
  GLEE_EXTERN GLEEPFNGLGETACTIVEVARYINGNVPROC GLeeFuncPtr_glGetActiveVaryingNV;
  #define glGetActiveVaryingNV GLeeFuncPtr_glGetActiveVaryingNV
#endif
#ifndef GLEE_H_DEFINED_glGetTransformFeedbackVaryingNV
#define GLEE_H_DEFINED_glGetTransformFeedbackVaryingNV
  typedef void (APIENTRYP GLEEPFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC) (GLuint program, GLuint index, GLint * location);
  GLEE_EXTERN GLEEPFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC GLeeFuncPtr_glGetTransformFeedbackVaryingNV;
  #define glGetTransformFeedbackVaryingNV GLeeFuncPtr_glGetTransformFeedbackVaryingNV
#endif
#endif

/* GL_EXT_bindable_uniform */

#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
#define __GLEE_GL_EXT_bindable_uniform 1
/* Constants */
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT                0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT              0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT              0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT                   0x8DED
#define GL_UNIFORM_BUFFER_EXT                              0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT                      0x8DEF
#ifndef GLEE_H_DEFINED_glUniformBufferEXT
#define GLEE_H_DEFINED_glUniformBufferEXT
  typedef void (APIENTRYP GLEEPFNGLUNIFORMBUFFEREXTPROC) (GLuint program, GLint location, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLUNIFORMBUFFEREXTPROC GLeeFuncPtr_glUniformBufferEXT;
  #define glUniformBufferEXT GLeeFuncPtr_glUniformBufferEXT
#endif
#ifndef GLEE_H_DEFINED_glGetUniformBufferSizeEXT
#define GLEE_H_DEFINED_glGetUniformBufferSizeEXT
  typedef GLint (APIENTRYP GLEEPFNGLGETUNIFORMBUFFERSIZEEXTPROC) (GLuint program, GLint location);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMBUFFERSIZEEXTPROC GLeeFuncPtr_glGetUniformBufferSizeEXT;
  #define glGetUniformBufferSizeEXT GLeeFuncPtr_glGetUniformBufferSizeEXT
#endif
#ifndef GLEE_H_DEFINED_glGetUniformOffsetEXT
#define GLEE_H_DEFINED_glGetUniformOffsetEXT
  typedef GLintptr (APIENTRYP GLEEPFNGLGETUNIFORMOFFSETEXTPROC) (GLuint program, GLint location);
  GLEE_EXTERN GLEEPFNGLGETUNIFORMOFFSETEXTPROC GLeeFuncPtr_glGetUniformOffsetEXT;
  #define glGetUniformOffsetEXT GLeeFuncPtr_glGetUniformOffsetEXT
#endif
#endif

/* GL_EXT_texture_integer */

#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
#define __GLEE_GL_EXT_texture_integer 1
/* Constants */
#define GL_RGBA32UI_EXT                                    0x8D70
#define GL_RGB32UI_EXT                                     0x8D71
#define GL_ALPHA32UI_EXT                                   0x8D72
#define GL_INTENSITY32UI_EXT                               0x8D73
#define GL_LUMINANCE32UI_EXT                               0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT                         0x8D75
#define GL_RGBA16UI_EXT                                    0x8D76
#define GL_RGB16UI_EXT                                     0x8D77
#define GL_ALPHA16UI_EXT                                   0x8D78
#define GL_INTENSITY16UI_EXT                               0x8D79
#define GL_LUMINANCE16UI_EXT                               0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT                         0x8D7B
#define GL_RGBA8UI_EXT                                     0x8D7C
#define GL_RGB8UI_EXT                                      0x8D7D
#define GL_ALPHA8UI_EXT                                    0x8D7E
#define GL_INTENSITY8UI_EXT                                0x8D7F
#define GL_LUMINANCE8UI_EXT                                0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT                          0x8D81
#define GL_RGBA32I_EXT                                     0x8D82
#define GL_RGB32I_EXT                                      0x8D83
#define GL_ALPHA32I_EXT                                    0x8D84
#define GL_INTENSITY32I_EXT                                0x8D85
#define GL_LUMINANCE32I_EXT                                0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT                          0x8D87
#define GL_RGBA16I_EXT                                     0x8D88
#define GL_RGB16I_EXT                                      0x8D89
#define GL_ALPHA16I_EXT                                    0x8D8A
#define GL_INTENSITY16I_EXT                                0x8D8B
#define GL_LUMINANCE16I_EXT                                0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT                          0x8D8D
#define GL_RGBA8I_EXT                                      0x8D8E
#define GL_RGB8I_EXT                                       0x8D8F
#define GL_ALPHA8I_EXT                                     0x8D90
#define GL_INTENSITY8I_EXT                                 0x8D91
#define GL_LUMINANCE8I_EXT                                 0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT                           0x8D93
#define GL_RED_INTEGER_EXT                                 0x8D94
#define GL_GREEN_INTEGER_EXT                               0x8D95
#define GL_BLUE_INTEGER_EXT                                0x8D96
#define GL_ALPHA_INTEGER_EXT                               0x8D97
#define GL_RGB_INTEGER_EXT                                 0x8D98
#define GL_RGBA_INTEGER_EXT                                0x8D99
#define GL_BGR_INTEGER_EXT                                 0x8D9A
#define GL_BGRA_INTEGER_EXT                                0x8D9B
#define GL_LUMINANCE_INTEGER_EXT                           0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT                     0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT                           0x8D9E
#ifndef GLEE_H_DEFINED_glTexParameterIivEXT
#define GLEE_H_DEFINED_glTexParameterIivEXT
  typedef void (APIENTRYP GLEEPFNGLTEXPARAMETERIIVEXTPROC) (GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLTEXPARAMETERIIVEXTPROC GLeeFuncPtr_glTexParameterIivEXT;
  #define glTexParameterIivEXT GLeeFuncPtr_glTexParameterIivEXT
#endif
#ifndef GLEE_H_DEFINED_glTexParameterIuivEXT
#define GLEE_H_DEFINED_glTexParameterIuivEXT
  typedef void (APIENTRYP GLEEPFNGLTEXPARAMETERIUIVEXTPROC) (GLenum target, GLenum pname, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLTEXPARAMETERIUIVEXTPROC GLeeFuncPtr_glTexParameterIuivEXT;
  #define glTexParameterIuivEXT GLeeFuncPtr_glTexParameterIuivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTexParameterIivEXT
#define GLEE_H_DEFINED_glGetTexParameterIivEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXPARAMETERIIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXPARAMETERIIVEXTPROC GLeeFuncPtr_glGetTexParameterIivEXT;
  #define glGetTexParameterIivEXT GLeeFuncPtr_glGetTexParameterIivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTexParameterIuivEXT
#define GLEE_H_DEFINED_glGetTexParameterIuivEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXPARAMETERIUIVEXTPROC) (GLenum target, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXPARAMETERIUIVEXTPROC GLeeFuncPtr_glGetTexParameterIuivEXT;
  #define glGetTexParameterIuivEXT GLeeFuncPtr_glGetTexParameterIuivEXT
#endif
#ifndef GLEE_H_DEFINED_glClearColorIiEXT
#define GLEE_H_DEFINED_glClearColorIiEXT
  typedef void (APIENTRYP GLEEPFNGLCLEARCOLORIIEXTPROC) (GLint red, GLint green, GLint blue, GLint alpha);
  GLEE_EXTERN GLEEPFNGLCLEARCOLORIIEXTPROC GLeeFuncPtr_glClearColorIiEXT;
  #define glClearColorIiEXT GLeeFuncPtr_glClearColorIiEXT
#endif
#ifndef GLEE_H_DEFINED_glClearColorIuiEXT
#define GLEE_H_DEFINED_glClearColorIuiEXT
  typedef void (APIENTRYP GLEEPFNGLCLEARCOLORIUIEXTPROC) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
  GLEE_EXTERN GLEEPFNGLCLEARCOLORIUIEXTPROC GLeeFuncPtr_glClearColorIuiEXT;
  #define glClearColorIuiEXT GLeeFuncPtr_glClearColorIuiEXT
#endif
#endif

/* GL_GREMEDY_frame_terminator */

#ifndef GL_GREMEDY_frame_terminator
#define GL_GREMEDY_frame_terminator 1
#define __GLEE_GL_GREMEDY_frame_terminator 1
/* Constants */
#ifndef GLEE_H_DEFINED_glFrameTerminatorGREMEDY
#define GLEE_H_DEFINED_glFrameTerminatorGREMEDY
  typedef void (APIENTRYP GLEEPFNGLFRAMETERMINATORGREMEDYPROC) ();
  GLEE_EXTERN GLEEPFNGLFRAMETERMINATORGREMEDYPROC GLeeFuncPtr_glFrameTerminatorGREMEDY;
  #define glFrameTerminatorGREMEDY GLeeFuncPtr_glFrameTerminatorGREMEDY
#endif
#endif

/* GL_NV_conditional_render */

#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
#define __GLEE_GL_NV_conditional_render 1
/* Constants */
#define GL_QUERY_WAIT_NV                                   0x8E13
#define GL_QUERY_NO_WAIT_NV                                0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV                         0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV                      0x8E16
#ifndef GLEE_H_DEFINED_glBeginConditionalRenderNV
#define GLEE_H_DEFINED_glBeginConditionalRenderNV
  typedef void (APIENTRYP GLEEPFNGLBEGINCONDITIONALRENDERNVPROC) (GLuint id, GLenum mode);
  GLEE_EXTERN GLEEPFNGLBEGINCONDITIONALRENDERNVPROC GLeeFuncPtr_glBeginConditionalRenderNV;
  #define glBeginConditionalRenderNV GLeeFuncPtr_glBeginConditionalRenderNV
#endif
#ifndef GLEE_H_DEFINED_glEndConditionalRenderNV
#define GLEE_H_DEFINED_glEndConditionalRenderNV
  typedef void (APIENTRYP GLEEPFNGLENDCONDITIONALRENDERNVPROC) ();
  GLEE_EXTERN GLEEPFNGLENDCONDITIONALRENDERNVPROC GLeeFuncPtr_glEndConditionalRenderNV;
  #define glEndConditionalRenderNV GLeeFuncPtr_glEndConditionalRenderNV
#endif
#endif

/* GL_NV_present_video */

#ifndef GL_NV_present_video
#define GL_NV_present_video 1
#define __GLEE_GL_NV_present_video 1
/* Constants */
#define GL_FRAME_NV                                        0x8E26
#define GL_FIELDS_NV                                       0x8E27
#define GL_CURRENT_TIME_NV                                 0x8E28
#define GL_NUM_FILL_STREAMS_NV                             0x8E29
#define GL_PRESENT_TIME_NV                                 0x8E2A
#define GL_PRESENT_DURATION_NV                             0x8E2B
#endif

/* GL_EXT_transform_feedback */

#ifndef GL_EXT_transform_feedback
#define GL_EXT_transform_feedback 1
#define __GLEE_GL_EXT_transform_feedback 1
/* Constants */
#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT                   0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT             0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT              0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT           0x8C8F
#define GL_INTERLEAVED_ATTRIBS_EXT                         0x8C8C
#define GL_SEPARATE_ATTRIBS_EXT                            0x8C8D
#define GL_PRIMITIVES_GENERATED_EXT                        0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT       0x8C88
#define GL_RASTERIZER_DISCARD_EXT                          0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT     0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT  0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT                 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT              0x8C7F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT       0x8C76
#ifndef GLEE_H_DEFINED_glBeginTransformFeedbackEXT
#define GLEE_H_DEFINED_glBeginTransformFeedbackEXT
  typedef void (APIENTRYP GLEEPFNGLBEGINTRANSFORMFEEDBACKEXTPROC) (GLenum primitiveMode);
  GLEE_EXTERN GLEEPFNGLBEGINTRANSFORMFEEDBACKEXTPROC GLeeFuncPtr_glBeginTransformFeedbackEXT;
  #define glBeginTransformFeedbackEXT GLeeFuncPtr_glBeginTransformFeedbackEXT
#endif
#ifndef GLEE_H_DEFINED_glEndTransformFeedbackEXT
#define GLEE_H_DEFINED_glEndTransformFeedbackEXT
  typedef void (APIENTRYP GLEEPFNGLENDTRANSFORMFEEDBACKEXTPROC) ();
  GLEE_EXTERN GLEEPFNGLENDTRANSFORMFEEDBACKEXTPROC GLeeFuncPtr_glEndTransformFeedbackEXT;
  #define glEndTransformFeedbackEXT GLeeFuncPtr_glEndTransformFeedbackEXT
#endif
#ifndef GLEE_H_DEFINED_glBindBufferRangeEXT
#define GLEE_H_DEFINED_glBindBufferRangeEXT
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERRANGEEXTPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERRANGEEXTPROC GLeeFuncPtr_glBindBufferRangeEXT;
  #define glBindBufferRangeEXT GLeeFuncPtr_glBindBufferRangeEXT
#endif
#ifndef GLEE_H_DEFINED_glBindBufferOffsetEXT
#define GLEE_H_DEFINED_glBindBufferOffsetEXT
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFEROFFSETEXTPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
  GLEE_EXTERN GLEEPFNGLBINDBUFFEROFFSETEXTPROC GLeeFuncPtr_glBindBufferOffsetEXT;
  #define glBindBufferOffsetEXT GLeeFuncPtr_glBindBufferOffsetEXT
#endif
#ifndef GLEE_H_DEFINED_glBindBufferBaseEXT
#define GLEE_H_DEFINED_glBindBufferBaseEXT
  typedef void (APIENTRYP GLEEPFNGLBINDBUFFERBASEEXTPROC) (GLenum target, GLuint index, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLBINDBUFFERBASEEXTPROC GLeeFuncPtr_glBindBufferBaseEXT;
  #define glBindBufferBaseEXT GLeeFuncPtr_glBindBufferBaseEXT
#endif
#ifndef GLEE_H_DEFINED_glTransformFeedbackVaryingsEXT
#define GLEE_H_DEFINED_glTransformFeedbackVaryingsEXT
  typedef void (APIENTRYP GLEEPFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC) (GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode);
  GLEE_EXTERN GLEEPFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC GLeeFuncPtr_glTransformFeedbackVaryingsEXT;
  #define glTransformFeedbackVaryingsEXT GLeeFuncPtr_glTransformFeedbackVaryingsEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTransformFeedbackVaryingEXT
#define GLEE_H_DEFINED_glGetTransformFeedbackVaryingEXT
  typedef void (APIENTRYP GLEEPFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC) (GLuint program, GLuint index, GLint * location);
  GLEE_EXTERN GLEEPFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC GLeeFuncPtr_glGetTransformFeedbackVaryingEXT;
  #define glGetTransformFeedbackVaryingEXT GLeeFuncPtr_glGetTransformFeedbackVaryingEXT
#endif
#endif

/* GL_EXT_direct_state_access */

#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
#define __GLEE_GL_EXT_direct_state_access 1
/* Constants */
#define GL_PROGRAM_MATRIX_EXT                              0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT                    0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT                  0x8E2F
#ifndef GLEE_H_DEFINED_glClientAttribDefaultEXT
#define GLEE_H_DEFINED_glClientAttribDefaultEXT
  typedef void (APIENTRYP GLEEPFNGLCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
  GLEE_EXTERN GLEEPFNGLCLIENTATTRIBDEFAULTEXTPROC GLeeFuncPtr_glClientAttribDefaultEXT;
  #define glClientAttribDefaultEXT GLeeFuncPtr_glClientAttribDefaultEXT
#endif
#ifndef GLEE_H_DEFINED_glPushClientAttribDefaultEXT
#define GLEE_H_DEFINED_glPushClientAttribDefaultEXT
  typedef void (APIENTRYP GLEEPFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
  GLEE_EXTERN GLEEPFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC GLeeFuncPtr_glPushClientAttribDefaultEXT;
  #define glPushClientAttribDefaultEXT GLeeFuncPtr_glPushClientAttribDefaultEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixLoadfEXT
#define GLEE_H_DEFINED_glMatrixLoadfEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXLOADFEXTPROC) (GLenum mode, const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLMATRIXLOADFEXTPROC GLeeFuncPtr_glMatrixLoadfEXT;
  #define glMatrixLoadfEXT GLeeFuncPtr_glMatrixLoadfEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixLoaddEXT
#define GLEE_H_DEFINED_glMatrixLoaddEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXLOADDEXTPROC) (GLenum mode, const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLMATRIXLOADDEXTPROC GLeeFuncPtr_glMatrixLoaddEXT;
  #define glMatrixLoaddEXT GLeeFuncPtr_glMatrixLoaddEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixMultfEXT
#define GLEE_H_DEFINED_glMatrixMultfEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXMULTFEXTPROC) (GLenum mode, const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLMATRIXMULTFEXTPROC GLeeFuncPtr_glMatrixMultfEXT;
  #define glMatrixMultfEXT GLeeFuncPtr_glMatrixMultfEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixMultdEXT
#define GLEE_H_DEFINED_glMatrixMultdEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXMULTDEXTPROC) (GLenum mode, const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLMATRIXMULTDEXTPROC GLeeFuncPtr_glMatrixMultdEXT;
  #define glMatrixMultdEXT GLeeFuncPtr_glMatrixMultdEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixLoadIdentityEXT
#define GLEE_H_DEFINED_glMatrixLoadIdentityEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXLOADIDENTITYEXTPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLMATRIXLOADIDENTITYEXTPROC GLeeFuncPtr_glMatrixLoadIdentityEXT;
  #define glMatrixLoadIdentityEXT GLeeFuncPtr_glMatrixLoadIdentityEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixRotatefEXT
#define GLEE_H_DEFINED_glMatrixRotatefEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXROTATEFEXTPROC) (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLMATRIXROTATEFEXTPROC GLeeFuncPtr_glMatrixRotatefEXT;
  #define glMatrixRotatefEXT GLeeFuncPtr_glMatrixRotatefEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixRotatedEXT
#define GLEE_H_DEFINED_glMatrixRotatedEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXROTATEDEXTPROC) (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLMATRIXROTATEDEXTPROC GLeeFuncPtr_glMatrixRotatedEXT;
  #define glMatrixRotatedEXT GLeeFuncPtr_glMatrixRotatedEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixScalefEXT
#define GLEE_H_DEFINED_glMatrixScalefEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXSCALEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLMATRIXSCALEFEXTPROC GLeeFuncPtr_glMatrixScalefEXT;
  #define glMatrixScalefEXT GLeeFuncPtr_glMatrixScalefEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixScaledEXT
#define GLEE_H_DEFINED_glMatrixScaledEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXSCALEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLMATRIXSCALEDEXTPROC GLeeFuncPtr_glMatrixScaledEXT;
  #define glMatrixScaledEXT GLeeFuncPtr_glMatrixScaledEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixTranslatefEXT
#define GLEE_H_DEFINED_glMatrixTranslatefEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXTRANSLATEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
  GLEE_EXTERN GLEEPFNGLMATRIXTRANSLATEFEXTPROC GLeeFuncPtr_glMatrixTranslatefEXT;
  #define glMatrixTranslatefEXT GLeeFuncPtr_glMatrixTranslatefEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixTranslatedEXT
#define GLEE_H_DEFINED_glMatrixTranslatedEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXTRANSLATEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
  GLEE_EXTERN GLEEPFNGLMATRIXTRANSLATEDEXTPROC GLeeFuncPtr_glMatrixTranslatedEXT;
  #define glMatrixTranslatedEXT GLeeFuncPtr_glMatrixTranslatedEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixFrustumEXT
#define GLEE_H_DEFINED_glMatrixFrustumEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXFRUSTUMEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
  GLEE_EXTERN GLEEPFNGLMATRIXFRUSTUMEXTPROC GLeeFuncPtr_glMatrixFrustumEXT;
  #define glMatrixFrustumEXT GLeeFuncPtr_glMatrixFrustumEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixOrthoEXT
#define GLEE_H_DEFINED_glMatrixOrthoEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXORTHOEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
  GLEE_EXTERN GLEEPFNGLMATRIXORTHOEXTPROC GLeeFuncPtr_glMatrixOrthoEXT;
  #define glMatrixOrthoEXT GLeeFuncPtr_glMatrixOrthoEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixPopEXT
#define GLEE_H_DEFINED_glMatrixPopEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXPOPEXTPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLMATRIXPOPEXTPROC GLeeFuncPtr_glMatrixPopEXT;
  #define glMatrixPopEXT GLeeFuncPtr_glMatrixPopEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixPushEXT
#define GLEE_H_DEFINED_glMatrixPushEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXPUSHEXTPROC) (GLenum mode);
  GLEE_EXTERN GLEEPFNGLMATRIXPUSHEXTPROC GLeeFuncPtr_glMatrixPushEXT;
  #define glMatrixPushEXT GLeeFuncPtr_glMatrixPushEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixLoadTransposefEXT
#define GLEE_H_DEFINED_glMatrixLoadTransposefEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXLOADTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLMATRIXLOADTRANSPOSEFEXTPROC GLeeFuncPtr_glMatrixLoadTransposefEXT;
  #define glMatrixLoadTransposefEXT GLeeFuncPtr_glMatrixLoadTransposefEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixLoadTransposedEXT
#define GLEE_H_DEFINED_glMatrixLoadTransposedEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXLOADTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLMATRIXLOADTRANSPOSEDEXTPROC GLeeFuncPtr_glMatrixLoadTransposedEXT;
  #define glMatrixLoadTransposedEXT GLeeFuncPtr_glMatrixLoadTransposedEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixMultTransposefEXT
#define GLEE_H_DEFINED_glMatrixMultTransposefEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXMULTTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat * m);
  GLEE_EXTERN GLEEPFNGLMATRIXMULTTRANSPOSEFEXTPROC GLeeFuncPtr_glMatrixMultTransposefEXT;
  #define glMatrixMultTransposefEXT GLeeFuncPtr_glMatrixMultTransposefEXT
#endif
#ifndef GLEE_H_DEFINED_glMatrixMultTransposedEXT
#define GLEE_H_DEFINED_glMatrixMultTransposedEXT
  typedef void (APIENTRYP GLEEPFNGLMATRIXMULTTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble * m);
  GLEE_EXTERN GLEEPFNGLMATRIXMULTTRANSPOSEDEXTPROC GLeeFuncPtr_glMatrixMultTransposedEXT;
  #define glMatrixMultTransposedEXT GLeeFuncPtr_glMatrixMultTransposedEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureParameterfEXT
#define GLEE_H_DEFINED_glTextureParameterfEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREPARAMETERFEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLTEXTUREPARAMETERFEXTPROC GLeeFuncPtr_glTextureParameterfEXT;
  #define glTextureParameterfEXT GLeeFuncPtr_glTextureParameterfEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureParameterfvEXT
#define GLEE_H_DEFINED_glTextureParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLTEXTUREPARAMETERFVEXTPROC GLeeFuncPtr_glTextureParameterfvEXT;
  #define glTextureParameterfvEXT GLeeFuncPtr_glTextureParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureParameteriEXT
#define GLEE_H_DEFINED_glTextureParameteriEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREPARAMETERIEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLTEXTUREPARAMETERIEXTPROC GLeeFuncPtr_glTextureParameteriEXT;
  #define glTextureParameteriEXT GLeeFuncPtr_glTextureParameteriEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureParameterivEXT
#define GLEE_H_DEFINED_glTextureParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLTEXTUREPARAMETERIVEXTPROC GLeeFuncPtr_glTextureParameterivEXT;
  #define glTextureParameterivEXT GLeeFuncPtr_glTextureParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureImage1DEXT
#define GLEE_H_DEFINED_glTextureImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXTUREIMAGE1DEXTPROC GLeeFuncPtr_glTextureImage1DEXT;
  #define glTextureImage1DEXT GLeeFuncPtr_glTextureImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureImage2DEXT
#define GLEE_H_DEFINED_glTextureImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXTUREIMAGE2DEXTPROC GLeeFuncPtr_glTextureImage2DEXT;
  #define glTextureImage2DEXT GLeeFuncPtr_glTextureImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureSubImage1DEXT
#define GLEE_H_DEFINED_glTextureSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXTURESUBIMAGE1DEXTPROC GLeeFuncPtr_glTextureSubImage1DEXT;
  #define glTextureSubImage1DEXT GLeeFuncPtr_glTextureSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureSubImage2DEXT
#define GLEE_H_DEFINED_glTextureSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXTURESUBIMAGE2DEXTPROC GLeeFuncPtr_glTextureSubImage2DEXT;
  #define glTextureSubImage2DEXT GLeeFuncPtr_glTextureSubImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTextureImage1DEXT
#define GLEE_H_DEFINED_glCopyTextureImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
  GLEE_EXTERN GLEEPFNGLCOPYTEXTUREIMAGE1DEXTPROC GLeeFuncPtr_glCopyTextureImage1DEXT;
  #define glCopyTextureImage1DEXT GLeeFuncPtr_glCopyTextureImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTextureImage2DEXT
#define GLEE_H_DEFINED_glCopyTextureImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
  GLEE_EXTERN GLEEPFNGLCOPYTEXTUREIMAGE2DEXTPROC GLeeFuncPtr_glCopyTextureImage2DEXT;
  #define glCopyTextureImage2DEXT GLeeFuncPtr_glCopyTextureImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTextureSubImage1DEXT
#define GLEE_H_DEFINED_glCopyTextureSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYTEXTURESUBIMAGE1DEXTPROC GLeeFuncPtr_glCopyTextureSubImage1DEXT;
  #define glCopyTextureSubImage1DEXT GLeeFuncPtr_glCopyTextureSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTextureSubImage2DEXT
#define GLEE_H_DEFINED_glCopyTextureSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYTEXTURESUBIMAGE2DEXTPROC GLeeFuncPtr_glCopyTextureSubImage2DEXT;
  #define glCopyTextureSubImage2DEXT GLeeFuncPtr_glCopyTextureSubImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTextureImageEXT
#define GLEE_H_DEFINED_glGetTextureImageEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLGETTEXTUREIMAGEEXTPROC GLeeFuncPtr_glGetTextureImageEXT;
  #define glGetTextureImageEXT GLeeFuncPtr_glGetTextureImageEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTextureParameterfvEXT
#define GLEE_H_DEFINED_glGetTextureParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETTEXTUREPARAMETERFVEXTPROC GLeeFuncPtr_glGetTextureParameterfvEXT;
  #define glGetTextureParameterfvEXT GLeeFuncPtr_glGetTextureParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTextureParameterivEXT
#define GLEE_H_DEFINED_glGetTextureParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXTUREPARAMETERIVEXTPROC GLeeFuncPtr_glGetTextureParameterivEXT;
  #define glGetTextureParameterivEXT GLeeFuncPtr_glGetTextureParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTextureLevelParameterfvEXT
#define GLEE_H_DEFINED_glGetTextureLevelParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXTURELEVELPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETTEXTURELEVELPARAMETERFVEXTPROC GLeeFuncPtr_glGetTextureLevelParameterfvEXT;
  #define glGetTextureLevelParameterfvEXT GLeeFuncPtr_glGetTextureLevelParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTextureLevelParameterivEXT
#define GLEE_H_DEFINED_glGetTextureLevelParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXTURELEVELPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXTURELEVELPARAMETERIVEXTPROC GLeeFuncPtr_glGetTextureLevelParameterivEXT;
  #define glGetTextureLevelParameterivEXT GLeeFuncPtr_glGetTextureLevelParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureImage3DEXT
#define GLEE_H_DEFINED_glTextureImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXTUREIMAGE3DEXTPROC GLeeFuncPtr_glTextureImage3DEXT;
  #define glTextureImage3DEXT GLeeFuncPtr_glTextureImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureSubImage3DEXT
#define GLEE_H_DEFINED_glTextureSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLTEXTURESUBIMAGE3DEXTPROC GLeeFuncPtr_glTextureSubImage3DEXT;
  #define glTextureSubImage3DEXT GLeeFuncPtr_glTextureSubImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyTextureSubImage3DEXT
#define GLEE_H_DEFINED_glCopyTextureSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYTEXTURESUBIMAGE3DEXTPROC GLeeFuncPtr_glCopyTextureSubImage3DEXT;
  #define glCopyTextureSubImage3DEXT GLeeFuncPtr_glCopyTextureSubImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexParameterfEXT
#define GLEE_H_DEFINED_glMultiTexParameterfEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXPARAMETERFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLMULTITEXPARAMETERFEXTPROC GLeeFuncPtr_glMultiTexParameterfEXT;
  #define glMultiTexParameterfEXT GLeeFuncPtr_glMultiTexParameterfEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexParameterfvEXT
#define GLEE_H_DEFINED_glMultiTexParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXPARAMETERFVEXTPROC GLeeFuncPtr_glMultiTexParameterfvEXT;
  #define glMultiTexParameterfvEXT GLeeFuncPtr_glMultiTexParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexParameteriEXT
#define GLEE_H_DEFINED_glMultiTexParameteriEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXPARAMETERIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLMULTITEXPARAMETERIEXTPROC GLeeFuncPtr_glMultiTexParameteriEXT;
  #define glMultiTexParameteriEXT GLeeFuncPtr_glMultiTexParameteriEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexParameterivEXT
#define GLEE_H_DEFINED_glMultiTexParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXPARAMETERIVEXTPROC GLeeFuncPtr_glMultiTexParameterivEXT;
  #define glMultiTexParameterivEXT GLeeFuncPtr_glMultiTexParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexImage1DEXT
#define GLEE_H_DEFINED_glMultiTexImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLMULTITEXIMAGE1DEXTPROC GLeeFuncPtr_glMultiTexImage1DEXT;
  #define glMultiTexImage1DEXT GLeeFuncPtr_glMultiTexImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexImage2DEXT
#define GLEE_H_DEFINED_glMultiTexImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLMULTITEXIMAGE2DEXTPROC GLeeFuncPtr_glMultiTexImage2DEXT;
  #define glMultiTexImage2DEXT GLeeFuncPtr_glMultiTexImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexSubImage1DEXT
#define GLEE_H_DEFINED_glMultiTexSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLMULTITEXSUBIMAGE1DEXTPROC GLeeFuncPtr_glMultiTexSubImage1DEXT;
  #define glMultiTexSubImage1DEXT GLeeFuncPtr_glMultiTexSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexSubImage2DEXT
#define GLEE_H_DEFINED_glMultiTexSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLMULTITEXSUBIMAGE2DEXTPROC GLeeFuncPtr_glMultiTexSubImage2DEXT;
  #define glMultiTexSubImage2DEXT GLeeFuncPtr_glMultiTexSubImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyMultiTexImage1DEXT
#define GLEE_H_DEFINED_glCopyMultiTexImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
  GLEE_EXTERN GLEEPFNGLCOPYMULTITEXIMAGE1DEXTPROC GLeeFuncPtr_glCopyMultiTexImage1DEXT;
  #define glCopyMultiTexImage1DEXT GLeeFuncPtr_glCopyMultiTexImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyMultiTexImage2DEXT
#define GLEE_H_DEFINED_glCopyMultiTexImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
  GLEE_EXTERN GLEEPFNGLCOPYMULTITEXIMAGE2DEXTPROC GLeeFuncPtr_glCopyMultiTexImage2DEXT;
  #define glCopyMultiTexImage2DEXT GLeeFuncPtr_glCopyMultiTexImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyMultiTexSubImage1DEXT
#define GLEE_H_DEFINED_glCopyMultiTexSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
  GLEE_EXTERN GLEEPFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC GLeeFuncPtr_glCopyMultiTexSubImage1DEXT;
  #define glCopyMultiTexSubImage1DEXT GLeeFuncPtr_glCopyMultiTexSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyMultiTexSubImage2DEXT
#define GLEE_H_DEFINED_glCopyMultiTexSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC GLeeFuncPtr_glCopyMultiTexSubImage2DEXT;
  #define glCopyMultiTexSubImage2DEXT GLeeFuncPtr_glCopyMultiTexSubImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexImageEXT
#define GLEE_H_DEFINED_glGetMultiTexImageEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXIMAGEEXTPROC GLeeFuncPtr_glGetMultiTexImageEXT;
  #define glGetMultiTexImageEXT GLeeFuncPtr_glGetMultiTexImageEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexParameterfvEXT
#define GLEE_H_DEFINED_glGetMultiTexParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXPARAMETERFVEXTPROC GLeeFuncPtr_glGetMultiTexParameterfvEXT;
  #define glGetMultiTexParameterfvEXT GLeeFuncPtr_glGetMultiTexParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexParameterivEXT
#define GLEE_H_DEFINED_glGetMultiTexParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXPARAMETERIVEXTPROC GLeeFuncPtr_glGetMultiTexParameterivEXT;
  #define glGetMultiTexParameterivEXT GLeeFuncPtr_glGetMultiTexParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexLevelParameterfvEXT
#define GLEE_H_DEFINED_glGetMultiTexLevelParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC GLeeFuncPtr_glGetMultiTexLevelParameterfvEXT;
  #define glGetMultiTexLevelParameterfvEXT GLeeFuncPtr_glGetMultiTexLevelParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexLevelParameterivEXT
#define GLEE_H_DEFINED_glGetMultiTexLevelParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC GLeeFuncPtr_glGetMultiTexLevelParameterivEXT;
  #define glGetMultiTexLevelParameterivEXT GLeeFuncPtr_glGetMultiTexLevelParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexImage3DEXT
#define GLEE_H_DEFINED_glMultiTexImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLMULTITEXIMAGE3DEXTPROC GLeeFuncPtr_glMultiTexImage3DEXT;
  #define glMultiTexImage3DEXT GLeeFuncPtr_glMultiTexImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexSubImage3DEXT
#define GLEE_H_DEFINED_glMultiTexSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
  GLEE_EXTERN GLEEPFNGLMULTITEXSUBIMAGE3DEXTPROC GLeeFuncPtr_glMultiTexSubImage3DEXT;
  #define glMultiTexSubImage3DEXT GLeeFuncPtr_glMultiTexSubImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glCopyMultiTexSubImage3DEXT
#define GLEE_H_DEFINED_glCopyMultiTexSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC GLeeFuncPtr_glCopyMultiTexSubImage3DEXT;
  #define glCopyMultiTexSubImage3DEXT GLeeFuncPtr_glCopyMultiTexSubImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glBindMultiTextureEXT
#define GLEE_H_DEFINED_glBindMultiTextureEXT
  typedef void (APIENTRYP GLEEPFNGLBINDMULTITEXTUREEXTPROC) (GLenum texunit, GLenum target, GLuint texture);
  GLEE_EXTERN GLEEPFNGLBINDMULTITEXTUREEXTPROC GLeeFuncPtr_glBindMultiTextureEXT;
  #define glBindMultiTextureEXT GLeeFuncPtr_glBindMultiTextureEXT
#endif
#ifndef GLEE_H_DEFINED_glEnableClientStateIndexedEXT
#define GLEE_H_DEFINED_glEnableClientStateIndexedEXT
  typedef void (APIENTRYP GLEEPFNGLENABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
  GLEE_EXTERN GLEEPFNGLENABLECLIENTSTATEINDEXEDEXTPROC GLeeFuncPtr_glEnableClientStateIndexedEXT;
  #define glEnableClientStateIndexedEXT GLeeFuncPtr_glEnableClientStateIndexedEXT
#endif
#ifndef GLEE_H_DEFINED_glDisableClientStateIndexedEXT
#define GLEE_H_DEFINED_glDisableClientStateIndexedEXT
  typedef void (APIENTRYP GLEEPFNGLDISABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
  GLEE_EXTERN GLEEPFNGLDISABLECLIENTSTATEINDEXEDEXTPROC GLeeFuncPtr_glDisableClientStateIndexedEXT;
  #define glDisableClientStateIndexedEXT GLeeFuncPtr_glDisableClientStateIndexedEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexCoordPointerEXT
#define GLEE_H_DEFINED_glMultiTexCoordPointerEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXCOORDPOINTEREXTPROC) (GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLMULTITEXCOORDPOINTEREXTPROC GLeeFuncPtr_glMultiTexCoordPointerEXT;
  #define glMultiTexCoordPointerEXT GLeeFuncPtr_glMultiTexCoordPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexEnvfEXT
#define GLEE_H_DEFINED_glMultiTexEnvfEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXENVFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLMULTITEXENVFEXTPROC GLeeFuncPtr_glMultiTexEnvfEXT;
  #define glMultiTexEnvfEXT GLeeFuncPtr_glMultiTexEnvfEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexEnvfvEXT
#define GLEE_H_DEFINED_glMultiTexEnvfvEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXENVFVEXTPROC GLeeFuncPtr_glMultiTexEnvfvEXT;
  #define glMultiTexEnvfvEXT GLeeFuncPtr_glMultiTexEnvfvEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexEnviEXT
#define GLEE_H_DEFINED_glMultiTexEnviEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXENVIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLMULTITEXENVIEXTPROC GLeeFuncPtr_glMultiTexEnviEXT;
  #define glMultiTexEnviEXT GLeeFuncPtr_glMultiTexEnviEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexEnvivEXT
#define GLEE_H_DEFINED_glMultiTexEnvivEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXENVIVEXTPROC GLeeFuncPtr_glMultiTexEnvivEXT;
  #define glMultiTexEnvivEXT GLeeFuncPtr_glMultiTexEnvivEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexGendEXT
#define GLEE_H_DEFINED_glMultiTexGendEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXGENDEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
  GLEE_EXTERN GLEEPFNGLMULTITEXGENDEXTPROC GLeeFuncPtr_glMultiTexGendEXT;
  #define glMultiTexGendEXT GLeeFuncPtr_glMultiTexGendEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexGendvEXT
#define GLEE_H_DEFINED_glMultiTexGendvEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLdouble * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXGENDVEXTPROC GLeeFuncPtr_glMultiTexGendvEXT;
  #define glMultiTexGendvEXT GLeeFuncPtr_glMultiTexGendvEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexGenfEXT
#define GLEE_H_DEFINED_glMultiTexGenfEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXGENFEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLMULTITEXGENFEXTPROC GLeeFuncPtr_glMultiTexGenfEXT;
  #define glMultiTexGenfEXT GLeeFuncPtr_glMultiTexGenfEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexGenfvEXT
#define GLEE_H_DEFINED_glMultiTexGenfvEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXGENFVEXTPROC GLeeFuncPtr_glMultiTexGenfvEXT;
  #define glMultiTexGenfvEXT GLeeFuncPtr_glMultiTexGenfvEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexGeniEXT
#define GLEE_H_DEFINED_glMultiTexGeniEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXGENIEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLMULTITEXGENIEXTPROC GLeeFuncPtr_glMultiTexGeniEXT;
  #define glMultiTexGeniEXT GLeeFuncPtr_glMultiTexGeniEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexGenivEXT
#define GLEE_H_DEFINED_glMultiTexGenivEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXGENIVEXTPROC GLeeFuncPtr_glMultiTexGenivEXT;
  #define glMultiTexGenivEXT GLeeFuncPtr_glMultiTexGenivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexEnvfvEXT
#define GLEE_H_DEFINED_glGetMultiTexEnvfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXENVFVEXTPROC GLeeFuncPtr_glGetMultiTexEnvfvEXT;
  #define glGetMultiTexEnvfvEXT GLeeFuncPtr_glGetMultiTexEnvfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexEnvivEXT
#define GLEE_H_DEFINED_glGetMultiTexEnvivEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXENVIVEXTPROC GLeeFuncPtr_glGetMultiTexEnvivEXT;
  #define glGetMultiTexEnvivEXT GLeeFuncPtr_glGetMultiTexEnvivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexGendvEXT
#define GLEE_H_DEFINED_glGetMultiTexGendvEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXGENDVEXTPROC GLeeFuncPtr_glGetMultiTexGendvEXT;
  #define glGetMultiTexGendvEXT GLeeFuncPtr_glGetMultiTexGendvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexGenfvEXT
#define GLEE_H_DEFINED_glGetMultiTexGenfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXGENFVEXTPROC GLeeFuncPtr_glGetMultiTexGenfvEXT;
  #define glGetMultiTexGenfvEXT GLeeFuncPtr_glGetMultiTexGenfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexGenivEXT
#define GLEE_H_DEFINED_glGetMultiTexGenivEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXGENIVEXTPROC GLeeFuncPtr_glGetMultiTexGenivEXT;
  #define glGetMultiTexGenivEXT GLeeFuncPtr_glGetMultiTexGenivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFloatIndexedvEXT
#define GLEE_H_DEFINED_glGetFloatIndexedvEXT
  typedef void (APIENTRYP GLEEPFNGLGETFLOATINDEXEDVEXTPROC) (GLenum target, GLuint index, GLfloat * data);
  GLEE_EXTERN GLEEPFNGLGETFLOATINDEXEDVEXTPROC GLeeFuncPtr_glGetFloatIndexedvEXT;
  #define glGetFloatIndexedvEXT GLeeFuncPtr_glGetFloatIndexedvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetDoubleIndexedvEXT
#define GLEE_H_DEFINED_glGetDoubleIndexedvEXT
  typedef void (APIENTRYP GLEEPFNGLGETDOUBLEINDEXEDVEXTPROC) (GLenum target, GLuint index, GLdouble * data);
  GLEE_EXTERN GLEEPFNGLGETDOUBLEINDEXEDVEXTPROC GLeeFuncPtr_glGetDoubleIndexedvEXT;
  #define glGetDoubleIndexedvEXT GLeeFuncPtr_glGetDoubleIndexedvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetPointerIndexedvEXT
#define GLEE_H_DEFINED_glGetPointerIndexedvEXT
  typedef void (APIENTRYP GLEEPFNGLGETPOINTERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLvoid* * data);
  GLEE_EXTERN GLEEPFNGLGETPOINTERINDEXEDVEXTPROC GLeeFuncPtr_glGetPointerIndexedvEXT;
  #define glGetPointerIndexedvEXT GLeeFuncPtr_glGetPointerIndexedvEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedTextureImage3DEXT
#define GLEE_H_DEFINED_glCompressedTextureImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC GLeeFuncPtr_glCompressedTextureImage3DEXT;
  #define glCompressedTextureImage3DEXT GLeeFuncPtr_glCompressedTextureImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedTextureImage2DEXT
#define GLEE_H_DEFINED_glCompressedTextureImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC GLeeFuncPtr_glCompressedTextureImage2DEXT;
  #define glCompressedTextureImage2DEXT GLeeFuncPtr_glCompressedTextureImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedTextureImage1DEXT
#define GLEE_H_DEFINED_glCompressedTextureImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC GLeeFuncPtr_glCompressedTextureImage1DEXT;
  #define glCompressedTextureImage1DEXT GLeeFuncPtr_glCompressedTextureImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedTextureSubImage3DEXT
#define GLEE_H_DEFINED_glCompressedTextureSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC GLeeFuncPtr_glCompressedTextureSubImage3DEXT;
  #define glCompressedTextureSubImage3DEXT GLeeFuncPtr_glCompressedTextureSubImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedTextureSubImage2DEXT
#define GLEE_H_DEFINED_glCompressedTextureSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC GLeeFuncPtr_glCompressedTextureSubImage2DEXT;
  #define glCompressedTextureSubImage2DEXT GLeeFuncPtr_glCompressedTextureSubImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedTextureSubImage1DEXT
#define GLEE_H_DEFINED_glCompressedTextureSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC GLeeFuncPtr_glCompressedTextureSubImage1DEXT;
  #define glCompressedTextureSubImage1DEXT GLeeFuncPtr_glCompressedTextureSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glGetCompressedTextureImageEXT
#define GLEE_H_DEFINED_glGetCompressedTextureImageEXT
  typedef void (APIENTRYP GLEEPFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint lod, GLvoid * img);
  GLEE_EXTERN GLEEPFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC GLeeFuncPtr_glGetCompressedTextureImageEXT;
  #define glGetCompressedTextureImageEXT GLeeFuncPtr_glGetCompressedTextureImageEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedMultiTexImage3DEXT
#define GLEE_H_DEFINED_glCompressedMultiTexImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC GLeeFuncPtr_glCompressedMultiTexImage3DEXT;
  #define glCompressedMultiTexImage3DEXT GLeeFuncPtr_glCompressedMultiTexImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedMultiTexImage2DEXT
#define GLEE_H_DEFINED_glCompressedMultiTexImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC GLeeFuncPtr_glCompressedMultiTexImage2DEXT;
  #define glCompressedMultiTexImage2DEXT GLeeFuncPtr_glCompressedMultiTexImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedMultiTexImage1DEXT
#define GLEE_H_DEFINED_glCompressedMultiTexImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC GLeeFuncPtr_glCompressedMultiTexImage1DEXT;
  #define glCompressedMultiTexImage1DEXT GLeeFuncPtr_glCompressedMultiTexImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedMultiTexSubImage3DEXT
#define GLEE_H_DEFINED_glCompressedMultiTexSubImage3DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC GLeeFuncPtr_glCompressedMultiTexSubImage3DEXT;
  #define glCompressedMultiTexSubImage3DEXT GLeeFuncPtr_glCompressedMultiTexSubImage3DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedMultiTexSubImage2DEXT
#define GLEE_H_DEFINED_glCompressedMultiTexSubImage2DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC GLeeFuncPtr_glCompressedMultiTexSubImage2DEXT;
  #define glCompressedMultiTexSubImage2DEXT GLeeFuncPtr_glCompressedMultiTexSubImage2DEXT
#endif
#ifndef GLEE_H_DEFINED_glCompressedMultiTexSubImage1DEXT
#define GLEE_H_DEFINED_glCompressedMultiTexSubImage1DEXT
  typedef void (APIENTRYP GLEEPFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * bits);
  GLEE_EXTERN GLEEPFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC GLeeFuncPtr_glCompressedMultiTexSubImage1DEXT;
  #define glCompressedMultiTexSubImage1DEXT GLeeFuncPtr_glCompressedMultiTexSubImage1DEXT
#endif
#ifndef GLEE_H_DEFINED_glGetCompressedMultiTexImageEXT
#define GLEE_H_DEFINED_glGetCompressedMultiTexImageEXT
  typedef void (APIENTRYP GLEEPFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint lod, GLvoid * img);
  GLEE_EXTERN GLEEPFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC GLeeFuncPtr_glGetCompressedMultiTexImageEXT;
  #define glGetCompressedMultiTexImageEXT GLeeFuncPtr_glGetCompressedMultiTexImageEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramStringEXT
#define GLEE_H_DEFINED_glNamedProgramStringEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid * string);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMSTRINGEXTPROC GLeeFuncPtr_glNamedProgramStringEXT;
  #define glNamedProgramStringEXT GLeeFuncPtr_glNamedProgramStringEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameter4dEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameter4dEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC GLeeFuncPtr_glNamedProgramLocalParameter4dEXT;
  #define glNamedProgramLocalParameter4dEXT GLeeFuncPtr_glNamedProgramLocalParameter4dEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameter4dvEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameter4dvEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLdouble * params);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC GLeeFuncPtr_glNamedProgramLocalParameter4dvEXT;
  #define glNamedProgramLocalParameter4dvEXT GLeeFuncPtr_glNamedProgramLocalParameter4dvEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameter4fEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameter4fEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC GLeeFuncPtr_glNamedProgramLocalParameter4fEXT;
  #define glNamedProgramLocalParameter4fEXT GLeeFuncPtr_glNamedProgramLocalParameter4fEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameter4fvEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameter4fvEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC GLeeFuncPtr_glNamedProgramLocalParameter4fvEXT;
  #define glNamedProgramLocalParameter4fvEXT GLeeFuncPtr_glNamedProgramLocalParameter4fvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedProgramLocalParameterdvEXT
#define GLEE_H_DEFINED_glGetNamedProgramLocalParameterdvEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC GLeeFuncPtr_glGetNamedProgramLocalParameterdvEXT;
  #define glGetNamedProgramLocalParameterdvEXT GLeeFuncPtr_glGetNamedProgramLocalParameterdvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedProgramLocalParameterfvEXT
#define GLEE_H_DEFINED_glGetNamedProgramLocalParameterfvEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC GLeeFuncPtr_glGetNamedProgramLocalParameterfvEXT;
  #define glGetNamedProgramLocalParameterfvEXT GLeeFuncPtr_glGetNamedProgramLocalParameterfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedProgramivEXT
#define GLEE_H_DEFINED_glGetNamedProgramivEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDPROGRAMIVEXTPROC) (GLuint program, GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDPROGRAMIVEXTPROC GLeeFuncPtr_glGetNamedProgramivEXT;
  #define glGetNamedProgramivEXT GLeeFuncPtr_glGetNamedProgramivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedProgramStringEXT
#define GLEE_H_DEFINED_glGetNamedProgramStringEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum pname, GLvoid * string);
  GLEE_EXTERN GLEEPFNGLGETNAMEDPROGRAMSTRINGEXTPROC GLeeFuncPtr_glGetNamedProgramStringEXT;
  #define glGetNamedProgramStringEXT GLeeFuncPtr_glGetNamedProgramStringEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameters4fvEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameters4fvEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC GLeeFuncPtr_glNamedProgramLocalParameters4fvEXT;
  #define glNamedProgramLocalParameters4fvEXT GLeeFuncPtr_glNamedProgramLocalParameters4fvEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameterI4iEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameterI4iEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC) (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC GLeeFuncPtr_glNamedProgramLocalParameterI4iEXT;
  #define glNamedProgramLocalParameterI4iEXT GLeeFuncPtr_glNamedProgramLocalParameterI4iEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameterI4ivEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameterI4ivEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLint * params);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC GLeeFuncPtr_glNamedProgramLocalParameterI4ivEXT;
  #define glNamedProgramLocalParameterI4ivEXT GLeeFuncPtr_glNamedProgramLocalParameterI4ivEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParametersI4ivEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParametersI4ivEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint * params);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC GLeeFuncPtr_glNamedProgramLocalParametersI4ivEXT;
  #define glNamedProgramLocalParametersI4ivEXT GLeeFuncPtr_glNamedProgramLocalParametersI4ivEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameterI4uiEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameterI4uiEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC GLeeFuncPtr_glNamedProgramLocalParameterI4uiEXT;
  #define glNamedProgramLocalParameterI4uiEXT GLeeFuncPtr_glNamedProgramLocalParameterI4uiEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParameterI4uivEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParameterI4uivEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC GLeeFuncPtr_glNamedProgramLocalParameterI4uivEXT;
  #define glNamedProgramLocalParameterI4uivEXT GLeeFuncPtr_glNamedProgramLocalParameterI4uivEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedProgramLocalParametersI4uivEXT
#define GLEE_H_DEFINED_glNamedProgramLocalParametersI4uivEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC GLeeFuncPtr_glNamedProgramLocalParametersI4uivEXT;
  #define glNamedProgramLocalParametersI4uivEXT GLeeFuncPtr_glNamedProgramLocalParametersI4uivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedProgramLocalParameterIivEXT
#define GLEE_H_DEFINED_glGetNamedProgramLocalParameterIivEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC GLeeFuncPtr_glGetNamedProgramLocalParameterIivEXT;
  #define glGetNamedProgramLocalParameterIivEXT GLeeFuncPtr_glGetNamedProgramLocalParameterIivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedProgramLocalParameterIuivEXT
#define GLEE_H_DEFINED_glGetNamedProgramLocalParameterIuivEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC GLeeFuncPtr_glGetNamedProgramLocalParameterIuivEXT;
  #define glGetNamedProgramLocalParameterIuivEXT GLeeFuncPtr_glGetNamedProgramLocalParameterIuivEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureParameterIivEXT
#define GLEE_H_DEFINED_glTextureParameterIivEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLTEXTUREPARAMETERIIVEXTPROC GLeeFuncPtr_glTextureParameterIivEXT;
  #define glTextureParameterIivEXT GLeeFuncPtr_glTextureParameterIivEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureParameterIuivEXT
#define GLEE_H_DEFINED_glTextureParameterIuivEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLTEXTUREPARAMETERIUIVEXTPROC GLeeFuncPtr_glTextureParameterIuivEXT;
  #define glTextureParameterIuivEXT GLeeFuncPtr_glTextureParameterIuivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTextureParameterIivEXT
#define GLEE_H_DEFINED_glGetTextureParameterIivEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXTUREPARAMETERIIVEXTPROC GLeeFuncPtr_glGetTextureParameterIivEXT;
  #define glGetTextureParameterIivEXT GLeeFuncPtr_glGetTextureParameterIivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetTextureParameterIuivEXT
#define GLEE_H_DEFINED_glGetTextureParameterIuivEXT
  typedef void (APIENTRYP GLEEPFNGLGETTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETTEXTUREPARAMETERIUIVEXTPROC GLeeFuncPtr_glGetTextureParameterIuivEXT;
  #define glGetTextureParameterIuivEXT GLeeFuncPtr_glGetTextureParameterIuivEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexParameterIivEXT
#define GLEE_H_DEFINED_glMultiTexParameterIivEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXPARAMETERIIVEXTPROC GLeeFuncPtr_glMultiTexParameterIivEXT;
  #define glMultiTexParameterIivEXT GLeeFuncPtr_glMultiTexParameterIivEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexParameterIuivEXT
#define GLEE_H_DEFINED_glMultiTexParameterIuivEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLMULTITEXPARAMETERIUIVEXTPROC GLeeFuncPtr_glMultiTexParameterIuivEXT;
  #define glMultiTexParameterIuivEXT GLeeFuncPtr_glMultiTexParameterIuivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexParameterIivEXT
#define GLEE_H_DEFINED_glGetMultiTexParameterIivEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXPARAMETERIIVEXTPROC GLeeFuncPtr_glGetMultiTexParameterIivEXT;
  #define glGetMultiTexParameterIivEXT GLeeFuncPtr_glGetMultiTexParameterIivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetMultiTexParameterIuivEXT
#define GLEE_H_DEFINED_glGetMultiTexParameterIuivEXT
  typedef void (APIENTRYP GLEEPFNGLGETMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETMULTITEXPARAMETERIUIVEXTPROC GLeeFuncPtr_glGetMultiTexParameterIuivEXT;
  #define glGetMultiTexParameterIuivEXT GLeeFuncPtr_glGetMultiTexParameterIuivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform1fEXT
#define GLEE_H_DEFINED_glProgramUniform1fEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM1FEXTPROC) (GLuint program, GLint location, GLfloat v0);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM1FEXTPROC GLeeFuncPtr_glProgramUniform1fEXT;
  #define glProgramUniform1fEXT GLeeFuncPtr_glProgramUniform1fEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform2fEXT
#define GLEE_H_DEFINED_glProgramUniform2fEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM2FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM2FEXTPROC GLeeFuncPtr_glProgramUniform2fEXT;
  #define glProgramUniform2fEXT GLeeFuncPtr_glProgramUniform2fEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform3fEXT
#define GLEE_H_DEFINED_glProgramUniform3fEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM3FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM3FEXTPROC GLeeFuncPtr_glProgramUniform3fEXT;
  #define glProgramUniform3fEXT GLeeFuncPtr_glProgramUniform3fEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform4fEXT
#define GLEE_H_DEFINED_glProgramUniform4fEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM4FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM4FEXTPROC GLeeFuncPtr_glProgramUniform4fEXT;
  #define glProgramUniform4fEXT GLeeFuncPtr_glProgramUniform4fEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform1iEXT
#define GLEE_H_DEFINED_glProgramUniform1iEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM1IEXTPROC) (GLuint program, GLint location, GLint v0);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM1IEXTPROC GLeeFuncPtr_glProgramUniform1iEXT;
  #define glProgramUniform1iEXT GLeeFuncPtr_glProgramUniform1iEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform2iEXT
#define GLEE_H_DEFINED_glProgramUniform2iEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM2IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM2IEXTPROC GLeeFuncPtr_glProgramUniform2iEXT;
  #define glProgramUniform2iEXT GLeeFuncPtr_glProgramUniform2iEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform3iEXT
#define GLEE_H_DEFINED_glProgramUniform3iEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM3IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM3IEXTPROC GLeeFuncPtr_glProgramUniform3iEXT;
  #define glProgramUniform3iEXT GLeeFuncPtr_glProgramUniform3iEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform4iEXT
#define GLEE_H_DEFINED_glProgramUniform4iEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM4IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM4IEXTPROC GLeeFuncPtr_glProgramUniform4iEXT;
  #define glProgramUniform4iEXT GLeeFuncPtr_glProgramUniform4iEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform1fvEXT
#define GLEE_H_DEFINED_glProgramUniform1fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM1FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM1FVEXTPROC GLeeFuncPtr_glProgramUniform1fvEXT;
  #define glProgramUniform1fvEXT GLeeFuncPtr_glProgramUniform1fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform2fvEXT
#define GLEE_H_DEFINED_glProgramUniform2fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM2FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM2FVEXTPROC GLeeFuncPtr_glProgramUniform2fvEXT;
  #define glProgramUniform2fvEXT GLeeFuncPtr_glProgramUniform2fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform3fvEXT
#define GLEE_H_DEFINED_glProgramUniform3fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM3FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM3FVEXTPROC GLeeFuncPtr_glProgramUniform3fvEXT;
  #define glProgramUniform3fvEXT GLeeFuncPtr_glProgramUniform3fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform4fvEXT
#define GLEE_H_DEFINED_glProgramUniform4fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM4FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM4FVEXTPROC GLeeFuncPtr_glProgramUniform4fvEXT;
  #define glProgramUniform4fvEXT GLeeFuncPtr_glProgramUniform4fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform1ivEXT
#define GLEE_H_DEFINED_glProgramUniform1ivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM1IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM1IVEXTPROC GLeeFuncPtr_glProgramUniform1ivEXT;
  #define glProgramUniform1ivEXT GLeeFuncPtr_glProgramUniform1ivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform2ivEXT
#define GLEE_H_DEFINED_glProgramUniform2ivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM2IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM2IVEXTPROC GLeeFuncPtr_glProgramUniform2ivEXT;
  #define glProgramUniform2ivEXT GLeeFuncPtr_glProgramUniform2ivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform3ivEXT
#define GLEE_H_DEFINED_glProgramUniform3ivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM3IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM3IVEXTPROC GLeeFuncPtr_glProgramUniform3ivEXT;
  #define glProgramUniform3ivEXT GLeeFuncPtr_glProgramUniform3ivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform4ivEXT
#define GLEE_H_DEFINED_glProgramUniform4ivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM4IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM4IVEXTPROC GLeeFuncPtr_glProgramUniform4ivEXT;
  #define glProgramUniform4ivEXT GLeeFuncPtr_glProgramUniform4ivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix2fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix2fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix2fvEXT;
  #define glProgramUniformMatrix2fvEXT GLeeFuncPtr_glProgramUniformMatrix2fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix3fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix3fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix3fvEXT;
  #define glProgramUniformMatrix3fvEXT GLeeFuncPtr_glProgramUniformMatrix3fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix4fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix4fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix4fvEXT;
  #define glProgramUniformMatrix4fvEXT GLeeFuncPtr_glProgramUniformMatrix4fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix2x3fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix2x3fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix2x3fvEXT;
  #define glProgramUniformMatrix2x3fvEXT GLeeFuncPtr_glProgramUniformMatrix2x3fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix3x2fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix3x2fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix3x2fvEXT;
  #define glProgramUniformMatrix3x2fvEXT GLeeFuncPtr_glProgramUniformMatrix3x2fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix2x4fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix2x4fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix2x4fvEXT;
  #define glProgramUniformMatrix2x4fvEXT GLeeFuncPtr_glProgramUniformMatrix2x4fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix4x2fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix4x2fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix4x2fvEXT;
  #define glProgramUniformMatrix4x2fvEXT GLeeFuncPtr_glProgramUniformMatrix4x2fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix3x4fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix3x4fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix3x4fvEXT;
  #define glProgramUniformMatrix3x4fvEXT GLeeFuncPtr_glProgramUniformMatrix3x4fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniformMatrix4x3fvEXT
#define GLEE_H_DEFINED_glProgramUniformMatrix4x3fvEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC GLeeFuncPtr_glProgramUniformMatrix4x3fvEXT;
  #define glProgramUniformMatrix4x3fvEXT GLeeFuncPtr_glProgramUniformMatrix4x3fvEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform1uiEXT
#define GLEE_H_DEFINED_glProgramUniform1uiEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM1UIEXTPROC) (GLuint program, GLint location, GLuint v0);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM1UIEXTPROC GLeeFuncPtr_glProgramUniform1uiEXT;
  #define glProgramUniform1uiEXT GLeeFuncPtr_glProgramUniform1uiEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform2uiEXT
#define GLEE_H_DEFINED_glProgramUniform2uiEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM2UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM2UIEXTPROC GLeeFuncPtr_glProgramUniform2uiEXT;
  #define glProgramUniform2uiEXT GLeeFuncPtr_glProgramUniform2uiEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform3uiEXT
#define GLEE_H_DEFINED_glProgramUniform3uiEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM3UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM3UIEXTPROC GLeeFuncPtr_glProgramUniform3uiEXT;
  #define glProgramUniform3uiEXT GLeeFuncPtr_glProgramUniform3uiEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform4uiEXT
#define GLEE_H_DEFINED_glProgramUniform4uiEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM4UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM4UIEXTPROC GLeeFuncPtr_glProgramUniform4uiEXT;
  #define glProgramUniform4uiEXT GLeeFuncPtr_glProgramUniform4uiEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform1uivEXT
#define GLEE_H_DEFINED_glProgramUniform1uivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM1UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM1UIVEXTPROC GLeeFuncPtr_glProgramUniform1uivEXT;
  #define glProgramUniform1uivEXT GLeeFuncPtr_glProgramUniform1uivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform2uivEXT
#define GLEE_H_DEFINED_glProgramUniform2uivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM2UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM2UIVEXTPROC GLeeFuncPtr_glProgramUniform2uivEXT;
  #define glProgramUniform2uivEXT GLeeFuncPtr_glProgramUniform2uivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform3uivEXT
#define GLEE_H_DEFINED_glProgramUniform3uivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM3UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM3UIVEXTPROC GLeeFuncPtr_glProgramUniform3uivEXT;
  #define glProgramUniform3uivEXT GLeeFuncPtr_glProgramUniform3uivEXT
#endif
#ifndef GLEE_H_DEFINED_glProgramUniform4uivEXT
#define GLEE_H_DEFINED_glProgramUniform4uivEXT
  typedef void (APIENTRYP GLEEPFNGLPROGRAMUNIFORM4UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint * value);
  GLEE_EXTERN GLEEPFNGLPROGRAMUNIFORM4UIVEXTPROC GLeeFuncPtr_glProgramUniform4uivEXT;
  #define glProgramUniform4uivEXT GLeeFuncPtr_glProgramUniform4uivEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedBufferDataEXT
#define GLEE_H_DEFINED_glNamedBufferDataEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLsizeiptr size, const GLvoid * data, GLenum usage);
  GLEE_EXTERN GLEEPFNGLNAMEDBUFFERDATAEXTPROC GLeeFuncPtr_glNamedBufferDataEXT;
  #define glNamedBufferDataEXT GLeeFuncPtr_glNamedBufferDataEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedBufferSubDataEXT
#define GLEE_H_DEFINED_glNamedBufferSubDataEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid * data);
  GLEE_EXTERN GLEEPFNGLNAMEDBUFFERSUBDATAEXTPROC GLeeFuncPtr_glNamedBufferSubDataEXT;
  #define glNamedBufferSubDataEXT GLeeFuncPtr_glNamedBufferSubDataEXT
#endif
#ifndef GLEE_H_DEFINED_glMapNamedBufferEXT
#define GLEE_H_DEFINED_glMapNamedBufferEXT
  typedef GLvoid* (APIENTRYP GLEEPFNGLMAPNAMEDBUFFEREXTPROC) (GLuint buffer, GLenum access);
  GLEE_EXTERN GLEEPFNGLMAPNAMEDBUFFEREXTPROC GLeeFuncPtr_glMapNamedBufferEXT;
  #define glMapNamedBufferEXT GLeeFuncPtr_glMapNamedBufferEXT
#endif
#ifndef GLEE_H_DEFINED_glUnmapNamedBufferEXT
#define GLEE_H_DEFINED_glUnmapNamedBufferEXT
  typedef GLboolean (APIENTRYP GLEEPFNGLUNMAPNAMEDBUFFEREXTPROC) (GLuint buffer);
  GLEE_EXTERN GLEEPFNGLUNMAPNAMEDBUFFEREXTPROC GLeeFuncPtr_glUnmapNamedBufferEXT;
  #define glUnmapNamedBufferEXT GLeeFuncPtr_glUnmapNamedBufferEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedBufferParameterivEXT
#define GLEE_H_DEFINED_glGetNamedBufferParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC) (GLuint buffer, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC GLeeFuncPtr_glGetNamedBufferParameterivEXT;
  #define glGetNamedBufferParameterivEXT GLeeFuncPtr_glGetNamedBufferParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedBufferPointervEXT
#define GLEE_H_DEFINED_glGetNamedBufferPointervEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDBUFFERPOINTERVEXTPROC) (GLuint buffer, GLenum pname, GLvoid* * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDBUFFERPOINTERVEXTPROC GLeeFuncPtr_glGetNamedBufferPointervEXT;
  #define glGetNamedBufferPointervEXT GLeeFuncPtr_glGetNamedBufferPointervEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedBufferSubDataEXT
#define GLEE_H_DEFINED_glGetNamedBufferSubDataEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid * data);
  GLEE_EXTERN GLEEPFNGLGETNAMEDBUFFERSUBDATAEXTPROC GLeeFuncPtr_glGetNamedBufferSubDataEXT;
  #define glGetNamedBufferSubDataEXT GLeeFuncPtr_glGetNamedBufferSubDataEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureBufferEXT
#define GLEE_H_DEFINED_glTextureBufferEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTUREBUFFEREXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLTEXTUREBUFFEREXTPROC GLeeFuncPtr_glTextureBufferEXT;
  #define glTextureBufferEXT GLeeFuncPtr_glTextureBufferEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexBufferEXT
#define GLEE_H_DEFINED_glMultiTexBufferEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXBUFFEREXTPROC) (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
  GLEE_EXTERN GLEEPFNGLMULTITEXBUFFEREXTPROC GLeeFuncPtr_glMultiTexBufferEXT;
  #define glMultiTexBufferEXT GLeeFuncPtr_glMultiTexBufferEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedRenderbufferStorageEXT
#define GLEE_H_DEFINED_glNamedRenderbufferStorageEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC GLeeFuncPtr_glNamedRenderbufferStorageEXT;
  #define glNamedRenderbufferStorageEXT GLeeFuncPtr_glNamedRenderbufferStorageEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedRenderbufferParameterivEXT
#define GLEE_H_DEFINED_glGetNamedRenderbufferParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC) (GLuint renderbuffer, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC GLeeFuncPtr_glGetNamedRenderbufferParameterivEXT;
  #define glGetNamedRenderbufferParameterivEXT GLeeFuncPtr_glGetNamedRenderbufferParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glCheckNamedFramebufferStatusEXT
#define GLEE_H_DEFINED_glCheckNamedFramebufferStatusEXT
  typedef GLenum (APIENTRYP GLEEPFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC) (GLuint framebuffer, GLenum target);
  GLEE_EXTERN GLEEPFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC GLeeFuncPtr_glCheckNamedFramebufferStatusEXT;
  #define glCheckNamedFramebufferStatusEXT GLeeFuncPtr_glCheckNamedFramebufferStatusEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedFramebufferTexture1DEXT
#define GLEE_H_DEFINED_glNamedFramebufferTexture1DEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC GLeeFuncPtr_glNamedFramebufferTexture1DEXT;
  #define glNamedFramebufferTexture1DEXT GLeeFuncPtr_glNamedFramebufferTexture1DEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedFramebufferTexture2DEXT
#define GLEE_H_DEFINED_glNamedFramebufferTexture2DEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC GLeeFuncPtr_glNamedFramebufferTexture2DEXT;
  #define glNamedFramebufferTexture2DEXT GLeeFuncPtr_glNamedFramebufferTexture2DEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedFramebufferTexture3DEXT
#define GLEE_H_DEFINED_glNamedFramebufferTexture3DEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
  GLEE_EXTERN GLEEPFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC GLeeFuncPtr_glNamedFramebufferTexture3DEXT;
  #define glNamedFramebufferTexture3DEXT GLeeFuncPtr_glNamedFramebufferTexture3DEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedFramebufferRenderbufferEXT
#define GLEE_H_DEFINED_glNamedFramebufferRenderbufferEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC GLeeFuncPtr_glNamedFramebufferRenderbufferEXT;
  #define glNamedFramebufferRenderbufferEXT GLeeFuncPtr_glNamedFramebufferRenderbufferEXT
#endif
#ifndef GLEE_H_DEFINED_glGetNamedFramebufferAttachmentParameterivEXT
#define GLEE_H_DEFINED_glGetNamedFramebufferAttachmentParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC GLeeFuncPtr_glGetNamedFramebufferAttachmentParameterivEXT;
  #define glGetNamedFramebufferAttachmentParameterivEXT GLeeFuncPtr_glGetNamedFramebufferAttachmentParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glGenerateTextureMipmapEXT
#define GLEE_H_DEFINED_glGenerateTextureMipmapEXT
  typedef void (APIENTRYP GLEEPFNGLGENERATETEXTUREMIPMAPEXTPROC) (GLuint texture, GLenum target);
  GLEE_EXTERN GLEEPFNGLGENERATETEXTUREMIPMAPEXTPROC GLeeFuncPtr_glGenerateTextureMipmapEXT;
  #define glGenerateTextureMipmapEXT GLeeFuncPtr_glGenerateTextureMipmapEXT
#endif
#ifndef GLEE_H_DEFINED_glGenerateMultiTexMipmapEXT
#define GLEE_H_DEFINED_glGenerateMultiTexMipmapEXT
  typedef void (APIENTRYP GLEEPFNGLGENERATEMULTITEXMIPMAPEXTPROC) (GLenum texunit, GLenum target);
  GLEE_EXTERN GLEEPFNGLGENERATEMULTITEXMIPMAPEXTPROC GLeeFuncPtr_glGenerateMultiTexMipmapEXT;
  #define glGenerateMultiTexMipmapEXT GLeeFuncPtr_glGenerateMultiTexMipmapEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferDrawBufferEXT
#define GLEE_H_DEFINED_glFramebufferDrawBufferEXT
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERDRAWBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERDRAWBUFFEREXTPROC GLeeFuncPtr_glFramebufferDrawBufferEXT;
  #define glFramebufferDrawBufferEXT GLeeFuncPtr_glFramebufferDrawBufferEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferDrawBuffersEXT
#define GLEE_H_DEFINED_glFramebufferDrawBuffersEXT
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC) (GLuint framebuffer, GLsizei n, const GLenum * bufs);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC GLeeFuncPtr_glFramebufferDrawBuffersEXT;
  #define glFramebufferDrawBuffersEXT GLeeFuncPtr_glFramebufferDrawBuffersEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferReadBufferEXT
#define GLEE_H_DEFINED_glFramebufferReadBufferEXT
  typedef void (APIENTRYP GLEEPFNGLFRAMEBUFFERREADBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERREADBUFFEREXTPROC GLeeFuncPtr_glFramebufferReadBufferEXT;
  #define glFramebufferReadBufferEXT GLeeFuncPtr_glFramebufferReadBufferEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFramebufferParameterivEXT
#define GLEE_H_DEFINED_glGetFramebufferParameterivEXT
  typedef void (APIENTRYP GLEEPFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC GLeeFuncPtr_glGetFramebufferParameterivEXT;
  #define glGetFramebufferParameterivEXT GLeeFuncPtr_glGetFramebufferParameterivEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedRenderbufferStorageMultisampleEXT
#define GLEE_H_DEFINED_glNamedRenderbufferStorageMultisampleEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC GLeeFuncPtr_glNamedRenderbufferStorageMultisampleEXT;
  #define glNamedRenderbufferStorageMultisampleEXT GLeeFuncPtr_glNamedRenderbufferStorageMultisampleEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedRenderbufferStorageMultisampleCoverageEXT
#define GLEE_H_DEFINED_glNamedRenderbufferStorageMultisampleCoverageEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC) (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
  GLEE_EXTERN GLEEPFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC GLeeFuncPtr_glNamedRenderbufferStorageMultisampleCoverageEXT;
  #define glNamedRenderbufferStorageMultisampleCoverageEXT GLeeFuncPtr_glNamedRenderbufferStorageMultisampleCoverageEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedFramebufferTextureEXT
#define GLEE_H_DEFINED_glNamedFramebufferTextureEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC GLeeFuncPtr_glNamedFramebufferTextureEXT;
  #define glNamedFramebufferTextureEXT GLeeFuncPtr_glNamedFramebufferTextureEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedFramebufferTextureLayerEXT
#define GLEE_H_DEFINED_glNamedFramebufferTextureLayerEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
  GLEE_EXTERN GLEEPFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC GLeeFuncPtr_glNamedFramebufferTextureLayerEXT;
  #define glNamedFramebufferTextureLayerEXT GLeeFuncPtr_glNamedFramebufferTextureLayerEXT
#endif
#ifndef GLEE_H_DEFINED_glNamedFramebufferTextureFaceEXT
#define GLEE_H_DEFINED_glNamedFramebufferTextureFaceEXT
  typedef void (APIENTRYP GLEEPFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
  GLEE_EXTERN GLEEPFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC GLeeFuncPtr_glNamedFramebufferTextureFaceEXT;
  #define glNamedFramebufferTextureFaceEXT GLeeFuncPtr_glNamedFramebufferTextureFaceEXT
#endif
#ifndef GLEE_H_DEFINED_glTextureRenderbufferEXT
#define GLEE_H_DEFINED_glTextureRenderbufferEXT
  typedef void (APIENTRYP GLEEPFNGLTEXTURERENDERBUFFEREXTPROC) (GLuint texture, GLenum target, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLTEXTURERENDERBUFFEREXTPROC GLeeFuncPtr_glTextureRenderbufferEXT;
  #define glTextureRenderbufferEXT GLeeFuncPtr_glTextureRenderbufferEXT
#endif
#ifndef GLEE_H_DEFINED_glMultiTexRenderbufferEXT
#define GLEE_H_DEFINED_glMultiTexRenderbufferEXT
  typedef void (APIENTRYP GLEEPFNGLMULTITEXRENDERBUFFEREXTPROC) (GLenum texunit, GLenum target, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLMULTITEXRENDERBUFFEREXTPROC GLeeFuncPtr_glMultiTexRenderbufferEXT;
  #define glMultiTexRenderbufferEXT GLeeFuncPtr_glMultiTexRenderbufferEXT
#endif
#endif

/* GL_EXT_vertex_array_bgra */

#ifndef GL_EXT_vertex_array_bgra
#define GL_EXT_vertex_array_bgra 1
#define __GLEE_GL_EXT_vertex_array_bgra 1
/* Constants */
#endif

/* GL_EXT_texture_swizzle */

#ifndef GL_EXT_texture_swizzle
#define GL_EXT_texture_swizzle 1
#define __GLEE_GL_EXT_texture_swizzle 1
/* Constants */
#define GL_TEXTURE_SWIZZLE_R_EXT                           0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT                           0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT                           0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT                           0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT                        0x8E46
#endif

/* GL_NV_explicit_multisample */

#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1
#define __GLEE_GL_NV_explicit_multisample 1
/* Constants */
#define GL_SAMPLE_POSITION_NV                              0x8E50
#define GL_SAMPLE_MASK_NV                                  0x8E51
#define GL_SAMPLE_MASK_VALUE_NV                            0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV                 0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV      0x8E54
#define GL_MAX_SAMPLE_MASK_WORDS_NV                        0x8E59
#define GL_TEXTURE_RENDERBUFFER_NV                         0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV                         0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV                     0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV            0x8E58
#ifndef GLEE_H_DEFINED_glGetMultisamplefvNV
#define GLEE_H_DEFINED_glGetMultisamplefvNV
  typedef void (APIENTRYP GLEEPFNGLGETMULTISAMPLEFVNVPROC) (GLenum pname, GLuint index, GLfloat * val);
  GLEE_EXTERN GLEEPFNGLGETMULTISAMPLEFVNVPROC GLeeFuncPtr_glGetMultisamplefvNV;
  #define glGetMultisamplefvNV GLeeFuncPtr_glGetMultisamplefvNV
#endif
#ifndef GLEE_H_DEFINED_glSampleMaskIndexedNV
#define GLEE_H_DEFINED_glSampleMaskIndexedNV
  typedef void (APIENTRYP GLEEPFNGLSAMPLEMASKINDEXEDNVPROC) (GLuint index, GLbitfield mask);
  GLEE_EXTERN GLEEPFNGLSAMPLEMASKINDEXEDNVPROC GLeeFuncPtr_glSampleMaskIndexedNV;
  #define glSampleMaskIndexedNV GLeeFuncPtr_glSampleMaskIndexedNV
#endif
#ifndef GLEE_H_DEFINED_glTexRenderbufferNV
#define GLEE_H_DEFINED_glTexRenderbufferNV
  typedef void (APIENTRYP GLEEPFNGLTEXRENDERBUFFERNVPROC) (GLenum target, GLuint renderbuffer);
  GLEE_EXTERN GLEEPFNGLTEXRENDERBUFFERNVPROC GLeeFuncPtr_glTexRenderbufferNV;
  #define glTexRenderbufferNV GLeeFuncPtr_glTexRenderbufferNV
#endif
#endif

/* GL_NV_transform_feedback2 */

#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1
#define __GLEE_GL_NV_transform_feedback2 1
/* Constants */
#define GL_TRANSFORM_FEEDBACK_NV                           0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV             0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV             0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV                   0x8E25
#ifndef GLEE_H_DEFINED_glBindTransformFeedbackNV
#define GLEE_H_DEFINED_glBindTransformFeedbackNV
  typedef void (APIENTRYP GLEEPFNGLBINDTRANSFORMFEEDBACKNVPROC) (GLenum target, GLuint id);
  GLEE_EXTERN GLEEPFNGLBINDTRANSFORMFEEDBACKNVPROC GLeeFuncPtr_glBindTransformFeedbackNV;
  #define glBindTransformFeedbackNV GLeeFuncPtr_glBindTransformFeedbackNV
#endif
#ifndef GLEE_H_DEFINED_glDeleteTransformFeedbacksNV
#define GLEE_H_DEFINED_glDeleteTransformFeedbacksNV
  typedef void (APIENTRYP GLEEPFNGLDELETETRANSFORMFEEDBACKSNVPROC) (GLsizei n, const GLuint * ids);
  GLEE_EXTERN GLEEPFNGLDELETETRANSFORMFEEDBACKSNVPROC GLeeFuncPtr_glDeleteTransformFeedbacksNV;
  #define glDeleteTransformFeedbacksNV GLeeFuncPtr_glDeleteTransformFeedbacksNV
#endif
#ifndef GLEE_H_DEFINED_glGenTransformFeedbacksNV
#define GLEE_H_DEFINED_glGenTransformFeedbacksNV
  typedef void (APIENTRYP GLEEPFNGLGENTRANSFORMFEEDBACKSNVPROC) (GLsizei n, GLuint * ids);
  GLEE_EXTERN GLEEPFNGLGENTRANSFORMFEEDBACKSNVPROC GLeeFuncPtr_glGenTransformFeedbacksNV;
  #define glGenTransformFeedbacksNV GLeeFuncPtr_glGenTransformFeedbacksNV
#endif
#ifndef GLEE_H_DEFINED_glIsTransformFeedbackNV
#define GLEE_H_DEFINED_glIsTransformFeedbackNV
  typedef GLboolean (APIENTRYP GLEEPFNGLISTRANSFORMFEEDBACKNVPROC) (GLuint id);
  GLEE_EXTERN GLEEPFNGLISTRANSFORMFEEDBACKNVPROC GLeeFuncPtr_glIsTransformFeedbackNV;
  #define glIsTransformFeedbackNV GLeeFuncPtr_glIsTransformFeedbackNV
#endif
#ifndef GLEE_H_DEFINED_glPauseTransformFeedbackNV
#define GLEE_H_DEFINED_glPauseTransformFeedbackNV
  typedef void (APIENTRYP GLEEPFNGLPAUSETRANSFORMFEEDBACKNVPROC) ();
  GLEE_EXTERN GLEEPFNGLPAUSETRANSFORMFEEDBACKNVPROC GLeeFuncPtr_glPauseTransformFeedbackNV;
  #define glPauseTransformFeedbackNV GLeeFuncPtr_glPauseTransformFeedbackNV
#endif
#ifndef GLEE_H_DEFINED_glResumeTransformFeedbackNV
#define GLEE_H_DEFINED_glResumeTransformFeedbackNV
  typedef void (APIENTRYP GLEEPFNGLRESUMETRANSFORMFEEDBACKNVPROC) ();
  GLEE_EXTERN GLEEPFNGLRESUMETRANSFORMFEEDBACKNVPROC GLeeFuncPtr_glResumeTransformFeedbackNV;
  #define glResumeTransformFeedbackNV GLeeFuncPtr_glResumeTransformFeedbackNV
#endif
#ifndef GLEE_H_DEFINED_glDrawTransformFeedbackNV
#define GLEE_H_DEFINED_glDrawTransformFeedbackNV
  typedef void (APIENTRYP GLEEPFNGLDRAWTRANSFORMFEEDBACKNVPROC) (GLenum mode, GLuint id);
  GLEE_EXTERN GLEEPFNGLDRAWTRANSFORMFEEDBACKNVPROC GLeeFuncPtr_glDrawTransformFeedbackNV;
  #define glDrawTransformFeedbackNV GLeeFuncPtr_glDrawTransformFeedbackNV
#endif
#endif

/* GL_SGIX_texture_select */

#ifndef GL_SGIX_texture_select
#define GL_SGIX_texture_select 1
#define __GLEE_GL_SGIX_texture_select 1
/* Constants */
#endif

/* GL_INGR_blend_func_separate */

#ifndef GL_INGR_blend_func_separate
#define GL_INGR_blend_func_separate 1
#define __GLEE_GL_INGR_blend_func_separate 1
/* Constants */
#ifndef GLEE_H_DEFINED_glBlendFuncSeparateINGR
#define GLEE_H_DEFINED_glBlendFuncSeparateINGR
  typedef void (APIENTRYP GLEEPFNGLBLENDFUNCSEPARATEINGRPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
  GLEE_EXTERN GLEEPFNGLBLENDFUNCSEPARATEINGRPROC GLeeFuncPtr_glBlendFuncSeparateINGR;
  #define glBlendFuncSeparateINGR GLeeFuncPtr_glBlendFuncSeparateINGR
#endif
#endif

/* GL_SGIX_depth_pass_instrument */

#ifndef GL_SGIX_depth_pass_instrument
#define GL_SGIX_depth_pass_instrument 1
#define __GLEE_GL_SGIX_depth_pass_instrument 1
/* Constants */
#endif

/* GL_SGIX_igloo_interface */

#ifndef GL_SGIX_igloo_interface
#define GL_SGIX_igloo_interface 1
#define __GLEE_GL_SGIX_igloo_interface 1
/* Constants */
#ifndef GLEE_H_DEFINED_glIglooInterfaceSGIX
#define GLEE_H_DEFINED_glIglooInterfaceSGIX
  typedef void (APIENTRYP GLEEPFNGLIGLOOINTERFACESGIXPROC) (GLenum pname, const GLvoid * params);
  GLEE_EXTERN GLEEPFNGLIGLOOINTERFACESGIXPROC GLeeFuncPtr_glIglooInterfaceSGIX;
  #define glIglooInterfaceSGIX GLeeFuncPtr_glIglooInterfaceSGIX
#endif
#endif

/* GL_EXT_fragment_lighting */

#ifndef GL_EXT_fragment_lighting
#define GL_EXT_fragment_lighting 1
#define __GLEE_GL_EXT_fragment_lighting 1
/* Constants */
#define GL_FRAGMENT_LIGHTING_EXT                           0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_EXT                     0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT                0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT           0x8403
#define GL_MAX_FRAGMENT_LIGHTS_EXT                         0x8404
#define GL_MAX_ACTIVE_LIGHTS_EXT                           0x8405
#define GL_CURRENT_RASTER_NORMAL_EXT                       0x8406
#define GL_LIGHT_ENV_MODE_EXT                              0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT           0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT               0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT                0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT   0x840B
#define GL_FRAGMENT_LIGHT0_EXT                             0x840C
#define GL_FRAGMENT_LIGHT7_EXT                             0x8413
#ifndef GLEE_H_DEFINED_glFragmentLightModeliEXT
#define GLEE_H_DEFINED_glFragmentLightModeliEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELIEXTPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELIEXTPROC GLeeFuncPtr_glFragmentLightModeliEXT;
  #define glFragmentLightModeliEXT GLeeFuncPtr_glFragmentLightModeliEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightModelfEXT
#define GLEE_H_DEFINED_glFragmentLightModelfEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELFEXTPROC) (GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELFEXTPROC GLeeFuncPtr_glFragmentLightModelfEXT;
  #define glFragmentLightModelfEXT GLeeFuncPtr_glFragmentLightModelfEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightModelivEXT
#define GLEE_H_DEFINED_glFragmentLightModelivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELIVEXTPROC) (GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELIVEXTPROC GLeeFuncPtr_glFragmentLightModelivEXT;
  #define glFragmentLightModelivEXT GLeeFuncPtr_glFragmentLightModelivEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightModelfvEXT
#define GLEE_H_DEFINED_glFragmentLightModelfvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTMODELFVEXTPROC) (GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTMODELFVEXTPROC GLeeFuncPtr_glFragmentLightModelfvEXT;
  #define glFragmentLightModelfvEXT GLeeFuncPtr_glFragmentLightModelfvEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightiEXT
#define GLEE_H_DEFINED_glFragmentLightiEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTIEXTPROC) (GLenum light, GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTIEXTPROC GLeeFuncPtr_glFragmentLightiEXT;
  #define glFragmentLightiEXT GLeeFuncPtr_glFragmentLightiEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightfEXT
#define GLEE_H_DEFINED_glFragmentLightfEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTFEXTPROC) (GLenum light, GLenum pname, GLfloat param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTFEXTPROC GLeeFuncPtr_glFragmentLightfEXT;
  #define glFragmentLightfEXT GLeeFuncPtr_glFragmentLightfEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightivEXT
#define GLEE_H_DEFINED_glFragmentLightivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTIVEXTPROC) (GLenum light, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTIVEXTPROC GLeeFuncPtr_glFragmentLightivEXT;
  #define glFragmentLightivEXT GLeeFuncPtr_glFragmentLightivEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentLightfvEXT
#define GLEE_H_DEFINED_glFragmentLightfvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTLIGHTFVEXTPROC) (GLenum light, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTLIGHTFVEXTPROC GLeeFuncPtr_glFragmentLightfvEXT;
  #define glFragmentLightfvEXT GLeeFuncPtr_glFragmentLightfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentLightivEXT
#define GLEE_H_DEFINED_glGetFragmentLightivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLGETFRAGMENTLIGHTIVEXTPROC) (GLenum light, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTLIGHTIVEXTPROC GLeeFuncPtr_glGetFragmentLightivEXT;
  #define glGetFragmentLightivEXT GLeeFuncPtr_glGetFragmentLightivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentLightfvEXT
#define GLEE_H_DEFINED_glGetFragmentLightfvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLGETFRAGMENTLIGHTFVEXTPROC) (GLenum light, GLenum pname, GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTLIGHTFVEXTPROC GLeeFuncPtr_glGetFragmentLightfvEXT;
  #define glGetFragmentLightfvEXT GLeeFuncPtr_glGetFragmentLightfvEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialfEXT
#define GLEE_H_DEFINED_glFragmentMaterialfEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTMATERIALFEXTPROC) (GLenum face, GLenum pname, const GLfloat param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALFEXTPROC GLeeFuncPtr_glFragmentMaterialfEXT;
  #define glFragmentMaterialfEXT GLeeFuncPtr_glFragmentMaterialfEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialiEXT
#define GLEE_H_DEFINED_glFragmentMaterialiEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTMATERIALIEXTPROC) (GLenum face, GLenum pname, const GLint param);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALIEXTPROC GLeeFuncPtr_glFragmentMaterialiEXT;
  #define glFragmentMaterialiEXT GLeeFuncPtr_glFragmentMaterialiEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialfvEXT
#define GLEE_H_DEFINED_glFragmentMaterialfvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTMATERIALFVEXTPROC) (GLenum face, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALFVEXTPROC GLeeFuncPtr_glFragmentMaterialfvEXT;
  #define glFragmentMaterialfvEXT GLeeFuncPtr_glFragmentMaterialfvEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentMaterialivEXT
#define GLEE_H_DEFINED_glFragmentMaterialivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTMATERIALIVEXTPROC) (GLenum face, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLFRAGMENTMATERIALIVEXTPROC GLeeFuncPtr_glFragmentMaterialivEXT;
  #define glFragmentMaterialivEXT GLeeFuncPtr_glFragmentMaterialivEXT
#endif
#ifndef GLEE_H_DEFINED_glFragmentColorMaterialEXT
#define GLEE_H_DEFINED_glFragmentColorMaterialEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAGMENTCOLORMATERIALEXTPROC) (GLenum face, GLenum mode);
  GLEE_EXTERN GLEEPFNGLFRAGMENTCOLORMATERIALEXTPROC GLeeFuncPtr_glFragmentColorMaterialEXT;
  #define glFragmentColorMaterialEXT GLeeFuncPtr_glFragmentColorMaterialEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentMaterialfvEXT
#define GLEE_H_DEFINED_glGetFragmentMaterialfvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLGETFRAGMENTMATERIALFVEXTPROC) (GLenum face, GLenum pname, const GLfloat * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTMATERIALFVEXTPROC GLeeFuncPtr_glGetFragmentMaterialfvEXT;
  #define glGetFragmentMaterialfvEXT GLeeFuncPtr_glGetFragmentMaterialfvEXT
#endif
#ifndef GLEE_H_DEFINED_glGetFragmentMaterialivEXT
#define GLEE_H_DEFINED_glGetFragmentMaterialivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLGETFRAGMENTMATERIALIVEXTPROC) (GLenum face, GLenum pname, const GLint * params);
  GLEE_EXTERN GLEEPFNGLGETFRAGMENTMATERIALIVEXTPROC GLeeFuncPtr_glGetFragmentMaterialivEXT;
  #define glGetFragmentMaterialivEXT GLeeFuncPtr_glGetFragmentMaterialivEXT
#endif
#ifndef GLEE_H_DEFINED_glLightEnviEXT
#define GLEE_H_DEFINED_glLightEnviEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLLIGHTENVIEXTPROC) (GLenum pname, GLint param);
  GLEE_EXTERN GLEEPFNGLLIGHTENVIEXTPROC GLeeFuncPtr_glLightEnviEXT;
  #define glLightEnviEXT GLeeFuncPtr_glLightEnviEXT
#endif
#endif

/* GL_EXT_geometry_shader4 */

#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
#define __GLEE_GL_EXT_geometry_shader4 1
/* Constants */
#define GL_GEOMETRY_SHADER_EXT                             0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_EXT                       0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT                         0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT                        0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT            0x8C29
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT             0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT               0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT                      0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT             0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT                0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT        0x8DE1
#define GL_LINES_ADJACENCY_EXT                             0xA
#define GL_LINE_STRIP_ADJACENCY_EXT                        0xB
#define GL_TRIANGLES_ADJACENCY_EXT                         0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT                    0xD
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT        0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT          0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT              0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT        0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT                          0x8642
#ifndef GLEE_H_DEFINED_glProgramParameteriEXT
#define GLEE_H_DEFINED_glProgramParameteriEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMPARAMETERIEXTPROC) (GLuint program, GLenum pname, GLint value);
  GLEE_EXTERN GLEEPFNGLPROGRAMPARAMETERIEXTPROC GLeeFuncPtr_glProgramParameteriEXT;
  #define glProgramParameteriEXT GLeeFuncPtr_glProgramParameteriEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureEXT
#define GLEE_H_DEFINED_glFramebufferTextureEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTUREEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTUREEXTPROC GLeeFuncPtr_glFramebufferTextureEXT;
  #define glFramebufferTextureEXT GLeeFuncPtr_glFramebufferTextureEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureLayerEXT
#define GLEE_H_DEFINED_glFramebufferTextureLayerEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURELAYEREXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURELAYEREXTPROC GLeeFuncPtr_glFramebufferTextureLayerEXT;
  #define glFramebufferTextureLayerEXT GLeeFuncPtr_glFramebufferTextureLayerEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureFaceEXT
#define GLEE_H_DEFINED_glFramebufferTextureFaceEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTUREFACEEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTUREFACEEXTPROC GLeeFuncPtr_glFramebufferTextureFaceEXT;
  #define glFramebufferTextureFaceEXT GLeeFuncPtr_glFramebufferTextureFaceEXT
#endif
#endif

/* GL_EXT_scene_marker */

#ifndef GL_EXT_scene_marker
#define GL_EXT_scene_marker 1
#define __GLEE_GL_EXT_scene_marker 1
/* Constants */
#ifndef GLEE_H_DEFINED_glBeginSceneEXT
#define GLEE_H_DEFINED_glBeginSceneEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLBEGINSCENEEXTPROC) ();
  GLEE_EXTERN GLEEPFNGLBEGINSCENEEXTPROC GLeeFuncPtr_glBeginSceneEXT;
  #define glBeginSceneEXT GLeeFuncPtr_glBeginSceneEXT
#endif
#ifndef GLEE_H_DEFINED_glEndSceneEXT
#define GLEE_H_DEFINED_glEndSceneEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLENDSCENEEXTPROC) ();
  GLEE_EXTERN GLEEPFNGLENDSCENEEXTPROC GLeeFuncPtr_glEndSceneEXT;
  #define glEndSceneEXT GLeeFuncPtr_glEndSceneEXT
#endif
#endif

/* GL_EXT_texture_compression_dxt1 */

#ifndef GL_EXT_texture_compression_dxt1
#define GL_EXT_texture_compression_dxt1 1
#define __GLEE_GL_EXT_texture_compression_dxt1 1
/* Constants */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT                    0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT                   0x83F1
#endif

/* GL_EXT_texture_env */

#ifndef GL_EXT_texture_env
#define GL_EXT_texture_env 1
#define __GLEE_GL_EXT_texture_env 1
/* Constants */
#define GL_TEXTURE_ENV0_EXT                                0
#define GL_TEXTURE_ENV_MODE_ALPHA_EXT                      0
#define GL_ENV_COPY_EXT                                    0
#define GL_ENV_REPLACE_EXT                                 0
#define GL_ENV_MODULATE_EXT                                0
#define GL_ENV_ADD_EXT                                     0
#define GL_ENV_SUBTRACT_EXT                                0
#define GL_ENV_REVERSE_SUBTRACT_EXT                        0
#define GL_ENV_BLEND_EXT                                   0
#define GL_ENV_REVERSE_BLEND_EXT                           0
#define GL_TEXTURE_ENV_SHIFT_EXT                           0
#endif

/* GL_IBM_static_data */

#ifndef GL_IBM_static_data
#define GL_IBM_static_data 1
#define __GLEE_GL_IBM_static_data 1
/* Constants */
#define GL_ALL_STATIC_DATA_IBM                             103060
#define GL_STATIC_VERTEX_ARRAY_IBM                         103061
#endif

/* GL_NV_gpu_program4 */

#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1
#define __GLEE_GL_NV_gpu_program4 1
/* Constants */
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT                    0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT                    0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV                    0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV                    0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV                0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV                0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV                  0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV                  0x8DA6
#define GL_GEOMETRY_PROGRAM_NV                             0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV                  0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV          0x8C28
#define GL_GEOMETRY_VERTICES_OUT_EXT                       0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT                         0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT                        0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT            0x8C29
#define GL_LINES_ADJACENCY_EXT                             0xA
#define GL_LINE_STRIP_ADJACENCY_EXT                        0xB
#define GL_TRIANGLES_ADJACENCY_EXT                         0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT                    0xD
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT        0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT          0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT              0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT        0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT                          0x8642
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT                 0x88FD
#ifndef GLEE_H_DEFINED_glProgramLocalParameterI4iNV
#define GLEE_H_DEFINED_glProgramLocalParameterI4iNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETERI4INVPROC) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETERI4INVPROC GLeeFuncPtr_glProgramLocalParameterI4iNV;
  #define glProgramLocalParameterI4iNV GLeeFuncPtr_glProgramLocalParameterI4iNV
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameterI4ivNV
#define GLEE_H_DEFINED_glProgramLocalParameterI4ivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETERI4IVNVPROC) (GLenum target, GLuint index, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETERI4IVNVPROC GLeeFuncPtr_glProgramLocalParameterI4ivNV;
  #define glProgramLocalParameterI4ivNV GLeeFuncPtr_glProgramLocalParameterI4ivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParametersI4ivNV
#define GLEE_H_DEFINED_glProgramLocalParametersI4ivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC GLeeFuncPtr_glProgramLocalParametersI4ivNV;
  #define glProgramLocalParametersI4ivNV GLeeFuncPtr_glProgramLocalParametersI4ivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameterI4uiNV
#define GLEE_H_DEFINED_glProgramLocalParameterI4uiNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETERI4UINVPROC) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETERI4UINVPROC GLeeFuncPtr_glProgramLocalParameterI4uiNV;
  #define glProgramLocalParameterI4uiNV GLeeFuncPtr_glProgramLocalParameterI4uiNV
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParameterI4uivNV
#define GLEE_H_DEFINED_glProgramLocalParameterI4uivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC) (GLenum target, GLuint index, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC GLeeFuncPtr_glProgramLocalParameterI4uivNV;
  #define glProgramLocalParameterI4uivNV GLeeFuncPtr_glProgramLocalParameterI4uivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramLocalParametersI4uivNV
#define GLEE_H_DEFINED_glProgramLocalParametersI4uivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC GLeeFuncPtr_glProgramLocalParametersI4uivNV;
  #define glProgramLocalParametersI4uivNV GLeeFuncPtr_glProgramLocalParametersI4uivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameterI4iNV
#define GLEE_H_DEFINED_glProgramEnvParameterI4iNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETERI4INVPROC) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETERI4INVPROC GLeeFuncPtr_glProgramEnvParameterI4iNV;
  #define glProgramEnvParameterI4iNV GLeeFuncPtr_glProgramEnvParameterI4iNV
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameterI4ivNV
#define GLEE_H_DEFINED_glProgramEnvParameterI4ivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETERI4IVNVPROC) (GLenum target, GLuint index, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETERI4IVNVPROC GLeeFuncPtr_glProgramEnvParameterI4ivNV;
  #define glProgramEnvParameterI4ivNV GLeeFuncPtr_glProgramEnvParameterI4ivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParametersI4ivNV
#define GLEE_H_DEFINED_glProgramEnvParametersI4ivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETERSI4IVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETERSI4IVNVPROC GLeeFuncPtr_glProgramEnvParametersI4ivNV;
  #define glProgramEnvParametersI4ivNV GLeeFuncPtr_glProgramEnvParametersI4ivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameterI4uiNV
#define GLEE_H_DEFINED_glProgramEnvParameterI4uiNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETERI4UINVPROC) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETERI4UINVPROC GLeeFuncPtr_glProgramEnvParameterI4uiNV;
  #define glProgramEnvParameterI4uiNV GLeeFuncPtr_glProgramEnvParameterI4uiNV
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParameterI4uivNV
#define GLEE_H_DEFINED_glProgramEnvParameterI4uivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETERI4UIVNVPROC) (GLenum target, GLuint index, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETERI4UIVNVPROC GLeeFuncPtr_glProgramEnvParameterI4uivNV;
  #define glProgramEnvParameterI4uivNV GLeeFuncPtr_glProgramEnvParameterI4uivNV
#endif
#ifndef GLEE_H_DEFINED_glProgramEnvParametersI4uivNV
#define GLEE_H_DEFINED_glProgramEnvParametersI4uivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLPROGRAMENVPARAMETERSI4UIVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLuint * params);
  GLEE_EXTERN GLEEPFNGLPROGRAMENVPARAMETERSI4UIVNVPROC GLeeFuncPtr_glProgramEnvParametersI4uivNV;
  #define glProgramEnvParametersI4uivNV GLeeFuncPtr_glProgramEnvParametersI4uivNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramLocalParameterIivNV
#define GLEE_H_DEFINED_glGetProgramLocalParameterIivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC) (GLenum target, GLuint index, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC GLeeFuncPtr_glGetProgramLocalParameterIivNV;
  #define glGetProgramLocalParameterIivNV GLeeFuncPtr_glGetProgramLocalParameterIivNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramLocalParameterIuivNV
#define GLEE_H_DEFINED_glGetProgramLocalParameterIuivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC) (GLenum target, GLuint index, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC GLeeFuncPtr_glGetProgramLocalParameterIuivNV;
  #define glGetProgramLocalParameterIuivNV GLeeFuncPtr_glGetProgramLocalParameterIuivNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramEnvParameterIivNV
#define GLEE_H_DEFINED_glGetProgramEnvParameterIivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLGETPROGRAMENVPARAMETERIIVNVPROC) (GLenum target, GLuint index, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMENVPARAMETERIIVNVPROC GLeeFuncPtr_glGetProgramEnvParameterIivNV;
  #define glGetProgramEnvParameterIivNV GLeeFuncPtr_glGetProgramEnvParameterIivNV
#endif
#ifndef GLEE_H_DEFINED_glGetProgramEnvParameterIuivNV
#define GLEE_H_DEFINED_glGetProgramEnvParameterIuivNV
  typedef GLvoid (APIENTRYP GLEEPFNGLGETPROGRAMENVPARAMETERIUIVNVPROC) (GLenum target, GLuint index, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETPROGRAMENVPARAMETERIUIVNVPROC GLeeFuncPtr_glGetProgramEnvParameterIuivNV;
  #define glGetProgramEnvParameterIuivNV GLeeFuncPtr_glGetProgramEnvParameterIuivNV
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureEXT
#define GLEE_H_DEFINED_glFramebufferTextureEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTUREEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTUREEXTPROC GLeeFuncPtr_glFramebufferTextureEXT;
  #define glFramebufferTextureEXT GLeeFuncPtr_glFramebufferTextureEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureLayerEXT
#define GLEE_H_DEFINED_glFramebufferTextureLayerEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTURELAYEREXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTURELAYEREXTPROC GLeeFuncPtr_glFramebufferTextureLayerEXT;
  #define glFramebufferTextureLayerEXT GLeeFuncPtr_glFramebufferTextureLayerEXT
#endif
#ifndef GLEE_H_DEFINED_glFramebufferTextureFaceEXT
#define GLEE_H_DEFINED_glFramebufferTextureFaceEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLFRAMEBUFFERTEXTUREFACEEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
  GLEE_EXTERN GLEEPFNGLFRAMEBUFFERTEXTUREFACEEXTPROC GLeeFuncPtr_glFramebufferTextureFaceEXT;
  #define glFramebufferTextureFaceEXT GLeeFuncPtr_glFramebufferTextureFaceEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2iEXT
#define GLEE_H_DEFINED_glVertexAttribI2iEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI2IEXTPROC) (GLuint index, GLint x, GLint y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2IEXTPROC GLeeFuncPtr_glVertexAttribI2iEXT;
  #define glVertexAttribI2iEXT GLeeFuncPtr_glVertexAttribI2iEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3iEXT
#define GLEE_H_DEFINED_glVertexAttribI3iEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI3IEXTPROC) (GLuint index, GLint x, GLint y, GLint z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3IEXTPROC GLeeFuncPtr_glVertexAttribI3iEXT;
  #define glVertexAttribI3iEXT GLeeFuncPtr_glVertexAttribI3iEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4iEXT
#define GLEE_H_DEFINED_glVertexAttribI4iEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4IEXTPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4IEXTPROC GLeeFuncPtr_glVertexAttribI4iEXT;
  #define glVertexAttribI4iEXT GLeeFuncPtr_glVertexAttribI4iEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI1uiEXT
#define GLEE_H_DEFINED_glVertexAttribI1uiEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI1UIEXTPROC) (GLuint index, GLuint x);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI1UIEXTPROC GLeeFuncPtr_glVertexAttribI1uiEXT;
  #define glVertexAttribI1uiEXT GLeeFuncPtr_glVertexAttribI1uiEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2uiEXT
#define GLEE_H_DEFINED_glVertexAttribI2uiEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI2UIEXTPROC) (GLuint index, GLuint x, GLuint y);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2UIEXTPROC GLeeFuncPtr_glVertexAttribI2uiEXT;
  #define glVertexAttribI2uiEXT GLeeFuncPtr_glVertexAttribI2uiEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3uiEXT
#define GLEE_H_DEFINED_glVertexAttribI3uiEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI3UIEXTPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3UIEXTPROC GLeeFuncPtr_glVertexAttribI3uiEXT;
  #define glVertexAttribI3uiEXT GLeeFuncPtr_glVertexAttribI3uiEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4uiEXT
#define GLEE_H_DEFINED_glVertexAttribI4uiEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4UIEXTPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4UIEXTPROC GLeeFuncPtr_glVertexAttribI4uiEXT;
  #define glVertexAttribI4uiEXT GLeeFuncPtr_glVertexAttribI4uiEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI1ivEXT
#define GLEE_H_DEFINED_glVertexAttribI1ivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI1IVEXTPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI1IVEXTPROC GLeeFuncPtr_glVertexAttribI1ivEXT;
  #define glVertexAttribI1ivEXT GLeeFuncPtr_glVertexAttribI1ivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2ivEXT
#define GLEE_H_DEFINED_glVertexAttribI2ivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI2IVEXTPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2IVEXTPROC GLeeFuncPtr_glVertexAttribI2ivEXT;
  #define glVertexAttribI2ivEXT GLeeFuncPtr_glVertexAttribI2ivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3ivEXT
#define GLEE_H_DEFINED_glVertexAttribI3ivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI3IVEXTPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3IVEXTPROC GLeeFuncPtr_glVertexAttribI3ivEXT;
  #define glVertexAttribI3ivEXT GLeeFuncPtr_glVertexAttribI3ivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4ivEXT
#define GLEE_H_DEFINED_glVertexAttribI4ivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4IVEXTPROC) (GLuint index, const GLint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4IVEXTPROC GLeeFuncPtr_glVertexAttribI4ivEXT;
  #define glVertexAttribI4ivEXT GLeeFuncPtr_glVertexAttribI4ivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI1uivEXT
#define GLEE_H_DEFINED_glVertexAttribI1uivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI1UIVEXTPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI1UIVEXTPROC GLeeFuncPtr_glVertexAttribI1uivEXT;
  #define glVertexAttribI1uivEXT GLeeFuncPtr_glVertexAttribI1uivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI2uivEXT
#define GLEE_H_DEFINED_glVertexAttribI2uivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI2UIVEXTPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI2UIVEXTPROC GLeeFuncPtr_glVertexAttribI2uivEXT;
  #define glVertexAttribI2uivEXT GLeeFuncPtr_glVertexAttribI2uivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI3uivEXT
#define GLEE_H_DEFINED_glVertexAttribI3uivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI3UIVEXTPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI3UIVEXTPROC GLeeFuncPtr_glVertexAttribI3uivEXT;
  #define glVertexAttribI3uivEXT GLeeFuncPtr_glVertexAttribI3uivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4uivEXT
#define GLEE_H_DEFINED_glVertexAttribI4uivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4UIVEXTPROC) (GLuint index, const GLuint * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4UIVEXTPROC GLeeFuncPtr_glVertexAttribI4uivEXT;
  #define glVertexAttribI4uivEXT GLeeFuncPtr_glVertexAttribI4uivEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4bvEXT
#define GLEE_H_DEFINED_glVertexAttribI4bvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4BVEXTPROC) (GLuint index, const GLbyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4BVEXTPROC GLeeFuncPtr_glVertexAttribI4bvEXT;
  #define glVertexAttribI4bvEXT GLeeFuncPtr_glVertexAttribI4bvEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4svEXT
#define GLEE_H_DEFINED_glVertexAttribI4svEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4SVEXTPROC) (GLuint index, const GLshort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4SVEXTPROC GLeeFuncPtr_glVertexAttribI4svEXT;
  #define glVertexAttribI4svEXT GLeeFuncPtr_glVertexAttribI4svEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4ubvEXT
#define GLEE_H_DEFINED_glVertexAttribI4ubvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4UBVEXTPROC) (GLuint index, const GLubyte * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4UBVEXTPROC GLeeFuncPtr_glVertexAttribI4ubvEXT;
  #define glVertexAttribI4ubvEXT GLeeFuncPtr_glVertexAttribI4ubvEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribI4usvEXT
#define GLEE_H_DEFINED_glVertexAttribI4usvEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBI4USVEXTPROC) (GLuint index, const GLushort * v);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBI4USVEXTPROC GLeeFuncPtr_glVertexAttribI4usvEXT;
  #define glVertexAttribI4usvEXT GLeeFuncPtr_glVertexAttribI4usvEXT
#endif
#ifndef GLEE_H_DEFINED_glVertexAttribIPointerEXT
#define GLEE_H_DEFINED_glVertexAttribIPointerEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLVERTEXATTRIBIPOINTEREXTPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
  GLEE_EXTERN GLEEPFNGLVERTEXATTRIBIPOINTEREXTPROC GLeeFuncPtr_glVertexAttribIPointerEXT;
  #define glVertexAttribIPointerEXT GLeeFuncPtr_glVertexAttribIPointerEXT
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribIivEXT
#define GLEE_H_DEFINED_glGetVertexAttribIivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLGETVERTEXATTRIBIIVEXTPROC) (GLuint index, GLenum pname, GLint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBIIVEXTPROC GLeeFuncPtr_glGetVertexAttribIivEXT;
  #define glGetVertexAttribIivEXT GLeeFuncPtr_glGetVertexAttribIivEXT
#endif
#ifndef GLEE_H_DEFINED_glGetVertexAttribIuivEXT
#define GLEE_H_DEFINED_glGetVertexAttribIuivEXT
  typedef GLvoid (APIENTRYP GLEEPFNGLGETVERTEXATTRIBIUIVEXTPROC) (GLuint index, GLenum pname, GLuint * params);
  GLEE_EXTERN GLEEPFNGLGETVERTEXATTRIBIUIVEXTPROC GLeeFuncPtr_glGetVertexAttribIuivEXT;
  #define glGetVertexAttribIuivEXT GLeeFuncPtr_glGetVertexAttribIuivEXT
#endif
#endif

/* GL_OES_byte_coordinates */

#ifndef GL_OES_byte_coordinates
#define GL_OES_byte_coordinates 1
#define __GLEE_GL_OES_byte_coordinates 1
/* Constants */
#define GL_BYTE                                            0x1400
#endif

/* GL_OES_compressed_paletted_texture */

#ifndef GL_OES_compressed_paletted_texture
#define GL_OES_compressed_paletted_texture 1
#define __GLEE_GL_OES_compressed_paletted_texture 1
/* Constants */
#define GL_PALETTE4_RGB8_OES                               0x8B90
#define GL_PALETTE4_RGBA8_OES                              0x8B91
#define GL_PALETTE4_R5_G6_B5_OES                           0x8B92
#define GL_PALETTE4_RGBA4_OES                              0x8B93
#define GL_PALETTE4_RGB5_A1_OES                            0x8B94
#define GL_PALETTE8_RGB8_OES                               0x8B95
#define GL_PALETTE8_RGBA8_OES                              0x8B96
#define GL_PALETTE8_R5_G6_B5_OES                           0x8B97
#define GL_PALETTE8_RGBA4_OES                              0x8B98
#define GL_PALETTE8_RGB5_A1_OES                            0x8B99
#endif

/* GL_OES_single_precision */

#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1
#define __GLEE_GL_OES_single_precision 1
/* Constants */
#ifndef GLEE_H_DEFINED_glDepthRangefOES
#define GLEE_H_DEFINED_glDepthRangefOES
  typedef GLvoid (APIENTRYP GLEEPFNGLDEPTHRANGEFOESPROC) (GLclampf n, GLclampf f);
  GLEE_EXTERN GLEEPFNGLDEPTHRANGEFOESPROC GLeeFuncPtr_glDepthRangefOES;
  #define glDepthRangefOES GLeeFuncPtr_glDepthRangefOES
#endif
#ifndef GLEE_H_DEFINED_glFrustumfOES
#define GLEE_H_DEFINED_glFrustumfOES
  typedef GLvoid (APIENTRYP GLEEPFNGLFRUSTUMFOESPROC) (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
  GLEE_EXTERN GLEEPFNGLFRUSTUMFOESPROC GLeeFuncPtr_glFrustumfOES;
  #define glFrustumfOES GLeeFuncPtr_glFrustumfOES
#endif
#ifndef GLEE_H_DEFINED_glOrthofOES
#define GLEE_H_DEFINED_glOrthofOES
  typedef GLvoid (APIENTRYP GLEEPFNGLORTHOFOESPROC) (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
  GLEE_EXTERN GLEEPFNGLORTHOFOESPROC GLeeFuncPtr_glOrthofOES;
  #define glOrthofOES GLeeFuncPtr_glOrthofOES
#endif
#ifndef GLEE_H_DEFINED_glClipPlanefOES
#define GLEE_H_DEFINED_glClipPlanefOES
  typedef GLvoid (APIENTRYP GLEEPFNGLCLIPPLANEFOESPROC) (GLenum plane, const GLfloat* equation);
  GLEE_EXTERN GLEEPFNGLCLIPPLANEFOESPROC GLeeFuncPtr_glClipPlanefOES;
  #define glClipPlanefOES GLeeFuncPtr_glClipPlanefOES
#endif
#ifndef GLEE_H_DEFINED_glGetClipPlanefOES
#define GLEE_H_DEFINED_glGetClipPlanefOES
  typedef GLvoid (APIENTRYP GLEEPFNGLGETCLIPPLANEFOESPROC) (GLenum plane, GLfloat* equation);
  GLEE_EXTERN GLEEPFNGLGETCLIPPLANEFOESPROC GLeeFuncPtr_glGetClipPlanefOES;
  #define glGetClipPlanefOES GLeeFuncPtr_glGetClipPlanefOES
#endif
#ifndef GLEE_H_DEFINED_glClearDepthfOES
#define GLEE_H_DEFINED_glClearDepthfOES
  typedef GLvoid (APIENTRYP GLEEPFNGLCLEARDEPTHFOESPROC) (GLclampd depth);
  GLEE_EXTERN GLEEPFNGLCLEARDEPTHFOESPROC GLeeFuncPtr_glClearDepthfOES;
  #define glClearDepthfOES GLeeFuncPtr_glClearDepthfOES
#endif
#endif

/* GL_SGIX_pixel_texture_bits */

#ifndef GL_SGIX_pixel_texture_bits
#define GL_SGIX_pixel_texture_bits 1
#define __GLEE_GL_SGIX_pixel_texture_bits 1
/* Constants */
#endif

/* GL_SGIX_texture_range */

#ifndef GL_SGIX_texture_range
#define GL_SGIX_texture_range 1
#define __GLEE_GL_SGIX_texture_range 1
/* Constants */
#define GL_RGB_SIGNED_SGIX                                 0x85E0
#define GL_RGBA_SIGNED_SGIX                                0x85E1
#define GL_ALPHA_SIGNED_SGIX                               0x85E2
#define GL_LUMINANCE_SIGNED_SGIX                           0x85E3
#define GL_INTENSITY_SIGNED_SGIX                           0x85E4
#define GL_LUMINANCE_ALPHA_SIGNED_SGIX                     0x85E5
#define GL_RGB16_SIGNED_SGIX                               0x85E6
#define GL_RGBA16_SIGNED_SGIX                              0x85E7
#define GL_ALPHA16_SIGNED_SGIX                             0x85E8
#define GL_LUMINANCE16_SIGNED_SGIX                         0x85E9
#define GL_INTENSITY16_SIGNED_SGIX                         0x85EA
#define GL_LUMINANCE16_ALPHA16_SIGNED_SGIX                 0x85EB
#define GL_RGB_EXTENDED_RANGE_SGIX                         0x85EC
#define GL_RGBA_EXTENDED_RANGE_SGIX                        0x85ED
#define GL_ALPHA_EXTENDED_RANGE_SGIX                       0x85EE
#define GL_LUMINANCE_EXTENDED_RANGE_SGIX                   0x85EF
#define GL_INTENSITY_EXTENDED_RANGE_SGIX                   0x85F0
#define GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX             0x85F1
#define GL_RGB16_EXTENDED_RANGE_SGIX                       0x85F2
#define GL_RGBA16_EXTENDED_RANGE_SGIX                      0x85F3
#define GL_ALPHA16_EXTENDED_RANGE_SGIX                     0x85F4
#define GL_LUMINANCE16_EXTENDED_RANGE_SGIX                 0x85F5
#define GL_INTENSITY16_EXTENDED_RANGE_SGIX                 0x85F6
#define GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX         0x85F7
#define GL_MIN_LUMINANCE_SGIS                              0x85F8
#define GL_MAX_LUMINANCE_SGIS                              0x85F9
#define GL_MIN_INTENSITY_SGIS                              0x85FA
#define GL_MAX_INTENSITY_SGIS                              0x85FB
#endif

/* WGL  */

#ifdef WIN32

/* Extension querying variables */

GLEE_EXTERN GLboolean _GLEE_WGL_ARB_buffer_region;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_multisample;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_extensions_string;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_pixel_format;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_make_current_read;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_pbuffer;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_render_texture;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_pixel_format_float;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_create_context;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_make_current_read;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_pixel_format;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_pbuffer;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_depth_float;
GLEE_EXTERN GLboolean _GLEE_WGL_3DFX_multisample;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_multisample;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_digital_video_control;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_gamma;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_genlock;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_image_buffer;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_swap_frame_lock;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_render_depth_texture;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_render_texture_rectangle;
GLEE_EXTERN GLboolean _GLEE_WGL_ATI_pixel_format_float;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_float_buffer;
GLEE_EXTERN GLboolean _GLEE_WGL_3DL_stereo_control;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_pixel_format_packed_float;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_framebuffer_sRGB;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_present_video;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_swap_group;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_gpu_affinity;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_display_color_table;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_extensions_string;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_swap_control;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_vertex_array_range;
GLEE_EXTERN GLboolean _GLEE_WGL_OML_sync_control;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_swap_frame_usage;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_video_output;

/* Aliases for extension querying variables */

#define GLEE_WGL_ARB_buffer_region     GLeeEnabled(&_GLEE_WGL_ARB_buffer_region)
#define GLEE_WGL_ARB_multisample     GLeeEnabled(&_GLEE_WGL_ARB_multisample)
#define GLEE_WGL_ARB_extensions_string     GLeeEnabled(&_GLEE_WGL_ARB_extensions_string)
#define GLEE_WGL_ARB_pixel_format     GLeeEnabled(&_GLEE_WGL_ARB_pixel_format)
#define GLEE_WGL_ARB_make_current_read     GLeeEnabled(&_GLEE_WGL_ARB_make_current_read)
#define GLEE_WGL_ARB_pbuffer     GLeeEnabled(&_GLEE_WGL_ARB_pbuffer)
#define GLEE_WGL_ARB_render_texture     GLeeEnabled(&_GLEE_WGL_ARB_render_texture)
#define GLEE_WGL_ARB_pixel_format_float     GLeeEnabled(&_GLEE_WGL_ARB_pixel_format_float)
#define GLEE_WGL_ARB_create_context     GLeeEnabled(&_GLEE_WGL_ARB_create_context)
#define GLEE_WGL_EXT_make_current_read     GLeeEnabled(&_GLEE_WGL_EXT_make_current_read)
#define GLEE_WGL_EXT_pixel_format     GLeeEnabled(&_GLEE_WGL_EXT_pixel_format)
#define GLEE_WGL_EXT_pbuffer     GLeeEnabled(&_GLEE_WGL_EXT_pbuffer)
#define GLEE_WGL_EXT_depth_float     GLeeEnabled(&_GLEE_WGL_EXT_depth_float)
#define GLEE_WGL_3DFX_multisample     GLeeEnabled(&_GLEE_WGL_3DFX_multisample)
#define GLEE_WGL_EXT_multisample     GLeeEnabled(&_GLEE_WGL_EXT_multisample)
#define GLEE_WGL_I3D_digital_video_control     GLeeEnabled(&_GLEE_WGL_I3D_digital_video_control)
#define GLEE_WGL_I3D_gamma     GLeeEnabled(&_GLEE_WGL_I3D_gamma)
#define GLEE_WGL_I3D_genlock     GLeeEnabled(&_GLEE_WGL_I3D_genlock)
#define GLEE_WGL_I3D_image_buffer     GLeeEnabled(&_GLEE_WGL_I3D_image_buffer)
#define GLEE_WGL_I3D_swap_frame_lock     GLeeEnabled(&_GLEE_WGL_I3D_swap_frame_lock)
#define GLEE_WGL_NV_render_depth_texture     GLeeEnabled(&_GLEE_WGL_NV_render_depth_texture)
#define GLEE_WGL_NV_render_texture_rectangle     GLeeEnabled(&_GLEE_WGL_NV_render_texture_rectangle)
#define GLEE_WGL_ATI_pixel_format_float     GLeeEnabled(&_GLEE_WGL_ATI_pixel_format_float)
#define GLEE_WGL_NV_float_buffer     GLeeEnabled(&_GLEE_WGL_NV_float_buffer)
#define GLEE_WGL_3DL_stereo_control     GLeeEnabled(&_GLEE_WGL_3DL_stereo_control)
#define GLEE_WGL_EXT_pixel_format_packed_float     GLeeEnabled(&_GLEE_WGL_EXT_pixel_format_packed_float)
#define GLEE_WGL_EXT_framebuffer_sRGB     GLeeEnabled(&_GLEE_WGL_EXT_framebuffer_sRGB)
#define GLEE_WGL_NV_present_video     GLeeEnabled(&_GLEE_WGL_NV_present_video)
#define GLEE_WGL_NV_swap_group     GLeeEnabled(&_GLEE_WGL_NV_swap_group)
#define GLEE_WGL_NV_gpu_affinity     GLeeEnabled(&_GLEE_WGL_NV_gpu_affinity)
#define GLEE_WGL_EXT_display_color_table     GLeeEnabled(&_GLEE_WGL_EXT_display_color_table)
#define GLEE_WGL_EXT_extensions_string     GLeeEnabled(&_GLEE_WGL_EXT_extensions_string)
#define GLEE_WGL_EXT_swap_control     GLeeEnabled(&_GLEE_WGL_EXT_swap_control)
#define GLEE_WGL_NV_vertex_array_range     GLeeEnabled(&_GLEE_WGL_NV_vertex_array_range)
#define GLEE_WGL_OML_sync_control     GLeeEnabled(&_GLEE_WGL_OML_sync_control)
#define GLEE_WGL_I3D_swap_frame_usage     GLeeEnabled(&_GLEE_WGL_I3D_swap_frame_usage)
#define GLEE_WGL_NV_video_output     GLeeEnabled(&_GLEE_WGL_NV_video_output)

/* WGL_ARB_buffer_region */

#ifndef WGL_ARB_buffer_region
#define WGL_ARB_buffer_region 1
#define __GLEE_WGL_ARB_buffer_region 1
/* Constants */
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB                     0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB                      0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB                           0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB                         0x00000008
#ifndef GLEE_H_DEFINED_wglCreateBufferRegionARB
#define GLEE_H_DEFINED_wglCreateBufferRegionARB
  typedef HANDLE (APIENTRYP GLEEPFNWGLCREATEBUFFERREGIONARBPROC) (HDC hDC, int iLayerPlane, UINT uType);
  GLEE_EXTERN GLEEPFNWGLCREATEBUFFERREGIONARBPROC GLeeFuncPtr_wglCreateBufferRegionARB;
  #define wglCreateBufferRegionARB GLeeFuncPtr_wglCreateBufferRegionARB
#endif
#ifndef GLEE_H_DEFINED_wglDeleteBufferRegionARB
#define GLEE_H_DEFINED_wglDeleteBufferRegionARB
  typedef VOID (APIENTRYP GLEEPFNWGLDELETEBUFFERREGIONARBPROC) (HANDLE hRegion);
  GLEE_EXTERN GLEEPFNWGLDELETEBUFFERREGIONARBPROC GLeeFuncPtr_wglDeleteBufferRegionARB;
  #define wglDeleteBufferRegionARB GLeeFuncPtr_wglDeleteBufferRegionARB
#endif
#ifndef GLEE_H_DEFINED_wglSaveBufferRegionARB
#define GLEE_H_DEFINED_wglSaveBufferRegionARB
  typedef BOOL (APIENTRYP GLEEPFNWGLSAVEBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height);
  GLEE_EXTERN GLEEPFNWGLSAVEBUFFERREGIONARBPROC GLeeFuncPtr_wglSaveBufferRegionARB;
  #define wglSaveBufferRegionARB GLeeFuncPtr_wglSaveBufferRegionARB
#endif
#ifndef GLEE_H_DEFINED_wglRestoreBufferRegionARB
#define GLEE_H_DEFINED_wglRestoreBufferRegionARB
  typedef BOOL (APIENTRYP GLEEPFNWGLRESTOREBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
  GLEE_EXTERN GLEEPFNWGLRESTOREBUFFERREGIONARBPROC GLeeFuncPtr_wglRestoreBufferRegionARB;
  #define wglRestoreBufferRegionARB GLeeFuncPtr_wglRestoreBufferRegionARB
#endif
#endif

/* WGL_ARB_multisample */

#ifndef WGL_ARB_multisample
#define WGL_ARB_multisample 1
#define __GLEE_WGL_ARB_multisample 1
/* Constants */
#define WGL_SAMPLE_BUFFERS_ARB                             0x2041
#define WGL_SAMPLES_ARB                                    0x2042
#endif

/* WGL_ARB_extensions_string */

#ifndef WGL_ARB_extensions_string
#define WGL_ARB_extensions_string 1
#define __GLEE_WGL_ARB_extensions_string 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglGetExtensionsStringARB
#define GLEE_H_DEFINED_wglGetExtensionsStringARB
  typedef const char * (APIENTRYP GLEEPFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
  GLEE_EXTERN GLEEPFNWGLGETEXTENSIONSSTRINGARBPROC GLeeFuncPtr_wglGetExtensionsStringARB;
  #define wglGetExtensionsStringARB GLeeFuncPtr_wglGetExtensionsStringARB
#endif
#endif

/* WGL_ARB_pixel_format */

#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format 1
#define __GLEE_WGL_ARB_pixel_format 1
/* Constants */
#define WGL_NUMBER_PIXEL_FORMATS_ARB                       0x2000
#define WGL_DRAW_TO_WINDOW_ARB                             0x2001
#define WGL_DRAW_TO_BITMAP_ARB                             0x2002
#define WGL_ACCELERATION_ARB                               0x2003
#define WGL_NEED_PALETTE_ARB                               0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB                        0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB                         0x2006
#define WGL_SWAP_METHOD_ARB                                0x2007
#define WGL_NUMBER_OVERLAYS_ARB                            0x2008
#define WGL_NUMBER_UNDERLAYS_ARB                           0x2009
#define WGL_TRANSPARENT_ARB                                0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB                      0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB                    0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB                     0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB                    0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB                    0x203B
#define WGL_SHARE_DEPTH_ARB                                0x200C
#define WGL_SHARE_STENCIL_ARB                              0x200D
#define WGL_SHARE_ACCUM_ARB                                0x200E
#define WGL_SUPPORT_GDI_ARB                                0x200F
#define WGL_SUPPORT_OPENGL_ARB                             0x2010
#define WGL_DOUBLE_BUFFER_ARB                              0x2011
#define WGL_STEREO_ARB                                     0x2012
#define WGL_PIXEL_TYPE_ARB                                 0x2013
#define WGL_COLOR_BITS_ARB                                 0x2014
#define WGL_RED_BITS_ARB                                   0x2015
#define WGL_RED_SHIFT_ARB                                  0x2016
#define WGL_GREEN_BITS_ARB                                 0x2017
#define WGL_GREEN_SHIFT_ARB                                0x2018
#define WGL_BLUE_BITS_ARB                                  0x2019
#define WGL_BLUE_SHIFT_ARB                                 0x201A
#define WGL_ALPHA_BITS_ARB                                 0x201B
#define WGL_ALPHA_SHIFT_ARB                                0x201C
#define WGL_ACCUM_BITS_ARB                                 0x201D
#define WGL_ACCUM_RED_BITS_ARB                             0x201E
#define WGL_ACCUM_GREEN_BITS_ARB                           0x201F
#define WGL_ACCUM_BLUE_BITS_ARB                            0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB                           0x2021
#define WGL_DEPTH_BITS_ARB                                 0x2022
#define WGL_STENCIL_BITS_ARB                               0x2023
#define WGL_AUX_BUFFERS_ARB                                0x2024
#define WGL_NO_ACCELERATION_ARB                            0x2025
#define WGL_GENERIC_ACCELERATION_ARB                       0x2026
#define WGL_FULL_ACCELERATION_ARB                          0x2027
#define WGL_SWAP_EXCHANGE_ARB                              0x2028
#define WGL_SWAP_COPY_ARB                                  0x2029
#define WGL_SWAP_UNDEFINED_ARB                             0x202A
#define WGL_TYPE_RGBA_ARB                                  0x202B
#define WGL_TYPE_COLORINDEX_ARB                            0x202C
#ifndef GLEE_H_DEFINED_wglGetPixelFormatAttribivARB
#define GLEE_H_DEFINED_wglGetPixelFormatAttribivARB
  typedef BOOL (APIENTRYP GLEEPFNWGLGETPIXELFORMATATTRIBIVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues);
  GLEE_EXTERN GLEEPFNWGLGETPIXELFORMATATTRIBIVARBPROC GLeeFuncPtr_wglGetPixelFormatAttribivARB;
  #define wglGetPixelFormatAttribivARB GLeeFuncPtr_wglGetPixelFormatAttribivARB
#endif
#ifndef GLEE_H_DEFINED_wglGetPixelFormatAttribfvARB
#define GLEE_H_DEFINED_wglGetPixelFormatAttribfvARB
  typedef BOOL (APIENTRYP GLEEPFNWGLGETPIXELFORMATATTRIBFVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues);
  GLEE_EXTERN GLEEPFNWGLGETPIXELFORMATATTRIBFVARBPROC GLeeFuncPtr_wglGetPixelFormatAttribfvARB;
  #define wglGetPixelFormatAttribfvARB GLeeFuncPtr_wglGetPixelFormatAttribfvARB
#endif
#ifndef GLEE_H_DEFINED_wglChoosePixelFormatARB
#define GLEE_H_DEFINED_wglChoosePixelFormatARB
  typedef BOOL (APIENTRYP GLEEPFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);
  GLEE_EXTERN GLEEPFNWGLCHOOSEPIXELFORMATARBPROC GLeeFuncPtr_wglChoosePixelFormatARB;
  #define wglChoosePixelFormatARB GLeeFuncPtr_wglChoosePixelFormatARB
#endif
#endif

/* WGL_ARB_make_current_read */

#ifndef WGL_ARB_make_current_read
#define WGL_ARB_make_current_read 1
#define __GLEE_WGL_ARB_make_current_read 1
/* Constants */
#define ERROR_INVALID_PIXEL_TYPE_ARB                       0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB             0x2054
#ifndef GLEE_H_DEFINED_wglMakeContextCurrentARB
#define GLEE_H_DEFINED_wglMakeContextCurrentARB
  typedef BOOL (APIENTRYP GLEEPFNWGLMAKECONTEXTCURRENTARBPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
  GLEE_EXTERN GLEEPFNWGLMAKECONTEXTCURRENTARBPROC GLeeFuncPtr_wglMakeContextCurrentARB;
  #define wglMakeContextCurrentARB GLeeFuncPtr_wglMakeContextCurrentARB
#endif
#ifndef GLEE_H_DEFINED_wglGetCurrentReadDCARB
#define GLEE_H_DEFINED_wglGetCurrentReadDCARB
  typedef HDC (APIENTRYP GLEEPFNWGLGETCURRENTREADDCARBPROC) ();
  GLEE_EXTERN GLEEPFNWGLGETCURRENTREADDCARBPROC GLeeFuncPtr_wglGetCurrentReadDCARB;
  #define wglGetCurrentReadDCARB GLeeFuncPtr_wglGetCurrentReadDCARB
#endif
#endif

/* WGL_ARB_pbuffer */

#ifndef WGL_ARB_pbuffer
#define WGL_ARB_pbuffer 1
#define __GLEE_WGL_ARB_pbuffer 1
/* Constants */
#define WGL_DRAW_TO_PBUFFER_ARB                            0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB                         0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB                          0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB                         0x2030
#define WGL_PBUFFER_LARGEST_ARB                            0x2033
#define WGL_PBUFFER_WIDTH_ARB                              0x2034
#define WGL_PBUFFER_HEIGHT_ARB                             0x2035
#define WGL_PBUFFER_LOST_ARB                               0x2036
#ifndef GLEE_H_DEFINED_wglCreatePbufferARB
#define GLEE_H_DEFINED_wglCreatePbufferARB
  typedef HPBUFFERARB (APIENTRYP GLEEPFNWGLCREATEPBUFFERARBPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
  GLEE_EXTERN GLEEPFNWGLCREATEPBUFFERARBPROC GLeeFuncPtr_wglCreatePbufferARB;
  #define wglCreatePbufferARB GLeeFuncPtr_wglCreatePbufferARB
#endif
#ifndef GLEE_H_DEFINED_wglGetPbufferDCARB
#define GLEE_H_DEFINED_wglGetPbufferDCARB
  typedef HDC (APIENTRYP GLEEPFNWGLGETPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer);
  GLEE_EXTERN GLEEPFNWGLGETPBUFFERDCARBPROC GLeeFuncPtr_wglGetPbufferDCARB;
  #define wglGetPbufferDCARB GLeeFuncPtr_wglGetPbufferDCARB
#endif
#ifndef GLEE_H_DEFINED_wglReleasePbufferDCARB
#define GLEE_H_DEFINED_wglReleasePbufferDCARB
  typedef int (APIENTRYP GLEEPFNWGLRELEASEPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer, HDC hDC);
  GLEE_EXTERN GLEEPFNWGLRELEASEPBUFFERDCARBPROC GLeeFuncPtr_wglReleasePbufferDCARB;
  #define wglReleasePbufferDCARB GLeeFuncPtr_wglReleasePbufferDCARB
#endif
#ifndef GLEE_H_DEFINED_wglDestroyPbufferARB
#define GLEE_H_DEFINED_wglDestroyPbufferARB
  typedef BOOL (APIENTRYP GLEEPFNWGLDESTROYPBUFFERARBPROC) (HPBUFFERARB hPbuffer);
  GLEE_EXTERN GLEEPFNWGLDESTROYPBUFFERARBPROC GLeeFuncPtr_wglDestroyPbufferARB;
  #define wglDestroyPbufferARB GLeeFuncPtr_wglDestroyPbufferARB
#endif
#ifndef GLEE_H_DEFINED_wglQueryPbufferARB
#define GLEE_H_DEFINED_wglQueryPbufferARB
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYPBUFFERARBPROC) (HPBUFFERARB hPbuffer, int iAttribute, int * piValue);
  GLEE_EXTERN GLEEPFNWGLQUERYPBUFFERARBPROC GLeeFuncPtr_wglQueryPbufferARB;
  #define wglQueryPbufferARB GLeeFuncPtr_wglQueryPbufferARB
#endif
#endif

/* WGL_ARB_render_texture */

#ifndef WGL_ARB_render_texture
#define WGL_ARB_render_texture 1
#define __GLEE_WGL_ARB_render_texture 1
/* Constants */
#define WGL_BIND_TO_TEXTURE_RGB_ARB                        0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB                       0x2071
#define WGL_TEXTURE_FORMAT_ARB                             0x2072
#define WGL_TEXTURE_TARGET_ARB                             0x2073
#define WGL_MIPMAP_TEXTURE_ARB                             0x2074
#define WGL_TEXTURE_RGB_ARB                                0x2075
#define WGL_TEXTURE_RGBA_ARB                               0x2076
#define WGL_NO_TEXTURE_ARB                                 0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB                           0x2078
#define WGL_TEXTURE_1D_ARB                                 0x2079
#define WGL_TEXTURE_2D_ARB                                 0x207A
#define WGL_MIPMAP_LEVEL_ARB                               0x207B
#define WGL_CUBE_MAP_FACE_ARB                              0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                0x2082
#define WGL_FRONT_LEFT_ARB                                 0x2083
#define WGL_FRONT_RIGHT_ARB                                0x2084
#define WGL_BACK_LEFT_ARB                                  0x2085
#define WGL_BACK_RIGHT_ARB                                 0x2086
#define WGL_AUX0_ARB                                       0x2087
#define WGL_AUX1_ARB                                       0x2088
#define WGL_AUX2_ARB                                       0x2089
#define WGL_AUX3_ARB                                       0x208A
#define WGL_AUX4_ARB                                       0x208B
#define WGL_AUX5_ARB                                       0x208C
#define WGL_AUX6_ARB                                       0x208D
#define WGL_AUX7_ARB                                       0x208E
#define WGL_AUX8_ARB                                       0x208F
#define WGL_AUX9_ARB                                       0x2090
#ifndef GLEE_H_DEFINED_wglBindTexImageARB
#define GLEE_H_DEFINED_wglBindTexImageARB
  typedef BOOL (APIENTRYP GLEEPFNWGLBINDTEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
  GLEE_EXTERN GLEEPFNWGLBINDTEXIMAGEARBPROC GLeeFuncPtr_wglBindTexImageARB;
  #define wglBindTexImageARB GLeeFuncPtr_wglBindTexImageARB
#endif
#ifndef GLEE_H_DEFINED_wglReleaseTexImageARB
#define GLEE_H_DEFINED_wglReleaseTexImageARB
  typedef BOOL (APIENTRYP GLEEPFNWGLRELEASETEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
  GLEE_EXTERN GLEEPFNWGLRELEASETEXIMAGEARBPROC GLeeFuncPtr_wglReleaseTexImageARB;
  #define wglReleaseTexImageARB GLeeFuncPtr_wglReleaseTexImageARB
#endif
#ifndef GLEE_H_DEFINED_wglSetPbufferAttribARB
#define GLEE_H_DEFINED_wglSetPbufferAttribARB
  typedef BOOL (APIENTRYP GLEEPFNWGLSETPBUFFERATTRIBARBPROC) (HPBUFFERARB hPbuffer, const int * piAttribList);
  GLEE_EXTERN GLEEPFNWGLSETPBUFFERATTRIBARBPROC GLeeFuncPtr_wglSetPbufferAttribARB;
  #define wglSetPbufferAttribARB GLeeFuncPtr_wglSetPbufferAttribARB
#endif
#endif

/* WGL_ARB_pixel_format_float */

#ifndef WGL_ARB_pixel_format_float
#define WGL_ARB_pixel_format_float 1
#define __GLEE_WGL_ARB_pixel_format_float 1
/* Constants */
#define WGL_TYPE_RGBA_FLOAT_ARB                            0x21A0
#endif

/* WGL_ARB_create_context */

#ifndef WGL_ARB_create_context
#define WGL_ARB_create_context 1
#define __GLEE_WGL_ARB_create_context 1
/* Constants */
#define WGL_CONTEXT_DEBUG_BIT_ARB                          0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB             0x0002
#define WGL_CONTEXT_MAJOR_VERSION_ARB                      0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB                      0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB                        0x2093
#define WGL_CONTEXT_FLAGS_ARB                              0x2094
#define ERROR_INVALID_VERSION_ARB                          0x2095
#ifndef GLEE_H_DEFINED_wglCreateContextAttribsARB
#define GLEE_H_DEFINED_wglCreateContextAttribsARB
  typedef HGLRC (APIENTRYP GLEEPFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int * attribList);
  GLEE_EXTERN GLEEPFNWGLCREATECONTEXTATTRIBSARBPROC GLeeFuncPtr_wglCreateContextAttribsARB;
  #define wglCreateContextAttribsARB GLeeFuncPtr_wglCreateContextAttribsARB
#endif
#endif

/* WGL_EXT_make_current_read */

#ifndef WGL_EXT_make_current_read
#define WGL_EXT_make_current_read 1
#define __GLEE_WGL_EXT_make_current_read 1
/* Constants */
#define ERROR_INVALID_PIXEL_TYPE_EXT                       0x2043
#ifndef GLEE_H_DEFINED_wglMakeContextCurrentEXT
#define GLEE_H_DEFINED_wglMakeContextCurrentEXT
  typedef BOOL (APIENTRYP GLEEPFNWGLMAKECONTEXTCURRENTEXTPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
  GLEE_EXTERN GLEEPFNWGLMAKECONTEXTCURRENTEXTPROC GLeeFuncPtr_wglMakeContextCurrentEXT;
  #define wglMakeContextCurrentEXT GLeeFuncPtr_wglMakeContextCurrentEXT
#endif
#ifndef GLEE_H_DEFINED_wglGetCurrentReadDCEXT
#define GLEE_H_DEFINED_wglGetCurrentReadDCEXT
  typedef HDC (APIENTRYP GLEEPFNWGLGETCURRENTREADDCEXTPROC) ();
  GLEE_EXTERN GLEEPFNWGLGETCURRENTREADDCEXTPROC GLeeFuncPtr_wglGetCurrentReadDCEXT;
  #define wglGetCurrentReadDCEXT GLeeFuncPtr_wglGetCurrentReadDCEXT
#endif
#endif

/* WGL_EXT_pixel_format */

#ifndef WGL_EXT_pixel_format
#define WGL_EXT_pixel_format 1
#define __GLEE_WGL_EXT_pixel_format 1
/* Constants */
#define WGL_NUMBER_PIXEL_FORMATS_EXT                       0x2000
#define WGL_DRAW_TO_WINDOW_EXT                             0x2001
#define WGL_DRAW_TO_BITMAP_EXT                             0x2002
#define WGL_ACCELERATION_EXT                               0x2003
#define WGL_NEED_PALETTE_EXT                               0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT                        0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT                         0x2006
#define WGL_SWAP_METHOD_EXT                                0x2007
#define WGL_NUMBER_OVERLAYS_EXT                            0x2008
#define WGL_NUMBER_UNDERLAYS_EXT                           0x2009
#define WGL_TRANSPARENT_EXT                                0x200A
#define WGL_TRANSPARENT_VALUE_EXT                          0x200B
#define WGL_SHARE_DEPTH_EXT                                0x200C
#define WGL_SHARE_STENCIL_EXT                              0x200D
#define WGL_SHARE_ACCUM_EXT                                0x200E
#define WGL_SUPPORT_GDI_EXT                                0x200F
#define WGL_SUPPORT_OPENGL_EXT                             0x2010
#define WGL_DOUBLE_BUFFER_EXT                              0x2011
#define WGL_STEREO_EXT                                     0x2012
#define WGL_PIXEL_TYPE_EXT                                 0x2013
#define WGL_COLOR_BITS_EXT                                 0x2014
#define WGL_RED_BITS_EXT                                   0x2015
#define WGL_RED_SHIFT_EXT                                  0x2016
#define WGL_GREEN_BITS_EXT                                 0x2017
#define WGL_GREEN_SHIFT_EXT                                0x2018
#define WGL_BLUE_BITS_EXT                                  0x2019
#define WGL_BLUE_SHIFT_EXT                                 0x201A
#define WGL_ALPHA_BITS_EXT                                 0x201B
#define WGL_ALPHA_SHIFT_EXT                                0x201C
#define WGL_ACCUM_BITS_EXT                                 0x201D
#define WGL_ACCUM_RED_BITS_EXT                             0x201E
#define WGL_ACCUM_GREEN_BITS_EXT                           0x201F
#define WGL_ACCUM_BLUE_BITS_EXT                            0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT                           0x2021
#define WGL_DEPTH_BITS_EXT                                 0x2022
#define WGL_STENCIL_BITS_EXT                               0x2023
#define WGL_AUX_BUFFERS_EXT                                0x2024
#define WGL_NO_ACCELERATION_EXT                            0x2025
#define WGL_GENERIC_ACCELERATION_EXT                       0x2026
#define WGL_FULL_ACCELERATION_EXT                          0x2027
#define WGL_SWAP_EXCHANGE_EXT                              0x2028
#define WGL_SWAP_COPY_EXT                                  0x2029
#define WGL_SWAP_UNDEFINED_EXT                             0x202A
#define WGL_TYPE_RGBA_EXT                                  0x202B
#define WGL_TYPE_COLORINDEX_EXT                            0x202C
#ifndef GLEE_H_DEFINED_wglGetPixelFormatAttribivEXT
#define GLEE_H_DEFINED_wglGetPixelFormatAttribivEXT
  typedef BOOL (APIENTRYP GLEEPFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues);
  GLEE_EXTERN GLEEPFNWGLGETPIXELFORMATATTRIBIVEXTPROC GLeeFuncPtr_wglGetPixelFormatAttribivEXT;
  #define wglGetPixelFormatAttribivEXT GLeeFuncPtr_wglGetPixelFormatAttribivEXT
#endif
#ifndef GLEE_H_DEFINED_wglGetPixelFormatAttribfvEXT
#define GLEE_H_DEFINED_wglGetPixelFormatAttribfvEXT
  typedef BOOL (APIENTRYP GLEEPFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues);
  GLEE_EXTERN GLEEPFNWGLGETPIXELFORMATATTRIBFVEXTPROC GLeeFuncPtr_wglGetPixelFormatAttribfvEXT;
  #define wglGetPixelFormatAttribfvEXT GLeeFuncPtr_wglGetPixelFormatAttribfvEXT
#endif
#ifndef GLEE_H_DEFINED_wglChoosePixelFormatEXT
#define GLEE_H_DEFINED_wglChoosePixelFormatEXT
  typedef BOOL (APIENTRYP GLEEPFNWGLCHOOSEPIXELFORMATEXTPROC) (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);
  GLEE_EXTERN GLEEPFNWGLCHOOSEPIXELFORMATEXTPROC GLeeFuncPtr_wglChoosePixelFormatEXT;
  #define wglChoosePixelFormatEXT GLeeFuncPtr_wglChoosePixelFormatEXT
#endif
#endif

/* WGL_EXT_pbuffer */

#ifndef WGL_EXT_pbuffer
#define WGL_EXT_pbuffer 1
#define __GLEE_WGL_EXT_pbuffer 1
/* Constants */
#define WGL_DRAW_TO_PBUFFER_EXT                            0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT                         0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT                          0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT                         0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT                      0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT                     0x2032
#define WGL_PBUFFER_LARGEST_EXT                            0x2033
#define WGL_PBUFFER_WIDTH_EXT                              0x2034
#define WGL_PBUFFER_HEIGHT_EXT                             0x2035
#ifndef GLEE_H_DEFINED_wglCreatePbufferEXT
#define GLEE_H_DEFINED_wglCreatePbufferEXT
  typedef HPBUFFEREXT (APIENTRYP GLEEPFNWGLCREATEPBUFFEREXTPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
  GLEE_EXTERN GLEEPFNWGLCREATEPBUFFEREXTPROC GLeeFuncPtr_wglCreatePbufferEXT;
  #define wglCreatePbufferEXT GLeeFuncPtr_wglCreatePbufferEXT
#endif
#ifndef GLEE_H_DEFINED_wglGetPbufferDCEXT
#define GLEE_H_DEFINED_wglGetPbufferDCEXT
  typedef HDC (APIENTRYP GLEEPFNWGLGETPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer);
  GLEE_EXTERN GLEEPFNWGLGETPBUFFERDCEXTPROC GLeeFuncPtr_wglGetPbufferDCEXT;
  #define wglGetPbufferDCEXT GLeeFuncPtr_wglGetPbufferDCEXT
#endif
#ifndef GLEE_H_DEFINED_wglReleasePbufferDCEXT
#define GLEE_H_DEFINED_wglReleasePbufferDCEXT
  typedef int (APIENTRYP GLEEPFNWGLRELEASEPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer, HDC hDC);
  GLEE_EXTERN GLEEPFNWGLRELEASEPBUFFERDCEXTPROC GLeeFuncPtr_wglReleasePbufferDCEXT;
  #define wglReleasePbufferDCEXT GLeeFuncPtr_wglReleasePbufferDCEXT
#endif
#ifndef GLEE_H_DEFINED_wglDestroyPbufferEXT
#define GLEE_H_DEFINED_wglDestroyPbufferEXT
  typedef BOOL (APIENTRYP GLEEPFNWGLDESTROYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer);
  GLEE_EXTERN GLEEPFNWGLDESTROYPBUFFEREXTPROC GLeeFuncPtr_wglDestroyPbufferEXT;
  #define wglDestroyPbufferEXT GLeeFuncPtr_wglDestroyPbufferEXT
#endif
#ifndef GLEE_H_DEFINED_wglQueryPbufferEXT
#define GLEE_H_DEFINED_wglQueryPbufferEXT
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer, int iAttribute, int * piValue);
  GLEE_EXTERN GLEEPFNWGLQUERYPBUFFEREXTPROC GLeeFuncPtr_wglQueryPbufferEXT;
  #define wglQueryPbufferEXT GLeeFuncPtr_wglQueryPbufferEXT
#endif
#endif

/* WGL_EXT_depth_float */

#ifndef WGL_EXT_depth_float
#define WGL_EXT_depth_float 1
#define __GLEE_WGL_EXT_depth_float 1
/* Constants */
#define WGL_DEPTH_FLOAT_EXT                                0x2040
#endif

/* WGL_3DFX_multisample */

#ifndef WGL_3DFX_multisample
#define WGL_3DFX_multisample 1
#define __GLEE_WGL_3DFX_multisample 1
/* Constants */
#define WGL_SAMPLE_BUFFERS_3DFX                            0x2060
#define WGL_SAMPLES_3DFX                                   0x2061
#endif

/* WGL_EXT_multisample */

#ifndef WGL_EXT_multisample
#define WGL_EXT_multisample 1
#define __GLEE_WGL_EXT_multisample 1
/* Constants */
#define WGL_SAMPLE_BUFFERS_EXT                             0x2041
#define WGL_SAMPLES_EXT                                    0x2042
#endif

/* WGL_I3D_digital_video_control */

#ifndef WGL_I3D_digital_video_control
#define WGL_I3D_digital_video_control 1
#define __GLEE_WGL_I3D_digital_video_control 1
/* Constants */
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D     0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D           0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D              0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D              0x2053
#ifndef GLEE_H_DEFINED_wglGetDigitalVideoParametersI3D
#define GLEE_H_DEFINED_wglGetDigitalVideoParametersI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int * piValue);
  GLEE_EXTERN GLEEPFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC GLeeFuncPtr_wglGetDigitalVideoParametersI3D;
  #define wglGetDigitalVideoParametersI3D GLeeFuncPtr_wglGetDigitalVideoParametersI3D
#endif
#ifndef GLEE_H_DEFINED_wglSetDigitalVideoParametersI3D
#define GLEE_H_DEFINED_wglSetDigitalVideoParametersI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int * piValue);
  GLEE_EXTERN GLEEPFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC GLeeFuncPtr_wglSetDigitalVideoParametersI3D;
  #define wglSetDigitalVideoParametersI3D GLeeFuncPtr_wglSetDigitalVideoParametersI3D
#endif
#endif

/* WGL_I3D_gamma */

#ifndef WGL_I3D_gamma
#define WGL_I3D_gamma 1
#define __GLEE_WGL_I3D_gamma 1
/* Constants */
#define WGL_GAMMA_TABLE_SIZE_I3D                           0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D                      0x204F
#ifndef GLEE_H_DEFINED_wglGetGammaTableParametersI3D
#define GLEE_H_DEFINED_wglGetGammaTableParametersI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int * piValue);
  GLEE_EXTERN GLEEPFNWGLGETGAMMATABLEPARAMETERSI3DPROC GLeeFuncPtr_wglGetGammaTableParametersI3D;
  #define wglGetGammaTableParametersI3D GLeeFuncPtr_wglGetGammaTableParametersI3D
#endif
#ifndef GLEE_H_DEFINED_wglSetGammaTableParametersI3D
#define GLEE_H_DEFINED_wglSetGammaTableParametersI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int * piValue);
  GLEE_EXTERN GLEEPFNWGLSETGAMMATABLEPARAMETERSI3DPROC GLeeFuncPtr_wglSetGammaTableParametersI3D;
  #define wglSetGammaTableParametersI3D GLeeFuncPtr_wglSetGammaTableParametersI3D
#endif
#ifndef GLEE_H_DEFINED_wglGetGammaTableI3D
#define GLEE_H_DEFINED_wglGetGammaTableI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue);
  GLEE_EXTERN GLEEPFNWGLGETGAMMATABLEI3DPROC GLeeFuncPtr_wglGetGammaTableI3D;
  #define wglGetGammaTableI3D GLeeFuncPtr_wglGetGammaTableI3D
#endif
#ifndef GLEE_H_DEFINED_wglSetGammaTableI3D
#define GLEE_H_DEFINED_wglSetGammaTableI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLSETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue);
  GLEE_EXTERN GLEEPFNWGLSETGAMMATABLEI3DPROC GLeeFuncPtr_wglSetGammaTableI3D;
  #define wglSetGammaTableI3D GLeeFuncPtr_wglSetGammaTableI3D
#endif
#endif

/* WGL_I3D_genlock */

#ifndef WGL_I3D_genlock
#define WGL_I3D_genlock 1
#define __GLEE_WGL_I3D_genlock 1
/* Constants */
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D                   0x2044
#define WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D                0x2045
#define WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D               0x2046
#define WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D                 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D                0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D               0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D                0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D                 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D                   0x204C
#ifndef GLEE_H_DEFINED_wglEnableGenlockI3D
#define GLEE_H_DEFINED_wglEnableGenlockI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLENABLEGENLOCKI3DPROC) (HDC hDC);
  GLEE_EXTERN GLEEPFNWGLENABLEGENLOCKI3DPROC GLeeFuncPtr_wglEnableGenlockI3D;
  #define wglEnableGenlockI3D GLeeFuncPtr_wglEnableGenlockI3D
#endif
#ifndef GLEE_H_DEFINED_wglDisableGenlockI3D
#define GLEE_H_DEFINED_wglDisableGenlockI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLDISABLEGENLOCKI3DPROC) (HDC hDC);
  GLEE_EXTERN GLEEPFNWGLDISABLEGENLOCKI3DPROC GLeeFuncPtr_wglDisableGenlockI3D;
  #define wglDisableGenlockI3D GLeeFuncPtr_wglDisableGenlockI3D
#endif
#ifndef GLEE_H_DEFINED_wglIsEnabledGenlockI3D
#define GLEE_H_DEFINED_wglIsEnabledGenlockI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLISENABLEDGENLOCKI3DPROC) (HDC hDC, BOOL * pFlag);
  GLEE_EXTERN GLEEPFNWGLISENABLEDGENLOCKI3DPROC GLeeFuncPtr_wglIsEnabledGenlockI3D;
  #define wglIsEnabledGenlockI3D GLeeFuncPtr_wglIsEnabledGenlockI3D
#endif
#ifndef GLEE_H_DEFINED_wglGenlockSourceI3D
#define GLEE_H_DEFINED_wglGenlockSourceI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGENLOCKSOURCEI3DPROC) (HDC hDC, UINT uSource);
  GLEE_EXTERN GLEEPFNWGLGENLOCKSOURCEI3DPROC GLeeFuncPtr_wglGenlockSourceI3D;
  #define wglGenlockSourceI3D GLeeFuncPtr_wglGenlockSourceI3D
#endif
#ifndef GLEE_H_DEFINED_wglGetGenlockSourceI3D
#define GLEE_H_DEFINED_wglGetGenlockSourceI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETGENLOCKSOURCEI3DPROC) (HDC hDC, UINT * uSource);
  GLEE_EXTERN GLEEPFNWGLGETGENLOCKSOURCEI3DPROC GLeeFuncPtr_wglGetGenlockSourceI3D;
  #define wglGetGenlockSourceI3D GLeeFuncPtr_wglGetGenlockSourceI3D
#endif
#ifndef GLEE_H_DEFINED_wglGenlockSourceEdgeI3D
#define GLEE_H_DEFINED_wglGenlockSourceEdgeI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT uEdge);
  GLEE_EXTERN GLEEPFNWGLGENLOCKSOURCEEDGEI3DPROC GLeeFuncPtr_wglGenlockSourceEdgeI3D;
  #define wglGenlockSourceEdgeI3D GLeeFuncPtr_wglGenlockSourceEdgeI3D
#endif
#ifndef GLEE_H_DEFINED_wglGetGenlockSourceEdgeI3D
#define GLEE_H_DEFINED_wglGetGenlockSourceEdgeI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT * uEdge);
  GLEE_EXTERN GLEEPFNWGLGETGENLOCKSOURCEEDGEI3DPROC GLeeFuncPtr_wglGetGenlockSourceEdgeI3D;
  #define wglGetGenlockSourceEdgeI3D GLeeFuncPtr_wglGetGenlockSourceEdgeI3D
#endif
#ifndef GLEE_H_DEFINED_wglGenlockSampleRateI3D
#define GLEE_H_DEFINED_wglGenlockSampleRateI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT uRate);
  GLEE_EXTERN GLEEPFNWGLGENLOCKSAMPLERATEI3DPROC GLeeFuncPtr_wglGenlockSampleRateI3D;
  #define wglGenlockSampleRateI3D GLeeFuncPtr_wglGenlockSampleRateI3D
#endif
#ifndef GLEE_H_DEFINED_wglGetGenlockSampleRateI3D
#define GLEE_H_DEFINED_wglGetGenlockSampleRateI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT * uRate);
  GLEE_EXTERN GLEEPFNWGLGETGENLOCKSAMPLERATEI3DPROC GLeeFuncPtr_wglGetGenlockSampleRateI3D;
  #define wglGetGenlockSampleRateI3D GLeeFuncPtr_wglGetGenlockSampleRateI3D
#endif
#ifndef GLEE_H_DEFINED_wglGenlockSourceDelayI3D
#define GLEE_H_DEFINED_wglGenlockSourceDelayI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT uDelay);
  GLEE_EXTERN GLEEPFNWGLGENLOCKSOURCEDELAYI3DPROC GLeeFuncPtr_wglGenlockSourceDelayI3D;
  #define wglGenlockSourceDelayI3D GLeeFuncPtr_wglGenlockSourceDelayI3D
#endif
#ifndef GLEE_H_DEFINED_wglGetGenlockSourceDelayI3D
#define GLEE_H_DEFINED_wglGetGenlockSourceDelayI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT * uDelay);
  GLEE_EXTERN GLEEPFNWGLGETGENLOCKSOURCEDELAYI3DPROC GLeeFuncPtr_wglGetGenlockSourceDelayI3D;
  #define wglGetGenlockSourceDelayI3D GLeeFuncPtr_wglGetGenlockSourceDelayI3D
#endif
#ifndef GLEE_H_DEFINED_wglQueryGenlockMaxSourceDelayI3D
#define GLEE_H_DEFINED_wglQueryGenlockMaxSourceDelayI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay);
  GLEE_EXTERN GLEEPFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC GLeeFuncPtr_wglQueryGenlockMaxSourceDelayI3D;
  #define wglQueryGenlockMaxSourceDelayI3D GLeeFuncPtr_wglQueryGenlockMaxSourceDelayI3D
#endif
#endif

/* WGL_I3D_image_buffer */

#ifndef WGL_I3D_image_buffer
#define WGL_I3D_image_buffer 1
#define __GLEE_WGL_I3D_image_buffer 1
/* Constants */
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D                    0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D                          0x00000002
#ifndef GLEE_H_DEFINED_wglCreateImageBufferI3D
#define GLEE_H_DEFINED_wglCreateImageBufferI3D
  typedef LPVOID (APIENTRYP GLEEPFNWGLCREATEIMAGEBUFFERI3DPROC) (HDC hDC, DWORD dwSize, UINT uFlags);
  GLEE_EXTERN GLEEPFNWGLCREATEIMAGEBUFFERI3DPROC GLeeFuncPtr_wglCreateImageBufferI3D;
  #define wglCreateImageBufferI3D GLeeFuncPtr_wglCreateImageBufferI3D
#endif
#ifndef GLEE_H_DEFINED_wglDestroyImageBufferI3D
#define GLEE_H_DEFINED_wglDestroyImageBufferI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLDESTROYIMAGEBUFFERI3DPROC) (HDC hDC, LPVOID pAddress);
  GLEE_EXTERN GLEEPFNWGLDESTROYIMAGEBUFFERI3DPROC GLeeFuncPtr_wglDestroyImageBufferI3D;
  #define wglDestroyImageBufferI3D GLeeFuncPtr_wglDestroyImageBufferI3D
#endif
#ifndef GLEE_H_DEFINED_wglAssociateImageBufferEventsI3D
#define GLEE_H_DEFINED_wglAssociateImageBufferEventsI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count);
  GLEE_EXTERN GLEEPFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC GLeeFuncPtr_wglAssociateImageBufferEventsI3D;
  #define wglAssociateImageBufferEventsI3D GLeeFuncPtr_wglAssociateImageBufferEventsI3D
#endif
#ifndef GLEE_H_DEFINED_wglReleaseImageBufferEventsI3D
#define GLEE_H_DEFINED_wglReleaseImageBufferEventsI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const LPVOID * pAddress, UINT count);
  GLEE_EXTERN GLEEPFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC GLeeFuncPtr_wglReleaseImageBufferEventsI3D;
  #define wglReleaseImageBufferEventsI3D GLeeFuncPtr_wglReleaseImageBufferEventsI3D
#endif
#endif

/* WGL_I3D_swap_frame_lock */

#ifndef WGL_I3D_swap_frame_lock
#define WGL_I3D_swap_frame_lock 1
#define __GLEE_WGL_I3D_swap_frame_lock 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglEnableFrameLockI3D
#define GLEE_H_DEFINED_wglEnableFrameLockI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLENABLEFRAMELOCKI3DPROC) ();
  GLEE_EXTERN GLEEPFNWGLENABLEFRAMELOCKI3DPROC GLeeFuncPtr_wglEnableFrameLockI3D;
  #define wglEnableFrameLockI3D GLeeFuncPtr_wglEnableFrameLockI3D
#endif
#ifndef GLEE_H_DEFINED_wglDisableFrameLockI3D
#define GLEE_H_DEFINED_wglDisableFrameLockI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLDISABLEFRAMELOCKI3DPROC) ();
  GLEE_EXTERN GLEEPFNWGLDISABLEFRAMELOCKI3DPROC GLeeFuncPtr_wglDisableFrameLockI3D;
  #define wglDisableFrameLockI3D GLeeFuncPtr_wglDisableFrameLockI3D
#endif
#ifndef GLEE_H_DEFINED_wglIsEnabledFrameLockI3D
#define GLEE_H_DEFINED_wglIsEnabledFrameLockI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLISENABLEDFRAMELOCKI3DPROC) (BOOL * pFlag);
  GLEE_EXTERN GLEEPFNWGLISENABLEDFRAMELOCKI3DPROC GLeeFuncPtr_wglIsEnabledFrameLockI3D;
  #define wglIsEnabledFrameLockI3D GLeeFuncPtr_wglIsEnabledFrameLockI3D
#endif
#ifndef GLEE_H_DEFINED_wglQueryFrameLockMasterI3D
#define GLEE_H_DEFINED_wglQueryFrameLockMasterI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYFRAMELOCKMASTERI3DPROC) (BOOL * pFlag);
  GLEE_EXTERN GLEEPFNWGLQUERYFRAMELOCKMASTERI3DPROC GLeeFuncPtr_wglQueryFrameLockMasterI3D;
  #define wglQueryFrameLockMasterI3D GLeeFuncPtr_wglQueryFrameLockMasterI3D
#endif
#endif

/* WGL_NV_render_depth_texture */

#ifndef WGL_NV_render_depth_texture
#define WGL_NV_render_depth_texture 1
#define __GLEE_WGL_NV_render_depth_texture 1
/* Constants */
#define WGL_BIND_TO_TEXTURE_DEPTH_NV                       0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV             0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV                        0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV                     0x20A6
#define WGL_DEPTH_COMPONENT_NV                             0x20A7
#endif

/* WGL_NV_render_texture_rectangle */

#ifndef WGL_NV_render_texture_rectangle
#define WGL_NV_render_texture_rectangle 1
#define __GLEE_WGL_NV_render_texture_rectangle 1
/* Constants */
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV               0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV              0x20A1
#define WGL_TEXTURE_RECTANGLE_NV                           0x20A2
#endif

/* WGL_ATI_pixel_format_float */

#ifndef WGL_ATI_pixel_format_float
#define WGL_ATI_pixel_format_float 1
#define __GLEE_WGL_ATI_pixel_format_float 1
/* Constants */
#define WGL_TYPE_RGBA_FLOAT_ATI                            0x21A0
#endif

/* WGL_NV_float_buffer */

#ifndef WGL_NV_float_buffer
#define WGL_NV_float_buffer 1
#define __GLEE_WGL_NV_float_buffer 1
/* Constants */
#define WGL_FLOAT_COMPONENTS_NV                            0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV           0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV          0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV         0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV        0x20B4
#define WGL_TEXTURE_FLOAT_R_NV                             0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV                            0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV                           0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV                          0x20B8
#endif

/* WGL_3DL_stereo_control */

#ifndef WGL_3DL_stereo_control
#define WGL_3DL_stereo_control 1
#define __GLEE_WGL_3DL_stereo_control 1
/* Constants */
#define WGL_STEREO_EMITTER_ENABLE_3DL                      0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL                     0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL                     0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL                     0x2058
#endif

/* WGL_EXT_pixel_format_packed_float */

#ifndef WGL_EXT_pixel_format_packed_float
#define WGL_EXT_pixel_format_packed_float 1
#define __GLEE_WGL_EXT_pixel_format_packed_float 1
/* Constants */
#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT                   0x20A8
#endif

/* WGL_EXT_framebuffer_sRGB */

#ifndef WGL_EXT_framebuffer_sRGB
#define WGL_EXT_framebuffer_sRGB 1
#define __GLEE_WGL_EXT_framebuffer_sRGB 1
/* Constants */
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT                   0x20A9
#endif

/* WGL_NV_present_video */

#ifndef WGL_NV_present_video
#define WGL_NV_present_video 1
#define __GLEE_WGL_NV_present_video 1
/* Constants */
#define WGL_NUM_VIDEO_SLOTS_NV                             0x20F0
#ifndef GLEE_H_DEFINED_wglEnumerateVideoDevicesNV
#define GLEE_H_DEFINED_wglEnumerateVideoDevicesNV
  typedef int (APIENTRYP GLEEPFNWGLENUMERATEVIDEODEVICESNVPROC) (HDC hDC, HVIDEOOUTPUTDEVICENV * phDeviceList);
  GLEE_EXTERN GLEEPFNWGLENUMERATEVIDEODEVICESNVPROC GLeeFuncPtr_wglEnumerateVideoDevicesNV;
  #define wglEnumerateVideoDevicesNV GLeeFuncPtr_wglEnumerateVideoDevicesNV
#endif
#ifndef GLEE_H_DEFINED_wglBindVideoDeviceNV
#define GLEE_H_DEFINED_wglBindVideoDeviceNV
  typedef BOOL (APIENTRYP GLEEPFNWGLBINDVIDEODEVICENVPROC) (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int * piAttribList);
  GLEE_EXTERN GLEEPFNWGLBINDVIDEODEVICENVPROC GLeeFuncPtr_wglBindVideoDeviceNV;
  #define wglBindVideoDeviceNV GLeeFuncPtr_wglBindVideoDeviceNV
#endif
#ifndef GLEE_H_DEFINED_wglQueryCurrentContextNV
#define GLEE_H_DEFINED_wglQueryCurrentContextNV
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYCURRENTCONTEXTNVPROC) (int iAttribute, int * piValue);
  GLEE_EXTERN GLEEPFNWGLQUERYCURRENTCONTEXTNVPROC GLeeFuncPtr_wglQueryCurrentContextNV;
  #define wglQueryCurrentContextNV GLeeFuncPtr_wglQueryCurrentContextNV
#endif
#endif

/* WGL_NV_swap_group */

#ifndef WGL_NV_swap_group
#define WGL_NV_swap_group 1
#define __GLEE_WGL_NV_swap_group 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglJoinSwapGroupNV
#define GLEE_H_DEFINED_wglJoinSwapGroupNV
  typedef BOOL (APIENTRYP GLEEPFNWGLJOINSWAPGROUPNVPROC) (HDC hDC, GLuint group);
  GLEE_EXTERN GLEEPFNWGLJOINSWAPGROUPNVPROC GLeeFuncPtr_wglJoinSwapGroupNV;
  #define wglJoinSwapGroupNV GLeeFuncPtr_wglJoinSwapGroupNV
#endif
#ifndef GLEE_H_DEFINED_wglBindSwapBarrierNV
#define GLEE_H_DEFINED_wglBindSwapBarrierNV
  typedef BOOL (APIENTRYP GLEEPFNWGLBINDSWAPBARRIERNVPROC) (GLuint group, GLuint barrier);
  GLEE_EXTERN GLEEPFNWGLBINDSWAPBARRIERNVPROC GLeeFuncPtr_wglBindSwapBarrierNV;
  #define wglBindSwapBarrierNV GLeeFuncPtr_wglBindSwapBarrierNV
#endif
#ifndef GLEE_H_DEFINED_wglQuerySwapGroupNV
#define GLEE_H_DEFINED_wglQuerySwapGroupNV
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYSWAPGROUPNVPROC) (HDC hDC, GLuint * group, GLuint * barrier);
  GLEE_EXTERN GLEEPFNWGLQUERYSWAPGROUPNVPROC GLeeFuncPtr_wglQuerySwapGroupNV;
  #define wglQuerySwapGroupNV GLeeFuncPtr_wglQuerySwapGroupNV
#endif
#ifndef GLEE_H_DEFINED_wglQueryMaxSwapGroupsNV
#define GLEE_H_DEFINED_wglQueryMaxSwapGroupsNV
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYMAXSWAPGROUPSNVPROC) (HDC hDC, GLuint * maxGroups, GLuint * maxBarriers);
  GLEE_EXTERN GLEEPFNWGLQUERYMAXSWAPGROUPSNVPROC GLeeFuncPtr_wglQueryMaxSwapGroupsNV;
  #define wglQueryMaxSwapGroupsNV GLeeFuncPtr_wglQueryMaxSwapGroupsNV
#endif
#ifndef GLEE_H_DEFINED_wglQueryFrameCountNV
#define GLEE_H_DEFINED_wglQueryFrameCountNV
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYFRAMECOUNTNVPROC) (HDC hDC, GLuint * count);
  GLEE_EXTERN GLEEPFNWGLQUERYFRAMECOUNTNVPROC GLeeFuncPtr_wglQueryFrameCountNV;
  #define wglQueryFrameCountNV GLeeFuncPtr_wglQueryFrameCountNV
#endif
#ifndef GLEE_H_DEFINED_wglResetFrameCountNV
#define GLEE_H_DEFINED_wglResetFrameCountNV
  typedef BOOL (APIENTRYP GLEEPFNWGLRESETFRAMECOUNTNVPROC) (HDC hDC);
  GLEE_EXTERN GLEEPFNWGLRESETFRAMECOUNTNVPROC GLeeFuncPtr_wglResetFrameCountNV;
  #define wglResetFrameCountNV GLeeFuncPtr_wglResetFrameCountNV
#endif
#endif

/* WGL_NV_gpu_affinity */

#ifndef WGL_NV_gpu_affinity
#define WGL_NV_gpu_affinity 1
#define __GLEE_WGL_NV_gpu_affinity 1
/* Constants */
#define WGL_ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV           0x20D0
#define WGL_ERROR_MISSING_AFFINITY_MASK_NV                 0x20D1
#ifndef GLEE_H_DEFINED_wglEnumGpusNV
#define GLEE_H_DEFINED_wglEnumGpusNV
  typedef BOOL (APIENTRYP GLEEPFNWGLENUMGPUSNVPROC) (UINT iGpuIndex, HGPUNV * phGpu);
  GLEE_EXTERN GLEEPFNWGLENUMGPUSNVPROC GLeeFuncPtr_wglEnumGpusNV;
  #define wglEnumGpusNV GLeeFuncPtr_wglEnumGpusNV
#endif
#ifndef GLEE_H_DEFINED_wglEnumGpuDevicesNV
#define GLEE_H_DEFINED_wglEnumGpuDevicesNV
  typedef BOOL (APIENTRYP GLEEPFNWGLENUMGPUDEVICESNVPROC) (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
  GLEE_EXTERN GLEEPFNWGLENUMGPUDEVICESNVPROC GLeeFuncPtr_wglEnumGpuDevicesNV;
  #define wglEnumGpuDevicesNV GLeeFuncPtr_wglEnumGpuDevicesNV
#endif
#ifndef GLEE_H_DEFINED_wglCreateAffinityDCNV
#define GLEE_H_DEFINED_wglCreateAffinityDCNV
  typedef HDC (APIENTRYP GLEEPFNWGLCREATEAFFINITYDCNVPROC) (const HGPUNV * phGpuList);
  GLEE_EXTERN GLEEPFNWGLCREATEAFFINITYDCNVPROC GLeeFuncPtr_wglCreateAffinityDCNV;
  #define wglCreateAffinityDCNV GLeeFuncPtr_wglCreateAffinityDCNV
#endif
#ifndef GLEE_H_DEFINED_wglEnumGpusFromAffinityDCNV
#define GLEE_H_DEFINED_wglEnumGpusFromAffinityDCNV
  typedef BOOL (APIENTRYP GLEEPFNWGLENUMGPUSFROMAFFINITYDCNVPROC) (HDC hAffinityDC, UINT iGpuIndex, HGPUNV * hGpu);
  GLEE_EXTERN GLEEPFNWGLENUMGPUSFROMAFFINITYDCNVPROC GLeeFuncPtr_wglEnumGpusFromAffinityDCNV;
  #define wglEnumGpusFromAffinityDCNV GLeeFuncPtr_wglEnumGpusFromAffinityDCNV
#endif
#ifndef GLEE_H_DEFINED_wglDeleteDCNV
#define GLEE_H_DEFINED_wglDeleteDCNV
  typedef BOOL (APIENTRYP GLEEPFNWGLDELETEDCNVPROC) (HDC hdc);
  GLEE_EXTERN GLEEPFNWGLDELETEDCNVPROC GLeeFuncPtr_wglDeleteDCNV;
  #define wglDeleteDCNV GLeeFuncPtr_wglDeleteDCNV
#endif
#endif

/* WGL_EXT_display_color_table */

#ifndef WGL_EXT_display_color_table
#define WGL_EXT_display_color_table 1
#define __GLEE_WGL_EXT_display_color_table 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglCreateDisplayColorTableEXT
#define GLEE_H_DEFINED_wglCreateDisplayColorTableEXT
  typedef GLboolean (APIENTRYP GLEEPFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (GLushort id);
  GLEE_EXTERN GLEEPFNWGLCREATEDISPLAYCOLORTABLEEXTPROC GLeeFuncPtr_wglCreateDisplayColorTableEXT;
  #define wglCreateDisplayColorTableEXT GLeeFuncPtr_wglCreateDisplayColorTableEXT
#endif
#ifndef GLEE_H_DEFINED_wglLoadDisplayColorTableEXT
#define GLEE_H_DEFINED_wglLoadDisplayColorTableEXT
  typedef GLboolean (APIENTRYP GLEEPFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (const GLushort * table, GLuint length);
  GLEE_EXTERN GLEEPFNWGLLOADDISPLAYCOLORTABLEEXTPROC GLeeFuncPtr_wglLoadDisplayColorTableEXT;
  #define wglLoadDisplayColorTableEXT GLeeFuncPtr_wglLoadDisplayColorTableEXT
#endif
#ifndef GLEE_H_DEFINED_wglBindDisplayColorTableEXT
#define GLEE_H_DEFINED_wglBindDisplayColorTableEXT
  typedef GLboolean (APIENTRYP GLEEPFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (GLushort id);
  GLEE_EXTERN GLEEPFNWGLBINDDISPLAYCOLORTABLEEXTPROC GLeeFuncPtr_wglBindDisplayColorTableEXT;
  #define wglBindDisplayColorTableEXT GLeeFuncPtr_wglBindDisplayColorTableEXT
#endif
#ifndef GLEE_H_DEFINED_wglDestroyDisplayColorTableEXT
#define GLEE_H_DEFINED_wglDestroyDisplayColorTableEXT
  typedef VOID (APIENTRYP GLEEPFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (GLushort id);
  GLEE_EXTERN GLEEPFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC GLeeFuncPtr_wglDestroyDisplayColorTableEXT;
  #define wglDestroyDisplayColorTableEXT GLeeFuncPtr_wglDestroyDisplayColorTableEXT
#endif
#endif

/* WGL_EXT_extensions_string */

#ifndef WGL_EXT_extensions_string
#define WGL_EXT_extensions_string 1
#define __GLEE_WGL_EXT_extensions_string 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglGetExtensionsStringEXT
#define GLEE_H_DEFINED_wglGetExtensionsStringEXT
  typedef const char * (APIENTRYP GLEEPFNWGLGETEXTENSIONSSTRINGEXTPROC) ();
  GLEE_EXTERN GLEEPFNWGLGETEXTENSIONSSTRINGEXTPROC GLeeFuncPtr_wglGetExtensionsStringEXT;
  #define wglGetExtensionsStringEXT GLeeFuncPtr_wglGetExtensionsStringEXT
#endif
#endif

/* WGL_EXT_swap_control */

#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1
#define __GLEE_WGL_EXT_swap_control 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglSwapIntervalEXT
#define GLEE_H_DEFINED_wglSwapIntervalEXT
  typedef BOOL (APIENTRYP GLEEPFNWGLSWAPINTERVALEXTPROC) (int interval);
  GLEE_EXTERN GLEEPFNWGLSWAPINTERVALEXTPROC GLeeFuncPtr_wglSwapIntervalEXT;
  #define wglSwapIntervalEXT GLeeFuncPtr_wglSwapIntervalEXT
#endif
#ifndef GLEE_H_DEFINED_wglGetSwapIntervalEXT
#define GLEE_H_DEFINED_wglGetSwapIntervalEXT
  typedef int (APIENTRYP GLEEPFNWGLGETSWAPINTERVALEXTPROC) ();
  GLEE_EXTERN GLEEPFNWGLGETSWAPINTERVALEXTPROC GLeeFuncPtr_wglGetSwapIntervalEXT;
  #define wglGetSwapIntervalEXT GLeeFuncPtr_wglGetSwapIntervalEXT
#endif
#endif

/* WGL_NV_vertex_array_range */

#ifndef WGL_NV_vertex_array_range
#define WGL_NV_vertex_array_range 1
#define __GLEE_WGL_NV_vertex_array_range 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglAllocateMemoryNV
#define GLEE_H_DEFINED_wglAllocateMemoryNV
  typedef void* (APIENTRYP GLEEPFNWGLALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
  GLEE_EXTERN GLEEPFNWGLALLOCATEMEMORYNVPROC GLeeFuncPtr_wglAllocateMemoryNV;
  #define wglAllocateMemoryNV GLeeFuncPtr_wglAllocateMemoryNV
#endif
#ifndef GLEE_H_DEFINED_wglFreeMemoryNV
#define GLEE_H_DEFINED_wglFreeMemoryNV
  typedef void (APIENTRYP GLEEPFNWGLFREEMEMORYNVPROC) (void * pointer);
  GLEE_EXTERN GLEEPFNWGLFREEMEMORYNVPROC GLeeFuncPtr_wglFreeMemoryNV;
  #define wglFreeMemoryNV GLeeFuncPtr_wglFreeMemoryNV
#endif
#endif

/* WGL_OML_sync_control */

#ifndef WGL_OML_sync_control
#define WGL_OML_sync_control 1
#define __GLEE_WGL_OML_sync_control 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglGetSyncValuesOML
#define GLEE_H_DEFINED_wglGetSyncValuesOML
  typedef BOOL (APIENTRYP GLEEPFNWGLGETSYNCVALUESOMLPROC) (HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc);
  GLEE_EXTERN GLEEPFNWGLGETSYNCVALUESOMLPROC GLeeFuncPtr_wglGetSyncValuesOML;
  #define wglGetSyncValuesOML GLeeFuncPtr_wglGetSyncValuesOML
#endif
#ifndef GLEE_H_DEFINED_wglGetMscRateOML
#define GLEE_H_DEFINED_wglGetMscRateOML
  typedef BOOL (APIENTRYP GLEEPFNWGLGETMSCRATEOMLPROC) (HDC hdc, INT32 * numerator, INT32 * denominator);
  GLEE_EXTERN GLEEPFNWGLGETMSCRATEOMLPROC GLeeFuncPtr_wglGetMscRateOML;
  #define wglGetMscRateOML GLeeFuncPtr_wglGetMscRateOML
#endif
#ifndef GLEE_H_DEFINED_wglSwapBuffersMscOML
#define GLEE_H_DEFINED_wglSwapBuffersMscOML
  typedef INT64 (APIENTRYP GLEEPFNWGLSWAPBUFFERSMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
  GLEE_EXTERN GLEEPFNWGLSWAPBUFFERSMSCOMLPROC GLeeFuncPtr_wglSwapBuffersMscOML;
  #define wglSwapBuffersMscOML GLeeFuncPtr_wglSwapBuffersMscOML
#endif
#ifndef GLEE_H_DEFINED_wglSwapLayerBuffersMscOML
#define GLEE_H_DEFINED_wglSwapLayerBuffersMscOML
  typedef INT64 (APIENTRYP GLEEPFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
  GLEE_EXTERN GLEEPFNWGLSWAPLAYERBUFFERSMSCOMLPROC GLeeFuncPtr_wglSwapLayerBuffersMscOML;
  #define wglSwapLayerBuffersMscOML GLeeFuncPtr_wglSwapLayerBuffersMscOML
#endif
#ifndef GLEE_H_DEFINED_wglWaitForMscOML
#define GLEE_H_DEFINED_wglWaitForMscOML
  typedef BOOL (APIENTRYP GLEEPFNWGLWAITFORMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc);
  GLEE_EXTERN GLEEPFNWGLWAITFORMSCOMLPROC GLeeFuncPtr_wglWaitForMscOML;
  #define wglWaitForMscOML GLeeFuncPtr_wglWaitForMscOML
#endif
#ifndef GLEE_H_DEFINED_wglWaitForSbcOML
#define GLEE_H_DEFINED_wglWaitForSbcOML
  typedef BOOL (APIENTRYP GLEEPFNWGLWAITFORSBCOMLPROC) (HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc);
  GLEE_EXTERN GLEEPFNWGLWAITFORSBCOMLPROC GLeeFuncPtr_wglWaitForSbcOML;
  #define wglWaitForSbcOML GLeeFuncPtr_wglWaitForSbcOML
#endif
#endif

/* WGL_I3D_swap_frame_usage */

#ifndef WGL_I3D_swap_frame_usage
#define WGL_I3D_swap_frame_usage 1
#define __GLEE_WGL_I3D_swap_frame_usage 1
/* Constants */
#ifndef GLEE_H_DEFINED_wglGetFrameUsageI3D
#define GLEE_H_DEFINED_wglGetFrameUsageI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLGETFRAMEUSAGEI3DPROC) (float * pUsage);
  GLEE_EXTERN GLEEPFNWGLGETFRAMEUSAGEI3DPROC GLeeFuncPtr_wglGetFrameUsageI3D;
  #define wglGetFrameUsageI3D GLeeFuncPtr_wglGetFrameUsageI3D
#endif
#ifndef GLEE_H_DEFINED_wglBeginFrameTrackingI3D
#define GLEE_H_DEFINED_wglBeginFrameTrackingI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLBEGINFRAMETRACKINGI3DPROC) ();
  GLEE_EXTERN GLEEPFNWGLBEGINFRAMETRACKINGI3DPROC GLeeFuncPtr_wglBeginFrameTrackingI3D;
  #define wglBeginFrameTrackingI3D GLeeFuncPtr_wglBeginFrameTrackingI3D
#endif
#ifndef GLEE_H_DEFINED_wglEndFrameTrackingI3D
#define GLEE_H_DEFINED_wglEndFrameTrackingI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLENDFRAMETRACKINGI3DPROC) ();
  GLEE_EXTERN GLEEPFNWGLENDFRAMETRACKINGI3DPROC GLeeFuncPtr_wglEndFrameTrackingI3D;
  #define wglEndFrameTrackingI3D GLeeFuncPtr_wglEndFrameTrackingI3D
#endif
#ifndef GLEE_H_DEFINED_wglQueryFrameTrackingI3D
#define GLEE_H_DEFINED_wglQueryFrameTrackingI3D
  typedef BOOL (APIENTRYP GLEEPFNWGLQUERYFRAMETRACKINGI3DPROC) (DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage);
  GLEE_EXTERN GLEEPFNWGLQUERYFRAMETRACKINGI3DPROC GLeeFuncPtr_wglQueryFrameTrackingI3D;
  #define wglQueryFrameTrackingI3D GLeeFuncPtr_wglQueryFrameTrackingI3D
#endif
#endif

/* WGL_NV_video_output */

#ifndef WGL_NV_video_output
#define WGL_NV_video_output 1
#define __GLEE_WGL_NV_video_output 1
/* Constants */
#define WGL_BIND_TO_VIDEO_RGB_NV                           0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV                          0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV                 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV                             0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV                             0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV                             0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV                   0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV                   0x20C7
#define WGL_VIDEO_OUT_FRAME                                0x20C8
#define WGL_VIDEO_OUT_FIELD_1                              0x20C9
#define WGL_VIDEO_OUT_FIELD_2                              0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2                   0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1                   0x20CC
#ifndef GLEE_H_DEFINED_wglGetVideoDeviceNV
#define GLEE_H_DEFINED_wglGetVideoDeviceNV
  typedef BOOL (APIENTRYP GLEEPFNWGLGETVIDEODEVICENVPROC) (HDC hDC, int numDevices, HPVIDEODEV * hVideoDevice);
  GLEE_EXTERN GLEEPFNWGLGETVIDEODEVICENVPROC GLeeFuncPtr_wglGetVideoDeviceNV;
  #define wglGetVideoDeviceNV GLeeFuncPtr_wglGetVideoDeviceNV
#endif
#ifndef GLEE_H_DEFINED_wglReleaseVideoDeviceNV
#define GLEE_H_DEFINED_wglReleaseVideoDeviceNV
  typedef BOOL (APIENTRYP GLEEPFNWGLRELEASEVIDEODEVICENVPROC) (HPVIDEODEV hVideoDevice);
  GLEE_EXTERN GLEEPFNWGLRELEASEVIDEODEVICENVPROC GLeeFuncPtr_wglReleaseVideoDeviceNV;
  #define wglReleaseVideoDeviceNV GLeeFuncPtr_wglReleaseVideoDeviceNV
#endif
#ifndef GLEE_H_DEFINED_wglBindVideoImageNV
#define GLEE_H_DEFINED_wglBindVideoImageNV
  typedef BOOL (APIENTRYP GLEEPFNWGLBINDVIDEOIMAGENVPROC) (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
  GLEE_EXTERN GLEEPFNWGLBINDVIDEOIMAGENVPROC GLeeFuncPtr_wglBindVideoImageNV;
  #define wglBindVideoImageNV GLeeFuncPtr_wglBindVideoImageNV
#endif
#ifndef GLEE_H_DEFINED_wglReleaseVideoImageNV
#define GLEE_H_DEFINED_wglReleaseVideoImageNV
  typedef BOOL (APIENTRYP GLEEPFNWGLRELEASEVIDEOIMAGENVPROC) (HPBUFFERARB hPbuffer, int iVideoBuffer);
  GLEE_EXTERN GLEEPFNWGLRELEASEVIDEOIMAGENVPROC GLeeFuncPtr_wglReleaseVideoImageNV;
  #define wglReleaseVideoImageNV GLeeFuncPtr_wglReleaseVideoImageNV
#endif
#ifndef GLEE_H_DEFINED_wglSendPbufferToVideoNV
#define GLEE_H_DEFINED_wglSendPbufferToVideoNV
  typedef BOOL (APIENTRYP GLEEPFNWGLSENDPBUFFERTOVIDEONVPROC) (HPBUFFERARB hPbuffer, int iBufferType, unsigned long * pulCounterPbuffer, BOOL bBlock);
  GLEE_EXTERN GLEEPFNWGLSENDPBUFFERTOVIDEONVPROC GLeeFuncPtr_wglSendPbufferToVideoNV;
  #define wglSendPbufferToVideoNV GLeeFuncPtr_wglSendPbufferToVideoNV
#endif
#ifndef GLEE_H_DEFINED_wglGetVideoInfoNV
#define GLEE_H_DEFINED_wglGetVideoInfoNV
  typedef BOOL (APIENTRYP GLEEPFNWGLGETVIDEOINFONVPROC) (HPVIDEODEV hpVideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo);
  GLEE_EXTERN GLEEPFNWGLGETVIDEOINFONVPROC GLeeFuncPtr_wglGetVideoInfoNV;
  #define wglGetVideoInfoNV GLeeFuncPtr_wglGetVideoInfoNV
#endif
#endif
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else /* GLX */

/* Extension querying variables */

GLEE_EXTERN GLboolean _GLEE_GLX_VERSION_1_3;
GLEE_EXTERN GLboolean _GLEE_GLX_VERSION_1_4;
GLEE_EXTERN GLboolean _GLEE_GLX_ARB_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_ARB_fbconfig_float;
GLEE_EXTERN GLboolean _GLEE_GLX_ARB_create_context;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIS_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_visual_info;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_swap_control;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_video_sync;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_make_current_read;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_visual_rating;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_import_context;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_fbconfig;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_pbuffer;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_cushion;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_video_resize;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_swap_group;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_swap_barrier;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIS_blended_overlay;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIS_shared_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_SUN_get_transparent_index;
GLEE_EXTERN GLboolean _GLEE_GLX_3DFX_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_copy_sub_buffer;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_pixmap_colormap;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_release_buffers;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_set_3dfx_mode;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_visual_select_group;
GLEE_EXTERN GLboolean _GLEE_GLX_OML_swap_method;
GLEE_EXTERN GLboolean _GLEE_GLX_OML_sync_control;
GLEE_EXTERN GLboolean _GLEE_GLX_NV_float_buffer;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_hyperpipe;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_agp_offset;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_fbconfig_packed_float;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_framebuffer_sRGB;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_texture_from_pixmap;
GLEE_EXTERN GLboolean _GLEE_GLX_NV_present_video;
GLEE_EXTERN GLboolean _GLEE_GLX_NV_video_out;
GLEE_EXTERN GLboolean _GLEE_GLX_NV_swap_group;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_scene_marker;
GLEE_EXTERN GLboolean _GLEE_GLX_NV_video_output;

/* Aliases for extension querying variables */

#define GLEE_GLX_VERSION_1_3     GLeeEnabled(&_GLEE_GLX_VERSION_1_3)
#define GLEE_GLX_VERSION_1_4     GLeeEnabled(&_GLEE_GLX_VERSION_1_4)
#define GLEE_GLX_ARB_multisample     GLeeEnabled(&_GLEE_GLX_ARB_multisample)
#define GLEE_GLX_ARB_fbconfig_float     GLeeEnabled(&_GLEE_GLX_ARB_fbconfig_float)
#define GLEE_GLX_ARB_create_context     GLeeEnabled(&_GLEE_GLX_ARB_create_context)
#define GLEE_GLX_SGIS_multisample     GLeeEnabled(&_GLEE_GLX_SGIS_multisample)
#define GLEE_GLX_EXT_visual_info     GLeeEnabled(&_GLEE_GLX_EXT_visual_info)
#define GLEE_GLX_SGI_swap_control     GLeeEnabled(&_GLEE_GLX_SGI_swap_control)
#define GLEE_GLX_SGI_video_sync     GLeeEnabled(&_GLEE_GLX_SGI_video_sync)
#define GLEE_GLX_SGI_make_current_read     GLeeEnabled(&_GLEE_GLX_SGI_make_current_read)
#define GLEE_GLX_EXT_visual_rating     GLeeEnabled(&_GLEE_GLX_EXT_visual_rating)
#define GLEE_GLX_EXT_import_context     GLeeEnabled(&_GLEE_GLX_EXT_import_context)
#define GLEE_GLX_SGIX_fbconfig     GLeeEnabled(&_GLEE_GLX_SGIX_fbconfig)
#define GLEE_GLX_SGIX_pbuffer     GLeeEnabled(&_GLEE_GLX_SGIX_pbuffer)
#define GLEE_GLX_SGI_cushion     GLeeEnabled(&_GLEE_GLX_SGI_cushion)
#define GLEE_GLX_SGIX_video_resize     GLeeEnabled(&_GLEE_GLX_SGIX_video_resize)
#define GLEE_GLX_SGIX_swap_group     GLeeEnabled(&_GLEE_GLX_SGIX_swap_group)
#define GLEE_GLX_SGIX_swap_barrier     GLeeEnabled(&_GLEE_GLX_SGIX_swap_barrier)
#define GLEE_GLX_SGIS_blended_overlay     GLeeEnabled(&_GLEE_GLX_SGIS_blended_overlay)
#define GLEE_GLX_SGIS_shared_multisample     GLeeEnabled(&_GLEE_GLX_SGIS_shared_multisample)
#define GLEE_GLX_SUN_get_transparent_index     GLeeEnabled(&_GLEE_GLX_SUN_get_transparent_index)
#define GLEE_GLX_3DFX_multisample     GLeeEnabled(&_GLEE_GLX_3DFX_multisample)
#define GLEE_GLX_MESA_copy_sub_buffer     GLeeEnabled(&_GLEE_GLX_MESA_copy_sub_buffer)
#define GLEE_GLX_MESA_pixmap_colormap     GLeeEnabled(&_GLEE_GLX_MESA_pixmap_colormap)
#define GLEE_GLX_MESA_release_buffers     GLeeEnabled(&_GLEE_GLX_MESA_release_buffers)
#define GLEE_GLX_MESA_set_3dfx_mode     GLeeEnabled(&_GLEE_GLX_MESA_set_3dfx_mode)
#define GLEE_GLX_SGIX_visual_select_group     GLeeEnabled(&_GLEE_GLX_SGIX_visual_select_group)
#define GLEE_GLX_OML_swap_method     GLeeEnabled(&_GLEE_GLX_OML_swap_method)
#define GLEE_GLX_OML_sync_control     GLeeEnabled(&_GLEE_GLX_OML_sync_control)
#define GLEE_GLX_NV_float_buffer     GLeeEnabled(&_GLEE_GLX_NV_float_buffer)
#define GLEE_GLX_SGIX_hyperpipe     GLeeEnabled(&_GLEE_GLX_SGIX_hyperpipe)
#define GLEE_GLX_MESA_agp_offset     GLeeEnabled(&_GLEE_GLX_MESA_agp_offset)
#define GLEE_GLX_EXT_fbconfig_packed_float     GLeeEnabled(&_GLEE_GLX_EXT_fbconfig_packed_float)
#define GLEE_GLX_EXT_framebuffer_sRGB     GLeeEnabled(&_GLEE_GLX_EXT_framebuffer_sRGB)
#define GLEE_GLX_EXT_texture_from_pixmap     GLeeEnabled(&_GLEE_GLX_EXT_texture_from_pixmap)
#define GLEE_GLX_NV_present_video     GLeeEnabled(&_GLEE_GLX_NV_present_video)
#define GLEE_GLX_NV_video_out     GLeeEnabled(&_GLEE_GLX_NV_video_out)
#define GLEE_GLX_NV_swap_group     GLeeEnabled(&_GLEE_GLX_NV_swap_group)
#define GLEE_GLX_EXT_scene_marker     GLeeEnabled(&_GLEE_GLX_EXT_scene_marker)
#define GLEE_GLX_NV_video_output     GLeeEnabled(&_GLEE_GLX_NV_video_output)

/* GLX_VERSION_1_3 */

#ifndef GLX_VERSION_1_3
#define GLX_VERSION_1_3 1
#define __GLEE_GLX_VERSION_1_3 1
/* Constants */
#define GLX_WINDOW_BIT                                     0x00000001
#define GLX_PIXMAP_BIT                                     0x00000002
#define GLX_PBUFFER_BIT                                    0x00000004
#define GLX_RGBA_BIT                                       0x00000001
#define GLX_COLOR_INDEX_BIT                                0x00000002
#define GLX_PBUFFER_CLOBBER_MASK                           0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT                          0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT                         0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT                           0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT                          0x00000008
#define GLX_AUX_BUFFERS_BIT                                0x00000010
#define GLX_DEPTH_BUFFER_BIT                               0x00000020
#define GLX_STENCIL_BUFFER_BIT                             0x00000040
#define GLX_ACCUM_BUFFER_BIT                               0x00000080
#define GLX_CONFIG_CAVEAT                                  0x20
#define GLX_X_VISUAL_TYPE                                  0x22
#define GLX_TRANSPARENT_TYPE                               0x23
#define GLX_TRANSPARENT_INDEX_VALUE                        0x24
#define GLX_TRANSPARENT_RED_VALUE                          0x25
#define GLX_TRANSPARENT_GREEN_VALUE                        0x26
#define GLX_TRANSPARENT_BLUE_VALUE                         0x27
#define GLX_TRANSPARENT_ALPHA_VALUE                        0x28
#define GLX_DONT_CARE                                      0xFFFFFFFF
#define GLX_NONE                                           0x8000
#define GLX_SLOW_CONFIG                                    0x8001
#define GLX_TRUE_COLOR                                     0x8002
#define GLX_DIRECT_COLOR                                   0x8003
#define GLX_PSEUDO_COLOR                                   0x8004
#define GLX_STATIC_COLOR                                   0x8005
#define GLX_GRAY_SCALE                                     0x8006
#define GLX_STATIC_GRAY                                    0x8007
#define GLX_TRANSPARENT_RGB                                0x8008
#define GLX_TRANSPARENT_INDEX                              0x8009
#define GLX_VISUAL_ID                                      0x800B
#define GLX_SCREEN                                         0x800C
#define GLX_NON_CONFORMANT_CONFIG                          0x800D
#define GLX_DRAWABLE_TYPE                                  0x8010
#define GLX_RENDER_TYPE                                    0x8011
#define GLX_X_RENDERABLE                                   0x8012
#define GLX_FBCONFIG_ID                                    0x8013
#define GLX_RGBA_TYPE                                      0x8014
#define GLX_COLOR_INDEX_TYPE                               0x8015
#define GLX_MAX_PBUFFER_WIDTH                              0x8016
#define GLX_MAX_PBUFFER_HEIGHT                             0x8017
#define GLX_MAX_PBUFFER_PIXELS                             0x8018
#define GLX_PRESERVED_CONTENTS                             0x801B
#define GLX_LARGEST_PBUFFER                                0x801C
#define GLX_WIDTH                                          0x801D
#define GLX_HEIGHT                                         0x801E
#define GLX_EVENT_MASK                                     0x801F
#define GLX_DAMAGED                                        0x8020
#define GLX_SAVED                                          0x8021
#define GLX_WINDOW                                         0x8022
#define GLX_PBUFFER                                        0x8023
#define GLX_PBUFFER_HEIGHT                                 0x8040
#define GLX_PBUFFER_WIDTH                                  0x8041
#ifndef GLEE_H_DEFINED_glXGetFBConfigs
#define GLEE_H_DEFINED_glXGetFBConfigs
  typedef GLXFBConfig * (APIENTRYP GLEEPFNGLXGETFBCONFIGSPROC) (Display * dpy, int screen, int * nelements);
  GLEE_EXTERN GLEEPFNGLXGETFBCONFIGSPROC GLeeFuncPtr_glXGetFBConfigs;
  #define glXGetFBConfigs GLeeFuncPtr_glXGetFBConfigs
#endif
#ifndef GLEE_H_DEFINED_glXChooseFBConfig
#define GLEE_H_DEFINED_glXChooseFBConfig
  typedef GLXFBConfig * (APIENTRYP GLEEPFNGLXCHOOSEFBCONFIGPROC) (Display * dpy, int screen, const int * attrib_list, int * nelements);
  GLEE_EXTERN GLEEPFNGLXCHOOSEFBCONFIGPROC GLeeFuncPtr_glXChooseFBConfig;
  #define glXChooseFBConfig GLeeFuncPtr_glXChooseFBConfig
#endif
#ifndef GLEE_H_DEFINED_glXGetFBConfigAttrib
#define GLEE_H_DEFINED_glXGetFBConfigAttrib
  typedef int (APIENTRYP GLEEPFNGLXGETFBCONFIGATTRIBPROC) (Display * dpy, GLXFBConfig config, int attribute, int * value);
  GLEE_EXTERN GLEEPFNGLXGETFBCONFIGATTRIBPROC GLeeFuncPtr_glXGetFBConfigAttrib;
  #define glXGetFBConfigAttrib GLeeFuncPtr_glXGetFBConfigAttrib
#endif
#ifndef GLEE_H_DEFINED_glXGetVisualFromFBConfig
#define GLEE_H_DEFINED_glXGetVisualFromFBConfig
  typedef XVisualInfo * (APIENTRYP GLEEPFNGLXGETVISUALFROMFBCONFIGPROC) (Display * dpy, GLXFBConfig config);
  GLEE_EXTERN GLEEPFNGLXGETVISUALFROMFBCONFIGPROC GLeeFuncPtr_glXGetVisualFromFBConfig;
  #define glXGetVisualFromFBConfig GLeeFuncPtr_glXGetVisualFromFBConfig
#endif
#ifndef GLEE_H_DEFINED_glXCreateWindow
#define GLEE_H_DEFINED_glXCreateWindow
  typedef GLXWindow (APIENTRYP GLEEPFNGLXCREATEWINDOWPROC) (Display * dpy, GLXFBConfig config, Window win, const int * attrib_list);
  GLEE_EXTERN GLEEPFNGLXCREATEWINDOWPROC GLeeFuncPtr_glXCreateWindow;
  #define glXCreateWindow GLeeFuncPtr_glXCreateWindow
#endif
#ifndef GLEE_H_DEFINED_glXDestroyWindow
#define GLEE_H_DEFINED_glXDestroyWindow
  typedef void (APIENTRYP GLEEPFNGLXDESTROYWINDOWPROC) (Display * dpy, GLXWindow win);
  GLEE_EXTERN GLEEPFNGLXDESTROYWINDOWPROC GLeeFuncPtr_glXDestroyWindow;
  #define glXDestroyWindow GLeeFuncPtr_glXDestroyWindow
#endif
#ifndef GLEE_H_DEFINED_glXCreatePixmap
#define GLEE_H_DEFINED_glXCreatePixmap
  typedef GLXPixmap (APIENTRYP GLEEPFNGLXCREATEPIXMAPPROC) (Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list);
  GLEE_EXTERN GLEEPFNGLXCREATEPIXMAPPROC GLeeFuncPtr_glXCreatePixmap;
  #define glXCreatePixmap GLeeFuncPtr_glXCreatePixmap
#endif
#ifndef GLEE_H_DEFINED_glXDestroyPixmap
#define GLEE_H_DEFINED_glXDestroyPixmap
  typedef void (APIENTRYP GLEEPFNGLXDESTROYPIXMAPPROC) (Display * dpy, GLXPixmap pixmap);
  GLEE_EXTERN GLEEPFNGLXDESTROYPIXMAPPROC GLeeFuncPtr_glXDestroyPixmap;
  #define glXDestroyPixmap GLeeFuncPtr_glXDestroyPixmap
#endif
#ifndef GLEE_H_DEFINED_glXCreatePbuffer
#define GLEE_H_DEFINED_glXCreatePbuffer
  typedef GLXPbuffer (APIENTRYP GLEEPFNGLXCREATEPBUFFERPROC) (Display * dpy, GLXFBConfig config, const int * attrib_list);
  GLEE_EXTERN GLEEPFNGLXCREATEPBUFFERPROC GLeeFuncPtr_glXCreatePbuffer;
  #define glXCreatePbuffer GLeeFuncPtr_glXCreatePbuffer
#endif
#ifndef GLEE_H_DEFINED_glXDestroyPbuffer
#define GLEE_H_DEFINED_glXDestroyPbuffer
  typedef void (APIENTRYP GLEEPFNGLXDESTROYPBUFFERPROC) (Display * dpy, GLXPbuffer pbuf);
  GLEE_EXTERN GLEEPFNGLXDESTROYPBUFFERPROC GLeeFuncPtr_glXDestroyPbuffer;
  #define glXDestroyPbuffer GLeeFuncPtr_glXDestroyPbuffer
#endif
#ifndef GLEE_H_DEFINED_glXQueryDrawable
#define GLEE_H_DEFINED_glXQueryDrawable
  typedef void (APIENTRYP GLEEPFNGLXQUERYDRAWABLEPROC) (Display * dpy, GLXDrawable draw, int attribute, unsigned int * value);
  GLEE_EXTERN GLEEPFNGLXQUERYDRAWABLEPROC GLeeFuncPtr_glXQueryDrawable;
  #define glXQueryDrawable GLeeFuncPtr_glXQueryDrawable
#endif
#ifndef GLEE_H_DEFINED_glXCreateNewContext
#define GLEE_H_DEFINED_glXCreateNewContext
  typedef GLXContext (APIENTRYP GLEEPFNGLXCREATENEWCONTEXTPROC) (Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, int direct);
  GLEE_EXTERN GLEEPFNGLXCREATENEWCONTEXTPROC GLeeFuncPtr_glXCreateNewContext;
  #define glXCreateNewContext GLeeFuncPtr_glXCreateNewContext
#endif
#ifndef GLEE_H_DEFINED_glXMakeContextCurrent
#define GLEE_H_DEFINED_glXMakeContextCurrent
  typedef int (APIENTRYP GLEEPFNGLXMAKECONTEXTCURRENTPROC) (Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
  GLEE_EXTERN GLEEPFNGLXMAKECONTEXTCURRENTPROC GLeeFuncPtr_glXMakeContextCurrent;
  #define glXMakeContextCurrent GLeeFuncPtr_glXMakeContextCurrent
#endif
#ifndef GLEE_H_DEFINED_glXGetCurrentReadDrawable
#define GLEE_H_DEFINED_glXGetCurrentReadDrawable
  typedef GLXDrawable (APIENTRYP GLEEPFNGLXGETCURRENTREADDRAWABLEPROC) ();
  GLEE_EXTERN GLEEPFNGLXGETCURRENTREADDRAWABLEPROC GLeeFuncPtr_glXGetCurrentReadDrawable;
  #define glXGetCurrentReadDrawable GLeeFuncPtr_glXGetCurrentReadDrawable
#endif
#ifndef GLEE_H_DEFINED_glXGetCurrentDisplay
#define GLEE_H_DEFINED_glXGetCurrentDisplay
  typedef Display * (APIENTRYP GLEEPFNGLXGETCURRENTDISPLAYPROC) ();
  GLEE_EXTERN GLEEPFNGLXGETCURRENTDISPLAYPROC GLeeFuncPtr_glXGetCurrentDisplay;
  #define glXGetCurrentDisplay GLeeFuncPtr_glXGetCurrentDisplay
#endif
#ifndef GLEE_H_DEFINED_glXQueryContext
#define GLEE_H_DEFINED_glXQueryContext
  typedef int (APIENTRYP GLEEPFNGLXQUERYCONTEXTPROC) (Display * dpy, GLXContext ctx, int attribute, int * value);
  GLEE_EXTERN GLEEPFNGLXQUERYCONTEXTPROC GLeeFuncPtr_glXQueryContext;
  #define glXQueryContext GLeeFuncPtr_glXQueryContext
#endif
#ifndef GLEE_H_DEFINED_glXSelectEvent
#define GLEE_H_DEFINED_glXSelectEvent
  typedef void (APIENTRYP GLEEPFNGLXSELECTEVENTPROC) (Display * dpy, GLXDrawable draw, unsigned long event_mask);
  GLEE_EXTERN GLEEPFNGLXSELECTEVENTPROC GLeeFuncPtr_glXSelectEvent;
  #define glXSelectEvent GLeeFuncPtr_glXSelectEvent
#endif
#ifndef GLEE_H_DEFINED_glXGetSelectedEvent
#define GLEE_H_DEFINED_glXGetSelectedEvent
  typedef void (APIENTRYP GLEEPFNGLXGETSELECTEDEVENTPROC) (Display * dpy, GLXDrawable draw, unsigned long * event_mask);
  GLEE_EXTERN GLEEPFNGLXGETSELECTEDEVENTPROC GLeeFuncPtr_glXGetSelectedEvent;
  #define glXGetSelectedEvent GLeeFuncPtr_glXGetSelectedEvent
#endif
#endif

/* GLX_VERSION_1_4 */

#ifndef GLX_VERSION_1_4
#define GLX_VERSION_1_4 1
#define __GLEE_GLX_VERSION_1_4 1
/* Constants */
#define GLX_SAMPLE_BUFFERS                                 100000
#define GLX_SAMPLES                                        100001
#ifndef GLEE_H_DEFINED_glXGetProcAddress
#define GLEE_H_DEFINED_glXGetProcAddress
  typedef __GLXextFuncPtr (APIENTRYP GLEEPFNGLXGETPROCADDRESSPROC) (const GLubyte * procName);
  GLEE_EXTERN GLEEPFNGLXGETPROCADDRESSPROC GLeeFuncPtr_glXGetProcAddress;
  #define glXGetProcAddress GLeeFuncPtr_glXGetProcAddress
#endif
#endif

/* GLX_ARB_multisample */

#ifndef GLX_ARB_multisample
#define GLX_ARB_multisample 1
#define __GLEE_GLX_ARB_multisample 1
/* Constants */
#define GLX_SAMPLE_BUFFERS_ARB                             100000
#define GLX_SAMPLES_ARB                                    100001
#endif

/* GLX_ARB_fbconfig_float */

#ifndef GLX_ARB_fbconfig_float
#define GLX_ARB_fbconfig_float 1
#define __GLEE_GLX_ARB_fbconfig_float 1
/* Constants */
#define GLX_RGBA_FLOAT_TYPE_ARB                            0x20B9
#define GLX_RGBA_FLOAT_BIT_ARB                             0x00000004
#endif

/* GLX_ARB_create_context */

#ifndef GLX_ARB_create_context
#define GLX_ARB_create_context 1
#define __GLEE_GLX_ARB_create_context 1
/* Constants */
#define GLX_CONTEXT_DEBUG_BIT_ARB                          0x00000001
#define GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB             0x00000002
#define GLX_CONTEXT_MAJOR_VERSION_ARB                      0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB                      0x2092
#define GLX_CONTEXT_FLAGS_ARB                              0x2094
#ifndef GLEE_H_DEFINED_glXCreateContextAttribsARB
#define GLEE_H_DEFINED_glXCreateContextAttribsARB
  typedef GLXContext (APIENTRYP GLEEPFNGLXCREATECONTEXTATTRIBSARBPROC) (Display * dpy, GLXFBConfig config, GLXContext share_context, int direct, const int * attrib_list);
  GLEE_EXTERN GLEEPFNGLXCREATECONTEXTATTRIBSARBPROC GLeeFuncPtr_glXCreateContextAttribsARB;
  #define glXCreateContextAttribsARB GLeeFuncPtr_glXCreateContextAttribsARB
#endif
#endif

/* GLX_SGIS_multisample */

#ifndef GLX_SGIS_multisample
#define GLX_SGIS_multisample 1
#define __GLEE_GLX_SGIS_multisample 1
/* Constants */
#define GLX_SAMPLE_BUFFERS_SGIS                            100000
#define GLX_SAMPLES_SGIS                                   100001
#endif

/* GLX_EXT_visual_info */

#ifndef GLX_EXT_visual_info
#define GLX_EXT_visual_info 1
#define __GLEE_GLX_EXT_visual_info 1
/* Constants */
#define GLX_X_VISUAL_TYPE_EXT                              0x22
#define GLX_TRANSPARENT_TYPE_EXT                           0x23
#define GLX_TRANSPARENT_INDEX_VALUE_EXT                    0x24
#define GLX_TRANSPARENT_RED_VALUE_EXT                      0x25
#define GLX_TRANSPARENT_GREEN_VALUE_EXT                    0x26
#define GLX_TRANSPARENT_BLUE_VALUE_EXT                     0x27
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT                    0x28
#define GLX_NONE_EXT                                       0x8000
#define GLX_TRUE_COLOR_EXT                                 0x8002
#define GLX_DIRECT_COLOR_EXT                               0x8003
#define GLX_PSEUDO_COLOR_EXT                               0x8004
#define GLX_STATIC_COLOR_EXT                               0x8005
#define GLX_GRAY_SCALE_EXT                                 0x8006
#define GLX_STATIC_GRAY_EXT                                0x8007
#define GLX_TRANSPARENT_RGB_EXT                            0x8008
#define GLX_TRANSPARENT_INDEX_EXT                          0x8009
#endif

/* GLX_SGI_swap_control */

#ifndef GLX_SGI_swap_control
#define GLX_SGI_swap_control 1
#define __GLEE_GLX_SGI_swap_control 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXSwapIntervalSGI
#define GLEE_H_DEFINED_glXSwapIntervalSGI
  typedef int (APIENTRYP GLEEPFNGLXSWAPINTERVALSGIPROC) (int interval);
  GLEE_EXTERN GLEEPFNGLXSWAPINTERVALSGIPROC GLeeFuncPtr_glXSwapIntervalSGI;
  #define glXSwapIntervalSGI GLeeFuncPtr_glXSwapIntervalSGI
#endif
#endif

/* GLX_SGI_video_sync */

#ifndef GLX_SGI_video_sync
#define GLX_SGI_video_sync 1
#define __GLEE_GLX_SGI_video_sync 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXGetVideoSyncSGI
#define GLEE_H_DEFINED_glXGetVideoSyncSGI
  typedef int (APIENTRYP GLEEPFNGLXGETVIDEOSYNCSGIPROC) (unsigned int * count);
  GLEE_EXTERN GLEEPFNGLXGETVIDEOSYNCSGIPROC GLeeFuncPtr_glXGetVideoSyncSGI;
  #define glXGetVideoSyncSGI GLeeFuncPtr_glXGetVideoSyncSGI
#endif
#ifndef GLEE_H_DEFINED_glXWaitVideoSyncSGI
#define GLEE_H_DEFINED_glXWaitVideoSyncSGI
  typedef int (APIENTRYP GLEEPFNGLXWAITVIDEOSYNCSGIPROC) (int divisor, int remainder, unsigned int * count);
  GLEE_EXTERN GLEEPFNGLXWAITVIDEOSYNCSGIPROC GLeeFuncPtr_glXWaitVideoSyncSGI;
  #define glXWaitVideoSyncSGI GLeeFuncPtr_glXWaitVideoSyncSGI
#endif
#endif

/* GLX_SGI_make_current_read */

#ifndef GLX_SGI_make_current_read
#define GLX_SGI_make_current_read 1
#define __GLEE_GLX_SGI_make_current_read 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXMakeCurrentReadSGI
#define GLEE_H_DEFINED_glXMakeCurrentReadSGI
  typedef int (APIENTRYP GLEEPFNGLXMAKECURRENTREADSGIPROC) (Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
  GLEE_EXTERN GLEEPFNGLXMAKECURRENTREADSGIPROC GLeeFuncPtr_glXMakeCurrentReadSGI;
  #define glXMakeCurrentReadSGI GLeeFuncPtr_glXMakeCurrentReadSGI
#endif
#ifndef GLEE_H_DEFINED_glXGetCurrentReadDrawableSGI
#define GLEE_H_DEFINED_glXGetCurrentReadDrawableSGI
  typedef GLXDrawable (APIENTRYP GLEEPFNGLXGETCURRENTREADDRAWABLESGIPROC) ();
  GLEE_EXTERN GLEEPFNGLXGETCURRENTREADDRAWABLESGIPROC GLeeFuncPtr_glXGetCurrentReadDrawableSGI;
  #define glXGetCurrentReadDrawableSGI GLeeFuncPtr_glXGetCurrentReadDrawableSGI
#endif
#endif

/* GLX_EXT_visual_rating */

#ifndef GLX_EXT_visual_rating
#define GLX_EXT_visual_rating 1
#define __GLEE_GLX_EXT_visual_rating 1
/* Constants */
#define GLX_VISUAL_CAVEAT_EXT                              0x20
#define GLX_SLOW_VISUAL_EXT                                0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT                      0x800D
#endif

/* GLX_EXT_import_context */

#ifndef GLX_EXT_import_context
#define GLX_EXT_import_context 1
#define __GLEE_GLX_EXT_import_context 1
/* Constants */
#define GLX_SHARE_CONTEXT_EXT                              0x800A
#define GLX_VISUAL_ID_EXT                                  0x800B
#define GLX_SCREEN_EXT                                     0x800C
#ifndef GLEE_H_DEFINED_glXGetCurrentDisplayEXT
#define GLEE_H_DEFINED_glXGetCurrentDisplayEXT
  typedef Display * (APIENTRYP GLEEPFNGLXGETCURRENTDISPLAYEXTPROC) ();
  GLEE_EXTERN GLEEPFNGLXGETCURRENTDISPLAYEXTPROC GLeeFuncPtr_glXGetCurrentDisplayEXT;
  #define glXGetCurrentDisplayEXT GLeeFuncPtr_glXGetCurrentDisplayEXT
#endif
#ifndef GLEE_H_DEFINED_glXQueryContextInfoEXT
#define GLEE_H_DEFINED_glXQueryContextInfoEXT
  typedef int (APIENTRYP GLEEPFNGLXQUERYCONTEXTINFOEXTPROC) (Display * dpy, GLXContext context, int attribute, int * value);
  GLEE_EXTERN GLEEPFNGLXQUERYCONTEXTINFOEXTPROC GLeeFuncPtr_glXQueryContextInfoEXT;
  #define glXQueryContextInfoEXT GLeeFuncPtr_glXQueryContextInfoEXT
#endif
#ifndef GLEE_H_DEFINED_glXGetContextIDEXT
#define GLEE_H_DEFINED_glXGetContextIDEXT
  typedef GLXContextID (APIENTRYP GLEEPFNGLXGETCONTEXTIDEXTPROC) (const GLXContext context);
  GLEE_EXTERN GLEEPFNGLXGETCONTEXTIDEXTPROC GLeeFuncPtr_glXGetContextIDEXT;
  #define glXGetContextIDEXT GLeeFuncPtr_glXGetContextIDEXT
#endif
#ifndef GLEE_H_DEFINED_glXImportContextEXT
#define GLEE_H_DEFINED_glXImportContextEXT
  typedef GLXContext (APIENTRYP GLEEPFNGLXIMPORTCONTEXTEXTPROC) (Display * dpy, GLXContextID contextID);
  GLEE_EXTERN GLEEPFNGLXIMPORTCONTEXTEXTPROC GLeeFuncPtr_glXImportContextEXT;
  #define glXImportContextEXT GLeeFuncPtr_glXImportContextEXT
#endif
#ifndef GLEE_H_DEFINED_glXFreeContextEXT
#define GLEE_H_DEFINED_glXFreeContextEXT
  typedef void (APIENTRYP GLEEPFNGLXFREECONTEXTEXTPROC) (Display * dpy, GLXContext context);
  GLEE_EXTERN GLEEPFNGLXFREECONTEXTEXTPROC GLeeFuncPtr_glXFreeContextEXT;
  #define glXFreeContextEXT GLeeFuncPtr_glXFreeContextEXT
#endif
#endif

/* GLX_SGIX_fbconfig */

#ifndef GLX_SGIX_fbconfig
#define GLX_SGIX_fbconfig 1
#define __GLEE_GLX_SGIX_fbconfig 1
/* Constants */
#define GLX_WINDOW_BIT_SGIX                                0x00000001
#define GLX_PIXMAP_BIT_SGIX                                0x00000002
#define GLX_RGBA_BIT_SGIX                                  0x00000001
#define GLX_COLOR_INDEX_BIT_SGIX                           0x00000002
#define GLX_DRAWABLE_TYPE_SGIX                             0x8010
#define GLX_RENDER_TYPE_SGIX                               0x8011
#define GLX_X_RENDERABLE_SGIX                              0x8012
#define GLX_FBCONFIG_ID_SGIX                               0x8013
#define GLX_RGBA_TYPE_SGIX                                 0x8014
#define GLX_COLOR_INDEX_TYPE_SGIX                          0x8015
#ifndef GLEE_H_DEFINED_glXGetFBConfigAttribSGIX
#define GLEE_H_DEFINED_glXGetFBConfigAttribSGIX
  typedef int (APIENTRYP GLEEPFNGLXGETFBCONFIGATTRIBSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, int attribute, int * value);
  GLEE_EXTERN GLEEPFNGLXGETFBCONFIGATTRIBSGIXPROC GLeeFuncPtr_glXGetFBConfigAttribSGIX;
  #define glXGetFBConfigAttribSGIX GLeeFuncPtr_glXGetFBConfigAttribSGIX
#endif
#ifndef GLEE_H_DEFINED_glXChooseFBConfigSGIX
#define GLEE_H_DEFINED_glXChooseFBConfigSGIX
  typedef GLXFBConfigSGIX * (APIENTRYP GLEEPFNGLXCHOOSEFBCONFIGSGIXPROC) (Display * dpy, int screen, int * attrib_list, int * nelements);
  GLEE_EXTERN GLEEPFNGLXCHOOSEFBCONFIGSGIXPROC GLeeFuncPtr_glXChooseFBConfigSGIX;
  #define glXChooseFBConfigSGIX GLeeFuncPtr_glXChooseFBConfigSGIX
#endif
#ifndef GLEE_H_DEFINED_glXCreateGLXPixmapWithConfigSGIX
#define GLEE_H_DEFINED_glXCreateGLXPixmapWithConfigSGIX
  typedef GLXPixmap (APIENTRYP GLEEPFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, Pixmap pixmap);
  GLEE_EXTERN GLEEPFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC GLeeFuncPtr_glXCreateGLXPixmapWithConfigSGIX;
  #define glXCreateGLXPixmapWithConfigSGIX GLeeFuncPtr_glXCreateGLXPixmapWithConfigSGIX
#endif
#ifndef GLEE_H_DEFINED_glXCreateContextWithConfigSGIX
#define GLEE_H_DEFINED_glXCreateContextWithConfigSGIX
  typedef GLXContext (APIENTRYP GLEEPFNGLXCREATECONTEXTWITHCONFIGSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, int direct);
  GLEE_EXTERN GLEEPFNGLXCREATECONTEXTWITHCONFIGSGIXPROC GLeeFuncPtr_glXCreateContextWithConfigSGIX;
  #define glXCreateContextWithConfigSGIX GLeeFuncPtr_glXCreateContextWithConfigSGIX
#endif
#ifndef GLEE_H_DEFINED_glXGetVisualFromFBConfigSGIX
#define GLEE_H_DEFINED_glXGetVisualFromFBConfigSGIX
  typedef XVisualInfo * (APIENTRYP GLEEPFNGLXGETVISUALFROMFBCONFIGSGIXPROC) (Display * dpy, GLXFBConfigSGIX config);
  GLEE_EXTERN GLEEPFNGLXGETVISUALFROMFBCONFIGSGIXPROC GLeeFuncPtr_glXGetVisualFromFBConfigSGIX;
  #define glXGetVisualFromFBConfigSGIX GLeeFuncPtr_glXGetVisualFromFBConfigSGIX
#endif
#ifndef GLEE_H_DEFINED_glXGetFBConfigFromVisualSGIX
#define GLEE_H_DEFINED_glXGetFBConfigFromVisualSGIX
  typedef GLXFBConfigSGIX (APIENTRYP GLEEPFNGLXGETFBCONFIGFROMVISUALSGIXPROC) (Display * dpy, XVisualInfo * vis);
  GLEE_EXTERN GLEEPFNGLXGETFBCONFIGFROMVISUALSGIXPROC GLeeFuncPtr_glXGetFBConfigFromVisualSGIX;
  #define glXGetFBConfigFromVisualSGIX GLeeFuncPtr_glXGetFBConfigFromVisualSGIX
#endif
#endif

/* GLX_SGIX_pbuffer */

#ifndef GLX_SGIX_pbuffer
#define GLX_SGIX_pbuffer 1
#define __GLEE_GLX_SGIX_pbuffer 1
/* Constants */
#define GLX_PBUFFER_BIT_SGIX                               0x00000004
#define GLX_BUFFER_CLOBBER_MASK_SGIX                       0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX                     0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX                    0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX                      0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX                     0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX                           0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX                          0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX                        0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX                          0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX                        0x00000100
#define GLX_MAX_PBUFFER_WIDTH_SGIX                         0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX                        0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX                        0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX                     0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX                    0x801A
#define GLX_PRESERVED_CONTENTS_SGIX                        0x801B
#define GLX_LARGEST_PBUFFER_SGIX                           0x801C
#define GLX_WIDTH_SGIX                                     0x801D
#define GLX_HEIGHT_SGIX                                    0x801E
#define GLX_EVENT_MASK_SGIX                                0x801F
#define GLX_DAMAGED_SGIX                                   0x8020
#define GLX_SAVED_SGIX                                     0x8021
#define GLX_WINDOW_SGIX                                    0x8022
#define GLX_PBUFFER_SGIX                                   0x8023
#ifndef GLEE_H_DEFINED_glXCreateGLXPbufferSGIX
#define GLEE_H_DEFINED_glXCreateGLXPbufferSGIX
  typedef GLXPbufferSGIX (APIENTRYP GLEEPFNGLXCREATEGLXPBUFFERSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int * attrib_list);
  GLEE_EXTERN GLEEPFNGLXCREATEGLXPBUFFERSGIXPROC GLeeFuncPtr_glXCreateGLXPbufferSGIX;
  #define glXCreateGLXPbufferSGIX GLeeFuncPtr_glXCreateGLXPbufferSGIX
#endif
#ifndef GLEE_H_DEFINED_glXDestroyGLXPbufferSGIX
#define GLEE_H_DEFINED_glXDestroyGLXPbufferSGIX
  typedef void (APIENTRYP GLEEPFNGLXDESTROYGLXPBUFFERSGIXPROC) (Display * dpy, GLXPbufferSGIX pbuf);
  GLEE_EXTERN GLEEPFNGLXDESTROYGLXPBUFFERSGIXPROC GLeeFuncPtr_glXDestroyGLXPbufferSGIX;
  #define glXDestroyGLXPbufferSGIX GLeeFuncPtr_glXDestroyGLXPbufferSGIX
#endif
#ifndef GLEE_H_DEFINED_glXQueryGLXPbufferSGIX
#define GLEE_H_DEFINED_glXQueryGLXPbufferSGIX
  typedef int (APIENTRYP GLEEPFNGLXQUERYGLXPBUFFERSGIXPROC) (Display * dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int * value);
  GLEE_EXTERN GLEEPFNGLXQUERYGLXPBUFFERSGIXPROC GLeeFuncPtr_glXQueryGLXPbufferSGIX;
  #define glXQueryGLXPbufferSGIX GLeeFuncPtr_glXQueryGLXPbufferSGIX
#endif
#ifndef GLEE_H_DEFINED_glXSelectEventSGIX
#define GLEE_H_DEFINED_glXSelectEventSGIX
  typedef void (APIENTRYP GLEEPFNGLXSELECTEVENTSGIXPROC) (Display * dpy, GLXDrawable drawable, unsigned long mask);
  GLEE_EXTERN GLEEPFNGLXSELECTEVENTSGIXPROC GLeeFuncPtr_glXSelectEventSGIX;
  #define glXSelectEventSGIX GLeeFuncPtr_glXSelectEventSGIX
#endif
#ifndef GLEE_H_DEFINED_glXGetSelectedEventSGIX
#define GLEE_H_DEFINED_glXGetSelectedEventSGIX
  typedef void (APIENTRYP GLEEPFNGLXGETSELECTEDEVENTSGIXPROC) (Display * dpy, GLXDrawable drawable, unsigned long * mask);
  GLEE_EXTERN GLEEPFNGLXGETSELECTEDEVENTSGIXPROC GLeeFuncPtr_glXGetSelectedEventSGIX;
  #define glXGetSelectedEventSGIX GLeeFuncPtr_glXGetSelectedEventSGIX
#endif
#endif

/* GLX_SGI_cushion */

#ifndef GLX_SGI_cushion
#define GLX_SGI_cushion 1
#define __GLEE_GLX_SGI_cushion 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXCushionSGI
#define GLEE_H_DEFINED_glXCushionSGI
  typedef void (APIENTRYP GLEEPFNGLXCUSHIONSGIPROC) (Display * dpy, Window window, float cushion);
  GLEE_EXTERN GLEEPFNGLXCUSHIONSGIPROC GLeeFuncPtr_glXCushionSGI;
  #define glXCushionSGI GLeeFuncPtr_glXCushionSGI
#endif
#endif

/* GLX_SGIX_video_resize */

#ifndef GLX_SGIX_video_resize
#define GLX_SGIX_video_resize 1
#define __GLEE_GLX_SGIX_video_resize 1
/* Constants */
#define GLX_SYNC_FRAME_SGIX                                0x00000000
#define GLX_SYNC_SWAP_SGIX                                 0x00000001
#ifndef GLEE_H_DEFINED_glXBindChannelToWindowSGIX
#define GLEE_H_DEFINED_glXBindChannelToWindowSGIX
  typedef int (APIENTRYP GLEEPFNGLXBINDCHANNELTOWINDOWSGIXPROC) (Display * display, int screen, int channel, Window window);
  GLEE_EXTERN GLEEPFNGLXBINDCHANNELTOWINDOWSGIXPROC GLeeFuncPtr_glXBindChannelToWindowSGIX;
  #define glXBindChannelToWindowSGIX GLeeFuncPtr_glXBindChannelToWindowSGIX
#endif
#ifndef GLEE_H_DEFINED_glXChannelRectSGIX
#define GLEE_H_DEFINED_glXChannelRectSGIX
  typedef int (APIENTRYP GLEEPFNGLXCHANNELRECTSGIXPROC) (Display * display, int screen, int channel, int x, int y, int w, int h);
  GLEE_EXTERN GLEEPFNGLXCHANNELRECTSGIXPROC GLeeFuncPtr_glXChannelRectSGIX;
  #define glXChannelRectSGIX GLeeFuncPtr_glXChannelRectSGIX
#endif
#ifndef GLEE_H_DEFINED_glXQueryChannelRectSGIX
#define GLEE_H_DEFINED_glXQueryChannelRectSGIX
  typedef int (APIENTRYP GLEEPFNGLXQUERYCHANNELRECTSGIXPROC) (Display * display, int screen, int channel, int * dx, int * dy, int * dw, int * dh);
  GLEE_EXTERN GLEEPFNGLXQUERYCHANNELRECTSGIXPROC GLeeFuncPtr_glXQueryChannelRectSGIX;
  #define glXQueryChannelRectSGIX GLeeFuncPtr_glXQueryChannelRectSGIX
#endif
#ifndef GLEE_H_DEFINED_glXQueryChannelDeltasSGIX
#define GLEE_H_DEFINED_glXQueryChannelDeltasSGIX
  typedef int (APIENTRYP GLEEPFNGLXQUERYCHANNELDELTASSGIXPROC) (Display * display, int screen, int channel, int * x, int * y, int * w, int * h);
  GLEE_EXTERN GLEEPFNGLXQUERYCHANNELDELTASSGIXPROC GLeeFuncPtr_glXQueryChannelDeltasSGIX;
  #define glXQueryChannelDeltasSGIX GLeeFuncPtr_glXQueryChannelDeltasSGIX
#endif
#ifndef GLEE_H_DEFINED_glXChannelRectSyncSGIX
#define GLEE_H_DEFINED_glXChannelRectSyncSGIX
  typedef int (APIENTRYP GLEEPFNGLXCHANNELRECTSYNCSGIXPROC) (Display * display, int screen, int channel, GLenum synctype);
  GLEE_EXTERN GLEEPFNGLXCHANNELRECTSYNCSGIXPROC GLeeFuncPtr_glXChannelRectSyncSGIX;
  #define glXChannelRectSyncSGIX GLeeFuncPtr_glXChannelRectSyncSGIX
#endif
#endif

/* GLX_SGIX_swap_group */

#ifndef GLX_SGIX_swap_group
#define GLX_SGIX_swap_group 1
#define __GLEE_GLX_SGIX_swap_group 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXJoinSwapGroupSGIX
#define GLEE_H_DEFINED_glXJoinSwapGroupSGIX
  typedef void (APIENTRYP GLEEPFNGLXJOINSWAPGROUPSGIXPROC) (Display * dpy, GLXDrawable drawable, GLXDrawable member);
  GLEE_EXTERN GLEEPFNGLXJOINSWAPGROUPSGIXPROC GLeeFuncPtr_glXJoinSwapGroupSGIX;
  #define glXJoinSwapGroupSGIX GLeeFuncPtr_glXJoinSwapGroupSGIX
#endif
#endif

/* GLX_SGIX_swap_barrier */

#ifndef GLX_SGIX_swap_barrier
#define GLX_SGIX_swap_barrier 1
#define __GLEE_GLX_SGIX_swap_barrier 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXBindSwapBarrierSGIX
#define GLEE_H_DEFINED_glXBindSwapBarrierSGIX
  typedef void (APIENTRYP GLEEPFNGLXBINDSWAPBARRIERSGIXPROC) (Display * dpy, GLXDrawable drawable, int barrier);
  GLEE_EXTERN GLEEPFNGLXBINDSWAPBARRIERSGIXPROC GLeeFuncPtr_glXBindSwapBarrierSGIX;
  #define glXBindSwapBarrierSGIX GLeeFuncPtr_glXBindSwapBarrierSGIX
#endif
#ifndef GLEE_H_DEFINED_glXQueryMaxSwapBarriersSGIX
#define GLEE_H_DEFINED_glXQueryMaxSwapBarriersSGIX
  typedef int (APIENTRYP GLEEPFNGLXQUERYMAXSWAPBARRIERSSGIXPROC) (Display * dpy, int screen, int * max);
  GLEE_EXTERN GLEEPFNGLXQUERYMAXSWAPBARRIERSSGIXPROC GLeeFuncPtr_glXQueryMaxSwapBarriersSGIX;
  #define glXQueryMaxSwapBarriersSGIX GLeeFuncPtr_glXQueryMaxSwapBarriersSGIX
#endif
#endif

/* GLX_SGIS_blended_overlay */

#ifndef GLX_SGIS_blended_overlay
#define GLX_SGIS_blended_overlay 1
#define __GLEE_GLX_SGIS_blended_overlay 1
/* Constants */
#define GLX_BLENDED_RGBA_SGIS                              0x8025
#endif

/* GLX_SGIS_shared_multisample */

#ifndef GLX_SGIS_shared_multisample
#define GLX_SGIS_shared_multisample 1
#define __GLEE_GLX_SGIS_shared_multisample 1
/* Constants */
#define GLX_MULTISAMPLE_SUB_RECT_WIDTH_SGIS                0x8026
#define GLX_MULTISAMPLE_SUB_RECT_HEIGHT_SGIS               0x8027
#endif

/* GLX_SUN_get_transparent_index */

#ifndef GLX_SUN_get_transparent_index
#define GLX_SUN_get_transparent_index 1
#define __GLEE_GLX_SUN_get_transparent_index 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXGetTransparentIndexSUN
#define GLEE_H_DEFINED_glXGetTransparentIndexSUN
  typedef int (APIENTRYP GLEEPFNGLXGETTRANSPARENTINDEXSUNPROC) (Display * dpy, Window overlay, Window underlay, long * pTransparentIndex);
  GLEE_EXTERN GLEEPFNGLXGETTRANSPARENTINDEXSUNPROC GLeeFuncPtr_glXGetTransparentIndexSUN;
  #define glXGetTransparentIndexSUN GLeeFuncPtr_glXGetTransparentIndexSUN
#endif
#endif

/* GLX_3DFX_multisample */

#ifndef GLX_3DFX_multisample
#define GLX_3DFX_multisample 1
#define __GLEE_GLX_3DFX_multisample 1
/* Constants */
#define GLX_SAMPLE_BUFFERS_3DFX                            0x8050
#define GLX_SAMPLES_3DFX                                   0x8051
#endif

/* GLX_MESA_copy_sub_buffer */

#ifndef GLX_MESA_copy_sub_buffer
#define GLX_MESA_copy_sub_buffer 1
#define __GLEE_GLX_MESA_copy_sub_buffer 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXCopySubBufferMESA
#define GLEE_H_DEFINED_glXCopySubBufferMESA
  typedef void (APIENTRYP GLEEPFNGLXCOPYSUBBUFFERMESAPROC) (Display * dpy, GLXDrawable drawable, int x, int y, int width, int height);
  GLEE_EXTERN GLEEPFNGLXCOPYSUBBUFFERMESAPROC GLeeFuncPtr_glXCopySubBufferMESA;
  #define glXCopySubBufferMESA GLeeFuncPtr_glXCopySubBufferMESA
#endif
#endif

/* GLX_MESA_pixmap_colormap */

#ifndef GLX_MESA_pixmap_colormap
#define GLX_MESA_pixmap_colormap 1
#define __GLEE_GLX_MESA_pixmap_colormap 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXCreateGLXPixmapMESA
#define GLEE_H_DEFINED_glXCreateGLXPixmapMESA
  typedef GLXPixmap (APIENTRYP GLEEPFNGLXCREATEGLXPIXMAPMESAPROC) (Display * dpy, XVisualInfo * visual, Pixmap pixmap, Colormap cmap);
  GLEE_EXTERN GLEEPFNGLXCREATEGLXPIXMAPMESAPROC GLeeFuncPtr_glXCreateGLXPixmapMESA;
  #define glXCreateGLXPixmapMESA GLeeFuncPtr_glXCreateGLXPixmapMESA
#endif
#endif

/* GLX_MESA_release_buffers */

#ifndef GLX_MESA_release_buffers
#define GLX_MESA_release_buffers 1
#define __GLEE_GLX_MESA_release_buffers 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXReleaseBuffersMESA
#define GLEE_H_DEFINED_glXReleaseBuffersMESA
  typedef int (APIENTRYP GLEEPFNGLXRELEASEBUFFERSMESAPROC) (Display * dpy, GLXDrawable drawable);
  GLEE_EXTERN GLEEPFNGLXRELEASEBUFFERSMESAPROC GLeeFuncPtr_glXReleaseBuffersMESA;
  #define glXReleaseBuffersMESA GLeeFuncPtr_glXReleaseBuffersMESA
#endif
#endif

/* GLX_MESA_set_3dfx_mode */

#ifndef GLX_MESA_set_3dfx_mode
#define GLX_MESA_set_3dfx_mode 1
#define __GLEE_GLX_MESA_set_3dfx_mode 1
/* Constants */
#define GLX_3DFX_WINDOW_MODE_MESA                          0x1
#define GLX_3DFX_FULLSCREEN_MODE_MESA                      0x2
#ifndef GLEE_H_DEFINED_glXSet3DfxModeMESA
#define GLEE_H_DEFINED_glXSet3DfxModeMESA
  typedef int (APIENTRYP GLEEPFNGLXSET3DFXMODEMESAPROC) (int mode);
  GLEE_EXTERN GLEEPFNGLXSET3DFXMODEMESAPROC GLeeFuncPtr_glXSet3DfxModeMESA;
  #define glXSet3DfxModeMESA GLeeFuncPtr_glXSet3DfxModeMESA
#endif
#endif

/* GLX_SGIX_visual_select_group */

#ifndef GLX_SGIX_visual_select_group
#define GLX_SGIX_visual_select_group 1
#define __GLEE_GLX_SGIX_visual_select_group 1
/* Constants */
#define GLX_VISUAL_SELECT_GROUP_SGIX                       0x8028
#endif

/* GLX_OML_swap_method */

#ifndef GLX_OML_swap_method
#define GLX_OML_swap_method 1
#define __GLEE_GLX_OML_swap_method 1
/* Constants */
#define GLX_SWAP_METHOD_OML                                0x8060
#define GLX_SWAP_EXCHANGE_OML                              0x8061
#define GLX_SWAP_COPY_OML                                  0x8062
#define GLX_SWAP_UNDEFINED_OML                             0x8063
#endif

/* GLX_OML_sync_control */

#ifndef GLX_OML_sync_control
#define GLX_OML_sync_control 1
#define __GLEE_GLX_OML_sync_control 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXGetSyncValuesOML
#define GLEE_H_DEFINED_glXGetSyncValuesOML
  typedef int (APIENTRYP GLEEPFNGLXGETSYNCVALUESOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t * ust, int64_t * msc, int64_t * sbc);
  GLEE_EXTERN GLEEPFNGLXGETSYNCVALUESOMLPROC GLeeFuncPtr_glXGetSyncValuesOML;
  #define glXGetSyncValuesOML GLeeFuncPtr_glXGetSyncValuesOML
#endif
#ifndef GLEE_H_DEFINED_glXGetMscRateOML
#define GLEE_H_DEFINED_glXGetMscRateOML
  typedef int (APIENTRYP GLEEPFNGLXGETMSCRATEOMLPROC) (Display * dpy, GLXDrawable drawable, int32_t * numerator, int32_t * denominator);
  GLEE_EXTERN GLEEPFNGLXGETMSCRATEOMLPROC GLeeFuncPtr_glXGetMscRateOML;
  #define glXGetMscRateOML GLeeFuncPtr_glXGetMscRateOML
#endif
#ifndef GLEE_H_DEFINED_glXSwapBuffersMscOML
#define GLEE_H_DEFINED_glXSwapBuffersMscOML
  typedef int64_t (APIENTRYP GLEEPFNGLXSWAPBUFFERSMSCOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
  GLEE_EXTERN GLEEPFNGLXSWAPBUFFERSMSCOMLPROC GLeeFuncPtr_glXSwapBuffersMscOML;
  #define glXSwapBuffersMscOML GLeeFuncPtr_glXSwapBuffersMscOML
#endif
#ifndef GLEE_H_DEFINED_glXWaitForMscOML
#define GLEE_H_DEFINED_glXWaitForMscOML
  typedef int (APIENTRYP GLEEPFNGLXWAITFORMSCOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t * ust, int64_t * msc, int64_t * sbc);
  GLEE_EXTERN GLEEPFNGLXWAITFORMSCOMLPROC GLeeFuncPtr_glXWaitForMscOML;
  #define glXWaitForMscOML GLeeFuncPtr_glXWaitForMscOML
#endif
#ifndef GLEE_H_DEFINED_glXWaitForSbcOML
#define GLEE_H_DEFINED_glXWaitForSbcOML
  typedef int (APIENTRYP GLEEPFNGLXWAITFORSBCOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t target_sbc, int64_t * ust, int64_t * msc, int64_t * sbc);
  GLEE_EXTERN GLEEPFNGLXWAITFORSBCOMLPROC GLeeFuncPtr_glXWaitForSbcOML;
  #define glXWaitForSbcOML GLeeFuncPtr_glXWaitForSbcOML
#endif
#endif

/* GLX_NV_float_buffer */

#ifndef GLX_NV_float_buffer
#define GLX_NV_float_buffer 1
#define __GLEE_GLX_NV_float_buffer 1
/* Constants */
#define GLX_FLOAT_COMPONENTS_NV                            0x20B0
#endif

/* GLX_SGIX_hyperpipe */

#ifndef GLX_SGIX_hyperpipe
#define GLX_SGIX_hyperpipe 1
#define __GLEE_GLX_SGIX_hyperpipe 1
/* Constants */
#define GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX                80
#define GLX_BAD_HYPERPIPE_CONFIG_SGIX                      91
#define GLX_BAD_HYPERPIPE_SGIX                             92
#define GLX_HYPERPIPE_DISPLAY_PIPE_SGIX                    0x00000001
#define GLX_HYPERPIPE_RENDER_PIPE_SGIX                     0x00000002
#define GLX_PIPE_RECT_SGIX                                 0x00000001
#define GLX_PIPE_RECT_LIMITS_SGIX                          0x00000002
#define GLX_HYPERPIPE_STEREO_SGIX                          0x00000003
#define GLX_HYPERPIPE_PIXEL_AVERAGE_SGIX                   0x00000004
#define GLX_HYPERPIPE_ID_SGIX                              0x8030
#ifndef GLEE_H_DEFINED_glXQueryHyperpipeNetworkSGIX
#define GLEE_H_DEFINED_glXQueryHyperpipeNetworkSGIX
  typedef GLXHyperpipeNetworkSGIX * (APIENTRYP GLEEPFNGLXQUERYHYPERPIPENETWORKSGIXPROC) (Display * dpy, int * npipes);
  GLEE_EXTERN GLEEPFNGLXQUERYHYPERPIPENETWORKSGIXPROC GLeeFuncPtr_glXQueryHyperpipeNetworkSGIX;
  #define glXQueryHyperpipeNetworkSGIX GLeeFuncPtr_glXQueryHyperpipeNetworkSGIX
#endif
#ifndef GLEE_H_DEFINED_glXHyperpipeConfigSGIX
#define GLEE_H_DEFINED_glXHyperpipeConfigSGIX
  typedef int (APIENTRYP GLEEPFNGLXHYPERPIPECONFIGSGIXPROC) (Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX * cfg, int * hpId);
  GLEE_EXTERN GLEEPFNGLXHYPERPIPECONFIGSGIXPROC GLeeFuncPtr_glXHyperpipeConfigSGIX;
  #define glXHyperpipeConfigSGIX GLeeFuncPtr_glXHyperpipeConfigSGIX
#endif
#ifndef GLEE_H_DEFINED_glXQueryHyperpipeConfigSGIX
#define GLEE_H_DEFINED_glXQueryHyperpipeConfigSGIX
  typedef GLXHyperpipeConfigSGIX * (APIENTRYP GLEEPFNGLXQUERYHYPERPIPECONFIGSGIXPROC) (Display * dpy, int hpId, int * npipes);
  GLEE_EXTERN GLEEPFNGLXQUERYHYPERPIPECONFIGSGIXPROC GLeeFuncPtr_glXQueryHyperpipeConfigSGIX;
  #define glXQueryHyperpipeConfigSGIX GLeeFuncPtr_glXQueryHyperpipeConfigSGIX
#endif
#ifndef GLEE_H_DEFINED_glXDestroyHyperpipeConfigSGIX
#define GLEE_H_DEFINED_glXDestroyHyperpipeConfigSGIX
  typedef int (APIENTRYP GLEEPFNGLXDESTROYHYPERPIPECONFIGSGIXPROC) (Display * dpy, int hpId);
  GLEE_EXTERN GLEEPFNGLXDESTROYHYPERPIPECONFIGSGIXPROC GLeeFuncPtr_glXDestroyHyperpipeConfigSGIX;
  #define glXDestroyHyperpipeConfigSGIX GLeeFuncPtr_glXDestroyHyperpipeConfigSGIX
#endif
#ifndef GLEE_H_DEFINED_glXBindHyperpipeSGIX
#define GLEE_H_DEFINED_glXBindHyperpipeSGIX
  typedef int (APIENTRYP GLEEPFNGLXBINDHYPERPIPESGIXPROC) (Display * dpy, int hpId);
  GLEE_EXTERN GLEEPFNGLXBINDHYPERPIPESGIXPROC GLeeFuncPtr_glXBindHyperpipeSGIX;
  #define glXBindHyperpipeSGIX GLeeFuncPtr_glXBindHyperpipeSGIX
#endif
#ifndef GLEE_H_DEFINED_glXQueryHyperpipeBestAttribSGIX
#define GLEE_H_DEFINED_glXQueryHyperpipeBestAttribSGIX
  typedef int (APIENTRYP GLEEPFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC) (Display * dpy, int timeSlice, int attrib, int size, void * attribList, void * returnAttribList);
  GLEE_EXTERN GLEEPFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC GLeeFuncPtr_glXQueryHyperpipeBestAttribSGIX;
  #define glXQueryHyperpipeBestAttribSGIX GLeeFuncPtr_glXQueryHyperpipeBestAttribSGIX
#endif
#ifndef GLEE_H_DEFINED_glXHyperpipeAttribSGIX
#define GLEE_H_DEFINED_glXHyperpipeAttribSGIX
  typedef int (APIENTRYP GLEEPFNGLXHYPERPIPEATTRIBSGIXPROC) (Display * dpy, int timeSlice, int attrib, int size, void * attribList);
  GLEE_EXTERN GLEEPFNGLXHYPERPIPEATTRIBSGIXPROC GLeeFuncPtr_glXHyperpipeAttribSGIX;
  #define glXHyperpipeAttribSGIX GLeeFuncPtr_glXHyperpipeAttribSGIX
#endif
#ifndef GLEE_H_DEFINED_glXQueryHyperpipeAttribSGIX
#define GLEE_H_DEFINED_glXQueryHyperpipeAttribSGIX
  typedef int (APIENTRYP GLEEPFNGLXQUERYHYPERPIPEATTRIBSGIXPROC) (Display * dpy, int timeSlice, int attrib, int size, void * returnAttribList);
  GLEE_EXTERN GLEEPFNGLXQUERYHYPERPIPEATTRIBSGIXPROC GLeeFuncPtr_glXQueryHyperpipeAttribSGIX;
  #define glXQueryHyperpipeAttribSGIX GLeeFuncPtr_glXQueryHyperpipeAttribSGIX
#endif
#endif

/* GLX_MESA_agp_offset */

#ifndef GLX_MESA_agp_offset
#define GLX_MESA_agp_offset 1
#define __GLEE_GLX_MESA_agp_offset 1
/* Constants */
#ifndef GLEE_H_DEFINED_glXGetAGPOffsetMESA
#define GLEE_H_DEFINED_glXGetAGPOffsetMESA
  typedef unsigned int (APIENTRYP GLEEPFNGLXGETAGPOFFSETMESAPROC) (const void * pointer);
  GLEE_EXTERN GLEEPFNGLXGETAGPOFFSETMESAPROC GLeeFuncPtr_glXGetAGPOffsetMESA;
  #define glXGetAGPOffsetMESA GLeeFuncPtr_glXGetAGPOffsetMESA
#endif
#endif

/* GLX_EXT_fbconfig_packed_float */

#ifndef GLX_EXT_fbconfig_packed_float
#define GLX_EXT_fbconfig_packed_float 1
#define __GLEE_GLX_EXT_fbconfig_packed_float 1
/* Constants */
#define GLX_RGBA_UNSIGNED_FLOAT_TYPE_EXT                   0x20B1
#define GLX_RGBA_UNSIGNED_FLOAT_BIT_EXT                    0x00000008
#endif

/* GLX_EXT_framebuffer_sRGB */

#ifndef GLX_EXT_framebuffer_sRGB
#define GLX_EXT_framebuffer_sRGB 1
#define __GLEE_GLX_EXT_framebuffer_sRGB 1
/* Constants */
#define GLX_FRAMEBUFFER_SRGB_CAPABLE_EXT                   0x20B2
#endif

/* GLX_EXT_texture_from_pixmap */

#ifndef GLX_EXT_texture_from_pixmap
#define GLX_EXT_texture_from_pixmap 1
#define __GLEE_GLX_EXT_texture_from_pixmap 1
/* Constants */
#define GLX_TEXTURE_1D_BIT_EXT                             0x00000001
#define GLX_TEXTURE_2D_BIT_EXT                             0x00000002
#define GLX_TEXTURE_RECTANGLE_BIT_EXT                      0x00000004
#define GLX_BIND_TO_TEXTURE_RGB_EXT                        0x20D0
#define GLX_BIND_TO_TEXTURE_RGBA_EXT                       0x20D1
#define GLX_BIND_TO_MIPMAP_TEXTURE_EXT                     0x20D2
#define GLX_BIND_TO_TEXTURE_TARGETS_EXT                    0x20D3
#define GLX_Y_INVERTED_EXT                                 0x20D4
#define GLX_TEXTURE_FORMAT_EXT                             0x20D5
#define GLX_TEXTURE_TARGET_EXT                             0x20D6
#define GLX_MIPMAP_TEXTURE_EXT                             0x20D7
#define GLX_TEXTURE_FORMAT_NONE_EXT                        0x20D8
#define GLX_TEXTURE_FORMAT_RGB_EXT                         0x20D9
#define GLX_TEXTURE_FORMAT_RGBA_EXT                        0x20DA
#define GLX_TEXTURE_1D_EXT                                 0x20DB
#define GLX_TEXTURE_2D_EXT                                 0x20DC
#define GLX_TEXTURE_RECTANGLE_EXT                          0x20DD
#define GLX_FRONT_LEFT_EXT                                 0x20DE
#define GLX_FRONT_RIGHT_EXT                                0x20DF
#define GLX_BACK_LEFT_EXT                                  0x20E0
#define GLX_BACK_RIGHT_EXT                                 0x20E1
#define GLX_FRONT_EXT                                      GLX_FRONT_LEFT_EXT
#define GLX_BACK_EXT                                       GLX_BACK_LEFT_EXT
#define GLX_AUX0_EXT                                       0x20E2
#define GLX_AUX1_EXT                                       0x20E3
#define GLX_AUX2_EXT                                       0x20E4
#define GLX_AUX3_EXT                                       0x20E5
#define GLX_AUX4_EXT                                       0x20E6
#define GLX_AUX5_EXT                                       0x20E7
#define GLX_AUX6_EXT                                       0x20E8
#define GLX_AUX7_EXT                                       0x20E9
#define GLX_AUX8_EXT                                       0x20EA
#define GLX_AUX9_EXT                                       0x20EB
#ifndef GLEE_H_DEFINED_glXBindTexImageEXT
#define GLEE_H_DEFINED_glXBindTexImageEXT
  typedef void (APIENTRYP GLEEPFNGLXBINDTEXIMAGEEXTPROC) (Display * dpy, GLXDrawable drawable, int buffer, const int * attrib_list);
  GLEE_EXTERN GLEEPFNGLXBINDTEXIMAGEEXTPROC GLeeFuncPtr_glXBindTexImageEXT;
  #define glXBindTexImageEXT GLeeFuncPtr_glXBindTexImageEXT
#endif
#ifndef GLEE_H_DEFINED_glXReleaseTexImageEXT
#define GLEE_H_DEFINED_glXReleaseTexImageEXT
  typedef void (APIENTRYP GLEEPFNGLXRELEASETEXIMAGEEXTPROC) (Display * dpy, GLXDrawable drawable, int buffer);
  GLEE_EXTERN GLEEPFNGLXRELEASETEXIMAGEEXTPROC GLeeFuncPtr_glXReleaseTexImageEXT;
  #define glXReleaseTexImageEXT GLeeFuncPtr_glXReleaseTexImageEXT
#endif
#endif

/* GLX_NV_present_video */

#ifndef GLX_NV_present_video
#define GLX_NV_present_video 1
#define __GLEE_GLX_NV_present_video 1
/* Constants */
#define GLX_NUM_VIDEO_SLOTS_NV                             0x20F0
#endif

/* GLX_NV_video_out */

#ifndef GLX_NV_video_out
#define GLX_NV_video_out 1
#define __GLEE_GLX_NV_video_out 1
/* Constants */
#define GLX_VIDEO_OUT_COLOR_NV                             0x20C3
#define GLX_VIDEO_OUT_ALPHA_NV                             0x20C4
#define GLX_VIDEO_OUT_DEPTH_NV                             0x20C5
#define GLX_VIDEO_OUT_COLOR_AND_ALPHA_NV                   0x20C6
#define GLX_VIDEO_OUT_COLOR_AND_DEPTH_NV                   0x20C7
#define GLX_VIDEO_OUT_FRAME_NV                             0x20C8
#define GLX_VIDEO_OUT_FIELD_1_NV                           0x20C9
#define GLX_VIDEO_OUT_FIELD_2_NV                           0x20CA
#define GLX_VIDEO_OUT_STACKED_FIELDS_1_2_NV                0x20CB
#define GLX_VIDEO_OUT_STACKED_FIELDS_2_1_NV                0x20CC
#endif

/* GLX_NV_swap_group */

#ifndef GLX_NV_swap_group
#define GLX_NV_swap_group 1
#define __GLEE_GLX_NV_swap_group 1
/* Constants */
#endif

/* GLX_EXT_scene_marker */

#ifndef GLX_EXT_scene_marker
#define GLX_EXT_scene_marker 1
#define __GLEE_GLX_EXT_scene_marker 1
/* Constants */
#endif

/* GLX_NV_video_output */

#ifndef GLX_NV_video_output
#define GLX_NV_video_output 1
#define __GLEE_GLX_NV_video_output 1
/* Constants */
#define GLX_VIDEO_OUT_COLOR_NV                             0x20C3
#define GLX_VIDEO_OUT_ALPHA_NV                             0x20C4
#define GLX_VIDEO_OUT_DEPTH_NV                             0x20C5
#define GLX_VIDEO_OUT_COLOR_AND_ALPHA_NV                   0x20C6
#define GLX_VIDEO_OUT_COLOR_AND_DEPTH_NV                   0x20C7
#define GLX_VIDEO_OUT_FRAME_NV                             0x20C8
#define GLX_VIDEO_OUT_FIELD_1_NV                           0x20C9
#define GLX_VIDEO_OUT_FIELD_2_NV                           0x20CA
#define GLX_VIDEO_OUT_STACKED_FIELDS_1_2_NV                0x20CB
#define GLX_VIDEO_OUT_STACKED_FIELDS_2_1_NV                0x20CC
#ifndef GLEE_H_DEFINED_glXGetVideoDeviceNV
#define GLEE_H_DEFINED_glXGetVideoDeviceNV
  typedef int (APIENTRYP GLEEPFNGLXGETVIDEODEVICENVPROC) (Display * dpy, int screen, int numVideoDevices, GLXVideoDeviceNV * pVideoDevice);
  GLEE_EXTERN GLEEPFNGLXGETVIDEODEVICENVPROC GLeeFuncPtr_glXGetVideoDeviceNV;
  #define glXGetVideoDeviceNV GLeeFuncPtr_glXGetVideoDeviceNV
#endif
#ifndef GLEE_H_DEFINED_glXReleaseVideoDeviceNV
#define GLEE_H_DEFINED_glXReleaseVideoDeviceNV
  typedef int (APIENTRYP GLEEPFNGLXRELEASEVIDEODEVICENVPROC) (Display * dpy, int screen, GLXVideoDeviceNV VideoDevice);
  GLEE_EXTERN GLEEPFNGLXRELEASEVIDEODEVICENVPROC GLeeFuncPtr_glXReleaseVideoDeviceNV;
  #define glXReleaseVideoDeviceNV GLeeFuncPtr_glXReleaseVideoDeviceNV
#endif
#ifndef GLEE_H_DEFINED_glXBindVideoImageNV
#define GLEE_H_DEFINED_glXBindVideoImageNV
  typedef int (APIENTRYP GLEEPFNGLXBINDVIDEOIMAGENVPROC) (Display * dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
  GLEE_EXTERN GLEEPFNGLXBINDVIDEOIMAGENVPROC GLeeFuncPtr_glXBindVideoImageNV;
  #define glXBindVideoImageNV GLeeFuncPtr_glXBindVideoImageNV
#endif
#ifndef GLEE_H_DEFINED_glXReleaseVideoImageNV
#define GLEE_H_DEFINED_glXReleaseVideoImageNV
  typedef int (APIENTRYP GLEEPFNGLXRELEASEVIDEOIMAGENVPROC) (Display * dpy, GLXPbuffer pbuf);
  GLEE_EXTERN GLEEPFNGLXRELEASEVIDEOIMAGENVPROC GLeeFuncPtr_glXReleaseVideoImageNV;
  #define glXReleaseVideoImageNV GLeeFuncPtr_glXReleaseVideoImageNV
#endif
#ifndef GLEE_H_DEFINED_glXSendPbufferToVideoNV
#define GLEE_H_DEFINED_glXSendPbufferToVideoNV
  typedef int (APIENTRYP GLEEPFNGLXSENDPBUFFERTOVIDEONVPROC) (Display * dpy, GLXPbuffer pbuf, int iBufferType, unsigned long * pulCounterPbuffer, GLboolean bBlock);
  GLEE_EXTERN GLEEPFNGLXSENDPBUFFERTOVIDEONVPROC GLeeFuncPtr_glXSendPbufferToVideoNV;
  #define glXSendPbufferToVideoNV GLeeFuncPtr_glXSendPbufferToVideoNV
#endif
#ifndef GLEE_H_DEFINED_glXGetVideoInfoNV
#define GLEE_H_DEFINED_glXGetVideoInfoNV
  typedef int (APIENTRYP GLEEPFNGLXGETVIDEOINFONVPROC) (Display * dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo);
  GLEE_EXTERN GLEEPFNGLXGETVIDEOINFONVPROC GLeeFuncPtr_glXGetVideoInfoNV;
  #define glXGetVideoInfoNV GLeeFuncPtr_glXGetVideoInfoNV
#endif
#endif
#endif /*end GLX */

/*****************************************************************
 * GLee functions
 *****************************************************************/

GLEE_EXTERN GLboolean GLeeInit( void );
GLEE_EXTERN GLint GLeeForceLink(const char * extensionName);
GLEE_EXTERN const char * GLeeGetErrorString( void );
GLEE_EXTERN const char * GLeeGetExtStrGL( void );
GLEE_EXTERN GLboolean GLeeEnabled(GLboolean * extensionQueryingVariable);

#ifdef WIN32
GLEE_EXTERN const char * GLeeGetExtStrWGL( void );
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else
GLEE_EXTERN const char * GLeeGetExtStrGLX( void );
#endif

#ifdef __cplusplus
}	/* end C linkage */
#endif

#endif /* __glee_h_ defined */
