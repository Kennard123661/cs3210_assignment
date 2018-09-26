//
// Created by kennard on 25/09/18.
//

#ifndef CS3210_ASSIGNMENT1_STATIONWAIT_H
#define CS3210_ASSIGNMENT1_STATIONWAIT_H

#endif //CS3210_ASSIGNMENT1_STATIONWAIT_H

typedef struct {
    float average_wait_time;// = 0;
    unsigned int min_wait_time;// = 0xFFFFFFFF; // hex code for maximum value that can be represented by 32 bits.
    unsigned int max_wait_time;// = 0;
    unsigned int num_trains_arrive;// = 0;
    unsigned int prev_time_stamp;// = 0;
} StationWait;

void train_arrive(unsigned int time, StationWait* station_wait) {
    unsigned int time_diff = time - station_wait->prev_time_stamp;
    station_wait->prev_time_stamp = time;
    station_wait->num_trains_arrive++;

    // incremental average
    station_wait->average_wait_time = station_wait->average_wait_time * ((float) station_wait->num_trains_arrive - 1) /
            (station_wait->num_trains_arrive) + ((float) time) / station_wait->num_trains_arrive;
    station_wait->max_wait_time = (time > station_wait->max_wait_time) ? time : station_wait->max_wait_time;
    station_wait->min_wait_time = (time < station_wait->min_wait_time) ? time : station_wait->min_wait_time;
}

StationWait* get_station_wait();