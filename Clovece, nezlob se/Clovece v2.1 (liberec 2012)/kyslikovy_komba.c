
void pohyb_na_bod2(float Xt, float Yt, float Zt)
{
	uint16_t pozice_motor0, pozice_motor1,pozice_motor2,pozice_motor3,pozice_motor4,B_term;
	int a0_term,a1_term, a2_term,a3_term,a4_term,a5_term,a6_term,a7_term;
	uint16_t B,B2;
	double a0,a1,a2,a3;	//uhel ramena
	double a4;	//uhel loktu
	double a5,a6,a7;	//uhel zapesti

	//alfa=(alfa*(M_PI/180));
	B2=sqrt(pow(Xt,2)+pow(Yt,2));																	//prepocitani do 2d
	//Zt=Zt+(sin(alfa)*delka_ramena4);																//pricteni naklonu
	//B2=B2+(cos(alfa)*delka_ramena4);
	B=sqrt(pow(B2,2)+pow(Zt,2));																	//delka spojnice
	a0=atan2(Yt,Xt);																				//uhel spojnice
	a1=acos((pow(delka_ramena1,1)-pow(delka_ramena1,2)+pow((B/2),2))/(2*delka_ramena1*(B/2)));
	a2=atan2(Zt,Xt);
	a3=a1+a2;
	a4=acos((pow(delka_ramena1,2)+pow(delka_ramena2,2)-pow((B/2),2))/(2*delka_ramena1*delka_ramena1));
	a5=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-pow(delka_ramena1,2))/(2*delka_ramena2*delka_ramena2));
	a6=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-pow((B/2),2))/(2*delka_ramena2*delka_ramena3));
	a7=a5+a6;

	pozice_motor0=(((((5*M_PI)/6)+a0)*180/M_PI)*3.4133333);
	pozice_motor1=(((((M_PI)/6)+a3)*180/M_PI)*3.4133333);
	pozice_motor2=((((a4+a5)-(M_PI/6))*180/M_PI)*3.4133333);
	pozice_motor3=(((a7-(M_PI/6))*180/M_PI)*3.4133333);

	motor[1].position(pozice_motor0);
	motor[2].position(pozice_motor1);
	motor[3].position(pozice_motor2);
	motor[4].position(pozice_motor3);


	/*a0_term=a0*180/M_PI;
	a1_term=a1*180/M_PI;
	a2_term=a2*180/M_PI;
	a3_term=a3*180/M_PI;
	a4_term=a4*180/M_PI;
	a5_term=a5*180/M_PI;
	a6_term=a6*180/M_PI;
	a7_term=a7*180/M_PI;

	pc<<"B "<<B<<endl;
	pc<<"A0 "<<a0_term<<endl;
	pc<<"A1 "<<a1_term<<endl;
	pc<<"A2 "<<a2_term<<endl;
	pc<<"A3 "<<a3_term<<endl;
	pc<<"A4 "<<a4_term<<endl;
	pc<<"A5 "<<a5_term<<endl;
	pc<<"A6 "<<a6_term<<endl;
	pc<<"A7 "<<a7_term<<endl;

	pc<<"Pozice 1:"<<pozice_motor1<<endl;
	pc<<"Pozice 2:"<<pozice_motor2<<endl;
	pc<<"Pozice 3:"<<pozice_motor3<<endl;*/
}

