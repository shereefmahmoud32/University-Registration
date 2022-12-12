#include<stdio.h>
#include<string.h>
struct name {

/*struct for the name of student*/

    char first_name [20];
    char middle_name [20];
    char last_name [20];
};

struct reg_num {

/*structure for the registration number of student*/

    char r_n[8];

};

struct nationality {

/*structure for the nationality of student*/

    char nati [20];
};

struct date{

/*structure for the date*/

    int day,month,year;
};

struct id {

/*structure for student id*/

    char type[20];
    char id[15];
    struct date valid;


};

struct address {

/*structure for the home address of student*/

    int F_N,H_N;
    char street[20];
    char Area[20];
    char city[20];
    char governorate[20];
    char country [20];
    char postal_code[10];
};

struct age {

/*structure for student age*/

   struct date age; int agee;
};

struct gender{

/*structure for student gender*/

    char gen[10];
};

struct enrolment{

/*structure for the enrolment term and year,ex; fall 2017.*/

    char term[10];
    int year;
};

struct department_of_enrolment {

/*structure for the department of student*/

    char depart[20];
};

struct tutor {

/*structure for student tutor name and code.*/

    struct name tut_name;
    char tut_code[5];
};

struct current_term{

/*current term of student name and calculated according to credit hours finished*/

    int term;/*calculated by the credit hours finished +1*/
};

struct date_time{

    struct date date_of_trans;/*for the transaction date*/
    int hour,minute,second;
};

struct details{

/*details of each payment*/

    float amount_paid;
    char transaction_number[20];
    char bank_of_trans[30];


struct date_time d;/*declaration for the time/date*/
};

struct payments {

    char type_fund [30];
    int num_of_payments;
    float total_paid;



struct details detail[100];/*declaration for the details of payments*/;
};

struct contact{

/*structure for student contact*/
    char email[50];
    char home_number[20];
    char mobile[20];
};

struct Credit_hours{

/*credit hours that should to be finished*/

    int max_c_hours;
    int finished_c_hours;
    int current_c_hours;
    int remaining;/*should be calculated*/

/*The finished and current hours should be computed from the sum of finished and current courses' credit
hours entered in the field relating to the course finished and current. The remaining hours
should be computed from the equation presented above.*/
};

struct gpa{

/*structure containing the gpa of student*/

    float gpa;
    int semester_finished;
    float gpa_each_term[10];

};

struct course_tutor{

/*structure for tutor details*/

    struct name lecturer;
    struct name GTA;
    struct name lab_GTA;
};

struct Marks_of_student{
/*structure for the marks of student*/
    float seventh,twelveth,year_work,final_grade,sum;
};

struct courses_details{

    char course_code[10];
    char course_name[30];
    int course_credit_hours;
    int number_of_times;/*number of times taking these course*/;
    int semester,year;/*for the finished courses*/


/*declaration for above structures*/
    struct course_tutor t;/*declaration for tutor details*/
    struct Marks_of_student marks;
    char grade[3];
    float student_percentage_absense;
};

struct Courses{

    int number_of_course;
    int total;/*total number of credit hours for these courses*/

struct courses_details d_f[100];/*declaration for the courses finished details*/
struct courses_details d_c[8];/*declaration for the courses current details*/
};

struct student_courses{
    /*declaration for the courses finished and current*/
    struct Courses current;
    struct Courses finished;
};

typedef struct {

    /*declaration for all student data*/

    struct name Student_name;
    struct reg_num Student_reg;
    struct nationality Nationality;
    struct id Id;
    struct address Home_addr;
    struct address Mail_addr;
    struct age Student_age;
    struct gender Student_gender;
    struct enrolment Enrol;
    struct department_of_enrolment Department;
    struct tutor Tut;
    struct current_term Curr_term;
    struct payments Payments_of_student;
    struct contact Student_contact;
    struct Credit_hours Credits;
    struct gpa Student_gpa;
    struct student_courses Courses_of_student;

}Student;



/*-----------------------------------------------------------------------------------*/



                                                    /*functions*/


/* function to read the data of student*/

void Read_name(Student s[]){

 /*function to read the name of student*/
    printf("Enter the first name of student\n");
    scanf("\n");
    gets(s[0].Student_name.first_name);
    printf("Enter the middle name\n");
    gets(s[0].Student_name.middle_name);
    printf("Enter the last name\n");
    gets(s[0].Student_name.last_name);

}

void Read_Registration (Student s[]){

/*function to read the registration*/
    char a;char N[5],t[2],y[5]; char r[8]="0000000";/*N for student number , t for the term, y for the year*/
    printf("Do you want to enter specified Registration number? Y/N\n");
    scanf(" %c",&a);

    /*to make sure that the input is correct*/
    while ((a!='y')&&(a!='Y')&&(a!='n')&&(a!='N')){
        printf("invalid input please enter again");
            scanf(" %c",&a);

    }
    if ((a=='y')||(a=='Y')){
        printf("Enter the Registration number\n");
        scanf("%s",&(s[0].Student_reg.r_n));
    }
    else if ((a=='n')||(a=='N')){
        printf("Enter the student number\n");
        scanf("\n");
        gets(N);
        printf("Enter the term that the student enterd\n");
        gets(t);
        printf("Enter the year");
        gets(y);
    /* to generate the gpa automatic*/
    for (int i=0;i<2;i++){
        r[i]=y[i+2];
    }
    r[2]=t[0];
    int len;
    len=strlen(N);
    for(int i=7-len,j=0;i<7;i++){
        r[i]=N[j];
        j++;
    }

puts(r);/* print the gpa that generated automaticaly*/
strcpy(s[0].Student_reg.r_n,r);/*to store the registration number*/

}

}

