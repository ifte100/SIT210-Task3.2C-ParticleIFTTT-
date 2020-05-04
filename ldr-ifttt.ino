  
int LDR_sensor = A0;

void setup()

{

pinMode(LDR_sensor, INPUT);

}

void loop()

{

static int lastEvent = 0;
int AnalogValue = analogRead(LDR_sensor);

if(AnalogValue > 0 && AnalogValue < 300 && lastEvent != 1 )
{
    lastEvent = 1;
    Particle.publish("Light-level-changed", "It's dark", PRIVATE);
}

else if(AnalogValue > 200 && AnalogValue < 1000 && lastEvent != 2 )
{
    lastEvent = 2;
    Particle.publish("Light-level-changed", "Low light", PRIVATE);
}

else if(AnalogValue > 1000 && lastEvent != 3 )
{
    lastEvent = 3;
    Particle.publish("Light-level-changed", "Very bright", PRIVATE);
}

delay(10000);

}