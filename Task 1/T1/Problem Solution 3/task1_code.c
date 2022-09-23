
#include <stdio.h>

#include <string.h>

int Integer[4],i=0,j,k,pos,val;

char Character[8],ch[2];

int v=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //// You can directly use Integer[] and Character[] array. 

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

/* Our program works by the rotation of the numeric array given according to each character and its position */
 void puzzle()

 { 

	char string3[20]=".txt";
	char string1[40]="Test_output_";
	string1[12]=v+48;
	strcat(string1,string3);
	FILE* f= fopen( string1, "w+"); //opening the output files in read and write mode
  	
 	void rotateByOne(int a[], int n)//function that helps in rotating the numbers once
	{

  		int i, temp;

  		temp = a[0];

  		for (i = 0; i < n-1; i++)//for loop over the length of the array

     		a[i] = a[i+1];//switching the numbers 

  		a[i] = temp;//completing the rotation by moving first element to last

	}


 	int q,x,y,z,length,num;

 	for(x=0;x<4;x++)//for loop to print the numbers
 	{

 		printf("%d",Integer[x]);//printing the number series
		

 	}	
	printf("\n");
 	for(y=0;y<8;y++)//for loop to print the characters

 	{   

 		printf("%c",Character[y]);//printing the characters to which a unique number series array is to be generated

 	}

 	printf("\n");

 	

 	int arr[16][2]={{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2},{3,3},{4,0},{4,1},{4,2},{4,3}};//each character based on its position is assigned a 'number'-that denotes the number of times the rotateByOne() should run
	
 	

 	for(z=0;z<8;z++)//Each character is extracted,the numeric array is shifted according to every character 

 	{   

 		if(Character[z]>='A' && Character[z]<='P')//To check is character is within the given constraints

		{

			num=Character[z]-65;//to generate the index for the array
			pos=arr[num][1];
			val=arr[num][0];
			while(Integer[pos]!=val)//The loop where the array rotation takes place based on the character
			{
				rotateByOne(Integer,4);
			}

		 	for(q=0;q<4;q++)//for loop To print the integers after rotation is performed

 			{
				if(q!=3)// to check the integers so that commas are displayed properly 
					fprintf(f,"%d, ",Integer[q]);	
				else
					fprintf(f,"%d ",Integer[q]);	

 			}
			if(Character[z+1]>='A' && Character[z+1]<='P')//condition To insert "-" where ever necessary
				fprintf(f," -  ");	
			

		}

 	}


	fclose(f);//close the output file
	printf("\n");
	v=v+1;
}

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //DO NOT EDIT

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 int main()

 { 
	
 	char str3[20]=".txt";
 	for(k=0;k<3;k++)

 	{

		char str1[40]="Test_input";

 		str1[10]=k+48;

 		strcat(str1,str3);

 		printf("\n%s",str1);

 		printf("\n");	

 		FILE* in_file = fopen( str1, "r"); // read only  

         

        if (! in_file ) // equivalent to saying if ( in_file == NULL ) 

        {  

            printf("oops, file can't be read\n"); 

            return 0;

        } 

 

        // attempt to read the next line and store 

        // the value in the "number" variable 

        for (i = 0; i < 4; i++)

    	{

        	fscanf(in_file, "%d", &Integer[i]);

    	}

    	//memset(&Character[0], 0, sizeof(Character));
	fscanf(in_file, "%c", &ch[0]);
	fscanf(in_file, "%c", &ch[1]);
        for (i = 0; i <8; i++)

    	{

        	fscanf(in_file, "%c", &Character[i]);

    	}             

        puzzle();

    }

    return 0;

}

