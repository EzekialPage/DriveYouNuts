//Ezekial Page
//Drive yuh nuts program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//count step number
int counter = 0;

//set all nuts
int nut1 [] = {1, 6, 2, 4, 5, 3};
int nut2 [] = {2, 3, 5, 1, 4, 6};
int nut3 [] = {3, 2, 4, 1, 6, 5};
int nut4 [] = {4, 5, 6, 1, 2, 3};
int nut5 [] = {5, 4, 3, 2, 1, 6};
int nut6 [] = {6, 5, 2, 1, 4, 3};
int nut7 [] = {3, 1, 6, 4, 2, 5};

//set whether nut is used and at what position
int position [] = {-1, -1, -1, -1, -1, -1, -1};
int endOrder [] = {-1, -1, -1, -1, -1, -1, -1};

//declare all functions
int chooseNut();
int rotate(int arr[]);
bool chooseRotate(int n);
bool compareVert(int a[], int b[]);
bool compare45(int a[], int b[]);
bool compare135(int a[], int b[]);
bool chooseCompareVert(int top, int bot);
bool chooseCompare45(int top, int bot);
bool chooseCompare135(int top, int bot);
int search();
bool insert2();
bool insert3();
bool insert4();
bool insert5();
bool insert6();
bool insert7();

int main(){
    bool finished = false;
    bool cont;
    bool skip = false;
    int counter = 0;
    while(finished != true){
        printf("program start\n");
        cont = true;
        //insert step 1
        printf("Start step 1\n");
        if(counter == 0){
            int node1 = chooseNut();
            position[node1] = counter;
            endOrder[counter] = node1;
            printf("Place nut %d\n", node1);
            counter++;
            printf("step 1 completed\n");
        }

        //insert step 2
        printf("Start step 2\n");
        if((insert2() == true) && (cont == true) && (counter == 1)){
            counter++;
            printf("step 2 completed\n");
        }else{
			if((cont == true)&&(counter == 1)){
				counter--;
				cont = false;
				printf("step 2 failed\n");
			}else{
                printf("step 2 skipped\n");
            }
        }

        //insert step 3
        printf("Start step 3\n");
        if((insert3() == true) && (cont == true) && (counter == 2)){
            counter++;
            printf("step 3 completed\n");
        }else{
            if((cont == true)&&(counter == 2)){
				counter--;
				cont = false;
				printf("step 3 failed\n");
			}else{
                printf("step 3 skipped\n");
            }
        }

        //insert step 4
        printf("Start step 4\n");
        if((insert4() == true) && (cont == true) && (counter == 3)){
            counter++;
            printf("step 4 completed\n");
        }else{
            if((cont == true)&&(counter == 3)){
				counter--;
				cont = false;
				printf("step 4 failed\n");
			}else{
                printf("step 4 skipped\n");
            }
        }

        //insert step 5
        printf("Start step 5\n");
        if((insert5() == true) && (cont == true) && (counter == 4)){
            counter++;
            printf("step 5 completed\n");
        }else{
            if((cont == true)&&(counter == 4)){
				counter--;
				cont = false;
				printf("step 5 failed\n");
			}else{
                printf("step 5 skipped\n");
            }
        }

        //insert step 6
        printf("Start step 6\n");
        if((insert6() == true) && (cont == true) && (counter == 5)){
            counter++;
            printf("step 6 completed\n");
        }else{
            if((cont == true)&&(counter == 5)){
				counter--;
				cont = false;
				printf("step 6 failed\n");
			}else{
                printf("step 6 skipped\n");
            }
        }

        //insert step 7
        printf("Start step 7\n");
        if((insert7() == true) && (cont == true) && (counter == 6)){
            finished = true;
            counter++;
            printf("step 7 completed\n");
        }else{
            if((cont == true)&&(counter == 6)){
				counter--;
				cont = false;
			}
			printf("step 7 failed\n");
        }
    }//end while

    //print finished solution
    printf("Drive you nuts solution:\n");
    int j;
    int len;
    for(j = 0; j < 7; j++){
        if(endOrder[j] == 0){
            for(len = 0; len < 7; len++){
                printf("%d ", nut1[len]);
            }
            printf("\n");
        }else if(endOrder[j] == 1){
            for(len = 0; len < 7; len++){
                printf("%d ", nut2[len]);
            }
            printf("\n");
        }else if(endOrder[j] == 2){
            for(len = 0; len < 7; len++){
                printf("%d ", nut3[len]);
            }
            printf("\n");
        }else if(endOrder[j] == 3){
            for(len = 0; len < 7; len++){
                printf("%d ", nut4[len]);
            }
            printf("\n");
        }else if(endOrder[j] == 4){
            for(len = 0; len < 7; len++){
                printf("%d ", nut5[len]);
            }
            printf("\n");
        }else if(endOrder[j] == 5){
            for(len = 0; len < 7; len++){
                printf("%d ", nut6[len]);
            }
            printf("\n");
        }else{
            for(len = 0; len < 7; len++){
                printf("%d ", nut7[len]);
            }
            printf("\n");
        }
    }

    return 0;
}//end main

