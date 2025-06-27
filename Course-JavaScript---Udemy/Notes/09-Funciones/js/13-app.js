//Otra manera de hacer 09-Funciones/js.app10 con Arrow Functions
const reproductor = {
    reproducir: id => console.log(`Reproduciendo canción con el id ${id}`),
    pausar: () => console.log('pausando...'),
    borrar: id  => console.log(`Borrando canción... ${id}`),
    crearPlaylist: nombre => console.log(`Creando la playlist de ${nombre}`),
    reproducirPlaylist: nombre => console.log(`Reproduciendo la playlist ${nombre}`),
    cancion: '',
    set nuevaCancion(cancion) { //'set' sirve para gravar / encapsular un contenido en la función que define (también sirve para tratar de proteger / organizar mejor el objeto). En este caso solamente afectan al objeto porque esta dentro del objeto
        this.cancion = cancion;//Recordatorio: 'this.var' es para que busque una variable dentro del objeto y no se fije en las de afuera
        console.log(`Añadiendo ${cancion}`);
    },
    get obtenerCancion() { //'get' sirve para obtener / encapsular un valor en la función que define (también sirve para tratar de proteger / organizar mejor el objeto). En este caso solamente afectan al objeto porque esta dentro del objeto
        console.log(`${this.cancion}`);
    }
}
reproductor.nuevaCancion = 'Enter Sandman'; //El 'set' y el 'get' se llaman como si fueran un objeto
reproductor.obtenerCancion;

// reproductor.reproducir(30);
// reproductor.reproducir(20);
// reproductor.pausar();
// reproductor.borrar('Max');
// reproductor.crearPlaylist('Max');
// reproductor.reproducirPlaylist('2023');