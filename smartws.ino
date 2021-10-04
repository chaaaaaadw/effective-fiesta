

//==== 셋 업 ===============================
void setup()
{
  pinMode(A0,1);  		//LED 
  digitalWrite(A0,1);		//핀 초기값
 
  pinMode(A3,0);  		//CDS 
  digitalWrite(A3,1); 

  pinMode(A4,1);  		//초음파 트리거  
  digitalWrite(A4,0);		// 

  pinMode(A5,0);  		//초음파 에코. 
  digitalWrite(A5,0);		// 
 
  pinMode(8,1);  		//LED 
  digitalWrite(8,0);		// 
  
  pinMode(13,1);  		//진동모터 
  digitalWrite(13,0);	 
}
 

void TRIG(void)			//초음파 트리거 
{digitalWrite(A4,1);
 delayMicroseconds(10);
 digitalWrite(A4,0);    
} 


void VIB(void)			//진동 함수 
{digitalWrite(13,1); 
 delay(100);
 digitalWrite(13,0); 
 delay(100); 
}


//=====    루      프   ========================

void loop()
{
LOOP:
 
 if((digitalRead(A3)))		//밤이면  
   {digitalWrite(8,1); 		//빨강 LED ON
    digitalWrite(A0,0);  	//초록 LED ON  
    delay(100);
    digitalWrite(8,0); 		//빨강 LED OFF
    digitalWrite(A0,1); }	//초록 LED OFF  
   		
   		

 TRIG();			//초음파 발사
 delayMicroseconds(500);
 
 delay(3); 			//50CM
 if(!(digitalRead(A5)))		//장애물 감지시  
   {VIB(); VIB(); VIB();     	//진동 3회씩
    goto LOOP;
   }

 delay(3);			//100cm
 if(!(digitalRead(A5)))		//장애물 감지시  
   {VIB(); VIB(); 		//진동 2회씩
    goto LOOP;
   }
   
 delay(3);			//150cm
 if(!(digitalRead(A5)))		//장애물 감지시  
   {VIB();}     		//진동 1회씩.
}