void Read_nationality (Student s[]){

/*function to read the nationality of student*/
    printf("Enter the nationality of the student\n");
    scanf("\n");
    gets(s[0].Nationality.nati);
}

void Read_id(Student s[]){

/*function to read the type of ID and the ID number*/
    printf("Enter the type of ID,(e.g., national ID, passport, …)\n");
    gets(s[0].Id.type);
    printf("Enter the ID\n");
    gets(s[0].Id.id);
    printf("Enter the validity of the ID (day/mon/year)");
    scanf("%d",&s[0].Id.valid.day);
    scanf("%d",&s[0].Id.valid.month);
    scanf("%d",&s[0].Id.valid.year);

}

void Read_home_address (Student s[]){

/*function to read the home address of student*/
    printf("Enter the flat number then home number\n");
    scanf("%d%d",&(s[0].Home_addr.F_N),&(s[0].Home_addr.H_N));
    printf("Enter the street name\n");
    scanf("\n");
    gets(s[0].Home_addr.street);
    printf("Enter the Area name\n");
    gets(s[0].Home_addr.Area);
    printf("Enter the City name\n");
    gets(s[0].Home_addr.city);
    printf("Enter the governorate name\n");
    gets(s[0].Home_addr.governorate);
    printf("Enter the postal code\n");
    gets(s[0].Home_addr.postal_code);

}

void Read_mailing_address (Student s[]){

 /*function to get the mailing address for student*/
    char x;/*to get the answer of the question*/
    printf("Is the mailing address the same as home address? answer with Y or N");
    scanf(" %c",&x);
    /*to make sure that the input is available*/
    while ((x!='y')&&(x!='Y')&&(x!='n')&&(x!='N')){
        printf("invalid input please enter again");
            scanf(" %c",&x);

    }
if (x=='y'||x=='Y'){
    s[0].Mail_addr= s[0].Home_addr;/*to copy the structure of home address into the mail address*/

}
if (x=='n'||x=='N'){
/*to get the inputs of the mailing address*/
   printf("Enter the flat number then home number\n");
    scanf("%d%d",&(s[0].Mail_addr.F_N),&(s[0].Mail_addr.H_N));
    printf("Enter the street name\n");
    scanf("\n");
    gets(s[0].Mail_addr.street);
    printf("Enter the Area name\n");
    gets(s[0].Mail_addr.Area);
    printf("Enter the City name\n");
    gets(s[0].Mail_addr.city);
    printf("Enter the governorate name\n");
    gets(s[0].Mail_addr.governorate);
    printf("Enter the postal code\n");
    gets(s[0].Mail_addr.postal_code);
}

}

void Read_date_of_birth(Student s[]){



/*function to read the date of birth*/
             printf("Enter the day of birth: (between 1:31)\n");
             scanf("%d",&(s[0].Student_age.age.day));
             /*to check the input*/
    while ((s[0].Student_age.age.day<1)||(s[0].Student_age.age.day>31)){
             printf("invalid number please enter again\n");
             scanf("%d",&(s[0].Student_age.age.day));
        }
            printf("Enter the month of birth: (between 1:12)\n");
            scanf("%d",&(s[0].Student_age.age.month));
            /*to check the input*/
    while ((s[0].Student_age.age.month<1)||(s[0].Student_age.age.month>12)){
             printf("invalid number please enter again\n");
            scanf("%d",&(s[0].Student_age.age.month));

}
/*to check the year is valid or not*/
 while ((s[0].Student_age.age.year<1980)||(s[0].Student_age.age.month>2021)){
            printf("Enter the year of birth: (between 1980:2021)\n");
            scanf("%d",&(s[0].Student_age.age.year));
        if ((s[0].Student_age.age.year>=1980) && (s[0].Student_age.age.day<=2021));
        else
            printf("invalid number please enter again\n");
}
    s[0].Student_age.agee = 2021 - s[0].Student_age.age.year; /*to calculate the age of the student and save the age*/
}

void Read_gender (Student s[]){
    /*function to read the gender of the student*/
    printf("Enter the gender of Student\n");
    scanf("\n");
    gets(s[0].Student_gender.gen);
}

void Read_enrolment (Student s[]){

/*function to get the term and year of enrollment*/
    printf("Enter the term of enrolment (eg.fall,...)\n");
    scanf("\n");
    gets(s[0].Enrol.term);
    printf("Enter the year of enrolment\n");
    scanf("%d",&(s[0].Enrol.year));
}

void Read_department (Student s[]){

/*function to read the department of student*/
    printf("Enter the department of enrolment\n");
    scanf("\n");
    gets(s[0].Department.depart);

}

void Read_student_tutor (Student s[]){

/*function to read the student tutor*/
    printf("Enter the student tutor first name\n");
    scanf("\n");
    gets(s[0].Tut.tut_name.first_name);
    printf("Enter the student tutor middle name\n");
    gets(s[0].Tut.tut_name.middle_name);
    printf("Enter the student tutor last name\n");
    gets(s[0].Tut.tut_name.last_name);
    printf("Enter the code of tutor\n");
    scanf("\n");
    gets(s[0].Tut.tut_code);
    }