void pohyb_na_bod2(float Xt, float Zt)
{
	uint16_t pozice_motor1;
	uint16_t pozice_motor2;
	uint16_t pozice_motor3;
	uint16_t B_term;
	int a1_term;
	int a2_term;
	int a3_term;
	int a4_term;
	int a5_term;
	int a6_term;
	int a7_term;
	uint16_t B;
	uint16_t B_22;
	double a1;
	double a2;
	double a3;	//uhel ramena
	double a4;	//uhel loktu
	double a5;
	double a6;
	double a7;	//uhel zapesti

	B=sqrt(pow(Xt,2)+pow(Zt,2));
	B_22=pow((B/2),2);
	a1=acos((pow(delka_ramena1,1)-pow(delka_ramena1,2)+B_22)/(2*delka_ramena1*(B/2)));
	a2=atan2(Zt,Xt);
	a3=a1+a2;
	a4=acos((pow(delka_ramena1,2)+pow(delka_ramena2,2)-B_22)/(2*delka_ramena1*delka_ramena1));
	a5=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-pow(delka_ramena1,2))/(2*delka_ramena2*delka_ramena2));
	a6=acos((pow(delka_ramena2,2)+pow(delka_ramena2,2)-B_22)/(2*delka_ramena2*delka_ramena3));
	a7=a5+a6;

	pozice_motor1=((((M_PI/6)+a3)*180/M_PI)*3.4133333);
	pozice_motor2=((((a4+a5)-(M_PI/6))*180/M_PI)*3.4133333);
	pozice_motor3=(((a7-(M_PI/6))*180/M_PI)*3.4133333);

	motor[2].position(pozice_motor1);
	motor[3].position(pozice_motor2);
	motor[4].position(pozice_motor3);

	a1_term=a1*180/M_PI;
	a2_term=a2*180/M_PI;
	a3_term=a3*180/M_PI;
	a4_term=a4*180/M_PI;
	a5_term=a5*180/M_PI;
	a6_term=a6*180/M_PI;
	a7_term=a7*180/M_PI;

	pc<<"B "<<B<<endl;
	pc<<"A1 "<<a1_term<<endl;
	pc<<"A2 "<<a2_term<<endl;
	pc<<"A3 "<<a3_term<<endl;
	pc<<"A4 "<<a4_term<<endl;
	pc<<"A5 "<<a5_term<<endl;
	pc<<"A6 "<<a6_term<<endl;
	pc<<"A7 "<<a7_term<<endl;

	pc<<"Pozice 1:"<<pozice_motor1<<endl;
	pc<<"Pozice 2:"<<pozice_motor2<<endl;
	pc<<"Pozice 3:"<<pozice_motor3<<endl;
}

void pohyb_na_bod(float Xt, float Zt)
{
	uint16_t pozice_motor1,pozice_motor2,B_term;
	int alfa_term,beta_term,gamma_term,delta_term,B;
	double alfa,beta,gamma,delta;

	B=sqrt(pow(Xt,2)+pow(Zt,2));
	alfa=atan2(Zt,Xt);
	beta=acos((pow(delka_ramena1,2)-pow(delka_ramena2,2)+pow(B,2))/(2*delka_ramena2*B));
	gamma=alfa+beta;
	delta=acos((pow(delka_ramena1,2)+pow(delka_ramena2,2)-pow(B,2))/(2*delka_ramena1*delka_ramena2));
	pozice_motor1=((((M_PI/3)+gamma)*180/M_PI)*3.4133333);
	pozice_motor2=(((((M_PI/3)+delta-(M_PI_2))*180/M_PI))*3.4133333);
	motor[2].position(pozice_motor1);
	motor[3].position(pozice_motor2);

	//B_term=B*1000;
	alfa_term=alfa*180/M_PI;
	beta_term=beta*180/M_PI;
	gamma_term=gamma*180/M_PI;
	delta_term=delta*180/M_PI;
	pc<<B<<endl;
	pc<<"alfa je:"<<alfa_term<<endl;
	pc<<"beta je:"<<beta_term<<endl;
	pc<<"gamma je:"<<gamma_term<<endl;
	pc<<"delta je:"<<delta_term<<endl;
	pc<<"pozice motoru1:"<<pozice_motor1<<endl;
	pc<<"pozice motoru2:"<<pozice_motor2<<endl;
}



while(1)
{
    if(buttons.isStart())
    {
        while(buttons.isStart())
        {
        }
            for(i=0; i!=pocet_motoru; i++)
            {
                motor[i+1].speed(1023);
            }

        //pohyb_na_bod2(100,100,100);

        for (;;)
        {
            //pohyb_na_bod2(50,50,50);
            for (int a=0;a!=360;a++)
            {
                pohyb_na_bod2(150,0,120,a);
                //pc<<a<<endl;
                _delay_ms(10);
            }
            for (int a=360;a!=0;a--)
            {
                pohyb_na_bod2(150,0,120,a);
                //pc<<a<<endl;
                _delay_ms(10);
            }

        }
    }
}
