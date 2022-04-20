# CIU-P9
## Arduino y Processing

Se ha realizado un programa del juego pong con una pelota que se puede controlar a través de un sensor de infrarrojo.
![animaciona](https://user-images.githubusercontent.com/44921828/163979163-a0b311b8-9ac8-4dad-b47a-adf06db1e556.gif)  <br/>
*Gif de Pong realizado*


Se utiliza un microcontroller Arduino Uno con un sensor infrarrojo conectado.

## Leer el valor del sensor en c++
El signal del sensor que mide la distancia del infrarojo es recibido por un c++ script que lee el signalo del input analogo y almacena el valor en una variable val.<br/>
``` val = analogRead(analogPin);  // read the input pin ``` <br/>
  Además, imprimimos val en el output serial para controlar los valores de val. <br/>
``` Serial.println(val); ```  <br/>
Al final tenemos un delay de 50 milisegundos para obtener un resultado mas estable. Con eso delay el programa todavia es demasiado rapido para reaccionar al movimiento del usuario.

## Usar el valor del sensor en Pong
Tenemos un programa de Pong con dos jugadores que pueden controlar raquetas que deben golpear la pelota.
Si la raqueta no goplea la pelota, hay un gol por el otro jugador. El jugador que tiene 3 gols gana.
Las funcionas del Pong en general estan escribido detallado [aqui](https://github.com/marco-nh/CIU-Practica-1).
Usamos eso programa y cambiamos algunos lineas para usar los valores del sensor infrarojo y usar los para controlar la raqueta del jugador 2 a la dereacho lado.

### Leer el valor en Processing
iniciar el port en setup: <br/>
```
String portName = Serial.list()[5]; 
myPort = new Serial(this, portName, 9600); 
```

Leer el port en draw: <br/>
``` 
if ( myPort.available() > 0)
  {  // If data is available,
    val = myPort.readStringUntil('\n'); // read it and store it in val 
  }
``` 
    
### Usar el valor en Processing
Mapamos el alcance que el sensor puede medir a la altitud de nuestra ventana. Entonces, la posicion de la raqueta dos se establace en la altidud mapeada.
``` 
if(val != null) //compoba si el valor es null
    { //si no mapa el valor a las posibles posiciones de la posicion de la pelota 2
    pos2 = map(float(val),200,600,0,400);
    if(pos2 > 350)
    {//si el sensor ha un valor fuera del alcance
      pos2 = 400-50;
    }
    if(pos2 < 0)
    {//si el sensor ha un valor fuera del alcance
      pos2 = 0;
    }
  } 
``` 


Usamos la funcion map porque es institivo que la pelota se mueva al bajo si el mano es bajo y que la peolte esta arriba si el mano es a la maxima alta que el sensor puede computar.
