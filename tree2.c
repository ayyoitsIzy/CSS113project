#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define bar "=====================\n"
#define ligae  printf(bar)
struct tree
{
    int id;
    int adjacency[100];
    int level;
    int connect;
    int visited;
    int created;
};




void make_default(struct tree *node,int id)//give default value to node
{
    node->level = 0 ;
    node->visited = 0;
    node->connect = 0;
    node->created = 0;
    node->id = id;       
}

void connect(struct tree *node_a,struct tree *node_b){ // add edge //
for (int i = 0; i < node_a->connect; i++)if (node_a->adjacency[i]==node_b->id)return;
    node_a->adjacency[node_a->connect] = node_b->id;
    node_a->connect++;
    node_b->adjacency[node_b->connect] = node_a->id;
    node_b->connect++;
}

void check_adjacency(struct tree *node){
    printf("%c is connect to : ",node->id+'a');
    for (int i = 0; i < node->connect; i++){
        printf(" %c",node->adjacency[i]+'a');
    }
    printf("\n");
}

void BFSandDFS(){
int amount;
printf("Please enter amount of node : ");scanf("%d",&amount);fflush(stdin);
struct tree node[amount];
for (int i = 0; i < amount; i++)make_default(&node[i],i);//give default value to all node//

for (int i = 0; i < amount; i++){
    char inp[100]="";
    printf("Please enter adajency node of node[%c] : ",i+'a');
    gets(inp);
    for (int j = 0; j < strlen(inp); j++)connect(&node[i],&node[inp[j]-'a']);
}

//======================add edge here======================//
/*
connect(&node[0],&node[1]);
connect(&node[1],&node[2]);
connect(&node[2],&node[0]);
connect(&node[3],&node[4]);
connect(&node[1],&node[3]);
connect(&node[3],&node[0]);
connect(&node[4],&node[2]);
connect(&node[4],&node[5]);
connect(&node[3],&node[5]);*/
for (int i = 0; i < amount; i++)check_adjacency(&node[i]);

//========================================================//

//======================select root node==================//
int root_node = 0;
char temp;
printf("Please enter root node : ");temp = getchar();root_node = temp - 'a';
node[root_node].visited = 1;
//==========================BFS===========================//

int queue[100]={root_node};
printf("BFS\n");
ligae;
printf("root node:%c \n",node[root_node].id+'a');
for (int i = 0,k = 0; i < amount-1;k++)
{
    int lookat = queue[k];
    printf("%c -> ",node[lookat].id+'a');
    for (int j = 0;j<node[lookat].connect; j++)
    {
        int adajency = node[lookat].adjacency[j];
        if (node[adajency].visited==0)
        {
            i++;
            queue[i] = node[adajency].id;
            node[adajency].visited = 1;
            printf("%c ",node[adajency].id+'a');
        }
    }
    printf("\n");
}
ligae;
//====================================================DFS==========================================================================//
for (int i = 0; i < amount; i++)node[i].visited = 0;//set all visited = 0 back to zero ready for dfs 
node[root_node].visited = 1;
printf("DFS\n");
memset(queue,0,sizeof queue);
int i=0,k;
while (1){
//for (int n = 0; n < 10; n++)printf(":%c:",queue[n]+'a');

int isleaf = 0;
int has_child = 0;
printf("%c->",node[root_node].id+'a');node[root_node].visited=1;
for (;isleaf == 0;)
{
for (int j = 0; j < node[root_node].connect; j++)
{
int child = node[node[root_node].adjacency[j]].id;
if (node[child].visited == 0)
{
    node[child].visited = 1;queue[i]=node[child].id;i++;
    printf("%c-> ",node[child].id+'a');
    root_node = child;
    break;
}
if (j == node[root_node].connect-1){isleaf = 1;}
}
//==============================================begin backtracking================================================//
}
for (i=i-1;i>=0; i--)
{
    int lookat = queue[i];
for (int j = 0; j < node[lookat].connect; j++)
{
int child = node[node[lookat].adjacency[j]].id;
if (node[child].visited == 0)
{
    printf("\n%c->",node[lookat].id+'a');
    queue[i] = node[child].id;
    has_child = 1;
    break;
}
if (j == node[root_node].connect-1)queue[i]=0;
}
if (has_child == 1)break;
}
if (has_child == 1){root_node = queue[i];continue;}
else break;

}


//===================================================================================================================//

};

int main(){
BFSandDFS();

}