void Read_current_term(Student s[]){

/*function to read the current term of student*/
    printf("Enter the current term\n");
    scanf("%d",&(s[0].Curr_term.term));

}

void Read_payments (Student s[]){

/*to read payments*/
    printf("Enter the type of payment\n");
    scanf("\n");
    gets(s[0].Payments_of_student.type_fund);
    printf("Enter the number of payments done\n");
    scanf("%d",&(s[0].Payments_of_student.num_of_payments));
    printf("Total number paid so far\n");
    scanf("%f",&(s[0].Payments_of_student.total_paid));

}

void Read_old_payments (Student s[]){

/*these function gets the number of previous payments and all the details about it*/
	for (int i=0;i<s[0].Payments_of_student.num_of_payments;i++){
    printf("Enter Amount paid\n");
    scanf("%f",&(s[0].Payments_of_student.detail[i].amount_paid));
    printf("Enter the transaction number\n");
    scanf("\n");
    gets(s[0].Payments_of_student.detail[i].transaction_number);
    printf("Enter the bank name\n");
    gets(s[0].Payments_of_student.detail[i].bank_of_trans);
    printf("Enter the date of transaction (day/month/year)\n");
    scanf("%d",&s[0].Payments_of_student.detail[i].d.date_of_trans.day);/*date of trans : date if transaction*/
    scanf("%d",&s[0].Payments_of_student.detail[i].d.date_of_trans.month);
    scanf("%d",&s[0].Payments_of_student.detail[i].d.date_of_trans.year);
    printf("Enter the time of transaction (hour/minute/second)\n");
    scanf("%d%d%d",&(s[0].Payments_of_student.detail[i].d.hour),&(s[0].Payments_of_student.detail[i].d.minute),&(s[0].Payments_of_student.detail[i].d.second));}

}

void Read_Student_contact (Student s[]){

/*function to read the contact of student*/
    printf("Enter the email\n");
    scanf("\n");
    gets(s[0].Student_contact.email);
    printf("Enter the home number\n");
    gets(s[0].Student_contact.home_number);
    printf("Enter the mobile number\n");
    gets(s[0].Student_contact.mobile);
}

void Read_Student_creditsH (Student s[]){

/*function to read the credits hours*/
    printf("Enter the maximum credit hours required for the degree\n");
    scanf("%d",&(s[0].Credits.max_c_hours));
    printf("Enter the finished credit hours\n");
    scanf("%d",&(s[0].Credits.finished_c_hours));
    printf("Enter the current credit hours\n");
    scanf("%d",&(s[0].Credits.current_c_hours));
    s[0].Credits.remaining=s[0].Credits.max_c_hours-s[0].Credits.finished_c_hours-s[0].Credits.current_c_hours;
}

void Read_courses_finished (Student s[]){

/*function to read the courses*/
    printf("Enter the data of the finished courses\n ");
    printf("Enter the number of courses finished\n");
    scanf("%d",&(s[0].Courses_of_student.finished.number_of_course));
    printf("Enter the total number of credits hours for these courses\n");
    scanf("%d",&(s[0].Courses_of_student.finished.total));
/*loop to read the data of the number of courses finished*/
    for (int i=0;i<s[0].Courses_of_student.finished.number_of_course;i++){
        printf("Enter course code\n");
        scanf("\n");
        gets(s[0].Courses_of_student.finished.d_f[i].course_code);
        printf("Enter course name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].course_name);
        printf("Enter course credit hours\n");
        scanf("%d",&(s[0].Courses_of_student.finished.d_f[i].course_credit_hours));
        printf("Enter number of times taking the course\n");
        scanf("%d",&(s[0].Courses_of_student.finished.d_f[i].number_of_times));
        printf("Enter semester and year for taking the course\n");
        scanf("%d%d",&(s[0].Courses_of_student.finished.d_f[i].semester),&(s[0].Courses_of_student.finished.d_f[i].year));
        printf("Enter the lecturer first name\n");
        scanf("\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.lecturer.first_name);
        printf("Enter the lecturer middle name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.lecturer.middle_name);
        printf("Enter the lecturer last name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.lecturer.last_name);
        printf("Enter the GTA first name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.GTA.first_name);
        printf("Enter the GTA middle name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.GTA.middle_name);
        printf("Enter the GTA last name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.GTA.last_name);
        printf("Enter the lab GTA first name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.lab_GTA.first_name);
        printf("Enter the lab GTA middle name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.lab_GTA.middle_name);
        printf("Enter the lab GTA last name\n");
        gets(s[0].Courses_of_student.finished.d_f[i].t.lab_GTA.last_name);
        printf("Enter the 7th mark out of 30\n");
        scanf("%f",&(s[0].Courses_of_student.finished.d_f[i].marks.seventh));
        printf("Enter the 12th mark out of 20\n");
        scanf("%f",&(s[0].Courses_of_student.finished.d_f[i].marks.twelveth));
        printf("Enter the year work mark out of 10\n");
        scanf("%f",&(s[0].Courses_of_student.finished.d_f[i].marks.year_work));
        printf("Enter the mark of final out of 40\n");
        scanf("%f",&(s[0].Courses_of_student.finished.d_f[i].marks.final_grade));

        /*calculation of the sum of all grades of one course out of 100*/

        s[0].Courses_of_student.finished.d_f[i].marks.sum=s[0].Courses_of_student.finished.d_f[i].marks.final_grade+s[0].Courses_of_student.finished.d_f[i].marks.year_work+s[0].Courses_of_student.finished.d_f[i].marks.twelveth+s[0].Courses_of_student.finished.d_f[i].marks.seventh;

       /*put the grade of the each subject according to scheme grading system*/

        if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 97 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"A+");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 93 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"A");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 89 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"A-");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 85 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"B+");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 80 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"B");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 75 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"B-");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 70 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"C+");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 65 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"C");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 60 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"C-");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 55 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"D+");
        else if (s[0].Courses_of_student.finished.d_f[i].marks.sum >= 50 )
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"D");
        else
        strcpy(s[0].Courses_of_student.finished.d_f[i].grade,"F");



        printf("Enter the student percentage absence during the course\n");
        scanf("%f",&(s[0].Courses_of_student.finished.d_f[i].student_percentage_absense));





         }

}

