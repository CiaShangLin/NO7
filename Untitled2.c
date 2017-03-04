#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct number{
	struct number *next;
	int num;
};

struct sequence{
	struct sequence *next;
	struct number *behind;
	int digit;
};

struct sequence *creatorSequ(){
	struct sequence *newNode;
	newNode=(struct sequence *)malloc(sizeof(struct sequence));
	newNode->behind=NULL;
	newNode->next=NULL;
	return newNode;
}

struct number *creatorNum(){
	struct number *newNode;
	newNode=(struct number *)malloc(sizeof(struct number));
	newNode->next=NULL;
	return newNode;
}

int checkRand(struct sequence *head,int rand){
	struct sequence *ptr=head;
	struct number *ptr2;
	while(ptr!=NULL){
		if(rand%10==ptr->digit){
			ptr2=ptr->behind;
			while(ptr2!=NULL){
				if(ptr2->num==rand){
					return 1;
				}
				ptr2=ptr2->next;
			}
		}
		ptr=ptr->next;
	}
	return 0;
}

int checkSeuq(struct sequence *head,int rand){
	struct sequence *ptr=head;
	while(ptr!=NULL){
		if(ptr->digit==rand%10)
		  return 1;
		ptr=ptr->next;
	}
	return 0;
}

struct sequence *addition(struct sequence *head,int rand){
	struct sequence *ptr=head;
	struct number *ptr2;
	while(ptr!=NULL){
		if(ptr->digit==rand%10){
			ptr2=ptr->behind;
			while(ptr2!=NULL){
				while(ptr2->next==NULL){
					ptr2->next=creatorNum();
					ptr2->next->num=rand;
					return head;
				}
				ptr2=ptr2->next;
			}
		}
		ptr=ptr->next;
	}

}

void print(struct sequence *head){
	struct number *ptr2;
	struct sequence *ptr=head;
	while(ptr!=NULL){
		printf("%d:",ptr->digit);
		ptr2=ptr->behind;
		while(ptr2!=NULL){
			printf("%d ",ptr2->num);
			ptr2=ptr2->next;
		}
		printf("\n");
		ptr=ptr->next;
	}
}


int main(int argc, char *argv[]) {
	int run=1;
	char ch;
	srand(time(NULL));
	struct sequence *head=NULL,*temp=NULL,*newNode=NULL;
	
    while(run==1){
		scanf("%c",&ch);
		int ran=rand()%999+1;
		if(checkRand(head,ran)==0){                  //
			if(checkSeuq(head,ran)==1){          //-??A¡±A?A 
			    head=addition(head,ran);
			    print(head);
		    }else{
		    	newNode=creatorSequ();
		    	newNode->behind=creatorNum();
				newNode->digit=ran%10;      //¡Lu¡±A?A 
				newNode->behind->num=ran;
			    if(head==NULL){
				    head=newNode;
				    temp=newNode;
			    }else{
			    	temp->next=newNode;
			    	temp=newNode;
		    	}
				print(head);
		    }
	    }else{
	    	printf("-??A?A?A\n");
		} 
   }

	return 0;
}

