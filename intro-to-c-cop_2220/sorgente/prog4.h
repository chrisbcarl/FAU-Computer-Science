#ifndef SORGENTE_PROG4
#define SORGENTE_PROG4

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define SIZE2 100

typedef struct lol {
	int a;
} lol;

typedef struct {
	int a;
} kk;


typedef struct Song
{
	char title[SIZE2];
	char artist[SIZE2];
	char album[SIZE2];
	int year;
	double cost;

} Song;


//print operations
void print(Song song);
void print_Pointerstyle(Song * song);

//create operations
Song getASong();
void input(Song * song);



int prog4() {
	Song list[SIZE2];
	Song song1 = {"", "", "", 0, 0};

	
	
	//HARDCODING option 1
	Song song2;
	strcpy(song2.title, "Immigrant Song");
	strcpy(song2.album, "Led Zepplin III");
	strcpy(song2.artist, "Led Zepplin");
	song2.year = 1970;
	song2.cost = 1.94;
	list[2] = song2;
	//song2 exists in reality
	//list[1], an empty song already exists in reality
	//now we replace list[1] with another real song

	//HARDCODING option 2
	Song song3 = {"Taco Bell", "Fast Food", "America", 2000, 3.83};

	


	list[1] = song1;
	list[3] = song3;

	//HARDCODING
	//list[3] already existed in reality,
	//now we're just updating its contents
	strcpy(list[3].title, "Stairway to Heaven");
	strcpy(list[3].album, "Led Zepplin IV");
	strcpy(list[3].artist, "Led Zepplin");
	list[3].year = 1974;
	list[3].cost = 1.99;

	print(song2);
	print(list[3]);

	list[4] = getASong();
	Song song5 = { "", "", "", 0, 0.0 };
	input(&song5);				//!HARDCODING, using alternate array access
	list[5] = song5;
	input(&list[6]);			//!HARDCODING

	input(&list[0]);

	for (int i = 0; i < 7; i++)
	{
		print(list[i]);
	}




	return 0;
}

//strcpy
//strcat
//strlen
//strcmp


void print(Song song)
{
	printf("%s\n", song.title);
	printf("%s\n", song.artist);
	printf("%s\n", song.album);
	printf("%d\n", song.year);
	printf("$%0.2lf\n", song.cost);
}

void print_Pointerstyle(Song * song)
{
	//when struct is a pointer
	//struct->attribute is the same things as saying (*struct).attribute
	printf("%s\n", song->title);
	printf("%s\n", song->artist);
	printf("%s\n", (*song).album);
	printf("%d\n", (*song).year);
	printf("$%0.2lf\n", song->cost);
}


Song getASong()
{
	Song song;
	printf("song.title ");	scanf(" %s", &song.title);
	printf("song.artist ");	scanf(" %s", &song.artist);
	printf("song.album ");	scanf(" %s", &song.album);
	printf("song.year ");	scanf(" %d", &song.year);
	printf("song.cost ");	scanf(" %lf", &song.cost);
	return song;
}
void input(Song * song)
{
	printf("song.title ");	scanf(" %s", song->title);
	printf("song.artist ");	scanf(" %s", song->artist);
	printf("song.album ");	scanf(" %s", song->album);
	printf("song.year ");	
	scanf(" %d", &song->year);
	printf("song.cost ");	
	scanf(" %lf", &song->cost);
}

#endif