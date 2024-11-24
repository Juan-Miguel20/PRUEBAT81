float leerNumeroFlotante(const char *mensaje);
int leerNumeroEntero(const char *mensaje);
int validarNombre(const char *nombre);
void agregarProducto(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int *total_productos);
void mostrarInventario(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int total_productos);
void editarProducto(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int total_productos);
void eliminarProducto(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int *total_productos);
void crearPedido(char nombres[][50], int cantidades[], float costos[], int recursos[][10], char nombres_recursos[][10][50], int total_recursos[], int total_productos, float presupuesto);