void Read_courses_current (Student s[]){

/*function to read the courses*/
    printf("Enter the data of the current courses\n ");
    printf("Enter the number of courses current\n");
    scanf("%d",&(s[0].Courses_of_student.current.number_of_course));
    printf("Enter the total number of credits hours for these courses\n");
    scanf("%d",&(s[0].Courses_of_student.current.total));

    for (int i=0;i<s[0].Courses_of_student.current.number_of_course;i++){
        printf("Enter course code\n");
        scanf("\n");
        gets(s[0].Courses_of_student.current.d_c[i].course_code);
        printf("Enter course name\n");
        gets(s[0].Courses_of_student.current.d_c[i].course_name);
        printf("Enter course credit hours\n");
        scanf("%d",&(s[0].Courses_of_student.current.d_c[i].course_credit_hours));
        printf("Enter number of times taking the course\n");
        scanf("%d",&(s[0].Courses_of_student.current.d_c[i].number_of_times));
        printf("Enter semester and year for taking the course\n");
        scanf("%d%d",&(s[0].Courses_of_student.current.d_c[i].semester),&(s[0].Courses_of_student.current.d_c[i].year));
        printf("Enter the lecturer first name\n");
        scanf("\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.lecturer.first_name);
        printf("Enter the lecturer middle name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.lecturer.middle_name);
        printf("Enter the lecturer last name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.lecturer.last_name);
        printf("Enter the GTA first name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.GTA.first_name);
        printf("Enter the GTA middle name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.GTA.middle_name);
        printf("Enter the GTA last name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.GTA.last_name);
        printf("Enter the lab GTA first name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.lab_GTA.first_name);
        printf("Enter the lab GTA middle name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.lab_GTA.middle_name);
        printf("Enter the lab GTA last name\n");
        gets(s[0].Courses_of_student.current.d_c[i].t.lab_GTA.last_name);
        printf("Enter the 7th mark out of 30\n");
        scanf("%f",&(s[0].Courses_of_student.current.d_c[i].marks.seventh));
        printf("Enter the 12th mark out of 20\n");
        scanf("%f",&(s[0].Courses_of_student.current.d_c[i].marks.twelveth));
        printf("Enter the year work mark out of 10\n");
        scanf("%f",&(s[0].Courses_of_student.current.d_c[i].marks.year_work));
        printf("Enter the mark of final out of 40\n");
        scanf("%f",&(s[0].Courses_of_student.current.d_c[i].marks.final_grade));

        /*the line below is to calculate overall grade of student*/
        s[0].Courses_of_student.current.d_c[i].marks.sum=s[0].Courses_of_student.current.d_c[i].marks.final_grade+s[0].Courses_of_student.current.d_c[i].marks.year_work+s[0].Courses_of_student.current.d_c[i].marks.twelveth+s[0].Courses_of_student.current.d_c[i].marks.seventh;
        if (s[0].Courses_of_student.current.d_c[i].marks.sum >= 97 )
        strcpy(s[0].Courses_of_student.current.d_c[i].grade,"A+");
        else if (s[0].Courses_of_student.current.d_c[i].marks.sum >= 93 )
        strcpy(s[0].Courses_of_student.current.d_c[i].grade,"A");
        else if (s[0].Courses_of_student.current.d_c[i].marks.sum >= 89 )
        strcpy(s[0].Courses_of_student.current.d_c[i].grade,"A-");
        else if (s[0].Courses_of_student.current.d_c[i].marks.sum >= 85 )
        strcpy(s[0].Courses_of_student.current.d_c[i].grade,"B+");
        else if (s[0].Courses_of_student.current.d_c[i].marks.sum >= 80 )
        strcpy(s[0].Courses_of_student.current.d_c[i].grade,"B");
        else if (s[0].Courses_of_student.current.d_c[i].marks.sum >= 75 )
        strcpy(s[0].Courses_of_student.current.d_c[i].grade,"B-");
        else if (s[0].Courses_of_student.current.d_c[i].marks.sum >= 70 )
        strcpy(s[0].Courses_of_student.current.d_c[i].grade,"C+");
         else if (s[0].Courses_of_student.finished.d_c[i].marks.sum >= 65 )
        strcpy(s[0].Courses_of_student.finished.d_c[i].grade,"C");
        else if (s[0].Courses_of_student.finished.d_c[i].marks.sum >= 60 )
        strcpy(s[0].Courses_of_student.finished.d_c[i].grade,"C-");
        else if (s[0].Courses_of_student.finished.d_c[i].marks.sum >= 55 )
        strcpy(s[0].Courses_of_student.finished.d_c[i].grade,"D+");
        else if (s[0].Courses_of_student.finished.d_c[i].marks.sum >= 50 )
        strcpy(s[0].Courses_of_student.finished.d_c[i].grade,"D");
        else
        strcpy(s[0].Courses_of_student.finished.d_c[i].grade,"F");


        printf("Enter the student percentage absence during the course\n");
        scanf("%f",&(s[0].Courses_of_student.current.d_c[i].student_percentage_absense));





         }

}
/*-------------------------------------------------------------------------------------*/


/*function to determine gpa*/


void total_gpa (Student s[]){
    float current_points = 0.0 , finished_points= 0.0 ,total_points=0,gpa_total=0;/*declaration for variable that will save the points*/

/*to calculate the total point of the current courses*/
        for(int i=0;i<s[0].Courses_of_student.current.number_of_course;i++ ){
                /*check the grade and then calculate the number of points according to the univeristy grading system*/
            if (    (strcmp(s[0].Courses_of_student.current.d_c[i].grade,"A+" )==0)) {
                current_points+= (float)4.0*s[0].Courses_of_student.current.d_c[i].course_credit_hours;

            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"A" )==0)) {
                 current_points+= (23/6.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;

            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"A-" )==0))  {
                 current_points+= (11/3.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"B+" )==0) ){
                 current_points+= (10/3.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;

            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"B" )==0)) {
                 current_points+= 3.0*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"B-" )==0)) {
                 current_points+= (8/3.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"C+" )==0)) {
                 current_points+= (7/3.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"C" )==0)) {
                current_points+= (2.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }

            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"C-" )==0))  {
                 current_points+= (5/3.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"D+" )==0))  {
                 current_points+= (4/3.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"D" )==0))  {
                 current_points+= (1.0)*s[0].Courses_of_student.current.d_c[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.current.d_c[i].grade,"F" )==0));



        }



        /*to calulate the total finished point to determine the gpa*/


        for(int i=0;i<s[0].Courses_of_student.finished.number_of_course ;i++ ){
            /*check the grade and then calculate the number of points according to the univeristy grading system*/

            if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"A+" )==0)) {

                finished_points+= 4.0*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;

            }
            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"A" )==0)) {
                 finished_points+= (23/6.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"A-" )==0)){
                 finished_points+= (11/3.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }

            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"B+" )==0)) {
                 finished_points+= (10/3.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }

            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"B" )==0)){
                 finished_points+= 3.0*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }

            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"B-" )==0))  {
                 finished_points+= (8/3.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }

            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"C+" )==0))  {
                 finished_points+= (7/3.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"C" )==0)) {
                finished_points+= (2.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }

            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"C-" )==0)){
                 finished_points+= (5/3.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"D+" )==0)){
                 finished_points+= (4/3.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"D" )==0)){
                 finished_points+= (1.0)*s[0].Courses_of_student.finished.d_f[i].course_credit_hours;
            }
            else if ((strcmp(s[0].Courses_of_student.finished.d_f[i].grade,"F" )==0));


        }

    total_points = current_points + finished_points;/*calculation for the total points*/
    /*calculation for the gpa total*/
    gpa_total = (total_points) / (s[0].Courses_of_student.finished.total+s[0].Courses_of_student.current.total);
    s[0].Student_gpa.gpa=gpa_total;/*save the gpa of student*/
}