//gets random number
int chooseNut(){
    bool accepted = false;
    while(accepted == false){
        srand(time(0));
        int random = rand() % 7;
        if ((random == 0) && (position[0] == -1)){
            return 0;
        }else if ((random == 1) && (position[1] == -1)){
            return 1;
        }else if ((random == 2) && (position[2] == -1)){
            return 2;
        }else if ((random == 3) && (position[3] == -1)){
            return 3;
        }else if ((random == 4) && (position[4] == -1)){
            return 4;
        }else if ((random == 5) && (position[5] == -1)){
            return 5;
        }else if ((random == 6) && (position[6] == -1)){
            return 6;
        }else{
            accepted = true;
        }
    }
}

//rotate nut 1 time counter clockwise
int rotate(int arr[]){
    int temp = arr[6];
    int i;
    for (i = 6; i > 0; i--) {
        arr[i] = *(arr + (i+1));
    }
    arr[0] = temp;
}

//choose which nut needs rotating and then rotate it
bool chooseRotate(int n){
    if(n == 0){
        rotate(nut1);
        return true;
    }else if(n == 1){
        rotate(nut2);
        return true;
    }else if(n == 2){
        rotate(nut3);
        return true;
    }else if(n == 3){
        rotate(nut4);
        return true;
    }else if(n == 4){
        rotate(nut5);
        return true;
    }else if(n == 5){
        rotate(nut6);
        return true;
    }else if(n ==6){
        rotate(nut7);
        return true;
    }else{
        printf("Error: ChooseRotate encountered an invalid value");
        return false;
    }
}

//compare vertical connections
bool compareVert(int a[], int b[]){
    if(a[3] == b[0]){
        return true;
    }else{
        return false;
    }
}

//compare 45 degree angle connections
bool compare45(int a[], int b[]){
    if(a[4] == b[1]){
        return true;
    }else{
        return false;
    }
}

//compare 135 degree angle connections
bool compare135(int a[], int b[]){
    if(a[2] == b[5]){
        return true;
    }else{
        return false;
    }
}

