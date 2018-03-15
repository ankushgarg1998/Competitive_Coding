#include <stdio.h>
#include <stdlib.h>


struct courses
    {
    char course_name[20];

    struct subject
      {
      char sub_name[20];
      int daoc[10];
      int weoc[10];
      }sub[10];

    struct teacher
      {
      char teach_id[10];
      }teach[10];

    struct room
      {
      int room;
      }r[10];

    }co[10];



void main()
{
    int a[20][20][20],b[20][20][20],c[20][20][20],i,j,l,d,m,e,f,k,q;
    printf("Enter total no. of courses:");
    scanf("%d",&f);
    for(j=0;j<f;j++)
       {

          printf("Enter the total no. of subjects including Practicals also in course%d:",j+1);
          scanf("%d",&m);
          for(i=0;i<m;i++)
              {
                    printf("Enter name of %d subject:",i+1);
                    scanf("%s",&co[j].sub[i].sub_name);
                    for(q=0;q<10;q++)
                    co[j].sub[i].daoc[q] = 0;
                    for(q=0;q<10;q++)
                    co[j].sub[i].weoc[q] = 0;

                    printf("Enter this teacher id also:");
                    scanf("%s",&co[j].teach[i].teach_id);
                    printf("Enter the room no.:");
                    scanf("%d",&co[j].r[i].room);
              }
       }
          printf("Enter the total no. of days:");
          scanf("%d",&d);
          printf("enter total no. of lectures in a day:");
          scanf("%d",&e);
          for(i=0;i<f;i++)
                 {
                         for(j=0;j<d;j++)
                              {
                                      for(k=0;k<e;k++)
                                              {
                                                     l=rand() % m;
                                                     if(co[i].sub[l].daoc[j] <= 1)
                                                          {
                                                          if(co[i].sub[l].weoc[i] <= 3)
                                                                {
                                                                co[i].sub[l].daoc[j]++;
                                                                co[i].sub[l].weoc[i]++;
                                                                a[i][j][k]=co[i].sub[l].sub_name;
                                                                b[i][j][k]=co[i].teach[l].teach_id;
                                                                c[i][j][k]=co[i].r[l].room;
                                                              }
                                                          else
                                                              k--;
                                                          }
                                                      else
                                                          k--;
                                              }
                              }
                  }
          system("clear");
          for(k=0;k<f;k++)
                {
                          printf("\n\n\n\t\t\tTIME TABLE FOR COURSE %d\n",k+1);
                          for(i=0;i<e;i++)
                                      {
                                             printf("\tTIME%d\t",i+1);
                                      }
                          printf("\n\n");
                          for(i=0;i<d;i++)
                                      {
                                            printf("DAY%d\t",i+1);
                                            for(j=0;j<e;j++)
                                                  {
                                                          printf("%s:%s:%d\t",a[k][i][j],b[k][i][j],c[k][i][j]);
                                                           //printf("\t");
                                                   }
                                             printf("\n");
                                      }
                 }

}
