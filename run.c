#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "list.h"
char *s;
main(int argc, char *argv[]){
	FILE *fp, *fd;
	list l;
	node *q, *sq, *start;
	init(&l);
	char c, zipfname[20] = "", fntmp[20] = "", ch, binc[9], bstr[500]; 
	int i, size, chk, count = 0, first = 1, len, j, a, ar[24], choice;
	size = 1024;
        if(argc == 1){
		printf("\nToo few parameter......");
		printf("\nSyntax cmd is ./project file name\n");
		exit(1);
	} 
	strcpy(fntmp,argv[1]);
        for(i = 0; fntmp[i] != '.'; i++){
		zipfname[i] = fntmp[i];
	}
	zipfname[i] = '.';
	i++;
	zipfname[i] = 'z';
	i++;
        zipfname[i] = 'i';
        i++;
        zipfname[i] = 'p';
        i++;
        zipfname[i] = '\0';
        fp = fopen(argv[1], "r");
        if(fp == NULL){
		printf("\nFile does not exsist....\n");
		exit(1);
	}
	while((c = getc(fp)) != EOF){
		if (first == 1){
			append(&l, c);
			first = 0;
		}
		else
			search(&l,c);
	}
	fclose(fp);
	q = l.head;
	while(q != NULL){
		count++;
		q = q->next;
	}
	q = l.head;  
/*	printf("\nLinked List is created having each char from source file with weight 0\n");      
	print(q);
	scanf("%d",&chk);*/
/*	printf("\nAssign  frequency as weight for each char\n");*/
	assign_initial_wt(q);
/*	scanf("%d", &chk);*/
	sq = breakmerge(q,count);
/*	printf("\nUsing merge sort the linked list is sorted\n");
	print(sq);
	scanf("%d", &chk);*/
	start = htree(sq);
	start1 = start;
/*	printf("\nCreation of Huffman Tree\n");        */
/*	treestruct(start1, 0);*/
/*	scanf("%d", &chk);
	printf("\nAfter creating Huffman tree Linked list is created:\n");*/
	printPaths(start);
	i = 0;
/*	scanf("%d",&chk);
	printf("\nStarted file compression................");*/
	int pos = 0;
	fp = fopen(argv[1], "r");    
	char *buffer = (char *)malloc(size);
	pos = 0;
	while((c = getc(fp)) != EOF){
		buffer[pos++] = c;
		if(pos >= size - 1) { 
			size *= 2;
			buffer = (char*)realloc(buffer, size);
		}
 	}
	buffer[pos] = '\0';
	fclose(fp);
/*	printf("\nSource Program is......");
	printf("\n%s", buffer);
	scanf("%d", &chk);*/
	char *bs = (char *)malloc(size);
	conversion(buffer, bs);
	char *coded_str = (char *)malloc(size);
/*	printf("\nBinary form is\n %d %s",(int)strlen(bs), bs);
	scanf("%d", &chk);*/
	size = strlen(bs) + 12;
	B_to_decod(bs, coded_str, size);              
/*	printf("\nCoded form of binary in char form is-> %s",coded_str);
	scanf("%d",&chk);*/
	fd = fopen(zipfname,"w+");
	fprintf(fd,"%s",coded_str);
	fclose(fd);
	free(buffer);
        free(bs);           
        free(coded_str);
	printf("\nDo you want to unzip file press 1 for yes and 0 for No:");
	scanf("%d", &choice);
	if (choice == 1){
		fp = fopen(zipfname,"rb");
		size = 1024;
		buffer = (char *)malloc(size);
		pos = 0;
		while((c = getc(fp)) != EOF){
			buffer[pos++] = c;
			if(pos >= size - 1) { 
				size *= 2;
				buffer = (char*)realloc(buffer, size);
			}
		}  
		buffer[pos] = '\0';
		len = strlen(buffer);
		bs = (char *)malloc(size);
		pos = 0;
//		scanf("%d", &chk);
		for(i = 0;i < len; i++){
			ch = buffer[i];
			atob(ch, ar);
			for(j = 0; j < 8; j++){
				a = 48 + ar[j]; 
				bs[pos++] = a;
				if(pos >= size - 1) { 
					size *= 2;
					bs = (char*)realloc(bs, size);
				}
			}   
		}
		bs[pos] = '\0';
		char *bsw = (char *)malloc(size); 
		int bslen = strlen(bs);
		int cnt0_5 = 0, cnt1_5 = 0,found = 0;
		bsw[0] = bs[0];
		bsw[1] = bs[1];
		bsw[2] = bs[2];
		for(i = 3, j = 3;i < bslen; i++){
			if (found == 0){
				if(bs[i] == '0'){
					cnt0_5++;
					if(cnt0_5 == 5){     
						cnt0_5 = 0;
						found = 1; 
					}
					else
						cnt1_5 = 0;
					bsw[j++] = bs[i];
				}
				else{
                         		cnt1_5++;
					if(cnt1_5 == 5){
						cnt1_5=0; 
						found = 1;
					}
					else
						cnt0_5 = 0;
					bsw[j++] = bs[i]; 
				}
			}
			else
				found = 0;
		} 
		bsw[j] = '\0';          
/*		printf("\nAfter Reading Coded file it is converted into binary form\n");
		printf("\n%s", bsw);
		scanf("%d", &chk);*/
		int dsize = 1024;
		char *decoded_str = (char *)malloc(dsize);
		conv_bin_char(bsw, decoded_str);
		printf("\ndecoded file is:-\n%s", decoded_str);
		fclose(fp);
	}
printf("\ndone.....");
printf("\nAcknoledgement\n");
printf("\n I would like to thanks Director, COEP and Head, Department of Computer Enginerring and IT");
printf("\n for providing favourable environment for bidding scholars");
printf("\n I would like to spcially thank Prof Abhijeet A M and teachers for providing techincal guidence.");
printf("\n during development of this mini project");
printf("\n Thank you.....\n"); 
}