//chooses which 2 nuts to compare and calls compare45
//top is top right corner bot is bottom left corner
bool chooseCompare45(int top, int bot){
    if((top == 0)&&(bot == 1)){
        return(compare45(nut1,nut2));
    }else if((top == 0)&&(bot == 2)){
        return(compare45(nut1,nut3));
    }else if((top == 0)&&(bot == 3)){
        return(compare45(nut1,nut4));
    }else if((top == 0)&&(bot == 4)){
        return(compare45(nut1,nut5));
    }else if((top == 0)&&(bot == 5)){
        return(compare45(nut1,nut6));
    }else if((top == 0)&&(bot == 6)){
        return(compare45(nut1,nut7));
    }else if((top == 1)&&(bot == 0)){
        return(compare45(nut2,nut1));
    }else if((top == 1)&&(bot == 2)){
        return(compare45(nut2,nut3));
    }else if((top == 1)&&(bot == 3)){
        return(compare45(nut2,nut4));
    }else if((top == 1)&&(bot == 4)){
        return(compare45(nut2,nut5));
    }else if((top == 1)&&(bot == 5)){
        return(compare45(nut2,nut6));
    }else if((top == 1)&&(bot == 6)){
        return(compare45(nut2,nut7));
    }else if((top == 2)&&(bot == 0)){
        return(compare45(nut3,nut1));
    }else if((top == 2)&&(bot == 1)){
        return(compare45(nut3,nut2));
    }else if((top == 2)&&(bot == 3)){
        return(compare45(nut3,nut4));
    }else if((top == 2)&&(bot == 4)){
        return(compare45(nut3,nut5));
    }else if((top == 2)&&(bot == 5)){
        return(compare45(nut3,nut6));
    }else if((top == 2)&&(bot == 6)){
        return(compare45(nut3,nut7));
    }else if((top == 3)&&(bot == 0)){
        return(compare45(nut4,nut1));
    }else if((top == 3)&&(bot == 1)){
        return(compare45(nut4,nut2));
    }else if((top == 3)&&(bot == 2)){
        return(compare45(nut4,nut3));
    }else if((top == 3)&&(bot == 4)){
        return(compare45(nut4,nut5));
    }else if((top == 3)&&(bot == 5)){
        return(compare45(nut4,nut6));
    }else if((top == 3)&&(bot == 6)){
        return(compare45(nut4,nut7));
    }else if((top == 4)&&(bot == 0)){
        return(compare45(nut5,nut1));
    }else if((top == 4)&&(bot == 1)){
        return(compare45(nut5,nut2));
    }else if((top == 4)&&(bot == 2)){
        return(compare45(nut5,nut3));
    }else if((top == 4)&&(bot == 3)){
        return(compare45(nut5,nut4));
    }else if((top == 4)&&(bot == 5)){
        return(compare45(nut5,nut6));
    }else if((top == 4)&&(bot == 6)){
        return(compare45(nut5,nut7));
    }else if((top == 5)&&(bot == 0)){
        return(compare45(nut6,nut1));
    }else if((top == 5)&&(bot == 1)){
        return(compare45(nut6,nut2));
    }else if((top == 5)&&(bot == 2)){
        return(compare45(nut6,nut3));
    }else if((top == 5)&&(bot == 3)){
        return(compare45(nut6,nut4));
    }else if((top == 5)&&(bot == 4)){
        return(compare45(nut6,nut5));
    }else if((top == 5)&&(bot == 6)){
        return(compare45(nut6,nut7));
    }else if((top == 6)&&(bot == 0)){
        return(compare45(nut7,nut1));
    }else if((top == 6)&&(bot == 1)){
        return(compare45(nut7,nut2));
    }else if((top == 6)&&(bot == 2)){
        return(compare45(nut7,nut3));
    }else if((top == 6)&&(bot == 3)){
        return(compare45(nut7,nut4));
    }else if((top == 6)&&(bot == 4)){
        return(compare45(nut7,nut5));
    }else if((top == 6)&&(bot == 5)){
        return(compare45(nut7,nut6));
    }
}

//chooses which 2 nuts to compare and calls compareVert
bool chooseCompareVert(int top, int bot){
    if((top == 0)&&(bot == 1)){
        return(compareVert(nut1,nut2));
    }else if((top == 0)&&(bot == 2)){
        return(compareVert(nut1,nut3));
    }else if((top == 0)&&(bot == 3)){
        return(compareVert(nut1,nut4));
    }else if((top == 0)&&(bot == 4)){
        return(compareVert(nut1,nut5));
    }else if((top == 0)&&(bot == 5)){
        return(compareVert(nut1,nut6));
    }else if((top == 0)&&(bot == 6)){
        return(compareVert(nut1,nut7));
    }else if((top == 1)&&(bot == 0)){
        return(compareVert(nut2,nut1));
    }else if((top == 1)&&(bot == 2)){
        return(compareVert(nut2,nut3));
    }else if((top == 1)&&(bot == 3)){
        return(compareVert(nut2,nut4));
    }else if((top == 1)&&(bot == 4)){
        return(compareVert(nut2,nut5));
    }else if((top == 1)&&(bot == 5)){
        return(compareVert(nut2,nut6));
    }else if((top == 1)&&(bot == 6)){
        return(compareVert(nut2,nut7));
    }else if((top == 2)&&(bot == 0)){
        return(compareVert(nut3,nut1));
    }else if((top == 2)&&(bot == 1)){
        return(compareVert(nut3,nut2));
    }else if((top == 2)&&(bot == 3)){
        return(compareVert(nut3,nut4));
    }else if((top == 2)&&(bot == 4)){
        return(compareVert(nut3,nut5));
    }else if((top == 2)&&(bot == 5)){
        return(compareVert(nut3,nut6));
    }else if((top == 2)&&(bot == 6)){
        return(compareVert(nut3,nut7));
    }else if((top == 3)&&(bot == 0)){
        return(compareVert(nut4,nut1));
    }else if((top == 3)&&(bot == 1)){
        return(compareVert(nut4,nut2));
    }else if((top == 3)&&(bot == 2)){
        return(compareVert(nut4,nut3));
    }else if((top == 3)&&(bot == 4)){
        return(compareVert(nut4,nut5));
    }else if((top == 3)&&(bot == 5)){
        return(compareVert(nut4,nut6));
    }else if((top == 3)&&(bot == 6)){
        return(compareVert(nut4,nut7));
    }else if((top == 4)&&(bot == 0)){
        return(compareVert(nut5,nut1));
    }else if((top == 4)&&(bot == 1)){
        return(compareVert(nut5,nut2));
    }else if((top == 4)&&(bot == 2)){
        return(compareVert(nut5,nut3));
    }else if((top == 4)&&(bot == 3)){
        return(compareVert(nut5,nut4));
    }else if((top == 4)&&(bot == 5)){
        return(compareVert(nut5,nut6));
    }else if((top == 4)&&(bot == 6)){
        return(compareVert(nut5,nut7));
    }else if((top == 5)&&(bot == 0)){
        return(compareVert(nut6,nut1));
    }else if((top == 5)&&(bot == 1)){
        return(compareVert(nut6,nut2));
    }else if((top == 5)&&(bot == 2)){
        return(compareVert(nut6,nut3));
    }else if((top == 5)&&(bot == 3)){
        return(compareVert(nut6,nut4));
    }else if((top == 5)&&(bot == 4)){
        return(compareVert(nut6,nut5));
    }else if((top == 5)&&(bot == 6)){
        return(compareVert(nut6,nut7));
    }else if((top == 6)&&(bot == 0)){
        return(compareVert(nut7,nut1));
    }else if((top == 6)&&(bot == 1)){
        return(compareVert(nut7,nut2));
    }else if((top == 6)&&(bot == 2)){
        return(compareVert(nut7,nut3));
    }else if((top == 6)&&(bot == 3)){
        return(compareVert(nut7,nut4));
    }else if((top == 6)&&(bot == 4)){
        return(compareVert(nut7,nut5));
    }else if((top == 6)&&(bot == 5)){
        return(compareVert(nut7,nut6));
    }
}

