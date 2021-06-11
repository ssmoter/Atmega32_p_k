/*
 * GccApplication1.cpp
 *
 * Created: 27.04.2021 13:29:53
 * Author : Slawek
 */ 

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "hd44780.c"
#include "hd44780.h"

	int i=0;
	int k=0;

#pragma region Dzialania
int ADD(int a,int b)
{
	return a+b;
}
int SUB(int a,int b)
{
	return a-b;
}
int DIV(int a,int b)
{
	return a/b;
}
int MULT(int a,int b)
{
	return a*b;
}

#pragma endregion Dzialania

int Score(int A,int B,int Znak)
{
	int wynik;
	switch (Znak)
	{
		case 1:
		wynik=ADD(A,B);
		break;
		case 2:
		wynik=SUB(A,B);
		break;
		case 3:
		wynik=DIV(A,B);
		break;
		case 4:
		wynik=MULT(A,B);
		break;
		default:
		
		break;
	}
	
	return wynik;
}

void CzyszczenieTablicy(char parametr[])
{
	for(int j=0;j<20;j++)
	{
		parametr[j]='\0';
	}
}

void Display(char Parametr[])
{
	LCD_Clear();
	
	for(int j=0;j<i;j++)
	{
		LCD_GoTo(j,0);
		LCD_WriteText(&Parametr[j]);
	}
	_delay_ms(50);
}
void DisplayScore(char parametr[],int Wynik)
{
	for(int j=0;j<i;j++)
	{
		LCD_GoTo(j,0);
		LCD_WriteText(&parametr[j]);
	}
	_delay_ms(50);
	
	char wynik[sizeof(Wynik)];
	itoa(Wynik,wynik,10);
	
	LCD_GoTo(0,3);
	LCD_WriteText(wynik);
	
	_delay_ms(200);

}

int Rzutowanie(char parametr[])
{
	return atoi(parametr);
}


