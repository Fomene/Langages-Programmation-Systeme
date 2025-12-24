import java.util.concurrent.locks.ReentrantReadWriteLock;

class Memoire {
    private int valeur = 0; // Donnée partagée
    private final ReentrantReadWriteLock verrou = new ReentrantReadWriteLock(); // lecteur/rédacteur

    // plusieurs threads peuvent tenir le readLock simultanément.
    public void lire(int idLecteur) {
        verrou.readLock().lock();
        try {
            System.out.println("Lecteur " + idLecteur + " lit : " + valeur);
        } finally {
            verrou.readLock().unlock();
        }
    }

    // seul un rédacteur à la fois, et il bloque les lecteurs le temps d'écrire
    public void ecrire(int idRedacteur) {
        verrou.writeLock().lock();
        try {
            valeur++;
            System.out.println("Redacteur " + idRedacteur + " ecrit : " + valeur);
        } finally {
            verrou.writeLock().unlock();
        }
    }
}

// encapsule l'appel de lecture
class Lecteur extends Thread {
    private final Memoire memoire;
    private final int id;

    public Lecteur(int id, Memoire memoire) {
        this.id = id;
        this.memoire = memoire;
    }

    @Override
    public void run() {
        memoire.lire(id);
    }
}

// encapsule l'appel d'ecriture
class Redacteur extends Thread {
    private final Memoire memoire;
    private final int id;

    public Redacteur(int id, Memoire memoire) {
        this.id = id;
        this.memoire = memoire;
    }

    @Override
    public void run() {
        memoire.ecrire(id);
    }
}

public class programme5 {
    public static void main(String[] args) {
        Memoire memoire = new Memoire();

        // 3 lecteurs et 2 rédacteurs pour démonstration
        new Lecteur(1, memoire).start();
        new Lecteur(2, memoire).start();
        new Redacteur(1, memoire).start();
        new Lecteur(3, memoire).start();
        new Redacteur(2, memoire).start();
    }
}
