/*************************************************************************
	> File Name: students_table.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Aug 2024 07:53:44 PM CST
 ************************************************************************/


static void init_table(struct Database *);
static size_t getDataSize();
static void printData(void *);
static void scanData(void *);

__attribute__((constructor))
static void __register_table(){
    register_table(table_name , init_table);
    return ;
}

void init_table(struct Database *db){
    db->table_name = table_name;
    db->table_file = table_file;
    db->getDataSize = getDataSize;
    db->scanData = scanData;
    db->printData = printData;
    db->header_name = header_name;
    db->header_len = header_len;
    db->header_cnt = sizeof(header_len)/sizeof(header_len[0]);

    return ;
}

static size_t getDataSize()
{
    return sizeof(table_data);
}


