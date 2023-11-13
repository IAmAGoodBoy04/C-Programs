/*
Digital Circle of Destiny

Problem Statement:
In the realm of computational challenges, 
we encounter an intriguing scenario involving 'n' tech-savvy individuals engrossed in a virtual gaming experience. 
These friends are seated in a virtual circle, each bearing a unique numeric identifier from 1 to n. 
In this digital circle, navigating clockwise from the ith individual takes you to the (i+1)th individual, where 1 ≤ i < n. 
Furthermore, if you venture clockwise from the nth individual, you'll seamlessly return to the 1st individual.

Now, let's delve into the intricate rules governing this immersive gaming environment:
1. The adventure begins with the 1st friend.
2. The next k friends in the clockwise direction, including the starting friend, are meticulously counted. It's important to note that this counting wraps around the virtual circle, which means you may end up counting the same friend more than once.
3. The friend who is counted last in this process must bid farewell to the circle and is, unfortunately, declared out of the game.
4. If there are still more than one friend remaining in the circle, the gaming saga continues. We return to step 2, starting from the friend immediately clockwise of the individual who just left the circle, and the counting ritual repeats.
5. The game continues until only one friend remains inside the circle. At this point, the last remaining friend is crowned as the ultimate victor of the virtual gaming contest.

Your mission, as an aspiring computer engineer, is to develop a computational solution that, given the number of friends represented by 'n' and an integer 'k', can efficiently determine and declare the triumphant friend who emerges victorious from this captivating digital circle.
The challenge awaits your algorithmic prowess! Craft a program to unveil the winner of this virtual gaming extravaganza, and may the code be ever in your favor.




Example 1:

Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.

Example 2:

Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.

*/

#include "queue.c"
#include<stdio.h>
#include<stdlib.h>
int findDCODChampion(int n, int k){
    que* dcod=initialize_queue(n);
    for(int i=1;i<=n;i++){
        enqueue(dcod,i);
    }
    int temp;
    for(int c=0;c<n-1;c++){
        for(int i=0;i<k-1;i++){
            temp=dequeue(dcod);
            enqueue(dcod,temp);
        }
        temp=dequeue(dcod);
    }
    return front(dcod);
}
int main(){
    int n,k,ans;
    printf("Enter value of n and k for DCOD\n");
    scanf("%d %d",&n,&k);
    ans=findDCODChampion(n,k);
    printf("The winner of the game is %d\n",ans);
    return 0;
}