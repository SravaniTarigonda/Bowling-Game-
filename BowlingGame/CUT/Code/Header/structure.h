#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct bowler_database
{
     int bowler_id;
     char bowler_name[20];
     int bowler_experience;
     int no_of_tournaments_won;
     struct bowler_database *next;
}bd;
bd *start;


typedef struct bowling_database
{
     int bowler_id;
     int no_of_strikes;
     int no_of_spares;
     int frame_score[10];  // cumm_array
     int total_score;
     struct bowling_database *next;
}bd1;
bd1 *start1;

// functions from maintain_database_function.c
int add_bowler();
int edit_information();
int delete_bowler();
int view_bowler_information();

// functions from file_handling.c
int file_to_linkedlist();
int linkedlist_to_file();

// function from play_the_game_function.c
int play_the_game_function(int);

// functions from show_report.c
int Bowler_data_sheet();
int Bowling_day_report();

#endif

