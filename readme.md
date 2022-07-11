# POLICAJERO
## Descripción
        El policajero se ha creado para la comunidad de la EPN, con el fin de tener un entorno mas amigable dentro de la Universidad para gestionar mejor el dinero.

## Estado del proyecto
        El proyecto se encuentra en desarrollo y tiene finalizada la etapa de programación de validación de datos, como numero de tarjeta y pin. En posteriores semanas estarán disponibles las demás opciones que ofrece el Policajero, como: retiro, depósito, transferecia y consulta de dinero.

## ¿Cómo instalar/ejecutar el policajero?
        El policajero, actualmente se lo puede ejecutar en consola, ya que el IDE utilizado es Visual Studio Code y para ello, se utiliza el terminal GitBash.

## ¿Cómo funciona el policajero?
        Para hacer uso del policajero, debemos estar registrados en la base de datos del policajero.

        Al iniciar el programa del policajero, realizará la lectura del número de tarjeta (ingreso por teclado), posterior a esto, se pedirá el pin guardado previamente en el registro, y una vez validado con éxito estos datos, accederemos al menú principal del policajero.

    -Registro.
        El registro está dado en un archivo de texto (.txt) llamado "base".

    -Validación de Datos (Número de tarjeta y PIN).
        existReg(); Al ingresar el número de tarjeta, se hará la comparación con la base para verificar si el usuario existe. En caso de que no exista, el policajero finalizará su ejecución.

        verPin(); Luego de verificar la existencia del usuario, se solicitará el PIN, y en caso de ser erroneo, solo tendrá 3 intentos para ingresar el correcto. En caso de errar las 3 veces, el policajero finalizará su ejecución.

    -Funciones.
        getOp(); La funciones que ofrece el policajero son:
            * Retiro de dinero
            * Depósito de dinero
            * Transferencia de dinero
            * Consulta de saldo

    -Código.
        Los datos del archivo de texto, al iniciar la ejecución del policajero, se guardan un vector de tipo estructura(struct usuario), posterior a esto, el numero de tarjeta se compara con los datos del vector y cuando lo encuentre, todos los datos (nombre, numero de tarjeta, pin y saldo)d e este usuario se guarda en una nueva estructura para su futuro uso.

## Posibles Fallos
        Existe la posibilidad de que en el registro se ingrese un nuevo usuario con la información en distinto orden al establecido, lo que puede producir un error al leer los datos.

        Un posible error, se puede dar al cambiar de dirección el archivo "base.txt".

        Un bug consciente en este proyecto, es la ausencia de un bloqueo luego del 3er intento erroneo del PIN, ya que se puede volver a ingresar al policajero e intentar 3 veces más.