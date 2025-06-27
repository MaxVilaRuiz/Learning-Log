//Definiendo funciones dentro de objetos:
const reproductor = {
    reproducir: function(id) {
        console.log(`Reproduciendo canción con el id ${id}`);
    },
    pausar: function() {
        console.log('pausando...');
    },
    borrar: function(id) {
        console.log(`Borrando canción... ${id}`);
    },
    crearPlaylist: function(nombre){
        console.log(`Creando la playlist de ${nombre}`)
    },
    reproducirPlaylist: function(nombre) {
        console.log(`Reproduciendo la playlist ${nombre}`)
    }
}

//Llamar a funciones de objetos:
reproductor.reproducir(30);
reproductor.reproducir(20);
reproductor.pausar();
reproductor.borrar('Max');
reproductor.crearPlaylist('Max');
reproductor.reproducirPlaylist('2023');

//Ejemplo personal:
const nombrePlaylist = prompt('Añade nombre a la Playlist: '); //Creo una variable con el valor String que añada el usuario (promp() = input) y hago que la función 'nombrePlaylist' del objeto 'reproductor' transmita el mensaje a la consola con el nombre personalizado que ha escogido el usuario.
reproductor.crearPlaylist(nombrePlaylist);