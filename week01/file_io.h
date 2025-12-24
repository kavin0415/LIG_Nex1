#pragma once
#ifndef __FILE_IO_H__
#define __FILE_IO_H__
#define USER_NAME_MAX 30

typedef struct user {
    char name[USER_NAME_MAX];
    int score;
}t_user;

#endif