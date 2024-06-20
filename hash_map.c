// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdint.h>
// #include <stdbool.h>

// #define MAX_NAME 256
// #define TABLE_SIZE 10
// #define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFUL)

// typedef struct
// {
//   char name[MAX_NAME];
//   int age;
// } person;

// person *hash_table[TABLE_SIZE];

// unsigned int hash(char *name)
// {
//   int len = strnlen(name, MAX_NAME);
//   unsigned int hash_value = 0;
//   for (int i = 0; i < len; ++i)
//   {
//     hash_value += name[i];
//     hash_value = (hash_value * name[i]) % TABLE_SIZE;
//   }
//   return hash_value;
// }

// void init_hash_table()
// {
//   for (int i = 0; i < TABLE_SIZE; i++)
//   {
//     hash_table[i] = NULL;
//   }
// }
// void print_table()
// {
//   printf("Start\n");
//   for (int i = 0; i < TABLE_SIZE; i++)
//   {
//     if (hash_table[i] == NULL)
//     {
//       printf("\t%i\t---\n", i);
//     }
//     else if (hash_table[i] == DELETED_NODE)
//     {
//       printf("\t%i\t---<DELETED>\n", i);
//     }
//     else
//     {
//       printf("\t%i\t%s\n", i, hash_table[i]->name);
//     }
//   }
//   printf("End\n");
// }

// bool hash_table_insert(person *p)
// {
//   if (p == NULL)
//     return false;
//   int index = hash(p->name);
//   for (int i = 0; i < TABLE_SIZE; ++i)
//   {
//     int try = (i + index) % TABLE_SIZE;
//     if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
//     {
//       hash_table[try] = p;
//       return true;
//     }
//   }
//   return false;
// }

// person *hash_table_lookup(char *name)
// {
//   int index = hash(name);
//   for (int i = 0; i < TABLE_SIZE; i++)
//   {
//     int try = (i + index) % TABLE_SIZE;
//     if (hash_table[try] == NULL)
//     {
//       return false;
//     }

//     if (hash_table[try] == DELETED_NODE)
//       continue;

//     if (hash_table[try] != NULL && (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0))
//     {
//       return hash_table[try];
//     }
//   }
//   return NULL;
// }

// person *hash_table_delete(char *name)
// {
//   int index = hash(name);
//   for (int i = 0; i < TABLE_SIZE; i++)
//   {
//     int try = (i + index) % TABLE_SIZE;
//     if (hash_table[try] == NULL)
//       return NULL;
//     if (hash_table[try] == DELETED_NODE)
//       continue;
//     if (hash_table[try] != NULL && (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0))
//     {
//       person *tmp = hash_table[try];
//       hash_table[try] = NULL;
//       return tmp;
//     }
//   }
//   return NULL;
// }

// int main()
// {
//   init_hash_table();
//   person jacob = {.name = "Jacob", .age = 24};
//   person kate = {.name = "Kate", .age = 19};
//   person mpho = {.name = "Mpho", .age = 14};
//   person a = {.name = "a", .age = 14};
//   person b = {.name = "b", .age = 14};
//   person c = {.name = "c", .age = 14};
//   person d = {.name = "d", .age = 14};
//   person e = {.name = "e", .age = 14};
//   person f = {.name = "f", .age = 14};

//   hash_table_insert(&jacob);
//   hash_table_insert(&kate);
//   hash_table_insert(&mpho);
//   hash_table_insert(&a);
//   hash_table_insert(&b);
//   hash_table_insert(&c);
//   hash_table_insert(&d);
//   hash_table_insert(&e);
//   hash_table_insert(&f);

//   print_table();

//   person *temp = hash_table_lookup("Mpho");
//   if (temp == NULL)
//   {
//     printf("Not found \n");
//   }
//   else
//   {
//     printf("Found %s.\n", temp->name);
//   }

//   temp = hash_table_lookup("George");
//   if (temp == NULL)
//   {
//     printf("Not found \n");
//   }
//   else
//   {
//     printf("Found %s.\n", temp->name);
//   }

//   hash_table_delete("Mpho");
//   temp = hash_table_lookup("Mpho");
//   if (temp == NULL)
//   {
//     printf("Not found \n");
//   }
//   else
//   {
//     printf("Found %s.\n", temp->name);
//   }
//   print_table();

//   // printf("Jacob => %u\n", hash("Jacob"));
//   // printf("Natalie => %u\n", hash("Natalie"));
//   // printf("Sara => %u\n", hash("Sara"));
//   // printf("Mpho => %u\n", hash("Mpho"));
//   // printf("Tebogo => %u\n", hash("Tebogo"));

//   return 0;
// }