/*/////////////////////////////////////////////////////////////////////////////////*/

/*function to search for the registration number and number  */
 struct name* get_name (Student s[], char reg[] ,int n){
     /*function receives the structure array of student and the registration number that we search for and the number of students*/
	int ind;/*to find the number of the student that we search for into the array of struct*/
	  for (int i=0; i<n; i++ ){
            /*n is the number of students*/
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;break;
		  }
	  }


return &(s[ind].Student_name); // this function returns a pointer to the required structure of name
}

int get_age (Student s[], char reg[] ,int n){
/*function receives the structure array of student and the registration number that we search for and the number of students*/

	int ind;/*to find the number of the student that we search for into the array of struct*/
	 for (int i=0; i<n; i++ ){
            /* n should be array length in dynamic array */
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;
		  }
	  }
return s[ind].Student_age.agee; /*returns a pointer to the required string*/
}

struct address* get_homeadress (Student s[], char reg[] ,int n){

    /*function receives the structure array of student and the registration number that we search for and the number of students*/

	  int ind;
	  for (int i=0; i<n; i++ ){
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;
		  }
	  }
return &s[ind].Home_addr; /* returns a pointer to the required structure of home address*/
}

float get_gpa (Student s[], char reg[] ,int n){

/*function receives the structure array of student and the registration number that we search for and the number of students*/

	int ind;
	  for (int i=0; i<n; i++ ){ //n should be array length in dynamic array passed from the main
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;
		  }
	  }
return s[ind].Student_gpa.gpa; // this function returns the value of the GPA
}

/*--------------------------------------------------------------------------------------------------------------------------*/
/*functions that edit specific details of student*/
void edit_nationality (Student s[], char reg[] ,int n, char nationality[]){
    /*function that edit the nationality of student*/
	int ind;
	 for (int i=0; i<n; i++ ){
            /*n is the number of students*/
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;
		  }
	  }
 strcpy(s[ind].Nationality.nati, nationality);
}


