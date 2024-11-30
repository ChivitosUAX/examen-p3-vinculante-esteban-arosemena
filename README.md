# examen-p3-vinculante-esteban-arosemena
https://github.com/ChivitosUAX/examen-p3-vinculante-esteban-arosemena.git

***

# EXPLICACION DEL CONTENIDO Y DEL PROGRAMA:
### Más abajo se encuentra el enunciado, casi al final.

Introducción

Este proyecto aborda un problema de optimización de recursos y gestión del tiempo en un escenario realista de alta presión. Como project managers, debemos planificar y coordinar una serie de tareas para garantizar que un ejecutivo pueda llegar a una reunión crucial a tiempo, respetando un límite de tiempo estricto y minimizando la cantidad de ayudantes contratados.

Objetivo del Proyecto

Optimizar la gestión del tiempo para que el ejecutivo llegue a tiempo a su reunión en Barcelona, cumpliendo con el plazo máximo de 100 minutos.
Minimizar la cantidad de ayudantes contratados para realizar tareas delegables, manteniendo la eficiencia en la ejecución de las tareas.
Descripción del Problema

El CEO de una compañía ha aterrizado en Barcelona y tiene una reunión crucial a las 19:30. Cuenta con solo 100 minutos antes de que cierre la facturación para su vuelo desde Madrid a Barcelona. Es necesario planificar y ejecutar una serie de tareas con dependencias específicas para asegurar que el ejecutivo llegue a tiempo.

Análisis de Tareas y Dependencias

Lista de Tareas
Letra	Tarea	Duración (min)
A	Reserva de vuelo	20
B	Informar a casa para empacar	5
C	Empacar maletas	40
D	Preparación del billete por la agencia	10
E	Recoger el billete de la agencia	5
F	Llevar el billete a la oficina	10
G	Recoger las maletas de casa	20
H	Llevar maletas a la oficina	25 (reducido a 5)
I	Conversación sobre documentos requeridos	35
J	Dictar instrucciones para ausencia	25
K	Reunir documentos	15
L	Organizar documentos	5
M	Viajar al aeropuerto y facturar	25
Dependencias entre Tareas
C depende de B.
D depende de A.
E depende de D.
F depende de E.
G depende de C.
H depende de G.
K depende de I.
L depende de K.
M depende de F, H, L, y J.
Estrategia de Solución

Identificación de Tareas Delegables
Tareas que el Ejecutivo Debe Realizar Personalmente:

A: Reserva de vuelo
I: Conversación sobre documentos requeridos
E: Recoger el billete de la agencia
F: Llevar el billete a la oficina
M: Viajar al aeropuerto y facturar
Tareas Delegables a Ayudantes:

B: Informar a casa para empacar
C: Empacar maletas
G: Recoger las maletas de casa
H: Llevar maletas a la oficina (duración reducida con más ayudantes)
J: Dictar instrucciones para ausencia
K: Reunir documentos
L: Organizar documentos
Optimización del Cronograma
Para cumplir con el plazo de 100 minutos, es necesario:

Priorizar la tarea "A" al inicio para no retrasar tareas dependientes.
Delegar tareas que no requieren la presencia del ejecutivo.
Reducir la duración de tareas críticas, como "H", contratando ayudantes adicionales.
Programar tareas en paralelo siempre que sea posible.
Contratación de Ayudantes
Cantidad mínima de ayudantes necesarios: 5

Ayudante 1: B, C, G
Ayudante 2: J
Ayudante 3: K, L
Ayudante 4 y 5: H (trabajando en conjunto para reducir la duración)
Implementación en C++

