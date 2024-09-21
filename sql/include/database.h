/*************************************************************************
	> File Name: database.h
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Aug 2024 06:07:42 PM CST
 ************************************************************************/

#ifndef _DATABASE_H
#define _DATABASE_H

struct Database;

typedef void(*InitTable_T)(struct Database *);

enum OP_TYPE{
    CHOOSE_TABLE,
    TABLE_USAGE,
    OP_END,
    LIST_TABLE,
    ADD_TABLE,
    MODIFY_TABLE,
    DELETE_TABLE
};

struct table_data{
    void *data;
    long offset;
    struct table_data *next;
};

struct TableInfo{
    const char *table_name;
    InitTable_T init_table;
};

struct Database {
    FILE *table;
    const char *table_name;
    const char *table_file;
    const char **header_name;
    int header_cnt;
    int *header_len;
    struct table_data head;
    size_t (*getDataSize)();
    void (*printData)(void *);
    void (*scanData)(void *);
};

void run_database();
void register_table(const char *, InitTable_T);

//唯一变量,避免重复定义;
extern struct Database db;

#endif
