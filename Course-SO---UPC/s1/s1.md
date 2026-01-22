PREGUNTA 1. ¿Qué comandos habéis utilizado para crear los directorios S1..S5?
#mkdir s1 s2 s3 s4 s5

PREGUNTA 2. ¿Qué comando utilizas para listar el contenido de un directorio? ¿Qué opción hay que añadir para ver los ficheros ocultos?
#ls -a

PREGUNTA 3. ¿Qué opción hay que añadir a ls para ver información extendida de los ficheros? ¿Qué campos se ven por defecto con esa opción? (si no encuentras la información en el man pregunta a tu profesor)
#ls -l

PREGUNTA 4. ¿Qué opciones de menú has activado para extender la información que muestra el File Browser?
-Poniendolo en modo de visualizacion de lista, y activando los campos que queremos ver.

PREGUNTA 5. ¿Qué secuencia de comandos has ejecutado para borrar un directorio, comprobar que no está y volver a crearlo?
#rmdir s1
#ls
#mkdir s1

PREGUNTA 6. ¿Qué diferencia hay entre el comando cat y less?
-El comando cat abre una nueva ventana mostrando el contenido de un archivo, y less muestra el contenido de un archivo dentro de la propia treminal pero con la posibilidad de desplazarse por el.

PREGUNTA 7. ¿Para qué sirve la opción -i del comando cp? ¿Cuál es la orden para hacer un alias del comando cp que incluya la opción -i?
-La opcion -i sirve para que el comando cp nos pide confirmar si queremos sobreescribir un archivo que ya existe. Sirve para evitar que se sobreescriban archivos por error.

PREGUNTA 8. ¿Qué hace la opción -i del comando rm? ¿Y la opción -i del mv? Escribe la orden para hacer un alias del comando rm que incluya la opción -i.
-La opcion -i del comando rm sirve para que nos pida confirmacion antes de borrar un archivo, y, en el comando mv sirve para que nos pida confirmacion antes de sobreescribir un archivo.

PREGUNTA 9. ¿Qué opciones de chmod has utilizado para dejar solamente los permisos de escritura? ¿Qué resultado ha devuelvo cat al intentar ver el fichero test? ¿Qué opciones de chmod has utilizado para dejar solamente los permisos de lectura? ¿Has conseguido borrarlo?
#chmod ugo=w test
#cat test //Permiso denegado

#chmod ugo=r test
#rm test //Si, pero me ha pedido confirmacion

PREGUNTA 10. ¿Cuál es el significado de las variables de entorno PATH, HOME y PWD?
-Path: Es una variable que contiene la ruta de los directorios donde se encuentran las instrucciones de los comandos que se ejecutan en la terminal.
-Home: Es una variable que contiene la ruta del directorio personal del usuario.
-Pwd: Es una variable que contiene la ruta del directorio en el que nos encontramos.

PREGUNTA 11.La variable PATH es una lista de directorios, ¿Qué carácter hace de separador entre un directorio y otro?
-El caracter ":".

PREGUNTA 12.¿Qué comando has usado para definir y consultar el valor de las nuevas variables que has definido?
#export DESK=~/Desktop
#echo $DESK

PREGUNTA 13.¿Qué versión del ls se ha ejecutado?: El ls del sistema o el que te acabas de descargar? Ejecuta el comando “which ls” para comprobarlo.
-Ejeutando #which ls, sale el PATH de nuestro directio actual.

PREGUNTA 14.¿El directorio en el que estás, está definido en la variable PATH? ¿Qué implica esto?
-Si, ya que lo hemos añadido antediormente, y ejecutando #echo $PATH, nos muestra la ruta de nuestro directorio actual (.). Esto implica que podemos usar el ejecutable ls sin tener que especificar la ruta completa.

PREGUNTA 15.¿Qué binario ls se ha ejecutado en cada caso de los anteriores:El ls del sistema o el que te acabas de descargar? Ejecuta el comando “which ls” para comprobarlo.
-Antes de modificar la variable PATH original, se ejecuta la de el sistema. Despues de modificar el PATH añadiendole nuestro directorio actual, se ejecutara el ls que nos mehos descargado. Ahora despues de eliminar nuestro derectorio actual del PATH, se volvera a ejecutar el del sistms.

PREGUNTA 16.¿Qué diferencia hay entre utilizar > y >>?
-El > sobreescribe el contenido del archivo con la dalida de un comando, y el >> añade el contenido al final del archivo.



