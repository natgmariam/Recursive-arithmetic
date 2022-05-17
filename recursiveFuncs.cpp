//
//Description: using recursive functions to do arithmetic's 
//such as counting characthers, ints, reading strings, as
//well as reading and comparing string arrays  
//Input: there is no input, main has text cases to check foe 
//Output: are the test case results from main such as reading 
//all the char is a string of arrays and other such cases

#include "recursiveFuncs.h"
using namespace std;

// * integerPow
unsigned int integerPow(unsigned int num, unsigned int pow){
    // YOUR CODE HERE
    if(pow ==0) return 1;  //base case 
    else if(pow ==1) return num;  //base case 

      //reduction, pow/2 another case chehcking pow 
    else if (pow %2 == 0) return integerPow(num, pow/2) * integerPow(num, pow/2); 
    else {
       //final recursion till we reach pow = 0
        return num * integerPow(num, pow/2) * integerPow(num, pow/2);  
                                     
    }
    
}

// * countChars
unsigned int countCharacter(char *str, char searchChar, unsigned int currentIndex, unsigned int strLength, bool left, bool right){
    // YOUR CODE HERE 
    if(!*str) return 0; //base condition 

    if(searchChar == currentIndex && left == true & right ==true) //if at location 
    
        strLength+=left; //read to the left   
        strLength-=right; //read to the right 
        //ones location is found, add one to the array and read thoug the chars 
        return (*str==searchChar)+countCharacter(str+1, searchChar, currentIndex, strLength, left, right); 

}

// * popBalloons
void popBalloons(char **grid, unsigned int currentHeight, unsigned int currentWidth, unsigned int height, unsigned int width, char balloon){
    // YOUR CODE HERE 
    
    if(currentHeight >= height || currentWidth >= width) return; //base 
    
    if (grid[currentHeight][currentWidth] == balloon) //of at location 
    {
        
        grid[currentHeight][currentWidth]=' '; 
        
        popBalloons(grid, currentHeight+1, currentWidth,height,width,balloon);// move up 
        
        popBalloons(grid, currentHeight-1, currentWidth,height,width,balloon); //move down 
        
        popBalloons(grid, currentHeight,currentWidth+1,height,width,balloon); //move right 
        
        popBalloons(grid, currentHeight, currentWidth-1,height,width,balloon);//left 
    }   
     
    

}

// * countLettersInSentence
unsigned int countLettersInSentence(char **sentence, unsigned int currentWord, unsigned int currentLetter){
    // YOUR CODE HERE
   // int count; 
    if(sentence[currentWord]==nullptr) return 0; //base case 
    
    if(sentence[currentWord][currentLetter] == '\0'){ //check to see if '\o' is reached 
           
        return countLettersInSentence(sentence, currentWord+1, 0); //add only word 
    }  
    
    return 1+ countLettersInSentence(sentence,currentWord,currentLetter+1); //done 
}

// * alphaMerge
unsigned int alphaMerge(char *&destArray, unsigned int currentSize, const char *arr1, const char *arr2, unsigned int p1, unsigned int p2){
    // YOUR CODE HERE
    
    //the base case was not reached so, 
    //after declaring a new array of the correct size,
    // do a deep copy, then determine which letter alphabetically comes next, 
    //dependent on arr1 with p1 and arr2 with p2

    int count = 0; 
    if(arr1[p1]=='\0' && arr2[p2] == '\0') return count; //base case 
    //deep copy for array 
    char *copy=new char[currentSize+1];
    for(int i = 0; i < currentSize; i++){
        copy[i]=destArray[i];
    } 
    delete [] destArray;
    destArray=NULL;
    destArray=copy; //deep copy 
    //if array 1 is empty and 2 issnt 
    if(arr1[p1]=='\0'&&arr2[p2]!='\0'){
        destArray[currentSize]=arr2[p2];
        count= 1; 
        count+=alphaMerge(destArray,currentSize+1, arr1, arr2, p1, p2+1);  
    }
    //if array2 is empty and 1 isnt 
    if(arr1[p1]!='\0'&&arr2[p2]=='\0'){
        destArray[currentSize]=arr1[p1];
        count= 1; 
        count+=alphaMerge(destArray,currentSize+1, arr1, arr2, p1+1, p2);  
    }
    //to print arr1 if its next 
    if(arr1[p1] <= arr2[p2] && arr1[p1] != '\0'&& arr2[p2]!='\0'){
        destArray[currentSize]=arr1[p1];
        count=1;
        count += alphaMerge(destArray, currentSize+1, arr1, arr2, p1+1, p2);
    }
    //to print arr2 if its necr 
    if(arr1[p1]>arr2[p2] && arr1[p1] != '\0' && arr2[p2]!='\0'){
        destArray[currentSize]=arr2[p2];
        count=1;
        count+= alphaMerge(destArray, currentSize+1, arr1, arr2, p1, p2+1);
    }
    return count; //done 
    


    
//    return *temp + alphaMerge(destArray, currentSize, arr1, arr2, p1, p2);

}
