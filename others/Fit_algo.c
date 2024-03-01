#include <stdio.h>
#include <limits.h>

int FirstFit(int* slotSize,int progSize,int size){
    for (int i = 0; i < size; i++) {
        if (slotSize[i] >= progSize) {
            return i;
        }
    }
    return -1; 
}

int BestFit(int* slotSize,int progSize,int size){
    int shortest=-1;
    int shortest_sizeDiff=INT_MAX;
    for(int i=0;i<size;i++){
        int sizeDiff=slotSize[i]-progSize;
        if((sizeDiff>=0) && (sizeDiff<shortest_sizeDiff) && (slotSize[i]>=progSize)){
            shortest=i;
            shortest_sizeDiff=sizeDiff;
        }
    }
    return shortest;
}

int WorstFit(int* slotSize, int progSize, int size) {
    int worst = -1;
    int largest_sizeDiff = INT_MIN;
    for (int i = 0; i <size; i++) {
        int sizeDiff = slotSize[i] - progSize;
        if (sizeDiff >= 0 && sizeDiff > largest_sizeDiff) {
            worst = i;
            largest_sizeDiff = sizeDiff;
        }
    }
    return worst;
}

void FIT(int* slotSize, int progSize, int size, int* fitResult) {
    int First = FirstFit(slotSize, progSize, size);
    int Best = BestFit(slotSize, progSize, size);
    int Worst = WorstFit(slotSize, progSize, size);
    
    fitResult[0] = slotSize[First];
    fitResult[1] = slotSize[Best];
    fitResult[2] = slotSize[Worst];
}

int main() {
    int slotSize[100];
    int size;
    int progSize;

    printf("Enter the number of slots: ");
    scanf("%d", &size);

    printf("Enter the slot sizes:");
    for (int i = 0; i < size; i++) {
        scanf("%d", &slotSize[i]);
    }

    printf("Enter the program size: ");
    scanf("%d", &progSize);

    int fitResult[3];
    FIT(slotSize, progSize, size, fitResult);

    printf("First Fit: %d\n", fitResult[0]);
    printf("Best Fit: %d\n", fitResult[1]);
    printf("Worst Fit: %d\n", fitResult[2]);

    return 0;
}