void edit_reg (Student s[], char reg[] ,int n, char regnew[]){
	int ind;
	  for (int i=0; i<n; i++ ){ //n should be array length in dynamic array passed from the main
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;
		  }
	  }
 strcmp(s[ind].Student_reg.r_n, regnew); // this function edits the value of the registration number
}


void edit_homeadress (Student s[],char reg[] ,int n){
    /*to edit the home address*/

	int ind;
	  for (int i=0; i<n; i++ ){
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;break;
		  }
	  }
    printf("Enter the flat number then home number\n");
    scanf("%d%d",&(s[ind].Home_addr.F_N),&(s[ind].Home_addr.H_N));
    printf("Enter the street name\n");
    scanf("\n");
    gets(s[ind].Home_addr.street);
    printf("Enter the Area name\n");
    gets(s[ind].Home_addr.Area);
    printf("Enter the City name\n");
    gets(s[ind].Home_addr.city);
    printf("Enter the governorate name\n");
    gets(s[ind].Home_addr.governorate);
    printf("Enter the postal code\n");
    gets(s[ind].Home_addr.postal_code);
}

void edit_gpa (Student s[], char reg[] ,int n){
    printf("Enter the new gpa\n");
        float gpa_new;
        scanf("%f",&gpa_new);
	int ind;
	for (int i=0; i<n; i++ ){
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;break;
		  }
	  }
 s[ind].Student_gpa.gpa= gpa_new;
}


void edit_currentsubject(Student s[],char reg[] ,int n, char gradenew[], char sub[]  ){
    /*function to edit the current course*/

 int ind,T;
	  for (int i=0; i<n; i++ ){
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;
		  }
	  }
	  for (int i=0; i<n; i++ ){
	  if (strcmp( s[ind].Courses_of_student.current.d_c[i].course_name, sub )==0 )
	  	{
	  		T =i;break;
		  }
	  }

	strcpy(s[ind].Courses_of_student.current.d_c[T].grade, gradenew);
total_gpa (s);

}


void edit_finishedsubject(Student s[],char reg[] ,int n, char gradenew[], char sub[]  ){
    /*function to edit the finished course*/
 int ind, T;
	 for (int i=0; i<n; i++ ){ /*search for the student*/
	  if (strcmp( s[i].Student_reg.r_n , reg )==0 )
	  	{
	  		ind =i;break;
		  }
	  }
	  for (int i=0; i<n; i++ ){
	  if (strcmp( s[ind].Courses_of_student.finished.d_c[i].course_name, sub )==0 )
	  	{
	  		T =i;break;
		  }
	  }

	strcpy(s[ind].Courses_of_student.finished.d_c[T].grade, gradenew);
	total_gpa (s);/*to calculate the new gpa so call the function*/

}

/*--------------------------------------------------------------------------------------------------------------------*/