//chooses which 2 nuts to compare and calls compare135
//top is top left corner bot is bottom right corner
bool chooseCompare135(int top, int bot){
    if((top == 0)&&(bot == 1)){
        return(compare135(nut1,nut2));
    }else if((top == 0)&&(bot == 2)){
        return(compare135(nut1,nut3));
    }else if((top == 0)&&(bot == 3)){
        return(compare135(nut1,nut4));
    }else if((top == 0)&&(bot == 4)){
        return(compare135(nut1,nut5));
    }else if((top == 0)&&(bot == 5)){
        return(compare135(nut1,nut6));
    }else if((top == 0)&&(bot == 6)){
        return(compare135(nut1,nut7));
    }else if((top == 1)&&(bot == 0)){
        return(compare135(nut2,nut1));
    }else if((top == 1)&&(bot == 2)){
        return(compare135(nut2,nut3));
    }else if((top == 1)&&(bot == 3)){
        return(compare135(nut2,nut4));
    }else if((top == 1)&&(bot == 4)){
        return(compare135(nut2,nut5));
    }else if((top == 1)&&(bot == 5)){
        return(compare135(nut2,nut6));
    }else if((top == 1)&&(bot == 6)){
        return(compare135(nut2,nut7));
    }else if((top == 2)&&(bot == 0)){
        return(compare135(nut3,nut1));
    }else if((top == 2)&&(bot == 1)){
        return(compare135(nut3,nut2));
    }else if((top == 2)&&(bot == 3)){
        return(compare135(nut3,nut4));
    }else if((top == 2)&&(bot == 4)){
        return(compare135(nut3,nut5));
    }else if((top == 2)&&(bot == 5)){
        return(compare135(nut3,nut6));
    }else if((top == 2)&&(bot == 6)){
        return(compare135(nut3,nut7));
    }else if((top == 3)&&(bot == 0)){
        return(compare135(nut4,nut1));
    }else if((top == 3)&&(bot == 1)){
        return(compare135(nut4,nut2));
    }else if((top == 3)&&(bot == 2)){
        return(compare135(nut4,nut3));
    }else if((top == 3)&&(bot == 4)){
        return(compare135(nut4,nut5));
    }else if((top == 3)&&(bot == 5)){
        return(compare135(nut4,nut6));
    }else if((top == 3)&&(bot == 6)){
        return(compare135(nut4,nut7));
    }else if((top == 4)&&(bot == 0)){
        return(compare135(nut5,nut1));
    }else if((top == 4)&&(bot == 1)){
        return(compare135(nut5,nut2));
    }else if((top == 4)&&(bot == 2)){
        return(compare135(nut5,nut3));
    }else if((top == 4)&&(bot == 3)){
        return(compare135(nut5,nut4));
    }else if((top == 4)&&(bot == 5)){
        return(compare135(nut5,nut6));
    }else if((top == 4)&&(bot == 6)){
        return(compare135(nut5,nut7));
    }else if((top == 5)&&(bot == 0)){
        return(compare135(nut6,nut1));
    }else if((top == 5)&&(bot == 1)){
        return(compare135(nut6,nut2));
    }else if((top == 5)&&(bot == 2)){
        return(compare135(nut6,nut3));
    }else if((top == 5)&&(bot == 3)){
        return(compare135(nut6,nut4));
    }else if((top == 5)&&(bot == 4)){
        return(compare135(nut6,nut5));
    }else if((top == 5)&&(bot == 6)){
        return(compare135(nut6,nut7));
    }else if((top == 6)&&(bot == 0)){
        return(compare135(nut7,nut1));
    }else if((top == 6)&&(bot == 1)){
        return(compare135(nut7,nut2));
    }else if((top == 6)&&(bot == 2)){
        return(compare135(nut7,nut3));
    }else if((top == 6)&&(bot == 3)){
        return(compare135(nut7,nut4));
    }else if((top == 6)&&(bot == 4)){
        return(compare135(nut7,nut5));
    }else if((top == 6)&&(bot == 5)){
        return(compare135(nut7,nut6));
    }
}

