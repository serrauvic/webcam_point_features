# webcam_point_features
Detection of ORB features from online webcam imges.

# ORB (Oriented FAST and Rotated BRIEF)
ORB es una algoritme que neix com alternativa lliure als algoritmes SIFT i SURF. Aquest algoritme es una combinació de FAST per a la detecció de punts d’interès i BRIEF per a la descripció binària d’aquest punts, però incorporant importants millores respecte als anteriors.

ORB incorpora un mecanisme de compensació de la orientació fent que sigui més immune a les rotacions i augmenta la eficacia en la detecció dels parells de mostreig òptims .

Per millorar la sensibilitat a la rotació utilitza la intensitat del centroid de la zona al voltant dels punts d’interès, en primer lloc es defineix el moment del centroid, amb el moment s’extreu el centre de la zona, llavors construeix un vector des del centre dels punts d’interès fins al centroid, a partir d’aqui extreu la orientació.

En aquesta aplicació s’implementat la detecció de punts d’interès amb ORB original però aplicant una mascara per focalitzar la zona de la imatge on es volen detecta aquest punts.

Referencies:

https://en.wikipedia.org/wiki/Features_from_accelerated_segment_test

https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_feature2d/py_orb/py_orb.html

https://gilscvblog.com/2013/10/04/a-tutorial-on-binary-descriptors-part-3-the-orb-descriptor/
