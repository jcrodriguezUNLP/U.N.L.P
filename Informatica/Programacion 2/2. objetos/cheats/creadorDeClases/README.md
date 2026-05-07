# Java Class Generator 3.0

Esta herramienta de línea de comandos (CLI) permite automatizar la creación y gestión de clases Java siguiendo las convenciones de la cátedra de Objetos de la UNLP.

## 🚀 Características
- **Generación Automática:** Crea esqueletos completos con atributos, constructores (incluyendo `super`), getters, setters, `toString` y herencia de métodos abstractos.
- **Sincronización en Tiempo Real:** Cualquier cambio realizado en el programa se exporta automáticamente a un archivo `.java` en la carpeta `generadas/`.
- **Persistencia Proactiva:** El estado del proyecto se guarda automáticamente en cada paso, permitiendo cerrar y retomar el trabajo sin perder datos.
- **Gestión de Herencia:** Soporte para clases abstractas y herencia de atributos/métodos entre clases creadas en la misma sesión.

## 🛠️ Cómo usar el programa

1. **Nueva Clase:** Define el nombre, si es abstracta, de quién hereda y sus atributos/métodos.
2. **Previsualizar:** Mira el código generado directamente en la consola antes de revisarlo en el archivo físico.
3. **Editar:** Modifica cualquier aspecto de una clase existente. El archivo físico se renombrará o actualizará automáticamente.
4. **Eliminar:** Quita una clase de la memoria y borra su archivo `.java` de la carpeta `generadas/`.

## 📁 Estructura del Proyecto
- `generadas/`: Contiene los archivos `.java` exportados y la base de datos de sesión (`memoria.dat`).
- `src/`: Lógica del generador organizada en componentes de UI, persistencia y modelos.

## 📝 Notas de Uso
- El programa capitaliza automáticamente los nombres de las clases.
- Los tipos de datos incluyen primitivos, `String`, `List` y `ArrayList`.
- Para tipos personalizados, selecciona la opción "otro" al definir el tipo de una variable.
