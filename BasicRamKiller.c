#include <stdio.h>
using namespace std;
struct killer{
   double a[200];
   double b[200];
   double c[200];
   struct killer *next;
};
#typedef struct killer killer ;
int main() {
killer *head,*p;
    head=(killer *)malloc(1*sizeof(killer));
    p=head ;
    while (1)
    {
        p->next=(killer *)malloc(1*sizeof(killer));
        p=p->next;
    }
    return 0;
}