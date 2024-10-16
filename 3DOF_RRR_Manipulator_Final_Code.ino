/**************************************************Author : Team  *******************************************************************/
/**************************************************Date   : 25/4/2023  **************************************************************/
/**************************************************Title  : RRR_Manipulator_Robot_arm************************************************/
/************************************************************************************************************************************/

/* Sensors_used_Discription */
/**************************************************Ultrasonic_sensor*****************************************************************/
/* Sensor_Discription: */
/*  instrument that measures the distance to an object using ultrasonic sound waves. */
/*   working_principle_of_ultrasonic_sensor :
 *    
 *                                          It sends an ultrasonic pulse out at 40kHz which travels 
 *                                          through the air and if there is an obstacle or object, 
 *                                          it will bounce back to the sensor.By calculating the travel 
 *                                          time and the speed of sound,the distance can be calculated.
*/  
/* Equations_to_determine_distance :
 *  
 *                                          speed   = distance/time..
 *                                          350 m/s = 350 * 0.0001 = 0.035 cm/micro_second.. 
 *                                          0.035   = d/(time/2)
 *                                          d/t     = 0.035/2
 *                                          d       = t/57...    will be written in code..
 */
/* HC_SR04_Circuit:
 *                                          HC_SR04 has four pins .. 
 *                                          vcc , GND , TRIG & echo pin ..
 *                                          TRIG : starting transimission pin.
 *                                          echo : receiving the reflected wave..
 */
 /* HC_SR04_data:
  *                                         Max_distance : 4m
  *                                         min_Distance : 2 cm
  */
/**************************************************Water_Level_sensor*****************************************************************/
/***********************************************************************************************************************************/
/* Sensor_Discription: */
/*   instrument that can detect the presence of water "as rain detector"
     as well as using it to determine the level of water in such a container */
     
/*   working_principle_of_Water_Level_sensor :
                                             * 1- Sensor contains 10 rods , each five is connected to each other..   
                                             *    , npn transistor " working as a switch by appling voltage to its base .
                                             * 2- 5 rods are connencted to resistance and 5v voltage..
                                             *    , the other 5 rods are connected to the base.. 
                                             *    collector of transistor is connected with 5v voltage..
                                             *    emmitor is connected with ground.. 
                                             *    when water is on sensor , a resistance is been found between rods , so 
                                             *    voltage is applied on base , then circuit is off...
                                             * 3- value of resistance determine the level of water...
*/
/* SE045_data:
                                             * Max_distance_for_detect_water : 4cm
                                             * min_Distance_for_detect_water : 0.5 cm
*/    
/* SE045_Circuit:
                                             * VCC , GND pin       
                                             * Signal pin " resistance value " . 
*/
/***********************************************************************************************************************************/
/* Define_Arduino_pins */
/* Servo_pins */
/* Pwm_Servo_Driver_used*/
#define servo_joint1  1 
#define servo_joint2  2 
#define servo_joint3  3 

/* Ultrasonic_pins */
#define trig_pin  4
#define echo_pin  5

/* Water_Level_pins */
#define water_signal_pin  A1

/* Object */
#define  Cup_length  8   
/***********************************************************************************************************************************/
/* Libraries_inclueded */
/* including_arduino_servo_library */
   #include <Servo.h> 
/************************************************************************************************************************************/
/* Define_Global_Variables*/

/* Manipulator_Links_Length(Fixed) */
/* Links_Length as measured */
  const float Link1_length = 5;
  const float Link2_length = 12;
  const float Link3_length = 9;

/* Joint_angles_values */
  double Theta1  = 0;
  double Theta2  = 0 ; 
  double Theta3  = 0 ;

/* Ultrasoinc_Global_Variables */
 unsigned int Global_u32_Distance = 0 ;
 unsigned int Global_u32_Time = 0;
 uint8_t      Global_is_water = 0;


/* Water_level_Global_Variables */
 unsigned int Res_value = 0 ;

/************************************************************************************************************************************/
/* Define_objects */
/* making objects fron class servo for joint1 , joint2 , joint3 */
Servo Joint_1;
Servo Joint_2;
Servo Joint_3;
/***********************************************************************************************************************************/
/* Functions_Prototypes*/

/* Manipulator_Main_Task_intialization_function_prototype*/
 void Manipulator_Go_To_Cup_intialization(void);
 void Manipulator_Go_To_inital(void);
 
/* Manipulator_Main_Task_function_prototype*/
void Manipulator_Go_To_Cup(void);

/* Manipulator_functions_prototypes */
 void Get_Joints_Angles ( int px , int py , int pz);

/* Servo_motor_functions_prototypes.. */ 
void Servo_joints_void_Init( uint8_t joint1_signal_pin , uint8_t joint2_signal_pin , uint8_t joint3_signal_pin );
void Servo_void_Rotate (  uint8_t Servo_joint_number , uint8_t Angle_Of_Rotation );

/* UltraSonic_functions_prototypes */
void UltraSonic_void_Init(uint8_t TRIG_PIN , uint8_t ECHO_PIN );
void UltraSonic_void_Start_Triggering(uint8_t TRIG_PIN , uint8_t ECHO_PIN );
void UltraSonic_void_Get_Distance(uint8_t ECHO_PIN);

