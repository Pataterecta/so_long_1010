#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <unistd.h>
// # include <fcnt1.h>
// # include <mlx.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
// # include "../libraries/Libft/libft.h"
# define KEY_ESC 65307       // 우분투 ESC 키
# define KEY_W 119           // 우분투 W 키
# define KEY_S 115           // 우분투 S 키
# define KEY_A 97            // 우분투 S 키
# define KEY_D 100           // 우분투 S 키
# define PRESS_RED_BUTTON 33 //

typedef struct s_param
{
	int		fd;
	char	*result;
	char	**splited_res;
	int		n_of_lines;
	int		count_e;
	int		count_p;
	int		count_c;
	int		move;
	int		p_x;
	int		p_y;
	int		C;
	int		P;
	int		E;
	int		win_height;
	int		win_width;
	int		he;
	int		wi;
	int		x;
	int		y;
	void	*g;
	void	*w;
	void	*p;
	void	*c;
	void	*e;
	void	*mlx;
	void	*mlx_win;
	void	*win;
	void *img; // 이미지 객체
	// char    *addr;          // 이미지 데이터의 시작 주소
	int bits_per_pixel; // 한 픽셀당 비트 수
	int line_length;    // 한 줄의 길이 (바이트 단위)
	int endian;         // 엔디안 정보 (픽셀 데이터의 순서)
}			t_param;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

//초기화 함수 만들기
//프리 함수 필요 - malloc 들어간애들, 구조체 자체
//나가는 함수
// checker.c
int			middle_lines(t_param *par);
int			count_compo(t_param *par);
int			length_compare(t_param *par);
int			map_checker(t_param *par);
// checker2.c
int			check_element_map(t_param *par);
int			check_empty_line(t_param *par);
int			check_all_ones(char *str);
int			check_one_boundaries(char *str);
void		howmanylines(t_param *par);
// map_read.c
int			add_lines(t_param *par);
// void error_message(const char *message);
// ft_split.c
size_t		ft_strlcpy(char *dst, const char *src, size_t len);
// static size_t	get_word_cnt(char const *str, char c);
// static void	*is_free(char **str, int str_index);
// static char	**set_worddup(char const *s, char c, char **mem);
char		**ft_split(char const *s, char c);
// image.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		error_message(const char *msg);
// set_param.c
void		set_param(t_param *par);
// xy.c
int			key_press(int keycode, t_param *par);
void	move_left(t_param *par, int y);  // 왼쪽으로 이동
void	move_right(t_param *par, int y); // 오른쪽으로 이동
void	move_up(t_param *par, int y);    // 위로 이동하는 함수
void		move_down(t_param *par, int y);
// gnl
char		*get_next_line(int fd);
char		*ft_get_backup(char *backup);
char		*ft_file_read(int fd, char *backup, char *buf);
char		*ft_get_line(char *backup);
size_t		ft_strlen(const char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);

#endif