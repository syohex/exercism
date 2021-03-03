package meetup

import (
	"fmt"
	"time"
)

type WeekSchedule int

const (
	First WeekSchedule = iota
	Second
	Third
	Fourth
	Last
	Teenth
)

func daysOfMonth(month time.Month, year int) int {
	if month != time.February {
		switch month {
		case time.April, time.June, time.September, time.November:
			return 30
		default:
			return 31
		}
	}

	if year%400 == 0 {
		return 29
	} else if year%100 == 0 {
		return 28
	} else if year%4 == 0 {
		return 29
	} else {
		return 28
	}
}

func Day(week WeekSchedule, weekDay time.Weekday, month time.Month, year int) int {
	date := fmt.Sprintf("%02d-01-%d", month, year)
	t, err := time.Parse("01-02-2006", date)
	if err != nil {
		panic(err)
	}

	wday := int(weekDay)
	w := int(t.Weekday())

	matched := 0
	matchDay := 0
	day := 1
	limit := daysOfMonth(month, year)
	for day <= limit {
		if w == wday {
			matched++
			if (week == First && matched == 1) ||
				(week == Second && matched == 2) ||
				(week == Third && matched == 3) ||
				(week == Fourth && matched == 4) {
				return day
			}

			if week == Teenth && day >= 10 {
				if day >= 13 {
					return day
				}

				return day + 7
			}

			matchDay = day
		}

		w = (w + 1) % 7
		day++
	}

	return matchDay
}