//basic linear search on position array only
int search(int a){
    int i;
    for(i = 0; i < 7; i++){
        if(position[i]== a){
            return i;
        }
    }
    return -1;
}

//attempt insert in spot 2
bool insert2(){
    int valid [] = {-1, -1, -1, -1, -1, -1, -1};
    int newNut;
    int middle;
    int i;
    for(i = 0; i < 6; i++){
        //get new nut and verify nut hasn't been used in current step
        newNut = chooseNut();
        while(valid[newNut] != -1){
                printf("While");
            newNut = chooseNut();
        }

        //mark new nut as used in current step
        valid[newNut] = 0;

        //find which nut is in location 0
        middle = search(0);

        int r;
        for(r = 0; r < 7; r++){
            //check if nut matches up or needs to rotate
            if(chooseCompareVert(newNut, middle)){
                position[newNut] = counter;
                endOrder[counter] = newNut;
                printf("Place nut %d\n", newNut);
                return true;
            }else{
                chooseRotate(newNut);
            }
        }
    }
    //if no possible fit found return false
    position[middle] = -1;
    endOrder[counter] = -1;
    return false;
}

//attempt insert in spot 3
bool insert3(){
    int valid [] = {-1, -1, -1, -1, -1, -1, -1};
    int newNut;
    int middle;
    int second;
    int i;
    for(i = 0; i < 5; i++){
        //get new nut and verify nut hasn't been used in current step
        newNut = chooseNut();
        while(valid[newNut] != -1){
            newNut = chooseNut();
        }

        //mark new nut as used in current step
        valid[newNut] = 0;

        //find which nut is in location 0 and 1
        middle = search(0);
        second = search(1);

        //rotate nut until it matches up with middle nut
        int r;
        for(r = 0; r < 7; r++){
            //check if nut matches up or needs to rotate
            if(chooseCompare45(newNut, middle)){
                //check to see if second connection matches
                if(chooseCompare135(second, newNut)){
                    position[newNut] = counter;
                    endOrder[counter] = newNut;
                    printf("Place nut %d\n", newNut);
                    return true;
                }
            }else{
                chooseRotate(newNut);
            }
        }
    }
    //if no possible fit found return false
    position[second] = -1;
    endOrder[counter] = -1;
    return false;
}

