/*
 * search.c
 *
 *  Created on: Nov 8, 2012
 *      Author: chensiyuan2010
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
 #include <stdlib.h>
#include "sorted-list.h"

struct nodeE{
	char * filename;
	int count;
	struct nodeE *next;
};

struct list{
	char * key;
	 struct nodeE * node;
	struct list *next;

};

struct list * read (char *filen,struct list * head){
		char *my_string;
			 char *filecontent=malloc(100);
			//my_string = (char *) malloc (nbytes + 1);
			 FILE *fp;
		 if ((fp = fopen(filen, "r")) == NULL) {
			                  printf(" can't open:%s.\n", filen);
			                  return 1;
			              }
		 else {
		//	 struct list * ptr=malloc(sizeof( struct list));
			 struct list * temp=malloc(sizeof( struct list));;

			// temp->key=NULL:
int bi=0;
char *a; char *s;
			            	  int loop=0;
			            	  struct nodeE * nod; struct nodeE * nodtemp;
			            	  while (fgets(filecontent, 1000, fp)!= NULL){
			            		  TokenizerT *tk;
			            		  tk= TKCreate(filecontent);

			            		  while( tk->ts[0]!='\0'){
			            		//	  printf("1check the temp:%s\n",temp->key);
			            		  a=TKGetNextToken(tk);

			            		  if(strcmp(a,"list")==0){
			            			  bi=0;
			            			  nodtemp=malloc(sizeof(struct nodeE));
			            			  struct list * ptr=malloc(sizeof( struct list));
			            		//	  printf("2check the temp:%s\n",temp->key);
			            			  a=TKGetNextToken(tk);
			            			   ptr->key=malloc(strlen(a)+1);
			            			  ptr->key=a;
			            			  ptr->next=NULL;
			          // ptr->next=NULL;this change the output,the default not null;
			            		//	  printf("3check the temp:%s\n",temp->key);
			            			  if(temp->key==NULL){
			            				 temp=ptr;
			            				// temp->key=malloc(strlen(a)+1);bug
			            				 head=temp;
			            			  }else{
			            			//	 struct list * ptr1=malloc(sizeof( struct list));
			            			//	 ptr1=temp;
			            			//	  printf("!!!check the temp:%s\n",temp->key);
			            				 //struct list * ptr1=temp;
			            				  for(;; temp==temp->next){

			            					  if(temp->next==NULL){
			            						 // ptr1->next=ptr;
			            						  temp->next=ptr;
			            						 // ptr1=ptr1->next;
			            						temp=  temp->next;
			            						  break;
			            					  }
			            				  }


			            				  //temp->next=ptr;
//when insert , they search the position, but here only add to last of list;
			            				//  temp=temp->next;


			            			  }
			            			 // strcpy(a,"list");
			            			  goto out;
			            		  }

			            		  if(strcmp(a,"/list")!=0||strcmp(a,"list")!=0) {

			            			  if(bi==0){
			            				  nod=malloc(sizeof(struct nodeE));
			            				  nod->filename=malloc(strlen(a)+1);
			            				  nod->filename=a;
			          				  bi=1;
		            			               }
			            			  else	{

										nod->count=a;
										  bi=0;
										  if(temp->node==NULL){
											  nodtemp=nod;
											  temp->node=nod;

											 	  }else{
									for(;; nodtemp==nodtemp->next){
										if(nodtemp->next==NULL){
											nodtemp->next=nod;
											nodtemp=  nodtemp->next;
											  break;
										}
									}

											    			  }



								    		  }
			            		  }
			            		  if(strcmp(a,"/list")==0){
			            					            			  a=TKGetNextToken(tk);


			            					            		  }
			            	  out:

//char asf='d';
			            	  printf("");
		//printf("token:%s\n", a);
			            		  }

			            		//  printf("check the temp:%s\n",temp->key);
			            	//	  printf("check the head:%s\n",head->key);
			            		//  printf("%s\n", filecontent);


			            	  }

			                 fclose(fp);



			         //        printf("???check the temp:%s\n",temp->key);

			      }
	//	 printf("check the next head:%s\n",head->key);
		// printf("check the next head:%s\n",head->next->key);
		 //printf("check the next head:%s\n",head->next->next->key);
		 return head;
	}

	struct list *	search( struct list * head, char * key){
		//struct list * ptr=malloc(sizeof(struct list ));
				//ptr=head;
		struct list * ptr=malloc(sizeof(struct list));
		ptr=head;
	//	printf("!check the next head:%s\n",head->key);
				// printf("check the next head:%s\n",head->next->key);
				// printf("check the next head:%s\n",head->next->next->key);

	//	printf("key is:%s\n",ptr->key);
		for(;ptr!=NULL; ptr=ptr->next){


		if(strcmp(ptr->key, key)==0){
		//	printf("key is:%s\n",ptr->key);
			return ptr;

		}

		}
		return NULL;
	}

	char * sa(struct list * s1,struct list *s2){

		  struct nodeE * n1=malloc(sizeof(struct nodeE));
		  //struct nodeE * n2=malloc(sizeof(struct nodeE));
		  n1=s1->node;
		  //n2=s2->node;
		for(;n1!=NULL;n1=n1->next){
			 struct nodeE * n2=malloc(sizeof(struct nodeE));
							 n2=s2->node;
			for(;n2!=NULL;n2=n2->next){

				if(strcmp(n1->filename,n2->filename)==0){
					printf("final sa is:%s\n",n2->filename);
				}
			}
		}
		return NULL;
	}

	char * so(struct list * s1,struct list *s2){
		 struct nodeE * n1=malloc(sizeof(struct nodeE));
				 // struct nodeE * n2=malloc(sizeof(struct nodeE));
				  n1=s1->node;
				//  n2=s2->node;
		for(;n1!=NULL;n1=n1->next){
				 struct nodeE * n2=malloc(sizeof(struct nodeE));
								 n2=s2->node;
				for(;n2!=NULL;n2=n2->next){

					if(strcmp(n1->filename,n2->filename)==0){
						//printf("so is:%s\n",n1->filename);
						break;
					}
				}
				if(n2==NULL){
					printf("final so is:%s\n",n1->filename);
				}


		}
		struct nodeE * n2=malloc(sizeof(struct nodeE));
		n2=s2->node;
		for(;n2!=NULL;n2=n2->next){


								printf("final so is:%s\n",n2->filename);

						}
			return NULL;
		}
int main(int argc, char **argv){
	//printf("hello");
	char * key1=malloc(32);char* key2=malloc(32); char* saso=malloc(22);
	struct list *head=malloc(sizeof(struct list));
	struct list *s1=malloc(sizeof(struct list));
	struct list *s2=malloc(sizeof(struct list));
	 if(head->key==NULL){
		//	printf("head is Null:\n");
				            			  }
	//struct list *s1;
	head=read(argv[1],head);
/*
	printf("main head is:%s\n",head->key);
	printf("main head is:%s\n",head->next->key);*/
	printf("input sa string string // sa string string\n");
	scanf("%s %s %s", saso, key1, key2);
	//s1=search( head,"a");
	//s2=search( head,"name");
	s1=search( head,key1);
		s2=search( head,key2);
	/*printf("the output is:%s\n",s1->key);

	printf("the tempnod is:%s\n",s1->node->filename);
	printf("the tempnod is:%s\n",s1->node->next->filename);
	printf("the tempnod is:%s\n",s1->node->next->next->filename);
*/


//	printf("saso, %s\n",saso);
	if(strcmp(saso,"sa")==0){
	sa(s1,s2);}
	if(strcmp(saso,"so")==0){
	so(s1,s2);}
	/*printf("saso, %s\n",saso);
	printf("saso, %s\n",key1);
	printf("saso, %s\n",key2);*/
	return 1;
}

