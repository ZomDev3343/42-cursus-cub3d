#include "../../include/cub3d.h"
#include <math.h>

void sortSprites(int* order, float* dist, int amount)
{
    // Create an array of pairs
    struct Sprite {
        float dist;
        int order;
    } *sprites;
    
    sprites = (struct Sprite*)malloc(amount * sizeof(struct Sprite));
    if (sprites == NULL) {
        // Handle memory allocation failure
        return;
    }
    
    // Populate the array
    for (int i = 0; i < amount; i++) {
        sprites[i].dist = dist[i];
        sprites[i].order = order[i];
    }
    
    // Sort the array based on distances
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (sprites[j].dist < sprites[j + 1].dist) {
                struct Sprite temp = sprites[j];
                sprites[j] = sprites[j + 1];
                sprites[j + 1] = temp;
            }
        }
    }
    
    // Restore sorted values back to the input arrays
    for (int i = 0; i < amount; i++) {
        dist[i] = sprites[i].dist;
        order[i] = sprites[i].order;
    }
    
    free(sprites);
}

int int_abs(int value) {
    return (value < 0) ? -value : value;
}

void	draw_sprite(t_global *global, t_image *image)
{
	int	i;
	int	spriteOrder[global->n_sprites];
	float	spriteDistance[global->n_sprites];

	i = 0;
	while (i < global->n_sprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((global->player.y - global->sprites[i].x) * (global->player.y - global->sprites[i].x) +
				(global->player.x - global->sprites[i].y) * (global->player.x - global->sprites[i].y));
		i++;
	}
	sortSprites(spriteOrder, spriteDistance, global->n_sprites);
	
	i = 0;
	while (i < global->n_sprites)
	{
		float spriteX = global->sprites[spriteOrder[i]].x - global->player.y;
      		float spriteY = global->sprites[spriteOrder[i]].y - global->player.x;

		//printf("Sprite %d, distance: %f\n", spriteOrder[i], spriteDistance[i]);
		//printf("planeX: %f, dirX: %f, planeY: %f, dirY: %f\n", global->player.plane_x, global->player.dir_x, global->player.plane_y, global->player.dir_y);

		float invDet = 1.0 / (global->player.plane_y * global->player.dir_x - global->player.dir_y * global->player.plane_x);
		float transformX = -invDet * (global->player.dir_x * spriteX - global->player.dir_y * spriteY);
      		float transformY = invDet * (-global->player.plane_x * spriteX + global->player.plane_y * spriteY);
		int spriteScreenX = (int)((global->win_width / 2) * (1 + transformX / transformY));

		printf("%d spriteX:%d transformX: %f, transformY: %f\n",i, spriteScreenX, transformX, transformY);
		#define uDiv 1
      		#define vDiv 1
      		#define vMove 0.0
      		int vMoveScreen = (int)(vMove / transformY);

		int spriteHeight = int_abs((int)(global->win_height / (transformY))) / vDiv;
		int	drawStartY;
		if (spriteHeight == -2147483648)
			drawStartY = spriteHeight / 2 + global->win_height/ 2 + vMoveScreen;
		else
			drawStartY = -spriteHeight / 2 + global->win_height/ 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int	drawEndY;
		if (spriteHeight == -2147483648)
     			drawEndY = -spriteHeight / 2 + global->win_height / 2 + vMoveScreen;
		else
			drawEndY = spriteHeight / 2 + global->win_height / 2 + vMoveScreen;
		if(drawEndY >= global->win_height) drawEndY = global->win_height - 1;

		int spriteWidth = int_abs((int) (global->win_height / (transformY))) / uDiv;
		

      		int drawStartX = -spriteWidth / 2 + spriteScreenX;
     // printf("drawStartX: %d, -spriteWidth: %d, spriteScreenX: %d\n", drawStartX, -spriteWidth, spriteScreenX);

		//int	drawStartX;
		//if (spriteHeight == -2147483648)
      		//	drawStartX = spriteWidth / 2 + spriteScreenX;
		//else
		//	drawStartX = -spriteWidth / 2 + spriteScreenX;
      		if(drawStartX < 0) drawStartX = 0;

      		int drawEndX;
		if (spriteHeight == -2147483648)
	       		drawEndX = -spriteWidth / 2 + spriteScreenX;
		else
			drawEndX = spriteWidth / 2 + spriteScreenX;
      		if(drawEndX > global->win_width) drawEndX = global->win_width;
		
		//printf("drawStartX = %d\n", drawStartX);
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      		{
			int texX;
			if (spriteWidth == -2147483648)
        			texX = (int)(256 * (stripe - (spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
			else
				texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;

        		if(transformY > 0 && transformY < global->zbuffer[stripe])
       			{
          			for(int y = drawStartY; y < drawEndY; y++)
          			{
					(void) image;
					int texY;
					int d;
						d = (y - vMoveScreen) * 256 - global->win_height * 128 + spriteHeight * 128;
            					texY = ((d * 64) / spriteHeight) / 256;
            				int color = get_pixel_color(&global->sprites[i].texture, texX, texY);
            				if(color)
					{
//						printf("y = %d, stripe = %d, color = %d\n", y, stripe, color);
						draw_pixel(image, stripe, y, color);
					}
          			}
        		}
      		}
		i++;
	}
}
