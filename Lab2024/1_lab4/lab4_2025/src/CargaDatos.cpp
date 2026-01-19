#include "../include/CargaDatos.h"
#include <cstddef>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    Factory *factory = Factory::getInstance();
    IControladorFechaActual *cfa = factory->getControladorFechaActual();
    IPublicacionInmuebleController *pic = factory->getPublicacionInmuebleController();
    IUsuarioController *uc = factory->getUsuarioController();

    // Set fecha actual
    cfa->setNewFechaActual(20, 06, 2025);

    // Set clientes
    uc->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Pérez", "46859342");
    uc->finalizarAltaUsuario();
    uc->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");
    uc->finalizarAltaUsuario();

    // Set propietarios e Inmuebles correspondientes    
    uc->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "123456789012", "099876543");
    uc->altaCasa("Av.Rivera", 1020, 120, 1995, true, Plano);
    uc->altaApartamento("AV.Brasil", 2031, 75, 1980, 5, true, 3500);
    uc->finalizarAltaUsuario();
    
    uc->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "987654321001", "091234567");
    uc->altaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);
    uc->finalizarAltaUsuario();

    uc->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "654321987654", "092345678");
    uc->altaApartamento("Colonia", 1542, 95, 1978, 12, true, 2800);
    uc->finalizarAltaUsuario();

    uc->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "321098765432", "098765432");
    uc->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
    uc->finalizarAltaUsuario();

    uc->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "890123456789", "097654321");
    uc->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    uc->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    uc->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
    uc->finalizarAltaUsuario();

    // Set Inmobiliarias con sus respectivos Propietarios a representar
    uc->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    uc->representarPropietario("marcelom");
    uc->representarPropietario("jorge88");
    uc->finalizarAltaUsuario();
    
    uc->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia", "https://idealhome.uy", "099123456");
    uc->representarPropietario("marcelom");
    uc->representarPropietario("jorge88");
    uc->finalizarAltaUsuario();
    
    uc->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    uc->representarPropietario("robertarce");
    uc->representarPropietario("soledadf");
    uc->representarPropietario("jorge88");
    uc->finalizarAltaUsuario();

    //cargar AdministraPropiedad
    cfa->setNewFechaActual(12,12,2015);
    pic->altaAdministraPropiedad("casasur123", 2);
    cfa->setNewFechaActual(25,9,2023);
    pic->altaAdministraPropiedad("idealhome", 1);
    cfa->setNewFechaActual(20,07,2022);
    pic->altaAdministraPropiedad("vivaurbana", 3);
    cfa->setNewFechaActual(01,01,2022);
    pic->altaAdministraPropiedad("vivaurbana", 4);
    cfa->setNewFechaActual(03,07,2010);
    pic->altaAdministraPropiedad("idealhome",5);
    cfa->setNewFechaActual(04,11,2019);
    pic->altaAdministraPropiedad("casasur123",6);
    cfa->setNewFechaActual(19,05,2020);
    pic->altaAdministraPropiedad("vivaurbana",6);
    cfa->setNewFechaActual(19,07,2024);
    pic->altaAdministraPropiedad("idealhome",6);
    cfa->setNewFechaActual(18,9,2023);
    pic->altaAdministraPropiedad("idealhome",7);
    cfa->setNewFechaActual(19,05,2022);
    pic->altaAdministraPropiedad("vivaurbana",8);

    // Suscripciones a inmobiliarias

    std::set<DTInmobiliaria*> cI = uc->listarNoSuscritas("luisito23");
    uc->generarSuscripcion("casasur123");
    uc->generarSuscripcion("idealhome");
    for (std::set<DTInmobiliaria*>::iterator it = cI.begin(); it != cI.end(); it++) {
        delete *it;
    }
    uc->finalizarAltaUsuario();
    
    cI = uc->listarNoSuscritas("anarojo88");
    uc->generarSuscripcion("casasur123");
    uc->generarSuscripcion("idealhome");
    uc->generarSuscripcion("vivaurbana");
    for (std::set<DTInmobiliaria*>::iterator it = cI.begin(); it != cI.end(); it++) {
        delete *it;
    }  
    uc->finalizarAltaUsuario();
    
    cI = uc->listarNoSuscritas("marcelom");
    uc->generarSuscripcion("idealhome");
    for (std::set<DTInmobiliaria*>::iterator it = cI.begin(); it != cI.end(); it++) {
        delete *it;
    }
    uc->finalizarAltaUsuario();    
    
    cI = uc->listarNoSuscritas("robertarce");
    uc->generarSuscripcion("idealhome");
    for (std::set<DTInmobiliaria*>::iterator it = cI.begin(); it != cI.end(); it++) {
        delete *it;
    }
    uc->finalizarAltaUsuario();
    
    cI = uc->listarNoSuscritas("soledadf");
    uc->generarSuscripcion("vivaurbana");
    for (std::set<DTInmobiliaria*>::iterator it = cI.begin(); it != cI.end(); it++) {
        delete *it;
    }
    uc->finalizarAltaUsuario();
    
    cI = uc->listarNoSuscritas("martagal");
    uc->generarSuscripcion("vivaurbana");
    for (std::set<DTInmobiliaria *>::iterator it = cI.begin(); it != cI.end(); it++)
    {
        delete *it;
    }
    uc->finalizarAltaUsuario();
    
    cI = uc->listarNoSuscritas("jorge88");
    uc->generarSuscripcion("casasur123");
    uc->generarSuscripcion("idealhome");
    uc->generarSuscripcion("vivaurbana");
    for (std::set<DTInmobiliaria*>::iterator it = cI.begin(); it != cI.end(); it++) {
        delete *it;
    }
    uc->finalizarAltaUsuario();
    cI.clear();


    // Generamos las publicaciones
    cfa->setNewFechaActual(9,10,2011);
    pic->altaPublicacion("idealhome", 5, Venta, "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000);
    
    cfa->setNewFechaActual(15,01,2016);
    pic->altaPublicacion("casasur123", 2, Alquiler, "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000);
    
    cfa->setNewFechaActual(05,03,2019);
    pic->altaPublicacion("casasur123", 2, Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500);

    cfa->setNewFechaActual(03,04,2019);
    pic->altaPublicacion("idealhome", 5, Alquiler, "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500);

    cfa->setNewFechaActual(12,12,2019);
    pic->altaPublicacion("casasur123", 6, Venta, "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000);

    cfa->setNewFechaActual(12,06,2020);
    pic->altaPublicacion("casasur123", 2, Venta, "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 390000);

    cfa->setNewFechaActual(20,07,2020);
    pic->altaPublicacion("vivaurbana", 6, Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000);

    cfa->setNewFechaActual(04,03,2022);
    pic->altaPublicacion("vivaurbana", 4, Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000);

    cfa->setNewFechaActual(12,9,2022);
    pic->altaPublicacion("vivaurbana", 3, Alquiler, "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000);

    cfa->setNewFechaActual(01,10,2023);
    pic->altaPublicacion("idealhome", 1, Venta, "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000);

    cfa->setNewFechaActual(18,10,2023);
    pic->altaPublicacion("idealhome", 7, Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000);

    cfa->setNewFechaActual(19,10,2023);
    pic->altaPublicacion("idealhome", 7, Venta, "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000);

    cfa->setNewFechaActual(20,11,2023);
    pic->altaPublicacion("idealhome", 7, Alquiler, "Apartamento con gran vista a la rambla", 31000);

    cfa->setNewFechaActual(20,11,2023);
    pic->altaPublicacion("idealhome", 7, Venta, "Aprtamente en excelentes condiciones de 80 m", 450000);

    cfa->setNewFechaActual(8,03,2024);
    pic->altaPublicacion("vivaurbana", 3, Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000);

    cfa->setNewFechaActual(05,05,2024);
    pic->altaPublicacion("idealhome", 7, Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000);

    cfa->setNewFechaActual(01,8,2024);
    pic->altaPublicacion("idealhome", 6, Venta, "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000);
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}

CargaDatos::~CargaDatos(){
    instance = NULL;
}

void CargaDatos::destruirInstance(){
    if (instance != NULL)
    {
        delete instance;
        instance = NULL;
    }
    
}