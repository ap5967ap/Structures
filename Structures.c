#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{ //defining a structure student 
    char name[20];  //stores names of student
    int id;         //stores id of student
    float marks;    //stores marks of student
}student;

void get_data(student *student_instance, FILE *ptr){ //function to get data from file to a structure
    fscanf(ptr, "%s %d %f", student_instance->name, &student_instance->id, &student_instance->marks);
}
void get_data_array(student data[], FILE *ptr, int n){ //function to get data from file into array of structures
    for(int i = 0; i < n; i++){
        get_data(&data[i],ptr); //adding data to array of structure at each index
    }
}

void sort(student data[], int n){ //sort to sort array of structures
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (data[i].id > data[j].id){//Selection Sort
                student temp=data[i]; //Swap if necessary
                data[i]=data[j];
                data[j]=temp;
            }
        }   
    }
}
void output_file(student data[], int n, FILE *ptr){ //creates an output file "output_file.txt"
    for (int i = 0; i < n; i++)
    {
        fprintf(ptr,"%s %d %.0f\n",data[i].name,data[i].id,data[i].marks);
    }
}
int main(){
    int n; //stores size of array of structures
    FILE *ptr=fopen("input_file.txt","r"); //File pointer to "input_file.txt"
    if (ptr==NULL) //file can't be opened properly
        printf("Error: Could not open input file");
    fscanf(ptr,"%d",&n);//input n from "input_file.txt" 
    student *data=(student *)malloc(n*sizeof(student)); //creating an array of structures in heap (malloc-ed)
    get_data_array(data,ptr,n); //stores data in array of structures
    sort(data,n); //sorting array based on id
    FILE *ptr2=fopen("output_file","w+"); //pointer to "output_file.txt"
    if(ptr2==NULL)//file can't be opened properly
        printf("Error: Could not open output file");
    output_file(data, n, ptr2);//printing output in "output_file.txt"
    
return 0;
}