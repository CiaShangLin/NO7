#include <stdio.h>
#include <stdlib.h>

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

int checkSeuq(){
	
}


int main(int argc, char *argv[]) {
	int run=1;
	struct sequence *head=NULL,*temp=NULL,*newNode=NULL;
	struct number *ptr=NULL;
	while(run!=1){
		int rand=rand()%999+1;
		if(checkRand()==1){                  //重複亂數 
			if(checkSeuq(head)==1){          //重複尾數 
			    
		    }else{
		    	newNode=creatorSequ();
				newNode->digit=rand%10;      //取尾數 
			    if(head==NULL){
				    head=newNode;
				    temp=newNode;
			    }else{
			    	temp->next=newNode;
			    	temp=newNode;
		    	}
		    }
	    }else{
	    	printf("重複亂數\n");
		} 
   }

	return 0;
}