void print(Student s[]){
	printf("student name is %s %s %s\n" ,s[0].Student_name.first_name,s[0].Student_name.middle_name, s[0].Student_name.last_name  );
	printf("student nationality is %s \n", s[0].Nationality.nati );
	printf("student ID is %s %s %d %d %d \n", s[0].Id.type, s[0].Id.id, s[0].Id.valid.day,s[0].Id.valid.month,s[0].Id.valid.year);
	printf("home address is %d\n %d\n %s\n %s\n %s\n %s\n %s \n%s\n",s[0].Home_addr.F_N,s[0].Home_addr.H_N,s[0].Home_addr.street,s[0].Home_addr.Area,s[0].Home_addr.city,s[0].Home_addr.governorate, s[0].Home_addr.country,s[0].Home_addr.postal_code);
	printf("mailing Address is %d\n %d\n %s\n %s\n %s\n %s\n %s \n%s\n",s[0].Mail_addr.F_N,s[0].Mail_addr.H_N,s[0].Mail_addr.street,s[0].Mail_addr.Area,s[0].Mail_addr.city,s[0].Mail_addr.governorate, s[0].Mail_addr.country,s[0].Mail_addr.postal_code);
	printf("student age is: %d\n birth day: %d/ %d/ %d\n",s[0].Student_age.agee,s[0].Student_age.age.day, s[0].Student_age.age.month, s[0].Student_age.age.year );
	printf("student gender is: %s \n", s[0].Student_gender.gen);
	printf("enrollment term is %s, enrollment year is %d\n", s[0].Enrol.term, s[0].Enrol.year);
	printf("enrolled department is %s\n", s[0].Department.depart);
	printf("tutor name is:%s %s %s tutor code is: %s\n", s[0].Tut.tut_name.first_name,s[0].Tut.tut_name.middle_name,s[0].Tut.tut_name.last_name, s[0].Tut.tut_code);
	printf("current term is: %d\n", s[0].Curr_term.term);
	printf("funding type is: %s\n  number of Payments_of_students done: %d\n total amount paid so far: %f\n", s[0].Payments_of_student.type_fund,s[0].Payments_of_student.num_of_payments,s[0].Payments_of_student.total_paid );
	printf("student contact mail is: %s\n student contact home phone is: %s \n student contact mobile number is: %s \n",s[0].Student_contact.email, s[0].Student_contact.home_number, s[0].Student_contact.mobile);
	printf("max reqired credit hours for the degree is: %d\n finished credit hours is: %d\n current registered hours is: %d\n remaining hours is: %d \n",s[0].Credits.max_c_hours,s[0].Credits.finished_c_hours,s[0].Credits.current_c_hours,s[0].Credits.remaining);
	printf("GPA is: %f\n",s[0].Student_gpa.gpa);
    printf("number of courses finished is %d\n",s[0].Courses_of_student.finished.number_of_course);
    printf("total number of credit hours for these courses is%d\n",s[0].Courses_of_student.finished.total);
    for (int i=0;i<s[0].Courses_of_student.finished.number_of_course;i++){
    printf("course code is %s\n",s[0].Courses_of_student.finished.d_f[i].course_code);
    printf("course name is %s\n",s[0].Courses_of_student.finished.d_f[i].course_name);
    printf("course credit hours:%d\n",s[0].Courses_of_student.finished.d_f[i].course_credit_hours);
    printf("Number of times taking the course:%d\n",s[0].Courses_of_student.finished.d_f[i].number_of_times);
    printf("Semester and year for taking the course in the case of finished courses are %d  %d\n",s[0].Courses_of_student.finished.d_f[i].semester,s[0].Courses_of_student.finished.d_f[i].year);
    printf("course lecturer name is:%s %s %s\n",s[0].Courses_of_student.finished.d_f[i].t.lecturer.first_name,s[0].Courses_of_student.finished.d_f[i].t.lecturer.middle_name,s[0].Courses_of_student.finished.d_f[i].t.lecturer.last_name);
    printf("course GTA name is %s %s %s\n",s[0].Courses_of_student.finished.d_f[i].t.GTA.first_name,s[0].Courses_of_student.finished.d_f[i].t.GTA.middle_name,s[0].Courses_of_student.finished.d_f[i].t.GTA.last_name);
    printf("course lab GTA name is %s %s %s\n",s[0].Courses_of_student.finished.d_f[i].t.lab_GTA.first_name,s[0].Courses_of_student.finished.d_f[i].t.lab_GTA.middle_name,s[0].Courses_of_student.finished.d_f[i].t.lab_GTA.last_name);
    printf("marks of seventh is %f of 30\n",s[0].Courses_of_student.finished.d_f[i].marks.seventh);
    printf("marks of twelveth is %f of 20\n",s[0].Courses_of_student.finished.d_f[i].marks.twelveth);
    printf("marks of year work is %f of 100\n",s[0].Courses_of_student.finished.d_f[i].marks.year_work);
    printf("marks of final is %f of 40\n",s[0].Courses_of_student.finished.d_f[i].marks.final_grade);
    printf("sum of marks is %f of 100\n",s[0].Courses_of_student.finished.d_f[i].marks.sum);
    printf("Student percentage absence during the course\n",s[0].Courses_of_student.finished.d_f[i].student_percentage_absense);
    }
for (int i=0;i<s[0].Courses_of_student.current.number_of_course;i++){
    printf("course code is %s\n",s[0].Courses_of_student.current.d_c[i].course_code);
    printf("course name is %s\n",s[0].Courses_of_student.current.d_c[i].course_name);
    printf("course credit hours:%d\n",s[0].Courses_of_student.current.d_c[i].course_credit_hours);
    printf("Number of times taking the course:%d\n",s[0].Courses_of_student.current.d_c[i].number_of_times);
    printf("Semester and year for taking the course in the case of current courses are %d  %d\n",s[0].Courses_of_student.current.d_c[i].semester,s[0].Courses_of_student.current.d_c[i].year);
    printf("course lecturer name is:%s %s %s\n",s[0].Courses_of_student.current.d_c[i].t.lecturer.first_name,s[0].Courses_of_student.current.d_c[i].t.lecturer.middle_name,s[0].Courses_of_student.current.d_c[i].t.lecturer.last_name);
    printf("course GTA name is %s %s %s\n",s[0].Courses_of_student.current.d_c[i].t.GTA.first_name,s[0].Courses_of_student.current.d_c[i].t.GTA.middle_name,s[0].Courses_of_student.current.d_c[i].t.GTA.last_name);
    printf("course lab GTA name is %s %s %s\n",s[0].Courses_of_student.current.d_c[i].t.lab_GTA.first_name,s[0].Courses_of_student.current.d_c[i].t.lab_GTA.middle_name,s[0].Courses_of_student.current.d_c[i].t.lab_GTA.last_name);
    printf("marks of seventh is %f of 30\n",s[0].Courses_of_student.current.d_c[i].marks.seventh);
    printf("marks of twelveth is %f of 20\n",s[0].Courses_of_student.current.d_c[i].marks.twelveth);
    printf("marks of year work is %f of 100\n",s[0].Courses_of_student.current.d_c[i].marks.year_work);
    printf("marks of final is %f of 40\n",s[0].Courses_of_student.current.d_c[i].marks.final_grade);
    printf("sum of marks is %f of 100\n",s[0].Courses_of_student.current.d_c[i].marks.sum);
    printf("Student percentage absence during the course\n",s[0].Courses_of_student.current.d_c[i].student_percentage_absense);
    }

}