Estructuras de Datos Utilizadas
Task: Representa una tarea con sus atributos:
id: Identificador (letra).
name: Nombre descriptivo.
duration: Duración en minutos.
dependencies: Lista de identificadores de tareas de las que depende.
assignedTo: Recurso asignado (Ejecutivo o Ayudante).
startTime y endTime: Tiempos de inicio y fin.
Resource: Representa un recurso (Ejecutivo o Ayudante):
name: Nombre del recurso.
availableAt: Tiempo en el que el recurso está disponible.
Descripción del Código
Inicialización de Tareas y Recursos: Se definen las tareas y se asignan a los recursos correspondientes, incluyendo sus dependencias.
Funciones Auxiliares:
getTask: Obtiene una referencia a una tarea por su identificador.
dependenciesCompleted: Verifica si todas las dependencias de una tarea se han completado.
Asignación de Tiempos:
Se programa cada tarea en el tiempo más temprano posible, considerando la disponibilidad del recurso y la finalización de las dependencias.
La tarea "A" se fuerza a iniciar en el tiempo 0.
Actualización de Recursos:
Se actualiza la disponibilidad de cada recurso después de asignar una tarea.
Verificación y Salida:
Se verifica que todas las tareas hayan sido programadas.
Se calcula el tiempo total del proyecto.
Se imprime el cronograma detallado.
Ejecución del Programa
Para compilar y ejecutar el programa:

g++ -o programa programa.cpp
./programa
Resultados

Cronograma Generado
Cronograma de tareas:
Ejecutivo realiza A: Reserva de vuelo de 0 min a 20 min.
Ayudante 1 realiza B: Informar a casa para empacar de 0 min a 5 min.
Ayudante 2 realiza J: Dictar instrucciones para ausencia de 0 min a 25 min.
Agencia realiza D: Preparación del billete por la agencia de 20 min a 30 min.
Ejecutivo realiza I: Conversación sobre documentos requeridos de 20 min a 55 min.
Ayudante 1 realiza C: Empacar maletas de 5 min a 45 min.
Ejecutivo realiza E: Recoger el billete de la agencia de 55 min a 60 min.
Ayudante 1 realiza G: Recoger las maletas de casa de 45 min a 65 min.
Ejecutivo realiza F: Llevar el billete a la oficina de 60 min a 70 min.
Ayudante 3 realiza K: Reunir documentos de 55 min a 70 min.
Ayudante 4 y 5 realizan H: Llevar maletas a la oficina de 65 min a 70 min.
Ayudante 3 realiza L: Organizar documentos de 70 min a 75 min.
Ejecutivo realiza M: Viajar al aeropuerto y facturar de 75 min a 100 min.

Tiempo total del proyecto: 100 minutos.
Es posible completar todas las tareas en el plazo de 100 minutos.
Verificación del Tiempo Total
Tiempo total del proyecto: 100 minutos.
Plazo máximo permitido: 100 minutos.
Cumplimiento del plazo: Sí.
Conclusiones

Optimización Lograda: Se logró optimizar el cronograma para que todas las tareas se completen en 100 minutos o menos.
Uso Eficiente de Recursos: La contratación de 5 ayudantes permitió distribuir las tareas delegables y reducir la duración de tareas críticas.
Respeto de Dependencias: Todas las dependencias entre tareas se respetaron en la programación.
Importancia de la Planificación: Este ejercicio demuestra cómo una planificación cuidadosa y la optimización de recursos pueden resolver problemas complejos bajo restricciones de tiempo.
Referencias

Algoritmos de Programación y Planificación: Se utilizaron conceptos de programación de tareas y manejo de dependencias para desarrollar la solución.
Estructuras de Datos en C++: Uso de estructuras, mapas y vectores para gestionar tareas y recursos.

***

# ENUNCIADO

Condiciones de Entrega del Examen de Programación en C++

Estimado estudiante,

Para garantizar una correcta evaluación de tus habilidades y entendimiento en la programación en C++, hemos establecido un conjunto de condiciones que deberás seguir al momento de entregar tus respuestas al examen. La estructura y presentación de tu entrega son esenciales para facilitar el proceso de corrección y asegurarnos de que hemos evaluado todos tus esfuerzos de manera justa.

Instrucciones para la entrega:

Repositorio en GitHub:

Todo tu trabajo debe estar contenido en un repositorio en GitHub.
Asegúrate de que el repositorio sea privado al inicio, y podrás hacerlo público después de que finalice el período de revisión del examen (si así lo deseas).
Fichero ZIP:

Una vez hayas terminado de resolver el examen, crea un archivo ZIP de todo el repositorio.
El nombre del archivo ZIP debe seguir el formato: Apellido_Nombre_ExamenCPP.zip (reemplaza Apellido y Nombre con tu apellido y nombre respectivamente).
Fichero README.md:

