/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:49:52 by kdahl             #+#    #+#             */
/*   Updated: 2020/10/03 20:01:09 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include "../minilibx/mlx.h"

typedef	struct		s_sprites
{
	float			sprite_x;
	float			sprite_y;
	float			sprite_dist;
	float			sprite_screen_size;
	float			sprite_dir;
	int				sprite_text;
	int				h_offset;
	int				v_offset;
	int				sprites;
	int				sprites_die;
}					t_sprites;

typedef struct		s_cub3d
{
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		posa;
	float		raya;
	void		*mlx_ptr;
	void		*window_ptr;
	void		*image_ptr;
	void		*t_img0;
	void		*t_img1;
	void		*t_img2;
	void		*t_img3;
	void		*st_img;
	void		*pistol_ptr;
	void		*pistol_ptr2;
	void		*pistol_ptr3;
	void		*pistol_ptr4;
	void		*life_ptr100;
	void		*life_ptr90;
	void		*life_ptr80;
	void		*life_ptr70;
	void		*life_ptr60;
	void		*life_ptr50;
	void		*life_ptr40;
	void		*life_ptr30;
	void		*life_ptr20;
	void		*life_ptr10;
	void		*life_ptr0;
	void		*dead;
	char		*img_texture;
	char		*texture_adr0;
	char		*texture_adr1;
	char		*texture_adr2;
	char		*texture_adr3;
	char		*texture_adr4;
	char		*stexture_adr;
	char		*pistol_adr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			t_bits_per_pixel;
	int			t_size_line;
	int			t_endian;
	int			st_bits_per_pixel;
	int			st_size_line;
	int			st_endian;
	int			mapwidth;
	int			mapheight;
	int			worldmap[500][500];
	int			screenwidth;
	int			screenheight;
	int			firstmapstr;
	int			lastmapstr;
	int			error;
	int			t_width;
	int			t_height;
	int			st_width;
	int			st_height;
	int			p_width;
	int			p_height;
	int			l_width;
	int			l_height;
	int			f_width;
	int			f_height;
	int			x_texcoord;
	int			ray_array[5000];
	int			pressed;
	int			side;
	int			cell_x_len;
	int			cell_y_len;
	int			sprites_num;
	int			sprites_pars;
	int			sprites_eaten;
	int			map_len;
	int			map_heigh;
	int			player_foud;
	int			map_found;
	int			play_music;
	char		nopath[100];
	char		sopath[100];
	char		wepath[100];
	char		eapath[100];
	char		spath[100];
	int			f_color;
	int			c_color;
	int			rem;
	int			index;
	float		hx;
	float		hy;
	float		hitx;
	float		hity;
	int			bmp;
	int			posx_w;
	int			posy_w;
	float		delta_w;
	int			mouse_on;
	int			gun_pos;
	int			damage;
	int			dam_end;
	int			max_screen_w;
	int			max_screen_h;
	int			music;
	t_sprites	sprites[100];
}					t_cub3d;

t_cub3d				init_cub3d_struct(void);
void				printerror(t_cub3d *cub3d, int errcase);
void				draw3dsky(float lineh, float lineo, int r, t_cub3d *cub3d);
void				draw3dfloor(float lineh, float
								lineo, int r, t_cub3d *cub3d);
void				drawwall3d(float lineh, float lineo, t_cub3d *cub3d, int r);
void				draw3dscene(float raydist, int r, t_cub3d *cub3d);
void				drawrays3d(t_cub3d *cub3d);
void				calcsprite(t_cub3d *cub3d);
void				calcspritesparams(t_cub3d *cub3d, float fov);
void				sortsprites(t_cub3d *cub3d);
void				drawsprite(t_cub3d *cub3d);
void				drawsprite2(t_cub3d *cub3d, int j, int i);
void				drawit(int i, int j, t_cub3d *cub3d);
void				rendersprites(t_cub3d *cub3d);
void				findplayer(t_cub3d *cub3d);
void				mlx_mainloop(t_cub3d *cub3d);
void				cub3d_engine(t_cub3d *cub3d);
void				getsouth(char *line, t_cub3d *cub3d);
void				mouse(t_cub3d *cub3d);
void				life(t_cub3d *cub3d);
void				pistol(t_cub3d *cub3d);
void				damage_process(t_cub3d *cub3d);
void				eat_sprites(t_cub3d *cub3d);
void				sprites_r_eaten(t_cub3d *cub3d);
void				key_rrotate(t_cub3d *cub3d);
void				key_lrotate(t_cub3d *cub3d);
void				sounds_setting(t_cub3d *cub3d);
void				eat_sprites(t_cub3d *cub3d);
void				put_string_smallwindow(t_cub3d *cub3d);
void				sprites_r_eaten(t_cub3d *cub3d);
void				check_window(t_cub3d *cub3d);
void				if_error(t_cub3d *cub3d);
char				setplayerangle(float angle, t_cub3d *cub3d);
char				checkplayermap(char word, t_cub3d *cub3d);
char				checkmapifcase(char *line, t_cub3d *cub3d);
unsigned long		creatergb(int r, int g, int b);
float				dist(float x1, float y1, float x2, float y2);
float				get_aim(t_cub3d *cub3d);
int					get_life(t_cub3d *cub3d);
int					checkmap(char *line, t_cub3d *cub3d);
int					checkresolution(char *line, t_cub3d *cub3d);
int					getpath(char *line, t_cub3d *cub3d);
int					path2sprite(char *line, t_cub3d *cub3d);
int					path2north(char *line, t_cub3d *cub3d);
int					path2south(char *line, t_cub3d *cub3d);
int					path2west(char *line, t_cub3d *cub3d);
int					path2east(char *line, t_cub3d *cub3d);
int					getfloorcolor(char *line, t_cub3d *cub3d);
int					getceillingcolor(char *line, t_cub3d *cub3d);
int					checkline(char *line, t_cub3d *cub3d);
int					argparser(char **argv, t_cub3d *cub3d);
int					getspritetext(t_cub3d *cub3d);
int					gettexture(t_cub3d *cub3d);
int					maprender(t_cub3d *cub3d);
int					iswall(t_cub3d *cub3d, int key);
int					keyboard(int key, t_cub3d *cub3d);
int					checkmapagain(t_cub3d *cub3d);
int					main(int argc, char **argv);
int					close_event(t_cub3d *cub3d);
int					bmp_parser(char **argv2, t_cub3d *cub3d);
int					create_bitmap(t_cub3d *cub3d, char *name);
int					mouse_on(t_cub3d *cub3d);
int					get_pistol(t_cub3d *cub3d);
int					retry(int key, t_cub3d *cub3d);
int					shooting_process(t_cub3d *cub3d);
int					key_shot(int un_use, int x, int y, t_cub3d *cub3d);
int					go_leftright(t_cub3d *cub3d);
int					go_straight(t_cub3d *cub3d);
int					go_back(t_cub3d *cub3d);
int					is_map_last(t_cub3d *cub3d);
int					if_resol(t_cub3d *cub3d);

#endif
