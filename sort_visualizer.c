#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define WIDTH 900
#define HEIGHT 600
#define NUM_BLOCKS 80
#define GROUND_DISTANCE 700

typedef struct{

	Color color;
	int height;
	float width;
	float x;
	float y;

}Block;

Block arr[NUM_BLOCKS];

void PlaySortingSound(int height) {
	
	float frequency = 200.0f + (float)height * 4.0f;
	Wave wave = LoadWave("beep.wav"); 	      
	Sound sound = LoadSoundFromWave(wave);
	float novoPitch = 0.5f + ((float)height / 200.0f);
	SetSoundPitch(sound, novoPitch);
	PlaySound(sound);
	UnloadWave(wave);

}

void create_block_array(){
	
	int space = (NUM_BLOCKS-1) * 5, x = 100;
	float total_space = GROUND_DISTANCE - (float)space;
       	float block_width = total_space / NUM_BLOCKS;
		
	for(int i = 0; i < NUM_BLOCKS; i++){
		
		int height = rand()%190 + 10;
		arr[i] = (Block){WHITE, height, block_width,
		       	(float)x, 400-(float)height};
		x += block_width + 5;

	}

}

void print_blocks(){

	for(int i = 0; i < NUM_BLOCKS; i++){
	
		printf("HEIGHT: %d,  WIDTH: %2.f, X: %2.f, Y: %2.f \n",
				arr[i].height, arr[i].width, arr[i].x, arr[i].y);

	}

}

void draw_ground(){

	DrawRectangle(100, 400, GROUND_DISTANCE, 10, WHITE);

}

void draw_blocks(){

	draw_ground();
	for(int i = 0; i < NUM_BLOCKS; i++){
	
		DrawRectangle(arr[i].x, arr[i].y, arr[i].width,
			       	arr[i].height, arr[i].color);
	
	}
}

void draw_sorted_blocks(){

	for(int i = 0; i < NUM_BLOCKS; i++){
		BeginDrawing();
		draw_blocks();
		arr[i].color = GREEN;
		PlaySortingSound(arr[i].height);
		ClearBackground(BLACK);
		EndDrawing();
		usleep(100000);
	}

}

int sort_array(){

	int aux;
	float y;
	int ShouldClose = 0;
	for(int i = 0; i < NUM_BLOCKS-1;  i++){
		arr[i].color = GREEN;
		ShouldClose = WindowShouldClose();
		for(int j = i+1; j < NUM_BLOCKS; j++){
			ShouldClose = WindowShouldClose();
			arr[j].color = RED;
			BeginDrawing();
			draw_blocks();
			PlaySortingSound(arr[j].height);	
			if(i != j){
				if(arr[i].height > arr[j].height){
				
					aux = arr[i].height;
					y = arr[i].y;
					arr[i].height = arr[j].height;
					arr[i].y = arr[j].y;
					arr[j].height = aux;
					arr[j].y = y;

				}
			if(ShouldClose){
			
				break;
			
			}
			ClearBackground(BLACK);
			EndDrawing();
			arr[j].color = WHITE;
			usleep(10000);
			}

		}
		if(ShouldClose){
		
			break;

		}
		arr[i].color = WHITE;
	}
	return ShouldClose;
}


int main(){

srand(time(NULL));
InitWindow(WIDTH, HEIGHT, "Sort Visualizer");
InitAudioDevice();
SetTargetFPS(60);
create_block_array();
print_blocks();
	while(!WindowShouldClose()){
		
		int x = sort_array();

		if(x == 1){
		
			break;

		}
		draw_sorted_blocks();
		break;
	}	
CloseAudioDevice();
CloseWindow();
}