Dentro de tu repositorio, debes incluir un archivo README.md.
Este archivo debe contener:
El link directo a tu repositorio de GitHub.
Una descripción breve de cada uno de los ejercicios resueltos, con referencias a los archivos o carpetas específicos donde se puede encontrar cada solución.
El uso adecuado de Markdown en tu README.md para estructurar y formatear el contenido será valorado positivamente.
Envío:

Entrega el archivo ZIP a través de la plataforma o método que se te indique (por ejemplo, un sistema de gestión de aprendizaje, correo electrónico, etc.).
Asegúrate de enviar tu trabajo antes de la fecha y hora límite. Las entregas fuera de plazo pueden no ser evaluadas o incurrir en penalizaciones.
Otros aspectos a considerar:

Asegúrate de que tu código esté bien comentado, organizado y que sea fácil de leer y entender.
Si utilizas alguna referencia externa para resolver algún ejercicio, es esencial que lo cites en tu README.md.
Siguiendo estas condiciones y presentando tu trabajo de manera organizada, nos ayudarás a llevar a cabo un proceso de revisión más eficiente. Deseamos que demuestres todo tu conocimiento y habilidades en este examen. ¡Buena suerte!


Bienvenidos a este reto práctico de algoritmos. En este ejercicio, pondrán a prueba sus habilidades para planificar y optimizar recursos bajo un escenario realista de alta presión.

Enunciado del Problema:

Ustedes son Project Managers en una empresa internacional. Reciben una llamada urgente de un alto ejecutivo, informándoles que el CEO de la compañía ha aterrizado en Barcelona desde Estados Unidos y tiene una reunión crucial para las 19:30 en la ciudad. Sin embargo, el ejecutivo cuenta con solo 100 minutos antes de que cierre la facturación para su vuelo desde Madrid a Barcelona.

Objetivo: Debido a la urgencia de la situación, necesitan optimizar las tareas para cumplir con el objetivo de que el ejecutivo llegue a la reunión a tiempo. A continuación se detalla la lista de tareas necesarias, sus descripciones y las duraciones de cada una. Su misión es identificar las dependencias entre las tareas, calcular el tiempo total para completar las tareas en el orden adecuado, y determinar si es posible cumplir con el plazo de 100 minutos.

Tareas, Descripciones y Duraciones:

A: Reserva de vuelo (20 min)
B: Informar a casa para empacar (5 min)
C: Empacar maletas (40 min)
D: Preparación del billete por la agencia (10 min)
E: Recoger el billete de la agencia (5 min)
F: Llevar el billete a la oficina (10 min)
G: Recoger las maletas de casa (20 min)
H: Llevar maletas a la oficina (25 min)
I: Conversación sobre documentos requeridos (35 min)
J: Dictar instrucciones para ausencia (25 min)
K: Reunir documentos (15 min)
L: Organizar documentos (5 min)
M: Viajar al aeropuerto y facturar (25 min)
Dependencias entre tareas:

Algunas tareas deben ser realizadas antes que otras, por ejemplo, no se puede viajar al aeropuerto antes de haber recogido las maletas.
Además, la reserva del vuelo debe completarse antes de recoger el billete, y la preparación del billete debe ocurrir antes de llevar el billete a la oficina.
Objetivos del Reto:

Definir el Objetivo del Proyecto: Identificar el propósito principal del proyecto (optimizar la gestión del tiempo para cumplir con el plazo de 100 minutos) y no solo las tareas.

Diagrama de Flujo del Cronograma: Crear un diagrama de flujo para visualizar el cronograma del proyecto, teniendo en cuenta solo las dependencias entre tareas y no restricciones de recursos.

Desarrollo de Algoritmo en C++:

Crear un programa en C++ que permita calcular el orden de ejecución de las tareas en función de sus dependencias.
Determinar el tiempo total necesario para completar todas las tareas.
Evaluar si es posible completar las tareas en 100 minutos o menos.
Imprimir el orden óptimo de ejecución de las tareas y su tiempo total.
Restricciones:

El tiempo máximo permitido para completar las tareas es de 100 minutos.
El algoritmo debe gestionar de forma eficiente las dependencias entre las tareas, de tal manera que optimice el tiempo de ejecución.
Entrega:

Código fuente en C++ que implemente la solución al problema.
Diagrama de flujo que represente el cronograma de ejecución de las tareas.
¡Buena suerte y que la optimización esté de su lado!