int main(void)
{
LCD_Initalize();
		
		#pragma region Deklaracja portow
		
		DDRC &=~(1<<PC7);
		PORTC |=(1<<PC7);

		DDRC &=~(1<<PC6);
		PORTC |=(1<<PC6);
		
		DDRC &=~(1<<PC5);
		PORTC |=(1<<PC5);
		
		DDRC &=~(1<<PC4);
		PORTC |=(1<<PC4);
		
		DDRC &=~(1<<PC3);
		PORTC |=(1<<PC3);
		
		DDRC &=~(1<<PC2);
		PORTC |=(1<<PC2);
		
		DDRC &=~(1<<PC1);
		PORTC |=(1<<PC1);
		
		DDRC &=~(1<<PC0);
		PORTC |=(1<<PC0);
		
		DDRD &=~(1<<PD0);
		PORTD |=(1<<PD0);
		
		DDRD &=~(1<<PD1);
		PORTD |=(1<<PD1);
		
		DDRD &=~(1<<PD2);
		PORTD |=(1<<PD2);
		
		DDRD &=~(1<<PD3);
		PORTD |=(1<<PD3);
		
		DDRD &=~(1<<PD4);
		PORTD |=(1<<PD4);
		
		DDRD &=~(1<<PD5);
		PORTD |=(1<<PD5);
		
		DDRD &=~(1<<PD6);
		PORTD |=(1<<PD6);
		
		DDRD &=~(1<<PD7);
		PORTD |=(1<<PD7);
		#pragma endregion Deklaracja portow

		char A[20];
		char B[20];
		int Aint;
		int Bint;
		bool znak=true;
		int RodzajDzialania=0;
		uint8_t Delat_time =30;
		
	while(1)
	{
			if (!(PIND &(1<<PD0)))
			{
				_delay_ms(Delat_time);
				
				if (!(PIND &(1<<PD0)))
				{
				i=0;
				k=0;
				znak=true;
				CzyszczenieTablicy(A);
				CzyszczenieTablicy(B);
				Aint=0;
				Bint=0;
				LCD_Clear();
				}
			}
		
		if (znak==true)
		{
			#pragma region PierwszaLiczba
				if (!(PINC &(1<<PC7)))
				{
					_delay_ms(Delat_time);
					
					if (!(PINC &(1<<PC7)))
					{
						A[i]='0';
						Aint=Rzutowanie(A);
						i++;
						Display(A);
					}
				}
				if (!(PINC &(1<<PC6)))
				{
					_delay_ms(Delat_time);
					
					if (!(PINC &(1<<PC6)))
					{
						A[i]='9';
						Aint=Rzutowanie(A);
						i++;
						Display(A);
					}
				}
			if (!(PINC &(1<<PC5)))
			{
					_delay_ms(Delat_time);
					
				if (!(PINC &(1<<PC5)))
				{
					A[i]='8';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			
			if (!(PINC &(1<<PC4)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC4)))
				{
					A[i]='7';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			if (!(PINC &(1<<PC3)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC3)))
				{
					A[i]='6';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			
			if (!(PINC &(1<<PC2)))
			{
					_delay_ms(Delat_time);
					
				if (!(PINC &(1<<PC2)))
				{
					A[i]='5';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			if (!(PINC &(1<<PC1)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC1)))
				{
					A[i]='4';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			
			if (!(PINC &(1<<PC0)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC0)))
				{
					A[i]='3';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			if (!(PIND &(1<<PD7)))
			{
				_delay_ms(Delat_time);
				
				if (!(PIND &(1<<PD7)))
				{
					A[i]='2';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			
			if (!(PIND &(1<<PD6)))
			{
				_delay_ms(Delat_time);
				
				if (!(PIND &(1<<PD6)))
				{
					A[i]='1';
					Aint=Rzutowanie(A);
					i++;
					Display(A);
				}
			}
			#pragma endregion PierwszaLiczba
			#pragma region Znaki
			
			if (!(PIND &(1<<PD2)))
			{
				_delay_ms(Delat_time);
				
				if (!(PIND &(1<<PD2)))
				{
					A[i]='*';
					i++;
					RodzajDzialania=4;
					znak=false;
					Display(A);
				}
			}
			if (!(PIND &(1<<PD3)))
			{
				_delay_ms(Delat_time);
			
				if (!(PIND &(1<<PD3)))
				{
					A[i]='/';
					i++;
					RodzajDzialania=3;
					znak=false;
					Display(A);
				}
			}
			
			if (!(PIND &(1<<PD4)))
			{
				_delay_ms(Delat_time);
				
				if (!(PIND &(1<<PD4)))
				{
					A[i]='-';
					i++;
					RodzajDzialania=2;
					znak=false;
					Display(A);
				}
			}
			if (!(PIND &(1<<PD5)))
			{
				_delay_ms(Delat_time);
				
				if (!(PIND &(1<<PD5)))
				{
				A[i]='+';
				i++;
				RodzajDzialania=1;
				znak=false;
				Display(A);
				}
			}

			#pragma endregion Znaki
		}
		else
		{
			#pragma region DrugaLiczba
			
			if (!(PINC &(1<<PC7)))
			{
				_delay_ms(Delat_time);

				if (!(PINC &(1<<PC7)))
				{
				A[i]='0';
				B[k]='0';
				k++;
				Bint=Rzutowanie(B);
				i++;
				Display(A);
				}
			}
			
			if (!(PINC &(1<<PC6)))
			{
				_delay_ms(Delat_time);

				if (!(PINC &(1<<PC6)))
				{
					A[i]='9';
					B[k]='9';
					k++;
					Bint=Rzutowanie(B);
					i++;
					Display(A);
				}
			}
			if (!(PINC &(1<<PC5)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC5)))
				{
				A[i]='8';
				B[k]='8';
				k++;
				Bint=Rzutowanie(B);
				i++;
				Display(A);
				}
				
			}
			
			if (!(PINC &(1<<PC4)))
			{
					_delay_ms(Delat_time);
					
				if (!(PINC &(1<<PC4)))
				{
					A[i]='7';
					B[k]='7';
					k++;
					Bint=Rzutowanie(B);
					i++;
					Display(A);
				}
			
			}
			if (!(PINC &(1<<PC3)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC3)))
				{
					A[i]='6';
					B[k]='6';
					k++;
					Bint=Rzutowanie(B);
					i++;
					Display(A);
				}
			}
			
			if (!(PINC &(1<<PC2)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC2)))
				{
					A[i]='5';
					B[k]='5';
					k++;
					Bint=Rzutowanie(B);
					i++;
					Display(A);
				}
				
			}
			if (!(PINC &(1<<PC1)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC1)))
				{
					A[i]='4';
					B[k]='4';
					k++;
					Bint=Rzutowanie(B);
					i++;
					Display(A);
				}
				
			}
			
			if (!(PINC &(1<<PC0)))
			{
				_delay_ms(Delat_time);
				
				if (!(PINC &(1<<PC0)))
				{
				A[i]='3';
				B[k]='3';
				k++;
				Bint=Rzutowanie(B);
				i++;
				Display(A);
				}
				
			}
			if (!(PIND &(1<<PD7)))
			{
				_delay_ms(Delat_time);
				
				if (!(PIND &(1<<PD7)))
				{
					A[i]='2';
					B[k]='2';
					k++;
					Bint=Rzutowanie(B);
					i++;
					Display(A);
				}
			}
			
			if (!(PIND &(1<<PD6)))
			{
				_delay_ms(Delat_time);
				if (!(PIND &(1<<PD6)))
				{
					A[i]='1';
					B[k]='1';
					k++;
					Bint=Rzutowanie(B);
					i++;
					Display(A);
				}
			}
			
			
			#pragma endregion DrugaLiczba
				if (!(PIND &(1<<PD1)))
				{
					_delay_ms(Delat_time);
					
					if (!(PIND &(1<<PD1)))
					{
						A[i]='=';
						Display(A);
						i=0;
						k=0;
						DisplayScore(A,Score(Aint,Bint,RodzajDzialania));
						znak=false;
						CzyszczenieTablicy(A);
						CzyszczenieTablicy(B);
						Aint=0;
						Bint=0;
					}
					
				}
		}
	}
}



