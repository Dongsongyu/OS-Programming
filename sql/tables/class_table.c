/*************************************************************************
	> File Name: students_table.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Aug 2024 07:53:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include "database.h"

static const char *table_name = "class table";
static const char *table_file = "./data/class_data.dat";
static const char *header_name[] = {"name", "No.Stu", "master"};
static const int  *header_len[] = {8,6,8};

typedef struct {
    char name[20];
    int NoStu;
    char master[20];
} table_data;

#include "table_unit.q"

static void printData(void *__data)
{
    table_data *data = (table_data *)(__data);
    char frm[100];
    sprintf(frm,"%%%ds|%%%dd|%%%ds|\n",
           header_len[0],header_len[1],header_len[2]);
    printf(frm,data->name,data->NoStu,data->master);
    printf("\n");

    return ;
}

static void scanData(void *__data)
{
    table_data *data = (table_data *)(__data);
    scanf("%s%d%s",
         data->name,&(data->NoStu),
         data->master
         );
    return sizeof(table_data);
}

