//Recordatorio: usando la creación de función de (function var() {}) lo puede leer en la primera vuelta y hace que puedas llamar a las funciones antes de ser definidas y se ejecuten correctamente

iniciarApp();
function iniciarApp() {
    console.log('Iniciando app...');
    segundaFuncion(); //Puedes llamar funciones desde el codigo de otras funciones
}

function segundaFuncion() {
    console.log('Desde la segunda función');
    usuarioAutenticado('Pablo');
}

function usuarioAutenticado(usuario) {
    console.log('Autenticando usuario...');
    console.log(`Usuario autenticado exitosamente: ${usuario}`);
}