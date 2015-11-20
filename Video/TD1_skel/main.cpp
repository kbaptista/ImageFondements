#include "videoframes.hpp"
#include "motiontools.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "stdio.h"
#include <stdlib.h>

using namespace cv;
using namespace std;
// 2.1 : Extraction de la séquece d'images d'une vidéo

// int main( int argc, char* argv[] )
// {
// 	//On vérifie qu'on a un paramètre
// 	if( argc < 2)
//     {
//      cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
//      return -1;
//     }
	
// 	// Lecture de la vidéo passée en paramètre
// 	// La création du vecteur se fait à la lecture

// 	VideoFrames vf(argv[1]);

// 	// Affichage de la première trame
// 	const cv::Mat& frame = vf.frame(1);
// 	/* À compléter */
// 	if(! frame.data )                              // Check for invalid input
//     {
//         cout <<  "Could not open or find the image" << std::endl ;
//         return -1;
//     }

//     namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
//     imshow( "Display window", frame );               // Show our image inside it.
//     //waitKey(0);										 // Wait for a keystroke in the window

//     if (argc >=3)
//     {
// 		// Sauvegarde de la séquence des trames
// 		vf.saveToPngSequence(argv[2]);
//     }

// 	return 0;
// }


// 2.2 Affichage d’un champ de vecteurs
int main( int argc, char* argv[] )
{
    if (argc < 2)
    {
        cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
        return -1;
    }

	// Lecture de l'image passée en paramètre
	/* À compléter */

    cv::Mat A;
    A = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    printf("%d\n", A.rows );
	// Initialisation des vecteur de déplacement
	/* À compléter */
    cv::Size s( A.cols, A.rows); 
    cv::Mat vecFlowX (s, CV_32F, cv::Scalar(10));
    cv::Mat vecFlowY (s, CV_32F, cv::Scalar(5 ));

	// Dessin des vecteurs de déplacment sur une image à afficher
 	MotionTools::drawVectorFlow(A, vecFlowX, vecFlowY, 10, cv::Scalar(256, 256, 256, 0));

	// Affichage de l'image où ont été dessiné les vecteurs
	/* À compléter */
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", A );               // Show our image inside it.
    waitKey(0);                    

 	return 0;
}

// // 2.3, 2.4 et 2.5 Compensation de l'image, calcul de l'image d'erreurs et calcul de l'Erreur Quadratique Moyenne (EQM)
// int main( int argc, char* argv[] )
// {
// 	// Lecture de l'image passée en paramètres
// 	/* À compléter */

// 	// Création artificielle d'un champ de vecteur (3,3) sur l'ensemble de l'image
// 	/* À compléter */

// 	// Calcul de l'image compensée à partir du champ de vecteurs (cela produit un décalage de (3,3))
// 	MotionTools::compenseFromVectorFlow( /* À compléter */ );

// 	// Calcul de l'image d'erreur entre l'image initiale et l'image compensée
// 	MotionTools::errorImage( /* À compléter */ );

// 	// Calcul et affichage de l'Erreur Quadratique Moyenne
// 	std::cout << "EQM = " << MotionTools::computeEQM( /* À compléter */ ) << std::endl;

// 	// Affichage des différentes images
// 	/* À compléter */

// 	return 0;
// }