/* Water_Level_functions_prototypes */ 
void Water_Level_void_Init(uint8_t Signal_Pin);
void Water_Level_char_Detection(uint8_t Signal_Pin);
/************************************************************************************************************************************/
/* Run_one_Time */
void setup()
{
 Serial.begin(9600);
 Manipulator_Go_To_Cup_intialization();
 //UltraSonic_void_Init(trig_pin , echo_pin );
 //UltraSonic_void_Start_Triggering(trig_pin , echo_pin );

}

/************************************************************************************************************************************/
/* Run_Repeatly */
void loop()
{
 //  UltraSonic_void_Start_Triggering(trig_pin , echo_pin );

 // UltraSonic_void_Get_Distance(echo_pin);
      Manipulator_Go_To_Cup();
      Serial.println(Global_u32_Distance);

}
/************************************************************************************************************************************/

/* Functions_implementations */
/* Servo_motor_functions_implementations.. */ 
void Servo_joints_void_Init( uint8_t joint1_signal_pin , uint8_t joint2_signal_pin , uint8_t joint3_signal_pin )
{
     Joint_1.attach(joint1_signal_pin);
     Joint_2.attach(joint2_signal_pin);
     Joint_3.attach(joint3_signal_pin);

}
/***********************************************************************************************************************************/
void Servo_void_Rotate ( uint8_t Servo_joint_number, uint8_t Angle_Of_Rotation )
{
     /* Servo_joint_number :
                           *  choose from :
                           *  1- servo_joint1
                           *  2- servo_joint2
                           *  3- servo_joint3
     */

     /* Rotate first joint */
     if      ( Servo_joint_number == 1 )  
     {
     Joint_1.write( Angle_Of_Rotation );
     }
     
     /* Rotate second joint */
     else if ( Servo_joint_number == 2 ) 
     {
     Joint_2.write( Angle_Of_Rotation );
     }

     /* Rotate third joint */
     else if ( Servo_joint_number == 3 ) 
     {
     Joint_3.write( Angle_Of_Rotation );
     }
     else ;
}
/***********************************************************************************************************************************/
/* UltraSonic_functions_implementations */

/* UltraSonic_Intialization */
void UltraSonic_void_Init( uint8_t TRIG_PIN , uint8_t ECHO_PIN )
{
     /* TRIG_PIN as Output to send signal of start triggering */
     pinMode(TRIG_PIN , OUTPUT);
     /* ECHO_PIN as Input to receive signal of determining an object */
     pinMode(ECHO_PIN , INPUT);
}

/*************************************************************UltraSonic_Start_Triggering *******************************************/

void UltraSonic_void_Start_Triggering(uint8_t TRIG_PIN , uint8_t ECHO_PIN )
{
    /*  step 1  : make sure Trig_pin has low signal .. */
    digitalWrite( TRIG_PIN , LOW );
    /*  step 2  : wait for 5 microseconds... */
    delayMicroseconds(5);           
    /*  step 3  : Trig_pin is high to start triggering..*/
    digitalWrite( TRIG_PIN , HIGH);
    /*  step 4  : wait for 10 microseconds... */
    delayMicroseconds(10);           
    /*  step 5  : Trig_pin is low again.. */
    digitalWrite( TRIG_PIN , LOW );
    /*  MCU will transmit 8 pulses with 40khz.... */
}
/***********************************************************************************************************************************/
/* Determining_distance_from_object*/
void UltraSonic_void_Get_Distance(uint8_t ECHO_PIN)
{
  
    Global_u32_Distance = 0 ;
    /*step 1 : Determining time of travelling and reflecting " when echp pin as high " */
    Global_u32_Time = pulseIn(ECHO_PIN , HIGH );
    /*step 1 : Determining Distance */
    Global_u32_Distance = Global_u32_Time /57 ;

    delay(500);
}
/***********************************************************************************************************************************/
/* Water_Level_functions_implementation */ 
void Water_Level_void_Init(uint8_t Signal_Pin)
{
  /* Signal_pin"analog" is input...*/
  pinMode(Signal_Pin, INPUT);
}
/***********************************************************************************************************************************/
void Water_Level_char_Detection(uint8_t Signal_Pin)
              {
              Res_value = 0;
              /* step 1 : get the value of resistance */
              Res_value = analogRead( Signal_Pin );
   
              /* step 2 : detect if there is water */
              if( Res_value > 0 )   
                 {
                 Global_is_water = 1 ;
                /* water Detection!!! */
                 }
     
              else 
              {
                 Global_is_water = 0 ;

              }
             /* step 3 : return result */
             delay(100);
             
              }
