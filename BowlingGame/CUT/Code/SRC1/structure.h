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
     int frame_and_cumulative_score[2][10];  // row 1: stores frame and row2 : stores cumulative
     int current_tournament;
     int total_score;
     struct bowling_database *next;
}bd1;
bd1 *start1;

// functions from maintain_database_function.c
int add_bowler();
int edit_information();
int delete_bowler();
int view_bowler_information();

// functions from bowler_file_handling.c
int bowler_to_list();
int list_to_bowler();

// functions from bowling_file_handling.c
int bowling_to_list();
int list_to_bowling();


// function from play_the_game_function.c
int play_the_game_function(int);
int random_number();
int strike_condition(int,int);
int spare_condition(int,int);
int extra_balls(int);

// functions from show_report.c
int Bowler_data_sheet();
int Bowling_day_report();

// functions from main.c
int maintain_database(); //function for first option to show options
int play_the_game(); // function for second option
int show_reports(); //function for third option
int make_current_tournament_zero();


#define SIZE 20
#define MAX 15



#endif

