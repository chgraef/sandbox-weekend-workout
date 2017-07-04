# frozen_string_literal

module UtilsSpecHelpers
  extend self

  def generate_alpha_string(range)
    raise ArgumentError, '"range" cannot be nil.' if range.nil?

    unless range.kind_of?(Range)
      raise ArgumentError, 'The "range" parameter must be of type Range.'
    end

    alpha_chars = [*'A'..'Z', *'a'..'z'].join
    generate_string(range, chars: alpha_chars)
  end

  def generate_bad_string(range)
    raise ArgumentError, '"range" cannot be nil.' if range.nil?

    unless range.kind_of?(Range)
      raise ArgumentError, 'The "range" parameter must be of type Range.'
    end

    bad_chars = [*?0..?9, '+', '-', '?', '#'].join

    generate_string(range, chars: bad_chars)
  end

  def generate_good_array(range)
    raise ArgumentError, '"range" cannot be nil.' if range.nil?

    unless range.kind_of?(Range)
      raise ArgumentError, 'The "range" parameter must be of type Range.'
    end

    good_ary = generate_array(range) { generate_alpha_string(1..31) }

    good_ary
  end

  def generate_array_with_non_string(range)
    raise ArgumentError, '"range" cannot be nil.' if range.nil?

    unless range.kind_of?(Range)
      raise ArgumentError, 'The "range" parameter must be of type Range.'
    end

    bad_items = [0, 0.0, 0..9, {}].map(&:freeze).freeze

    good_ary  = generate_array(range) { generate_alpha_string(1..31) }
    bad_item  = bad_items.sample
    bad_ary   = good_ary + [bad_item]

    bad_ary.shuffle
  end

  def generate_array_with_bad_string(range)
    raise ArgumentError, '"range" cannot be nil.' if range.nil?

    unless range.kind_of?(Range)
      raise ArgumentError, 'The "range" parameter must be of type Range.'
    end

    good_ary = generate_array(range) { generate_alpha_string(1..31) }
    bad_str  = generate_bad_string(1..31)
    bad_ary  = good_ary + [bad_str]

    bad_ary.shuffle
  end

  private

  def generate_array(range, **options, &block)
    raise ArgumentError, '"range" cannot be nil.' if range.nil?

    unless range.kind_of?(Range)
      raise ArgumentError, 'The "range" parameter must be of type Range.'
    end

    validate_options!(**options)

    ary_len = rand(range)

    Array.new(ary_len, &block)
  end

  def generate_string(range, **options)
    raise ArgumentError, '"range" cannot be nil.' if range.nil?

    unless range.kind_of?(Range)
      raise ArgumentError, 'The "range" parameter must be of type Range.'
    end

    validate_options!(**options)

    ary_len = rand(range)
    base_s  = options.fetch(:chars, [*'A'..'Z', *'a'..'z', *?0..?9].join)

    Array.new(ary_len) { base_s.chars.sample }.join
  end

  def validate_options!(**options)
    options.each do |k, v|
      raise ArgumentError, "The key cannot be nil." if k.nil?
      raise ArgumentError, %Q(The value of "#{k}" cannot be nil.) if v.nil?
    end
  end
end

