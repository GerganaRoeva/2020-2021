package com.elsys.fitness;

import com.elsys.fitness.training.Training;
import com.elsys.fitness.training.TrainingType;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CustomerTest {

    private Customer customer;
    private Card card;

    @BeforeEach
    void setup() {
        card = new Card(10);
        customer = new Customer("Marti", "Hihi", card);
    }

    @Test
    void performTraining() {
        Training training = new Training("tabata", TrainingType.GROUP_TRAINING);
        customer.performTraining(training);

        assertEquals(9, card.getRemainingTrainings());
    }
}