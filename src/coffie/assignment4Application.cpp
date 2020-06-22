/* 

   assignment4Application.cpp -  Text Analysis Using Binary Search Tree
   ============================================================================================

   Author
   ===========================================================================================

   Isaac Coffie, MSIT Carnegie Mellon University Africa
   March 17th 2020


   The functionality of the program is defined as follows.
   ============================================================================================

   The purpose of this assignment is help students analyze text using binary search trees (BST)
   
   This data for the text analysis is stored in an input file (input.txt) with a number of test cases 
   For each test case, we analyze the text and the resulting solution is printed alphabetically unto the output.txt file
   
  Format of the input and output file are defined below
  =============================================================================================

   Input file
   ----------
	../data/words.txt
	../data/textfile1.txt
	../data/textfile2.txt
	../data/textfile3.txt
	../data/textfile4.txt
	../data/textfile5.txt
	../data/textfile6.txt
	../data/textfile7.txt


   Output file
   ------
   The output file is formatted in the following way:

   first line is my Andrew ID
   The remaining line containts the name of the file to be processed, summary statistics of the tree, and words in the dictionary. Sample output file is below

   coffie
	../data/textfileX.txt
	My!!!! HE-ART is in the work
	My heart is in the WIRK Maximum number of probes: XX
	Average number of probes: XX
	heart	1 (X)
	in	2 (X)
	is	2 (X)
	my	2 (X)
	the	2 (X)
	work	1 (X)
	--------------------
	../data/textfileX2.txt



   Solution Strategy / Summary of the Algorithm
   =================================================================================
   I broke down my implementation into sub tasks with the help of helper functions.
   I maintained two binary tree: one for the dictionary words and the other for textual files
   The words from the texts files may not be alphanumeric so I had to process the words such that they meet the specifications

   More importantly, to achieve the task at hand, I adapted the insert algorithm of the BST to keep track of duplicates, and increase the frequency count for all duplicate words. The default count is 1.
   I also created a function (i.e. contains) to check if a word is valid in our word dictionary. This was necessary because we can only insert valid words into out BST
   Since we were asked to compute the maximum and average probes for each tree, I created helper functions, such as get tree height, find size of tree and get total probes, to achieve this task
   
   --MAXIMUM PROBES
   The maximum number of probes is essentially the height of the full tree. I used a recursive algorithm, that recursively compute the hieght of the left and right sub trees
   I created a helper function, called max(), which returns the maximum height of the left and right sub trees
   
   --AVERAGE NUMBER OF PROBES
   Also, the average number of probes is equal to the level of each node element, divided by the size of the tree. 
   To achieve this, I adapted the inorder tree traversal to recursively add the level of each node element to a sum total variable.
   I then divided this sum total by the size of the tree, which was also implemented recursively, counting the number of node element in an in inorder form

   

   Test Strategy
   =================================================================================

   This program has been tested with variety of test data sets that reflect all valid conditions, including boundary conditions:

	#TEST 1: input file with empty content
			
			INPUT:

			
			EXPECTED OUTPUT:
			no content in the output file other than my AndrewID

	#TEST 2: input file with words and 1 text file containing a mixture of correctly and incorrectly spelt words
			
			textfile1.txt:
				My!!!! he-art is in the work
				My heart is in the wirk

			EXPECTED OUTPUT:
				
					coffie
					../data/textfile1.txt
					My!!!! HE-ART is in the work
					My heart is in the WIRK 
					Maximum number of probes: 4
					Average number of probes: 2.5
					heart	1 (3)
					in	2 (2)
					is	2 (1)
					my	2 (0)
					the	2 (1)
					work	1 (2)
					--------------------

	#TEST 3: text file with increasing order of insertion, essentially to create a skinny tree
			
			INPUT:
				heart in is My the work

			EXPECTED OUTPUT:
				
					coffie
					../data/textfile2.txt
					heart in is My the work
					Maximum number of probes: 6
					Average number of probes: 3.5
					heart	1 (0)
					in	1 (1)
					is	1 (2)
					my	1 (3)
					the	1 (4)
					work	1 (5)
					--------------------


	#TEST 4: - input file with more than 1 text file

		INPUT:
		../data/words.txt
		../data/textfile1.txt
		../data/textfile2.txt


		EXPECTED OUTPUT:

			coffie
			../data/textfile1.txt
			My!!!! HE-ART is in the work
			My heart is in the WIRK Maximum number of probes: 4
			Average number of probes: 2.5
			heart	1 (3)
			in	2 (2)
			is	2 (1)
			my	2 (0)
			the	2 (1)
			work	1 (2)
			--------------------
			../data/textfile2.txt
			heart in is My the work
			Maximum number of probes: 6
			Average number of probes: 3.5
			heart	1 (0)
			in	1 (1)
			is	1 (2)
			my	1 (3)
			the	1 (4)
			work	1 (5)
			--------------------

	#TEST 5: text file with empty content
		
		INPUT:
			

		EXPECTED OUTPUT: 
		coffie
		../data/textfile4.txt
		Maximum number of probes: 0
		Average number of probes: 0.0
		--------------------


	#TEST 6: text file with all non alphanumeric words
		
		INPUT:
			!!
			!!!
			??#%^&$^$&*$*(_*>$<$&#%#%^)
			_&^$_^#^$^#^<^#?#^^#^^#^&)&_*%@#%#^^#&
			*%*^$%$^&!!!!!@@@###
			#()$$$$$%%%^^^^(
			!


		EXPECTED OUTPUT: 
		coffie
		../data/textfile6.txt
		Maximum number of probes: 0
		Average number of probes: 0.0
		--------------------

	#TEST 7: Text file with a strange combination of valid word with special characters
		
			INPUT:
				My heart i-s in @##4the work!!!!!!!!!!
				helta! kin?s wer!tou it'd some gh--ana

				EXPECTED OUTPUT:

				coffie
				../data/textfile7.txt
				My heart I-S in @##4THE work!!!!!!!!!!
				HELTA! KIN?S WER!TOU it'd some GH--ANA
				Maximum number of probes: 4
				Average number of probes: 2.5
				heart	1 (1)
				in	1 (2)
				it	1 (3)
				my	1 (0)
				some	1 (2)
				work	1 (1)
				--------------------



    Time Complexity = g(n) = O(NlogN)
   =================================================================================
   The order of complexity of this program is a NlogN
   This is because the outer loop iterates through the number of elements in the input file, which is equal to O(N)
   Within the loop, we call the height, get probe and size of the tree, which takes O(logN) order of complexity
   
   We also perform some constant operations in this loop such as if statements, incrementing counter, printing to file

   So, Overall, our time complexity ~  N*(logN) + K
   Therefore the overall worst case time complexity is O(NlogN)


   File organization -    This segement of comment is adopted from Prof David Vernon
   -----------------

   assignment4.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation
	
  binaryTree.h				Binary Search Tree implementation file header

   assignment4Implementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation

    binaryTreeImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implements the BST
 
   assignment4Application.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application

*/
 
