pub struct Allergies {
    score: u32,
}

#[derive(Debug, PartialEq)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}

fn allergen_to_score(allergen: &Allergen) -> u32 {
    match allergen {
        Allergen::Eggs => 1,
        Allergen::Peanuts => 2,
        Allergen::Shellfish => 4,
        Allergen::Strawberries => 8,
        Allergen::Tomatoes => 16,
        Allergen::Chocolate => 32,
        Allergen::Pollen => 64,
        Allergen::Cats => 128,
    }
}

fn score_to_allergen(score: &u32) -> Allergen {
    match score {
        1 => Allergen::Eggs,
        2 => Allergen::Peanuts,
        4 => Allergen::Shellfish,
        8 => Allergen::Strawberries,
        16 => Allergen::Tomatoes,
        32 => Allergen::Chocolate,
        64 => Allergen::Pollen,
        128 => Allergen::Cats,
        _ => panic!("never reach here"),
    }
}

impl Allergies {
    pub fn new(score: u32) -> Self {
        Self { score }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        let num = allergen_to_score(allergen);
        self.score & num != 0
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        (1u32..=8)
            .into_iter()
            .filter_map(|s| {
                let mask = 2u32.pow(s - 1);
                if (self.score & mask) != 0 {
                    Some(score_to_allergen(&mask))
                } else {
                    None
                }
            })
            .collect()
    }
}