/***********************************************************************************************************************************/
 /* Function to get the three joints "Servo Angles" 
 *  arguiments : position of cup of water in x,y,z ..
 */

 void Get_Joints_Angles ( int px , int py , int (pz))
 {
  pz = pz--;
  /* step 1: define_local_variables */
  float r = 0;
  float k = 0;

  float alpha = 0 ;
  float beta  = 0 ;

  Theta1  = 0 ;
  Theta2  = 0 ; 
  Theta3  = 0 ;
  
  /* step 2: Theta1 *
  /**********************Calc_joint1_angle****************************************************************/
  Theta1 = atan2(py,px);

  /* step 2: Theta2 *
  /**********************Calc_joint3_angle****************************************************************/
  
  /* 1- calc r : Projection of L2+L3 in "x_y plane" */
  /* 2- calc k : Geometery parameter */
  /* 3- calc Theta 3 */
  r = sqrt(px*px + py*py);

  k = sqrt(r*r + pow(( pz - Link1_length ),2));
  /* Description : */
  /* r   : the distance from the origin to the cup of water in the x-y plane.
     pz  : the vertical distance from the origin to the cup of water.
     k   :the length of the projection of the third link (the end effector) onto the x-y plane, 
         when the arm is in the position to reach the cup of water.
     Link1_length : the length of the first link in the robotic arm (the distance from the base to the second joint).*/
 

  Theta3 = acos (( pow(k,2) - pow(Link2_length,2) - pow(Link3_length,2)) / (2*Link2_length * Link3_length));
 /*  Link2_length  : the length of the second link in the robotic arm (the distance between the second and third joints)
     Link3_length  : the length of the third link in the robotic arm (the distance between the third joint and the end effector)
     Theta3        : the angle between the second and third links in the robotic arm, as measured from the second joint.*/
     
  /* step 3: Theta1 *
  /**********************Calc_joint2_angle**********************************/
  /* 1- calc alpha : Geometery angle */
  /* 2- calc beta  : Geometery angle */
  /* 3- calc_theta2 */

   beta = atan2((pz - Link1_length) , r );
   /* beta  : the angle between the x-y plane and the line connecting 
    * the second joint to the projection of the cup of water onto the x-y plane. */
    
   alpha  = atan2((Link3_length * sin(Theta3)) , ( Link2_length + Link3_length *cos(Theta3))); 
   /* alpha : an intermediate angle used to calculate the joint angle θ₂.*/

   Theta2 = beta - alpha ;
   
   /* step 4:Convert_angles_from_Rad_to_degrees */
    Theta1 = Theta1 * (180.0 / PI);
    Theta2 = Theta2 * (180.0 / PI);
    Theta3 = Theta3 * (180.0 / PI);
 }
 /***********************************************************************************************************************************/
 /* Manipulator_Main_Task_intialization_function_implementation */

 void Manipulator_Go_To_Cup_intialization(void)
 {
 /* step one : intialize_arduino_pins_as_inputs/outputs */
 /* servo_motor */
 Servo_joints_void_Init(servo_joint1 , servo_joint2 , servo_joint3 );
 /* ultrasonic_sensor */
 UltraSonic_void_Init(trig_pin , echo_pin );
 /* Water_Level_sensor */
 Water_Level_void_Init(water_signal_pin);

 /* Start_Triggering_for_ultrasonic_sensor */
 UltraSonic_void_Start_Triggering(trig_pin , echo_pin );
 }
 /***********************************************************************************************************************************/
 void Manipulator_Go_To_inital(void)
 {
      Servo_void_Rotate(1,0);
      delay(500); 
      Servo_void_Rotate(2,90); 
      delay(500); 
      Servo_void_Rotate(3,0);   
      delay(500); 

 }
  /***********************************************************************************************************************************/

 /* Manipulator_Main_Task_function_implementation*/
void Manipulator_Go_To_Cup( void )
{
   
     /* step one   : Have_an_intial_position.. */
     Manipulator_Go_To_inital();
     
     /* step two   : Get_The_position_by_ultrasoinc_sensor. */
     UltraSonic_void_Start_Triggering(trig_pin , echo_pin );
     UltraSonic_void_Get_Distance(echo_pin);

  
     /*  Description:
      * Cup_of_water is moving linearly by a only one varivable distance along x axis ..
      * x will be given from ultrasoinc sensor..
      * y will always be zero .. manipultor motion is 2D in x,z only...
      * z will be fixed,refered as the length of the cup along the z_axis...       */
    
      /* step three   : Get_the_angles_using_inverse_kinmatics.. */
      Get_Joints_Angles ( (Global_u32_Distance+6) , 0 , (Cup_length-3) );
         
      /* Description:
       * BY Geometery method Theta1,Theta2,Theta3 will be given ..
       * Theta 1 : will be fixed as we move along line in x_axis..                 */
 
      /* step four : Give_joints_angles_to_servo_motors_to_reach_desired_position */
      Servo_void_Rotate(1,Theta1); 
      delay(500);
      Servo_void_Rotate(2,(-Theta2)); 
      delay(500);
      Servo_void_Rotate(3,Theta3);  
      delay(500);

      delay(3000);
      
      /* step five  : Determine_if_the_cup_contains_water                          */
      Water_Level_char_Detection(water_signal_pin);
      delay(3000);
      
      /* step six  : print_if_there_is_water_in_cup */
      if( Global_is_water == 0 )
      {
      Serial.println("There is water!!!");
      }
      else
      {
      Serial.println("There is no water!!!");
      }
      }
  