void func (Student s[]){
int  choose;
printf("please enter the number of the data that you want to enter now for student;\n");
printf("1- The student name\n");
printf("2- Registration number of student \n");
printf("3- The nationality of student\n");
printf("4- The ID data of student\n");
printf("5- The home address of student\n");
printf("6- The mailing address of student\n");
printf("7- The date of birth of student\n");
printf("8- The student gender\n");
printf("9- The Enrolment term and year\n");
printf("10- The Department of student\n");
printf("11- The student tutor\n");
printf("12- The current term\n");
printf("13- The payments details\n");
printf("14- The old payments details\n");
printf("15- The student contact\n");
printf("16- The student credit hours\n");
printf("17- The courses finished\n");
printf("18- The current Courses \n");
printf("19- To enter all the data One time\n");
for (int i=0;i<19;i++){
scanf("%d",&choose);
while (choose>19 &&choose<1){
    printf("invalid number please enter again\n");
    scanf("%d",&choose);
}

if (choose==1)
    Read_name(s);
else if (choose==2)
    Read_Registration (s);
else if (choose==3)
    Read_nationality (s);
else if (choose==4)
    Read_id (s);
else if (choose==5)
    Read_home_address (s);
else if (choose==6)
    Read_mailing_address (s);
else if (choose==7)
    Read_date_of_birth (s);
else if (choose==8)
    Read_gender (s);
else if (choose==9)
    Read_enrolment (s);
else if (choose==10)
    Read_department (s);
else if (choose==11)
    Read_student_tutor(s);
else if (choose==12)
    Read_current_term(s);
else if (choose==13)
    Read_payments(s);
else if (choose==14)
    Read_old_payments(s);
else if (choose==15)
    Read_Student_contact(s);
else if (choose==16){
    Read_Student_creditsH(s);}
else if (choose==17){
    Read_courses_finished(s);}

else if (choose==18){
    Read_courses_current(s);
}
else if(choose==19)
{
    if (i==0){
Read_name(s);
Read_Registration (s);
Read_nationality (s);
Read_id (s);
Read_home_address (s);
Read_mailing_address (s);
Read_date_of_birth (s);
Read_gender (s);
Read_enrolment (s);
Read_department (s);
Read_student_tutor(s);
Read_current_term(s);
Read_payments(s);
Read_old_payments(s);
Read_Student_contact(s);
Read_Student_creditsH(s);
Read_courses_finished(s);
Read_courses_current(s);
    break;
    }
    else
        printf("please any other number ");
}

printf("enter again for the next choice");
}}


/*---------------------------------------*/




int main (void){
    int n;
    printf("enter the number of students: ");
    scanf("%d",&n);
    char searchh[10]; int num;
    Student s[n];

    func(s);                  /*call to the function that contains the data should to be inputed*/
    total_gpa (s);           /*function that calculate the total gpa and stored it for the student gpa*/

    print(s);               /*call to the function that print the data of student*/


/* to choose the data that will return */
	printf("Enter the registration number  of the student that you want search for \n ");
	scanf("\n");
	gets(searchh);
		printf("choose the number of the data that you want to get: \n");
	printf("1-  name\n ");
	printf("2-  age\n ");
	printf("3-  homeadress\n ");
	printf("4-  GPA\n ");
	scanf("%d",&num);

	while(num>4 || num<1){
        printf("invalid choice please enter again");
        scanf("%d",&num);
	}


	if (num==1){

		struct name* pointname= get_name(s ,searchh ,n );

		printf("Name is %s %s %s",pointname->first_name, pointname->middle_name, pointname->last_name);
	}
	else if (num==2){

		printf("%d",(get_age( s ,searchh ,n )));
	}
	else if(num==3){
	struct address* pointhome = get_homeadress( s,searchh ,n );
	printf("home address is %d\n %d\n %s\n %s\n %s\n %s\n %s \n%s\n",pointhome->F_N,pointhome->H_N,pointhome->street,pointhome->Area,pointhome->city,pointhome->governorate, pointhome->country,pointhome->postal_code);
	}
	else {
    printf("%f",get_gpa( s,searchh ,n ));
	}

/*-----------------------------------------------------------*/
/*to edit some details of student*/

	printf("Enter the registration number  of the student to change its value: ");
	scanf("\n");
	gets(searchh);
	printf("select a number");
	printf("1-  GPA\n ");
	printf("2-  nationality\n ");
	printf("3-  home address\n ");
	printf("4-  A subject grade\n ");

	scanf("%d",&num);
/* passes to the function the student struct array and the searchh registration and the number of students*/
	if (num==1){
/* to edit the gpa*/
        edit_gpa(s, searchh, n );
	}

	else if (num==2){
/*to edit the nationality*/
		printf("enter the new nationality");
		char natse[20];
		scanf("%s",natse);
		edit_nationality( s ,searchh ,n, natse );
			}
	else if(num==3){
/*to edit the homeaddress*/
		edit_homeadress(s,searchh,n);
	}

	else if (num==4) {
            /*to edit the grade of subject and calculate the new gpa*/
		int k;char gradenew[3];char sub[10];
		printf("1- edit a current subject");
		printf("2- edit a finished subject");
		scanf("%d",&k);
		if(k==1){
		printf("enter subject name: ");
		scanf("%s",sub);
		printf("enter new grad: ");
		scanf("%s",gradenew);
	edit_currentsubject(s,searchh ,n, gradenew, sub );}
		else if (k==2){
		printf("enter subject name: ");
		scanf("%s",sub);

		printf("enter new grad: ");
		scanf("%s",gradenew);
	edit_finishedsubject(s,searchh ,n, gradenew, sub );
		}}
print(s);/*function to print all the data*/

return 0;
}