#include "assignment4.h"
#include "binaryTree.h"
 
int main() {

	//declare and initialize global variables
   bool debug = false; // print diagnostic information?
   bool input_dictionary = true;  // we begin by reading the dictionary
   int end_of_file;
   int end_of_file2;
   char filename[MAX_BUFFER_SIZE];
   char word[MAX_BUFFER_SIZE];
   char original_word[MAX_BUFFER_SIZE];
   char alphanum[MAX_BUFFER_SIZE];
   unsigned int i, j; 
   char ch;
   unsigned int k=0;

   //file pointer variables
   FILE *fp_in;
   FILE *fp_out;
   FILE *fp_in2;

   //variables to build the tree
   BINARY_TREE_TYPE dictionary = NULL;
   BINARY_TREE_TYPE tree = NULL;
   ELEMENT_TYPE e;

   //attempt reading the input.txt file
   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
      prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
      prompt_and_exit(1);
   }

   fprintf(fp_out,"coffie\n");

   /* read the filenames from the input file */

   //initialize the dictionary. we only do it once since there is only one dictionary of word
   initialize(&dictionary);

   end_of_file = fscanf(fp_in, "%s", filename);  // read a filename

   while (end_of_file != EOF) {

	   //check if the file is not a dictionary file
      if (!input_dictionary) {
		  fprintf(fp_out,"%s\n",filename);
		  initialize(&tree); // called each time before we read a new text file for analysis
	  }

      /* open the target file: dictionary or text */

      if ((fp_in2 = fopen(filename,"r")) == 0) {  
	      printf("Error can't open text file %s\n",filename);
         prompt_and_exit(1);
      }

      end_of_file2 = fscanf(fp_in2, "%s", original_word);  // read a word from the file

	  /* check the whitespace character after the word to see if it is a newline */
      ch = getc(fp_in2);
	  if (ch == '\n') {
	     strcat(original_word,"\n"); // add a newline character so that subsequent text is on the next line
	  }
	  else {
		 strcat(original_word," ");  // add the whitespace
      }

      while (end_of_file2 != EOF) {
             
		 strcpy(word,original_word); // make a copy of the word so that we can process it
		                             // but keep the original so that we can write it to the output file 

         /* convert word to lower case */
		 
         for (i=0; i<strlen(word); i++) {
            word[i] = tolower(word[i]);
         }

		 /* remove non-alphanumeric characters */
		 k=0;
		 for (i=0; i<strlen(word); i++) {

			 //remove s after apostropher
			 if(word[i] == '\'') break;

			 if (isalnum(word[i]) || word[i] == '-') {
				 alphanum[k++] = word[i];
			 }
		 }

		 alphanum[k] = '\0';
		 
         if (strlen(alphanum) > 0) {

			if (input_dictionary) {
				
				/*** building the dictionary ***/
				//add element to word dictionary
				assign_element_values(&e, alphanum);
			    insert(e, &dictionary);
			}
			else {

			   /*** analyzing text ***/

				//assign element/word to struct
				assign_element_values(&e, alphanum);
					
				//check if word is in dictionary
				if(contains(e, dictionary)){

					insert(e, &tree);
					
					fprintf(fp_out, "%s", original_word); // copy to output 
				} else{

					/* convert word to upper case */
		 
					 for (i=0; i<strlen(original_word); i++) {
						original_word[i] = toupper(original_word[i]);
					 }

					fprintf(fp_out, "%s", original_word); // copy to output 
				}
		       
			}
         }
  
         end_of_file2 = fscanf(fp_in2, "%s", original_word);
		      
	     /* check the whitespace character to see if it is a newline */
         ch = getc(fp_in2);
	     if (ch == '\n') {
	        strcat(original_word,"\n");  // add the newline
	     }
		 else {

			 strcat(original_word," ");  // add the whitespace
		 }
      }

	  if (!input_dictionary) {

		  //print statistics on the tree

		  //print the maximum number of probes
         fprintf(fp_out, "Maximum number of probes: %d\n", height(tree)); 

		 //compute the average probes
		 int size = tree_size(tree);
		 int all_sum = get_total_probes(tree,0);
		 float average = 0.0;

		 if (size > 0){
		 	average = float(all_sum) / size;
		 }

         fprintf(fp_out, "Average number of probes: %3.1f\n", average);

		 //print the frequency and level of tree
		 print_inorder(fp_out, tree, 0);
         fprintf (fp_out,"--------------------\n");
	  }

      fclose(fp_in2); //close file pointer

	  
      end_of_file = fscanf(fp_in, "%s", filename); // read the next filename

	  input_dictionary = false; // the first file is the dictionary file; we've read it so now we reset this flag
   };

   fclose(fp_in);
   fclose(fp_out);
}
