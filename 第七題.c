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

void sort(struct sequence *head){
	struct sequence *ptr=head,*ptr2,*k;
	struct number *numPtr,*temp; 
	while(ptr!=NULL){
		numPtr=ptr->behind;
		while(numPtr!=NULL){
			temp=numPtr->next;
			while(temp!=NULL){
				if(numPtr->num>temp->num){
					int t=numPtr->num;
					numPtr->num=temp->num;
					temp->num=t;
			    }
			    temp=temp->next;
			}
			numPtr=numPtr->next;
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
	char ch='Y';
	srand(time(NULL));
	struct sequence *head=NULL,*temp=NULL,*newNode=NULL;
	
	printf("請按enter鍵,不要請按N :");
	scanf("%c",&ch);
	
    while(ch!='N'){
		int ran=rand()%999+1;
		if(checkRand(head,ran)==0){              //檢查有無重複亂數 
			if(checkSeuq(head,ran)==1){          //已有重複digit
			    head=addition(head,ran);
			    print(head);
		    }else{
		    	newNode=creatorSequ();
		    	newNode->behind=creatorNum();
				newNode->digit=ran%10;      
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
	    	printf("亂數已重複\n");
		} 
		printf("請按enter鍵,不要請按N\n");
		scanf("%c",&ch);
   }
   sort(head);
   print(head); 


	return 0;
}