//attempt insert in spot 4
bool insert4(){
    int valid [] = {-1, -1, -1, -1, -1, -1, -1};
    int newNut;
    int middle;
    int second;
    int r;
    int i;
    for(i = 0; i < 4; i++){
        //get new nut and verify nut hasn't been used in current step
        newNut = chooseNut();
        while(valid[newNut] != -1){
            newNut = chooseNut();
        }

        //mark new nut as used in current step
        valid[newNut] = 0;

        //find which nut is in location 0 and 1
        middle = search(0);
        second = search(2);

        //rotate nut until it matches up with middle nut
        for(r = 0; r < 7; r++){
            //check if nut matches up or needs to rotate
            if(chooseCompare135(middle, newNut)){
                //check to see if second connection matches
                if(chooseCompareVert(second, newNut)){
                    position[newNut] = counter;
                    endOrder[counter] = newNut;
                    printf("Place nut %d\n", newNut);
                    return true;
                }
            }else{
                chooseRotate(newNut);
            }
        }
    }
    //if no possible fit found return false
    position[second] = -1;
    endOrder[counter] = -1;
    return false;
}

//attempt insert in spot 5
bool insert5(){
    int valid [] = {-1, -1, -1, -1, -1, -1, -1};
    int newNut;
    int i;
    int middle;
    int second;
    int r;
    for(i = 0; i < 3; i++){
        //printf("%d\n", i);
        //get new nut and verify nut hasn't been used in current step
        newNut = chooseNut();
        //printf("newNut: %d\n", newNut);

        while(valid[newNut] != -1){
            //printf("WHILE\n");
            newNut = chooseNut();
        }

        //mark new nut as used in current step
        valid[newNut] = 0;

        //find which nut is in location 0 and 1
        middle = search(0);
        second = search(3);
        //printf("Vars set\n");

        //rotate nut until it matches up with middle nut
        for(r = 0; r < 7; r++){
            //printf("For loop 2: %d\n", r);
            //check if nut matches up or needs to rotate
            if(chooseCompareVert(middle, newNut)){
                //printf("if1\n");
                //check to see if second connection matches
                if(chooseCompare45(second, newNut)){
                    //printf("\n");
                    position[newNut] = counter;
                    endOrder[counter] = newNut;
                    printf("Place nut %d\n", newNut);
                    return true;
                }
            }else{
                //printf("else\n");
                chooseRotate(newNut);
            }
        }
    }
    //if no possible fit found return false
    position[second] = -1;
    endOrder[counter] = -1;
    return false;
}

//attempt insert in spot 6
bool insert6(){
    int valid [] = {-1, -1, -1, -1, -1, -1, -1};
    int newNut;
    int middle;
    int second;
    int r;
    int i;
    for(i = 0; i < 2; i++){
        //printf("%d\n", i);
        //get new nut and verify nut hasn't been used in current step
        newNut = chooseNut();
        while(valid[newNut] != -1){
            //printf("WHILE");
            newNut = chooseNut();
        }

        //mark new nut as used in current step
        valid[newNut] = 0;

        //find which nut is in location 0 and 1
        middle = search(0);
        second = search(4);

        //rotate nut until it matches up with middle nut
        for(r = 0; r < 7; r++){
            //check if nut matches up or needs to rotate
            if(chooseCompare45(middle, newNut)){
                //check to see if second connection matches
                if(chooseCompare135(newNut, second)){
                    position[newNut] = counter;
                    endOrder[counter] = newNut;
                    printf("Place nut %d\n", newNut);
                    return true;
                }
            }else{
                chooseRotate(newNut);
            }
        }
    }
    //if no possible fit found return false
    position[second] = -1;
    endOrder[counter] = -1;
    return false;
}

//attempt insert in spot 7
bool insert7(){
    int valid [] = {-1, -1, -1, -1, -1, -1, -1};
    int newNut;
    int middle;
    int second;
    int third;
    int r;
    int i;
    for(i = 0; i < 1; i++){
        //get new nut and verify nut hasn't been used in current step
        newNut = chooseNut();
        while(valid[newNut] != -1){
            newNut = chooseNut();
        }

        //mark new nut as used in current step
        valid[newNut] = 0;

        //find which nut is in location 0 and 1
        middle = search(0);
        second = search(5);
        third = search(1);

        //rotate nut until it matches up with middle nut
        for(r = 0; r < 7; r++){
            //check if nut matches up or needs to rotate
            if(chooseCompare135(newNut, middle)){
                //check to see if second connection matches
                if((chooseCompare45(third, newNut))&&(chooseCompareVert(newNut, second))){
                    position[newNut] = counter;
                    endOrder[counter] = newNut;
                    printf("Place nut %d\n", newNut);
                    return true;
                }
            }else{
                chooseRotate(newNut);
            }
        }
    }
    //if no possible fit found return false
    position[second] = -1;
    endOrder[counter] = -1;
    return false;
}

