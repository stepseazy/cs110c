/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
import java.util.Scanner;
/**
 *
 * @author hendrik.brutsaert@cs110c.ccsf
 */
public class JavaApplication1 {
	static final int CARDS_IN_ROW=7;
	static final int NUM_CARDS=21;
	static final int NUM_ROWS=3;
	static int[] cardArray= new int[NUM_CARDS];
	static int[][] cardArray2d= new int[NUM_ROWS][CARDS_IN_ROW];
	
	public static void initArray() {
		for(int i=0;i<NUM_CARDS;i++) {
			cardArray[i]=i;
		}
	}
	
	public static int getRand(int min, int max){
		return min + (int)(Math.random() * ((max - min) + 1));
	}
	
	public static int getRow() {
		System.out.println("Which row is your card in");
		Scanner scan=new Scanner(System.in);
		return scan.nextInt();
	}
	
	public static void dealCards() {
		int counter=0;
		for (int col=0;col<CARDS_IN_ROW; col++) {
		for(int row=0;row<NUM_ROWS; row++) {
			cardArray2d[row][col]=cardArray[counter];
			counter++;
		}
		}
	}
	
	public static void printCards() {
		for(int row=0;row<NUM_ROWS; row++) {
		for (int col=0;col<CARDS_IN_ROW; col++) {			
			System.out.print(cardArray2d[row][col]+" ");
		}
		System.out.println(" ");
		}
	}
	
	public static void swap(int arr[], int i, int j) {
		int temp;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	
	}
	
	public static void putInCardArray() {
		
		for(int row=0;row<NUM_ROWS; row++) {
		for (int col=0;col<CARDS_IN_ROW; col++) {			
			cardArray[row*7+col]=cardArray2d[row][col];
		}
		}
	}
	
	public static void putInMiddle(int columnChosen) {
		int firstCol=0;
		int secondCol=1;
		int thirdCol=2;
		
		switch(columnChosen) {
		case(1):
			firstCol=1;
			secondCol=0;
			thirdCol=2;
			break;
		case(2):
			firstCol=0;
			secondCol=1;
			thirdCol=2;
			break;
		case(3):
			firstCol=1;
			secondCol=2;
			thirdCol=0;
			break;
		}
		for(int i=0;i<CARDS_IN_ROW; i++) {
			cardArray[i]=cardArray2d[firstCol][i];
			cardArray[i+CARDS_IN_ROW]=cardArray2d[secondCol][i];
			cardArray[i+CARDS_IN_ROW*2]=cardArray2d[thirdCol][i];
		}
	}
	
	public static void main(String[] args) {
		int chosenRow=1;
		initArray();
		dealCards();
		System.out.println("Chose a card");
		for(int i=0;i<4;i++) {
			printCards();
			chosenRow=getRow();
			putInMiddle(chosenRow);
			dealCards();
			putInCardArray();	
		}

	}
    
}
